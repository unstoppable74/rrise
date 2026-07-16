## User Experience

## Media Pool

The Media Pool view is where you can search, organize, and select your audio files to import into Wwise. This is invaluable if you have downloaded Strata libraries or are working with third-party sound libraries. These libraries often contain large numbers of files, which can make it time-consuming to find what you need. You can add these library folders to Media Pool databases, and then search for and audition your files directly in Wwise. You can also apply filters as search criteria to further refine the list of results.

After you find the files you want, you can audition them in the Transport area of the Media Pool. Additionally, you can modify the playback properties while auditioning the files and optionally apply these changes when you import them. The Media Pool allows you to import your final selections into your Wwise project, completing the workflow all in the same view, in Wwise. From the Wwise menu bar, click **Project > Media Pool** (Ctrl+P) to open the view.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=mediapool_overview.png)

### Databases

The Databases tab includes the Project Originals folder and the User Databases folder, where you can create User Databases and define the paths to folders that contain audio files. Additionally, you can organize User Databases by grouping them in Virtual Folders and assigning a different color to each one. Use the check boxes to include or exclude folders or databases from the search results.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=mp_databases_tab.png)

### Database Settings

In the Media Pool Database Settings dialog, you can add and remove database folders. You can also rescan databases, which recursively scans the tracked folders for all audio files and adds metadata and extracted audio features to the cache. Audio files in your `Originals` directory are scanned regularly.

### Filters

Use the Filters tab to add, delete, and modify filters that can be included or excluded to refine search results. For Field filters, you can specify which field the filter is operating on, the type of filtering operation, and the text or numeric value of the filter. You can also filter by similar sound or type a description of the sound to filter by. For more information, see [Similar Sound Search](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_new_features.html#features_25_1_similar_sound).

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=mp_filters_tab.png)

### Search

With the **Selected Fields** search type selected, use the search bar at the top of the Results pane to find specific audio files. As you type, the Media Pool searches the metadata in the database files and displays matches in the Results pane.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=mp_search.png)

The Search field supports the following operators to help you pinpoint results:

-   **Exact Phrase**: Use double quotes to find a specific phrase (e.g., "footstep medium").
-   **Exclude Words**: Use a hyphen or exclamation mark to remove unwanted results (e.g., "footstep !concrete").
    -   Exact phrases can also be excluded

To select which Metadata fields to search, click the gear icon to the right of the Search field. The Filename field is selected by default.

Optionally, you can select the **Audio Description** search type and then type a description of a sound in the search bar. For more information, see [Similar Sound Search](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_new_features.html#features_25_1_similar_sound).

### Results

The Results pane displays a list of audio files based on your search and filter criteria. The best matches appear at the top of the list. Use the Results shortcut menu to add audio files to the Audio File Importer or to import them directly into the Default Work Unit in your project. You can also change the order of the columns and configure them to display various Metadata Fields, Search Score, and Waveform.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=mp_results.png)

### Metadata

The Metadata pane displays all discovered metadata for a selected file. When you create a database and specify a path on your local drive or network drive, the Media Pool caches the metadata for each file. Caching this metadata facilitates fast searches through your libraries and allows you to filter results precisely. Metadata Fields can be added as a column or filter using the shortcut menu when selecting a Metadata Field.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=mp_metadata_field.png)

### Transport Properties

When auditioning files in the Media Pool, you can use the Transport properties to modify Volume, Pitch, Low-pass Filter, and High-pass Filter. The Loop check box loops playback within detected regions. You can apply any of these changes when importing the file.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=mp_transport.png)

### Audio Preview/Region Selector

The Audio Preview/Region Selector pane allows you to preview and play back audio. You can also select regions and add files to the Audio File Importer. When files are imported, a corresponding object is created in the project. If multiple regions are selected, an object is created for each region. You can manually select regions by clicking and dragging on the waveform or by clicking the markers embedded in the audio file. Hold Ctrl or Shift to select multiple regions. When you enable the **Auto-select detected regions** button, regions are automatically selected based on the measured energy of the audio content. You can edit regions by dragging the blue boxes.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=mp_auto_preview.png)

| _info_ | **Note:** Manual edits to selected regions are not persisted when you select a different file in the Results pane. |
|------|----------------------------------------------------------------------------------------------------------------|

When you import a region, the entire audio file is imported to the project `Originals` folder and objects are created in the project at the Object Destination with the selected region applied as trim start and trim end on the audio file source. When you import more than one region, each region is saved with a number appended to the object name. For example, if you import three regions in the same file, each region is saved as an object with "\_01", "\_02", and "\_03" appended to the end of each object name.

Click **Files** or **Regions** to populate the Audio File Importer, where the Object Type and Object Destination can be further specified.

### Similar Sound Search

Similar Sound Search allows you to search for sounds in your Media Pool databases using either a text query or a reference audio clip. This removes the need for keyword tagging and time-consuming manual navigation through vast sound libraries. It was designed specifically for sound effects and discovers unexpected matches that would be difficult to find using conventional search methods. For example, a sound labeled "smashing fruit" might be found as a match for the query "footsteps in mud."

In particular, Similar Sound Search allows for:

-   **Text-to-audio retrieval**: In the list to the right of the Search field, select **Audio Description** and then type a description of the desired sound. Results are chosen based only on their audio content.
-   **Audio-to-audio retrieval**: Right-click any file in the Results pane and click **Find Similar**. The sonic qualities of the file are used as a reference to find similar results.

In both cases, Similar Sound Search provides a new way to find audio, even if it was recorded for a different purpose. These two techniques enrich traditional filtering, which depends on metadata, extending the possibilities of existing sound libraries.

Similar Sound Search uses a non-generative machine learning model to place audio and text into a shared search space where sounds are grouped by acoustic and semantic similarity. It is an optional package you can add to Wwise using the Audiokinetic Launcher.

## Merging and Renaming of Hierarchies

### Goodbye Actor-Mixer Hierarchy and Interactive Music Hierarchy, Hello Containers!

The merging of the Interactive Music Hierarchy and Actor-Mixer Hierarchy under a shared Containers hierarchy is the first step toward bringing object types closer together as part of a shared sound, music, and voice design hierarchy. While this change preserves the way that containers have always operated, it paves the way for future opportunities to continue growing and sharing similar workflows across object types.

### Goodbye Actor-Mixer, Hello Property Container!

Simultaneously, the Actor-Mixer has been renamed Property Container to clearly reflect its use as a way to assign properties that can be inherited. This change comes in response to feedback we've received from early learners identifying the difficulty in accessing terminology that doesn't exist in other tools and isn't easily associated with the intended behavior.

### Goodbye Master-Mixer Hierarchy, Hello Busses!

Additionally, the Master-Mixer Hierarchy has been renamed Busses, in the same spirit of using a name that clearly relates to the contents of the hierarchy. A new top-level Audio Bus will be created as New Main Audio Bus, which marks the removal of the last instance of the term “Master” in the Wwise codebase. This shared initiative comes in collaboration with requests from developers working to remove controversial and insensitive terminology from their pipelines. For the same reason, the Master-Mixer Console has been renamed Busses Console.

### Goodbye Audio Devices, Hello Devices!

Last but not least, Audio Devices has been renamed Devices. It's shorter and has no spaces!

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=25_1_hierarchy.png)

### Project Folder Structure Migration

Migrating from an older version of Wwise results in the following changes:

-   "Audio Devices" renamed to "Devices"
-   "Master-Mixer Hierarchy" renamed to "Busses"
-   "Actor-Mixer Hierarchy" renamed to "Containers"
-   "Interactive Music Hierarchy" moved to a Virtual Folder in the Containers hierarchy and renamed "Music (Migrated)"

See [Important Migration Notes 2025.1](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=whatsnew_2025_1_migration.html) to understand how these changes affect your project and the integration of WAAPI in your workflow.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=project_structure_migration.png)

## Event Limiting

The ability to limit instances is a fundamental design and optimization strategy at the core of the voice pipeline. It now expands to include the ability to limit Events. You can limit an Event on either a global or game object scope. When the limit is reached, no additional Events are posted. You can also define a Cooldown Time, after which the Event can be posted again.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=event_limiting.png)

Limiting Event instances can be useful in cases where the game engine is requesting many of the same Events for playback simultaneously, but you only want one or a few Events to be posted by Wwise. A common scenario is a physics simulation, where a single impact might result in dozens of requests to post the same Impact Event. While there are scenarios where creating a system to limit the posting of Events from the game engine is still considered best practice, Event Limiting is now within reach as part of the workflow in Wwise.

## RTPC Mute/Solo

Auditioning Real Time Parameter Controls (RTPCs) now includes the ability to mute and solo their influence at the point of use. You can also mute and solo RTPCs when connected to a game as part of a live editing workflow. It works the same way it does for audio and makes it easy to hear the contribution RTPCs have on the resulting sound.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=rtpc_mute_solo.png)

## Audio File Importer View

The Audio File Importer is now a non-modal view that can be docked in any layout. The view also has new menus, buttons, and drag-and-drop capabilities.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=afi_view.png)

## Property Editor Improvements

Thanks to feedback from the community, the Property Editor continues to evolve in the direction of greater usability. The introduction of the vertical Property Editor in Wwise 2024.1 was a step toward greater accessibility.

### Resizing

Improvements have been made to the visual styling of the property categories and property layout, including adjustments to font size. Additionally, the center divider has been removed in favor of automatic horizontal resizing of the property columns.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=pe_resizing.png)

### Favorites Defaults

The Favorites category now includes common properties for each object type by default. These properties might be familiar to anyone who has used previous versions of Wwise, because they are similar to the properties that were presented in the General Settings tab of the legacy Property Editor for each object.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=favorites_default.gif)

### Keyboard Navigation of Properties

You can now use the Tab key to move focus from one property to the next. Use Shift+Tab to navigate in reverse order.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=pe_keyboard_navigation_one.png)

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=pe_keyboard_navigation_two.gif)

### Expandable Notes

Notes fields in the Property Editor are often used to help lend context to implementation decisions, communicate clearly about uses, and sometimes serve as a way for teams to find specific objects using the Wwise Search. Notes fields now expand to present the entire contents, improving visibility.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=expanded_notes.png)

### Default Editor Stability

Navigating between different object types has been unified to consistently present the Default Editor when selecting an object.

### Editor Usability Updates

We added context menus and refined the user experience working with Groups in the following editors:

-   Switch Container Editor
-   Sequence Container Editor
-   Music Playlist Editor

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=group_selection.png)

## Multiband Meter

Using the existing Meter Effect to output a Game Parameter leverages dynamics to control properties throughout the audio hierarchy. The Multiband Meter is a new Effect that expands on this by metering not only the full band of an incoming audio signal, but also four separate user-configured frequency bands.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=multiband_meter.png)

## Sidechaining

Sidechaining has arrived as a suite of plug-ins and additions to existing plug-ins. It allows you to monitor and apply audio signals to dynamically control the mix.

### Sidechain Mixes

Sidechain mixes have been added as a new system and ShareSet type in Wwise. They make it possible for Effect plug-ins to send and receive audio signals that are separate from the voice graph, allowing audio rendering to combine multiple disparate audio signals.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=sidechain_mixes.png)

The Sidechain Mix ShareSet can be used to identify and define a sidechain mix. The sidechain mix receives audio signals from one or more Sidechain Send Effects, and can be read by the Sidechain Receive Effect, or used as a Sidechain Input on other Effects, such as the Compressor and Expander.

### Sidechain Send Effect

The Sidechain Send Effect can be used on an Audio Bus or Aux Bus to send an audio signal to a Sidechain Mix ShareSet.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=sidechain_send.png)

### Sidechain Receive Effect

The Sidechain Receive Effect can be used on an Audio Bus or Aux Bus to receive the audio signal from a Sidechain Mix ShareSet. This is useful for testing purposes because it simply monitors the audio signal from an accumulated sidechain mix and uses that audio signal as an output of the Effect's processing.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=sidechain_receive.png)

### Improved Compressor and Expander Effects

The Compressor and Expander Effects now allow for the use of a sidechain mix to dynamically control the input audio signal. For example, the Compressor Effect reduces the volume of the input audio signal when the audio signal of the specified sidechain mix increases in volume.

You can now scale the Gain Reduction meter range between -3 dB and -96 dB. This makes it easier to monitor small gain reductions in the input audio signal.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=compressor.png)

## Improved Parametric EQ

The Parametric EQ plug-in has been radically expanded to make it more powerful and easier to use in many scenarios.

The plug-in now supports up to eight bands of filters for processing as well as some new modes of filtering. A new EQ Graph allows for easier configuration and interactive preview of the Parametric EQ properties, such as dragging control points around to modify the frequency, gain, and Q of each EQ filter. The graph shows not only the frequency response of each band, but also the accumulated effect of all of the bands.

In addition to previewing the accumulated frequency response of all the EQs, the plug-in also provides a visualization of the runtime EQ curve when profiling the sound engine, taking into account any RTPCs applied during execution of the Effect. You can also listen to, or solo, specific bands of audio in isolation, making it easier to preview exactly which portion of the audio mix will be affected by a specific EQ Band. This lets you shape your audio mix with greater clarity, precision, and speed.

A suite of dynamics-related functionality has also been added to the plug-in. An audio signal can now be used to automatically modify the EQ curve at runtime. By measuring the intensity of an audio signal in each band, the plug-in can automatically increase or decrease the gain of the corresponding band in a user-configurable manner. As well, the Parametric EQ can measure not only the in-line audio signal to drive the dynamics, but also a Sidechain Mix.

When a Sidechain Mix is used, this effectively brings frequency-based sidechaining to the Parametric EQ, allowing for dynamic equalization across multiple bands of the audio spectrum. The ability to automatically modulate frequency bands using audio from a separate Sidechain Mix opens up the possibilities to dynamically control the frequency of sounds in relation to other sounds that are playing. This is an important tool for preventing the buildup of frequencies across different categories of sounds or as a way to create unique equalization effects in response to other aspects of the mix.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=parametric_eq.png)

## External Source - WAV Playback

The External Source plug-in can now load WAV files without the need to convert them to WEM format.

With the External Source plug-in, a source audio file that is not part of a SoundBank can be loaded dynamically at runtime for playback. This plug-in is particularly useful for scenarios with large numbers of sounds, such as dialogue in multiple languages.

## speechEngine by ReadSpeaker

ReadSpeaker's speechEngine for Wwise is a cross-platform, on-device text-to-speech plug-in that creates natural-sounding speech from any text input. You can send text from the game at runtime to be converted into speech, for example, user interface narration or multiplayer text chats. You can customize the voice and adjust speech parameters like pitch and speed in Wwise Authoring while keeping the prosody intact. speechEngine for Wwise currently supports 10 languages and 12 voices, with more languages and voices planned for future releases.

speechEngine also produces word and viseme data, and notifies you when a new word or viseme is encountered in the speech. This can be used to implement word-highlighting or lip-sync functionality. It also supports Speech Synthesis Markup Language (SSML).

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=readspeaker.png)

ReadSpeaker is committed to delivering ethical AI-powered voice solutions. Learn more about their approach to ethical AI voices in gaming [here](https://www.readspeaker.com/blog/ethical-ai-voice-for-gaming).

See [speechEngine for Wwise](https://www.audiokinetic.com/en/wwise/plugins/readspeaker/) for further details on this plug-in, which is also supported in Wwise 2024.1.5, Wwise 2023.1.13, and later.

## WAQL Accessor Additions

Several Wwise Authoring Query Language (WAQL) accessors were added:

-   `workunitIsLoaded`: Returns true if a Work Unit is currently loaded in the project.
-   `musicTransitionObject`: Returns the transition Music Segment associated with the current Music Transition object.
-   `switchGroupGameParameter`: Returns the Game Parameter object associated with the current Switch Group object.
-   `customStates`: Returns the list of the current object's custom states that have a defined value.
-   `originalNonLFEChannelCount`: Returns the total number of channels in the original file, excluding low-frequency channels.
-   `originalAmbisonicsChannelCount`: Returns the total number of ambisonics channels of the original file associated with the current object.
-   `convertedNonLFEChannelCount`: Returns the total number of channels in the converted file, excluding low-frequency channels.
-   `convertedAmbisonicsChannelCount`: Returns the total number of ambisonics channels of the converted file associated with the current object.
-   `convertedSampleRateSetting`: Returns the selected sample rate settings of the converted file, expressed as a string.
-   `convertedTrimmedDuration`: Returns the duration in seconds of the trimmed converted audio source associated with the current object.
-   `isLanguageIncluded`: Returns true if the audio source object's parent includes the audio source's language.
-   `conversionFormat`: Returns the codec of the file associated with the current object.
-   `supportsStates`: Returns true if the object supports the use of States on any of its properties.
-   `supportsRandomizer`: Returns true if the object supports the use of a Randomizer on any of its properties.
-   `hasEmptySwitchStateAssignment`: Returns true if there are empty objects or paths assigned on Switch Containers and Music Switch Containers.
-   `extractEvents`: Returns the Event objects referenced by the SoundBank object.
-   `extractStructures`: Returns the object structures referenced by the SoundBank object.
-   `extractMedia`: Returns the paths of the media files referenced by the SoundBank object.
-   `soundbanksReferencingEvent`: Returns the SoundBank objects referencing the current Event object.

## Plug-in Unit Test Framework

A unit test infrastructure has been added, which can be included when you create plug-in projects. It allows you to develop your own unit tests. The plug-in project includes templates for two tests: one for the sound engine plug-in implementation and another for the parameters it uses. The unit tests are automatically built alongside your plug-in when you use the `wp.py` build command and can be launched with the `wp.py test` command. See [Unit Testing Your Plug-in](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=effectplugin_tools_unittest.html) for more information.

## Integrations

## Unity Wwise Browser

The Wwise Browser has replaced the Wwise Picker in the Wwise Unity Integration. The Wwise Browser includes various filters that you can use to easily identify the status of SoundBanks and the associated Wwise Project. You can use the context menu to navigate the Wwise project from within Unity and perform transport control operations, among others. See Managing Assets with the Wwise Browser for details.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=unity_wwise_browser.png)

## Unreal Dynamic Dialogue

Dynamic Dialogue in Wwise uses a set of rules in a decision tree to determine which sound to play at any particular moment in game. It is a flexible way to determine which sound to play, as decided by user-defined path associations as part of a Dialogue Event. It is a way to use States and Switches to choose the best sound. The benefits of the Dynamic Dialogue system include familiar setup using State and Switch associations, object sharing without containers, granular asset management, and runtime flexibility. For more information about Dynamic Dialogue in Wwise, see [Managing dynamic dialogue](https://www.audiokinetic.com/library/edge/?source=Help&id=managing_dynamic_dialogue).

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=unreal_dyn_dialoque.png)

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=footstep_dialogue.png)

The dynamic dialogue system is composed of two systems:

-   Dialogue Events, which contain decision-tree structures that resolve to audio nodes.
    -   Dialogue Events consist of paths of Switch and State Groups that resolve into an assigned object in one of two ways: through the provision of Switch and State values, or through a default path.
-   Dynamic Sequences, are associated with regular game objects (AkComponents in Unreal) that contain sequential playlists of resolved audio nodes.
    -   A Dynamic Sequence is a playlist of audio nodes bound to a game object. It is similar to a game-controlled music playlist container, or to a sequence container.

The _audio nodes_ that these systems use are any objects in the Containers Hierarchy that can be played in a regular Event, such as sound effects, voices, and containers.

Features include:

-   Dynamic Dialogue features are available as C++ functions and Blueprint Nodes
-   Dialogue Events can be imported through the Wwise Browser, like any other type of Event.
-   Dialogue Events can be previewed using the default path.
-   Path Arguments can be defined.
-   Argument can be added to the Resolve operation.
-   Audio Nodes can be added to Dynamic Sequence Playlists.

## Unreal Packaging Improvements

Changes to Packaging in Unreal have been made to 2024.1 and 2025.1:

-   Improved Unreal Modular Gameplay Feature Experience
    -   Extended DLC Support
    -   Auto-defined SoundBanks included in the correct packages

## Gym Improvements

Gyms provide Wwise projects that function as sandbox environments for developers. Test Wwise features in Unreal, Unity, or a custom integration before implementing them in your games. Demonstration Gyms are available for a wide variety of Wwise features.

In this release, Gym stability was improved, and Unity Gyms now use Unity Addressables (in parity with Unreal Packaging) by default.

## Spatial Audio: Acoustics

## Dual-Shelf Filter

The addition of a dual-shelf filter (DSF) supports physical accuracy while producing a more realistic perspective of distant sounds. The DSF is also well-suited for situations where tone control is preferred over the more dramatic filtering effects that the LPF provides. The DSF combines low and high shelf filters into one filter with computational complexity equivalent to that of LPF or HPF. This filter has characteristics that better approximate acoustic effects like diffraction and works well with attenuation curves. When used as part of diffraction or obstruction, DSF creates a more natural filtering experience. In early feedback gathered during Alpha testing, developers found the Dual Shelf Filter faster to set up, applicable across different content types, and better suited for the realistic representation of sound propagation over distance.

### High-Frequency Gain

High-frequency gain is the main control parameter of the DSF. Changing this parameter changes the gain of the high-frequency band. The following figures show the effect of the filter with varying gain. Note that gains can also be positive, resulting in a boost in the high-frequency band as opposed to an attenuation.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=high_frequency_gain.png)

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=dsf_response_by_gain.gif)

The following properties change the high-frequency gain:

-   Output Bus

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=dsf_output_bus.png)

-   Game-Defined Auxiliary Sends

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=dsf_aux_send.png)

-   Attenuation ShareSets

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=dsf_att_sharesets.png)

-   Reflect plug-in

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=dsf_reflect.png)

### DSF Emphasis

The DSF Emphasis property changes the shape of the DSF transition region. Its range is -1 to +1 and its default is 0.

The following graphs show the effect of DSF Emphasis in various settings. In the first graph, the high-frequency gain is set to -20 dB. In the second graph, the high-frequency gain is set to +10 dB.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=dsf_emphasis_one.png)

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=dsf_emphasis_two.png)

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=dsf_gain_minus20.gif)

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=dsf_gain_plus10.gif)

  
Higher DSF Emphasis results in a greater filtering effect, that is, greater attenuation in the mid-band frequencies.

DSF Emphasis is a global property that you can change in the Project Settings.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=dsf_project_setting.png)

DSF behavior is additive. When multiple DSFs are present along a signal's path, the high-frequency gains are summed. For example, if a voice goes through a distance DSF with -2 dB high-frequency gain, and then a diffraction DSF with -1 dB high-frequency gain, and then finally goes through the Output Bus DSF with -3 dB high-frequency gain, the effective high-frequency gain is -6 dB. Moreover, as an optimization, the sound engine only processes one DSF with a high-frequency gain of -6 dB, as opposed to processing three different DSF instances.

## Project Environmental Curves ShareSet

Environmental Curves at the project level are now defined by an Attenuation ShareSet specified in the Project Settings. This makes it easier to modify the Project Environmental Curves at runtime while maintaining the ability to optionally override or remove the inheritance of individual curves on a per-Attenuation basis. It also makes it easier to share Environmental Curves across projects. Additionally, new projects target a default set of physically-based Environmental Curves that provide a realistic starting point for acoustic simulation.

| _info_ | **Note:** Although the referenced Project Environmental Curves ShareSet contains distance curves, they are not used at the project level. Environmental curves include Obstruction, Occlusion, Diffraction, and Transmission curves. This feature also makes it possible to create Attenuation ShareSets with the distance volume curve set to **None**. |
|------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=project_env_curves.png)

## Game Object 3D Viewer Updates

The Game Object 3D Viewer is the best way to visualize the relationship between game objects, emitters, geometry, and acoustics information in a single view. Now you can easily customize the display of data in the Game Object 3D Viewer using the new Settings Toolbar. The settings are grouped in categories: View, Text, Game Object, and Acoustics. Each category includes options whose visibility and visibility properties can be toggled, modified, and pinned. You can also select objects in the center pane and the new Object Properties panel on the right provides information about the selected object.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=go3d_new_settings.png)

| ![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=Callout1.png) | **Scene Filtering**: Filter the Game Objects list for desired objects. Only the list is affected. For example, in the image above, the list is filtered for "emitter", but Rooms and the listener are still visible in the 3D Viewer. Also, rows are hidden instead of removed. You can access the filtered out rows by expanding the Game Objects list. Show or hide game objects in the 3D Viewer using the eye icon next to each game object in the list. There are additional actions you can select in the context menu, such as **Show Only Selected in the 3D Viewer**. |
|-----|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=Callout2.png) |                                                                                                           **Options Toolbar**: The 3D Viewer options used to be in a separate window. They are now in a toolbar above the 3D Viewer. The toolbar is customizable. It has categories of options that can be toggled in and out, and each category opens a list of options that can be pinned to the toolbar. In the image, we see a selection of pinned options.                                                                                                            |
| ![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=Callout3.png) |               **Object Selection**: You can select game objects, acoustic paths, and image sources in the 3D Viewer. When an object is selected, information is displayed in the Selection Property pane. For emitters, the selection properties include: Type, Position, Virtual Voices, Outer Radius, Inner Radius, and Room. Emitters also select their corresponding direct path. Acoustic path properties include Emitter, Path Length, Diffraction %, Transmission Loss, Obstruction %, Occlusion %, Spread %, Aperture %, Gain, and Node Information.               |

## Improved Reflect Plug-in

Properties in Reflect have been organized into the following groups: General, Warping, Doppler, Phasing, and Output. You can also add the properties you use most to the new Favorites category.

Additionally, the following improvements have been made to the properties in the Doppler group:

-   Distance Smoothing has been renamed Delay Smoothing and applies a smoothing filter to each reflection time.
-   Pitch Threshold has been renamed Pitch Limit and sets the maximum allowable Doppler pitch shift (in cents).
-   Delay Error Tolerance has been added to set the maximum allowable discrepancy between the effective delay and the desired delay.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=reflect_doppler.png)

**Same As Main Mix** and **Same As Passthrough Mix** have been added to the list of possible Output Configs. **Same as Main Mix** is now the default Output Config.

## Emitter Clustering (Experimental)

Emitter Clustering for acoustics is an experimental feature that aims to improve the performance of reflection and diffraction path computation by grouping emitters to reduce the number of calculations needed. The feature divides the space centered around the listener into a radial grid and then assigns each emitter to a grid cell, grouping them based on angle and distance. Clusters of emitters that are closer to the listener are smaller, with less chance of emitters being grouped, providing a higher degree of accuracy for closer sounds. Clusters of emitters that are farther away from the listener are bigger, with a greater chance of emitters being grouped. Once grouped, reflection and diffraction paths can be computed.

## Dynamic Load Balancing

Dynamic Load Balancing continuously distributes acoustic tasks in relation to the amount of processing power available at any given time. This automatically optimizes the trade-off between latency and throughput for acoustic path calculation. Different acoustic tasks, such as path finding, raycasting, clustering, reflection path validation, and diffraction, can be spread across processing frames dynamically corresponding to available CPU resources. When CPU usage is low, more acoustics tasks can be processed simultaneously. When CPU usage is high, acoustic tasks can be distributed across processing frames. This method replaces the CPU Limit, which attempted to dynamically adjust the value of NumberOfPrimaryRays.

Dynamic Load Balancing is a product of the CPU Limit and the Load Balancing Spread initialization settings. If there is no CPU Limit, load balancing remains constant at that setting. If there is a CPU Limit, the Load Balancing Spread setting is dynamically increased and attempts to minimize the CPU%; in this case the Load Balancing Spread value is used as a maximum value. If CPU usage is low, the Load Balancing Spread does not increase, but if the if the CPU usage rises to a high level for a period of time, the CPU load is dynamically balanced to compensate.

Dynamic Load Balancing properties are available in `[AkSpatialAudioInitSettings](https://www.audiokinetic.com/en/public-library/2025.1.9_9197/?source=SDK&id=struct_ak_spatial_audio_init_settings.html "Initialization settings of the spatial audio module.")`. For the Wwise Unity and Unreal Integrations, they are in the project settings.

## Room Distance Behavior

`AKSpatialAudioVolume` adds a Distance Behavior property to Rooms that determines how the Room interacts with other Rooms that it overlaps or is nested within.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=distance_behavior.png)

**Subtract**: When set to Subtract, the child Room is subtracted from the shape of the parent Room, along with any overlapping Rooms of lower priority. In this case, distance attenuation is applied to other Rooms when the listener is in this Room, because this Room is a distinct space.

In this example, the listener doesn't hear the Room Tone of the parent Room because the child Room is set to "subtract" the shape of the Room and apply distance attenuation.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=room_subtract.png)

| ![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=Callout1.png) | Parent Room |
|-----|-------------|
| ![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=Callout2.png) | Child Room  |
| ![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=Callout3.png) |  Listener   |

**Exclude**: When set to Exclude, the Room does not participate in the distance calculation of other Rooms. Distance attenuation does not apply to this Room's parents, or overlapping sections of lower priority Rooms, because this Room does not form a distinct space and is not subtracted from the shape of other Rooms.

In this example, the listener hears the Room Tone of the parent Room with no attenuation because the child Room is set to "exclude" the shape of the Room from the distance calculation.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=room_exclude.png)

| ![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=Callout1.png) | Parent Room |
|-----|-------------|
| ![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=Callout2.png) | Child Room  |
| ![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=Callout3.png) |  Listener   |

## Spatial Audio: 3D Audio

## Recorder (ADM) Plug-in - Experimental

The Recorder (ADM) is an experimental Effect plug-in that records the signal passing through an audio object-format bus. The content is saved to a WAV file in ADM format, which records multiple beds and individual 3D objects with animation. The plug-in can be used both in Wwise Authoring and in-game.

The channel count of the WAV file is fixed for the duration of the recording. The channels are allocated to main mix, passthrough mix, extra beds, and individual audio objects as needed. In addition to the standard assignment rules, when **Preserve Extra Beds** is enabled, objects with no 3D Spatialization and no speaker panning are not mixed.

When **Hold** is enabled, a single file is created during a recording session, even if there are periods of silence.

![](https://www.audiokinetic.com/images/2025.1.9_9197/?source=SDK&id=recorder_adm_overview.png)

## Sound Engine

## Behavioral Rewrite

Significant work has been done to rewrite behavioral aspects of the Wwise sound engine to optimize playback across multiple systems. These changes are fundamental to the continued scaling of the sound engine in support of future workflows and game engine features.

## Command Buffer API

Some games frequently send a high volume of data to the sound engine. For example, games with a lot of game objects and game syncs send hundreds of values to the sound engine at regular intervals. Although you can manage this data transfer using the existing C++ API, the new C-compatible, fully asynchronous Command Buffer API has the following benefits:

-   It minimizes both CPU usage and memory allocations for large data transfers.
-   It is fully compatible with any C11 compiler, and therefore its functions can be bound directly to other programming languages that have FFI (foreign function interface) capabilities, such as Rust.

Among other features, you can use the Command Buffer API to:

-   Group Events (PostEvent/SetRTPC).
-   Package "commands" in a single buffer (or frame).
-   Register calls, for example, Post and SetPosition.

This release introduces functions that will be expanded in future releases.

## Platform Support

We added support for Nintendo Switch 2 in Wwise 2024.1.5 and later.