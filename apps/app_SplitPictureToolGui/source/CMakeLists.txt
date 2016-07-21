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


#set(wxWidgets_CONFIGURATION mswu)
#find_package(wxWidgets COMPONENTS core base REQUIRED)
#include(${wxWidgets_USE_FILE})
 

# 指定生成目标
# 输出文件目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../../bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../../bin)

add_executable(${PROJECT_NAME} WIN32 ${ALL_FILES})

### 指定链接库
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    ${LIB_CBK}
#    ${wxWidgets_LIBRARIES}
)