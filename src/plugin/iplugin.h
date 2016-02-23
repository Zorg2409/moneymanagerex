
#ifndef IPLUGIN_H
#define IPLUGIN_H
 
#include <wx/wx.h>
#if defined(__WIN32__)
    #define IMPLEMENT_PLUGIN(name) extern "C" __declspec(dllexport) Plugin* CreatePlugin() { return new name();};
#else
    #define IMPLEMENT_PLUGIN(name) extern "C" Plugin* CreatePlugin() { return new name();};
#endif
 
//the plugin interface (a.k.a. abstract class)
//our plugin will contain GUI in itself - therefore we need to make it extend wxEvtHandler (or wxDialog for that matter)
class Plugin : public wxEvtHandler
{
public:
    virtual void PerformTasks()=0;
    virtual wxWindow* GetGUI(wxWindow* parent)=0;   
};
 
//define a function pointer type for convenience
#ifndef __PLUGIN_FUNCTION
#define __PLUGIN_FUNCTION
typedef Plugin* ( *CreatePlugin_function)();
#endif //__PLUGIN_FUNCTION
 
#endif
