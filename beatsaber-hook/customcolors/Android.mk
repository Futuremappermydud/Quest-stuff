# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
#
#
LOCAL_PATH := $(call my-dir)

TARGET_ARCH_ABI := $(APP_ABI)


include $(CLEAR_VARS)
LOCAL_MODULE := hook
#LOCAL_SRC_FILES := $(LOCAL_PATH)/../obj/local/armeabi-v7a/libhook.a
#LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../include

include $(CLEAR_VARS)
LOCAL_LDLIBS := -llog
LOCAL_CFLAGS    := -DMOD_ID='"CustomColors"' -DVERSION='"1.0.0"' -I'C:\Program Files\Unity\Editor\Data\il2cpp\libil2cpp'
LOCAL_MODULE    := customcolors
LOCAL_SRC_FILES := ../shared/utils/utils.cpp ../shared/utils/il2cpp-functions.cpp ../shared/utils/il2cpp-utils.cpp ../shared/utils/config-utils.cpp main.cpp ../shared/inline-hook/inlineHook.c ../shared/inline-hook/relocate.c ../shared/inline-hook/And64InlineHook.cpp
#LOCAL_STATIC_LIBRARIES := libhook
include $(BUILD_SHARED_LIBRARY)
