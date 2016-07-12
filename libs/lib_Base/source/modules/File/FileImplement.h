/////////////////////////////////////////////////////////////////////////////
// Name:        File_impl.h
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef __CBK_FILE_IMPLEMENT_H__
#define __CBK_FILE_IMPLEMENT_H__

#include <cbk/cbkprec.h>
#include "FileInterface.h"

NS_CBK_BEGIN
NS_CBK_FILE_BEGIN

	bool loadToString(tstring& outStr, tstring filePath);
	void printWorld();
	
NS_CBK_FILE_END
NS_CBK_END

#endif //__CBK_FILE_IMPLEMENT_H__