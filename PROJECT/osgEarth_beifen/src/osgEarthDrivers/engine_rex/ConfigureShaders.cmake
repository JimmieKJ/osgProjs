# configureshaders.cmake.in

set(source_dir      "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex")
set(bin_dir         "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex")
set(glsl_files      "RexEngine.vert.glsl;RexEngine.vert.view.glsl;RexEngine.tcs.glsl;RexEngine.tes.glsl;RexEngine.gs.glsl;RexEngine.frag.glsl;RexEngine.NormalMap.vert.glsl;RexEngine.NormalMap.frag.glsl;RexEngine.Morphing.vert.glsl;RexEngine.SDK.vert.glsl")
set(template_file   "Shaders.cpp.in")
set(output_cpp_file "D:/PROJECT/osgEarth/src/osgEarthDrivers/engine_rex/AutoGenShaders.cpp")

# modify the contents for inlining; replace input with output (var: file)
# i.e., the file name (in the form ) gets replaced with the
# actual contents of the named file and then processed a bit.
foreach(file ${glsl_files})

    # read the file into 'contents':
    file(READ ${source_dir}/${file} contents)

    # append a newline so we do not break the MULTILINE macro when the last line
    # of the file is a comment:
    set(contents "${contents}\n")

    # replace hashtags with a marker string to avoid breaking the MULTILINE macro:
	string(REGEX REPLACE "#" "$__HASHTAG__" tempString "${contents}")

    # replace newlines with printable newlines, and overwrite the original
    # file name with the processed contents.
	string(REGEX REPLACE "\n" "\\\\n\n" ${file} "${tempString}")

endforeach(file)

# send the processed glsl_files to the next template to create the
# shader source file.
configure_file(
	${source_dir}/${template_file}
	${output_cpp_file}
	@ONLY )
