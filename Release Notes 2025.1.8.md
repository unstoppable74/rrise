_menu_

-   __ Wwise
    
-   __ Certified Partner Plug-ins
    
-   __ Wwise Samples
    

Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

The following sections list and describe the changes to Wwise between version 2025.1.7 and version 2025.1.8.  
Platform-specific information can be found here:

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#generic_feature_changes_2025_1_8)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#generic_behavior_changes_2025_1_8)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#generic_misc_2025_1_8)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#generic_bugs_2025_1_8)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#generic_community_bugs_2025_1_8)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#generic_documentation_improvements_2025_1_8)

## New Features

-   **WG-49756** Added a user setting to limit the number of logical cores available to Wwise Authoring for multi-threaded operations, such as conversion, background analysis, and media indexing.

## Behavior Changes

-   **WG-83821** To support future Wwise development, the Init SoundBank now automatically includes plug-in media that's referenced by any Effect plug-in on the Main Audio Bus, or any other top-level Audio Bus in the Busses hierarchy. For example, if you have an AK Convolution Reverb Effect on the Main Audio Bus, the Init SoundBank will now include the converted impulse response for that Effect. To minimize duplication of media across SoundBanks that include Audio Busses, SoundBanks will now exclude Main Audio Busses from their content.

## Miscellaneous Changes

-   **WG-83233** Removed codecvt-based string conversion from Wwise Authoring.
-   **WG-83520** In the Parametric EQ plug-in, reduced the minimum value permitted for the Band Dynamics Threshold properties from -60db to -96db.

## Bug Fixes

-   **WG-79688** Fixed: When an RTPC prevents an Effect from being rendered, the Effect is not included in the SoundBank.
-   **WG-80302** Fixed: The Marker Transient Detect mode is not accessible anymore with the Soundseed Grain Source plug-in.
-   **WG-82347** Fixed: Inconsistent grouping of Sound nodes in Profiler Voice Graph.
-   **WG-82855** Fixed: Moving begin or end markers in AK Convolution Reverb sometimes leaves the waveform incorrectly selected.
-   **WG-83202** Fixed: (Acoustics) `[AK::SpatialAudio::RemoveImageSource](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_spatial_audio_a1069aeddd9dcb97445ce60fc5338b915.html#a1069aeddd9dcb97445ce60fc5338b915)` ignores image sources with ID 0.
-   **WG-83283** Fixed: (Acoustics) Path sorting sometimes sorts reflection paths incorrectly.
-   **WG-83354** Fixed: The plug-in property attribute "ShowDefaultWhenDefault" only applies to type Real64.
-   **WG-83462** Fixed: Possible crash when renaming Switch Groups.
-   **WG-83491** Fixed: (Mac Authoring) Can't drop WAV file in Audio File Importer.
-   **WG-83539** Fixed: (WAQL) Possible crash in a WAQL query.
-   **WG-83613** Fixed: Haptic Clip Player envelopes don't correctly initialize to their starting values at the beginning of playback.
-   **WG-83640** Fixed: AK Custom Panner Effect plug-in doesn't report an error when two speakers are at the same location.
-   **WG-83659** Fixed: The Haptic Clip Player doesn't support the Loop, Loop Infinite, and No. of Loops properties in the Property Editor.
-   **WG-83862** Fixed: Potential NaN value generated when processing multichannel Audio Objects with large spread values that are positioned directly in front of a listener.

# New Features

-   **WG-58880** Fixed: Possible crash when modifying a Sequence Container.
-   **WG-82536** Fixed: User preferences for the Property Editor can accumulate stale properties over time.
-   **WG-82869** Fixed: Crash in audio thread when another thread is attempting to register or unregister an audio device callback.
-   **WG-83139** Fixed: Audible clicks on some Audio Objects Busses with an active low-pass filter, or when processing some Effects on Audio Objects Busses where the Audio Objects have a non-zero Gain.
-   **WG-83228** Fixed: Blueprint actors with an AkPortal component are destroyed when copy-pasted and moved.
-   **WG-83238** Fixed: Possible crash when using the Voices Graph.
-   **WG-83268** Fixed: Possible crash when using States in the Mixing Desk.
-   **WG-83307** Fixed: Possible crash when loading a corrupted Work Unit.
-   **WG-83347** Fixed: Possible crash in `CAkMusicSwitchCtx::ScheduleSwitchTransition`.
-   **WG-83376** Fixed: (Acoustics) Jumps in room tone volume for nested Rooms connected with multiple Portals.
-   **WG-83514** Fixed: Hang when calling `AkMemoryMgr::DumpToFile` in low-memory situations.
-   **WG-83653** Fixed: Possible crash when playing a Music Playlist Container that only contains empty Segments and has entry and end markers set to 0.
-   **WG-83700** Fixed: Crash in Wwise Authoring when connecting to a game with a Portal or Room name set to nullptr.
-   **WG-83755** Fixed: Events leaking with calls to `[PostMIDIOnEvent()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ab24b5dc8bd4d1adbdc6aa5c98d94d946.html#ab24b5dc8bd4d1adbdc6aa5c98d94d946)` that target containers with Initial Delay.
-   **WG-83794** Fixed: Crash when applying live-edited conversion settings to a sound that was stopped during the conversion process.
-   **WG-83853** Fixed: Dynamic Sequence can enter an infinite loop if started with one or more audio nodes that are not in any loaded SoundBanks.
-   **WG-83909** Fixed: Possible crash in CAkPlayingMgr during a Stop All Action.

## Documentation Improvements

-   **WG-70265** Updated code samples in [Integrating Secondary Outputs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=integrating_secondary_outputs.html) to reflect latest API changes.
-   **WG-77162** Updated [Using Effects with Audio Objects](https://www.audiokinetic.com/library/edge/?source=Help&id=using_effects_with_audio_objects) to properly reflect the current set of Object Processors available in Wwise.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#new_features)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#behavior_changes)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#miscellaneous_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#fixes_for_community-reported_bugs)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_8.html#documentation_improvements)

_menu_