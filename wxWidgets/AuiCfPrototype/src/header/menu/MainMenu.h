#pragma once
#include "wx/wx.h"

wxMenu* createFileMenu();
void updateFileMenu(wxMenu* menu);
wxMenu* createViewMenu();
void updateViewMenu(wxMenu* menu);
wxMenu* createEditMenu();
void updateEditMenu(wxMenu* menu);
wxMenu* createEffectsMenu();
void updateEffectsMenu(wxMenu* menu);
wxMenu* createConfigurationMenu();
void updateConfigurationMenu(wxMenu* menu);
wxMenu* createHelpMenu();
void updateHelpMenu(wxMenu* menu);
wxMenu* createWindowMenu();
void updateWindowMenu(wxMenu* menu);