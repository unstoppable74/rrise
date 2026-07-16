_menu_

___

-   [Strata](https://www.audiokinetic.com/en/public-library/strata/)
-   [ReaWwise](https://www.audiokinetic.com/en/public-library/reawwise/)
-   [Audiokinetic Launcher](https://www.audiokinetic.com/en/public-library/wwise_launcher/)
-   [Wwise Audio Lab](https://www.audiokinetic.com/en/public-library/wal/)
-   [Wwise Adventure Game](https://www.audiokinetic.com/en/public-library/wag/)
-   [Cube](https://www.audiokinetic.com/en/public-library/cube/)
-   [GME In-Game Voice Chat](https://www.audiokinetic.com/en/public-library/gme/)
-   [Meta XR Audio](https://www.audiokinetic.com/en/public-library/metaxraudio/)

Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

The following sections list and describe the changes to Wwise between version 2025.1.6 and version 2025.1.7.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#generic_feature_changes_2025_1_7)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#generic_perf_changes_2025_1_7)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#generic_misc_2025_1_7)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#generic_bugs_2025_1_7)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#generic_community_bugs_2025_1_7)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#generic_documentation_improvements_2025_1_7)

## New Features

-   **WG-22372** Added support for copying and pasting curves and control points across Attenuation, RTPC, and HDR envelope editors.
-   **WG-82787** When the **All** button is selected in the Property Editor, categories are now more distinct visually.

## Performance Changes

-   **WG-82962** (Acoustics) Optimized volumetric samples generation method, reducing CPU spikes when adding Reverb Zones.
-   **WG-83003** Slightly improved performance of FFT operations in some Effects.

## Miscellaneous Changes

-   **WG-80507** Lowered range of Pitch Limit slider in Reflect plug-in to 1200. You can still enter higher values by typing in the text box.
-   **WG-83002** Updated `PremakePlugins.lua` so that 3rd-party plug-in developers can specify custom paths for generated binaries in their project, and also skip generation of projects to compile shared libraries or DLLs.
-   **WG-83071** Changed the default alignment of allocations from Bookmark Allocator and Temp Allocator to 16 to mitigate potential crashes when reading or writing SIMD data.

## Bug Fixes

-   **WG-81513** Fixed: Trimming an ADM audio source doesn't trim the object animations.
-   **WG-81777** Fixed: DSF contribution is missing in `[ak.wwise.core.profiler.getVoiceContributions](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_profiler_getvoicecontributions.html)`.
-   **WG-81840** Fixed: Missing 3D Selection Properties when selecting Game Object Radius' Virtual Position.
-   **WG-81930** Fixed: Project Database fails to initialize with a Root Output Path on a different drive than the project.
-   **WG-82334** Fixed: Parent's Game-Defined Auxiliary Sends DSF values affect child's values despite the parent being overridden.
-   **WG-82595** Fixed: WAAPI doesn't use the property range of custom States, preventing the LPF or HPF from being set below 0.
-   **WG-82627** Fixed: Wrong Fade-in and Fade-out Curve icons in Property Editor Sources category.
-   **WG-82798** Fixed: Dynamics on Parametric EQ Effect stop functioning after the Effect is bypassed and none of the other parameters controlling the Dynamics have been modified.
-   **WG-82809** Fixed: Profiler notifications for State and Switch changes are pushed by Authoring back to the Runtime. This leads to race conditions between the Runtime and Authoring.
-   **WG-82885** Fixed: Adjusting the Trim End position of a music clip doesn't update the duration of the Music Segment.
-   **WG-82911** Fixed: Game Parameter interpolation properties sometimes not synced by Authoring.
-   **WG-82912** Fixed: `Wwise.app` is sometimes installed without **Authoring** selected in the Launcher, resulting in an incomplete app package.
-   **WG-82938** Fixed: `[ak.wwise.core.object.setStateGroups](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_setstategroups.html)` loses custom States when adding a new State Group.
-   **WG-83008** Fixed: Profiling session file numbering starts at 2 instead of 1.
-   **WG-83023** Fixed: Crash when playing music clips that are missing original files.
-   **WG-83073** Fixed: Playback of a continuous, sample-accurate Sequence Container sometimes hangs after reparenting one of its children.
-   **WG-83375** Fixed: Assert under low-memory conditions when a sound starts with a limiter.
-   **WG-83407** Fixed: Possible crash in the spatial audio task system.

# New Features

-   **WG-77412** Fixed: Hang when hardware Opus decoder signals a particular error.
-   **WG-80073** Fixed: (Acoustics) Distance is inconsistent when using a Distance Probe, and Rooms are connected with multiple Portals.
-   **WG-82278** Fixed: Crash when continuous Blend Containers are stopped explicitly after bank unload.
-   **WG-82532** Fixed: Some public SDK headers fail to compile on Visual Studio when warning level `/W4` is used.
-   **WG-82540** Fixed: Possible random binary differences in SoundBanks when pre-rendering McDSP Effect.
-   **WG-82545** Fixed: **Paste** shortcut menu item prepends the content instead of replacing it.
-   **WG-82667** Fixed: Possible crash in the Audio File Importer when importing a TSV file after removing a folder.
-   **WG-82676** Fixed: Virtual label doesn't appear in the Voice Graph when a voice becomes virtual.
-   **WG-82692** Fixed: (Acoustics) Spread calculations become unstable when the listener has a direct line of sight through a Portal to an emitter that has a spread value larger than the Portal's aperture.
-   **WG-82734** Fixed: Custom data pointer provided in `IOHook::BatchOpen` isn't carried to calls to `IOHook::BatchRead`.
-   **WG-82739** Fixed: Incorrect virtual voice behavior can be applied on playback limiting of a looping container with a parent hierarchy.
-   **WG-82802** Fixed: Audio Device Status Callback for the AkAudioDeviceEvent\_SystemRemoval event reports the wrong device ID.
-   **WG-82821** Fixed: (Acoustics) Silent game objects require a lot of processing power in scenarios with many Reverb Zones.
-   **WG-82822** Fixed: Possible crash in `CAkPBI::CleanupFades()`.
-   **WG-82879** Fixed: Crash when deleting a State Group transition.
-   **WG-82887** Fixed: (Acoustics) Crash in `PortalIntersector::BeginPortal()` after a Portal has moved.
-   **WG-82929** Fixed: Random, Sequence, Switch, and Blend Containers don't react correctly to a break action.
-   **WG-82936** Fixed: (Acoustics) Possible crash in `CAkSpatialAudioEmitter::BuildIndirectPaths` when the sound engine stops.
-   **WG-82959** Fixed: `[GetSourcePlayPosition()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ae0b469d9fb8a099b40f52f004882d283.html#ae0b469d9fb8a099b40f52f004882d283)` returns invalid values if called immediately after `[PostEvent()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a41e9ef8d42951871fe4a8ae58a29a68e.html#a41e9ef8d42951871fe4a8ae58a29a68e)`.
-   **WG-82985** Fixed: (Acoustics) Feedback loops between two Room busses.
-   **WG-82997** Fixed: Possible crash when specifying a list with `[ak.wwise.core.object.create](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_create.html)` for a parent object that doesn't support lists.
-   **WG-83028** Fixed: Crash in Blend Container playback when changing crossfade RTPC value after the playback is stopped.
-   **WG-83230** Fixed: `[AK::SoundEngine::PrepareEvent()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a2e6ebb779470b43d78984c27f6a0c238.html#a2e6ebb779470b43d78984c27f6a0c238)` doesn't prepare the media for MIDI Target references.
-   **WG-83356** Fixed: `[AK::SoundEngine::PostMIDIOnEvent](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ab24b5dc8bd4d1adbdc6aa5c98d94d946.html#ab24b5dc8bd4d1adbdc6aa5c98d94d946)` doesn't call the provided callback function.

## Documentation Improvements

-   **WG-82647** Clarified virtual voice behavior **Kill if finite else virtual**.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#new_features)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#performance_changes)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#miscellaneous_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#fixes_for_community-reported_bugs)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_7.html#documentation_improvements)

_menu_