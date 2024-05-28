# See the build system documentation in IDF programming guide
# for more information about component CMakeLists.txt files.

idf_component_register(
    SRCS "i2c_wrapper.c"
    INCLUDE_DIRS "." "/platform"
)