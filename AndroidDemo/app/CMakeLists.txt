cmake_minimum_required(VERSION 3.4.1)

set(SRC_DIR ../../GDMMCore)

file(GLOB_RECURSE native_src "${SRC_DIR}/*.cpp")

add_library( GDMMCore
             SHARED
             ${native_src} )

find_library( log-lib
              log )

target_link_libraries( GDMMCore
                       GLESv2
                       EGL
                       android
                       ${log-lib} )