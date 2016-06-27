# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (cbk_projects)

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

# SET 
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# CBK 库名
SET(LIB_CBK 
    lib_Base
    lib_SplitPictureTool
    lib_tinyxml
)
# wxWidgets 根目录
SET(wxWidgets_ROOT_DIR "${PROJECT_SOURCE_DIR}/vender/wxWidgets/wxWidgets-3.1.0")


# CBK 头文件
SET(INCLUDE_CBK 
    ${PROJECT_SOURCE_DIR}/libs/lib_Base/source
    ${PROJECT_SOURCE_DIR}/libs/lib_SplitPictureTool/source
    ${PROJECT_SOURCE_DIR}/vender/lib_tinyxml/source
)

# 添加代码 子目录
add_subdirectory(apps/app_SplitPictureTool/source)
add_subdirectory(apps/app_SplitPictureToolGui/source)
add_subdirectory(libs/lib_Base/source)
add_subdirectory(libs/lib_SplitPictureTool/source)
add_subdirectory(vender/lib_tinyxml/source)
