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

The following sections list and describe the changes to Wwise between version 2021.1.3 and version 2021.1.4.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_4.html#generic_feature_changes_2021_1_4)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_4.html#generic_behavior_changes_2021_1_4)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_4.html#generic_perf_changes_2021_1_4)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_4.html#generic_bugs_2021_1_4)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_4.html#generic_community_bugs_2021_1_4)

## New Features

-   **WG-29814** Added support for offline rendering.
-   **WG-55607** Added a custom section in the AkGeometry Details Panel to control the surface property overrides.
-   **WG-55780** FilePackager: Added a -verbosity option to the command-line tool. It is now possible to reduce the verbosity to speed up packaging on larger projects.
-   **WG-56582** The Wwise Audio Lab now allows you to experiment with 3D audio using Audio Objects, multipositioned Radial Emitters, Room Tones, automatic Auxiliary Bus assignment, dynamic RTPC properties, and System Audio Device settings.

## Behavior Changes

-   **WG-55266** `[AK::SoundEngine::SetOutputDeviceEffect](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ad455f291883c352a87b5b03da64549aa.html#ad455f291883c352a87b5b03da64549aa)` now fails to initialize Audio Device Effects that are already instantiated on the Effect chain. This new limitation is necessary to prevent artifacts caused by multiple instances of the Mastering Suite from being active at the same time.

## Performance Changes

-   **WG-50250** Improved slow performance of RTPC-driven Switch Containers.
-   **WG-55745** Spatial Audio: Paths are still computed to sounds that have stopped playing so that their reverb tails may play out. Now, paths will stop being computed after enough time has elapsed.

## Bug Fixes

# New Features

-   **WG-51294** Fixed: Audio Object metadata collected during pipeline processing is not available to 3D audio-enabled Audio Device plug-ins.
-   **WG-51714** Fixed: Multi Editor display of the color chip shows gray color instead of an indeterminate value when multiple objects with different colors are selected
-   **WG-54043** Fixed: Music event cues that set States/Switches used by Interactive Music may lead to a crash.
-   **WG-54291** Fixed: Crash in `AkPipelineBufferBase::GetCachedBuffer` when using multi-core rendering.
-   **WG-54416** Fixed: Unnatural ambience zone behavior in the Wwise Audio Lab.
-   **WG-54448** Fixed: Multi-channel Audio Objects positioned at the default listener get mixed down to a monaural sound.
-   **WG-55425** Fixed: Files moved across drives in File Manager can leave a leftover file.
-   **WG-55536** Fixed: Hang when the main Audio Device resets while the main output is replaced using `[AK::SoundEngine::ReplaceOutput](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a81521a4611d3891c499ec9c5eb421ac2.html#a81521a4611d3891c499ec9c5eb421ac2)`, after adding secondary outputs with `[AK::SoundEngine::AddOutput](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a15ab79f954a307902f529d8ccde8ad48.html#a15ab79f954a307902f529d8ccde8ad48)`.
-   **WG-55606** Fixed: Acoustic textures are assigned to incorrect faces in Spatial Audio Volumes after editing the brush geometry.
-   **WG-55667** Fixed: File analysis is re-run unnecessarily when checking or unchecking impact and body components for input files that exceed 48 kHz.
-   **WG-55721** Fixed: Possible assert in Wwise debug when live editing.
-   **WG-55740** Fixed: (Mac Authoring) Nuendo Game Audio Connect import fails with file not found.
-   **WG-55744** Fixed: Nuendo Game Audio Connect does not detect corresponding files in subdirectories.
-   **WG-55794** Fixed: SoundBank generation does not delete a pre-existing .bnk file when in a different folder.
-   **WG-55798** Fixed: (Spatial Audio) An uninitialized variable causes paths from portals to be inconsistent.
-   **WG-55880** Fixed: Small memory leak in Wwise Authoring when converting Convolution media.
-   **WG-55901** Fixed: Synchronization of State values when connected to game.
-   **WG-55915** Fixed: The Factory Reflect effect is different from a default Reflect effect.
-   **WG-55981** Fixed: Crash in AddOutput when CAkWinDeviceCache is not available.
-   **WG-56048** Fixed: Wwise may hang when renaming an Original wav file and attempting to play it right away.
-   **WG-56074** Fixed: Command Queue Size in Profiler reports 100% when the command queue is actually empty.
-   **WG-56096** Fixed: Possible crash when reloading Work Units.
-   **WG-56110** Fixed: The default selected version of Wwise Motion does not always match Wwise's.
-   **WG-56201** Fixed: `AkGlobalCallbackLocation_WakeupFromSuspend` callback is not fired after calling `[AK::SoundEngine::WakeupFromSuspend](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a9244da1d4d0deedcabdaaae863fcff47.html#a9244da1d4d0deedcabdaaae863fcff47)` if all active outputs are "secondary".
-   **WG-56454** Fixed: (wp.py) Package command truncates long file paths during package creation.

-   **WG-54475** Fixed: (WAAPI) It's possible to delete the Master Audio Bus.
-   **WG-55009** Fixed: Crash in `CAkRTPCMgr::AkRTPCSubscription::PushUpdate` when using Blend Containers.
-   **WG-55024** Fixed: Playing streamed media with headers larger than the stream I/O granularity, such as some long WEM Opus files, would result in an error of "File header too large".
-   **WG-55265** Fixed: Multiple Mastering Suite instances are allowed to run simultaneously.
-   **WG-55353** Fixed: Sound Engine hangs when replacing the main output after adding a Secondary Output.
-   **WG-55451** Fixed: Compilation error when building the Sound Engine sources using Windows locales without UTF-8 code page support.
-   **WG-55528** Fixed: Column widths in the Event Editor and Contents Editor change after the user adjusted them.
-   **WG-55531** Fixed: MIDI file source references are sometimes removed from Work Unit files.
-   **WG-55616** Fixed: Short but audible pop when looping or seeking certain source files encoded in WEM Opus.
-   **WG-55631** Fixed: (Mac Authoring) Crash when adding an Audio Input source when Wwise was launched from the Project tab of the Launcher.
-   **WG-55678** Fixed: An invalid regular expression passed to "where" : "name:matches" in ak.wwise.core.object.get WAAPI query leads to a Wwise crash.
-   **WG-55691** Fixed: (Spatial Audio) The room game object rotates with the listener instead of remaining fixed to the room's orientation.
-   **WG-55710** Fixed: Crash with File Packager when loading a SoundbanksInfo.xml file larger than 1GB.
-   **WG-55723** Fixed: Wwise can crash on a division by zero with .wav files containing invalid or unsupported data in the 'fmt' chunk.
-   **WG-55795** Fixed: (Spatial Audio) Diffraction paths between a stationary emitter and a portal are not computed if the listener goes out of range and then comes back into range.
-   **WG-55875** Fixed: `[AK::SoundEngine::ExecuteActionOnPlayingID()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_aafa66841a791ef5e024fe4e99caf3e91.html#aafa66841a791ef5e024fe4e99caf3e91)` pauses and resumes global State transitions.
-   **WG-55929** Fixed: In the General Properties page, Master Bus config shows "Unknown" when outputting to an audio device other than System.
-   **WG-56180** Fixed: Wwise allows to connect to incompatible versions despite the WG-54349 behavior change.
-   **WG-56209** Fixed: (Spatial Audio) Transmission loss value of an internal room is not applied to ambience and reverb of an external room with a lower transmission loss when transitioning through a portal.
-   **WG-56290** Fixed: Game crash when connecting Wwise if Blend Containers were updated offline.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_4.html#new_features)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_4.html#behavior_changes)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_4.html#performance_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_4.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_4.html#fixes_for_community-reported_bugs)

_menu_