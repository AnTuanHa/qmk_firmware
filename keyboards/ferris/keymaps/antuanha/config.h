/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

// Pick good defaults for enabling homerow modifiers
// #define TAPPING_TERM 150
// #define IGNORE_MOD_TAP_INTERRUPT
// #define TAPPING_FORCE_HOLD
// #define PERMISSIVE_HOLD

// 1000 HZ polling rate
#define USB_POLLING_INTERVAL_MS 1

// Allows sending more than one key per scan. By default, only one key event
// getssent via process_record() per scan.  This has little impact on most
// typing, butif you're doing a lot of chords, or your scan rate is slow to
// begin with, you canhave some delay in processing key events. Each press and
// release is a separateevent. For a keyboard with 1ms or so scan times, even a
// very fast typist isn'tgoing to produce the 500 keystrokes a second needed to
// actually get more than afew ms of delay from this. But if you're doing
// chording on something with 3-4msscan times? You probably want this.
#define QMK_KEYS_PER_SCAN 4

#define FORCE_NKRO

// #define COMBO_COUNT 3
