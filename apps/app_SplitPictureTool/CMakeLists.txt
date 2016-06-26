# 设置变量
SET(PROJECT_NAME app_SplitPictureTool)
SET(SOURCE source)

# 项目信息
project (${PROJECT_NAME})

# 输出文件目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../bin)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(${SOURCE} DIR_SRCS)
aux_source_directory(${SOURCE}/modules DIR_MODULES_SRCS)

SET(SRCS 
	${DIR_SRCS} 
	${DIR_MODULES_SRCS}
)

# 按源目录来Filters
source_group_by_dir(SRCS)

# 指定生成目标 
add_executable(${PROJECT_NAME} ${SRCS})

# 指定链接库
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CBK_LIB})