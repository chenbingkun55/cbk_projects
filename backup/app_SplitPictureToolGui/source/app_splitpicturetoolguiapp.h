/////////////////////////////////////////////////////////////////////////////
// Name:        app_splitpicturetoolguiapp.h
// Purpose:     
// Author:      ChenBK
// Modified by: 
// Created:     25/06/2016 23:51:30
// RCS-ID:      
// Copyright:   
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _APP_SPLITPICTURETOOLGUIAPP_H_
#define _APP_SPLITPICTURETOOLGUIAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "SplitPictureToolGuiFrame.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * App_SplitPictureToolGuiApp class declaration
 */

class App_SplitPictureToolGuiApp: public wxApp
{    
    DECLARE_CLASS( App_SplitPictureToolGuiApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    App_SplitPictureToolGuiApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin App_SplitPictureToolGuiApp event handler declarations

////@end App_SplitPictureToolGuiApp event handler declarations

////@begin App_SplitPictureToolGuiApp member function declarations

////@end App_SplitPictureToolGuiApp member function declarations

////@begin App_SplitPictureToolGuiApp member variables
////@end App_SplitPictureToolGuiApp member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(App_SplitPictureToolGuiApp)
////@end declare app

#endif
    // _APP_SPLITPICTURETOOLGUIAPP_H_
