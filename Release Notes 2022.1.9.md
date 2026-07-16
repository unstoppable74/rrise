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

The following sections list and describe the changes to Wwise between version 2022.1.8 and version 2022.1.9.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_9.html#generic_feature_changes_2022_1_9)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_9.html#generic_misc_2022_1_9)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_9.html#generic_bugs_2022_1_9)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_9.html#generic_community_bugs_2022_1_9)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_9.html#generic_documentation_improvements_2022_1_9)

## New Features

-   **WG-60616** (WAAPI/WAQL) Added new accessors: mediaId, conversionHash, and contentHash.
-   **WG-66725** In Wwise Project Settings, you can now specify the line ending (LF vs. CRLF) applied when saving project and SoundBank files.
-   **WG-67361** You can now enable console output with the AK\_OUTPUT\_REDIRECT environment variable.
-   **WG-67403** You can now open the Attenuation Editor from the Positioning tab of the Property Editor even when **Override parent** is not selected.

## Miscellaneous Changes

-   **WG-68127** Changed SoundBank generation log message from "Header output path" to "Root output path".

## Bug Fixes

-   **WG-63299** Fixed: (Spatial Audio) An assert is triggered in `NudgeToShadowZone()` when calculating diffraction on certain geometries.
-   **WG-63963** Fixed: Timing values reported in the CPU tab of the Advanced Profiler are incorrect by a large factor in some scenarios.
-   **WG-67441** Fixed: Miscalculation in edge case of onset detection.
-   **WG-67502** Fixed: Event Editor is empty when creating an Event through the object shortcut menu.
-   **WG-67683** Fixed: Possible infinite hang in `AK::JobMgr::WorkUntilDone` when running the sound engine in multi-core execution.
-   **WG-67849** Fixed: In the Conversion Settings Editor, buttons aren't always properly enabled or disabled.
-   **WG-67941** Fixed: Some lines appear transparent when the Voice Monitor view is undocked.
-   **WG-68021** Fixed: Active Plug-in property set to incorrect value when connecting Wwise to a remote instance if the property has an RTPC and/or State applied.
-   **WG-68218** Fixed: Attempting to stop a Switch Container in Continuous Play Mode on a specific Playing ID can stop other instances of this sound playing simultaneously on the same game object.
-   **WG-68223** Fixed: Compressor and Expander Effects sometimes cause audio glitches when processing more than one Audio Object at one time.
-   **WG-68299** Fixed: Saving a project after removing a platform can corrupt unlinked Object Lists (for example, Effects list).
-   **WG-68387** Fixed: Stream Name is restricted to 16 char in the Streams tab of the Advanced Profiler.
-   **WG-68515** Fixed: Crash when using very short IR (<10ms) in AK Convolution Reverb.
-   **WG-68741** Fixed: Slightly negative values can be shown in CPU tab of the Advanced Profiler.
-   **WG-68775** Fixed: Window meter doesn't update in the HDR tab of the Property Editor for audio busses.
-   **WG-68794** Fixed: Loudness normalization wrongly attributed to Voice Volume in Voice Inspector.

# New Features

-   **WG-52007** Fixed: In the Music Segment Editor, it's not possible to snap to Beats/Bars or Cues when all tracks are excluded or when there are no tracks.
-   **WG-63450** Fixed: Possible crash when saving a project with files to check out.
-   **WG-65136** Fixed: (Spatial Audio) Transmission Loss is incorrectly reported in the Voice Inspector.
-   **WG-65184** Fixed: Possible crash when removing an Effect.
-   **WG-66303** Fixed: Possible crash after doing source operations in the File Manager.
-   **WG-66902** Fixed: Crash in `CAkParameterNode::IsOrIsChildOf()` when descendant nodes of a container have been unloaded.
-   **WG-67027** Fixed: Possible assert in debug when multiple music transitions occur at the same time.
-   **WG-67128** Fixed: Crash when editing some properties while lists are being reloaded.
-   **WG-67241** Fixed: `Wwise_IDs.h` is not managed by source control even if the **Use Source Control for Generated Files** option is enabled in the SoundBanks settings.
-   **WG-67349** Fixed: Some characters, such as dash, are not accepted in language names used in WAAPI SoundBank generation.
-   **WG-67373** Fixed: Source Editor shows duplicate of Channel Configuration 7.1.4 in the Channel Config Override list.
-   **WG-67469** Fixed: The MaxAttenuation attribute in a SoundBank XML file can trigger an invalid format error.
-   **WG-67691** Fixed: Using the `–soundbank-path` option of `WwiseConsole generate-soundbank` fails to generate the SoundBanks if they already existed elsewhere .
-   **WG-68026** Fixed: `[AK::SoundEngine::TryUnsetMedia](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a77698f766d8d18675e38d91a69987c7a.html#a77698f766d8d18675e38d91a69987c7a)` doesn't succeed for active MIDI files.
-   **WG-68060** Fixed: Possible crash when typing Perforce password.
-   **WG-68130** Fixed: Crash on Stop All action with multiple bus exceptions.
-   **WG-68291** Fixed: Function `StartProfilerCapture` can lead to a crash if the Wwise Profiler is also connected.
-   **WG-68342** Fixed: There is no `isIncluded` WAAPI/WAQL accessor that considers the Inclusion property of an object's ancestors.
-   **WG-68391** Fixed: Wrong volumes are applied to non-mixing busses when the hierarchy contains either a Blend Container or a Switch Container and two nodes are writing the bus output to the same output.
-   **WG-68719** Fixed: RTPC changes to the Playback Speed property are not applied correctly on MIDI clips.
-   **WG-68803** Fixed: Distorted output when building Vorbis decoder library with VS 2022 17.7 or later.
-   **WG-68832** Fixed: Crash when swapping zero-latency streamed PCM media.

## Documentation Improvements

-   **WG-65265** Elaborated on the relationship between obstruction, occlusion, diffraction, and transmission in [Obstruction and Occlusion with Game-defined Auxiliary Sends](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=soundengine_obsocc.html), [Acoustics](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=spatial_audio.html), and [Wwise Acoustics Concepts](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=spatial_audio_concepts.html).
-   **WG-66865** Added note about `[AK::SoundEngine::SetMultipleObstructionAndOcclusion](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ab0216f0dc33bef431d5d92f519e5be58.html#ab0216f0dc33bef431d5d92f519e5be58)` to [Integration Details - 3D Positions](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=soundengine_3dpositions.html).
-   **WG-68290** Added a new page on [Radial Emitters](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=spatial_audio_radial_emitters.html).
-   **WG-68517** Corrected Sequence Container icon in [Types of Containers](https://www.audiokinetic.com/library/edge/?source=Help&id=grouping_sound_and_motion_objects_to_create_actor_mixer_hierarchy_types_of_containers) table.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_9.html#new_features)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_9.html#miscellaneous_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_9.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_9.html#fixes_for_community-reported_bugs)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_9.html#documentation_improvements)

_menu_