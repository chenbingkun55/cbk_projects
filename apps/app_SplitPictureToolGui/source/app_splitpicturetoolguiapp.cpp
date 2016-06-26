/////////////////////////////////////////////////////////////////////////////
// Name:        app_splitpicturetoolguiapp.cpp
// Purpose:     
// Author:      ChenBK
// Modified by: 
// Created:     25/06/2016 23:51:30
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "app_splitpicturetoolguiapp.h"

////@begin XPM images
////@end XPM images


/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( App_SplitPictureToolGuiApp )
////@end implement app


/*
 * App_SplitPictureToolGuiApp type definition
 */

IMPLEMENT_CLASS( App_SplitPictureToolGuiApp, wxApp )


/*
 * App_SplitPictureToolGuiApp event table definition
 */

BEGIN_EVENT_TABLE( App_SplitPictureToolGuiApp, wxApp )

////@begin App_SplitPictureToolGuiApp event table entries
////@end App_SplitPictureToolGuiApp event table entries

END_EVENT_TABLE()


/*
 * Constructor for App_SplitPictureToolGuiApp
 */

App_SplitPictureToolGuiApp::App_SplitPictureToolGuiApp()
{
    Init();
}


/*
 * Member initialisation
 */

void App_SplitPictureToolGuiApp::Init()
{
////@begin App_SplitPictureToolGuiApp member initialisation
////@end App_SplitPictureToolGuiApp member initialisation
}

/*
 * Initialisation for App_SplitPictureToolGuiApp
 */

bool App_SplitPictureToolGuiApp::OnInit()
{    
////@begin App_SplitPictureToolGuiApp initialisation
	// Remove the comment markers above and below this block
	// to make permanent changes to the code.

#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	SplitPictureToolGuiFrame* mainWindow = new SplitPictureToolGuiFrame( NULL );
	mainWindow->Show(true);
////@end App_SplitPictureToolGuiApp initialisation

    return true;
}


/*
 * Cleanup for App_SplitPictureToolGuiApp
 */

int App_SplitPictureToolGuiApp::OnExit()
{    
////@begin App_SplitPictureToolGuiApp cleanup
	return wxApp::OnExit();
////@end App_SplitPictureToolGuiApp cleanup
}

