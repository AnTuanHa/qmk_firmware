# One-shot modifier and layer key source code
* One-shot modifier layer key code from
  [daliusd](https://github.com/daliusd/qmk_firmware/tree/daliusd-redox/keyboards/ferris/keymaps/daliusd)
* Inspired from [callum's one-shot
  modifiers](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum)

# Reasons
[callum's README](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum) explains
pretty well why mod-tap doesn't work, ie, [home row
mods](https://precondition.github.io/home-row-mods). In addition, [dalius's blog
post](https://blog.ffff.lt/posts/callum-layers/) expands further on why one-shot layer key is
needed, and also has the fix for callum's one-shot modifiers where he notes, "if you use one shot
mod and press down two or more keys without releasing them then modifier is applied to all of them.
E.g. press shift, release shift (triggers one shot shift), press s, press a, release s, release a,
will result in “SA” while expectation is “Sa”. That’s especially noticeable when you are typing
fast."

## TLDR
* mod-tap adds additional "input lag" because it has to figure out what is a tap or hold on _key
  up_, and not key down, when using home row modifiers.
* [QMK One Shot Keys](https://beta.docs.qmk.fm/using-qmk/software-features/one_shot_keys) are based
  on timers. Callum's and dalius' versions of the one-shot key is non-timer based.
* [QMK One Shot Layer (OSL)
  Keys](https://beta.docs.qmk.fm/using-qmk/software-features/feature_layers) are also based on
  timers. Dalius' one-shot layer keys are not based on timers.
* Dalius' version of the one-shot key is used over callum's since it includes one-shot layers, but
  also fixes callum's one-shot modifier key bug where "if you use one shot mod and press down two or
  more keys without releasing them then modifier is applied to all of them. E.g. press shift,
  release shift (triggers one shot shift), press s, press a, release s, release a, will result in
  “SA” while expectation is “Sa”. That’s especially noticeable when you are typing fast."
* Also, using home-row mods doesn't allow me to press `CTRL+C` or `CTRL+V` with one hand, and do
  other commonly used keyboard shortcuts with one hand.
