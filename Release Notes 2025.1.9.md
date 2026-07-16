Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

The following sections list and describe the changes to Wwise between version 2025.1.8 and version 2025.1.9.  
Platform-specific information can be found here:

-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_9.html#generic_perf_changes_2025_1_9)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_9.html#generic_bugs_2025_1_9)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_9.html#generic_community_bugs_2025_1_9)

## Performance Changes

-   **WG-67920** Improved performance when calculating the speaker matrix for multidirectional sources to ambisonic busses. Specifically, throughput performance of `CAkSpeakerPan::MultiDirectionAmbisonicPan` has been improved by 10-15 times.
-   **WG-82868** (Acoustics) Improved performance of Rooms by preventing inaudible rooms from updating.
-   **WG-84134** (Acoustics) Optimized `AkAcousticRoom::GetPaths()`.
-   **WG-84200** (Acoustics) Optimized `AkPropagationPathArray` to cache the longest path.
-   **WG-84201** (Acoustics) Optimized `AkPathsToPortals` to reduce cache misses.
-   **WG-84202** (Acoustics) Modified the Room sends collection to use a more efficient sort algorithm.

## Bug Fixes

# Performance Changes

-   **WG-78547** Fixed: In the Game Object 3D Viewer, when **Game Units per Meter** is set to a number greater than 1, changing the **World Orientation** unzooms the view.
-   **WG-79863** Fixed: In the Property Editor, it's possible to drag and drop a group from the Favorites category onto the category buttons, causing them to become deselected.
-   **WG-80330** Fixed: SoundBanks aren't located if the path includes special characters.
-   **WG-83025** Fixed: In the Game Object 3D Viewer, cannot reselect an object after selecting another object.
-   **WG-83189** Fixed: Holding Alt while dragging a slider on multiple objects in the Multi Editor causes values to become unstable and accelerate.
-   **WG-83786** Fixed: RTPC and Parametric EQ graph editors don't support theme switching.
-   **WG-83902** Fixed: (Acoustics) Duplicate reflections paths are sometimes found.
-   **WG-83938** Fixed: Cannot set the play start position of Sequence Containers.
-   **WG-84107** Fixed: Freeze when resizing the Game Sync Monitor view to a very small size.
-   **WG-84116** Fixed: In the Capture Log, the **Save** button is available even when there's no capture session to save.
-   **WG-84120** Fixed: MIDI note playback doesn't end if the MIDI Target has an Initial Delay longer than the note's duration.
-   **WG-84462** Fixed: "Debug out-of-range check" fails to detect NaN values in audio signals when sound engine is built against modern compilers.
-   **WG-84954** Fixed: Sending a source with an Anonymous channel config to a monaural bus results in panning volumes of zero.

-   **WG-81887** Fixed: Event Cues don't display properly in Tracks.
-   **WG-83388** Fixed: Possible crash when loading a Preset or undoing the loading of a Preset.
-   **WG-83419** Fixed: Possible crash when using Perforce and importing WAV files.
-   **WG-83633** Fixed: Media excluded from a SoundBank is streamed from loose media files when connecting Wwise to a game in Profile Only mode.
-   **WG-83703** Fixed: (Mac Authoring) Audio File Importer doesn't automatically open with drag-and-drop.
-   **WG-83969** Fixed: `[PrepareEvent()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a2e6ebb779470b43d78984c27f6a0c238.html#a2e6ebb779470b43d78984c27f6a0c238)` doesn't prepare streamed media with prefetch.
-   **WG-83983** Fixed: Not possible to copy and paste from Wwise Authoring list or tree to an external tool.
-   **WG-84080** Fixed: (Acoustics) Assert in `NudgeToShadowZone()` or `NudgeToViewZone()`.
-   **WG-84091** Fixed: Crash after disconnecting Wwise from a game with Live Media Transfers in progress.
-   **WG-84375** Fixed: Crash when opening a project when databases in `.cache` fail to be created or opened.
-   **WG-84432** Fixed: MIDI playback doesn't correctly trigger a Blend Container's crossfade Modulator.
-   **WG-84447** Fixed: Possible deadlock when Wwise terminates with Live Media Transfers in progress.
-   **WG-84465** Fixed: Crash when deleting an RTPC curve on property Max Sound Instances during playback.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)