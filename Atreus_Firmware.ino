/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "boobooking's firmware"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-SpaceCadet.h"
#include "Kaleidoscope-MagicCombo.h"
#include "Kaleidoscope-TapDance.h"

#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At LSHIFT(Key_2)
#define Key_Hash LSHIFT(Key_3)
#define Key_Dollar LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret LSHIFT(Key_6)
#define Key_And LSHIFT(Key_7)
#define Key_Star LSHIFT(Key_8)
#define Key_Plus LSHIFT(Key_Equals)

enum {
  MACRO_CHANGE_LANG
};

enum {
  COLEMAKDH,
  FUN,
  NAV,
  NUM,
  UPPER,
  RUSSIAN,
  RUSSIANEX
};

enum {
  TAP_C,
  TAP_V,
  TAP_YO,
  TAP_SHYA,
  TAP_TVERDIY
};

/* *INDENT-OFF* */
KEYMAPS(
  [COLEMAKDH] = KEYMAP_STACKED
  (
       Key_Q      ,Key_W                ,Key_F       ,Key_P       ,Key_B
      ,CTL_T(A)   ,ALT_T(R)             ,GUI_T(S)    ,SFT_T(T)    ,Key_G
      ,Key_Z      ,Key_X                ,TD(TAP_C)   ,Key_D       ,TD(TAP_V)       ,Key_Backtick
      ,Key_Esc    ,MoveToLayer(RUSSIAN) ,Key_LeftGui ,Key_Esc     ,LT(NAV, Space)  ,Key_Tab

                       ,Key_J              ,Key_L               ,Key_U     ,Key_Y      ,Key_Semicolon
                       ,Key_M              ,SFT_T(N)            ,GUI_T(E)  ,ALT_T(I)   ,CTL_T(O)
       ,Key_Backslash  ,Key_K              ,Key_H               ,Key_Comma ,Key_Period ,Key_Slash
       ,Key_Enter      ,LT(NUM, Backspace) ,ShiftToLayer(FUN)   ,Key_Minus ,Key_Quote  ,XXX
  ),

  [FUN] = KEYMAP_STACKED
  (
       Key_Exclamation ,Key_At           ,XXX           ,Key_Dollar           ,Key_Percent
      ,Key_LeftParen   ,XXX              ,XXX           ,XXX                  ,Key_RightParen
      ,Key_LeftBracket ,Key_RightBracket ,Key_Hash      ,Key_LeftCurlyBracket ,Key_RightCurlyBracket  ,Key_Caret
      ,TG(UPPER)       ,Key_Insert       ,Key_LeftGui   ,Key_LeftShift        ,Key_Space              ,Key_LeftControl

                   ,Key_PageUp      ,Key_7        ,Key_8         ,Key_9        ,Key_Backspace
                   ,Key_PageDown    ,SFT_T(4)     ,GUI_T(5)      ,ALT_T(6)     ,CTL_T(0)
      ,Key_And     ,Key_Star        ,Key_1        ,Key_2         ,Key_3        ,Key_Plus
      ,Key_LeftAlt ,Key_Backspace   ,___          ,Key_Period    ,___          ,Key_Equals
   ),

  [NAV] = KEYMAP_STACKED
  (
      LGUI(Key_1)        ,LGUI(Key_2)   ,LGUI(Key_3)   ,LGUI(Key_4)     ,LGUI(Key_5)
      ,Key_LeftControl   ,Key_LeftAlt   ,Key_LeftGui   ,Key_LeftShift   ,XXX
      ,XXX               ,XXX           ,XXX           ,XXX             ,XXX   ,XXX
      ,XXX               ,XXX           ,XXX           ,XXX             ,XXX   ,XXX

             ,LGUI(Key_6)     ,LGUI(Key_7)             ,LGUI(Key_8)                ,LGUI(Key_9)                 ,LGUI(Key_0)
             ,Key_LeftArrow   ,Key_DownArrow           ,Key_UpArrow                ,Key_RightArrow              ,LGUI(Key_Tab)
      ,XXX   ,XXX             ,LGUI(Key_LeftBracket)   ,LGUI(Key_RightBracket)     ,LALT(LGUI(Key_LeftArrow))   ,LALT(LGUI(Key_RightArrow))
      ,XXX   ,XXX             ,XXX                     ,XXX                        ,XXX                         ,XXX
  ),

  [NUM] = KEYMAP_STACKED
  (
       XXX     ,Key_7   ,Key_8   ,Key_9   ,XXX
      ,Key_0   ,Key_1   ,Key_2   ,Key_3   ,XXX
      ,XXX     ,Key_4   ,Key_5   ,Key_6   ,XXX   ,XXX
      ,XXX     ,XXX     ,XXX     ,___     ,___   ,___

             ,XXX              ,XXX             ,XXX              ,XXX            ,XXX
             ,Key_Backspace,   Key_RightShift   ,Key_LeftGui      ,Key_RightAlt   ,Key_RightControl
      ,XXX   ,XXX              ,XXX             ,XXX              ,XXX            ,XXX
      ,___   ,___              ,___             ,XXX              ,XXX            ,XXX
  ),

  [UPPER] = KEYMAP_STACKED
  (
       Key_Insert              ,Key_Home                 ,Key_UpArrow   ,Key_End        ,Key_PageUp
      ,Key_Delete              ,Key_LeftArrow            ,Key_DownArrow ,Key_RightArrow ,Key_PageDown
      ,___                     ,Consumer_VolumeIncrement ,XXX           ,XXX            ,___ ,___
      ,MoveToLayer(COLEMAKDH)  ,Consumer_VolumeDecrement ,___           ,___            ,___ ,___

                ,Key_UpArrow   ,Key_F7                  ,Key_F8           ,Key_F9          ,Key_F10
                ,Key_DownArrow ,Key_F4                  ,Key_F5           ,Key_F6          ,Key_F11
      ,___      ,XXX           ,Key_F1                  ,Key_F2           ,Key_F3          ,Key_F12
      ,___      ,___           ,MoveToLayer(COLEMAKDH)  ,Key_PrintScreen  ,Key_ScrollLock  ,Consumer_PlaySlashPause
   ),

  [RUSSIAN] = KEYMAP_STACKED
  (
       Key_Q      ,Key_W                   ,Key_E        ,Key_R       ,TD(TAP_YO)
      ,CTL_T(A)   ,LT(RUSSIANEX, S)        ,GUI_T(D)     ,SFT_T(F)    ,Key_G
      ,Key_Z      ,Key_X                   ,Key_C        ,Key_V       ,Key_B       ,Key_Backtick
      ,Key_Esc    ,MoveToLayer(COLEMAKDH)  ,Key_LeftGui  ,Key_Esc     ,Key_Space   ,Key_Tab

                       ,Key_Y          ,Key_U             ,TD(TAP_SHYA)   ,Key_P             ,Key_LeftBracket
                       ,Key_H          ,SFT_T(J)          ,GUI_T(K)       ,LT(RUSSIANEX, L)  ,CTL_T(Semicolon)
       ,Key_Backslash  ,Key_N          ,TD(TAP_TVERDIY)   ,Key_Comma      ,Key_Period        ,Key_Quote
       ,Key_Enter      ,Key_Backspace  ,MO(FUN)           ,Key_Minus      ,Key_Quote         ,Key_Enter
  ),

  [RUSSIANEX] = KEYMAP_STACKED
  (
       XXX   ,XXX   ,XXX   ,XXX   ,Key_Backslash
      ,XXX   ,XXX   ,XXX   ,XXX   ,XXX
      ,XXX   ,XXX   ,XXX   ,XXX   ,XXX   ,XXX
      ,XXX   ,XXX   ,XXX   ,___   ,___   ,___

             ,XXX   ,XXX                ,Key_O  ,XXX  ,XXX
             ,XXX   ,XXX                ,XXX    ,XXX  ,XXX
      ,XXX   ,XXX   ,Key_RightBracket   ,XXX    ,XXX  ,XXX
      ,___   ,___   ,___                ,XXX    ,XXX  ,XXX
  ),
)
/* *INDENT-ON* */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_CHANGE_LANG:
    if (keyToggledOn(keyState)) {
      return MACRO(
        D(LeftShift), D(LeftControl), D(LeftGui), D(LeftAlt), T(Q), U(LeftAlt), U(LeftGui), U(LeftControl), U(LeftShift)
        );
    }
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void tapDanceAction(uint8_t tapDanceIndex, KeyAddr key_addr, uint8_t tapCount, kaleidoscope::plugin::TapDance::ActionType tapDanceActionType) {
  switch (tapDanceIndex) {
    case TAP_C:
    return tapDanceActionKeys(
        tapCount, tapDanceActionType, Key_C, LGUI(Key_C)
      );
    case TAP_V:
    return tapDanceActionKeys(
        tapCount, tapDanceActionType, Key_V, LGUI(Key_V)
      );
    case TAP_YO:
    return tapDanceActionKeys(
        tapCount, tapDanceActionType, Key_T, Key_Backslash
      );
    case TAP_SHYA:
    return tapDanceActionKeys(
        tapCount, tapDanceActionType, Key_I, Key_O
      );
    case TAP_TVERDIY:
    return tapDanceActionKeys(
        tapCount, tapDanceActionType, Key_M, Key_RightBracket
      );
  }
}

KALEIDOSCOPE_INIT_PLUGINS(
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Qukeys,
  SpaceCadet,
  OneShot,
  Macros,
  TapDance
);

void setup() {
  Kaleidoscope.setup();
  SpaceCadet.disable();
  EEPROMKeymap.setup(10);
}

void loop() {
  Kaleidoscope.loop();
}
