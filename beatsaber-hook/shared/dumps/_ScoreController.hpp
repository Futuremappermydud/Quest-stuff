#ifndef _ScoreController_DEFINED
#define _ScoreController_DEFINED
// This .hpp file was compiled via beatsaber-hook/shared/helper.py's Parse Mode.
// Created by Sc2ad.
// Methods may not be valid!
#include <dlfcn.h>
#include <string_view>
#include "../utils/typedefs.h"
#include "../utils/il2cpp-functions.hpp"
#include "../utils/il2cpp-utils.hpp"
// Contains MethodInfo/Il2CppClass data for: .ScoreController
namespace _ScoreController {
    // .ScoreController
    typedef struct Class : Il2CppObject {
        int _feverModeRequiredCombo; // 0x18
        float _feverModeDuration; // 0x1C
        void* _gameplayModifiersModel; // 0x20
        void* _beatmapObjectSpawnController; // 0x28
        void* _playerHeadAndObstacleInteraction; // 0x30
        void* _audioTimeSyncController; // 0x38
        void* noteWasCutEvent; // 0x40
        void* noteWasMissedEvent; // 0x48
        void* scoreDidChangeEvent; // 0x50
        void* immediateMaxPossibleScoreDidChangeEvent; // 0x58
        void* multiplierDidChangeEvent; // 0x60
        void* comboDidChangeEvent; // 0x68
        void* feverModeChargeProgressDidChangeEvent; // 0x70
        void* feverDidStartEvent; // 0x78
        void* feverDidFinishEvent; // 0x80
        void* comboBreakingEventHappenedEvent; // 0x88
        int _baseRawScore; // 0x90
        int _prevFrameRawScore; // 0x94
        int _multiplier; // 0x98
        int _multiplierIncreaseProgress; // 0x9C
        int _multiplierIncreaseMaxProgress; // 0xA0
        int _combo; // 0xA4
        int _maxCombo; // 0xA8
        uint8_t _feverIsActive; // 0xAC
        float _feverStartTime; // 0xB0
        int _feverCombo; // 0xB4
        uint8_t _playerHeadWasInObstacle; // 0xB8
        int _immediateMaxPossibleRawScore; // 0xBC
        int _cutOrMissedNotes; // 0xC0
        void* _cutScoreBuffers; // 0xC8
        float _gameplayModifiersScoreMultiplier; // 0xD0
    } Class;
    static bool __cached = false;
    static Il2CppClass* klass;
    static const MethodInfo* add_noteWasCutEvent_Action3;
    static const MethodInfo* remove_noteWasCutEvent_Action3;
    static const MethodInfo* add_noteWasMissedEvent_Action2;
    static const MethodInfo* remove_noteWasMissedEvent_Action2;
    static const MethodInfo* add_scoreDidChangeEvent_Action2;
    static const MethodInfo* remove_scoreDidChangeEvent_Action2;
    static const MethodInfo* add_immediateMaxPossibleScoreDidChangeEvent_Action2;
    static const MethodInfo* remove_immediateMaxPossibleScoreDidChangeEvent_Action2;
    static const MethodInfo* add_multiplierDidChangeEvent_Action2;
    static const MethodInfo* remove_multiplierDidChangeEvent_Action2;
    static const MethodInfo* add_comboDidChangeEvent_Action1;
    static const MethodInfo* remove_comboDidChangeEvent_Action1;
    static const MethodInfo* add_feverModeChargeProgressDidChangeEvent_Action1;
    static const MethodInfo* remove_feverModeChargeProgressDidChangeEvent_Action1;
    static const MethodInfo* add_feverDidStartEvent_Action;
    static const MethodInfo* remove_feverDidStartEvent_Action;
    static const MethodInfo* add_feverDidFinishEvent_Action;
    static const MethodInfo* remove_feverDidFinishEvent_Action;
    static const MethodInfo* add_comboBreakingEventHappenedEvent_Action;
    static const MethodInfo* remove_comboBreakingEventHappenedEvent_Action;
    static const MethodInfo* MaxRawScoreForNumberOfNotes_int;
    static const MethodInfo* MaxModifiedScoreForMaxRawScore_int_GameplayModifiers_GameplayModifiersModelSO;
    static const MethodInfo* GetModifiedScoreForGameplayModifiersScoreMultiplier_int_float;
    static const MethodInfo* GetModifiedScoreForGameplayModifiers_int_GameplayModifiers_GameplayModifiersModelSO;
    static const MethodInfo* RawScoreWithoutMultiplier_NoteCutInfo_out_int_out_int_out_int;
    static const MethodInfo* get_prevFrameRawScore;
    static const MethodInfo* get_prevFrameModifiedScore;
    static const MethodInfo* get_maxCombo;
    static const MethodInfo* get_multiplierWithFever;
    static const MethodInfo* get_feverModeActive;
    static const MethodInfo* get_feverModeDrainProgress;
    static const MethodInfo* get_feverModeChargeProgress;
    static const MethodInfo* get_immediateMaxPossibleRawScore;
    static const MethodInfo* get_gameplayModifiersScoreMultiplier;
    static const MethodInfo* Init_GameplayModifiers;
    static const MethodInfo* Start;
    static const MethodInfo* OnDestroy;
    static const MethodInfo* Update;
    static const MethodInfo* LateUpdate;
    static const MethodInfo* LoseMultiplier_out_bool_out_bool;
    static const MethodInfo* NotifyForChange_bool_bool;
    static const MethodInfo* HandleNoteWasCutEvent_BeatmapObjectSpawnController_NoteController_NoteCutInfo;
    static const MethodInfo* HandleNoteWasMissedEvent_BeatmapObjectSpawnController_NoteController;
    static const MethodInfo* HandleCutScoreBufferDidFinishEvent_CutScoreBuffer;
    // The Initialization function that must be called before using any of these definitions
    static void Init() {
        if (!__cached) {
            klass = il2cpp_utils::GetClassFromName("", "ScoreController");
            add_noteWasCutEvent_Action3 = il2cpp_functions::class_get_method_from_name(klass, "add_noteWasCutEvent", 2);
            remove_noteWasCutEvent_Action3 = il2cpp_functions::class_get_method_from_name(klass, "remove_noteWasCutEvent", 2);
            add_noteWasMissedEvent_Action2 = il2cpp_functions::class_get_method_from_name(klass, "add_noteWasMissedEvent", 2);
            remove_noteWasMissedEvent_Action2 = il2cpp_functions::class_get_method_from_name(klass, "remove_noteWasMissedEvent", 2);
            add_scoreDidChangeEvent_Action2 = il2cpp_functions::class_get_method_from_name(klass, "add_scoreDidChangeEvent", 2);
            remove_scoreDidChangeEvent_Action2 = il2cpp_functions::class_get_method_from_name(klass, "remove_scoreDidChangeEvent", 2);
            add_immediateMaxPossibleScoreDidChangeEvent_Action2 = il2cpp_functions::class_get_method_from_name(klass, "add_immediateMaxPossibleScoreDidChangeEvent", 2);
            remove_immediateMaxPossibleScoreDidChangeEvent_Action2 = il2cpp_functions::class_get_method_from_name(klass, "remove_immediateMaxPossibleScoreDidChangeEvent", 2);
            add_multiplierDidChangeEvent_Action2 = il2cpp_functions::class_get_method_from_name(klass, "add_multiplierDidChangeEvent", 2);
            remove_multiplierDidChangeEvent_Action2 = il2cpp_functions::class_get_method_from_name(klass, "remove_multiplierDidChangeEvent", 2);
            add_comboDidChangeEvent_Action1 = il2cpp_functions::class_get_method_from_name(klass, "add_comboDidChangeEvent", 1);
            remove_comboDidChangeEvent_Action1 = il2cpp_functions::class_get_method_from_name(klass, "remove_comboDidChangeEvent", 1);
            add_feverModeChargeProgressDidChangeEvent_Action1 = il2cpp_functions::class_get_method_from_name(klass, "add_feverModeChargeProgressDidChangeEvent", 1);
            remove_feverModeChargeProgressDidChangeEvent_Action1 = il2cpp_functions::class_get_method_from_name(klass, "remove_feverModeChargeProgressDidChangeEvent", 1);
            add_feverDidStartEvent_Action = il2cpp_functions::class_get_method_from_name(klass, "add_feverDidStartEvent", 1);
            remove_feverDidStartEvent_Action = il2cpp_functions::class_get_method_from_name(klass, "remove_feverDidStartEvent", 1);
            add_feverDidFinishEvent_Action = il2cpp_functions::class_get_method_from_name(klass, "add_feverDidFinishEvent", 1);
            remove_feverDidFinishEvent_Action = il2cpp_functions::class_get_method_from_name(klass, "remove_feverDidFinishEvent", 1);
            add_comboBreakingEventHappenedEvent_Action = il2cpp_functions::class_get_method_from_name(klass, "add_comboBreakingEventHappenedEvent", 1);
            remove_comboBreakingEventHappenedEvent_Action = il2cpp_functions::class_get_method_from_name(klass, "remove_comboBreakingEventHappenedEvent", 1);
            MaxRawScoreForNumberOfNotes_int = il2cpp_functions::class_get_method_from_name(klass, "MaxRawScoreForNumberOfNotes", 1);
            MaxModifiedScoreForMaxRawScore_int_GameplayModifiers_GameplayModifiersModelSO = il2cpp_functions::class_get_method_from_name(klass, "MaxModifiedScoreForMaxRawScore", 3);
            GetModifiedScoreForGameplayModifiersScoreMultiplier_int_float = il2cpp_functions::class_get_method_from_name(klass, "GetModifiedScoreForGameplayModifiersScoreMultiplier", 2);
            GetModifiedScoreForGameplayModifiers_int_GameplayModifiers_GameplayModifiersModelSO = il2cpp_functions::class_get_method_from_name(klass, "GetModifiedScoreForGameplayModifiers", 3);
            RawScoreWithoutMultiplier_NoteCutInfo_out_int_out_int_out_int = il2cpp_functions::class_get_method_from_name(klass, "RawScoreWithoutMultiplier", 4);
            get_prevFrameRawScore = il2cpp_functions::class_get_method_from_name(klass, "get_prevFrameRawScore", 0);
            get_prevFrameModifiedScore = il2cpp_functions::class_get_method_from_name(klass, "get_prevFrameModifiedScore", 0);
            get_maxCombo = il2cpp_functions::class_get_method_from_name(klass, "get_maxCombo", 0);
            get_multiplierWithFever = il2cpp_functions::class_get_method_from_name(klass, "get_multiplierWithFever", 0);
            get_feverModeActive = il2cpp_functions::class_get_method_from_name(klass, "get_feverModeActive", 0);
            get_feverModeDrainProgress = il2cpp_functions::class_get_method_from_name(klass, "get_feverModeDrainProgress", 0);
            get_feverModeChargeProgress = il2cpp_functions::class_get_method_from_name(klass, "get_feverModeChargeProgress", 0);
            get_immediateMaxPossibleRawScore = il2cpp_functions::class_get_method_from_name(klass, "get_immediateMaxPossibleRawScore", 0);
            get_gameplayModifiersScoreMultiplier = il2cpp_functions::class_get_method_from_name(klass, "get_gameplayModifiersScoreMultiplier", 0);
            Init_GameplayModifiers = il2cpp_functions::class_get_method_from_name(klass, "Init", 1);
            Start = il2cpp_functions::class_get_method_from_name(klass, "Start", 0);
            OnDestroy = il2cpp_functions::class_get_method_from_name(klass, "OnDestroy", 0);
            Update = il2cpp_functions::class_get_method_from_name(klass, "Update", 0);
            LateUpdate = il2cpp_functions::class_get_method_from_name(klass, "LateUpdate", 0);
            LoseMultiplier_out_bool_out_bool = il2cpp_functions::class_get_method_from_name(klass, "LoseMultiplier", 2);
            NotifyForChange_bool_bool = il2cpp_functions::class_get_method_from_name(klass, "NotifyForChange", 2);
            HandleNoteWasCutEvent_BeatmapObjectSpawnController_NoteController_NoteCutInfo = il2cpp_functions::class_get_method_from_name(klass, "HandleNoteWasCutEvent", 3);
            HandleNoteWasMissedEvent_BeatmapObjectSpawnController_NoteController = il2cpp_functions::class_get_method_from_name(klass, "HandleNoteWasMissedEvent", 2);
            HandleCutScoreBufferDidFinishEvent_CutScoreBuffer = il2cpp_functions::class_get_method_from_name(klass, "HandleCutScoreBufferDidFinishEvent", 1);
            __cached = true;
        }
    }
}
#endif /* _ScoreController_DEFINED */