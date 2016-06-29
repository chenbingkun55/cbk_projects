/////////////////////////////////////////////////////////////////////////////
// Name:        FileUtil.cpp
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////


#include <cbk/cbkprec.h>
#include "FileUtil.h"

NS_BEGIN
FileUtil::FileUtil()
{

}


FileUtil::~FileUtil()
{

}



bool FileUtil::loadToString(tstring& outStr, tstring filePath)
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
NS_END