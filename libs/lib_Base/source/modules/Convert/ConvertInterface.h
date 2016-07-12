/////////////////////////////////////////////////////////////////////////////
// Name:        Convert.h
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef __CBK_CONVERT_INTERFACE_H__
#define __CBK_CONVERT_INTERFACE_H__

#include <cbk/cbkprec.h>

NS_CBK_BEGIN
NS_CBK_CONVERT_BEGIN

	void strToint(int& outInt, tstring inStr);
	void intToStr(tstring& outStr, int inInt);

NS_CBK_CONVERT_END
NS_CBK_END
#endif //__CBK_CONVERT_INTERFACE_H__