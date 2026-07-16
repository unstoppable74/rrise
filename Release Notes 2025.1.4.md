Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

Release Notes 2025.1.4

The following sections list and describe the changes to Wwise between version 2025.1.3 and version 2025.1.4.  
Platform-specific information can be found here:

[Android 2025.1.4](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=android_releasenotes_2025_1_4.html)

[OpenHarmony 2025.1.4](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=openharmony_releasenotes_2025_1_4.html)

[iOS/tvOS/visionOS 2025.1.4](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ios_releasenotes_2025_1_4.html)

[Linux 2025.1.4](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=linux_releasenotes_2025_1_4.html)

[Mac 2025.1.4](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=mac_releasenotes_2025_1_4.html)

[Windows 2025.1.4](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=windows_releasenotes_2025_1_4.html)

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_4.html#generic_feature_changes_2025_1_4)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_4.html#generic_behavior_changes_2025_1_4)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_4.html#generic_perf_changes_2025_1_4)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_4.html#generic_misc_2025_1_4)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_4.html#generic_bugs_2025_1_4)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_4.html#generic_community_bugs_2025_1_4)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_4.html#generic_documentation_improvements_2025_1_4)

## New Features

-   **WG-79096** After clicking an expander arrow in the Property Editor, you can use the left and right arrow keys to expand or collapse the group.
-   **WG-79513** Audio File Importer and Media Pool can now import regions into music clips.
-   **WG-80946** (WAAPI) `[ak.wwise.waapi.getSchema](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_waapi_getschema.html)` now returns a description of the function or topic.
-   **WG-80965** (WAAPI) `ak.wwise.core.executeLuaScript` now supports `luaString` as an argument to execute Lua code without a file.

## Behavior Changes

-   **WG-80630** The WwiseConsole in waapi-server mode now publishes the `[ak.wwise.core.log.itemAdded](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_log_itemadded.html)` topic and returns results with `[ak.wwise.core.log.get](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_log_get.html)`.
-   **WG-80891** Media Pool region detection no longer tries to include intro and outro silence for sounds that might be one-shots with intentional silence. Region detection now trims intro and outro silence in all cases.

## Performance Changes

-   **WG-81182** Improved performance of virtual voices by 15%.
-   **WG-81236** Improved performance of in-Authoring sound engine updates.

## Miscellaneous Changes

-   **WG-78734** In the Property Editor, added a **Reset to Default** option for the Favorites category.
-   **WG-80821** Small optimization of RTPC changes when used in Blend and Switch containers.

## Bug Fixes

# New Features

-   **WG-47058** Fixed: Language exclusions for Sound Voices are not copied when copying platform settings.
-   **WG-72712** Fixed: Contextual Help view sometimes reverts to the default property description instead of displaying the description of the last selected property.
-   **WG-76035** Fixed: Marquee selection on a sound's HDR envelope doesn't select the right points.
-   **WG-78067** Fixed: (Acoustics) The direct path hit point and transmission loss percentage jump around sporadically in the Game Object 3D Viewer.
-   **WG-78311** Fixed: `WwiseAuthoring_Tests.sln` is missing in Level 3 source code package.
-   **WG-78866** Fixed: Various memory leaks in the authoring tool, including during project migration.
-   **WG-78876** Fixed: The outer area of Solo/Mute buttons cannot be clicked.
-   **WG-79146** Fixed: (Acoustics) Room Transmission Loss doesn't transition smoothly when transition regions overlap.
-   **WG-79536** Fixed: In Media Pool, you can't bring the horizontal splitter all the way down.
-   **WG-79937** Fixed: Possible crash when configuring the columns in the Media Pool Results pane.
-   **WG-80067** Fixed: Possible assert in Wwise Debug when closing a project while sounds are playing in the Transport Control.
-   **WG-80076** Fixed: Unselected objects are drawn on top of selected objects.
-   **WG-80082** Fixed: Incorrect DSF final value in the Voice Inspector when a game-defined auxiliary send DSF is used.
-   **WG-80235** Fixed: Music playback sometimes crashes under low-memory conditions.
-   **WG-80239** Fixed: (Acoustics) Occasional glitch when moving through a Portal with load balancing enabled.
-   **WG-80337** Fixed: Possible crash when interacting with a List View while the Media Pool is scanning new audio files.
-   **WG-80360** Fixed: Copying and pasting in a Sequence Container copies objects multiple times.
-   **WG-80411** Fixed: Closing the search field of the List View can cause an assert.
-   **WG-80427** Fixed: There is no indication that only the Peak metering mode works for Sidechain Mixes.
-   **WG-80480** Fixed: Possible crash when closing a project.
-   **WG-80490** Fixed: Game Object 3D Viewer multiselection doesn't behave as expected.
-   **WG-80650** Fixed: (Acoustics) AKASSERT(i == j || (\*this)\[i\].PathID() != (\*this)\[j\].PathID()) when calculating reflection paths.
-   **WG-80671** Fixed: **Split to the Right** shortcut menu item splits the wrong tab when not the selected one.
-   **WG-80672** Fixed: Sequence Containers with crossfade start more than two sounds if an unplayable item is part of the sequence.
-   **WG-80701** Fixed: Image source icons have uniform color and alpha in the Game Object 3D Viewer when reflection paths are hidden.
-   **WG-80706** Fixed: In the Media Pool, pressing TAB on the keyboard doesn't set the focus on the correct control.
-   **WG-80711** Fixed: Analysis of invalid originals file can be cached.
-   **WG-80739** Fixed: Editing the automation path of a playing sound can cause silence.
-   **WG-80791** Fixed: A warning message sometimes appears over the search results in Media Pool.
-   **WG-80798** Fixed: Media Pool Database names are truncated when collapsed using arrow keys.
-   **WG-80897** Fixed: (Acoustics) Assert caused by a Portal that has been moved or disconnected.
-   **WG-80922** Fixed: Artifacts when scrolling up and down in the Mixing Desk.
-   **WG-80923** Fixed: The shortcut menu doesn't always appear when right-clicking an expander arrow in the Project Explorer.
-   **WG-80925** Fixed: Double-clicking a cue in the Music Segment Editor or Source Editor starts a marquee selection.
-   **WG-80929** Fixed: Possible crash when calling `CAkDefaultIOHookDeferred::Term` immediately after `[AK::SoundEngine::Term](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a90f8c91937038615480db2b57ce2279e.html#a90f8c91937038615480db2b57ce2279e)` while streaming sounds are still playing.
-   **WG-80953** Fixed: The HPF icon on bus connections does not appear in the Voice Inspector.
-   **WG-80960** Fixed: (Acoustics) Sounds with large or infinite attenuation distances are sporadic and unstable when the max diffraction path limit is exceeded.
-   **WG-81030** Fixed: Continuous containers are not stopped correctly when played in a MIDI context. Note that for the container to stop correctly, it must have at least one Envelope Modulator configured to stop playback after release.
-   **WG-81033** Fixed: It's sometimes impossible to drag items from a Random Container or a Sequence Container.
-   **WG-81041** Fixed: Crash when loading profiling sessions.
-   **WG-81076** Fixed: DSF Final Value incorrectly reported in Voice Inspector.
-   **WG-81213** Fixed: Crash in Unreal Editor when live editing a new Event.
-   **WG-81216** Fixed: Performance regression when generating SoundBanks through WwiseConsole.
-   **WG-81268** Fixed: (Acoustics) An error in the path segments between an emitter and their nearby Portals causes paths to sometimes not show up until the listener is in the same room as the emitter.
-   **WG-81365** Fixed: Possible memory corruption during Live Media Transfer.
-   **WG-81404** Fixed: Possible failure of file transfer during Live Media Transfer.

## Fixes for Community-Reported Bugs

-   **WG-70394** Fixed: WwiseConsole crashes when install files are missing.
-   **WG-79113** Fixed: (Acoustics) Portal obstruction and occlusion are not applied to a path when there is diffraction from geometry between the listener and the Portal.
-   **WG-79362** Fixed: Process not responding during initial indexing of a project.
-   **WG-79983** Fixed: (Acoustics) The distance of a wet (reverberant) path from the emitter to an adjacent room and then to the listener is misrepresented as the direct distance between the emitter and listener. A new distance model is now used that takes into account the distance between the emitter or listener and their closest Portals.
-   **WG-80095** Fixed: Possible assert when a streamed voice transitions from virtual to physical.
-   **WG-80161** Fixed: Crash in `AkRTree` with ill-formed geometries resulting in infinite dimension.
-   **WG-80401** Fixed: Moving cursors in the Attenuation Settings graph view does not update the audible attenuation preview for the Transport Control object.
-   **WG-80544** Fixed: Scrolling with the trackpad is unusable on MacOS.
-   **WG-80615** Fixed: Stinger Cue Name field not enabled when selecting Next Cue or Custom Cue.
-   **WG-80724** Fixed: (Acoustics) Invalid distance attenuation when inside a Room with a room tone using a Distance Probe.
-   **WG-80745** Fixed: (Acoustics) Room Transmission Loss doesn't interpolate correctly over the first Portal away from an emitter.
-   **WG-80783** Fixed: `.meta` files are parsed by the project database during asset import.
-   **WG-80807** Fixed: Floating windows lose maximized state when switching layout.
-   **WG-80940** Fixed: (Acoustics) Crash in `AkSoundGeometry::DistanceSqToPortalCutout()`.
-   **WG-80948** Fixed: Decoding errors when streaming long WEM Opus sounds that loop.
-   **WG-80998** Fixed: Hang when exiting a Unity game that was off-focus (suspended).
-   **WG-81088** Fixed: Crash when loading a project or deleting an object.
-   **WG-81271** Fixed: Possible hang in `AK::JobMgr::Internal::JobPool_InitEntry` when terminating the sound engine or stopping all sounds and removing all outputs.
-   **WG-81305** Fixed: Crash when `[AK::SoundEngine::Term](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a90f8c91937038615480db2b57ce2279e.html#a90f8c91937038615480db2b57ce2279e)` is called while Live Media Transfers are in progress.

## Documentation Improvements

-   **WG-79613** Added documentation for developers integrating Sidechain Mixes into third-party Effect plug-ins. See [Adding Support for Sidechain Mixes to Audio Plug-ins](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=effectplugin_sidechainmix.html).
-   **WG-80228** Added description of orthographic camera movement in [Examining objects with the Game Object 3D Viewer](https://www.audiokinetic.com/library/edge/?source=Help&id=examining_objects_with_game_object_3d_viewer).
-   **WG-80424** Updated [Obstruction and Occlusion with Game-defined Auxiliary Sends](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=soundengine_obsocc.html).
-   **WG-80725** Clarified the limitations of triggering Spatial Audio events with MIDI.
-   **WG-80818** Updated and reorganized [Managing file packages](https://www.audiokinetic.com/library/edge/?source=Help&id=Managing_File_Packages) and subpages. Clarified best practices for packaging DLC.
-   **WG-80982** Clarified upmixing scenarios in [Balance-Fade speaker panning illustrated](https://www.audiokinetic.com/library/edge/?source=Help&id=balance_fade_illustrated).
-   **WG-80986** Clarified limitations of the [Time Stretch](https://www.audiokinetic.com/library/edge/?source=Help&id=wwise_time_stretch_plug_in) plug-in and suggested an alternative for music objects.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Need Support?

Questions? Problems? Need more info? Contact us, and we can help!

[Visit our Support page](https://www.audiokinetic.com/help/support/)

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)