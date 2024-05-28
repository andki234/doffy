# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

# Include the ESP-IDF project.cmake file
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Include the main and drivers/i2c directories
#add_subdirectory(main)
#add_subdirectory(drivers/i2c)

# Add the drivers directory to the include path
include_directories("drivers")
include_directories("drivers/i2c")
include_directories("platform")

# Set the name of the project
project(doffy)
