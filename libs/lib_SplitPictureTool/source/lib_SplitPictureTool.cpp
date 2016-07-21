/////////////////////////////////////////////////////////////////////////////
// Name:        lib_SplitPictureTool.cpp
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#include "lib_SplitPictureTool.h"

NS_CBK_BEGIN
SplitPictureTool::SplitPictureTool(const tstring picFile, const tstring outPath /*= EMPTY_STRING*/, const tstring setupXmlFile /*= EMPTY_STRING*/)
{
	m_picFile = picFile;
	m_setupXmlFile = setupXmlFile;
	m_sOutPath = outPath;
	m_setupXmlStr = EMPTY_STRING;
	m_row = 0;
	m_colmun = 0;
	m_SplitBlockList.clear();
	m_SplitOffsetList.clear();
}

SplitPictureTool::~SplitPictureTool()
{

}

bool SplitPictureTool::initialize()
{
	if (!NS_CBK_FILE::loadToString(m_setupXmlStr, m_setupXmlFile))
	{
		return false;
	}
	
	TiXmlDocument doc;
	if (doc.Parse(m_setupXmlStr.c_str()))
	{
		TiXmlElement* root = doc.FirstChildElement("pic");
		TiXmlElement* fromat = root->FirstChildElement("fromat");

		NS_CBK_CONVERT::strToint(m_row,fromat->Attribute("row"));
		NS_CBK_CONVERT::strToint(m_colmun, fromat->Attribute("colmun"));

		this->intBlockList(root->FirstChildElement("blocks"));
		this->intOffsetList(root->FirstChildElement("offsets"));
	}
	return true;
}

void SplitPictureTool::terminate()
{

}

void SplitPictureTool::intBlockList(TiXmlElement* blocks)
{
		TiXmlElement* block = blocks->FirstChildElement("block");
		do
		{
			int index = 0;
			NS_CBK_CONVERT::strToint(index, block->Attribute("index"));
			tstring name = block->Attribute("name");

			if (index > 0 && index <= (m_row * m_colmun))
			{
				m_SplitBlockList.push_back(SPLIT_BLOCK(index, name));
			}
			block = block->NextSiblingElement();
		} while (block);
}

void SplitPictureTool::intOffsetList(TiXmlElement* offsets)
{
	TiXmlElement* offset = offsets->FirstChildElement("offset");
	do
	{
		int index, top, bottom, left, right;
		NS_CBK_CONVERT::strToint(index, offset->Attribute("index"));
		NS_CBK_CONVERT::strToint(top, offset->Attribute("top"));
		NS_CBK_CONVERT::strToint(bottom, offset->Attribute("bottom"));
		NS_CBK_CONVERT::strToint(left, offset->Attribute("left"));
		NS_CBK_CONVERT::strToint(right, offset->Attribute("right"));


		if (index > 0 && index <= (m_row * m_colmun))
		{
			m_SplitOffsetList.push_back(SPLIT_OFFSET(index, top, bottom, left, right));
		}
		offset = offset->NextSiblingElement();
	} while (offset);
}

void SplitPictureTool::process() 
{
	//for(m_picFiles){
	this->splitProcess();
	//}
}

void SplitPictureTool::splitProcess()
{

}

int SplitPictureTool::offsetProcess(int oIndex)
{
	return 0;
}

void SplitPictureTool::finishingFlush()
{

}

NS_CBK_END
