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

Wwise SDK 2025.1.9

Audiokinetic aims to provide you with the highest quality software. However, be aware of the limitations and known issues in this version of Wwise.

## Wwise Limitations

The following list describes the limitations in this version of Wwise.

-   3D Spatialization
    -   When performing 3D spatialization of standard multichannel sounds, a hard-coded channel layout is expected for any given number of channels (excluding LFE). The hard-coded layouts are as follows:

| Number of channels |                   Layout                   |
|--------------------|--------------------------------------------|
|         1          |                     FC                     |
|         2          |                   FL-FR                    |
|         3          |                  FL-FR-FC                  |
|         4          |                FL-FR-SL-SR                 |
|         5          |               FL-FR-FC-SL-SR               |
|         6          |             FL-FR-BL-BR-SL-SR              |
|         7          |            FL-FR-FC-BL-BR-SL-SR            |
|         8          |           FL-FR-FC-BL-BR-SL-SR-T           |
|         9          |        FL-FR-FC-BL-BR-SL-SR-HFL-HFR        |
|         10         |      FL-FR-FC-BL-BR-SL-SR-HFL-HFC-HFR      |
|         11         |    FL-FR-FC-BL-BR-SL-SR-HFL-HFR-HBL-HBR    |
|         12         |  FL-FR-FC-BL-BR-SL-SR-HFL-HFC-HFR-HBL-HBR  |
|         13         | FL-FR-FC-BL-BR-SL-SR-T-HFL-HFC-HFR-HBL-HBR |

-   Ambisonics
    -   Speaker panning has no effect on ambisonics voices/busses.
    -   Balance-Fade panning of voices/busses with standard channel configurations (mono, stereo, 5.1, and so on) has no effect when encoded in ambisonics.
    -   The Matrix Reverb does not support ambisonics configurations.
    -   When processing ambisonics, the RoomVerb's Front, Rear, and Center levels are ignored for late reverberation, and the Center level is ignored for early reflections.
-   Audio Busses  
    -   If you are ducking a bus that is playing a series of short sounds within a looped sequence container set to Continuous, you may experience a loss in ducking between the short sounds or at the loop point of the container. To avoid this behavior, you can either add sample accurate transitions between the sounds within the container, or set the ducking recovery time to anything but zero.
    -   On Android 8.0 and above, busses with the "Mute for Background Music" property will not be unmuted when another app playing music in Picture-in-Picture mode is dismissed without the Wwise app losing focus. The app must lose focus in order to restore BGM music properly when it is resumed.

# Wwise Limitations

-   Audio Devices
    
    -   **WG-50870** Audio stuttering on Windows when using Spatial Sound to output to headphones plugged into an Xbox controller.
    
    -   **WG-84368** On Android, the "Screen record" feature cannot record the app audio when using some low-latency output configurations. See [Controlling Latency on Android](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=pg_android_fastpath.html) for an in-depth explanation of low-latency configuration options on Android.
    
    -   Audio File Management
        -   The audio pipeline uses real-time sample rate conversion nodes when playing sounds that differ from the platform's native sample rate (48 kHz for Windows). To prevent possible conversion rate aliasing artifacts, content that does not require pitch-shifting such as music should be converted to match that of the native platform. For Windows, it is also possible to have a native format of 24 kHz using the audio quality option that is available from the SDK.
        -   The Vorbis encoder library may result in poor audio quality for sounds using sample rates below 16 kHz. The Vorbis codec was specifically tuned for higher sample rates and performs very well above 16 kHz. Audio quality below the 16 kHz sampling rate, however, can vary considerably depending on the encoding settings used and the audio asset itself.
        -   Minor artifacts may result when the Wwise loop fixing algorithm specified in some formats' conversion settings is applied. These artifacts, which result from slight time-stretching or pitch-shifting in the algorithm, are less noticeable for sources with a long duration.
        -   During the audio conversion process, loop regions that are shorter than the sample boundaries (format-specific) are removed.
        -   Looping music clips may lose timing accuracy each time the loop point is crossed due to loop fixing. However, the Play and Stop position in the segment are always sample accurate.
        -   **WG-30292** The SoundBank definition file for the Init SoundBank ('Init.txt') contains a listing of State Groups for each State that is included in a project. However, unless there is a transition time associated with a State Group, Init.bnk does not - and does not need to - contain any information about the State Group. Adding or renaming a State Group will not modify the contents of the Init.bnk, and will therefore not require a regeneration of Init.bnk. The generation of 'Init.txt' is tied to the generation of the 'Init.bnk'. To force 'Init.txt' to reflect an added or renamed State Group and to be regenerated when the contents of 'Init.bnk' have not changed, it must be manually deleted.
    -   Containers  
        -   Although you may use a Switch Container as a child of a random or sequence container with sample accurate transitions, transitions will not be sample accurate if the Switch Container plays more than one sound simultaneously.
        -   Containers with trigger-rate transitions cannot, by definition, be sample-accurate. Thus, if they are children of a container with sample accurate transitions, they may play out-of-sync.
        -   The maximum number of children in any type of container is 65,535. Although Wwise lets you create more than 65,535 in the authoring application, no parent-child link can be made between the parent and the child above this limit. Without the link, these child objects cannot receive any notification updates during playback, including changes to volume, positioning, and so on.
        -   There are several restrictions and limitations that currently exist when using the crossfade, sample accurate, and trigger rate transitions with random and sequence containers. For more information on using crossfade transitions, refer to the Wwise User Guide's [Using caution with crossfade transitions](https://www.audiokinetic.com/library/2025.1.9_9197/?source=Help&id=managing_crossfades#using_caution_with_crossfade_transitions).
        -   If the playback instance limit is reached for a Random or Sequence Container using Trigger Rate as the transition type, the currently playing sound as well as the container itself will be killed.
        -   Fade transition on a Resume action applied to a Random or Sequence Container using Trigger Rate as the transition type will be ignored.
    -   Effects
        -   Since you cannot apply a crossfade when bypassing or unbypassing an Effect, you may experience clicking when using the Enable/Disable Bypass Event Action.
        -   For motion Effects, trigger motors (Default and Xbox One) cannot be activated from the Wwise authoring tool. Only a PC UWP application can use them.
    -   Interactive Music
        -   A Music Switch transition rule cannot use both the options **Sync To - Same Time as Playing Segment** and **Use transition segment**. Whenever **Use transition segment** is enabled, **Sync To - Entry Cue** is used instead.
        -   The Break event action has no effect on interactive music objects (Music Segments, Music Switch Containers, and Music Playlist Containers). Its functionality may be reproduced with the help of a music switch container.
        -   The empty space on a track before a clip will be considered as the clip's pre-entry, possibly causing music transitions to occur later.
        -   Run-time sample rate conversion makes sounds longer by approximately 12 samples per minute, causing slight inconsistencies for music objects. Sources in the following sample rates are affected: 44100 Hz, 22050 Hz, 11025 Hz.
        -   The wave data displayed in the Music Segment Editor for a converted file represents the original file and not the converted file.
        -   A Music Event Cue with a SetState action may yield unknown results.
    -   Live Edition
        -   Some operations are not allowed during playback or when connected to a game, but are erroneously possible to edit using the List View or the Multi-Edit features. These operations include:
            -   Modifying the Output bus or the Override bus option.
            -   Enabling/Disabling voice limitation system.
        -   Editing these during playback could cause instability in the game and could require restarting the sound engine to recover.
    -   Positioning
        -   If you add or remove a point along the path during playback, the sound will continue to play, but there will be no propagation. The next time you play back the sound, the changes that you made will be applied.
    -   Projects  
        -   When a project is saved to a mapped network drive, performance may be seriously affected. If you decide to save your projects to a mapped network drive, Audiokinetic will not support these projects.
    -   Remote Connections
        -   If the IP address of a computer changes while the Remote Connections dialog box is open, the computer will be displayed in the Available list using the LAN IP address instead of the usual "Local Host" IP address. If you connect to this computer, this computer will be added to the History list using the LAN IP address even if the same computer is already in the list using the "Local Host" IP address. Wwise doesn't recognize that these two entries are the same remote computer. The next time you use Wwise, both entries will remain in the History list. Despite the duplication, you can connect to the computer using either entry.
        -   For information on troubleshooting the remote connection, refer to the Wwise Help list entitled "Troubleshooting Remote Connection Issues" found in the page "Profiling Tips and Best Practices".
    -   SDK  
        -   Debug versions of the Wwise SDK sample effect and source plug-ins cannot be used with the Wwise authoring tool.
    -   Streaming
        -   Streamed external sources are ignored by the caching system.
        -   A soft deadlock may occur when running out of memory in the Stream Manager pool while profiling, as the I/O thread may flood the profiling queue with out-of-memory notifications.
    -   Video Drivers
        -   Older versions of AMD Radeon drivers might cause Wwise to crash when opening / creating a project. Ensure that the latest drivers are installed.
    -   Voice Behavior
        -   In order to save performance, an estimate of the total Voice volume is computed before starting a Voice. (Starting a voice includes streaming, instantiating Effects, and instantiating the mixing Bus hierarchy.) The estimate does not take the volume of mixing Busses or Auxiliary Sends into account. Consequently, voices with virtual voice behavior set to Kill Voice may be immediately killed even when the Bus volume on the output Bus would cause the voice to be above threshold at the time of playback. Likewise, when the output Bus volume is below the threshold but there is an Aux Send, then the voice is killed instantly when played. However, if the sound is playing and then the output Bus volume drops below the threshold, then the sound is - as expected - not killed.
    
    ## Wwise Known Issues
    
    The following list describes the relevant outstanding issues that could not be resolved in this version of Wwise.
    
    -   Audio Files  
        -   **WG-11260**: Audio from file with too many markers fails to play. If the marker data chunk in the file header is larger than the granularity of the file streaming, the code fails to read the header.
        -   **WG-54888**: Audio file paths are case insensitive: it is undefined which representation will be used as reference in output files.
        -   **WG-68171**: A marker set at the very end of an audio file can fail to be processed by the sound engine depending on the sample rate of the converted audio file.
    -   Contents Editor
        -   **WG-14785**: Objects displayed in the Contents Editor are not sorted alphabetically, which can make it difficult to find objects quickly.
    -   Conversion Settings ShareSets
        -   **WG-67907**: There are no Factory Conversion Settings ShareSets for the Opus audio file format. If you need to use Opus, you have to create your own Conversion Settings ShareSet in Wwise Authoring.
    -   Decoded SoundBanks
        -   **WG-30133**: (tvOS only) It is not possible to save locally decoded SoundBanks.
    -   Game Object 3D Viewer
        -   **WG-16246**: The Game Sync Monitor doesn't update as expected until you add or remove a watch from the Watches list.
        -   **WG-45998**: Maximizing the Authoring on a HIDPI monitor set as secondary monitor will cause the Game Object 3d Viewer to go entirely black. Setting the HIDPI monitor as the primary monitor prevents this issue.
    -   Interactive Music
        -   **WG-14711**: Two 'bar', 'beat' or 'grid' notifications may be sent in a row at segment synchronization points.
        -   **WG-15728**: When a transition segment is added to the Any to Any transition and then removed, the music segment and corresponding media file is still included in the SoundBank, in error.
        -   **WG-16269**: Effect tails are trimmed when effects are inserted in interactive music objects (Music Segments, Music Switch Containers, and Music Playlist Containers).
    -   Integration Demo
        -   **WG-40445**: The Android Gradle project for IntegrationDemo will fail to build if located under a path containing spaces (such as "Program Files").
    -   Keyboard Shortcut manager
        -   **WG-19947**: OS keyboard shortcuts using the "Windows" key can't be remapped in Wwise.
    -   Motion
        -   **WG-14852**: Motion FX objects do not work as expected within a Dialogue Event.
        -   **WG-38787**: Xbox One controllers are not working properly in the authoring tool due to compatibility issues between the controller and the Windows driver. We suggest using Xbox 360 controllers instead.
        -   **WG-69519**: On macOS and iOS-based devices, the Motion output device drops the first few audio frames of non-zero vibration data in order to reduce CPU usage.
        -   **WG-69092**: On Windows, using the Motion output on an XInput controller connected over bluetooth may result in significant degradation in performance or audio crackling due to voice starvation, which can vary significantly from user to user. You can observe this issue in the CPU Timeline or other profiling tools, which might show that CAkLEngine::SoftwarePerformEpilogue takes a long time to be executed. Some observed symptoms include the following:
            -   The function takes an extra 2 milliseconds per tick to execute
            -   The function takes up to 8 milliseconds to execute if called more than 120 times per second, which can happen if [AkInitSettings::uNumSamplesPerFrame](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_init_settings_a2438a18ece872c83175f70d7f70d659b.html#a2438a18ece872c83175f70d7f70d659b "Number of samples per audio frame (256, 512, 1024, or 2048).") is set to a value lower than 400.
    -   Multi-Channel Creator
        -   **WG-16302**: Sample loop markers within a source file are not kept in the multi-channel files generated by the Multi-Channel Creator.
    -   Obstruction/Occlusion
        -   **WG-15678**: When updating the Obstruction/Occlusion curves in Wwise while connected to a game, the curve information is not propagated to the game, as expected.
    -   Offline Rendering
        -   **WG-57383**: If you enable the offline rendering sample script before play mode has been entered, there will be no sound. If you enable it after play mode has been entered, you will hear audio being rendered, however, it will be choppy.
        -   **WG-57403**: The main output device remains silent after disabling offline rendering without restarting the sound engine.
    -   Playback Limit  
        -   **WG-15124**: Playback limit involving Motion busses may continue to be applied even though it is grayed out in the Wwise application.
        -   **WG-43108**: Playing the same sound on the same game object repeatedly while:
            -   using "offset priority by <X> at max distance", and
            -   the game object is in motion, and
            -   the number of sound instances is already over the specified limit can end up killing the newest or oldest inaccurately. This is a side effect of an optimization system that prevents the accumulation of new sound instances triggered by the user that would flood the system with instances that, in the end, would not play.
    -   Profiler  
        -   **WG-15476**: Error message missing in the profiler when Wwise detects two similar media files that don't have the same size.
        -   **WG-15617**: When an error occurs in the profiler, Wwise displays the Event ID, but not the Event name.
    -   Property Editor
        -   **WG-41324**: Changing properties that turn a non-mixing bus into a mixing one (and vice-versa) while a sound is playing through it may cause volumes to be updated incorrectly. Restarting playback fixes the issue.
    -   RTPCs
        -   **WG-14506**: Audio glitches may occur when using a Peak Limiter as well as a Parametric EQ that has an output level driven by an RTPC.
        -   **WG-43798**: Audio glitches may occur while transitioning the volumes from multiple control positions very abruptly in different directions (quieter and louder); it may result in a momentarily non constant gain. For example, if a sound is under the influence of 2 volume transitions, where one is going from 0dB to +50dB and the other one is going from 0dB to -50 dB in a very short amount of time (few ms), the transition frame gain may not be accurately 0dB.
    -   SDK/Sound Engine  
        -   **WG-15501**: Memory address may be reused by Switch container after a game object is unregistered causing Wwise to play a different sound than is expected.
        -   **WG-16185**: Speaker volume matrix callback is not called for 2D sounds in IsInitiallyUnderThreshold.
    -   Source Plug-ins
        -   **WG-16232**: Clipping may occur when using the Pink or Red noise color setting within the Soundseed Air Woosh source plug-in.
    -   Source Control
        -   **WG-15558**: When using the Perforce plug-in, the file history scrolls unnecessarily as the information is received.
        -   **WG-15559**: When using the Perforce plug-in, the history returned by P4 truncates the description removing useful information.
        -   **WG-16257**: Wwise may crash when loading a work unit that includes an audio source with a space at the beginning of its filename.
        -   **WG-20587**: Issues may arise when creating nested Work Units whose path on disk exceeds MAX\_PATH (255) characters.
    
    The following list describes the limitations specific to this version of the Wwise Authoring Tool for Mac®.
    
    -   Audio File Importer:
        -   **WG-23920**: Mac Authoring Tool: Cannot import WAV files in Wwise using CTRL-Drag and Drop/CTRL-SHIFT Drag and Drop.
    -   Audio File Management:
        -   **WG-24779**: Mac Authoring Tool: Prevent moving WAV files outside the "Originals" folder and give an error message.
    -   Crankcase Audio REV:
        -   **WG-29775**: Mac Authoring Tool: Users cannot use Crankcase Audio REV.
    -   Custom Commands:
        -   **WG-58714**: Mac Authoring Tool: Cannot redirect output of Unix programs.
    -   Keyboard Shortcuts:
        -   **WG-25129**: Mac Authoring Tool: Wwise keyboard shortcuts are broken when using the Japanese "Romaji" and "Katakana" input sources.
    -   Layout/Toolbar/View:
        -   **WG-22214**: Mac Authoring Tool: Wwise layouts get messed up when you use the Mac OS X window management buttons.
        -   **WG-22217**: Mac Authoring Tool: White borders appear when you display/resize a floating view.
    -   Mac OS X version specifics:
        -   **WG-25990**: Mac Authoring Tool: When connecting a Bluetooth or HDMI audio device, the audio doesn't switch automatically to the new device.
    -   Motion:
        -   **WG-22220**: Mac Authoring Tool: Wwise CRASH when you close the Wwise Motion Generator Source Editor.
    -   Platforms:
        -   **WG-22234**: Mac Authoring Tool: Select "Mac" as default platform on Mac OS X.
    -   Projects:
        -   **WG-22237**: Mac Authoring Tool: Cannot open a Wwise project by double-clicking the \*.WPROJ file.
    -   Project Explorer:
        -   **WG-24807**: Mac Authoring Tool: Object name color doesn't update automatically in the Project Explorer when you delete a WAV file in the MacOS Finder.
    -   Project Settings:
        -   **WG-22244**: Mac Authoring Tool: Source Control plug-ins (Perforce and Subversion) are not supported.
    -   RTPCs:
        -   **WG-22231**: Mac Authoring Tool: There's no anti-aliasing on RTPC curves.
    -   SoundBanks:
        -   **WG-24974**: Mac Authoring Tool: Edit box content does not update properly when you edit the SoundBanks Path or Pre/Post Generation Steps.
        -   **WG-26291**: Mac Authoring Tool: The File Packager is not supported on Mac.
        -   **WG-60466**: Mac Authoring Tool: Unix programs are not supported in Pre/Post Generation Steps.
        -   **WG-65713**: Auto-defined SoundBanks do not support Dynamic Dialogue Events. Dynamic Dialogue Events must be placed in user-defined SoundBanks.
    -   SoundBank Manager:
        -   **WG-22243**: Mac Authoring Tool: Pressing the ESC key in the SoundBank Manager User Settings dialog clears its content instead of closing it.
    -   Audio Definition Model Support (Experimental)
        -   Bed channel order must follow the Dolby Atmos Master profile (see [Dolby Atmos ADM Profile specification](https://professionalsupport.dolby.com/s/article/Dolby-Atmos-ADM-Profile-specification?language=en_US)). The height channels in the 7.0.2 and 7.1.2 bed configurations are interpreted as Front height channels.
        -   The panning algorithm used for 3D positioning in the Wwise sound engine produces different results than the Cartesian Point Source Panner used in Dolby Atmos, especially with sounds close to the listener.
        -   Width, Height, and Depth are linearly mapped to Spread, and Spread corresponds to an object in which all three components are 1.0.
        -   The ADM audio data is treated as a multi-channel Anonymous configuration by Effects inserted on the Sound or Clip.
        -   The following metadata is not supported:
            -   Screen Scaling
            -   Screen Edge Lock
            -   Channel Lock
            -   Divergence
            -   Zone Exclusion
            -   Gain
            -   Diffuse
    

___

#### Was this page helpful?

_thumb\_up_ Yes _thumb\_down_ No

#### Tell us about your project. We're here to help.

Register your project and we'll help you get started with no strings attached!

[Get started with Wwise](https://www.audiokinetic.com/register-project/)

-   [Wwise Limitations](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_known_issues.html#wwise_limitations)
-   [Wwise Known Issues](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_known_issues.html#wwise_known_issues)

_menu_