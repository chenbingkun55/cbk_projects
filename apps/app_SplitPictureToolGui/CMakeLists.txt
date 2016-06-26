# 设置变量
SET(PROJECT_NAME app_SplitPictureToolGui)
SET(SOURCE source)

# 项目信息
project (${PROJECT_NAME})


# 输出文件目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../bin)

# wxWidgets
# 预处理
#add_definitions(-DWIN32)
#add_definitions(-D__WXMSW__)
#add_definitions(-D_WINDOWS)
#add_definitions(-DNOPCH)
#add_definitions(-D_CRT_SECURE_NO_WARNINGS)
#add_definitions(-D_DEBUG)

# 头文件
SET(wxWidgets_INCLUDE_DIRS "${wxWidgets_ROOT_DIR}/include")
INCLUDE_DIRECTORIES(${wxWidgets_INCLUDE_DIRS})

set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})


# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
aux_source_directory(${SOURCE} DIR_SRCS)
aux_source_directory(${SOURCE}/modules DIR_MODULES_SRCS)

SET(SRCS 
	${DIR_SRCS} 
	${DIR_MODULES_SRCS}
)

if(WIN32)
  set(SRCS ${SRCS} app_SplitPictureToolGui.rc)
endif(WIN32)

# 按源目录来Filters
source_group_by_dir(SRCS)

# 指定生成目标 
add_executable(${PROJECT_NAME} WIN32 ${SRCS})

# 指定链接库
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${LIB_SPLITPICTURETOOL} ${wxWidgets_LIBRARIES})
