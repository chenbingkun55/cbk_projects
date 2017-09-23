/////////////////////////////////////////////////////////////////////////////
// Name:        lib_SplitPictureTool.h
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef __CBK_LIB_SPLIT_PICTURE_TOOL_H__
#define __CBK_LIB_SPLIT_PICTURE_TOOL_H__

#include <cbk/cbkprec.h>

NS_CBK_BEGIN
class SplitPictureTool 
{
public:
	typedef struct SPLIT_BLOCK_TAG
	{
	public:
		SPLIT_BLOCK_TAG(int index = 0, tstring picName = EMPTY_STRING)
		{
			m_Index = index;
			m_PicName = picName;
		}

	public:
		int m_Index;
		tstring m_PicName;
	}SPLIT_BLOCK;

	typedef struct SPLIT_OFFSET_TAG
	{
	public:
		SPLIT_OFFSET_TAG(int index = 0, int top = 0, int bottom = 0, int left = 0, int right = 0)
		{
			m_Index = index;
			m_Top = top;
			m_Bottom = bottom;
			m_Left = left;
			m_Rigtht = right;
		}

		bool operator ==(const SPLIT_OFFSET_TAG& tmp) const
		{
			return tmp.m_Index == m_Index;
		}

	public:
		int m_Index;
		int m_Top;
		int m_Bottom;
		int m_Left;
		int m_Rigtht;
	}SPLIT_OFFSET;
	typedef std::vector<SPLIT_BLOCK> TV_SPLIT_BLOCK;
	typedef std::vector<SPLIT_OFFSET> TV_SPLIT_OFFSET;

public:
	SplitPictureTool(const tstring outPath = EMPTY_STRING, const tstring setupXmlFile = EMPTY_STRING);
	virtual ~SplitPictureTool();

	bool initialize();
	void terminate();

	void initBlockList(TiXmlElement* blocks);
	void initOffsetList(TiXmlElement* offsets);

	void process(const tstring picFile);
	void splitProcess(const tstring picFile);
	SPLIT_OFFSET getOffset(int oIndex);
	void finishingFlush();

private:
	int m_row;
	int m_colmun;
	tstring m_sOutPath;
	tstring m_setupXmlFile;
	tstring m_setupXmlStr;

	TV_SPLIT_BLOCK m_SplitBlockList;
	TV_SPLIT_OFFSET m_SplitOffsetList;
};


NS_CBK_END
#endif //__CBK_LIB_SPLIT_PICTURE_TOOL_H__