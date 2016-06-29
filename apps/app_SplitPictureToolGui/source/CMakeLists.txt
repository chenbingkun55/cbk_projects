# 设置变量
SET(PROJECT_NAME app_SplitPictureToolGui)

project(${PROJECT_NAME})
cmake_minimum_required(VERSION 2.8)

### 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
file(GLOB_RECURSE DIR_SRCS ${PROJECT_SOURCE_DIR} "*.cpp")
file(GLOB_RECURSE DIR_HEADER ${PROJECT_SOURCE_DIR} "*.h")

SET(ALL_FILES 
    ${DIR_SRCS} 
    ${DIR_HEADER}
)

 # 按源目录来Filters
source_group_by_dir(ALL_FILES)


set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
 
add_executable(${PROJECT_NAME} WIN32 ${ALL_FILES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})