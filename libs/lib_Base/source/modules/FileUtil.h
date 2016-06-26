/////////////////////////////////////////////////////////////////////////////
// Name:        FileUtil.h
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef __CBK_FILE_UTIL_H__
#define __CBK_FILE_UTIL_H__

#include <BaseDef.h>

NS_BEGIN
class FileUtil 
{
public:
	FileUtil();
	virtual ~FileUtil();

public:
	static bool openFile(std::fstream* outTream, tstring file);

};

NS_END
#endif //__CBK_FILE_UTIL_H__