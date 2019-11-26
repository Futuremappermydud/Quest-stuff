erase /Q /S .\obj
erase /Q /S .\lib
call c:\Users\VR\AppData\Local\Android\Sdk\ndk-bundle\build\ndk-build.cmd NDK_PROJECT_PATH=. APP_BUILD_SCRIPT=./Android.mk NDK_APPLICATION_MK=./Application.mk
