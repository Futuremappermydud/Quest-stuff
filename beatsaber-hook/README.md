# Beatsaber quest (il2cpp) modloader/function hooking poc

This is Sc2ad's fork of jakibaki's modloader, which contains many new functions that the original library does not yet have. However, the code style/true validity (as in, "can it run?") of this repo are significantly more in question than the main library.

## Acknowledgements

This wouldn't have been possible without a few people who have helped immensely.

- [emulamer](https://github.com/emulamer/): Created [BeatOn](https://github.com/emulamer/BeatOn), provided support, tested, and in general just a great person to talk to. This wouldn't exist at all if not for him motivating me to keep working.
- [jakibaki](https://github.com/jakibaki/): Created the library that actually supports all of the mod loading, as well as a lot of support when developing (and bearing with my annoying questions).
- [leo60228](https://github.com/leo60228): Created the custom colors mod using jakibaki's mod loader. The first mod that used his library.
- Trueavid#8335 (Discord): Helped test various things.

Right now this loads mods (`.so` files) from `/sdcard/Android/data/com.beatgames.beatsaber/files/mods/` and patches out the song-signature-check.

Uses https://github.com/ele7enxxh/Android-Inline-Hook + some macros for magic

Follow https://koz.io/using-frida-on-android-without-root/ to learn how to inject the modloader-library into the beatsaber apk (with the so built from this instead of frida)

The function offsets (as well as infos about the structs) can be obtained with il2cppdumper

```
ndk-build NDK_PROJECT_PATH=. APP_BUILD_SCRIPT=./Android.mk NDK_APPLICATION_MK=./Application.mk
```