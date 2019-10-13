# 设置变量
SET(PROJECT_NAME lib_gloox) # 修改 app_NAME 为新项目名称

# 项目信息
project (${PROJECT_NAME})

### 头文件
INCLUDE_DIRECTORIES(
    /usr/include/gnutls
    /usr/local/include/cbk/lib_gloox
)

### 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
AUX_SOURCE_DIRECTORY(./source ALL_FILES)

# 按源目录来Filters
source_group_by_dir(ALL_FILES)

# 指定生成目标
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../output/libs)

# 生成链接库
add_library(${PROJECT_NAME} ${ALL_FILES})

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")
#SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C)

# INSTALL(DIRECTORY ./source/
#     DESTINATION include/cbk/lib_gloox
#     FILES_MATCHING PATTERN "*.h"
#     )
#
# INSTALL(TARGETS ${PROJECT_NAME}
#     DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
#     )
