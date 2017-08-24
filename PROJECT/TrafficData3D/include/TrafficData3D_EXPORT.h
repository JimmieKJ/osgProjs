#ifndef TRAFFICDATA3D_EXPORT_H
#define TRAFFICDATA3D_EXPORT_H

#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)

#ifdef TRAFFICDATA_EXPORT		
#define TRAFFICDATA_API EXPORT
#else
#define TRAFFICDATA_API IMPORT
#endif

#endif