#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <linux/limits.h>
#include <sys/sendfile.h>
#include <sys/stat.h>

#include "../beatsaber-hook/shared/inline-hook/inlineHook.h"
#include "../beatsaber-hook/shared/utils/utils.h"
#ifndef JSMN_INCLUDED
#include "../beatsaber-hook/jsmn/jsmn.h"
#endif

#undef log
#define log(...) __android_log_print(ANDROID_LOG_INFO, "QuestHook", "[TemplateMod v0.0.0.1] " __VA_ARGS__)

// Constants
#define WallLayer 25
#define MoveBackLayer 27

///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// DEFINE OFFSETS THAT ARE USEFUL HERE ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

// ScoreController.RawScoreWithoutMultiplier: 0x48C248
#define RawScoreWithoutMulitplier_offset 0x48C248
// HandleSaberAfterCutSwingRatingCounterDidChangeEvent: 0x13233DC
#define HandleSaberAfterCutSwingRatingCounterDidChangeEvent_offset 0x13233DC
// LIV.ctor: 0x136E7BC
#define LIV_ctor_offset 0x136E7BC
// LayerMask field offset from Camera: 0x18
#define layermask_field_offset 0x18
// LayerMask.get_value: 0x298B60
#define LayerMask_get_value_offset 0x298B60
// LayerMask.set_value: 0x298B68
#define LayerMask_set_value_offset 0x298B68

///////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////// DEFINE HOOKS HERE ////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

MAKE_HOOK(LIV_ctor, LIV_ctor_offset, void, void* self) {
    log("Entering LIV.ctor hook...");
    log("Calling orig...");
    LIV_ctor(self);
    log("Attempting to get old layer mask...");
    // Get a pointer from a field offset of 0x18
    void** layerFieldOffset = (void**)(self) + layermask_field_offset;
    log("Original LIV LayerMask Pointer: %i", (int)layerFieldOffset);
    log("Attempting to get value of LIV LayerMask...");
    // Create a function for getting the layermask
    int (*get_value_layermask)(void*) = (void*)getRealOffset(LayerMask_get_value_offset);
    int originalValue = get_value_layermask(*layerFieldOffset);
    log("Attempting to set new layer to be the OR between current and %i...", WallLayer);
    // TODO CHANGED TO AND NOT FROM OR
    originalValue &= ~(1 << WallLayer);
    log("Attempting to set new layer to be the OR between current and %i...", MoveBackLayer);
    originalValue &= ~(1 << MoveBackLayer);
    // Create a function for setting the layermask
    void (*set_value_layermask)(void*, int) = (void*)getRealOffset(LayerMask_set_value_offset);
    set_value_layermask(*layerFieldOffset, originalValue);
    log("Completed LIV.ctor!");
}

MAKE_HOOK(raw_score_without_multiplier, RawScoreWithoutMulitplier_offset, void, void* noteCutInfo, void* saberAfterCutSwingRatingCounter, int* beforeCutRawScore, int* afterCutRawScore, int* cutDistanceRawScore) {
    log("Called RawScoreWithoutMultiplier Hook!");
    raw_score_without_multiplier(noteCutInfo, saberAfterCutSwingRatingCounter, beforeCutRawScore, afterCutRawScore, cutDistanceRawScore);
}

MAKE_HOOK(HandleSaberAfterCutSwingRatingCounterDidChangeEvent, HandleSaberAfterCutSwingRatingCounterDidChangeEvent_offset, void, FlyingScoreEffect* self, void* saberAfterCutSwingRatingCounter, float rating) {
    log("Called HandleSaberAfterCutSwingRatingCounterDidChangeEvent Hook!");
    log("Attempting to call standard HandleSaberAfterCutSwingRatingCounterDidChangeEvent...");
    HandleSaberAfterCutSwingRatingCounterDidChangeEvent(self, saberAfterCutSwingRatingCounter, rating);
    int beforeCut = 0;
    int afterCut = 0;
    int cutDistance = 0;
    raw_score_without_multiplier(self->noteCutInfo, self->saberAfterCutSwingRatingCounter, &beforeCut, &afterCut, &cutDistance);
    int score = beforeCut + afterCut;
    log("RawScore: %i", score);
    log("Completed HandleSaberAfterCutSwingRatingCounterDidChangeEvent!");
}

// INSTALL HOOKS

__attribute__((constructor)) void lib_main()
{
    log("Installing TemplateMod...");
    INSTALL_HOOK(raw_score_without_multiplier);
    log("Installed RawScoreWithoutMultiplier Hook!");
    INSTALL_HOOK(HandleSaberAfterCutSwingRatingCounterDidChangeEvent);
    log("Installed HandleSaberAfterCutSwingRatingCounterDidChangeEvent Hook!");
    INSTALL_HOOK(LIV_ctor);
    log("Installed LIV.ctor Hook!");
    log("Completed installing hooks!");
}