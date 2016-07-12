/////////////////////////////////////////////////////////////////////////////
// Name:        ConvertUtil.cpp
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////


#include <cbk/cbkprec.h>
#include "ConvertImplement.h"

NS_CBK_BEGIN
NS_CBK_CONVERT_BEGIN

void strToint(int& outInt, tstring inStr)
{
	outInt = 0;
	outInt = atoi(inStr.c_str());
}


void intToStr(tstring& outStr, int inInt)
{
	//std::stringstream ss;
	//ss << inInt;
	//ss >> outStr;
}

NS_CBK_CONVERT_END
NS_CBK_END

