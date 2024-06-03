/*******************************************************************************************
*
*   RhythmDebug v1.0.0 - Tool Description
*
*   MODULE USAGE:
*       #define GUI_RHYTHMDEBUG_IMPLEMENTATION
*       #include "gui_RhythmDebug.h"
*
*       INIT: GuiRhythmDebugState state = InitGuiRhythmDebug();
*       DRAW: GuiRhythmDebug(&state);
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 . All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/

#include "raylib.h"

// WARNING: raygui implementation is expected to be defined before including this header
#undef RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <string.h>     // Required for: strcpy()

#ifndef GUI_RHYTHMDEBUG_H
#define GUI_RHYTHMDEBUG_H

typedef struct {
    // Define anchors
    Vector2 anchor01;            // ANCHOR ID:1
    
    // Define controls variables
    bool WindowBox000Active;            // WindowBox: WindowBox000
    bool BPMVALUEEditMode;
    int BPMVALUEValue;            // ValueBOx: BPMVALUE
    bool NoteEditMode;
    char NoteText[128];            // TextBox: Note
    bool Section_changerEditMode;
    int Section_changerValue;            // Spinner: Section_changer
    bool Note_LEditMode;
    int Note_LValue;            // Spinner: Note_L

    // Define rectangles
    Rectangle layoutRecs[5];

    // Custom state variables (depend on development software)
    // NOTE: This variables should be added manually if required

} GuiRhythmDebugState;

#ifdef __cplusplus
extern "C" {            // Prevents name mangling of functions
#endif

//----------------------------------------------------------------------------------
// Defines and Macros
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
// ...

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
GuiRhythmDebugState InitGuiRhythmDebug(void);
void GuiRhythmDebug(GuiRhythmDebugState *state);

#ifdef __cplusplus
}
#endif

#endif // GUI_RHYTHMDEBUG_H

/***********************************************************************************
*
*   GUI_RHYTHMDEBUG IMPLEMENTATION
*
************************************************************************************/
#if defined(GUI_RHYTHMDEBUG_IMPLEMENTATION)

#include "raygui.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Internal Module Functions Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
GuiRhythmDebugState InitGuiRhythmDebug(void)
{
    GuiRhythmDebugState state = { 0 };

    // Init anchors
    state.anchor01 = (Vector2){ 744, 72 };            // ANCHOR ID:1
    
    // Initilize controls variables
    state.WindowBox000Active = true;            // WindowBox: WindowBox000
    state.BPMVALUEEditMode = false;
    state.BPMVALUEValue = 0;            // ValueBOx: BPMVALUE
    state.NoteEditMode = false;
    strcpy(state.NoteText, "");            // TextBox: Note
    state.Section_changerEditMode = false;
    state.Section_changerValue = 0;            // Spinner: Section_changer
    state.Note_LEditMode = false;
    state.Note_LValue = 0;            // Spinner: Note_L

    // Init controls rectangles
    state.layoutRecs[0] = (Rectangle){ state.anchor01.x + 0, state.anchor01.y + 0, 344, 456 };// WindowBox: WindowBox000
    state.layoutRecs[1] = (Rectangle){ state.anchor01.x + 48, state.anchor01.y + 96, 48, 24 };// ValueBOx: BPMVALUE
    state.layoutRecs[2] = (Rectangle){ 0, 0, 0, 0 };// TextBox: Note
    state.layoutRecs[3] = (Rectangle){ state.anchor01.x + 48, state.anchor01.y + 56, 120, 24 };// Spinner: Section_changer
    state.layoutRecs[4] = (Rectangle){ state.anchor01.x + 48, state.anchor01.y + 144, 120, 24 };// Spinner: Note_L

    // Custom variables initialization

    return state;
}

void GuiRhythmDebug(GuiRhythmDebugState *state)
{
    // Const text
    const char *WindowBox000Text = "Debug menu";    // WINDOWBOX: WindowBox000
    
    // Draw controls
    if (state->WindowBox000Active)
    {
        state->WindowBox000Active = !GuiWindowBox(state->layoutRecs[0], WindowBox000Text);
        if (GuiValueBox(state->layoutRecs[1], BPMVALUEText, &state->BPMVALUEValue, 0, 100, state->BPMVALUEEditMode)) state->BPMVALUEEditMode = !state->BPMVALUEEditMode;
        if (GuiSpinner(state->layoutRecs[3], Section_changerText, &state->Section_changerValue, 0, 100, state->Section_changerEditMode)) state->Section_changerEditMode = !state->Section_changerEditMode;
        if (GuiSpinner(state->layoutRecs[4], Note_LText, &state->Note_LValue, 0, 100, state->Note_LEditMode)) state->Note_LEditMode = !state->Note_LEditMode;
    }
    if (GuiTextBox(state->layoutRecs[2], state->NoteText, 128, state->NoteEditMode)) state->NoteEditMode = !state->NoteEditMode;
}

#endif // GUI_RHYTHMDEBUG_IMPLEMENTATION
