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
LOCAL_LDLIBS := -llog
LOCAL_CFLAGS    := -DMOD_ID='"StickyScore"' -DVERSION='"0.0.1"' -I'C:\Program Files\Unity\Editor\Data\il2cpp\libil2cpp'
LOCAL_MODULE    := xscore
LOCAL_SRC_FILES := ../beatsaber-hook/shared/utils/il2cpp-utils.cpp ../beatsaber-hook/shared/utils/utils.cpp ../beatsaber-hook/shared/utils/config-utils.cpp main.cpp ../beatsaber-hook/shared/inline-hook/inlineHook.c ../beatsaber-hook/shared/inline-hook/relocate.c ../beatsaber-hook/shared/inline-hook/And64InlineHook.cpp 
include $(BUILD_SHARED_LIBRARY)