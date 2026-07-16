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

The following sections list and describe the changes to Wwise between version 2022.1.1 and version 2022.1.2.  
Platform-specific information can be found here:

For earlier versions, please refer to [Previous Release Notes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=previousreleases.html).

-   [API Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#generic_api_changes_2022_1_2)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#generic_behavior_changes_2022_1_2)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#generic_perf_changes_2022_1_2)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#generic_misc_2022_1_2)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#generic_bugs_2022_1_2)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#generic_community_bugs_2022_1_2)

## API Changes

-   **WG-63183** A new API function for the `[AK::MemoryMgr](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_memory_mgr.html)`, [AK::MemoryMgr::TrimForThread](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_memory_mgr_a325a7f2aa771d1f25e280441cb77151d.html#a325a7f2aa771d1f25e280441cb77151d), has been added. This function gives game integrations additional opportunities to free up thread-local resources when threads enter periods of inactivity. For Wwise's built-in memory allocator, rpmalloc, this will finalize all deferred free operations on the thread and return thread-local heaps to the global store, to be later reused by other threads. This function is called after execution of `CAkAudioMgr::Perform` on the `EventMgr` thread, and after `CAkThreadedBankMgr` processes a set of commands on the `BankMgr` thread. We recommend that game integrations call this function on worker threads occasionally, such as after returning from execution of the `AK::JobMgr` worker function.

## Behavior Changes

-   **WG-63468** When using the [generate-soundbank](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=ak_wwise_cli_generatesoundbank.html) operation with the WwiseConsole, the source control operations are now done automatically when the option is enabled in the SoundBank Settings. It is possible to disable the source control operations by using the –no-source-control flag at the command line. User Project Settings will load if necessary to obtain the source control settings.

## Performance Changes

-   **WG-57458** Adjusted scheduling of jobs in the `AK::JobMgr` so that when a job has all of its dependencies satisfied, it is scheduled for execution immediately, instead of being enqueued and later dequeued. This should reduce the overhead of the job manager system, especially when running voice graphs containing many small busses, and improve execution of jobs due to improved cache utilization in many cases.
-   **WG-60124** The entirety of the sound engine tick, that is, execution of `CAkAudioMgr::Perform`, now runs as jobs of type `AkJobType_AudioProcessing`. For game integrations that have set up support for the Wwise Job Manager, even with just one worker of type `AkJobType_AudioProcessing`, this should eliminate almost all of the work performed on the `AK::EventMgr` thread, and instead let the entirety of the sound engine tick run on game engine thread pools. For example, this should eliminate performance issues that work being performed on the game engine thread pools might have experienced due to being pre-empted by the `AK::EventMgr` thread, which should improve the overall consistency of game engine performance.
-   **WG-63532** Dispatching of "empty" jobs by the `AK::JobMgr` no longer issues worker requests. Most notably, this should eliminate many worker requests initiated by `_CallGlobalExtensionsAsync` that would not actually have any work to be performed.

## Miscellaneous Changes

-   **WG-62516** CPU time spent on profiling of Spatial Audio in the runtime is now attributed to a separate Spatial Audio CPU timer scope. Previously it was attributed to "Global Extension".
-   **WG-63055** Upgraded Visual Studio 2022 version to 17.4.2.
-   **WG-63517** Running wp.py build commands now includes CL\_MPCount as an argument to the MSBuild process.

## Bug Fixes

# API Changes

-   **WG-57678** Fixed: (Spatial Audio) Reflections of a surface that is exactly coincident with another surface are intermittent and unstable.
-   **WG-61025** Fixed: Crash in Wwise Authoring when setting AK Convolution plug-in IR response times with a window of 0 frames.
-   **WG-61974** Fixed: Voice Inspector sometimes fails to display attenuation contributions when scrubbing the timeline.
-   **WG-62515** Fixed: (Spatial Audio) CPU usage spikes when profiling Spatial Audio.
-   **WG-62774** Fixed: (Spatial Audio) A 2nd order or higher diffraction path cuts out when the diffraction angle is very small.
-   **WG-62988** Fixed: Possible crash when loading a Profiler session (.prof file) in the Profiler.
-   **WG-63307** Fixed: (Spatial Audio) Possible loss of direct path through portals several rooms away.
-   **WG-63330** Fixed: Unintentional behavior change introduced by fix WG-61727 in Wwise 2021.1.11 and 2022.1.1. Under particular circumstances, Music Switch Containers with destination transitions with a positive fade offset are affected.
-   **WG-63422** Fixed: `[AkArray::Reserve](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=class_ak_array_ae86070a50fcf8a552ce9c2da01d6fceb.html#ae86070a50fcf8a552ce9c2da01d6fceb)` sometimes increases in size when not required.
-   **WG-63475** Fixed: Possible crash when using Paste Properties to copy an object list to one or more target objects.
-   **WG-63493** Fixed: Version Control operation can timeout during SoundBank Generation.
-   **WG-63495** Fixed: Wwise Profiler views are not cleared following a reload of one or more Work Units, which can lead to a crash.
-   **WG-63519** Fixed: WAAPI function calls are slow when no project is open.
-   **WG-63577** Fixed: (Spatial Audio) Diffraction angles for reflections are incorrectly calculated on geometry that has non-uniform scaling.
-   **WG-63580** Fixed: Media Size preview not shown on Sound objects.
-   **WG-63764** Fixed: The presence of feedback aux-send connections in the voice graph causes some non-feedback aux-send connections to go backwards in the Wwise Profiler Voice Graph, resulting in incorrect or non-deterministic mixes during audio rendering.
-   **WG-63769** Fixed: Crash when reloading a Work Unit that includes a State Group or Switch Group used by a Music Switch Container currently inspected in Wwise.
-   **WG-63862** Fixed: Possible crash in Wwise Authoring when changing RTPC curves on Attenuation while connected.
-   **WG-63880** Fixed: Voice Inspector doesn't snap to proper time when moving time cursor backwards with the timeline zoomed in.
-   **WG-63882** Fixed: Crash in AkPath.cpp when terminating engine in low-memory conditions
-   **WG-63887** Fixed: SoundBank Editor shortcut menu item **Open Containing Folder** for Auto-Defined SoundBanks doesn't include an entry for the .bnk file.

-   **WG-58892** Fixed: Imprecision with the panning of mono sounds with non-zero spread and non-zero focus to the back of the listener.
-   **WG-60199** Fixed: Possible crash on connection when using any plug-in that takes a string as a parameter, for example, the Recorder plug-in.
-   **WG-61907** Fixed: Crash when geometries contain invalid triangles.
-   **WG-62393** Fixed: Stereo Delay Effect plug-in does not apply dry gain to height channels.
-   **WG-63034** Fixed: Generic errors are reported when Mastering Suite initialization fails. An invalid channel configuration will now be reported when encountered.
-   **WG-63088** Fixed: Calls to `[AK::SoundEngine::PostMIDIOnEvent()](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ab24b5dc8bd4d1adbdc6aa5c98d94d946.html#ab24b5dc8bd4d1adbdc6aa5c98d94d946)` fail to release some allocated memory.
-   **WG-63242** Fixed: Freeze when generating SoundBanks with WwiseConsole and the option to add the generated files to Source Control is enabled.
-   **WG-63247** Fixed: Successive SoundBank generations can delete the source file(s) for Soundseed Grain plug-ins.
-   **WG-63270** Fixed: Reflect calls internal Wwise sound engine functions, which could result in compatibility issues if the Wwise source is changed. These internal function calls were replaced by calls to the public API.
-   **WG-63379** Fixed: Motion plug-in notice is displayed on project load.
-   **WG-63425** Fixed: Crash in AkConversionTable (RTPC support).
-   **WG-63465** Fixed: There is no longer a button to create new user-defined SoundBanks. The button has been put back, similar to a button that existed in Wwise 2021.1.
-   **WG-63512** Fixed: Assert from [IAkPluginMemAlloc.h](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=IAkPluginMemAlloc.h) header file make debug strings present in optimized targets.
-   **WG-63545** Fixed: Deadlock during a call to UnloadBank when:
    -   A sound stops with a transition during the call to UnloadBank.
    -   The same sound is paused in the same frame as the call to UnloadBank.
-   **WG-63585** Fixed: (Spatial Audio) A slow constant memory leak in the Spatial Audio pool.
-   **WG-63588** Fixed: Possible crash when opening a project that has a circular reference between a Music Event Cue and an Event.
-   **WG-63691** Fixed: Crash when using List View Size Previews in a project with version control integration enabled.
-   **WG-63749** Fixed: Calls to `[AK::SoundEngine::ExecuteActionOnEvent](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ac55e3d6ac464b0579a8487c88a755d8c.html#ac55e3d6ac464b0579a8487c88a755d8c)` perform action on all active MIDI items (starting with `[AK::SoundEngine::PostMIDIOnEvent](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=namespace_a_k_1_1_sound_engine_ab24b5dc8bd4d1adbdc6aa5c98d94d946.html#ab24b5dc8bd4d1adbdc6aa5c98d94d946)`), regardless of the target of the Event's Actions.
-   **WG-63860** Fixed: Crash when closing a Wwise project while a long version control operation is in progress.

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [API Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#api_changes)
-   [Behavior Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#behavior_changes)
-   [Performance Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#performance_changes)
-   [Miscellaneous Changes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#miscellaneous_changes)
-   [Bug Fixes](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#bug_fixes)
-   [Fixes for Community-Reported Bugs](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2022_1_2.html#fixes_for_community-reported_bugs)

_menu_