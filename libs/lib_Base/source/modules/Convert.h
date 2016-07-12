/////////////////////////////////////////////////////////////////////////////
// Name:        Convert.h
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef __CBK_CONVERT_H__
#define __CBK_CONVERT_H__

#include <cbk/cbkprec.h>

NS_CBK_BEGIN
class Convert
{
public:
	Convert();
	virtual ~Convert();

	static void strToint(int& outInt, tstring inStr);
	static void intToStr(tstring& outStr, int inInt);
private:
};
NS_CBK_END
#endif //__CBK_CONVERT_H__