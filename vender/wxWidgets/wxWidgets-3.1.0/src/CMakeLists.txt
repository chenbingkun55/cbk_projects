# 设置变量
SET(PROJECT_NAME lib_wxWidgets) # 修改 app_NAME 为新项目名称

# 项目信息
project (${PROJECT_NAME})

### CBK 头文件
INCLUDE_DIRECTORIES(
    ${INCLUDE_CBK}
)

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

# 指定生成目标
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../../bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../../bin)

# 生成链接库
add_library(${PROJECT_NAME} ${ALL_FILES})