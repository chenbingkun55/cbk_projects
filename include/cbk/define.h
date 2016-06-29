/////////////////////////////////////////////////////////////////////////////
// Name:        cbk/define.h
// Purpose:     
// Author:      ChenBK
// Modified by:
// Created:     2016-06-28
// Copyright:   (c) ChenBK
// Licence:     
/////////////////////////////////////////////////////////////////////////////


#ifndef _CBK_DEFINE_H_
#define _CBK_DEFINE_H_

#include "platform.h"

#define NS_BEGIN                     namespace cbk {
#define NS_END                       }

#define USING_NS                     using namespace cbk

#define EMPTY_STRING ""

typedef std::string tstring;

/*
   Digital Unix C++ compiler only defines this symbol for .cxx and .hxx files,
   so define it ourselves (newer versions do it for all files, though, and
   don't allow it to be redefined)
 */
#if defined(__DECCXX) && !defined(__VMS) && !defined(__cplusplus)
#define __cplusplus
#endif /* __DECCXX */

/*  Resolves linking problems under HP-UX when compiling with gcc/g++ */
#if defined(__HPUX__) && defined(__GNUG__)
#define va_list __gnuc_va_list
#endif /*  HP-UX */

/* Prevents conflicts between sys/types.h and winsock.h with Cygwin, */
/* when using Windows sockets. */
#if defined(__CYGWIN__) && defined(__WINDOWS__)
#define __USE_W32_SOCKETS
#endif

/*  ---------------------------------------------------------------------------- */
/*  check for native bool type and TRUE/FALSE constants */
/*  ---------------------------------------------------------------------------- */

/*  for backwards compatibility, also define TRUE and FALSE */
/*  */
/*  note that these definitions should work both in C++ and C code, so don't */
/*  use true/false below */
#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif

/*  ---------------------------------------------------------------------------- */
/*  portable calling conventions macros */
/*  ---------------------------------------------------------------------------- */

/*  stdcall is used for all functions called by Windows under Windows */
#if defined(__WINDOWS__)
    #if defined(__GNUWIN32__)
        #define wxSTDCALL __attribute__((stdcall))
    #else
        /*  both VC++ and Borland understand this */
        #define wxSTDCALL _stdcall
    #endif

#else /*  Win */
    /*  no such stupidness under Unix */
    #define wxSTDCALL
#endif

#endif /*  _CBK_DEFINE_H_ */
