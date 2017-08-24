# configureshaders.cmake.in

set(source_dir      "D:/PROJECT/osgEarth/src/osgEarth")
set(bin_dir         "D:/PROJECT/osgEarth/src/osgEarth")
set(glsl_files      "AlphaEffect.frag.glsl;DepthOffset.vert.glsl;Draping.vert.glsl;Draping.frag.glsl;GPUClamping.vert.glsl;GPUClamping.vert.lib.glsl;GPUClamping.frag.glsl;Instancing.vert.glsl")
set(template_file   "Shaders.cpp.in")
set(output_cpp_file "D:/PROJECT/osgEarth/src/osgEarth/AutoGenShaders.cpp")

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
