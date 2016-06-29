/////////////////////////////////////////////////////////////////////////////
// Name:        Convert.cpp
// Purpose:     
// Author:      ChenBK
// Created:     2016/06/26
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////


#include <cbk/cbkprec.h>
#include "Convert.h"

NS_BEGIN
Convert::Convert()
{

}


Convert::~Convert()
{

}


void Convert::strToint(int& outInt, tstring inStr)
{
	outInt = 0;
	outInt = atoi(inStr.c_str());
}


void Convert::intToStr(tstring& outStr, int inInt)
{
	//std::stringstream ss;
	//ss << inInt;
	//ss >> outStr;
}

NS_END

