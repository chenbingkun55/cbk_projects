/////////////////////////////////////////////////////////////////////////////
// Name:        cbk/chkconf.h
// Purpose:     
// Author:      ChenBK
// Modified by:
// Created:     2016-06-28
// Copyright:   (c) ChenBK
// Licence:     
/////////////////////////////////////////////////////////////////////////////
///
#ifndef _CBK_CHKCONF_H_
#define _CBK_CHKCONF_H_

#define cbkABORT_ON_CONFIG_ERROR

/*
   global features
 */

#ifndef cbkUSE_ANY
#   ifdef cbkABORT_ON_CONFIG_ERROR
#       error "cbkUSE_ANY must be defined, please read comment near the top of this file."
#   else
#       define cbkUSE_ANY 0
#   endif
#endif /* cbkUSE_ANY */

#ifndef cbkUSE_XML
#   ifdef cbkABORT_ON_CONFIG_ERROR
#       error "cbkUSE_XML must be defined, please read comment near the top of this file."
#   else
#       define cbkUSE_XML 0
#   endif
#endif /* !defined(cbkUSE_XML) */

#endif /* _CBK_CHKCONF_H_ */
