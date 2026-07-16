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

The following sections list and describe the changes to Wwise between version 2019.2.8 and version 2021.1.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#generic_feature_changes_2021_1)
-   [API Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#generic_api_changes_2021_1)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#generic_behavior_changes_2021_1)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#generic_perf_changes_2021_1)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#generic_misc_2021_1)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#generic_bugs_2021_1)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#generic_community_bugs_2021_1)

## New Features

# New Features

-   **WG-32040** Added a new query syntax, Wwise Authoring Query Language (WAQL), to greatly enhance project search capabilities.
-   **WG-37429** Standardized the upper portion of the Property Editor across views and made it more compact.
-   **WG-40303** Added user preference to select font typeface and size for better accessibility and readability.
-   **WG-42535** Added **Profile Only** mode to the Remote Connection options. This new option allows fast connection to a remote PC or game console for profiling and prevents sound engine changes due to unexpected synchronization.
-   **WG-43127** Breaking Plug-in API Change! Object-Based Configuration is now available on mixing busses:
    -   Deprecated Mixer Plug-Ins
    -   New Object Processor Effects `AK::IAkObjectAwareEffectPlugin`
    -   `AK::IAkSourcePluginContext::NodeID` has been removed in favor of `AK::IAkVoicePluginInfo::GetAudioNodeID`
    -   `[AK::IAkMixerPluginContext](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_i_ak_mixer_plugin_context.html "Interface to retrieve contextual information for a mixer.")` is now available to all Effects inserted on busses.
    -   `[AK::IAkMixerPluginContext::Compute3DPositioning()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_i_ak_mixer_plugin_context_aa3aebb0cd836c0dcab14e3d862e13626.html#aa3aebb0cd836c0dcab14e3d862e13626)` in\_fSpread and in\_fFocus arguments' range has changed from \[0,100\] to \[0,1\].
-   **WG-43531** (New Wwise Authoring Plug-in API) Added State and Linked status property accessor to the PropertySet interface.
-   **WG-44017** Added stomp allocator to AkMemoryMgr. Enable with `[AkMemSettings::uMemoryDebugLevel](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_mem_settings_ae97967db68ec10e8410af9f776f89e0d.html#ae97967db68ec10e8410af9f776f89e0d "Default 0 disabled. 1 debug enabled. 2 stomp allocator enabled. 3 stomp allocator and debug enabled....")` = 2. This is a debug only allocator that uses a "page per allocation" style allocation strategy to trap most invalid writes. Note that this allocator is very slow and uses a large amount of virtual memory. As such, enable to track specific problems rather than by default for development.
-   **WG-46032** (WAAPI) Added call `[ak.wwise.core.profiler.enableProfilerData](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_profiler_enableprofilerdata.html)` to enable profiling data from WAAPI.
-   **WG-46426** Added new field in the Query Editor to execute WAQL queries.
-   **WG-46885** Added new menu in the Segment Editor to edit Music Segment Custom Cue times and color in Multi Editor.
-   **WG-46920** Added `[AK::MemoryMgr::DumpToFile](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_memory_mgr_a4f48ed6707ab2f2341f4a81f1c6053d7.html#a4f48ed6707ab2f2341f4a81f1c6053d7)` to allow dumping of current allocations to a file.
-   **WG-46966** Added runtime memory debugging to AkMemoryMgr, accessible via `[AkMemSettings::uMemoryDebugLevel](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_mem_settings_ae97967db68ec10e8410af9f776f89e0d.html#ae97967db68ec10e8410af9f776f89e0d "Default 0 disabled. 1 debug enabled. 2 stomp allocator enabled. 3 stomp allocator and debug enabled....")`. This enables leak tracking and very basic integrity checks.
-   **WG-47071** On Work Unit file changes outside of Wwise, Wwise now attempts to reload only the changed Work Units as opposed to reloading the entire project.
-   **WG-47308** Added new experimental WEM Opus codec with performant seeking behavior.
-   **WG-47415** Improved usability of the Effect Editor when the Effect is showing monitoring information.
-   **WG-47487** Added two new options in the Conversion Settings to force the conversion of imported sounds to 5.1 or to 7.1 formats.
-   **WG-47492** Wwise Reflect Effect plug-in can now output Audio Objects if its parent's bus configuration is Object-Based.
-   **WG-47542** Added two new Spatial Audio functions to the API to add obstruction to paths without using diffraction and geometry. The new functions are:
    -   `AKRESULT SetGameObjectToPortalObstruction(AkGameObjectID in_gameObjectID, AkPortalID in_portalObjectID, AkReal32 in_fObstruction)`
    -   `AKRESULT SetPortalToPortalObstruction(AkPortalID in_portalObjectID0, AkPortalID in_portalObjectID1, AkReal32 in_fObstruction)`
-   **WG-47794** Added debug C runtime allocator hooks for `[AK::MemoryMgr](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_memory_mgr.html)`.
-   **WG-47948** Color Picker button has a new look with a paint palette.
-   **WG-48049** The Bus Property Editor now shows more information about the processing status of the bus.
-   **WG-48356** Removed Opus encoder Frame Size parameter. This has no impact on the quality of the encoding and improves decoding performance.
-   **WG-48591** Added ancestor and descendant filtering of music transitions.
-   **WG-48609** Default assert handlers now print a stacktrace.
-   **WG-48612** Added Memory Manager allocation tracing system.
-   **WG-48811** Added a tooltip to show custom cue times in the Music Segment Editor.
-   **WG-49192** Added Ping column to Remote Connections dialog box.
-   **WG-49210** (Mac Authoring) The 3D views are now available.
-   **WG-49453** Added information to indicate if a bus is mixing (processing) or not. Bus icons show if it is mixing (processing). The meter captions also indicate if it is mixing or not, and a tooltip indicates the reason it is mixing (processing).
-   **WG-49658** (WAAPI) Added `[ak.wwise.core.profiler.getAudioObjects](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_profiler_getaudioobjects.html)` to retrieve the Audio Objects from a profiling session. Also added to `[ak.wwise.core.profiler.getVoices](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_profiler_getvoices.html)` and `[ak.wwise.core.profiler.getBusses](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_profiler_getbusses.html)` the ability to get a single voice or bus using a pipeline ID.
-   **WG-49689** System Audio Device now shows profiling information.
-   **WG-49906** Replaced the legacy Opus codec with Audiokinetic's WEM Opus encoder.
-   **WG-49923** Added 3D Audio support on the System Audio Device.
-   **WG-50144** Emitter spread cones are now visible in the Game Object 3D Viewer, when enabled. They are displayed as defined by the attenuation ShareSet for a sound, or as calculated by Spatial Audio, in the case of radial emitters and rooms and portals.
-   **WG-50198** Added a setting to change the text size in the Game Object 3D Viewer.
-   **WG-50261** Added the ability to create Work Units under Music Switch Containers.
-   **WG-50456** Added a collapsible splitter to the Performance Monitor for the Value list.
-   **WG-50503** (New Wwise Authoring Plug-in API) Added write functions to DataWriter for uniformity with the PropertySet interface.
-   **WG-50632** Added keyboard shortcut F2 to rename Transitions in the Transition Matrix.
-   **WG-50699** (Mac Authoring) Added a menu option to scan for project and Work Unit changes.
-   **WG-50780** Added new context menu when holding the SHIFT key to generate a WAQL query and copy it to the clipboard.
-   **WG-50972** Object-Based metering is now supported in Mastering Suite.
-   **WG-51105** Spatial Audio: `[AK::SoundEngine::SetMultiplePositions](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_aec6be4dca0249557ea2680b755bd218a.html#aec6be4dca0249557ea2680b755bd218a)` is now fully supported by Spatial Audio emitters. Spatial Audio now computes diffraction, transmission, and reflection paths for each sound position.
-   **WG-51107** Spatial Audio: The transmission path is now shown in the Game Object 3D Viewer, along with the associated transmission loss, expressed as a percentage.
-   **WG-51236** Added Music Transition Filtering and added Work Units under Music Switch Containers
-   **WG-51261** Spatial Audio: The transmission loss value calculated for each connection on the wet path is now taken as the maximum of the upstream and downstream room. Previously, this value was taken as the maximum of the room upstream of the connection and that of the listener.
-   **WG-51277** Added column "Plug-in Name" to List View.
-   **WG-51315** (WAAPI) Added accessor "pluginName".
-   **WG-51347** Spatial Audio: An aperture value is now calculated for all sound paths passing through one or more portals. The aperture represents the smallest portal opening along the path, measured by the approximate solid angle subtended on the listener. The aperture restricts the maximum spread of a sound and can now be viewed in Obs/Occ tab of the Advanced Profiler.
-   **WG-51421** Spatial Audio: Improved the algorithm for portal spread calculation. The new algorithm is more efficient and prevents the spread from collapsing to 0 if the listener is 90 degrees off-axis of the portal.
-   **WG-51465** Spatial Audio: Added the new API `[AK::SpatialAudio::SetGameObjectRadius](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_spatial_audio_a8c2e8f50769b6ae29dcbcb636e9c33f2.html#a8c2e8f50769b6ae29dcbcb636e9c33f2)` to support radial sound sources.
-   **WG-51541** Spatial Audio: Added a new built-in Game Parameter for Transmission Loss.
-   **WG-51581** A warning icon is now issued in Mastering Suite anytime the plug-in is processing Object-Based audio in unlinked mode.
-   **WG-51650** Spatial Audio: The Portal transition region has been extended radially outwards from the corner of the portal opening, to provided full continuity when entering a portal from the side.
-   **WG-51677** Live plug-in monitoring data is now shown even when not capturing.
-   **WG-51772** Meter can now show the history of a profiling session that has been captured.
-   **WG-51879** Spatial Audio: Reverb and room tones now propagate between rooms that are connected only with a disabled portal, via their transmission path. A disabled portal can now be used to couple rooms together for the sole purpose of reverb transmission, when no diffraction path between the rooms is desired.

## API Changes

-   **WG-44180** (WAAPI) The Project object is now accessible by querying the root path '\\'. Querying the project's path now returns '\\'.
-   **WG-47068** (WAAPI) Accessors containing ":" character now also exist as an alias with no semicolon. Refer to `[ak.wwise.core.object.get](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_get.html)`.
-   **WG-47378** `[AK::IAkMixerPluginContext::Compute3DPositioning](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_i_ak_mixer_plugin_context_aa3aebb0cd836c0dcab14e3d862e13626.html#aa3aebb0cd836c0dcab14e3d862e13626)` now takes Spread and Focus values between 0 and 1.
-   **WG-47493** (WAAPI) Commands `ShowListView`, `ShowSchematicView`, and `Search` can now take a text value (i.e., a string) to search text in the project.
-   **WG-47651** Made the following changes:
    -   Changed functions `PostMIDIOnEvent` and `StopMIDIOnEvent` to support playing IDs. Also, added new `[AkMIDIEvent](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_m_i_d_i_event.html)` type, `AK_MIDI_EVENT_TYPE_WWISE_CMD`.
    -   `[AkSourcePosition](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_source_position.html "Return values for GetSourcePlayPositions.")` now has the member `updateBufferTick`, the value of `[GetBufferTick()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a8d4ce557eb5262a36140c26ccfb93fde.html#a8d4ce557eb5262a36140c26ccfb93fde)` at the time the position was updated.
    -   Added the function `[GetSampleTick()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ac688bf2d1ae6f2009e7cde602a753b6b.html#ac688bf2d1ae6f2009e7cde602a753b6b)`. This is equivalent to `[GetBufferTick()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a8d4ce557eb5262a36140c26ccfb93fde.html#a8d4ce557eb5262a36140c26ccfb93fde)` \* `[AkAudioSettings.uNumSamplesPerFrame](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_audio_settings_a2f27fe7b83e9c83ff7fc16b3160b669f.html#a2f27fe7b83e9c83ff7fc16b3160b669f "Number of samples per audio frame (256, 512, 1024 or 2048).")`.
-   **WG-48177** Added aligned realloc to the Memory Manager interface.
-   **WG-48344** Merged rpmalloc 1.4. Now using an rpmalloc first-class heap for media allocations to reduce cache overhead.
-   **WG-48570** Removed `AK_ALIGN_DMA, AK_ALIGN_FASTDMA` and `AK_ALIGN_SIZE_FOR_DMA` macros. Any usage of these can be removed as they have not been defined to anything for many years.
-   **WG-48746** Added new plug-in service `[AK::IAkMixerPluginContext::ComputePositioning](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_i_ak_mixer_plugin_context_a0d39528d0bf01ec4e08bc20956dfce2c.html#a0d39528d0bf01ec4e08bc20956dfce2c)` to compute panning gains.
-   **WG-49885** SpatialAudio API update: [AkPortalParams](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_portal_params.html "Parameters passed to SetPortal.") Extent type changed from [AkVector](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_vector.html "3D vector for some operations in 3D space. Typically intended only for localized calculations due to ...") of [AkExtent](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_extent.html), which has halfWidth, halfHeight, and halfDepth members. These should be set by the game according to its coordinate system.
-   **WG-50061** `[AK::IAkVoicePluginInfo](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_i_ak_voice_plugin_info.html "Voice-specific information available to plug-ins.")` does not inherit from `[AK::IAkGameObjectPluginInfo](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_i_ak_game_object_plugin_info.html "Game object information available to plugins.")` since busses are also associated to game objects. Pushed `IAkPluginContextBase::GetAudioNodeID()` to the base class `IAkPluginContextBase`, and removed the duplicate accessors, such as GetBusID.
-   **WG-50236** The Wwise Authoring Plug-in API has been rewritten for better separation of concerns and improved compatibility.
-   **WG-50501** Removed the unsupported `WritePascalString` and `WriteUtf16String` functions from the legacy plug-in API.
-   **WG-50872** (WAAPI) Renamed "skin" to "theme". Command `ReloadCurrentSkin` has been renamed to `ReloadCurrentTheme`.
-   **WG-51017** Moved some of the functions in `[AK::IAkGlobalPluginContext](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_i_ak_global_plugin_context.html)` for mixing (`MixChannel`, `Mix1inNChannels`, `MixNinNChannels`, `ApplyGain`, and `ApplyGainAndInterleave`) to a new interface, `[AK::IAkPluginServiceMixer](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_i_ak_plugin_service_mixer.html "Interface for the "Mixer" plug-in service, to handle mixing together of signals, or applying simple t...")`. You can fetch the interface by calling `[AK::IAkGlobalPluginContext::GetPluginService()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_i_ak_global_plugin_context_ac9cfbfdf2d01551973f6a2d2fa0bd79a.html#ac9cfbfdf2d01551973f6a2d2fa0bd79a)`, or using the `AK_GET_PLUGIN_SERVICE_MIXER` macro. Over time, other functions for signal processing will be added to this interface, as well as other "service" interfaces, to allow plug-in developers to leverage existing functionality inside of Wwise for Effects, including functionality that takes advantage of processor-specific enhancements.
-   **WG-51251** Breaking change! Simplified plug-in allocation interface `IAkPluginMemAlloc` by removing the "debug" versions of the functions. The memory debug functionality is now hidden in the plug-in host.
-   **WG-51622** Added timestamp to `NotifyMonitorData` for the plug-in API.
-   **WG-51809** (New Wwise Authoring Plug-in API) Removed byte swap flag from monitoring functions: little-endian is assumed.
-   **WG-52710** - Added emitterPos field to [AkDiffractionPathInfo](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_diffraction_path_info.html) for returning the position of the emitter used in this diffraction path when using the QueryDiffractionPaths API.
-   Added transmissionLoss field to [AkDiffractionPathInfo](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_diffraction_path_info.html) for returning information about the current transmission loss for an emitter when using the QueryDiffractionPaths API.
-   **WG-53241** Removed obsolete platforms from [PlatformID](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_platform_i_d.html) namespace.

## Behavior Changes

-   **WG-48027** In Spatial Audio, the spread calculation has been improved for the wet path going through portals.
-   **WG-48038** The distance used to compute spread and focus now corresponds to the real distance between the emitter and listener when the channel configuration of the output bus is fully 3D, that is, it has height channels, is ambisonics, or is Object-Based.
-   **WG-48178** [AkArray](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_ak_array.html "Specific implementation of array.") now uses aligned realloc.
-   **WG-48575** Out-of-memory message now additionally displays information concerning memory type.
-   **WG-50447** Added exclusive RTPC support to the predelay parameter in all Wwise reverb Effects, for initialisation of predelay before playback.
-   **WG-50776** Sound now propagates between Rooms that are only connected with disabled portals.
-   **WG-52087** Performance metrics are now reported at every frame.
-   **WG-53299** The behavior of the global callback location AkGlobalCallbackLocation\_PostMessagesProcessed has changed such that the callback is only executed once per buffer rendered. The callback is now executed when messages have been processed at any time between the current buffer and the previous buffer, where as previously it would potentially get executed multiple times per buffer rendered, if there were multiple batches of messages to process. The location of the callback has not changed.

## Performance Changes

-   **WG-47172** Improved performance of audio resampling algorithms, especially where AVX2 is available. Most notably, this should provide a 10% increase in throughput performance when playing back most Vorbis audio sources.
-   **WG-47544** Improved performance for Effects that utilize the Fast Fourier Transform (FFT) algorithm, especially on platforms where AVX2 is active and enabled. This delivers improvements, such as:
    -   Throughput performance of Convolution Reverb and Filter Effects improved by 1.3x-1.7x.
    -   Throughput performance of Harmonizer and Time Stretch Effects improved by 1.5x-1.75x.
-   **WG-51121** Advanced mode of the Mastering Suite's Limiter module has been optimized. The module is now 37% more efficient.
-   **WG-51334** Improved Spatial Audio monitoring data memory usage.
-   **WG-51775** Meter drawing has been optimized for better performance.

## Miscellaneous Changes

-   **WG-41575** Obstruction/Occlusion Data and SoundBank Data are now enabled by default in the Profiler Settings.
-   **WG-45796** Moved the Make-Up Gain property from Source Settings to General Settings.
-   **WG-47656** Added new 3D Audio Objects demo page in IntegrationDemo.
-   **WG-48720** Removed support for migration of Wwise Projects from versions earlier than 2013.1. It remains possible to migrate such projects to 2021.1 by first migrating to 2019.2.
-   **WG-50376** Separated acoustic texture factory assets from Reflect.
-   **WG-50769** Can now import 192 kHz audio files.
-   **WG-51039** Updated the Details panel in the Unreal Editor for AkSpatialAudioVolume. Changes to surface reflectors can now be made for multiple faces across multiple Spatial Audio Volumes.
-   **WG-51169** The Mastering Suite Effect is now inserted on an Audio Device instead of the Master Audio Bus.
-   **WG-51546** Moved the Room Extent Opacity slider to the Spatial Audio Debug section in the Game Object 3D Viewer Settings.

## Bug Fixes

-   **WG-41982** Fixed: (Windows Authoring) Crash dumps display incorrect OS version number.
-   **WG-43214** Fixed: SoundBanks cannot be generated at the root of a drive when authoring on Windows.
-   **WG-44531** Fixed: Wwise Wave Viewer keeps a lock on the file.
-   **WG-45632** Fixed: The user could move secondary playheads in the Source Editor while paused.
-   **WG-46046** Fixed: Visual glitch in the rulers of Game Sync Monitor and Voices Monitor when scrolling.
-   **WG-46286** Fixed: WwiseConsole.exe does not provide feedback during move-media-ids-to-single-file and move-media-ids-to-work-units operations.
-   **WG-46388** Fixed: A non-required dependency forcing to link with Commcentral.lib when profiling while not using it.
-   **WG-46564** Fixed: For plug-ins with multiple media items, media modification does not have an immediate effect.
-   **WG-47257** Fixed: Visual glitch on **OK** and **Cancel** buttons when creating a new project with an invalid name.
-   **WG-47312** Fixed: The menu Copy Short ID(s) to Clipboard appears even when no short ID is available.
-   **WG-48209** Fixed: The Project Explorer window can't be clicked on in some areas.
-   **WG-48719** Fixed: Room Tone wet path occlusion is applied twice when listener is in another closed off room.
-   **WG-48757** Fixed: Pressing the space bar does not trigger playback when the keyboard focus is on a check box inside a list.
-   **WG-48798** Fixed: Property Editor's title bar does not reflect currently selected object.
-   **WG-49197** Fixed: The folder path in the File Manager dialog is occasionally missing or misaligned.
-   **WG-49720** Fixed: Property Editor keyboard shortcuts (CTRL+1, CTRL+2, etc.) to switch tabs are not working.
-   **WG-49807** Fixed: Changing ShareSets in the Mastering Suite during playback produces audible artifacts.
-   **WG-50027** Fixed: (WAAPI) The commands OpenContainingFolderWorkUnit, OpenContainingFolderWAV, and OpenContainingFolderSoundbank fail when executed from WAAPI.
-   **WG-50155** Fixed: Crash when not setting any output parameter when overriding GetDialog in the Plug-in API 1.0 and 2.0.
-   **WG-50227** Fixed: Unexpected slider dragging behavior on High DPI with multiple monitors.
-   **WG-50337** Fixed: Meter display only works during a capture session for busses in the Master-Mixer Hierarchy.
-   **WG-50432** Fixed: Mute and solo filtering doesn't work in the Game Sync Monitor when muting a game object.
-   **WG-50668** Fixed: Some temporary files are not cleaned properly in Vorbis conversion.
-   **WG-50702** Fixed: Wave Viewer not displayed well on a High DPI display.
-   **WG-50906** Fixed: The game object scaling factor is applied twice when the game object is both the emitter and listener.
-   **WG-51726** Fixed: The color selector disappears when it's near the edge of the screen.
-   **WG-52515** Fixed issues with WAAPI asset synchronization when moving nested folders of Wwise objects.
-   **WG-52517** Fixed: The All Properties tab does not update correctly when the platform is changed.
-   **WG-52754** Fixed: Rare crash in Sound Engine, AkTransitionManager::ProcessTransitionList.
-   **WG-52896** Fixed: Obstruction is applied to the output of a Auxiliary Bus used as an early reflections bus. This is undesirable because each reflection (image source) is evaluated individually in Spatial Audio, and each may or may not be individually obstructed.
-   **WG-53142** Fixed: AkMemSettings::uMemAllocationSizeLimit can be exceeded with device memory.
-   **WG-53325** Fixed: Custom attachment mixer plug-in GUI is incorrectly sized.

-   **WG-47156** Fixed: Deadlock on prepare request.
-   **WG-48504** Fixed: Some Wwise threads don't call `[AK::MemoryMgr::InitForThread](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_memory_mgr_a76b450a2f472f5d9bc61aa1c3ed9a722.html#a76b450a2f472f5d9bc61aa1c3ed9a722)` when started.
-   **WG-49195** Fixed: Possible crash when executing pre or post generation steps during SoundBank generation.
-   **WG-51912** Fixed: The severity of Audio File Conversion errors cannot be changed.
-   **WG-52764** Fixed: Potential crash when using the main menu.
-   **WG-53081** Fixed: Unknown Game Object ID reported when ending Unreal game with Portal closed.

See also

-   [New Features Overview 2021.1](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_new_features.html)
-   [Important Migration Notes 2021.1](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_migration.html)

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#new_features)
-   [API Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#api_changes)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#behavior_changes)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#performance_changes)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#miscellaneous_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1.html#fixes_for_community-reported_bugs)

_menu_