# See the build system documentation in IDF programming guide
# for more information about component CMakeLists.txt files.

idf_component_register(
    SRCS    "main.c" 
            "drivers/i2c/i2c_wrapper.c"        # list the source files of this component
    INCLUDE_DIRS    "." 
                    "drivers/i2c" 
                    "platform" "sensors/lis3mdl"   # optional, add here public include directories
    PRIV_INCLUDE_DIRS   # optional, add here private include directories
    REQUIRES       # optional, list the public requirements (component names)
    PRIV_REQUIRES       # optional, list the private requirements
)
