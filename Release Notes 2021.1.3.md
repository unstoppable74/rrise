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

The following sections list and describe the changes to Wwise between version 2021.1.2 and version 2021.1.3.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#generic_feature_changes_2021_1_3)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#generic_behavior_changes_2021_1_3)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#generic_perf_changes_2021_1_3)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#generic_misc_2021_1_3)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#generic_bugs_2021_1_3)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#generic_community_bugs_2021_1_3)

## New Features

-   **WG-51853** Added the **Inactive Game Syncs** option to the Profiler Settings to capture all Game Syncs to be displayed in the Game Sync Monitor, whether they are associated with any playing sounds or not. For details on related changes, refer to **WG-54345** and **WG-54349** in the Behavior Changes section below.
-   **WG-53434** Profiler Filter: Added the ability through a menu option to avoid showing profiling data when there is no profiler filter active.
-   **WG-53504** (wp.py) Added Visual Studio Code integration to scaffoldings.

## Behavior Changes

-   **WG-54345** When profiling, Game Parameters not used by objects in the project are no longer synced.
-   **WG-54349** Exceptionally for this minor version, it is not possible to connect Wwise Authoring to a previous minor version of the sound engine.
-   **WG-54770** New user experience for Game Sync Monitor view. Game Syncs can now be viewed as a flat list or as a tree.
-   **WG-54968** RTPCs in Impacter are only applied at the beginning of the impact, such as after a loop or when a sound object triggers an Impacter instance multiple times.
-   **WG-55367** SounbanksInfo.xml now includes the universal identifier (GUID) for Switch Groups, State Groups, and their child Switches and States.

## Performance Changes

-   **WG-55096** Improved performance of the Voice Monitor when using filters.

## Miscellaneous Changes

-   **WG-53048** Clarified the names of the two Main Mix Configuration properties in Audio Device Editor.

## Bug Fixes

# New Features

-   **WG-54122** Fixed: Images are wrongly reported as missing in the Authoring application.
-   **WG-54484** Fixed: Appearance of Mixing Desk faders changes when moving the mouse over.
-   **WG-54514** Fixed: (Spatial Audio) An assert when shutting down the Sound Engine if `[AK::SpatialAudio::RemoveRoom()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_spatial_audio_a130a8d8fba48b2207aab063ce9ac729c.html#a130a8d8fba48b2207aab063ce9ac729c)` is not called.
-   **WG-54649** Fixed: Possible multiplication overflow on large files in `AK::StreamMgr::CAkStmTask::GetFileOffset`.
-   **WG-54772** Fixed: Game Sync Monitor displays wrong label for Game Syncs.
-   **WG-54808** Fixed: (Mac Authoring) Cannot use launch scripts without running Wwise.app first.
-   **WG-54898** Fixed: The _Save All Counters to File..._ entry in the context menu of the Performance Monitor is missing. It has been restored and renamed _Save Performance Counters._
-   **WG-54924** Fixed: Crash when editing AkGeometryComponent properties during Play In Editor.
-   **WG-54996** Fixed: Z control of Steering Panner is not updated after undo.
-   **WG-55153** Fixed: (Spatial Audio) Transmission loss is not applied when the straight line path between an emitter and the listener intersects any portal, even if the portal is not part of the path between the emitter and listener.
-   **WG-55155** Fixed: Krotos Igniter Live Synth crashes for some custom waveform files.
-   **WG-55179** Fixed: Using `DataWriter::WriteString` in Authoring plug-ins' `GetBankParameter` function always writes an empty string.
-   **WG-55183** Fixed: Source starvation when playing long Vorbis sounds with small Seek Table Granularity.
-   **WG-55206** Fixed: Rare infinite loop in CAkAudioMgr::ReserveQueue.
-   **WG-55219** Corrected an issue when using multi-positions and setting a number of positions higher than 255.
-   **WG-55234** Fixed: Convolution Reverb Effect Editor data refreshes needlessly.
-   **WG-55238** Fixed: Convolution Reverb Effect Editor does not always use impulse file when initially added.
-   **WG-55314** Fixed: (WAQL) Possible crash when using the "referenceTo" keyword.
-   **WG-55364** Fixed: Wwise projects with iZotope Trashbox Modeler plug-ins are set to dirty after project load.
-   **WG-55371** Fixed: Crash when playing sample accurate sequence container with child container that has an effect.
-   **WG-55417** Fixed: Impacter plug-in has runtime dependencies on C++ STL.
-   **WG-55458** Fixed: Device ID numbers are not displayed on Audio Devices in the Voice Graph and Voice Inspector.
-   **WG-55622** Fixed: Rare crash when using Blend Containers.

-   **WG-44867** Fixed: Possible Wwise Authoring crash when connected to a game.
-   **WG-54868** Fixed: Wwise crash when loading a project and the current theme is not found among the available themes.
-   **WG-54877** Fixed: Possible crash in Wwise when removing multiple entries in the Audio File/Folder list in the Audio File Importer dialog.
-   **WG-55072** Fixed: Insufficient memory reserved by macro CONVERT\_OSCHAR\_TO\_CHAR.
-   **WG-55319** Fixed: (Spatial Audio) In some circumstances, portal obstruction is not applied on paths that traverse multiple portals.
-   **WG-55345** Fixed: Wwise Meter plug-in causes the project to be dirty on load.
-   **WG-55347** Fixed: Crash when double-clicking on Modulator indicator in SoundSeed Grain.
-   **WG-55365** Fixed: (WAAPI) Queries using "ofType" return objects from the clipboard.
-   **WG-55527** Fixed: Auro Headphone plug-in dialog is too small in High DPI.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#new_features)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#behavior_changes)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#performance_changes)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#miscellaneous_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_3.html#fixes_for_community-reported_bugs)

_menu_