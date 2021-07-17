cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)

# Source files
add_library(
        cpp # Library name
        SHARED
        cpp-adapter.cpp
        ../cpp/example.cpp
        # ../../react-native/ReactCommon/jsi/jsi/jsi.cpp
        ../example/node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
)

# Header locations
include_directories(
        ../cpp
        #        ../../react-native/React
        #        ../../react-native/React/Base
        #        ../../react-native/ReactCommon/jsi
        ../example/node_modules/react-native/React
        ../example/node_modules/react-native/React/Base
        ../example/node_modules/react-native/ReactCommon/jsi
)

target_link_libraries(
        cpp # Library name
        android
)
