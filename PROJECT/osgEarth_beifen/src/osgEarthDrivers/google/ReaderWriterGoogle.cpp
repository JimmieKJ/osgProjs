/* -*-c++-*- */
/* osgEarth - Dynamic map generation toolkit for OpenSceneGraph
 * Copyright 2008-2013 Pelican Mapping
 * http://osgearth.org
 *
 * osgEarth is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <osgEarth/TileSource>
#include <osgEarth/Registry>
#include <osgEarth/URI>

#include <osg/Notify>
#include <osgDB/FileNameUtils>
#include <osgDB/FileUtils>
#include <osgDB/Registry>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <sstream>

#include "GoogleOptions"

using namespace osgEarth;
using namespace osgEarth::Drivers;

#define PROPERTY_DATASET    "dataset"
#define PROPERTY_VERSION    "version"
#define PROPERTY_LANGUAGE   "language"

class GoogleSource : public TileSource
{
public:
    GoogleSource( const TileSourceOptions& options ) : TileSource( options ), _options(options)
    {
        //nop
		if (_language.empty())
			_language = "en";

		if (_dataset.empty())
			_dataset = "satellite"; 
    }

    Status initialize(const osgDB::Options* dbOptions)
    {
        _dbOptions = Registry::instance()->cloneOrCreateOptions( dbOptions );
        CachePolicy::NO_CACHE.apply( _dbOptions.get() );

		setProfile(osgEarth::Registry::instance()->getGlobalMercatorProfile());

        return STATUS_OK;
    }

    osg::Image* createImage(const TileKey&        key,
                            ProgressCallback*     progress )
    {
        std::stringstream buf;

        //std::string dataset = 
        //    _options.dataset().isSet() ? _options.dataset().value() : "roads";

		if (_dataset == "satellite")
		{
			if (_version.empty())
				_version = "148";

			char server = getRandomServer();
			unsigned int tile_x, tile_y;
			key.getTileXY(tile_x, tile_y);
			int zoom = key.getLevelOfDetail();

			buf << "http://mt" << server << ".google.cn/maps/vt?lyrs=s%40199&hl=zh-CN&gl=CN&"
				//<< "?v=" << _version
				//<< "&hl=" << _language
				<< "&x=" << tile_x
				<< "&y=" << tile_y
				<< "&z=" << zoom

				<< "&s=Ga&.jpg";
		}
		/*
		else if (_dataset == "traffic")
		{
			char server = getRandomServer();
			unsigned int tile_x, tile_y;
			key.getTileXY(tile_x, tile_y);
			int zoom = key.getLevelOfDetail();

			buf << "http://mt" << server << ".google.com/mapstt"
				<< "?zoom=" << zoom
				<< "&x=" << tile_x
				<< "&y=" << tile_y
				<< "&.png";
		}
		else if (_dataset == "terrain")
		{
			if (_version.empty())
				_version = "w2p.87";

			char server = getRandomServer();
			unsigned int tile_x, tile_y;
			key.getTileXY(tile_x, tile_y);
			buf << "http://mt" << server << ".google.com/mt"
				<< "?v=" << _version
				<< "&hl=" << _language
				<< "&x=" << tile_x
				<< "&y=" << tile_y
				<< "&zoom=" << 17 - key.getLevelOfDetail()
				<< "&.jpg";
		}
		else if (_dataset == "labels")
		{
			if (_version.empty())
				_version = "w2t.92";

			char server = getRandomServer();
			unsigned int tile_x, tile_y;
			key.getTileXY(tile_x, tile_y);
			int zoom = key.getLevelOfDetail();

			buf << "http://mt" << server << ".google.com/mt"
				<< "?v=" << _version
				<< "&hl=" << _language
				<< "&x=" << tile_x
				<< "&y=" << tile_y
				<< "&z=" << zoom
				<< "&s=G&.png";
		}
		else if (_dataset == "roads")
		{
			if (_version.empty())
				_version = "w2.92";

			char server = getRandomServer();
			unsigned int tile_x, tile_y;
			key.getTileXY(tile_x, tile_y);
			int zoom = key.getLevelOfDetail();

			buf << "http://mt" << server << ".google.com/mt"
				<< "?v=" << _version
				<< "&hl=" << _language
				<< "&x=" << tile_x
				<< "&y=" << tile_y
				<< "&z=" << zoom
				<< "&s=Ga&.png";
		}
		*/

        std::string base;
        base = buf.str();

        OE_DEBUG << key.str() << "=" << base << std::endl;

        return URI(base).readImage( _dbOptions.get() ).releaseImage();
    }

    osg::HeightField* createHeightField(const TileKey& key,ProgressCallback*     progress )
    {
        //NI
        OE_WARN << "[Google] Driver does not support heightfields" << std::endl;
        return NULL;
    }

    std::string getExtension()  const 
    {
        //All Google tiles are in JPEG format
		if (_dataset == "satellite") return "jpg";
		else if (_dataset == "terrain") return "jpg";
		else if (_dataset == "labels") return "png";
		else if (_dataset == "roads") return "png";
		else if (_dataset == "traffic") return "png";
		else return "";
    }
    
    /** Tell the terrain engine not to cache tiles form this source. */
    CachePolicy getCachePolicyHint(const Profile*) const
    {
        return CachePolicy::DEFAULT;
    }

private:
	char getRandomServer()
	{
		//Gets a server from 0 - 3
		int server = rand() % 4;
		char serverChar[2];
		sprintf(serverChar, "%i", server);
		return serverChar[0];
	}

private:
    const GoogleOptions           _options;
    osg::ref_ptr<osgDB::Options> _dbOptions;

	std::string _dataset;
	std::string _version;
	std::string _language;

};


class ReaderWriterGoogle : public TileSourceDriver
{
    public:
        ReaderWriterGoogle()
        {
			supportsExtension("osgearth_google", "Google maps imagery");
        }

        virtual const char* className()
        {
			return "Google Imagery ReaderWriter";
        }

        virtual ReadResult readObject(const std::string& file_name, const Options* options) const
        {
            if ( !acceptsExtension(osgDB::getLowerCaseFileExtension( file_name )))
                return ReadResult::FILE_NOT_HANDLED;

            return new GoogleSource( getTileSourceOptions(options) );
        }
};

REGISTER_OSGPLUGIN(osgearth_google, ReaderWriterGoogle)

