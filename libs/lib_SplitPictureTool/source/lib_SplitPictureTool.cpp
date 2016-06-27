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
#include <tinyxml.h>
#include <tinystr.h>


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
	//FileUtil::openFile(m_pPicFile,m_sPicFile);
	TiXmlDocument doc("setup.xml");
	bool YesNo = doc.LoadFile();

	if (YesNo) 
	{
		TiXmlElement* root = doc.FirstChildElement("pic");
		TiXmlElement* fromat = doc.FirstChildElement("fromat");

		tstring m_Row = fromat->Attribute("row");
		tstring m_Colmun = fromat->Attribute("colmun");

		TiXmlElement* blocks = root->FirstChildElement("ps");
		/*do
		{
			int index = (int)blocks->Attribute("index");
			tstring name = (tstring)blocks->Attribute("name");

			if (index > 0 && index <= (m_Row * m_Colmun))
			{
				m_SplitBlockList[index].push_back(new SPLIT_BLOCK(index));
			}
		} while (blocks->NextSiblingElement());


		TiXmlElement* offsets = root->FirstChildElement("offset");
		do
		{
			int index = (int)offsets->Attribute("index");
			int top = (int)offsets->Attribute("top");
			int bottom = (int)offsets->Attribute("bottom");
			int left = (int)offsets->Attribute("left");
			int right = (int)offsets->Attribute("right");

			if (index > 0 && index <= (m_Row * m_Colmun))
			{
				m_SplitOffsetList[index].push_back(new SPLIT_OFFSET(index, top, bottom, left, right));
			}
		} while (offsets->NextSiblingElement());*/
	}
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
