/////////////////////////////////////////////////////////////////////////////
// Name:        FileUtil.cpp
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#include "FileUtil.h"
#include <fstream>

NS_BEGIN

bool FileUtil::openFile(std::fstream* outTream, tstring file)
{
	std::fstream* fs;
	fs->open(file);

	outTream = fs;
	return true;
}

NS_END
