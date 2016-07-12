/////////////////////////////////////////////////////////////////////////////
// Name:        FileUtil.cpp
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////


#include <cbk/cbkprec.h>
#include "FileImplement.h"

NS_CBK_BEGIN
NS_CBK_FILE_BEGIN

bool loadToString(tstring& outStr, tstring filePath)
{
	if(filePath.empty()) return FALSE;

	std::ifstream ifs(filePath, std::ifstream::binary);
	if (!ifs) 
	{
		std::cout << "file load faild.";
		return FALSE;
	}

	std::filebuf* pbuf = ifs.rdbuf();
	std::size_t size = (std::size_t)pbuf->pubseekoff(0, ifs.end, ifs.in);
	
	pbuf->pubseekpos(0, ifs.in);
	char* buffer = new char[size];
	pbuf->sgetn(buffer, size);
	outStr = buffer;

	ifs.close();
	delete[] buffer;
	return TRUE;
}

void printWorld()
{
	std::cout << "Hello World!\n" << std::endl;
}

NS_CBK_FILE_END
NS_CBK_END