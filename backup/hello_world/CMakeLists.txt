﻿# 设置变量
SET(PROJECT_NAME HelloWorld)

# 项目信息
project (${PROJECT_NAME})

### CBK 头文件
INCLUDE_DIRECTORIES(
    ${INCLUDE_BASE}
)

### 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
AUX_SOURCE_DIRECTORY(./source ALL_FILES)

# 按源目录来Filters
source_group_by_dir(ALL_FILES)

# 指定生成目标
# 输出文件目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${ALL_FILES})

### 指定链接库
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    ${LIB_BASE}
)
