SET(TARGET_SRC ReaderWriterGoogle.cpp)
SET(TARGET_H GoogleOptions)
SETUP_PLUGIN(osgearth_google)

# to install public driver includes:
SET(LIB_NAME google)
SET(LIB_PUBLIC_HEADERS GoogleOptions)
INCLUDE(ModuleInstallOsgEarthDriverIncludes OPTIONAL)

