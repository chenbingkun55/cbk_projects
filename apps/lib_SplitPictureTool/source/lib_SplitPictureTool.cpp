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
SplitPictureTool::SplitPictureTool(const tstring outPath /*= EMPTY_STRING*/, const tstring setupXmlFile /*= EMPTY_STRING*/)
{
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

		this->initBlockList(root->FirstChildElement("blocks"));
		this->initOffsetList(root->FirstChildElement("offsets"));
	}
	return true;
}

void SplitPictureTool::terminate()
{

}

void SplitPictureTool::initBlockList(TiXmlElement* blocks)
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

void SplitPictureTool::initOffsetList(TiXmlElement* offsets)
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

void SplitPictureTool::process(const tstring picFile)
{
	this->splitProcess(picFile);
	this->finishingFlush();
}

//void SplitPictureTool::process(vector<tstring> picFiles)
//{
//	//for(m_picFiles){
//	this->splitProcess(picFile);
//	this->finishingFlush();
//	//}
//}

void SplitPictureTool::splitProcess(const tstring picFile)
{
	wxImage::AddHandler(new wxPNGHandler);
	wxImageList* imageList = new wxImageList(m_row, m_colmun,true,1);
	wxImage image(picFile,wxBITMAP_TYPE_PNG);
	if (!image.Ok()) {
		wxMessageBox("Load png False");
		return;
	}

	int blockW = image.GetWidth() / m_colmun;
	int blockH = image.GetHeight() / m_row;
	int index = 0;
	for (int col = 0; col < m_colmun; col++)
	{
		for (int row = 0; row < m_row; row++) 
		{
			SPLIT_BLOCK block = m_SplitBlockList[index];
			SPLIT_OFFSET off  = this->getOffset(block.m_Index);

			wxImage image2(image.GetSubImage(wxRect(wxPoint(blockW*col, blockH*row),wxSize(blockW , blockH))));
			imageList->Add(image2);

//			std::cout << index << " -- " << "new Width: " << image2.GetWidth() - off.m_Left << "new Height: " << image2.GetHeight() - off.m_Top << std::endl;
			index++;
		}
	}


	wxMessageBox("Load png true");

	for (int i = 0; i < imageList->GetImageCount(); i++) 
	{

	}
}

SplitPictureTool::SPLIT_OFFSET SplitPictureTool::getOffset(int oIndex)
{
	TV_SPLIT_OFFSET::iterator it = find(m_SplitOffsetList.begin(), m_SplitOffsetList.end(), SPLIT_OFFSET(oIndex));
	if (it == m_SplitOffsetList.end()) 
	{
		return SPLIT_OFFSET();
	}

	return *it;
}

void SplitPictureTool::finishingFlush()
{

}

NS_CBK_END
