#Create a library called "automate" which includes the source file "main.c".
# The extension is already found. Any number of sources could be listed here.
add_library (automate SHARED ./main.c)
set_target_properties(automate PROPERTIES VERSION 1)
set_target_properties(automate PROPERTIES SOVERSION 1)

# Make sure the compiler can find include files for our automate library
# when other libraries or executables link to automate
target_include_directories (automate PRIVATE .)
target_include_directories (automate PUBLIC inc/)
