/////////////////////////////////////////////////////////////////////////////
// Name:        cbk/setup.h
// Purpose:     
// Author:      ChenBK
// Modified by:
// Created:     2016-06-28
// Copyright:   (c) ChenBK
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef __CBK_SETUP_H__
#define __CBK_SETUP_H__

#ifndef _MSC_VER
    #error "This file should only be included when using Microsoft Visual C++"
#endif

// notice that wxSUFFIX_DEBUG is a string but wxSUFFIX itself must be an
// identifier as string concatenation is not done inside #include where we
// need it
#ifdef _DEBUG
    #define cbkSUFFIX_DEBUG "D"
    #ifdef _UNICODE
        #define wxSUFFIX UD
    #else // !_UNICODE
        #define cbkSUFFIX D
    #endif // _UNICODE/!_UNICODE
#else
    #define cbkSUFFIX_DEBUG ""
    #ifdef _UNICODE
        #define cbkSUFFIX U
    #else // !_UNICODE
        // don't define wxSUFFIX at all as preprocessor operations don't work
        // with empty values so we need to check for this case specially below
    #endif // _UNICODE/!_UNICODE
#endif

// compiler-specific prefix: by default it's always just "vc" for compatibility
// reasons but if you use multiple MSVC versions you probably build them with
// COMPILER_PREFIX=vcXX and in this case you may want to either predefine
// wxMSVC_VERSION as "XX" or define wxMSVC_VERSION_AUTO to use the appropriate
// version depending on the compiler used
#ifdef cbkMSVC_VERSION
    #define cbkCOMPILER_PREFIX wxCONCAT(vc, cbkMSVC_VERSION)
#elif defined(wxMSVC_VERSION_AUTO)
    #if _MSC_VER == 1200
        #define cbkCOMPILER_PREFIX vc60
    #elif _MSC_VER == 1300
        #define cbkCOMPILER_PREFIX vc70
    #elif _MSC_VER == 1310
        #define cbkCOMPILER_PREFIX vc71
    #elif _MSC_VER == 1400
        #define cbkCOMPILER_PREFIX vc80
    #elif _MSC_VER == 1500
        #define cbkCOMPILER_PREFIX vc90
    #elif _MSC_VER == 1600
        #define cbkCOMPILER_PREFIX vc100
    #elif _MSC_VER == 1700
        #define cbkCOMPILER_PREFIX vc110
    #elif _MSC_VER == 1800
        #define cbkCOMPILER_PREFIX vc120
    #elif _MSC_VER == 1900
        #define cbkCOMPILER_PREFIX vc140
    #else
        #error "Unknown MSVC compiler version, please report to dev."
    #endif
#else
    #define cbkCOMPILER_PREFIX vc
#endif

// architecture-specific part: not used (again, for compatibility), for x86
#if defined(_M_X64)
    #define cbkARCH_SUFFIX _x64
#elif defined(_M_IA64)
    #define cbkARCH_SUFFIX _ia64
#else // assume _M_IX86
    #define cbkARCH_SUFFIX
#endif

#endif // __CBK_SETUP_H__
