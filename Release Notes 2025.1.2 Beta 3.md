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

The following sections list and describe the changes to Wwise between version 2025.1.1 and version 2025.1.2.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#generic_feature_changes_2025_1_2)
-   [API Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#generic_api_changes_2025_1_2)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#generic_behavior_changes_2025_1_2)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#generic_perf_changes_2025_1_2)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#generic_misc_2025_1_2)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#generic_bugs_2025_1_2)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#generic_community_bugs_2025_1_2)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#generic_documentation_improvements_2025_1_2)

## New Features

-   **WG-59168** The **Audio file destination** in the Audio File Importer view is now persisted.
-   **WG-69312** Added new parameters and controls to the Parametric EQ effect to enable it to act as a dynamic EQ. The effect now supports metering of individual bands of audio when using a Low Shelf, High Shelf, or Peaking filter, which then drives a complementary offset to the gain of each of the filters being applied. The metering can be driven by either the in-line audio signal being processed by the EQ, or a separate Sidechain Mix.
-   **WG-75446** Added extra visualization to the Parametric EQ Effect's filter graph when profiling the sound engine, showing the frequency response of the filter driving the Parametric EQ based on evaluated the built-in parameters, run-time RTPCs, and any dynamics processing. Also, added functionality to Listen to a specific section of the audio that is being affected by a certain EQ Band, and functionality to Listen to sections of audio that is driving the dynamics for a certain EQ band.

(For Release Note review: see Comments for editing-related information)

-   **WG-75640** Command Buffer: added commands to control stream caching, muting background music, sending custom data to plugins, and controlling the Suspended state of the Sound Engine.
-   **WG-76070** New experimental plug-in: Recorder (ADM) allows recording a rich object-based mix to an ADM file.
-   **WG-77697** It is possible to reorder the columns in the Media Pool Results area.
-   **WG-77953** Right-clicking a sound SFX now provides options to search for similar sounds in the Media Pool.
-   **WG-77955** New menu Show in Media Pool on Sound and Audio Source objects.
-   **WG-78560** Loading a Profiler Session is now accessible through the Profiler menu, from the Capture Log with a button, and as a command in the Wwise Shortcuts.
-   **WG-78690** A new menu option in the Media Pool Results area lets you import detected regions of selected audio files.
-   **WG-78807** Right-clicking on a Media Pool database now provides options to add folders and rescan the database.
-   **WG-78893** New WAAPI functions to query the Media Pool.
-   **WG-79079** Added new property to the Parametric EQ effect to limit the maximum number of bands of processing the effect may do. Even if higher bands are disabled, lower values for this can slightly reduce the CPU and memory cost of the effect.
-   **WG-79102** (Acoustics) Diffraction coefficients are now more accurately computed when an emitter or listener moves around an obstacle, with a reduced reliance on updating the nodes within the path itself. This allow the use of a higher movement threshold, higher load balancing spread, or larger clustering distances while minimizing loss of quality.
-   **WG-79331** New API for plug-ins to query detailed information about the output device they are routed to.
-   **WG-79564** Added controls to the Parametric EQ to Listen to, or "Solo", parts of the audio being affected by a specific band of the EQ process. Controls have also been added to Listen to a specific band of the input signal being used to drive the Dynamics for the EQ effect.
-   **WG-79841** Added a new boolean attribute to properties defined in a plug-in's XML description: "Temporary". When set, this prevents plug-in properties from being saved and persisted in the Wwise Project. This can be useful for certain properties that are only meant to be used when Wwise is connected to the sound engine.

## API Changes

-   **WG-69594** New API [AK::SoundEngine::ResetGlobalValues()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a532bfa9818dd773fcc34266fdc4006a2.html#a532bfa9818dd773fcc34266fdc4006a2) can be used to reset States, RTPCs in the Global scope, all changes made by Set Volume, Pitch, LPF, HPF event actions, effect Bypass flags and Effects changed through AK::SoundEngine::SetEffect.
-   **WG-75457** Added a new API for providing custom channel configurations for Sidechain Mixes at runtime, `[AK::SoundEngine::SetSidechainMixConfig](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_afd4347eabf3e6ef76ab641796d48b2ce.html#afd4347eabf3e6ef76ab641796d48b2ce)`.

## Behavior Changes

-   **WG-78137** Audi Source File paths in Generated Sound Bank Content TXT Files are now relative instead of absolute.
-   **WG-79323** The Motion Bus and Device are now in their own Work Units when importing Factory Motion.
-   **WG-79488** Soundbank generation reports an error for continuous containers used as a MIDI Target.

## Performance Changes

-   **WG-47170** Improved throughput performance of Metering functions when usage of AVX2 instructions is active.
-   **WG-78551** Performance Change: (Spatial Audio) Calculation of the indirect paths and reverb sends has been moved into a task. This allows this code to run in parallel, and to be load balanced, if desired. It significantly reduces the cost of updating a game object position, when using Spatial Audio.

## Miscellaneous Changes

-   **WG-79365** Sidechain Mixes have been moved into their category in the Project Explorer, instead of being grouped with Effects. Note that any Sidechain Mix objects created in previous releases of the Wwise 2025.1 Beta will be deleted and have to be re-created.
-   **WG-79455** None State exposed in the States Values tab.
-   **WG-79501** Improved logging performance of SetPosition API call in Capture Log.
-   **WG-79514** Wwise Console now logs more details when a project fails to open.

## Bug Fixes

# New Features

-   **WG-45038** Fixed: selection sphere can be smaller than icons.
-   **WG-77920** Fixed: (Acoustics) Toggling between rays and paths in the Game Object 3D Viewer causes paths to flicker.
-   **WG-78529** Fixed: crash when repeatedly loading sound banks with an unsupported version.
-   **WG-78614** Fixed: (Acoustics) Short sounds played with TriggerRate occasionally update with incorrect Spatial Audio properties.
-   **WG-78920** Fixed : CamelCase words were not properly indexed for search in the media pool.
-   **WG-78977** Fixed: (WAAPI) When creating Events in Project Explorer, the order of the notifications for the nameChanged and childAdded topics is not consistent across the different user interface actions.
-   **WG-79023** Fixed: Some captions have inconsistent tooltip text.
-   **WG-79072** Selection properties of a virtual position in the Game Object 3D Viewer should include the properties of their corresponding path.
-   **WG-79169** Fixed: (Acoustics) Room transmission loss doesn't interpolate correctly through a portal when leaving a hierarchy.
-   **WG-79232** Fixed: When using Auto-play and Loop in the Media Pool, multiple regions can play simultaneously.
-   **WG-79244** Fixed: (Acoustics) Rays cast from the listener are continuously added and then removed around some edges. This can cause unnecessary path updates.
-   **WG-79306** Fixed: 3D Game Object List eye icon state doesn't persist across connection/disconnections.
-   **WG-79320** Fixed: The Game Object Name column in the Capture Log can be incorrect for some game objects.
-   **WG-79363** Fixed: The selection properties of all positions of a multi-position emitter are not the same
-   **WG-79392** Fixed: Contextual help is not available on the Sidechain Send and Sidechain Receive plug-ins.
-   **WG-79393** Fix: Sidechain Mixed can't be linked/unlinked
-   **WG-79493** Fixed: 3D Game Object List row height is lower than eye button height.
-   **WG-79495** Fixed: 3D Viewer Tool bar display options reads "Text" instead of "Labels".
-   **WG-79505** Fixed: Windows can automatically turn on efficiency mode for Wwise Authoring application and tools.
-   **WG-79507** Fixed: Dangling Room ID on reflection selection info structure.
-   **WG-79508** Fixed: In the Game Object 3D Viewer, clicking on the Display Options button toggles a blue color regardless of the outcome. Fixed: Game Object 3D Viewer Follow button doesn't have a keyboard shortcut.
-   **WG-79525** Fixed: Some Spatial Audio properties are missing from the Selection Properties pane.
-   **WG-79526** Fixed: Incorrect and missing Reflection Path data in the 3D Selection Property pane.
-   **WG-79528** Fixed: 3D Toolbar tooltips are not identical to drop-down list tooltips.
-   **WG-79530** Fixed: (Acoustics) Diffraction node properties in the Game Object 3D Viewer show incorrect room information.
-   **WG-79537** Fixed : Media Pool files with the same filename in the same database would not all appear in searhc results.
-   **WG-79547** Fixed: Results don't update when adding new databases from folders in the Media Pool.
-   **WG-79586** Fixed: Infinite loop on SoundEngine `[Term()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_comm_a94e307d2974b89cc4fbc8ab0fef20d2f.html#a94e307d2974b89cc4fbc8ab0fef20d2f)` in low-memory conditions.
-   **WG-79589** Fixed: Columns of the Game 3D Viewer Selection Pane cannot be resized.
-   **WG-79590** Fixed: 3D Game Object List has wrong default columns and size.
-   **WG-79601** Fix: crash when live-editing a source
-   **WG-79639** Fixed: Results are slow when using Include/Exclude options on Media Pool databases and folders.
-   **WG-79725** Fixed: Terminating the sound engine after loading a soundbank containing a Sidechain Mix shareset, but without manually unloading the soundbank, results in a crash.
-   **WG-79755** Fixed: SoundBanks do not follow the Wwise Authoring's Hierarchy in the Wwise Browser.
-   **WG-79782** Fixed: AVX instructions would be called from non-AVX section of code when running an unoptimized executable with the Debug AkSoundEngine libraries.
-   **WG-79821** Fixed: In Project Explorer, the name of an object could be cut when it was renamed in another layout.

-   **WG-76564** Fixed: Switch Container takes into account Playing-ID-scoped RTPC values when determining initial state of playback.
-   **WG-77065** Fixed: Crash when renaming an object in the Project Explorer and confirming with the mouse.
-   **WG-77998** Fixed: Whenever Effect Bypass is bound by an RTPC in an Effect chain, other Effects in the chain are no longer bypassed.
-   **WG-78438** Fixed: Importing files over 800MB with `ak.wwise.core.audio.import` using the `audioFileBase64` argument fails.
-   **WG-78541** Fixed: **Jump to Specific Playlist Item** tooltip display issue in some cases.
-   **WG-78643** Fixed: Missing tooltip while dragging control point in music segment.
-   **WG-79135** Fixed: Possible crash when interacting with the Transitions tab of a Music Playlist Container.
-   **WG-79322** Fixed: Stack overflow in `CAkListener::ComputeSpeakerMatrixWithRays` in some scenarios with heavy usage of Spatial Audio.
-   **WG-79428** Fixed: SoundBank generation is longer than expected when some of the project's original WAV files have many references.
-   **WG-79463** Fixed: `SetMultiplePosition` does not honor emitter channel mask for multichannel sounds with height channels going into an Audio Objects bus.
-   **WG-79573** Fixed: Blend Containers with **Play Mode** set to **Continuous** sometimes report a DurationType that's not infinite.
-   **WG-79614** Fixed: (Acoustics) Crash in `AkKeyArray` when removing a Portal from a scene.
-   **WG-79635** Fixed: Music stops playing when connecting to a game and some files are missing from the `Originals` folder.
-   **WG-79638** Fixed: Project load is slow when loading large Dynamic Dialogue Work Units.
-   **WG-79658** Fixed: (Acoustics) A -6dB normalization gain for game-defined auxiliary sends is applied to the output of room busses, even when **Game-Defined Auxiliary Sends** is disabled.
-   **WG-79661** Fix: assert in AkParamTarget
-   **WG-79705** Fixed: Crash in `AkMemoryArena::HugeHeap::Malloc` if `AkMemoryArenaSettings::fnMemAllocSpan` returns a nullptr.

## Documentation Improvements

-   **WG-68404** Removed Fit to Geometry note about Phys Material Override since it's no longer accurate with Unreal Engine 5.
-   **WG-79484** Fixed: Mentions of Game Units To Meters instead of Game Units Per Meter.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#new_features)
-   [API Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#api_changes)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#behavior_changes)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#performance_changes)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#miscellaneous_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#fixes_for_community-reported_bugs)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_2.html#documentation_improvements)

_menu_