#Add executable called "CampusLex" that is built from the source files
# "*.c". The extensions are automatically found.
# add some lib to header search path
link_directories(/home/chinigami.kun/deploy/)#Add path to linked library
cmake_minimum_required(VERSION 3.18)
file (GLOB sourcefiles "./*.c" "./*.cxx")
#add_executable (CampusLex ./main.c ./lexparser.c)
add_executable (CampusLex ${sourcefiles})
target_include_directories (CampusLex PRIVATE .)
IF(${CMAKE_BUILD_TYPE} MATCHES Debug)
message("Proceed on Debug build...")
target_compile_options(CampusLex PUBLIC -g)
ELSE()
message("Proceed on Release build...")
target_compile_options(CampusLex PUBLIC -O2)
ENDIF()
# Link the executable to the automate library. Since the library has
# public include directories we will use those link directories when building
#  campuslex
target_link_libraries (CampusLex PRIVATE automate)
include_directories(../automate)
