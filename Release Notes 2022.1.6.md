Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

The following sections list and describe the changes to Wwise between version 2022.1.5 and version 2022.1.6.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_6.html#generic_bugs_2022_1_6)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_6.html#generic_community_bugs_2022_1_6)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_6.html#generic_documentation_improvements_2022_1_6)

## Bug Fixes

-   **WG-64654** Fixed: Possible crash while profiling using Game Object Profiler layout, and the game object is unregistered before audio playback ends.
-   **WG-65291** Fixed: (Perforce) SoundBank metadata files have "edited" status after a different user generates SoundBanks.
-   **WG-66246** Fixed: User interface stops responding when double-clicking **Import** in Audio File Importer.

# Bug Fixes

-   **WG-62887** Fixed: Possible crash on project load when the 3D device fails to initialize.
-   **WG-65792** Fixed: Voice Inspector shows two rows for a State Group on the same object and same property.
-   **WG-66093** Fixed: Crash in `CAkSpeakerPan::DecodeAmbisonicsBasic`.
-   **WG-66098** Fixed: Unity fails to open after Wwise version upgrade with the error "Missing Default Layout".
-   **WG-66278** Fixed: Deadlock in CAkPlayingMgr with concurrent rendering.
-   **WG-66318** Fixed: Missing volume numbers in Loudness Meter in High DPI at UI Scaling of 200%.
-   **WG-66428** Fixed: Voice starvation (CPU wait) due to AkFilePackageLowLevelIO usage when disk is heavily used.
-   **WG-66470** Fixed: (Spatial Audio) Crash in `AkAcousticRoom::PortalDistanceToProbe`.

## Documentation Improvements

-   **WG-56847** Added new topic [Wwise Wave Viewer](https://www.audiokinetic.com/library/edge/?source=Help&id=wwise_wave_viewer).
-   **WG-65269** Revised [Creating Audio Conversion Settings ShareSets](https://www.audiokinetic.com/library/edge/?source=Help&id=creating_audio_conversion_settings_sharesets) to make list of supported audio formats more prominent.
-   **WG-65273** Added a description to the [Dynamic Sequence SDK reference page](https://www.audiokinetic.com/library/edge/?source=SDK&id=namespace_a_k_1_1_sound_engine_1_1_dynamic_sequence.html), as well as links to related topics.
-   **WG-65641** Updated and clarified [Creating Resource Files for Your Plug-in](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=effectplugin_tools_resource_file.html) documentation.
-   **WG-66143** Added information to [Managing Project Files with a Source Control Plug-in](https://www.audiokinetic.com/library/edge/?source=Help&id=managing_project_files_using_workgroup_plug_in) on configuring a source control plug-in.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)