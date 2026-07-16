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

The following sections list and describe the changes to Wwise between version 2022.1.4 and version 2022.1.5.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_5.html#generic_feature_changes_2022_1_5)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_5.html#generic_behavior_changes_2022_1_5)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_5.html#generic_bugs_2022_1_5)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_5.html#generic_community_bugs_2022_1_5)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_5.html#generic_documentation_improvements_2022_1_5)

## New Features

-   **WG-65199** (wp.py) Added Visual Studio 2022 target support for the Authoring plug-in part.

## Behavior Changes

-   **WG-60217** When using an AkChannelMask on a Game Object via `[AK::SoundEngine::SetMultiplePositions](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_aec6be4dca0249557ea2680b755bd218a.html#aec6be4dca0249557ea2680b755bd218a)`, the channel mask was previously only applied to Audio Objects when they were mixed down to a non-Audio Objects bus. Now, the channel mask is also applied when Audio Objects are processed by any Audio Objects bus. When an AkChannelMask is applied to an Audio Object, only the channels set in the mask are included, and the resulting Audio Object has a reduced channel configuration based on the number of channels that are included. For example, applying a mask of AK\_SPEAKER\_FRONT\_RIGHT | AK\_SPEAKER\_SIDE\_LEFT to a quadraphonic Audio Object converts it into a stereo Audio Object consisting of the FR and SL channels from the original Audio Object. Most notably, this means that AkChannelMasks are now properly applied to Audio Objects, which are ultimately sent to an endpoint as System Audio Objects. This also improves the results of some Object Processor Effects, such as Compressor, which previously might have incorrectly incorporated channels into their processing that were yet to be masked out.
-   **WG-64863** Multichannel sources that are mixed to an ambisonic bus now have a loudness similar to their loudness when panned to a non-ambisonic bus. Specifically, this change increases the volume of multichannel sources for ambisonics by several decibels, depending on their channel count. For example, there will be an increase of +3db for a stereo source and +6db for a quadraphonic source. In practice, this means that any corrections to the mix that were made specifically for this situation can be removed.
-   **WG-65329** In the Remote Connections dialog, content is automatically sorted with Local host entries at the top of the IP Address / Device ID column.

## Bug Fixes

-   **WG-63556** Fixed: Project Explorer toolbar is not re-enabled after playback ends.
-   **WG-63943** Fixed: In the Paste Properties dialog, the expand/collapse states of the properties tree are preserved when we toggle filter mode.
-   **WG-64839** Fixed: Cannot build Authoring plug-ins without MFC.
-   **WG-65028** Fixed: Modified files do not appear in the Subversion Commit dialog.
-   **WG-65507** Fixed: Threading issue (invalid data access) during audio file conversion.
-   **WG-65588** Fixed: Crash when there is a syntax error in a WAQL query in which a Query object is used.
-   **WG-65607** Fixed: Changes to Game Object 3D Viewer Options are not applied after a capture.

# New Features

-   **WG-45904** Fixed: Possible crash or assert when changing a Music Segment position during playback.
-   **WG-58610** Fixed: (WAAPI) [ak.wwise.core.soundbank.generate](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_soundbank_generate.html) doesn't generate SoundBanks when no soundbank, language, and/or platform is provided if the key is provided as an empty array in the arguments. Now SoundBank generation logs are returned in [ak.wwise.core.soundbank.generate](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_soundbank_generate.html).
-   **WG-61704** Fixed: Meter plug-in doesn't meter properly when on objects in the Actor-Mixer hierarchy.
-   **WG-62164** Fixed: In the Transitions tab of an Object Tab, changes to column widths are reset when changing focus.
-   **WG-64397** Fixed: Source Control Log window appears during successful Check-Out and Add operations.
-   **WG-64440** Fixed: Possible crash when calling a Stop All Action with an exception list when playing a continuous Switch Container after the SoundBank containing it was unloaded.
-   **WG-64576** Fixed: Crash in `AKPerf::PostPipelineStats` while running multiple streams with Wwise Authoring connected to the sound engine runtime.
-   **WG-64918** Fixed: Possible crash when stopping Switch or Blend Containers playing in Continuous mode after assets are unloaded.
-   **WG-65078** Fixed: Crash when reporting the ErrorCode\_MusicRendererSeekingFailed error message if no valid game object was specified.
-   **WG-65296** Fixed: Benign "Wwise audio out of range: ComputeSpeakerMatrix2D" error when `[AkInitSettings::bDebugOutOfRangeCheckEnabled](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_init_settings_a0ffc62cdbb07d0c8ebb2440fd177625b.html#a0ffc62cdbb07d0c8ebb2440fd177625b "Debug setting: Enable checks for out-of-range (and NAN) floats in the processing code....")` is enabled and decoding an ambisonic source to standard channel configuration.
-   **WG-65439** Fixed: FilePackager cannot package media files tagged as "OtherBank".
-   **WG-65464** Fixed: (WAAPI) The user interface remains in a broken state when ak.wwise.core.undo.endGroup returns an error.
-   **WG-65465** Fixed: (WAAPI) Call to end Undo Group fails after creating Work Units.
-   **WG-65470** Fixed: Switch values can lead to ID clashes, setting the Switch has no effect.
-   **WG-65653** Fixed: (WAAPI) Using [ak.wwise.core.soundbank.generate](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_soundbank_generate.html) with argument skipLanguages equal to true does not generate SoundBanks.
-   **WG-65670** Fixed: AK Convolution Reverb curve ID conflicts on Work Unit reload.
-   **WG-65722** Fixed: When playing an object, the object selected in the Transport Control is immediately overridden by the last selection in the results list of the Query Editor.
-   **WG-65746** Fixed: Media ID changes after reloading Work Units.
-   **WG-65759** Fixed: (Spatial Audio) Diffraction paths are sometimes lost when the listener is positioned parallel to a portal's wall.

## Documentation Improvements

-   **WG-60867** Added Auto-Defined SoundBanks to [Strategies for Managing SoundBanks](https://www.audiokinetic.com/library/edge/?source=Help&id=strategies_for_managing_soundbanks).
-   **WG-64404** Clarified behavior of Game Parameters bound to built-in parameters. Refer to [Binding Game Parameters to built-in parameters](https://www.audiokinetic.com/library/edge/?source=Help&id=managing_game_parameters_used_in_rtpcs#binding_game_parameter_to_built_in_parameter).
-   **WG-65041** Added explanation of Meter Instances to the associated reference topic, [Understanding Selection Channels and Meter Instances](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/%5Bhttps://www.audiokinetic.com/library/edge/?source=Help&id=syncing_group_of_views%7Chttps://www.audiokinetic.com/library/edge/?source=Help&id=syncing_group_of_views%5D).
-   **WG-65140** Clarified limitation on adding RTPCs using the [Multi Editor](https://www.audiokinetic.com/library/edge/?source=Help&id=multi_editor_multi_editor).
-   **WG-65262** Moved to topic [Defining How Objects Within a Container are Played](https://www.audiokinetic.com/library/edge/?source=Help&id=defining_how_objects_within_container_are_played) information about mentioned parameters which had been in child pages. Edited for clarity.
-   **WG-66105** Elaborated on use of [ak.wwise.core.soundbank.generate](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_soundbank_generate.html) and [ak.wwise.core.soundbank.generationDone Publish Schema](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_soundbank_generationdone_publish_schema.html).

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_5.html#new_features)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_5.html#behavior_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_5.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_5.html#fixes_for_community-reported_bugs)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_5.html#documentation_improvements)

_menu_