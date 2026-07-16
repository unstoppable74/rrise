Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

Release Notes 2021.1.10

The following sections list and describe the changes to Wwise between version 2021.1.9 and version 2021.1.10.  
Platform-specific information can be found here:

[Android 2021.1.10](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=android_releasenotes_2021_1_10.html)

[iOS/tvOS 2021.1.10](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ios_releasenotes_2021_1_10.html)

[Linux 2021.1.10](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=linux_releasenotes_2021_1_10.html)

[Mac 2021.1.10](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=mac_releasenotes_2021_1_10.html)

[Windows and Windows UWP 2021.1.10](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=windows_releasenotes_2021_1_10.html)

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_10.html#generic_behavior_changes_2021_1_10)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_10.html#generic_perf_changes_2021_1_10)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_10.html#generic_bugs_2021_1_10)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_10.html#generic_community_bugs_2021_1_10)

## Behavior Changes

-   **WG-60412** Multi-channel Audio Objects that are sent to the output device as System Audio Objects now have volumes similar to those of equivalent multi-channel sources being panned to a Main Mix or Passthrough Mix. This change reduces the volume of multi-channel System Audio Objects by several decibels depending on their channel count, for example -3db for a stereo source or -7db for a quadraphonic source. In practice, this means that any corrections to the mix that were made specifically for 3D Audio in this regard can be removed.

## Performance Changes

-   **WG-54292** (Spatial Audio) Reduced the number of redundant paths for room game objects.

## Bug Fixes

# Behavior Changes

-   **WG-58695** Fixed: Possible crash when removing Voice Data profiling data and doing Start Capture.
-   **WG-59298** Fixed: Changes to the volume matrix in the `AK_SpeakerVolumeMatrix` callback only take effect on the next audio frame.
-   **WG-59312** Fixed: Audio Objects that are mixed to a Main Mix or Passthrough Mix on the Output Device have an audible crackle due to discontinuous panning when the Audio Object position changes.
-   **WG-59864** Fixed: Wwise undo commands stop working if the client is closed while using WAAPI scripts.
-   **WG-60068** Fixed: The visual size of the spread circle is wrong in the Audio Object 3D View when using Focus and Spread at the same time with mono sounds.
-   **WG-60103** Fixed: Memory leak when running the sound engine while allocating a new effect.
-   **WG-60348** Fixed: `SetGameObjectRadius` API call does not return its Game Object ID.
-   **WG-60428** Fixed: 4-channel Audio Objects that are sent to the output device as individual System Audio Objects have improper positioning.
-   **WG-60510** Fixed: `ComputeSphericalVBAPGains` returns slightly inaccurate volumes.
-   **WG-60564** Fixed: Possible memory leaks when memory allocations fail while registering game objects.
-   **WG-60579** Fixed: `SetGameObjectToPortalObstruction` and `SetPortalToPortalObstruction` objects and values are not printed to API Calls.
-   **WG-60686** Fixed: Property Editor does not refresh correctly when viewing a Music Switch Container after a Work Unit is reloaded.
-   **WG-60833** Fixed: Time Stretch effect on virtual voice (play from elapsed time) can cause CPU spike with certain Pitch values.
-   **WG-60861** Fixed: Crash when sending empty `[AkAcousticSurface](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_acoustic_surface.html)` names.
-   **WG-60899** Fixed: Crash in Query Editor when Column Configuration includes "Sizes Preview/Total Size".
-   **WG-60919** Fixed: Cannot paste a music clip after cutting it in the Music Segment Editor.
-   **WG-60938** Fixed: Incorrect samples produced in the tail of a Time Stretch effect.
-   **WG-60967** Fixed: Wwise leaks memory when copying or cutting Music Event Cues.

## Fixes for Community-Reported Bugs

-   **WG-59458** Fixed: Audio distortion when using more than one Mastering Suite plug-in in a single project.
-   **WG-59586** Fixed: Possible crash when using a slider to adjust a convolution reverb property.
-   **WG-59913** Fixed: Crash when calling `[AK::SoundEngine::StopAll](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a0439f61753f31e6b5bb0b42a140ad598.html#a0439f61753f31e6b5bb0b42a140ad598)` right after `[AK::SoundEngine::ClearBanks](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ab934f98a6622976d24e0a096911eb0c8.html#ab934f98a6622976d24e0a096911eb0c8)` while MIDI music contexts are playing.
-   **WG-59929** Fixed: Portal obstruction does not affect room tones.
-   **WG-60215** Fixed: Audio Input plug-in does not produce sound in Wwise Authoring.
-   **WG-60243** Fixed: Crash when audio device is disconnected for a long time.
-   **WG-60352** Fixed: Effect plug-ins are packaged in SoundBanks for unlinked platforms.
-   **WG-60373** Fixed: (Spatial Audio) A room tone that propagates to the listener's room through two possible paths, while traversing different intermediate rooms, is only heard through the shorter of the two paths.
-   **WG-60415** Fixed: Cannot import audio files using unicode characters on macOS.
-   **WG-60576** Fixed: Crash when reloading a State Group Work Unit while a Music Switch Container is in the Property Editor.
-   **WG-60592** Fixed: Crash when using Modulators that use RTPCs bound to built-in properties.
-   **WG-60618** Fixed: Errors reported by Address Sanitizer for `AK::DeviceEnumeratorHelper()` function.
-   **WG-60699** Fixed: Crash when opening a project when colors are set on Music Clips.
-   **WG-60739** Fixed: Custom Properties are not accessible in WAQL when they are defined under the project.
-   **WG-60823** Fixed: Crash when using the curve menu on the Audio Source Editor after the source is changed in an external editor.
-   **WG-60946** Fixed: Importing an additional audio file source using WAAPI or tab-delimited import does not set the source as active.
-   **WG-61077** Fixed: Crash when playing a Music Switch Container using a Switch Group linked to an RTPC with a built-in value (distance, for example).

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Need Support?

Questions? Problems? Need more info? Contact us, and we can help!

[Visit our Support page](https://www.audiokinetic.com/help/support/)

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)