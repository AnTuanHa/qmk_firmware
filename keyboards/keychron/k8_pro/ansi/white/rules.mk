# https://github.com/qmk/qmk_firmware/blob/master/docs/config_options.md
# Enables Link Time Optimization (LTO) when compiling the keyboard. This makes
# the process take longer, but it can significantly reduce the compiled size
# (and since the firmware is small, the added time is not noticeable).
#
# https://github.com/qmk/qmk_firmware/blob/develop/docs/squeezing_avr.md
# This will cause the final step to take longer, but should get you a smaller
# compiled size. This also disables Action Functions, and Action Macros, both of
# which are deprecated. This will get you the most savings, in most situations.
LTO_ENABLE = yes

# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_space_cadet.md
# Steve Losh described the Space Cadet Shift quite well. Essentially, when you
# tap Left Shift on its own, you get an opening parenthesis; tap Right Shift on
# its own and you get the closing one. When held, the Shift keys function as
# normal. Yes, it's as cool as it sounds, and now even cooler supporting Control
# and Alt as well!
#
# Disable this to reduce firmware size since it is not being used
SPACE_CADET_ENABLE = no

# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_grave_esc.md
# Replace the KC_GRAVE key in your keymap (usually to the left of the 1 key)
# with KC_GESC. Most of the time this key will output KC_ESC when pressed.
# However, when Shift or GUI are held down it will output KC_GRV instead.
#
# Disable this to reduce firmware size since KC_GESC is not being used
GRAVE_ESC_ENABLE = no

# https://github.com/qmk/qmk_firmware/blob/develop/docs/squeezing_avr.md
# These features are enabled by default, but they may not be needed. Double
# check to make sure. The Magic Keycodes are the largest and control things like
# NKRO toggling, GUI and ALT/CTRL swapping, etc. Disabling them will disable
# those functions. See Magic Functions for disabling related functions.
#
# Disable since NKRO toggling, GUI and ALT/CTRL swapping is not being used
MAGIC_ENABLE = no

DEBOUNCE_TYPE = asym_eager_defer_pk
