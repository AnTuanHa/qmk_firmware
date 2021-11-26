SRC += oneshot.c

# Enables Link Time Optimization (LTO) when compiling the keyboard.  This makes
# the process take longer, but it can significantly reduce the compiled size
# (and since the firmware is small, the added time is not noticeable).However,
# this will automatically disable the legacy TMK Macros and Functions features,
# as these break when LTO is enabled.  It does this by automatically defining
# NO_ACTION_MACRO and NO_ACTION_FUNCTION.  (Note: This does not affect QMK
# Macros and Layers.)
LTO_ENABLE = yes
