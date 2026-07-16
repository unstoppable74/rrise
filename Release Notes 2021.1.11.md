Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

Release Notes 2021.1.11

The following sections list and describe the changes to Wwise between version 2021.1.10 and version 2021.1.11.  
Platform-specific information can be found here:

[Android 2021.1.11](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=android_releasenotes_2021_1_11.html)

[iOS/tvOS 2021.1.11](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ios_releasenotes_2021_1_11.html)

[Linux 2021.1.11](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=linux_releasenotes_2021_1_11.html)

[Mac 2021.1.11](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=mac_releasenotes_2021_1_11.html)

[Windows and Windows UWP 2021.1.11](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=windows_releasenotes_2021_1_11.html)

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_11.html#generic_feature_changes_2021_1_11)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_11.html#generic_misc_2021_1_11)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_11.html#generic_bugs_2021_1_11)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_11.html#generic_community_bugs_2021_1_11)

## New Features

-   **WG-54953** Added support for metering of Loudness and True Peak values on busses performing Audio Object processing.

## Miscellaneous Changes

-   **WG-60486** Improved error messages when new assets fail to import.
-   **WG-62612** The Wwise Authoring application now provides hints to the system to use the high performance graphics mode for AMD and Nvidia GPUs.

## Bug Fixes

-   **WG-59700** Fixed: Possible crash in the Game Object 3d Viewer when resetting the 3D device.
-   **WG-60212** Fixed: Crash after attempting to load an incompatible Profiler session after a first successful session load.
-   **WG-60692** Fixed: (Spatial Audio) When a new sound plays, Room Game Objects do not update their sound paths until the listener moves.
-   **WG-61178** Fixed: Possible Wwise crash when pressing the Enter key immediately after adding an Effect.
-   **WG-61209** Fixed: (Spatial Audio) Portal occlusion on room tones is applied twice in the signal path.
-   **WG-61328** Fixed: (Spatial Audio) SetGameObjectRadius does not update paths until the listener moves.
-   **WG-61397** Fixed: (Spatial Audio) A diffraction path might be cut off before the end of a sound's attenuation radius if it passes through a portal that has a large width.
-   **WG-61595** Fixed: Connecting Wwise to a game overwrites the game's Effect bypass values set by Event Actions.
-   **WG-61684** Fixed: (wp.py) Crash when discovering installation directory for Visual Studio 2015.
-   **WG-61691** Fixed: Possible crash when connecting the profiler to a remote platform.
-   **WG-61781** Fixed: Possible case where WAV markers are ignored when playing original file in Wwise.
-   **WG-62116** Fixed: System Audio Objects sometimes disappear from Audio Device meter.
-   **WG-62433** Fixed: Low-pass filter label overlaps the control.
-   **WG-62788** Fixed: (Spatial Audio) Direct path incorrectly bends behind the listener when an emitter is in the same room and the listener is close to an off-centered portal.

## Fixes for Community-Reported Bugs

# New Features

-   **WG-52903** Fixed: Project Explorer doesn't restore expanded states correctly.
-   **WG-59422** Fixed: Crash when combining finite Sequence Containers that have Trigger rate transitions with Blend Containers that have Initial Delays.
-   **WG-60577** Fixed: Crash when deleting a Music Track while its volume slider is active.
-   **WG-60602** Fixed: Out-of-bounds memory access when encoding very small (<960 samples) sources with WEM Opus.
-   **WG-60945** Fixed: Game-Defined Auxiliary Sends don't get regular updates from RTPCs on busses.
-   **WG-60969** Fixed: (Spatial Audio) Any emitter using diffraction can become inaudible when the listener position overlaps a portal.
-   **WG-61127** Fixed: Crash in `CAkListener::MultiDirectionGainCorrectionForObjects` during low-memory scenarios.
-   **WG-61304** Fixed: (Spatial Audio) Diffraction path might be dropped and transmission loss goes to 0% when listener and emitter are in different rooms but on the same side of a portal.
-   **WG-61508** Fixed: SoundBank metadata Max attenuation for Events does not take Post Event actions into account.
-   **WG-61597** Fixed: Streaming media can be stopped if inspected by the garbage collector at the wrong time. Added more detailed logs to the AkUnrealIOHook.
-   **WG-61634** Fixed: Crash when inspecting an RTPC or State from the Multi Editor or the default plug-in property list.
-   **WG-61655** Fixed: Calling `[AK::SoundEngine::ReplaceOutput](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a81521a4611d3891c499ec9c5eb421ac2.html#a81521a4611d3891c499ec9c5eb421ac2)` with an Audio Device ShareSet of 0 can cause audio loss if the old output Audio Device is connected to multiple audio busses.
-   **WG-61686** Fixed: External Editor doesn't work on Music Clips and Music MIDI Clips in the Segment Editor.
-   **WG-61687** Fixed: WAQL originalFilePath doesn't work for MusicClip and MusicMidiClip.
-   **WG-61706** Fixed: Crash when Opus sounds start in virtual mode.
-   **WG-61727** Fixed: A nested Music Switch Container doesn't switch to the correct child when the parent Switch Container has an active Transition with a positive Offset.
-   **WG-61850** Fixed: (Spatial Audio) Any emitter using diffraction can become inaudible when the listener position overlaps a portal.
-   **WG-61981** Fixed: Crash due to memory stomp inside of CAkTransitionManager::TermList when shutting down the sound engine.
-   **WG-62017** Fixed: (Spatial Audio) AKASSERT(portalPath.IsEnabled()) in the function `AkAcousticRoom::InitContributingPortalPaths`.
-   **WG-62057** Fixed: Erroneous Seek Table Absence warnings occur when replaying Vorbis files from the beginning.
-   **WG-62149** Fixed: Imported SoundBank files can be linked with the wrong WwiseAddressableSoundbank if the former's name is a substring of the latter.  
    
-   **WG-62150** Fixed: Using S-Curve Interpolation on RTPC curves provides values outside the specified range in some cases. For example, it might generate negative values for Spread or LPF/HPF factors when the curve should stop at 0.
-   **WG-62177** Fixed: Setting a bus configuration to **Same as passthrough mix** when 3D Audio is available but passthrough is not available sets the bus configuration to Audio Objects instead of setting it to the Audio Device's main mix.
-   **WG-62358** Fixed: Crash due to stack overflow originating from `CAkVPL3dMixable::GetVolumes` in some scenarios.
-   **WG-62383** Fixed: File Packager takes a long time to complete when there are many excluded memory files in a single SoundBank.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Need Support?

Questions? Problems? Need more info? Contact us, and we can help!

[Visit our Support page](https://www.audiokinetic.com/help/support/)

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)