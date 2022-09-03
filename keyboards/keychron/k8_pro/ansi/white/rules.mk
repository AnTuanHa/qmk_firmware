LED_MATRIX_ENABLE = yes
LED_MATRIX_DRIVER = CKLED2001

# https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_space_cadet
# Steve Losh described the Space Cadet Shift quite well. Essentially, when you
# tap Left Shift on its own, you get an opening parenthesis; tap Right Shift on
# its own and you get the closing one. When held, the Shift keys function as
# normal. Yes, it's as cool as it sounds, and now even cooler supporting Control
# and Alt as well!
#
# Disable this to reduce firmware size since it is not being used
SPACE_CADET_ENABLE = no

# https://beta.docs.qmk.fm/using-qmk/advanced-keycodes/feature_grave_esc
# Replace the KC_GRAVE key in your keymap (usually to the left of the 1 key)
# with KC_GESC. Most of the time this key will output KC_ESC when pressed.
# However, when Shift or GUI are held down it will output KC_GRV instead.
#
# Disable this to reduce firmware size since KC_GESC is not being used
GRAVE_ESC_ENABLE = no

# https://github.com/qmk/qmk_firmware/blob/develop/docs/squeezing_avr.md
# Largest in size is "magic" -- the QMK magic keycodes -- which control things
# like NKRO toggling, GUI and ALT/CTRL swapping, etc. Disabling it will disable
# those functions.
#
# Disable since NKRO toggling, GUI and ALT/CTRL swapping is not being used
MAGIC_ENABLE = no

DEBOUNCE_TYPE = asym_eager_defer_pk
