Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

Release Notes 2021.1.13

The following sections list and describe the changes to Wwise between version 2021.1.12 and version 2021.1.13.  
Platform-specific information can be found here:

[Android 2021.1.13](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=android_releasenotes_2021_1_13.html)

[iOS/tvOS 2021.1.13](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ios_releasenotes_2021_1_13.html)

[Linux 2021.1.13](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=linux_releasenotes_2021_1_13.html)

[Mac 2021.1.13](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=mac_releasenotes_2021_1_13.html)

[Windows and Windows UWP 2021.1.13](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=windows_releasenotes_2021_1_13.html)

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_13.html#generic_feature_changes_2021_1_13)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_13.html#generic_behavior_changes_2021_1_13)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_13.html#generic_bugs_2021_1_13)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_13.html#generic_community_bugs_2021_1_13)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_13.html#generic_documentation_improvements_2021_1_13)

## New Features

-   **WG-65199** (wp.py) Added Visual Studio 2022 target support for the Authoring plug-in part.

## Behavior Changes

-   **WG-64106** The [AkGlobalCallbackLocation\_Init](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=_ak_callback_types_8h_ae7a5e30e1402c7cf90d1b47420911676.html#ae7a5e30e1402c7cf90d1b47420911676a97caf890959d744c1c088d19c2d02e11) callback is now issued before the `AK::EventMgr` thread is started, or before any calls to `CAkAudioMgr::RenderAudio`. Most notably, this ensures that [AkGlobalCallbackLocation\_Init](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=_ak_callback_types_8h_ae7a5e30e1402c7cf90d1b47420911676.html#ae7a5e30e1402c7cf90d1b47420911676a97caf890959d744c1c088d19c2d02e11) callbacks are issued before [AkGlobalCallbackLocation\_Begin](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=_ak_callback_types_8h_ae7a5e30e1402c7cf90d1b47420911676.html#ae7a5e30e1402c7cf90d1b47420911676af13fd05bf61f00e37dde9b34e8e14a98) and any other callbacks issued during audio rendering.

## Bug Fixes

-   **WG-61540** Fixed: Crash in `AkDevice::BaseCaptureCallbackStruct::ConvertForCapture` when trying to use ref RegisterCaptureCallback with 5th-order ambisonic output. Note that capturing 4th-order or 5th-order ambisonic output still outputs only 3rd-order FuMa-encoded ambisonics.
-   **WG-61974** Fixed: Voice Inspector sometimes fails to display attenuation contributions when scrubbing the timeline.
-   **WG-63879** Fixed: Inaccurate data in Voice Inspector's Contribution List when dragging the timeline cursor at a resolution smaller than the audio frame.
-   **WG-63880** Fixed: Voice Inspector doesn't snap to proper time when moving time cursor backwards with the timeline zoomed in.
-   **WG-63882** Fixed: Crash in AkPath.cpp when terminating engine in low-memory conditions
-   **WG-63956** Fixed: Possible crash while loading SoundBank Init.bnk under low memory conditions.
-   **WG-64172** Fixed: Crash in `[AK::SoundEngine::Term](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a90f8c91937038615480db2b57ce2279e.html#a90f8c91937038615480db2b57ce2279e)` when streamed sounds with the 3D User positioning option are playing at termination time.
-   **WG-64365** Fixed: Crashes or other errors occur in low-memory situations during playback of Random Containers or Music Playlists set to Random Continuous or Random Step.
-   **WG-64503** Fixed: (Mac Authoring) WwiseConsole incorrectly handles UNIX absolute paths.
-   **WG-64504** Fixed: Music Clip property curves are not deleted when the corresponding Work Unit is unloaded.
-   **WG-64585** Fixed: Inadvertent changes to assigned Media IDs after reloading Work Units.
-   **WG-64781** Fixed: SoundBanks do not contain a music object's MIDI target hierarchy when the MIDI target is specified by the music object's ancestry.
-   **WG-64839** Fixed: Cannot build Authoring plug-ins without MFC.
-   **WG-64957** Fixed: Media ID validation is done slightly too late during project load. This only impacts local playback in Wwise Authoring.
-   **WG-64982** Fixed: Missing tooltips when hovering over list headers.

## Fixes for Community-Reported Bugs

# New Features

-   **WG-61704** Fixed: Meter plug-in doesn't meter properly when on objects in the Actor-Mixer hierarchy.
-   **WG-61946** Fixed: Some memory addresses are not sufficiently aligned.
-   **WG-63559** Fixed: Possible crash when playing back a 3D-positioned LFE-only source while 3D Audio is enabled.
-   **WG-63588** Fixed: Possible crash when opening a project that has a circular reference between a Music Event Cue and an Event.
-   **WG-63817** Fixed: Project file `AutoDetectedSampleRates.cache` grows when no new files are introduced.
-   **WG-63852** Fixed: Stack overflow in `CAkSpeakerPan::ComputeSN3DphericalHarmonics` when panning some audio to a 5th-order ambisonic bus.
-   **WG-64285** Fixed: Bus and auxiliary bus properties are affected by RTPCs/States set on an ancestor object. This bug occurs in Wwise Authoring only.
-   **WG-64287** Fixed: Crashes or memory stomps while Wwise Profiler is connected to a game.
-   **WG-64478** Fixed: Unintended object ID reassignment during Work Unit reload. Such changes occur when an object is moved from one Work Unit to another.
-   **WG-64495** Fixed: Crash during `Ak3DAudioMixer::TriageAndMix` in low-memory scenarios.
-   **WG-64496** Fixed: Music Switch Containers are not packaged into SoundBanks correctly when the container includes a switch target that is not a child of the container in the project hierarchy.
-   **WG-64669** Fixed: Deadlock in Transitions of a Music Playlist Container that do not validate essential property values.
-   **WG-64683** Fixed: SoundBank GameSync exclusions don't work with Interactive Music objects.
-   **WG-64842** Fixed: Wwise crash when the Project Load Log contains certain messages.
-   **WG-64849** Fixed: Some bus structures with Listener Relative Routing can create situations where two Master Audio Busses erroneously send to the same Output Device twice in one tick, resulting in lost audio or other errors.
-   **WG-64898** Fixed: Music Stinger parent object(s) not packaged in SoundBanks.

## Documentation Improvements

-   **WG-64404** Clarified behavior of Game Parameters bound to built-in parameters. Refer to [Binding Game Parameters to built-in parameters](https://www.audiokinetic.com/library/edge/?source=Help&id=managing_game_parameters_used_in_rtpcs#binding_game_parameter_to_built_in_parameter).
-   **WG-65140** Clarified limitation on adding RTPCs using the [Multi Editor](https://www.audiokinetic.com/library/edge/?source=Help&id=multi_editor_multi_editor).

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Need Support?

Questions? Problems? Need more info? Contact us, and we can help!

[Visit our Support page](https://www.audiokinetic.com/help/support/)

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)