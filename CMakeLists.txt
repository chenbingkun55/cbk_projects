# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (cbk_projects)

# 配置编译器
set(CMAKE_SYSTEM_NAME Linux )

SET (CMAKE_C_COMPILER             "/usr/bin/clang")
SET (CMAKE_C_FLAGS                "-Wall -std=c99")
SET (CMAKE_C_FLAGS_DEBUG          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
SET (CMAKE_CXX_FLAGS                "-Wall")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_AR      "/usr/bin/llvm-ar")
SET (CMAKE_LINKER  "/usr/bin/llvm-ld")
SET (CMAKE_NM      "/usr/bin/llvm-nm")
SET (CMAKE_OBJDUMP "/usr/bin/llvm-objdump")
SET (CMAKE_RANLIB  "/usr/bin/llvm-ranlib")

# 属性开关
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


# 按源目录来Filters
macro(source_group_by_dir source_files)
    if(MSVC)
        set(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
        foreach(sgbd_file ${${source_files}})
            string(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})
            string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
            if(sgbd_nogroup)
                set(sgbd_group_name "\\")
            endif(sgbd_nogroup)
            source_group(${sgbd_group_name} FILES ${sgbd_file})
        endforeach(sgbd_file)
    endif(MSVC)
endmacro(source_group_by_dir)

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_CRT_SECURE_NO_WARNINGS -D__WXMSW__ -D_UNICODE -DWXBUILDING -DwxUSE_ZLIB_H_IN_PATH -DSCI_LEXER -DLINK_LEXERS -DCOMPILED_FROM_DSP")
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()

# wxWidgets 根目录
SET(wxWidgets_ROOT_DIR "${PROJECT_SOURCE_DIR}/libs/lib_wxwidgets")


# 库名
SET(LIB_BASE
    lib_cbk
    lib_png
    lib_jpeg
    lib_zlib
    lib_tinyxml
)



# 头文件
SET(INCLUDE_BASE 
    ${PROJECT_SOURCE_DIR}/cbk
    ${PROJECT_SOURCE_DIR}/cbk/include
    ${PROJECT_SOURCE_DIR}/libs/lib_png/source
    ${PROJECT_SOURCE_DIR}/libs/lib_jpeg/source
    ${PROJECT_SOURCE_DIR}/libs/lib_zlib/source
    ${PROJECT_SOURCE_DIR}/libs/lib_tinyxml/source
    ${PROJECT_SOURCE_DIR}/libs/lib_rapidjson/include
    ${PROJECT_SOURCE_DIR}/libs/lib_wxwidgets/include
    ${PROJECT_SOURCE_DIR}/libs/lib_wxwidgets/include/msvc
)

# apps
#add_subdirectory(apps/app_SplitPictureTool/source)
#add_subdirectory(apps/app_SplitPictureToolGui/source)
add_subdirectory(apps/hello_world)

# libs
add_subdirectory(cbk)
add_subdirectory(libs/lib_jpeg)
add_subdirectory(libs/lib_png)
add_subdirectory(libs/lib_zlib)
add_subdirectory(libs/lib_tinyxml)
#add_subdirectory(libs/lib_wxwidgets)
