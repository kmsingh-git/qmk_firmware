// Copyright 2023 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET

#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP22
#define I2C1_SCL_PIN GP23

#define AUDIO_PIN GP28
#define AUDIO_PWM_DRIVER PWMD6
#define AUDIO_INIT_DELAY
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A

#define ANALOG_JOYSTICK_Y_AXIS_PIN GP26
#define ANALOG_JOYSTICK_X_AXIS_PIN GP27
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_INVERT_X

#define TAPPING_TERM 185
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD // Must define chordal layout with this, and exclude thumb cluster by using *
#define QUICK_TAP_TERM 0
#define FLOW_TAP_TERM 100

#define NO_AUTO_SHIFT_TAB
#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_ALPHA

// #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD // Double tap Left Shift - see docs // This won't work with home row mods obviously. 
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 5000  // 5 seconds.

// rgb stuff
#define RGB_MATRIX_TIMEOUT 60000
#define SPLIT_RGB_MATRIX_ENABLE
#define SPLIT_TRANSPORT_MIRROR