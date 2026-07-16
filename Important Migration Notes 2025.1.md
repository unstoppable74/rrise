Due to some of the new features in 2025.1 (refer to [New Features Overview 2025.1](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_new_features.html)), there are several important things to be aware of before you migrate to Wwise 2025.1.

## Changes to Application Binary Interface (ABI)

The binary representation of the plug-in interface was changed. All plug-ins must be recompiled against the Wwise 2025.1 SDK headers to be loaded in the Wwise 2025.1 runtime.

## C/C++ API changes

In order to make certain types usable from C and to have more consistent representation across platforms, some elements of the C++ API have been changed:

## External Sources

[AkExternalSourceInfo::szFile](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_external_source_info_af29151c09e6b12f9b4f5b4c9a9389ba1.html#af29151c09e6b12f9b4f5b4c9a9389ba1 "UTF-8 File path for the source. If not NULL, the source will be streaming from disk....") is now a UTF-8 string (`char*`) rather than a OS-native string (`AkOSChar*`).

## Callback system

The PostEvent callback signature has changed. The previous callback info structure has been split in two:

-   Data common to all callback types is passed as a pointer to an [AkEventCallbackInfo](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_event_callback_info.html) structure. This pointer must not be cast to a different type.
-   Data unique to a callback type is passed as a `void` pointer. Cast this pointer to the appropriate callback info structure type based on the value of the `in_eType` parameter. Note that this pointer is null for some callback types where no additional information is necessary (i.e. AK\_EndOfEvent, AK\_Starvation, and AK\_MusicPlayStarted).

In addition, both the PostEvent and BusVolume callbacks now have the user cookie passed as an explicit parameter. The cookie is no longer stored in the info structure.

## Other minor type changes and renames

-   The enum `AK::SoundEngine::AkActionOnEventType` has been renamed to `AkActionOnEventType` in the global namespace. Its values are also similarly renamed.
-   The enum `AK::AkAudioDeviceEvent` has been renamed to `AkAudioDeviceEvent` in the global namespace. Its values are also similarly renamed.
-   The enum `AK::SoundEngine::MultiPositionType` has been renamed to `AkMultiPositionType` in the global namespace. Its values are also similarly renamed.
-   The enum `[AK::SoundEngine::DynamicSequence::DynamicSequenceType](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_1_1_dynamic_sequence_a8a2d2e9917fc300d080436c871b03b51.html#a8a2d2e9917fc300d080436c871b03b51)` has been renamed to `AkDynamicSequenceType` in the global namespace. Its values are also similarly renamed.
-   The struct `[AkMIDIPost](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_m_i_d_i_post.html)` no longer inherits `[AkMIDIEvent](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_m_i_d_i_event.html)`; it has a `midiEvent` data member instead.
-   `[AkWorldTransform](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_world_transform.html "Position and orientation of game objects in the world (i.e. supports 64-bit-precision position)")` and `[AkTransform](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_transform.html "Position and orientation of objects in a "local" space.")` are now `struct` types.
-   `[WaveFormatExtensible](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_wave_format_extensible.html)` has been renamed to `[WemFormatExtensible](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_wem_format_extensible.html)` to avoid confusion with the actual WAVE format definition.

## AkMusicEngine library is removed

The entire AK::MusicEngine namespace, related functions and library are removed. The functionality of AK::MusicEngine was all moved to [AK::SoundEngine](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine.html) and otherwise works the same way as before. If your game is using Unity or Unreal, the default integrations have been changed accordingly, it should be transparent. If your game uses a private game engine, this change will break your build. To migrate your code, follow these steps.

-   The AkMusicEngine.lib/so file was removed. Game build scripts should be modified to remove the library from the linker input.
-   The include AK/MusicEngine/Common/AkMusicEngine.h was removed. Remove all include statements to this file.
-   The functions AK::MusicEngine::Init and AK::MusicEngine::Term are removed, simply delete them from your Wwise initialization code, along with references to the AkMusicSettings type.
-   The function AK::MusicEngine::GetPlayingSegmentInfo was moved to [AK::SoundEngine::GetPlayingSegmentInfo](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a8446828c7f31802a83b7b087c44ccbd4.html#a8446828c7f31802a83b7b087c44ccbd4), simply change the namespace in your code.

## AK::SoundEngine::GetSourcePlayPosition and AK\_EnableGetSourcePlayPosition changes

The position of sources is now tracked by default. There is no need for the flag `AK_EnableGetSourcePlayPosition` to be passed to `[AK::SoundEngine::PostEvent](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a41e9ef8d42951871fe4a8ae58a29a68e.html#a41e9ef8d42951871fe4a8ae58a29a68e)`. The flag was simply removed, just delete any reference to it in your code.

`[AK::SoundEngine::GetSourcePlayPosition()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ae0b469d9fb8a099b40f52f004882d283.html#ae0b469d9fb8a099b40f52f004882d283)` now returns the position more precisely too. The difference is related to the latency of playback, as defined by `[AkPlatformInitSettings::uNumRefillsInVoice](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_platform_init_settings_a953085ec90c00bf53ddafc8af700277d.html#a953085ec90c00bf53ddafc8af700277d "Number of refill buffers in voice buffer. Defaults to 4.")`. Before 25.1, the latency was not taken in account therefore the time reported could be up to 4 buffers (40 to 80 ms) ahead of what was played, on top of other natural sources of timing uncertainty. The new timing should now be precise to one buffer (10 to 20ms).

## Other noteworthy removals

`IAkVoicePluginInfo::ComputePriorityWithDistance` was obsolete and removed.

## Asynchronous operations with custom BankManager thread are now supported

When `[AkInitSettings::bUseSoundBankMgrThread](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_init_settings_a3f9f40766762c100b829467ffaa31b24.html#a3f9f40766762c100b829467ffaa31b24 "Use a Wwise-owned thread for loading sound banks. If set to false, bank-loading will occur only insid...")` is set to `false`, asynchronous variants of bank API calls are no longer executed immediately. Instead, the operations are added to a queue and the game must call `[AK::SoundEngine::ProcessBanks](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a1bb80e2fe3b8051fb9ece6dc9bb1fbb6.html#a1bb80e2fe3b8051fb9ece6dc9bb1fbb6)` to process the operations in the queue. Refer to [Optimizing CPU usage](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=goingfurther_eventmgrthread.html) for more information on customizing Sound Engine threads.

There is no change in behavior if `[AkInitSettings::bUseSoundBankMgrThread](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_init_settings_a3f9f40766762c100b829467ffaa31b24.html#a3f9f40766762c100b829467ffaa31b24 "Use a Wwise-owned thread for loading sound banks. If set to false, bank-loading will occur only insid...")` is set to `true` (the default).

## Actor-Mixer Hierarchy, Master-Mixer Hierarchy, and Interactive Music Hierarchy

This version of Wwise introduces significant updates to the project's folder structure.

The following root nodes have been updated:

-   **Audio Devices**: Renamed to **Devices**
-   **Master-Mixer Hierarchy**: Renamed to **Busses**
-   **Actor-Mixer Hierarchy**: Renamed to **Containers**
-   **Interactive Music Hierarchy**: Moved to **Containers** and renamed to **Music (Migrated)**

Any tool, script, or engine referencing these paths will need to be updated.

Please note that Wwise provides aliases that automatically translate incoming paths to their new names. For example, `\Actor-Mixer Hierarchy\SFX_CHARACTER\SFX_EXPL_01` will automatically be translated to `\Containers\SFX_CHARACTER\SFX_EXPL_01`.

The SDK function [AK::SoundEngine::SetActorMixerEffect](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_a00256bfd86c2bed14c626922fc4417b0.html#a00256bfd86c2bed14c626922fc4417b0) was renamed [AK::SoundEngine::SetContainerEffect](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_af70b2f69c1377e5ad8e5b8310d73a104.html#af70b2f69c1377e5ad8e5b8310d73a104).

## WAAPI and WAQL Referring to Project Paths

The project structure changes affect WAAPI and WAQL scripts. Any code referencing the paths mentioned above will be impacted.

We recommend avoiding hardcoding paths like `\Actor-Mixer Hierarchy\Default Work Unit` in your client code. Instead, call [ak.wwise.core.getProjectInfo](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_getprojectinfo.html) and retrieve either the `defaultWorkUnits` or the `defaultImportWorkUnit`.

Please note that the **Interactive Music Hierarchy** no longer exists. Music objects can now be created directly within the **Containers** hierarchy.

## Tab Delimited Import Referring to Project Paths

The project structure changes also impact Tab Delimited Import files.

Ensure that your Tab Delimited Import generators and spreadsheets are updated to reflect the new path names.

## Property Changes for Authoring Plug-ins

-   InfiniteValue: this attribute is now restricted to integral property types.

## Actor-Mixer renamed to Property Container

The Actor-Mixer object is now called a Property Container.

Usage of "Actor-Mixer" and "ActorMixer" in WAAPI, WAQL and in Tab Delimited Import files should be changed to "Property Container" and "PropertyContainer" respectively.

## Master Audio Bus renamed to Main Audio Bus

When creating a new project, the "Master Audio Bus" object is now named "Main Audio Bus". Update WAAPI and WAQL scripts to "Main Audio Bus" for new projects; use "Master Audio Bus" for existing ones.

## MasterMixerConsole renamed to BussesConsole

The "MasterMixerConsole" view identifier has been renamed to "BussesConsole". Update WAAPI and WAQL scripts to "BussesConsole".

Layouts referencing the "MasterMixerConsole" view will need to be updated.

## ObjectList Data Model Changes

The internal structure of object lists has changed. Objects in some object lists are now accessed differently. The following lists now contain InnerObjects that have references to the Wwise object: **Arguments**, **EntryPath**, **Metadata**, **Playlist**.

-   **Arguments**: contains the InnerObject **ArgumentsSlot** with reference **Argument**. **Note**: This applies to Dialogue Event objects.
-   **Arguments**: contains the InnerObject **MusicArgumentsSlot** with reference **Argument**. **Note**: This applies to Music Switch Container objects.
-   **EntryPath**: contains the InnerObject **EntryPathSlot** with reference **EntryPathObject**
-   **Metadata**: contains the InnerObject **MetadataSlot** with reference **Metadata**
-   **Playlist**: contains the InnerObject **PlaylistSlot** with reference **PlaylistObject**

## WAAPI Object Lists

This table identifies the pertinent changes when using ak.wwise.core.object.set to construct the object lists.

# Changes to Application Binary Interface (ABI)

|            **Old style**             |                                                                                                 **New style**                                                                                                 |
|----------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| "@Arguments": [object1, object2] | "@Arguments": [{"type": "ArgumentsSlot", "name": "", "@Argument": object1}, {"type": "ArgumentsSlot", "name": "", "@Argument": object2}]

**Note**: This applies to Dialogue Event objects. |
| "@Arguments": [object1, object2] | "@Arguments": [{"type": "MusicArgumentsSlot", "name": "", "@Argument": object1}, {"type": "MusicArgumentsSlot", "name": "", "@Argument": object2}]

**Note**: This applies to Music Switch Container objects. |
| "@EntryPath": [object1, object2] |                          "@EntryPath": [{"type": "EntryPathSlot", "name": "", "@EntryPathObject": object1}, {"type": "EntryPathSlot", "name": "", "@EntryPathObject": object2}]                           |
| "@Metadata": [object1, object2]  |                                   "@Metadata": [{"type": "MetadataSlot", "name": "", "@Metadata": object1}, {"type": "MetadataSlot", "name": "", "@Metadata": object2}]                                   |
| "@Playlist": [object1, object2]  |                             "@Playlist": [{"type": "PlaylistSlot", "name": "", "@PlaylistObject": object1}, {"type": "PlaylistSlot", "name": "", "@PlaylistObject": object2}]                             |

## WAQL Object Lists

This table provides examples that identify the pertinent changes when using a WAQL query involving object lists.

|                                                                                            **Old style**                                                                                             |                                                                                                                                                                          **New style**                                                                                                                                                                           |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| where @metadata.any and @metadata.any(pluginname = "Wwise System Output Settings")

"\\Busses\\Default Work Unit\\Master Audio Bus\\BusA" select metadata.at(1)

return: ["metadata.at(1).name"] | where @metadata.any and @metadata.any(@metadata.pluginname = "Wwise System Output Settings")

"\\Busses\\Default Work Unit\\Master Audio Bus\\BusA" select metadata.at(1).metadata

return: ["metadata.at(1).metadata.name"]

from type plugininnerobject where pluginname = "metadataslot" select metadata.where(pluginname="Wwise System Output Settings") |
|                                                             from type randomsequencecontainer select playlist.where(type = "sound")                                                              |                                                                                                                                    from type randomsequencecontainer select playlist.where(playlistobject.type = "sound")                                                                                                                                    |
|                                                                            where @Arguments.any(name = "StateGroup1")                                                                            |                                                                                                                                                     where @Arguments.any(argument.name = "StateGroup1")                                                                                                                                                      |
|                                                                              where @EntryPath.any(name = "State1")                                                                               |                                                                                                                                                    where @EntryPath.any(entrypathobject.name = "State1")                                                                                                                                                     |

## Command ID Name Changes

-   The command `ShowAudioFilesImporter` has been renamed to `ShowAudioFileImporter`.

## Property Changes for Wwise Reflect

Several properties related to managing the Doppler effect have been updated. Some have been deprecated and hidden from the interface, while others introduce behavior changes.

## Renamed Properties

The following properties have been renamed, but their functionality remains identical:

-   **Distance Smoothing**: Renamed to **Delay Smoothing**.
-   **Pitch Threshold**: Renamed to **Pitch Limit**.

## Hidden and Deprecated Properties

The following properties have been deprecated. They still exist, but are hidden from the user interface. They will be removed completely in a later version.

-   **Smoothing Type**: Hidden and deprecated. In the future, only the efficient IIR mode will be supported.
-   **Threshold Mode**: Hidden and deprecated. In Continuous mode, an additional Doppler control algorithm, which is accessible via the new **Delay Error Tolerance** property, has been added. Its behavior is similar to the former Step mode.
-   **Distance Threshold** is now hidden and deprecated.

The Step mode has been deprecated. To replicate its behavior, use the new **Delay Error Tolerance** property in conjunction with a low **Pitch Limit** value. While related to **Distance Threshold**, **Delay Error Tolerance** defines the threshold as a relative measure of delay rather than an absolute distance. Refer to the Reflect Help for more details.

| _dangerous_ | **Warning:** If you had set the **Threshold Mode** to Step and wish to change the deprecated **Distance Threshold**, or switch to the improved Continuous mode, you need to make the hidden properties visible in the UI. To do so, open Authoring\x64\Debug\bin\Plugins\AkReflect.xml, locate the desired property, and change `IsVisible="false"` to `IsVisible="true"`. Then reopen Wwise. |
|-----------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|

## AK Expander Plug-in Library Removed

The [AK](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k.html "Definition of data structures for AkAudioObject.") Expander plug-in is no longer a standalone library or DLL, and all of its functionality has been moved into the [AK](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k.html "Definition of data structures for AkAudioObject.") Compressor library. References to the AkExpanderFX library or AkExpanderFXFactory for compilation should be removed, or updated to refer to the AKCompressorFX library instead. If the Wwise Authoring installation is updated in-place, make sure that the AkExpander library in Wwise Authoring's `Plugins` directory is deleted, to avoid errors during project load of duplicate plug-in IDs.

## Android Platform Init Settings changed

To provide better control over audio output initialization on Android, some initialization settings were removed and others added:

-   `[AkPlatformInitSettings::bEnableLowLatency](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_platform_init_settings_a1788425746a23a0df1b9fdbb0a19adb1.html#a1788425746a23a0df1b9fdbb0a19adb1)` was replaced by `[AkPlatformInitSettings::eAudioPath](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_platform_init_settings_ad2e47361df0729f77072ac27fe18fc77.html#ad2e47361df0729f77072ac27fe18fc77 "Which audio path to use. See enum for details. Default: AkAudioPath_LowLatency.")` to give more granular control over latency. Refer to the documentation of `AkAudioPath` to learn how to set this option.
-   `[AkPlatformInitSettings::eAudioAPI](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_platform_init_settings_ad937321443c5b4864233746935aa5e1c.html#ad937321443c5b4864233746935aa5e1c "Main audio API to use. Leave to AkAPI_Default for the default sink (default value)....")` bitfield now accepts two more bits to control use of the 3D Audio APIs on Android: `AkAudioAPI_DolbyAtmos` and `AkAudioAPI_AndroidSpatializer`.

On the vast majority of Android devices, settings now default to AAudio using PerformanceMode=LowLatency and SharedMode=Shared. This is different from Wwise 2024.1 which defaulted to AAudio using PerformanceMode=LowLatency and SharedMode=Exclusive. The new default should give better compatibility with a wider range of devices without a noticeable impact on latency.

## Windows Static Library Changes

Debug symbols are now embedded directly in `.lib` files for the Windows platform. Wwise static libraries for Windows are no longer accompanied by the corresponding `.pdb` files because they are unnecessary.