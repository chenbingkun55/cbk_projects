/////////////////////////////////////////////////////////////////////////////
// Name:        lib_SplitPictureTool.cpp
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////


#include "lib_SplitPictureTool.h"
#include <modules/FileUtil.h>

NS_BEGIN
SplitPictureTool::SplitPictureTool(const tstring picFile, const tstring outPath /*= EMPTY_STRING*/, const tstring setupXmlFile /*= EMPTY_STRING*/)
{
	m_sPicFile = picFile;
	m_sOutPath = outPath;
	m_sSetupXmlFile = setupXmlFile;

}

cbk::SplitPictureTool::~SplitPictureTool()
{

}

bool SplitPictureTool::Initialize()
{
	FileUtil::openFile(m_pPicFile,m_sPicFile);


	return true;
}



void SplitPictureTool::OffsetProcess()
{

}

void SplitPictureTool::SplitProcess()
{

}

void SplitPictureTool::FinishingFlush()
{

}

NS_END
