Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

Release Notes 2022.1.15

The following sections list and describe the changes to Wwise between version 2022.1.14 and version 2022.1.15.  
Platform-specific information can be found here:

[Android 2022.1.15](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=android_releasenotes_2022_1_15.html)

[OpenHarmony 2022.1.15](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=openharmony_releasenotes_2022_1_15.html)

[iOS/tvOS/visionOS 2022.1.15](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ios_releasenotes_2022_1_15.html)

[Linux 2022.1.15](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=linux_releasenotes_2022_1_15.html)

[Mac 2022.1.15](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=mac_releasenotes_2022_1_15.html)

[Windows and Windows UWP 2022.1.15](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=windows_releasenotes_2022_1_15.html)

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [New Features](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_15.html#generic_feature_changes_2022_1_15)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_15.html#generic_behavior_changes_2022_1_15)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_15.html#generic_bugs_2022_1_15)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_15.html#generic_community_bugs_2022_1_15)

## New Features

-   **WG-68160** MIDI files are now supported in the File Manager.

## Behavior Changes

-   **WG-73325** The CPU Timeline and CPU Usage graphs now include the time spent waiting to acquire the global lock during sound engine execution, which might be helpful in identifying some stalls in audio rendering.

## Bug Fixes

-   **WG-71929** When using a high DPI monitor, clicking an object in the Project Explorer sometimes does not result in it being displayed in the Property Editor.
-   **WG-73161** Fixed: Possible crash when trying to use the shortcut menu for a Music Segment.
-   **WG-73196** Fixed: Music Stinger Play At property values Next Beat and Next Bar are reversed.
-   **WG-73329** Fixed: Music Playlist Item does not allow setting Avoid Repeat to zero.

## Fixes for Community-Reported Bugs

# New Features

-   **WG-64858** Fixed: Audio does not come back when using SetOfflineRendering to false to resume normal playback.
-   **WG-72711** Fixed: Audio does not come back when setting SetOfflineRendering to false to resume normal playback.
-   **WG-72993** Fixed: Crash or assert in AkMediaEntry::Release when multiple copies of media are added while that media is in use.
-   **WG-73272** Fixed: (Spatial Audio) ErrorCode\_SpatialAudio\_PortalNotFound does not report the Portal ID properly.
-   **WG-73328** Fixed: Erroneous "Failed to unprepare event" errors in the capture log when unpreparing interactive music content.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Need Support?

Questions? Problems? Need more info? Contact us, and we can help!

[Visit our Support page](https://www.audiokinetic.com/help/support/)

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)