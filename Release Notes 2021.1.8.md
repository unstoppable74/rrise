Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

The following sections list and describe the changes to Wwise between version 2021.1.7 and version 2021.1.8.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_8.html#generic_perf_changes_2021_1_8)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_8.html#generic_bugs_2021_1_8)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_8.html#generic_community_bugs_2021_1_8)

## Performance Changes

-   **WG-56596** WAAPI calls made in pre or post-generation steps are now processed as fast as those run in the command line.

## Bug Fixes

-   **WG-53467** Fixed: WwiseConsole consumes 100% of CPU on macOS.
-   **WG-54064** Fixed: Callback not registered when loading a SoundBank in low-memory conditions.
-   **WG-58730** Fixed: Remote Connections dialog box doesn't always list all available instances on the local machine.
-   **WG-58825** Fixed: Incorrect DurationMin/DurationMax reported on sample-accurate containers with transition time greater than 0.
-   **WG-58947** Fixed: SoundSeed Grain is missing the filename display update in the Contents Editor.
-   **WG-59021** Fixed: Audible click when a sound transitions from Main Mix to Audio Objects due to adjustments in the Speaker Panning / 3D Spatialization Mix of the playing sound.
-   **WG-59071** Fixed: Wwise Convolution Reverb Channel Config drop-down list is not refreshed after loading a new IR file.
-   **WG-59244** Fixed: Media IDs not evaluated for custom Effects when reloading a Work Unit in the Master-Mixer Hierarchy.
-   **WG-59273** Fixed: Wwise fails to launch on macOS Monterey version 12.3.
-   **WG-59359** Fixed: WwiseConsole sometimes exits early.
-   **WG-59425** Fixed: An out-of-place Object Processor Effect on the Master Audio Bus sends erroneous data to the Audio Device.
-   **WG-59473** Fixed: Possible Wwise Authoring crash when loading plug-ins built with a more recent Wwise SDK.
-   **WG-59568** Fixed: Convolution in Filter mode replicates left channel to all dry output channels.
-   **WG-59569** Fixed: Timeout of main loop is sometimes ignored in WwiseConsole.

# Performance Changes

-   **WG-57147** Fixed: Crash in `GameObject3DCtrl::TermScene` when activating the Game Object 3D Viewer.
-   **WG-57941** Fixed: Priority "offset by distance" is not updated when a voice is virtual due to playback limit and the sound has the Hold Emitter Position and Orientation option selected.
-   **WG-58626** Fixed: (Spatial Audio) Spread applied by Spatial Audio is sometimes discontinuous when either the emitter or listener transitions into a portal that is not already on the path.
-   **WG-58706** Fixed: Missing migration step to remove boxmodel.wav original file from iZotope Box Modeler factory assets.
-   **WG-58743** Fixed: When crossing a portal, long diffraction paths may cut out, even if the diffraction value does not exceed 100%.
-   **WG-58802** Fixed: Uninitialized variable in struct `AkBufferPosInformation`.
-   **WG-58837** Fixed: Audio Device Effects sometimes fail to load when Init.bnk is loaded asynchronously.
-   **WG-58943** Fixed: Possible crash and audio corruption when using 3D Audio on Windows and Xbox.
-   **WG-59019** Fixed: Possible crash if `[AK::SoundEngine::AddOutput()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a15ab79f954a307902f529d8ccde8ad48.html#a15ab79f954a307902f529d8ccde8ad48)` is called immediately after `[AK::SoundEngine::Init()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a9a26da64092b97243844df77cbcdbf5f.html#a9a26da64092b97243844df77cbcdbf5f)`.
-   **WG-59259** Fixed: Crash when setting an RTPC value with transition under low memory conditions.
-   **WG-59382** Fixed: (Spatial Audio) Straight line paths through multiple portals can sometimes have non-zero diffraction.
-   **WG-59449** Fixed: codecvt dependency in WwiseAuthoringAPI SampleClient's AkAutoBahn library.
-   **WG-59602** Fixed: Some SoundSeed Woosh randomizer options don't work as expected when starting new instances.
-   **WG-59751** Fixed: Hang during SoundBank Generation when using a specific Switch Container structure.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)