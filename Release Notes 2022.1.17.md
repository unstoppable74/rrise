Warning: Some protected information is not displayed.  
Please [sign in](https://www.audiokinetic.com/redirect-sign-in/) if you are a licensed user for specific platforms.

Wwise SDK 2025.1.9

The following sections list and describe the changes to Wwise between version 2022.1.16 and version 2022.1.17.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_17.html#generic_bugs_2022_1_17)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_17.html#generic_community_bugs_2022_1_17)
-   [Documentation Improvements](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_17.html#generic_documentation_improvements_2022_1_17)

## Bug Fixes

# Bug Fixes

-   **WG-68568** Fixed: Crash in the Integration Demo on Mac when exiting the microphone demo page after enabling the microphone input.
-   **WG-74210** Fixed: Assertion failure in Spatial Audio module in Debug configuration under low memory conditions.
-   **WG-74278** Fixed: Infinite loop in Wwise Recorder plug-in termination under low memory conditions.
-   **WG-74469** Fixed: Voices and Buses in the CPU Timeline view are not displayed with their color as specified in the Wwise Project.

-   **WG-70074** Fixed: Cannot access all attenuation curves using WAAPI functions `[ak.wwise.core.object.getAttenuationCurve](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_getattenuationcurve.html)` and `[ak.wwise.core.object.setAttenuationCurve](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_core_object_setattenuationcurve.html)`.
-   **WG-71898** Fixed: Possible sound engine crash when loading a SoundBank containing an already loaded and playing music track.
-   **WG-73493** Fixed: Global modulators controlling RTPCs affecting sounds playing from a looping container can cause an assert.

## Documentation Improvements

-   **WG-73974** Improved text formatting in [Building Your Project for the Different Wwise Platforms](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=effectplugin_tools_building.html).

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)