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

// https://github.com/qmk/qmk_firmware/blob/develop/docs/squeezing_avr.md
// Starting with Lock Key support. If you have an Cherry MX Lock switch (lucky
// you!), you don't want to do this. But chances are, you don't. In that case,
// add this to your config.h:
//
// https://github.com/qmk/qmk_firmware/blob/master/docs/faq_keymap.md
// This feature is for mechanical lock switch like this Alps one. You can enable
// it by adding this to your config.h:
//
// #define LOCKING_SUPPORT_ENABLE
// #define LOCKING_RESYNC_ENABLE
//
// After enabling this feature use keycodes KC_LCAP, KC_LNUM and KC_LSCR in your
// keymap instead.
//
// Old vintage mechanical keyboards occasionally have lock switches but modern
// ones don't have. You don't need this feature in most case and just use
// keycodes KC_CAPS, KC_NLCK and KC_SLCK.
//
// Disable this feature to reduce firmware size since we do not use KC_LCAP,
// KC_LNUM, and KC_LSCR
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

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

// This is required to enable NKRO despite having NKRO_ENABLE = yes in rules.mk
#define FORCE_NKRO

// https://beta.docs.qmk.fm/developing-qmk/qmk-reference/config_options
// disable one-shot modifiers
//
// Disable this feature because we are using a custom verison of oneshot that is
// not based on timers
#define NO_ACTION_ONESHOT

// https://github.com/qmk/qmk_firmware/blob/develop/docs/squeezing_avr.md
// There are also some options for layers, that can reduce the firmware size.
// All of these settngs are for your config.h.
// You can limit the number of layers that the firmware uses -- if you're using
// less than 8 layers in total:
#define LAYER_STATE_8BIT
