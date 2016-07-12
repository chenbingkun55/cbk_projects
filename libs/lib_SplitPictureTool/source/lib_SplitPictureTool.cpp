/////////////////////////////////////////////////////////////////////////////
// Name:        lib_SplitPictureTool.cpp
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#include <cbk/cbkprec.h>
#include "lib_SplitPictureTool.h"

NS_CBK_BEGIN
SplitPictureTool::SplitPictureTool(const tstring picFile, const tstring outPath /*= EMPTY_STRING*/, const tstring setupXmlFile /*= EMPTY_STRING*/)
{
	if (!NS_CBK_FILE::loadToString(m_SetupXmlString, setupXmlFile)) return;
	m_sOutPath = outPath;
	m_row = 0;
	m_colmun = 0;
}

SplitPictureTool::~SplitPictureTool()
{

}

bool SplitPictureTool::initialize()
{
	TiXmlDocument doc;

	if (doc.Parse(m_SetupXmlString.c_str()))
	{
		TiXmlElement* root = doc.FirstChildElement("pic");
		TiXmlElement* fromat = root->FirstChildElement("fromat");

		Convert::strToint(m_row,fromat->Attribute("row"));
		Convert::strToint(m_colmun, fromat->Attribute("colmun"));

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
			Convert::strToint(index, block->Attribute("index"));
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
		Convert::strToint(index, offset->Attribute("index"));
		Convert::strToint(top, offset->Attribute("top"));
		Convert::strToint(bottom, offset->Attribute("bottom"));
		Convert::strToint(left, offset->Attribute("left"));
		Convert::strToint(right, offset->Attribute("right"));


		if (index > 0 && index <= (m_row * m_colmun))
		{
			m_SplitOffsetList.push_back(SPLIT_OFFSET(index, top, bottom, left, right));
		}
		offset = offset->NextSiblingElement();
	} while (offset);
}

void SplitPictureTool::splitProcess()
{

}

void SplitPictureTool::offsetProcess()
{

}

void SplitPictureTool::finishingFlush()
{

}

NS_CBK_END
