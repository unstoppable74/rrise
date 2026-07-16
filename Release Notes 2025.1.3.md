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

The following sections list and describe the changes to Wwise between version 2025.1.2 and version 2025.1.3.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#generic_feature_changes_2025_1_3)
-   [API Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#generic_api_changes_2025_1_3)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#generic_behavior_changes_2025_1_3)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#generic_perf_changes_2025_1_3)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#generic_misc_2025_1_3)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#generic_bugs_2025_1_3)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#generic_community_bugs_2025_1_3)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#generic_documentation_improvements_2025_1_3)

## New Features

-   **WG-72208** Added new `[AK::SoundEngine::SetAssertHook](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ad2c9fc62b22c1c995d2803f119735a85.html#ad2c9fc62b22c1c995d2803f119735a85)` function to programmatically set the assertion handler prior to Sound Engine initialization.
-   **WG-72915** Added the Command Buffer API for high-volume, low-overhead transfer of data to the Sound Engine. See [Increasing simulation data throughput with the Command Buffer API](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=goingfurther_commandbufferapi.html) for details.
-   **WG-78483** You can now use the mouse wheel to change the vertical zoom of the graph in the Parametric EQ Effect Editor and in the graphs in the Parametric EQ and Multiband Compressor modules of Mastering Suite.
-   **WG-79332** (Acoustics) Emitter clustering now works on Portal paths.
-   **WG-79612** In the Parametric EQ Effect Editor, the property list is now scrollable, so the view requires less vertical space. We also replaced the **Listen** properties with **Solo Band** and **Solo Band Dynamics Input** buttons so you can easily solo a band of audio being processed or a band of audio used for the dynamics input.
-   **WG-79630** You can now include or exclude a filter from Media Pool using a shortcut menu.
-   **WG-79645** Added a menu to the Media Pool to import selected regions when right-clicking on them.
-   **WG-79708** The Property Editor now includes a vertical fader to adjust Volume. Optionally, you can use a horizontal slider.
-   **WG-80059** Added a new button in Media Pool to stop the execution of a search.
-   **WG-80060** Added option to User Preferences to enable or disable Similar Sound Search in the Media Pool.
-   **WG-80259** Added support for Sidechain Mix ShareSets in the Meter view.
-   **WG-80260** Added support for Sidechain Mix ShareSets in Mixing Sessions.
-   **WG-80277** Added support for Command Add-ons and External Editors in the Media Pool.

## API Changes

-   **WG-74336** (WAAPI) Changed the WAAPI data model for some of the object lists. See [Important Migration Notes 2025.1](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_migration.html) for details.
-   **WG-80340** Added function to plug-in API to get speaker connections for an anonymous configuration.
-   **WG-80420** Removed support for the `IAkPluginServiceTempAlloc::GetTempAllocAudioRenderdouble` API to address reliability and design complications with sound engine plug-ins. Other functions on the `IAkPluginServiceTempAlloc` interface are unchanged. Related to this, calling `IAkEffectPluginContext::CreateOutputObjects` outside of `IAkOutOfPlaceObjectPlugin::Execute`, such as during `IAkEffectPlugin::Init` or `IAkPlugin::Reset`, now creates new [AkAudioObjects](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_audio_objects.html "A collection of audio objects. Encapsulates the audio data and metadata of each audio object in separ..."), but the associated [AkAudioBuffer](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_ak_audio_buffer.html) no longer has any pre-allocated memory for the audio data.

## Behavior Changes

-   **WG-76843** Updated peaks format to use less space in the project and Media Pool caches.
-   **WG-78426** Changed loudness of the Dual Shelf Filter when using non-zero Emphasis compared to Beta versions.
-   **WG-78428** Media Pool field names that only differed in terms of capitalization are now merged.
-   **WG-78777** Improved performance and sensitivity of region detection for the Media Pool.
-   **WG-79394** (Acoustics) `[AkSpatialAudioInitSettings::uMaxSoundPropagationDepth](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_spatial_audio_init_settings_a4d07df03b41fed0b33c61b84c692c22e.html#a4d07df03b41fed0b33c61b84c692c22e "Maximum number of rooms that sound can propagate through; must be less than or equal to AK_MAX_SOUND_...")` is now the number of rooms that sound can propagate through, where the first room is the listener's room. Setting `[AkSpatialAudioInitSettings::uMaxSoundPropagationDepth](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_spatial_audio_init_settings_a4d07df03b41fed0b33c61b84c692c22e.html#a4d07df03b41fed0b33c61b84c692c22e "Maximum number of rooms that sound can propagate through; must be less than or equal to AK_MAX_SOUND_...")` to a value less than 2 no longer propagates paths beyond the listener's room.
-   **WG-79862** **Find Similar in Media Pool** no longer appears in the shortcut menu of Project Explorer objects when it's unavailable.
-   **WG-79965** Asserts are now available in Profile SDK builds, but they are only enabled if an assert hook is provided. Because of this change, the Profile\_EnableAsserts build configuration was removed.
-   **WG-80033** In the Game Object 3D Viewer, clicking without pressing any key now cycles through objects. CTRL+click now selects multiple objects. Removed SHIFT+click behavior.
-   **WG-80304** Media Pool Similarity Search results no longer contain results with a score lower than 0.05.
-   **WG-80618** SoundBank generation no longer reports an error for continuous containers used as a MIDI target. This reverts WG-79488, which introduced the error report. Note that MIDI playback is still not stopped correctly if the MIDI target hierarchy contains a continuous container. See [Known Issues and Limitations](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_known_issues.html), issue WG-81030.

## Performance Changes

-   **WG-72322** Optimized LPF, HPF, and DSF processing. They now take less time to execute.
-   **WG-80024** Having multiple Parametric EQ graphs open while monitoring the sound engine no longer results in significant stalls in the UI across Wwise Authoring.
-   **WG-80322** Improved performance of remote connection, particularly on macOS.

## Miscellaneous Changes

-   **WG-78365** In the Property Editor, Loop and Transitions are now displayed as groups directly under the Random Container and Sequence Container categories, instead of being subgroups nested under the Mode group.
-   **WG-78947** Divided the "Finalizing..." operation of the project loader progress dialog into several more steps.
-   **WG-79646** Added advanced haptics examples to Motion Factory Presets. Note that the new Presets are not added to existing Wwise projects; they only appear in newly created Wwise projects.
-   **WG-79850** Moved the **Find Similar in Media Pool** menu item further down in the Project Explorer shortcut menu.
-   **WG-80144** Removed LPF and HPF properties from the Sidechain Send and Sidechain Receive Effects since they aren't used.
-   **WG-80233** Lua runtime now uses C++ exceptions for error handling instead of setjmp and longjmp.

## Bug Fixes

# New Features

-   **WG-62600** Fixed: Artifacts in profiling views when they auto-scroll.
-   **WG-67504** Fixed: (Acoustics) Room output normalization is shown as a volume in the Voice Graph but does not appear as a contribution in the Voice Inspector.
-   **WG-69934** Fixed: Aux Busses that are referenced by one or more user-defined Soundbanks also have an auto-defined Soundbank when auto-defined Soundbanks are enabled.
-   **WG-73871** Fixed: Opening a lot of Object Tabs can cause Wwise Authoring to hang.
-   **WG-74243** Fixed: No tooltip when hovering over remote platform connection status.
-   **WG-74536** Fixed: Wwise Authoring locks after opening a project without closing the warning that it's open in multiple instances of Wwise.
-   **WG-76692** Fixed: Entries in the Advanced Profiler's Voices tab are missing an Event ID on remote connect.
-   **WG-77038** Fixed: (WAQL) Some WAQL queries cause unstable results.
-   **WG-77566** Fixed: Parts of Game Object 3D Viewer camera toolbar appear in adjacent Selection Property pane.
-   **WG-78139** Fixed: When files are removed, the Media Pool search index maintenance sometimes deletes other entries.
-   **WG-78166** Fixed: Media Pool Filters list always fully expands when adding or removing filters.
-   **WG-78201** Fixed: Assert "CanDestroy" in `AK::StreamMgr::Term`, called at sound engine termination.
-   **WG-78345** Fixed: Assert when reloading a Work Unit that contains a Blend Track.
-   **WG-78429** Fixed: In Media Pool, selecting multiple metadata fields and clicking **Add Field as Filter** creates only one filter.
-   **WG-78614** Fixed: (Acoustics) Short sounds played with TriggerRate occasionally update with incorrect Spatial Audio properties.
-   **WG-78769** Fixed: Playback cursor jumps around when toggling the **Loop** check box in Media Pool while playing a sound.
-   **WG-78773** Fixed: In the Media Pool Audio Preview/Region Selector pane, the second of adjacent regions doesn't play.
-   **WG-78781** Fixed: In the Media Pool Audio Preview/Region Selector shortcut menu, **Select All File Markers Regions** doesn't select all regions.
-   **WG-78791** Fixed: Media Pool doesn't find files when the extension ".wav" is typed in the search field.
-   **WG-78846** Fixed: Unnecessary Live Media Transfer when using streaming files smaller than their prefetch value.
-   **WG-78922** Fixed: A pinned Reference View is updated when clicking **Find All References**.
-   **WG-78970** Fixed: In Media Pool, the Play button is not blue when playing.
-   **WG-79257** Fixed: When zooming in on the Media Pool's Audio Preview/Region Selector waveform, region icons and handles appear outside of their region.
-   **WG-79263** Fixed: (Mac Authoring) Imported files are not scheduled for analysis upon import.
-   **WG-79377** Fixed: In Media Pool, buttons at the bottom of the view overlap with the WAV information.
-   **WG-79378** Fixed: Ambisonic files are not downmixed in a way that allows region detection in Media Pool.
-   **WG-79380** Fixed: Audio Similarity filter option in Media Pool is unavailable when selecting multiple WAV files.
-   **WG-79515** Fixed: Double-clicking a hidden object in the 3D Game Object List clears the previous selection.
-   **WG-79837** Fixed: Wwise Authoring is unresponsive during Live Media Transfer of large media assets.
-   **WG-79848** Fixed: Selecting multiple Effects in the Property Editor and pressing the Delete key doesn't delete the Effects.
-   **WG-79861** Fixed: With multiple objects selected in the Project Explorer, **Find Similar in Media Pool** is unavailable in the shortcut menu.
-   **WG-79871** Fixed: Motion plug-in repeatedly outputs monitoring messages after an audio device configuration change.
-   **WG-79874** Fixed: Transitions tab's **Find in List** button displays "TION" instead of "X".
-   **WG-79906** Fixed: (Acoustics) In the Game Object 3D Viewer, Room direct paths are visible.
-   **WG-79912** Fixed: (Acoustics) Capture Log is missing information for `SetListeners`, `SetDefaultListeners`, and `SetGameObjectAuxSendValues`.
-   **WG-79922** Fixed: Similar Sound Search results are affected by commas and whitespace in the search string.
-   **WG-79943** Fixed: Some buttons don't have mouse feedback on hover.
-   **WG-79945** Fixed: Clicking **Files** or **Regions** in Media Pool overrides the destination object in the Audio File Importer.
-   **WG-79964** Fixed: (Acoustics) Diffraction paths from a Room are sometimes absent in the Game Object 3D Viewer when the Room has multiple Portals, some of which are disabled.
-   **WG-79971** Fixed: In Game Object 3D Viewer, reflection path diffraction % is still displayed when **Diffraction %** is deselected.
-   **WG-79973** Fixed: (Acoustics) Diffraction path nodes are sometimes assigned 0% diffraction when the node is on geometry that's in between two Portals.
-   **WG-79974** Fixed: (Acoustics) The diffraction coefficient is incorrectly calculated on paths with coincident diffraction points.
-   **WG-79999** Fixed: In the 3D Viewer toolbar, the Labels(Text) category is less intuitive than other categories.
-   **WG-80000** Fixed: Difficult to show/hide all objects in the 3D Game Object List.
-   **WG-80040** Fixed: (Acoustics) Display of image sources in the Game Object 3D Viewer is affected by the **Show Reflection Paths** option.
-   **WG-80063** Fixed: Object Tab doesn't update correctly when inspecting multiple modulators in succession.
-   **WG-80081** Fixed: Capture Log filtering doesn't work for API calls.
-   **WG-80083** Fixed: Spread cone visible in the Game Object 3D Viewer when there is not supposed to be any spread.
-   **WG-80105** Fixed: An active Mixing Session is unloaded after changing the user interface font or font size and after reloading the project.
-   **WG-80114** Fixed: In the Sample Project, some music transitions are broken.
-   **WG-80131** Fixed: Instability when pressing Ctrl+F4 while scrubbing a fader.
-   **WG-80143** Fixed: Sidechain Send and Sidechain Receive Effects ramp from a gain of 0db to the target volume on their initial audio render pass.
-   **WG-80165** Fixed: Toggling of Effect's Inclusion check box has no impact.
-   **WG-80167** Fixed: (Acoustics) Incorrect acoustic parameters on paths involving more than one portal.
-   **WG-80170** Fixed: (Acoustics) Diffraction paths are occasionally dropped when moving between Rooms with load balancing enabled.
-   **WG-80192** Fixed: Attempting to post an error message in the termination of a source plug-in can result in a crash.
-   **WG-80193** Fixed: Flicker in Mixing Desk controls for objects with custom object color.
-   **WG-80200** Fixed: Crash when clicking on the right edge of the 3D Viewer.
-   **WG-80244** Fixed: Media Pool's **Create new 'Media Pool Database'** buttons are not available after opening the view.
-   **WG-80284** Fixed: Deleting a Media Pool database doesn't cancel queued analysis tasks for files in that database.
-   **WG-80285** Fixed: It's possible to import a MIDI file into a non-music object.
-   **WG-80292** Fixed: `[AK::SoundEngine::SendPluginCustomGameData](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a25efe2a9b18ad130f4fc4c0c3599ec30.html#a25efe2a9b18ad130f4fc4c0c3599ec30)` crashes when sending large data buffers.
-   **WG-80310** Fixed: Unnecessary media analysis tasks are created for macOS resource fork files. For example, `._XXXX.wav`.
-   **WG-80315** Fixed: It's not possible to import a WAV file as a Music Segment using Ctrl+drag.
-   **WG-80325** Fixed: In the Audio File Importer, **Music Segment** appears twice in the Object Type/Action list.
-   **WG-80410** Fixed: Acoustic Paths from multiposition emitters are the same selection objects.
-   **WG-80438** Fixed: Waveform not displayed correctly in AK Convolution Reverb graph view.
-   **WG-80489** Fixed: Work Units that include the Reflect plug-in might become invalid after migration to Wwise 2025.1.
-   **WG-80517** Fixed: Possible crash when enabling Similar Sound Search on ADM files.
-   **WG-80545** Fixed: (Acoustics) The direct path is sometimes rendered with 0% transmission loss despite going through a wall.
-   **WG-80596** Fixed: Possible crash when reloading a project while the Audio File Importer is open.
-   **WG-80599** Fixed: The Media Pool **Import Selected Region(s)** shortcut menu item is duplicated when an object named Default Work Unit, that isn't an actual Default Work Unit, is selected in the Project Explorer.
-   **WG-80607** Fixed: Possible crash when reloading a Wwise project.
-   **WG-80613** Fixed: (Acoustics) Diffraction paths become unstable when portals overlap diffraction edges.
-   **WG-80648** Fixed: ASSERT in AkSAEmitterToListenerTask
-   **WG-80652** Fixed: Crash in `AkSAListenerToPortalTask::Execute`.
-   **WG-80680** Fixed: (Acoustics) When a sound with Diffraction and Transmission enabled is stopped and then started again, it's sometimes rendered without diffraction and transmission.
-   **WG-80758** Fixed: Crash when inspecting a Sound SFX or Sound Voice after removing it from a playlist in a Sequence Container.
-   **WG-80761** Fixed: (Acoustics) Paths though portals can sometimes be rendered with 0% diffraction, if they exceed the maximum node count of 8.
-   **WG-80861** Fixed: Crash when loading profiling sessions.
-   **WG-80898** Fixed: (Acoustics) Crash when executing a cancelled task after unregistering a game object when using path selection (uMaxGlobalReflectionPaths greater than 0).
-   **WG-80954** Fixed : Rare authoring crash when modifying audio descriptions for sMedia Pool imilarity search.
-   **WG-81060** Fixed: During a transition from two active filters to just one, the active filter does not behave correctly.
-   **WG-81073** Fixed: Menu to switch between "Bar and Beats" and "Seconds" in music segment no longer appears.
-   **WG-81142** Fixed: Shelf filter migration can break Attenuation ShareSets in some Work Units with non-standard formatting.
-   **WG-81202** Fixed : Updating already imported original media content would lead to ID collisions and the wrong converted media being packaged in soundbanks.

-   **WG-73399** Fixed: Windows 11 Snap layout feature doesn't work when hovering over Wwise Authoring's Maximize or Restore buttons.
-   **WG-76634** Fixed: Inconsistent use of precompiled headers in AkMemoryMgr. Removed old `stdafx.h` files.
-   **WG-77446** Fixed: Possible crash when selecting an object that has an Attenuation in the Project Explorer.
-   **WG-77548** Fixed: When issued from the Event Editor, the **Find in Project Explorer** shortcuts don't show the target of the selected Event Action.
-   **WG-77594** Fixed: Clicking **Show in Meter - Instance A** in the shortcut menu of an Auxiliary Bus meter opens an empty Meter view.
-   **WG-79350** Fixed: Crash in Flanger plug-in after live editing its parameters in low-memory conditions.
-   **WG-79529** Fixed: Possible crash when selecting a Music Switch Container in the Project Explorer.
-   **WG-79606** Fixed: (Acoustics) Assert and crash when `[AkSpatialAudioInitSettings::uMaxGlobalReflectionPaths](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_spatial_audio_init_settings_a79d0a9ef505102dd2960e339e526f6b8.html#a79d0a9ef505102dd2960e339e526f6b8)` is greater than 0.
-   **WG-79860** Fixed: Music transitions don't update properly when a source or destination is changed from **Any** to a specific object.
-   **WG-79873** Fixed: Music transitions with Source or Destination set to an empty Virtual Folder evaluate to "Any". Now they evaluate to "None".
-   **WG-79952** Fixed: Crash when selecting an **Override Parent** check box in the Property Editor.
-   **WG-80066** Fixed: Crashes and memory overruns when using out-of-place Effect plug-ins on Voices when the Effect uses a different channel configuration for the output signal than the input signal.
-   **WG-80094** Fixed: Assertion failure when decoding some WEM Opus files on PS5.
-   **WG-80123** Fixed: Wwise crash when right-clicking in an empty Source or Destination column in the Transitions tab.
-   **WG-80133** Fixed: (WAAPI) WAAPI sometimes sends invalid JSON when calling `[ak.wwise.core.profiler.getPerformanceMonitor](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_profiler_getperformancemonitor.html)`, which can break WAAPI clients.
-   **WG-80246** Fixed: Stack overflow in `AkNotificationSafeArray::DispatchCallbacks` when RTPC is used at large scale.
-   **WG-80308** Fixed: Crash when applying an AK Convolution Reverb Effect in Filter mode on a 7.1.4 sound source using a multichannel impulse response.
-   **WG-80425** Fixed: Binary differences in some `.bnk` and `.wem` files when generated using `Wwise.exe` compared to `WwiseConsole.exe`. Files generated by `Wwise.exe` remain unchanged, while those generated by `WwiseConsole.exe` are slightly different.
-   **WG-80455** Fixed: Wwise crash when creating Music Segment in Property Container, and Sounds in Music Switch Container.
-   **WG-80458** Fixed: Crash when holding down CTRL key while expanding objects in Project Explorer.

## Documentation Improvements

-   **WG-73005** Added missing interface elements to [Attenuation Editor](https://www.audiokinetic.com/en/library/edge/?source=Help&id=positioning_attenuation_editor).
-   **WG-75586** Added documentation for new and updated functionality of the Parametric EQ Effect plug-in.
-   **WG-80343** In all code samples, replaced instances of `AkModule.h` with `[AkMemoryMgrModule.h](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=AkMemoryMgrModule.h)`.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#new_features)
-   [API Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#api_changes)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#behavior_changes)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#performance_changes)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#miscellaneous_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#fixes_for_community-reported_bugs)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_3.html#documentation_improvements)

_menu_