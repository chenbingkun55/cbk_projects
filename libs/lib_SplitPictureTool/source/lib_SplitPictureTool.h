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

#include <BaseDef.h>

NS_BEGIN
class SplitPictureTool 
{
public:
	typedef struct SPLIT_OFFSET_TAG
	{
	public:
		SPLIT_OFFSET_TAG(int top = 0, int bottom = 0, int left = 0, int right = 0)
		{
			m_Top = top;
			m_Bottom = bottom;
			m_Left = left;
			m_Rigtht = right;
		}

	private:
		int m_Top;
		int m_Bottom;
		int m_Left;
		int m_Rigtht;
	}SPLIT_OFFSET;
	typedef std::vector<SPLIT_OFFSET*> TV_SPLIT_OFFSET;

public:
	SplitPictureTool(const tstring picFile, const tstring outPath = EMPTY_STRING, const tstring setupXmlFile = EMPTY_STRING);
	virtual ~SplitPictureTool();

	bool Initialize();
	void SplitProcess();
	void OffsetProcess();
	void FinishingFlush();

private:
	tstring m_sPicFile;
	tstring m_sOutPath;
	tstring m_sSetupXmlFile;

	std::fstream* m_pPicFile;
	TV_SPLIT_OFFSET* m_SplitOffsetList;
};

NS_END
#endif //__CBK_LIB_SPLIT_PICTURE_TOOL_H__