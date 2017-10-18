cmake_minimum_required(VERSION 3.4.1)

include_directories(
    ${CMAKE_SOURCE_DIR}/libs/include)

add_library(jpeg SHARED IMPORTED)
set_target_properties(jpeg PROPERTIES IMPORTED_LOCATION  ${CMAKE_SOURCE_DIR}/libs/libjpeg/${ANDROID_ABI}/libjpeg.so)

add_library( native-lib
             SHARED
             src/main/cpp/native-lib.cpp )


find_library(log-lib
              log )

target_link_libraries( native-lib
                       jpeg
                       ${log-lib} )