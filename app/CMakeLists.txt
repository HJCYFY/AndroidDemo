cmake_minimum_required(VERSION 3.4.1)

set(libjpeg_dir ${CMAKE_SOURCE_DIR}/libs)
set(INC_DIR ${libjpeg_dir}/include)
set(libjpeg_lib_dir ${libjpeg_dir}/libjpeg)

include_directories(${INC_DIR}
                    ${CMAKE_SOURCE_DIR}/src/main/cpp/
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenPano/
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenPano/third_Part/)

# find sources
file(GLOB SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenPano/feature/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenPano/stitch/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/OpenPano/lib/*.cpp)


add_library( native-lib
             SHARED
             src/main/cpp/native-lib.cpp
             src/main/cpp/imread.cpp
             src/main/cpp/imwrite.cpp
             ${SOURCES}
             )

find_library(log-lib
             log )
add_library(libjpeg SHARED IMPORTED)
set_target_properties(libjpeg PROPERTIES IMPORTED_LOCATION ${libjpeg_lib_dir}/${ANDROID_ABI}/libjpeg.so)


target_link_libraries( native-lib
                       libjpeg
                       ${log-lib} )