#ifndef _CRAZINES_H
#define _CRAZINES_H

#include <wx/wx.h>
#include <debug.h>

class MainWindow: public wxFrame
{
  public:
    MainWindow(const wxString &title, const wxPoint &pos, const wxSize &size);
  private:
    void OnOpenROM(wxCommandEvent &event);
    void OnDebugROM(wxCommandEvent &event);
    void OnDebugRegisters(wxCommandEvent &event);
    void OnDebugLog(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnPaint(wxPaintEvent& event);
    wxDECLARE_EVENT_TABLE();
    uint8_t screen[256 * 240 * 3];
};

class wxcraziNES: public wxApp
{
  public:
    virtual bool OnInit();
    MainWindow *frame = NULL;
    MemoryWindow *memory = NULL;
    RegistersWindow *registers = NULL;
    LogWindow *log = NULL;
};

enum
{
    ID_open_rom = 0,

    ID_debug_rom = 10,
    ID_debug_registers = 11,
    ID_debug_log = 12
};

#endif
