_menu_

-   __ Wwise
    
-   __ Certified Partner Plug-ins
    
-   __ Wwise Samples
    

Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

The following sections list and describe the changes to Wwise between version 2021.1.10 and version 2022.1.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#generic_feature_changes_2022_1)
-   [API Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#generic_api_changes_2022_1)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#generic_behavior_changes_2022_1)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#generic_perf_changes_2022_1)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#generic_misc_2022_1)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#generic_bugs_2022_1)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#generic_community_bugs_2022_1)

## New Features

-   **WG-21449** Added the `AK::SpatialAudio::SetDistanceProbe` API. For additional flexibility in third-person perspective games, it is now possible to have sounds attenuate based on the distance to a separate Game Object, while maintaining panning and spatialization relative to the Listener Game Object.
-   **WG-32283** (WAAPI) Added convertExternalSource which allows for the conversion of audio files external to the Wwise project according to the settings specified in a wsources file.
-   **WG-32577** (WAAPI) Added query functions getSwitch and getState. getSwitch returns information about the current state of a Switch Group for a given game object, and getState returns information about the current state of a State Group.
-   **WG-38235** (WAAPI) RTPCs can now be set in WAAPI using [ak.wwise.core.object.set](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_set.html).
-   **WG-39514** (WAAPI) Source and Effect plug-ins can now be created or set using [ak.wwise.core.object.set](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_set.html).
-   **WG-42569** (WAAPI) Added remote procedure call [ak.wwise.core.transport.prepare](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_transport_prepare.html) to load an object into the sound engine without playing it.
-   **WG-45413** Added Random Number Generator service to `[AK::IAkGlobalPluginContext](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_i_ak_global_plugin_context.html)`.
-   **WG-49287** Updates to the Time Stretch Effect:
    -   Added a new Transient Preserving Stretch Mode, an accompanying Quality Level slider, and a Stereo Processing mode.
    -   Added pitch shift functionality to both modes, with a Pitch Shift slider and randomization parameter.
-   **WG-50451** (WAAPI) Added the possibility to obtain the Mute and Solo states with isExplicitSolo, isExplicitMute, isImplicitMute, isImplicitSolo.
-   **WG-51539** Added the Audio Devices tab to the Advanced Profiler view, which lists all of the Audio Devices that are currently active in the sound engine.
-   **WG-52323** (WAAPI) Added function processSounbankDefinitions which allows importing SoundBank Defintion files.
-   **WG-52461** Added new Filter Behavior option to Project Settings. Voice low-pass and high-pass filter property values can now be combined in either of two ways:
    -   Sum all values (default, classic behavior)
    -   Use highest value (new, non-additive behavior)
-   **WG-52686** (WAAPI) Added an optional argument to Mute and Solo commands to specify the state.
-   **WG-52767** Reflect now offers a new simplified mode, where it uses each sound's attenuation curves to attenuate the sound's early reflections. The assumption is that the early reflections of a sound should be attenuated according to the same curves applied to the sound itself. The mode is called "simplified" because the user only needs to associate a sound with a simplified early reflection auxiliary bus to automatically have a reasonable design for the sound's early reflections. Moreover, since each sound can have its own unique attenuation, the same Reflect Effect ShareSet can attenuate the early reflection sounds of multiple sources differently. To allow some customization of the sound's attenuation curves in Reflect, two new properties have been introduced: distance and diffraction warping. These properties let you emphasize or de-emphasize the effect of distance and diffraction, respectively, on the sounds coming from image sources. If you want to further customize the Reflect curves, you still have the option of applying a custom curve, like before.
-   **WG-52979** (Spatial Audio) Colinear edges are now merged into a single diffraction edge to reduce the cost of processing multiple edges.
-   **WG-53001** Spatial Audio reflection path discovery is now more robust, and is able to discover more reflection paths with a lower number of primary rays.
-   **WG-53597** Saved Profiler capture sessions can now be opened by dragging and dropping the PROF file over the Capture Log view.
-   **WG-53796** (WAAPI) Added [ak.wwise.core.object.set](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_set.html) to set properties and create objects in a batch.
-   **WG-53899** Error reporting in the debug console, or any other logging mechanism, can now have all numerical identifiers translated into human-readable names and labels. This is accomplished by reading the Soundbanks.xml file or through a WAAPI connection to the Wwise project. See the `[AK::Monitor::AddTranslator](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_monitor_a2316d98b14d17cd1b14a27f63edc357e.html#a2316d98b14d17cd1b14a27f63edc357e)` function, and [AkXMLErrorMessageTranslator](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_ak_x_m_l_error_message_translator.html) and AkWAAPIErrorMessageTranslator classes for more information. Large projects could experience a lag when errors occur, in which case either XML and/or WAAPI translators can be disabled. Both translators have timeout parameters to limit the amount of time spent searching for the identifiers.
-   **WG-54118** It's now possible to spread the computation and validation of spatial audio paths over several frames preventing peaks in CPU usage.
-   **WG-54310** Added an auto-defined SoundBanks option. When enabled, Wwise automatically defines SoundBanks for each Event and Aux Bus, where possible. Refer to [Automatically Defining SoundBanks](https://www.audiokinetic.com/library/edge/?source=Help&id=auto_defining_soundbank) for more details.

Auto-defined SoundBanks are enabled via the SoundBank Settings. Refer to [SoundBank Settings](https://www.audiokinetic.com/library/edge/?source=Help&id=project_settings_soundbanks_tab) for more details.

# New Features

-   **WG-54420** Font size changes are now applied when clicking the OK button of the User Preferences dialog box.
-   **WG-54953** Added support for metering of Loudness and True Peak values on busses performing Audio Object processing.
-   **WG-55073** Game Sync Monitor now displays RTPC values on all properties, for all RTPC scopes (game object, playing ID, and MIDI), whether the RTPC is associated with any currently playing voices or not.
-   **WG-55094** Where a qualified object name can be specified in a WAAPI function or WAQL query, it's now also possible to specify a global Short ID using the form "Global:123456".
-   **WG-55349** The Metering Bar of the Effect Settings view now lists objects with the effect inserted at runtime. This enables profiling of Mastering Suite ShareSets assigned programmatically.
-   **WG-55428** Added the "verify" operation to WwiseConsole, which makes it possible to load a project without saving or migrating in order to verify the load log. This was possible in WwiseCLI but was missing from WwiseConsole.
-   **WG-55757** Attenuation ShareSets offer new Obstruction, Occlusion, Diffraction, and Transmission curves. They can be disabled or customized per sound.
-   **WG-56146** It's now possible to exclude a string from a search in the Project Explorer, List View, and Schematic View using an exclamation mark or minus sign. For example, this search will look for any object that contains the word "boy" but without the word "running": boy -running
-   **WG-56344** Automatic update of source control for generated files on SoundBank generation. Refer to [SoundBank Settings](https://www.audiokinetic.com/library/edge/?source=Help&id=project_settings_soundbanks_tab) for more details. Files updated in source control are:
    -   Generated SoundBank (.bnk) files.
    -   SoundBank metadata files (.xml and/or .json).
    -   Copied media files.
-   **WG-56567** External hooks for CPU profiling in the sound engine are now available, so that platform-specific profiling tools, or other applications, can be used to better understand the CPU usage of the sound engine:
    -   `[AkInitSettings::fnProfilerPushTimer](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_init_settings_a71783c4575cbf9410ecd8c7c5703c8d2.html#a71783c4575cbf9410ecd8c7c5703c8d2 "External (optional) function for tracking performance of the sound engine that is called when a timer...")`
    -   `[AkInitSettings::fnProfilerPopTimer](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_init_settings_a3d1f3008d52cdc3ead4e7497386e9dd7.html#a3d1f3008d52cdc3ead4e7497386e9dd7 "External (optional) function for tracking performance of the sound engine that is called when a timer...")`
    -   `[AkInitSettings::fnProfilerPostMarker](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_init_settings_afee08f27130b3fdf479d15fb06f15b12.html#afee08f27130b3fdf479d15fb06f15b12 "External (optional) function for tracking significant events in the sound engine, to act as a marker ...")`
-   **WG-56797** It's now possible to press Shift while dragging an object into the Schematic View to select additional objects.
-   **WG-56896** The Game Sync Monitor now shows Switch Groups and Switch values.
-   **WG-57049** It's now possible to use the "dot" syntax in WAQL and in WAAPI return option to access members of a returned JSON object directly. For example, you can use the WAQL keyword "where" directly on maxDurationSource.trimmedDuration, maxRadiusAttenuation.radius, and other similar cases.
-   **WG-57075** Removed the SoundBank generation tool CopyStreamedFiles.exe. The functionality has been replaced by the new SoundBank setting Copy Loose/Streamed Media. Refer to [SoundBank Settings](https://www.audiokinetic.com/library/edge/?source=Help&id=project_settings_soundbanks_tab) for more details.
-   **WG-57189** (Spatial Audio) It is now possible to use `[AK::SpatialAudio::SetImageSource](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_spatial_audio_aab4d85317c62724c00d25ba8913fb503.html#aab4d85317c62724c00d25ba8913fb503)` with the Early Reflections Auxiliary Bus assigned in the Wwise Authoring Tool, by passing AK\_INVALID\_AUX\_ID. The `[AK::SpatialAudio::SetImageSource](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_spatial_audio_aab4d85317c62724c00d25ba8913fb503.html#aab4d85317c62724c00d25ba8913fb503)` API no longer accepts a room argument. Filtering image sources so that only those with a room that matches the emitter and listener's room limits the usability of the feature. The user should add and remove image sources from game-side logic to provide the desired behavior.
-   **WG-57192** Spot reflectors (from the SetImageSource API) are now visible in the Game Object 3D Viewer.
-   **WG-57261** Added Set Effect Event action, which makes it possible to override Effects at runtime.
-   **WG-57299** Simplified the Transport Control and made it more compact. **Original** and **Inc. Only** are now accessed through the transport play options button to the right of the Play button. The Reset button is now highlighted when properties are changed by an event like mute or a volume change.
-   **WG-57551** Portals in the Game Object 3D Viewer now display their associated front and back room ID and names.
-   **WG-57870** Wwise Spatial Audio, along with the Wwise Sound Engine, now supports large world coordinates. All world positions are passed to Wwise using 64-bit floating-point numbers. Geometry is now passed to Spatial Audio with vertex positions relative to a local coordinate space. To convert between world space and the local space of the geometry, a Geometry Instance is created that defines a transformation. It is possible to create many instances of the same Geometry Set, which can be used to reduce data passed to Wwise and memory usage.
-   **WG-57936** SoundBank generation metadata files have been overhauled:
    -   New metadata file for global project information: ProjectInfo.(xml,json)
    -   New metadata file for platform-specific information: PlatformInfo.(xml,json)
    -   Extensive changes to the syntax of the contents of the all-bank SoundBankInfo.(xml,json) and per-bank metadata files.
    -   To reduce the size of metadata files, some common information has been moved from the all-bank and per-bank metadata files to the project and platform metadata files.
-   **WG-57940** Renamed the Property Help view to Contextual Help view and added it to the Profiler layout. In addition to providing details on selected properties, this view now provides details on any error selected in the Capture Log.
-   **WG-57983** Added new setting `[AkSpatialAudioInitSettings::uDiffractionOnReflectionsOrder](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_spatial_audio_init_settings_a245b315e0cca157bdbef7cde581e8561.html#a245b315e0cca157bdbef7cde581e8561)`, which replaces bEnableDiffractionOnReflections. Previously, if set to true, only one diffraction on reflection paths was computed. Now, the number of diffraction points is customizable.  
    
-   **WG-58052** Added the ability to change the Block Size property in the AK Convolution Reverb Effect Editor, previously locked to a value of 1024. This allows for a tradeoff between audio signal latency and amortized performance of the Effect. More information is available in the [AK Convolution](https://www.audiokinetic.com/library/edge/?source=Help&id=wwise_convolution_reverb_plug_in) documentation.
-   **WG-58078** Added new function [ak.wwise.core.getProjectInfo](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_getprojectinfo.html) to retrieve information about the current project.
-   **WG-58433** Added the new 3D Audio Bed Mixer plug-in, which can be used to control the number of Audio Objects passing through a bus.
-   **WG-58682** Added new SoundBank settings to manage the output folder. Refer to [SoundBank Settings](https://www.audiokinetic.com/library/edge/?source=Help&id=project_settings_soundbanks_tab) for more details.
    -   Copy Loose/Streamed Media: Copies required media files from the .cache folder to the output folder.
    -   Remove Unused Generated Files: Removes previously generated/copied files that are no longer required.
    -   Use Source Control for Generated Files: Updates source control for operations performed on the output folder.
-   **WG-58751** Replaced the Smooth Distance column in Reflect's Effect Editor with a Delay column.
-   **WG-59217** Added a new Infinite Hold option to the Meter Effect Editor. It allows indefinite holding of the output value, which can be useful in side-chaining scenarios in combination with Pausing the game.
-   **WG-59491** New 3D Audio Bed Mixer plug-in helps control the number of Audio Objects passing through a bus.
-   **WG-59606** It's now possible to have sound traverse a path into a room and then loop back into the listener's room though a different portal.
-   **WG-60494** A new performance bookmark is now reported via `[AkInitSettings::fnProfilerPostMarker](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_init_settings_afee08f27130b3fdf479d15fb06f15b12.html#afee08f27130b3fdf479d15fb06f15b12 "External (optional) function for tracking significant events in the sound engine, to act as a marker ...")` indicating when "Voice Starvation" events on the device have been detected by the sound engine.
-   **WG-60679** SoundBank generation: Added information communicated to users in generation log for debugging purposes.
-   **WG-61081** It's now possible to define Channel Mixdown settings in AK Convolution Reverb Effects with platform links instead of having to create separate ShareSets. For example, you can specify a monaural mixdown of an impulse response on one platform and a stereo mixdown for other platforms that have more robust CPU and memory resources.

## API Changes

-   **WG-52324** (WAAPI) Added topics ak.wwise.core.profiler.stateChanged and ak.wwise.core.profiler.switchChanged to allow subscription to notifications about changes of State Groups and Switch Groups.
-   **WG-55694** (WAAPI) Added [ak.wwise.core.sound.setActiveSource](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_sound_setactivesource.html) function and activeSource accessor.
-   **WG-55975** Functions for controlling AkSemaphores, such as AkCreateSemaphore, now accept AkSemaphore& as their parameter, not AkSemaphore\*.
-   **WG-56507** TryUnsetMedia now issues an asynchronous stop command, and marks media as unavailable, to guarantee that repeat calls to TryUnsetMedia will eventually succeed.
-   **WG-56825** Plug-in API and callbacks: converted `AK::IAkMetering` interface to a plain struct `[AK::AkMetering](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_a_k_1_1_ak_metering.html "Struct containing metering information about a buffer. Depending on when this struct is generated,...")`.
-   **WG-57085** Samples Library: `CAkFileHelpers::CloseFile` now accepts [AkFileDesc](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_file_desc.html) as an input parameter on all platforms, not an AkFileHandle.
-   **WG-57285** Added new commands to `AK::ISourceControl::PluginInfo` to support more operations without a user interface. The new commands are used when updating output files (generated SoundBank and copied media files) under source control.
-   **WG-57835** New argument is required in deprecated Mixer Plug-in API `IAkMixerInputContext::GetInputParam()` to allow the use of metadata plug-ins on Wwise objects routed to a mixer plug-in.
-   **WG-58049** The Wwise sound engine now supports large world coordinates for game objects by moving to double-precision values for positioning. This allows the positioning of sounds to behave predictably, even with worlds that are billions of units in size. APIs dealing with game object positions have been updated to use two new types, [AkWorldTransform](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_world_transform.html "Position and orientation of game objects in the world (i.e. supports 64-bit-precision position)") and [AkVector64](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_vector64.html "3D 64-bit vector. Intended as storage for world positions of sounds and objects, benefiting from 64-b..."), which provide the additional data. This also includes changing the typedefs for AkSoundPosition and AkListenerPosition from [AkTransform](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_transform.html "Position and orientation of objects in a "local" space.") to [AkWorldTransform](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_world_transform.html "Position and orientation of game objects in the world (i.e. supports 64-bit-precision position)"). For more information, refer to [Large World Coordinates for Game Objects](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_migration.html#large_world_coordinates_for_game_objects) in the migration notes.
-   **WG-58395** Added `AkMemSettings::bUseDeviceMemAlways` initialization parameter to reduce memory usage on certain platforms by instantiating only a single heap for both device and non-device memory, instead of separate heaps for the two.
-   **WG-58561** `[AK::Wwise::SourceControlContainers::IAkList](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_wwise_1_1_source_control_containers_1_1_i_ak_list.html)` now manages a single AkPos instance at a time. This means that methods returning an AkPos instance now invalidate any previously obtained AkPos, and such methods must no longer be called while iterating the list. Refer to the in-code SDK documentation for more details.
-   **WG-59164** Removed `AkCommSettings::uNotification` initialization parameter: there is now only one dynamic port for communication with Wwise Authoring.
-   **WG-59243** (WAAPI) Reworked content and format of information returned by function [ak.wwise.core.soundbank.generated](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_soundbank_generated.html).
-   **WG-59258** Made the function `[AK::Wwise::Plugin::IProgress::IsCancelled](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_wwise_1_1_plugin_1_1_i_progress_a17958067a0608c0bbd4fc1556b7f8767.html#a17958067a0608c0bbd4fc1556b7f8767 "Check if the user has cancelled the task.")` const.
-   **WG-59775** (WAAPI) Added new error URI `ak.wwise.unknown_class_id`. More details are now provided in errors ak.wwise.invalid\_language, ak.wwise.unknown\_language, ak.wwise.unknown\_platform, and ak.wwise.invalid\_type.
-   **WG-60226** The functions on IAkPluginServiceRNG to fetch the seed value used by the sound engine's random number generator now also advance the seed value.

## Behavior Changes

-   **WG-47808** Mouse wheel zoom and scroll modifiers have changed for ease of use. Most graphics-based views, like the RTPC editor, Music Segment Editor, and Source Editor, have the following new mouse wheel behavior. Note, when the mouse is over the vertical axis, all inputs affect the opposite plane. For example, Ctrl+Mouse wheel results in a vertical zoom instead of horizontal.
    -   Mouse wheel: Horizontal scroll
    -   Ctrl+Mouse wheel: Horizontal zoom
    -   Shift+Mouse wheel: Vertical scroll
    -   Ctrl+Shift+Mouse wheel: Vertical zoom
-   **WG-52328** (WAAPI) Added topics ak.wwise.core.profiler.gameObjectRegistered, ak.wwise.core.profiler.gameObjectUnregistered, and ak.wwise.core.profiler.gameObjectReset to allow subscription to notifications about the state of game objects.
-   **WG-52778** Mute and Solo buttons now use non-bold text icons so the implicitly muted/soloed modes are easier to identify.
-   **WG-53884** The monitoring queue no longer drops monitoring messages when it's full. Instead, the queue waits for the reader to make room for new messages. This may lead to some voice starvation when profiling. Voice starvation is more likely to occur during the startup of the Profiler and if many data types are selected in the Profiler Settings.
-   **WG-54026** The command "Profiler/Set Keyboard Focus to Text Filter" has been removed. It has been replaced by the more general "View/Search in Current View", which serves the same purpose. In addition to the Profiler views, this new command supports Text Filter in RTPC and Attenuation tabs. It also works in the Project Explorer, List View, and Schematic View.
-   **WG-54052** In the List View and Schematic View, selecting **Show in List View**/**Show in Schematic View** in the shortcut menu of objects, now creates a WAQL query for those objects in the Search field. It is also now possible to drag and drop objects from the List View or Schematic View onto the Search field to search for those objects only as a WAQL query.
-   **WG-54205** The new color of an unloaded Work Unit was not being saved. To avoid this issue, the SetColor command is now disabled on unloaded Work Units.
-   **WG-54703** Common Multi Editor properties, such as Color and Inclusion, are now in a Common group. Voice properties and Bus properties are now inside their own respective groups.
-   **WG-54820** When a WAAPI [ak.wwise.core.object.create](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_create.html) operation fails, all changes made to the project during its execution will be reverted.
-   **WG-55850** Sounds that end with a low-pass filter active no longer have audio glitches, or discontinuities, that could result from the low-pass filter's tail.
-   **WG-56382** It is now possible to run a command using a keyboard shortcut when the cursor is in an edit field (for example, a search field). Note that commands involving editing control keys, such as Left arrow and Insert, will not be executed: key mapping priority will still be given to the editing capabilities.
-   **WG-56404** Obstruction and diffraction can now be applied on top of each other, instead of one at a time.
-   **WG-56612** Selecting **Show in List View** in the shortcut menu of an object now brings keyboard focus to the Search field in the List View when it opens.
-   **WG-56816** Editing in text and numeric fields is now more consistent. Bringing the keyboard focus to a field automatically selects the text in the field. You can enter or exit Editing mode in a field by pressing Enter. The Notes field is exited by pressing Ctrl+Enter.
-   **WG-57307** Meter plug-in output value calculation has been modified. In Peak mode, the peak value across all channels is now consistently used. In RMS mode, the results are now more consistent across channel configurations for a given source signal. The level difference might affect the mix of existing projects when using the Meter for side-chaining.
-   **WG-57355** Plug-in DataWriter’s WriteString function no longer adds 4 bytes at the end of the string.
-   **WG-57394** Balance-Fade Speaker Panning loudness now matches that of Direct Assignment, which means it is louder than before for sounds with a channel count larger than 1. Refer to [Loudness Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_migration.html#loudness_changes_2022_1) for more details.
-   **WG-57686** Multiple Control Surface Binding views can now be open at the same time. And you can now activate/deactivate Control Surface Sessions from these views and deactivate them from the Control Surface Toolbar.
-   **WG-57857** Compressor and Expander gain reduction value calculation has been modified: the results are now more consistent across channel configurations for a given source signal. The level difference might affect the mix of existing projects.
-   **WG-58042** Source control status is now shown in the File Manager for source files and generated files.
-   **WG-58603** (Spatial Audio) Diffraction paths that exceed 100% diffraction, or paths that exceed the maximum attenuation distance of all currently playing sounds, are no longer passed to the sound engine for rendering. Furthermore, they are no longer displayed in the Game Object 3D Viewer, unless a debug display option is enabled. Note that both distance attenuation and diffraction curves are expected to be designed so that they taper to an inaudible level to prevent discontinuities.
-   **WG-58711** When executing a command (for example, Show in List View) when the Multi Editor is the current view and contains multiple objects, the command now uses the objects contained in the Multi Editor.
-   **WG-60241** Mouse wheel zoom and scroll modifiers have changed for ease of use. The Mixing Desk now has the following behavior:
    -   Mouse wheel: Vertical scroll
    -   Ctrl+Mouse wheel: Horizontal zoom
    -   Shift+MouseWheel: Horizontal scroll
-   **WG-60288** (Spatial Audio) Removed usage of `AK::SpatialAudio::String` from the Spatial Audio API and replaced it with standard c-strings to prevent memory allocation inside the Sound Engine from external code. Furthermore, the strings have been removed from the [AkRoomParams](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_room_params.html "Parameters passed to SetRoom.") and [AkPortalParams](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_portal_params.html "Parameters passed to SetPortal.") structs in favor of passing them directly into their respective functions. This eliminates the need for constructor, copy, and destructor methods in the parameter structs and simplifies client code.
-   **WG-60440** Changed the default value of `[AkInitSettings::uNumSamplesPerFrame](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_init_settings_a2438a18ece872c83175f70d7f70d659b.html#a2438a18ece872c83175f70d7f70d659b "Number of samples per audio frame (256, 512, 1024, or 2048).")` to 512 on all platforms. This increases out-of-the-box CPU usage in Wwise slightly but significantly reduces the total audio latency in the sound engine. It is still recommended to tune "Samples Per Frame" and "Number of Refills In Voice" to balance your game's total audio latency against the available computing resources.
-   **WG-60762** (Spatial Audio) Early reflection volume set using `[AK::SpatialAudio::SetEarlyReflectionsVolume](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_spatial_audio_a691784b217ba9ccd30e6513dedb924e6.html#a691784b217ba9ccd30e6513dedb924e6)` now applies to image sources set using `[AK::SpatialAudio::SetImageSource](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_spatial_audio_aab4d85317c62724c00d25ba8913fb503.html#aab4d85317c62724c00d25ba8913fb503)` as well as reflections calculated from geometry.
-   **WG-60985** The units of the Time To First Reflection variable are changed from seconds to milliseconds. Game Parameters previously mapped to this variable must now range over units of milliseconds instead of seconds.
-   **WG-61126** Improved Crankcase Audio REV 2 ADPCM Decoder to remove a hiss from low amplitude samples.
-   **WG-61755** Event Actions can no longer modify Effect bypasses on objects that do not specify Effects. An object specifies Effects if it has no parent object or it explicitly overrides the Effect list.

## Performance Changes

-   **WG-47020** Significantly improved performance when applying LPF and HPF effects on voices and on mix-connections to busses. Depending on the CPU architecture and number of voices being processed, throughput performance of LPF and HPF Effects has improved by a factor of 1.5-5.0x. High-end ARM CPUs and x86 CPUs leveraging AVX2 instructions are expected to see the most significant improvements.
-   **WG-53573** Significantly improved runtime performance when a very large number of RTPCs or Switches are in use at the same time in the game and used to drive multiple structures.
-   **WG-55298** Improved performance of Meter plug-in when in Peak mode by approximately 4x for channel-based Effects.
-   **WG-57259** Improved performance of Clear Audio File Cache.
-   **WG-58106** Reduced number of short-lived memory allocations incurred by `AkPipelineBufferBase::GetCachedBuffer` by keeping buffers allocated for more than one frame at a time.
-   **WG-59293** Disabled reflection ray casting when `[AkSpatialAudioInitSettings::uMaxReflectionOrder](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_spatial_audio_init_settings_a346377be1b9f6905fb2d8d3e1540eb39.html#a346377be1b9f6905fb2d8d3e1540eb39 "Maximum reflection order [1, 4] - the number of 'bounces' in a reflection path. A high reflection ord...")` is set to 0.
-   **WG-60536** Improved performance of 3d panning on speaker configurations with height channels.
-   **WG-60982** Improved performance of Time Stretch in Classic mode when not actually stretching.
-   **WG-61053** Significantly reduced CPU overhead of the sound engine runtime and `[AK::Monitor](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_monitor.html)` thread when the Wwise Profiler is connected and some Profiler Settings, such as Voice Inspector Data, are active. This should greatly improve the accuracy of the CPU measurements reported in Wwise.

## Miscellaneous Changes

-   **WG-42520** Increased the font size used in the Mixing Desk. It now matches the size used in other views.
-   **WG-43348** Rearranged the Attenuation Editor to match the layout of the RTPC tab in the Property Editor. The locations of the list and graph view have been swapped and new splitters let you manage the space.
-   **WG-44906** Reorganized the Project menu so project-based items are in one section and user settings are in another. Recently opened projects are now found in an Open Recent submenu, just below the Open menu item.
-   **WG-46458** The References button now displays a different colored icon for 0, 1, and more than one reference. This makes it easy to identify when a ShareSet is used by many objects and caution is needed.
-   **WG-53565** Removed Visual Studio 2015 distribution of the libraries.
-   **WG-54749** Updated rpmalloc to version 1.4.3.
-   **WG-54761** Renamed the Default User Settings dialog box to Default Object Values to better reflect its functionality.
-   **WG-54854** (Mac Authoring) Moved the Contextual Help indicator to the left of the Log indicator in the Wwise toolbar.
-   **WG-55196** Renamed the ShowUserProjectSettings WAAPI command to ShowDefaultObjectValues. And renamed the Show User Project Settings keyboard shortcut command to Show Default Object Values.
-   **WG-55385** Removed SoundFrame. Refer to [Using the Wwise Authoring API (WAAPI)](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=waapi.html) to learn more about the Wwise Authoring API (WAAPI), which replaces SoundFrame.
-   **WG-55853** Minor changes to structures in [AK\\Tools\\Common\\AkVectors.h](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=AkVectors.h):
    -   Return reference from assignment operators.
    -   Add const to member functions that do not modify the object.
    -   Return reference instead of const-reference from Normalize() functions.
-   **WG-56251** Adjusted usage of thread-local storage so that the sound engine no longer consumes TLS slots, or other platform-specific equivalents such as pthread\_key.
-   **WG-57475** Added WAQL examples in the Project template used when creating new projects.
-   **WG-57497** Removed the Wwise SoundSeed Impact Effect plug-in. Consider replacing it with the [Impacter](https://www.audiokinetic.com/library/edge/?source=Help&id=impacter_plug_in_source) source plug-in.
-   **WG-57578** The Wwise Level 3 Source Code (L3) build now treats warnings as errors.
-   **WG-58130** Various performance enhancements have been made to Source Control handling to make the usage of the File Manager smoother. The containers used by the Source Control API have been optimized and work is now batched to maximize throughput.
-   **WG-58202** AkVariant is no longer using deprecated std::codecvt helpers.
-   **WG-58232** (WAAPI) Removed "log" property from the directories result object returned by the [ak.wwise.core.getInfo](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_getinfo.html) function.
-   **WG-58779** Improved memory efficiency of filesystem path representation.
-   **WG-58921** Only reload Source Control icons from the File Manager when an operation was performed.
-   **WG-59903** Added support for Authoring plug-ins built with Windows Common Runtime Language.
-   **WG-59935** Corrected copyright year in all source code files and remove the dynamic build and version numbers. When debugging Wwise sound engine code in Visual Studio, it no longer reports that source files are different when the files are actually the same.
-   **WG-59996** Increased minimum version of Python for WAAPI and wp.py to 3.7. Python 2 is no longer officially supported.
-   **WG-61085** Updated Unity Addressables package dependency to 1.18.19.
-   **WG-62612** The Wwise Authoring application now provides hints to the system to use the high performance graphics mode for AMD and Nvidia GPUs.

## Bug Fixes

-   **WG-47645** Fixed: Up and down arrow keys don't change row selection properly if the user didn't select the current row by choosing the first cell. Up and down arrow keys can now move focus up and down between fields in a list when in edit mode. The Enter key can now be used to both enter and exit editing mode.
-   **WG-48738** Fixed: Time Stretch plug-in reduces amplitude of initial transient.
-   **WG-49144** Fixed: Crash when Source Control plug-in submits an invalid argument to user preferences.
-   **WG-52204** Fixed: Title of Audio File Conversion dialog box is cropped.
-   **WG-52631** Fixed: Log message is shown when changing modes in Profiler Statistics view.
-   **WG-52675** Fixed: Wwise menu bar is available during a project load, which could lead to a crash.
-   **WG-54476** Fixed: Keyboard shortcut conflicts are not always reported correctly.
-   **WG-54546** Fixed: Possible crash when deleting or unlinking a Blend Container's children.
-   **WG-54817** Fixed: Precision errors can occur in automated positioning when the sound engine has been running for several hours or more.
-   **WG-55005** Fixed: Out-of-range State values are not reported nor fixed on project load.
-   **WG-55028** Fixed: Possible crash when a game is loading a SoundBank while connecting to Wwise.
-   **WG-55439** Fixed: Issue monitoring game objects with more than 255 positions.
-   **WG-55466** Fixed: (WAAPI) Header generation scripts are not compatible with Python 3.
-   **WG-55505** Fixed: (Spatial Audio) Portal obstruction isn't consistently displayed when **Show Portal Info Text** is enabled in the Game Object 3D Viewer Settings.
-   **WG-55559** Fixed: Plug-in's `[AK::Wwise::Plugin::CustomData::InitFromWorkunit()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_a_k_1_1_wwise_1_1_plugin_1_1_v1_1_1_custom_data_a98ef6df5fb929064e5bb3ffef29a1e10.html#a98ef6df5fb929064e5bb3ffef29a1e10 "Load the custom data structure from the provided Work Unit's XML.")` function not called when Work Unit's PluginData section is empty.
-   **WG-55950** Fixed: Crash when playing an audio file after it's been moved to another folder.
-   **WG-55978** Fixed: Wwise Authoring often experiences starvation when playing back audio to multiple devices with different sample rates.
-   **WG-55984** Fixed: Crash when calling WAAPI function [ak.wwise.core.object.get](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_get.html) with a WAQL query that consists of only a GUID with no double-quotes and no dollar sign.
-   **WG-56470** Fixed: Stochastic ray casting gives slightly different results when executing Spatial Audio jobs concurrently across multiple threads.
-   **WG-56551** Fixed: Missing indication for disabled profiling data types in Performance Monitor.
-   **WG-56692** Fixed: Output Peak is not displayed if profiling is started by calling `[StartProfilerCapture()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a55e99fc6cc6be2f93c4599e6e1bd1c0d.html#a55e99fc6cc6be2f93c4599e6e1bd1c0d)`.
-   **WG-56826** Fixed: Cone Preview is unresponsive if Cone Use is already enabled when you open the Attenuation Editor.
-   **WG-56835** Fixed: Voice Monitor graph view is cropped when window width is reduced.
-   **WG-57036** Fixed: In Music Segment Editor, numbers in Voice Volume text boxes are cropped with High DPI monitor settings and larger font sizes.
-   **WG-57048** Fixed: Crash when renaming a Work Unit to a name that has close to 260 characters.
-   **WG-57198** Fixed: When hovering over a text box with a slider in the List View, the text alignment changes.
-   **WG-57371** Fixed: Infinite loop in audio resampling when the sound engine is initialized at certain sample rates.
-   **WG-57379** Fixed: Possible crash while generating SoundBanks that contain an Impacter plug-in instance.
-   **WG-57389** Fixed: Game Sync Monitor shows duplicate values from the same line in the tooltip.
-   **WG-57720** Fixed: (Mac Authoring) Floating views are cropped.
-   **WG-58047** Fixed: Crash when generating SoundBanks following a change in the project's languages.
-   **WG-58463** Fixed: Pressing Alt key alone removes keyboard focus from the user interface.
-   **WG-58959** Fixed: No error message generated in response to invalid Perforce configuration.
-   **WG-59166** Fixed: Numerous stalls in Wwise Authoring when opening projects or changing audio settings.
-   **WG-59356** Fixed: Possible case where successive SoundBank generations result in different SoundBank contents. The SoundBanks contain the same items, but in a different order.
-   **WG-59389** Fixed: Wwise reports properties with values for unknown platforms. Saving the project does not remove said values.
-   **WG-59471** Fixed: Voice Inspector monitoring data is corrupted when using built-in RTPCs with multi-positioned Game Objects.
-   **WG-59496** Fixed: Wwise user interface is sometimes slow to respond following a copy-paste operation.
-   **WG-60024** Fixed: Loading a project with any AK Convolution ShareSets causes the project to become dirty.
-   **WG-60212** Fixed: Crash after attempting to load an incompatible profiler session after a first successful session load.
-   **WG-60406** Fixed: Project becomes dirty when the Crankcase Audio REV 2 plug-in source editor is displayed.
-   **WG-60692** Fixed: (Spatial Audio) When a new sound plays, Room Game Objects do not update their sound paths until the listener moves.
-   **WG-61079** Fixed: AK Convolution Reverb plug-in does not update the available controls or statistics when the active platform is changed.
-   **WG-61209** Fixed: (Spatial Audio) Portal occlusion on room tones is applied twice in the signal path.
-   **WG-61328** Fixed: (Spatial Audio) SetGameObjectRadius does not update paths until the listener moves.
-   **WG-61397** Fixed: (Spatial Audio) A diffraction path might be cut off before the end of a sound's attenuation radius if it passes through a portal that has a large width.
-   **WG-61595** Fixed: Connecting Wwise to a game overwrites the game's Effect bypass values set by Event Actions.
-   **WG-61684** Fixed: (wp.py) Crash when discovering installation directory for Visual Studio 2015.
-   **WG-61691** Fixed: Possible crash when connecting the profiler to a remote platform.
-   **WG-61781** Fixed: Possible case where WAV markers are ignored when playing original file in Wwise.
-   **WG-62116** Fixed: System Audio Objects sometimes disappear from Audio Device meter.
-   **WG-62353** Fixed: Project Explorer expanded and collapsed nodes are not always restored correctly.
-   **WG-62433** Fixed: Low-pass filter label overlaps the control.

-   **WG-26295** Fixed: GetFileStatus performance issue in File Manager dialog box.
-   **WG-39471** Fixed: Renamed Wwise Authoring object "AudioSource" to "AudioFileSource" to avoid error returned by [ak.wwise.core.object.get](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_get.html).
-   **WG-42166** Fixed: Clicking an already selected object doesn't load it in the Transport Control or Property Editor.
-   **WG-44005** Fixed: (WAAPI) [ak.wwise.core.audio.import](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_audio_import.html) doesn't respect all importLocation arguments.
-   **WG-46888** Fixed: RTPC tab graph view zoom resets every time a curve is clicked.
-   **WG-47131** Fixed: Can't copy and paste states from one object to another.
-   **WG-52612** Fixed: Environment Variables in Command Add-ons are not automatically expanded.
-   **WG-54050** Fixed: Typo in name of "IsZeroLantency" property of Music Tracks and sound objects. Corrected to "IsZeroLatency".
-   **WG-54582** Fixed: Event Editor Target column doesn't show the parent name for States and Switches.
-   **WG-54746** Fixed: Folders with a dot in the name are not recognized as folders in File Manager.
-   **WG-55001** Fixed: (WAAPI) [ak.wwise.core.object.delete](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_delete.html) and [ak.wwise.core.audio.import](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_audio_import.html) are missing from the WAAPI headers for JavaScript and TypeScript.
-   **WG-55033** Fixed: No errors reported when loading a Music Track that contains Music Clips without an Audio Source.
-   **WG-55669** Fixed: Loudness Meter's layout makes it hard to reduce the size of the view without losing frequently-used areas.
-   **WG-56405** Fixed: Copying and pasting contents from the Project Explorer to an external editor doesn't maintain the same sorting order as in the Project Explorer.
-   **WG-56408** Fixed: Wwise Sound Engine communication code can over-allocate memory when another application accidentally connects to its network ports.
-   **WG-57212** Fixed: `[AK::SoundEngine::SetOutputDeviceEffect](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ad455f291883c352a87b5b03da64549aa.html#ad455f291883c352a87b5b03da64549aa)` produces a "Device not found error" when specifying the Audio Device ShareSet but using the default hardware ID (0), even when there is an appropriate device.
-   **WG-57251** Fixed: (WAAPI) Import fails when using base64 content and Perforce.
-   **WG-57838** Fixed: Output level is reduced with AK Convolution Reverb inserted on a bus that has height channels.
-   **WG-57840** Fixed: In List View and Contents Editor, pressing the left arrow key does not always collapse the parent object when it is not currently visible.
-   **WG-58452** Fixed: Improved the previous "No Valid Switch" error message returned when trying to set and use invalid or unspecified switches that were not provided with a Default Switch value.
-   **WG-58464** Fixed: Voice Monitor graph view zoom is reset upon starting a new capture.
-   **WG-59203** Fixed: Wwise can't connect to a Perforce server with graph support enabled. Added new option in Perforce settings.
-   **WG-59422** Fixed: Crash when combining finite Sequence Containers that have Trigger rate transitions with Blend Containers that have Initial Delays.
-   **WG-60369** Fixed: (Mac Authoring) External Editors and Command Add-ons fail to execute.
-   **WG-60410** Fixed: Authoring crash when missing Crankcase Audio REV 2 plug-in dependencies.
-   **WG-60577** Fixed: Crash when deleting a Music Track while its volume slider is active.
-   **WG-60602** Fixed: Out-of-bounds memory access when encoding very small (<960 samples) sources with WEM Opus.
-   **WG-60821** Fixed: Possible crash in Recorder plug-in when interacting with UI while recording starts.
-   **WG-60863** Fixed: The Help or F1 button in the Metadata Editor does not open the Help.
-   **WG-60945** Fixed: Game-Defined Auxiliary Sends don't get regular updates from RTPCs on busses.
-   **WG-60959** Fixed: Encoding of WEM Opus media produces slightly different results across AMD and Intel CPUs. Note that while the newly generated media will be different than before, the old encodings of WEM Opus media are still supported.
-   **WG-60969** Fixed: (Spatial Audio) Any emitter using diffraction can become inaudible when the listener position overlaps a portal.
-   **WG-61127** Fixed: Crash in `CAkListener::MultiDirectionGainCorrectionForObjects` during low-memory scenarios.
-   **WG-61508** Fixed: SoundBank metadata Max attenuation for Events does not take Post Event actions into account.
-   **WG-61634** Fixed: Crash when inspecting an RTPC or State from the Multi Editor or the default plug-in property list.
-   **WG-61655** Fixed: Calling `[AK::SoundEngine::ReplaceOutput](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a81521a4611d3891c499ec9c5eb421ac2.html#a81521a4611d3891c499ec9c5eb421ac2)` with an Audio Device ShareSet of 0 can cause audio loss if the old output Audio Device is connected to multiple audio busses.
-   **WG-61682** Fixed: Sound volume goes to multiples hundreds of dB when the same RTPC is used in a Blend Container and children of that Blend Container.
-   **WG-61706** Fixed: Crash when Opus sounds start in virtual mode.
-   **WG-61727** Fixed: A nested Music Switch Container doesn't switch to the correct child when the parent Switch Container has an active Transition with a positive Offset.
-   **WG-62014** Fixed: Playback of External Sources and some streams while `[AkInitSettings::bDebugOutOfRangeCheckEnabled](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_init_settings_a0ffc62cdbb07d0c8ebb2440fd177625b.html#a0ffc62cdbb07d0c8ebb2440fd177625b "Debug setting: Enable checks for out-of-range (and NAN) floats in the processing code....")` is enabled creates false errors indicating invalid audio data.

See also

-   [New Features Overview 2022.1](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_new_features.html)
-   [Important Migration Notes 2022.1](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_migration.html)

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#new_features)
-   [API Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#api_changes)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#behavior_changes)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#performance_changes)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#miscellaneous_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1.html#fixes_for_community-reported_bugs)

_menu_