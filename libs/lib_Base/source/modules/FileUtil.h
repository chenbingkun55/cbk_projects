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

#include <cbk/cbkprec.h>

NS_BEGIN
class FileUtil
{
public:
	FileUtil() ;
	virtual ~FileUtil() ;

	static bool loadToString(tstring& outStr, tstring filePath);
private:
};
NS_END
#endif //__CBK_FILE_UTIL_H__