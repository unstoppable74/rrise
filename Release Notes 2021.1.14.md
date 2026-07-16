Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

The following sections list and describe the changes to Wwise between version 2021.1.13 and version 2021.1.14.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_14.html#generic_feature_changes_2021_1_14)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_14.html#generic_bugs_2021_1_14)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2021_1_14.html#generic_community_bugs_2021_1_14)

## New Features

-   **WG-66725** In Wwise Project Settings, you can now specify the line ending (LF vs. CRLF) applied when saving project and SoundBank files.

## Bug Fixes

-   **WG-60363** Fixed: (Mac Authoring) Cannot import audio files if the path includes Unicode characters.
-   **WG-66813** Fixed: Some background tasks are delayed.

# New Features

-   **WG-45904** Fixed: Possible crash or assert when changing a Music Segment position during playback.
-   **WG-53851** Fixed: Crash while restarting a Profiler session when using the Voice Inspector.
-   **WG-65198** Fixed: Crash in Vorbis conversion following file conversion error or source control error.
-   **WG-65670** Fixed: AK Convolution Reverb curve ID conflicts on Work Unit reload.
-   **WG-65746** Fixed: Media ID changes after reloading Work Units.
-   **WG-65759** Fixed: (Spatial Audio) Diffraction paths are sometimes lost when the listener is positioned parallel to a portal's wall.
-   **WG-66279** Fixed: Possible crash when terminating the sound engine while sounds using emitter automation are still playing.
-   **WG-66419** Fixed: Modified files do not appear in the Subversion Commit dialog.
-   **WG-66428** Fixed: Voice starvation (CPU wait) due to AkFilePackageLowLevelIO usage when disk is heavily used.
-   **WG-67005** Fixed: WAAPI Import of localized WAV files does not account for the specified object path.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)