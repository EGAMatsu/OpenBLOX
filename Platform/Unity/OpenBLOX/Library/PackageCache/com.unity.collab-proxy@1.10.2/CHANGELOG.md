# Changelog
All notable changes to this package will be documented in this file.

## [1.10.2] - 2021-08-27

Plastic SCM for Unity is now available as part of the Version Control Package! You can enable Plastic SCM via Window > Plastic SCM to get started!
If you have previously used the Unity Asset Store Plastic SCM plug-in, you can now simply use this package. Make sure you delete the plug-in from your project.
Removing a previously added Plastic SCM Asset Store Plug-In:
- Select the PlasticSCM folder in the Assets\Plugins folder on the Project tab, then click Edit > Delete
- Close the Unity Editor and open your project again. You will find the Plastic SCM menu item in the Window menu.

### Added
- Added horizontal scroll bar to Changesets list for easier viewing
- Added auto-login for SSO credentials handler
- Added metrics for changeset tab usage
- Added metrics for checkin actions
- Added new Undo icon
- Added missing API documentation
- Added ability to modify assets without checkout
- Added ability to allow empty checkin messages
- Added empty checking message localization
- Added Plastic toolbar button to Unity editor
- Added notification icon for incoming changes to Plastic toolbar button

### Changed
- Removed the unneeded refresh button from History Tab
- Moved search bar to the top right global icon section in all tabs
- Updated capitalization of options in the Settings context menu
- Updated tab button styling to be consistent with Unity Editor conventions
- Status bar visible across all tabs
- Moved refresh button to the toolbar at the top right corner of the window
- Moved changesets time period selector to the right corner of the window
- Removed "Changes of changeset" header on the Changesets tab
- Moved number of selected items next to "Item" metadata title on the Pending Changes tab
- Improved refresh icon resolution
- Changed changesets detail to appear in vertical column
- Reduced default number of columns in changesets tab
- The number of changesets is no longer displayed in changesets tab
- Changed Launch branch explorer into an icon with tooltip
- Removed the hide changes button in changesets tab
- Moved incoming change prompt and button into a status bar
- Changed "Launch Plastic" to "Launch Plastic SCM" in options menu
- Wording change for plastic installation
- Updated file status icons

### Fixed
- Fixed a bug where the Texture2D error would pop up after downloading a project
- Fixed a bug when context menu would sometimes disappear
- Fixed small textbox on checkin dialog when launched from context menu
- Fixed a workspace NullReferenceException bug
- Fixed notification icon not showing on Plastic window
- Fixed auto login errors not showing up for users
- Fixed unexpected error message after user switched workspace to a label

## [1.8.0] - 2021-07-13

Plastic SCM for Unity is now available as part of the Version Control Package! You can enable Plastic SCM via Window > Plastic SCM to get started!
If you have previously used the Unity Asset Store Plastic SCM plug-in, you can now simply use this package. Make sure you delete the plug-in from your project.
Removing a previously added Plastic SCM Asset Store Plug-In:
- Select the PlasticSCM folder in the Assets\Plugins folder on the Project tab, then click Edit > Delete
- Close the Unity Editor and open your project again. You will find the Plastic SCM menu item in the Window menu.

### Added
- Added Checkin and Update confirmation notification
- Added auto sign in when logged into Unity account

### Changed
- Simplified UI: decluttered UI
- Improved load time performance

### Fixed
- Fixed view not switching to workspace after creating an Enterprise Gluon workspace
- Fixed contextual menu not showing up in project view
- Fixed SSO renew token after password change
- Fixed some namespace collisions with Antlr3

## [1.6.0] - 2021-06-25

Plastic SCM for Unity is now available as part of the Version Control Package! You can enable Plastic SCM via Window > Plastic SCM to get started!
If you have previously used the Unity Asset Store Plastic SCM plug-in, you can now simply use this package. Make sure you delete the plug-in from your project.
Removing a previously added Plastic SCM Asset Store Plug-In:
- Select the PlasticSCM folder in the Assets\Plugins folder on the Project tab, then click Edit > Delete
- Close the Unity Editor and open your project again. You will find the Plastic SCM menu item in the Window menu.
### Added
- Added support for inviting other members. This option is available from the gear / settings icon.
- Added support for signing in with Cloud Edition. This is available during the onboarding screen if you have never signed in.
- Added support for turning off Plastic in their project. This option removes the Plastic metadata from your directory. This option is available under Assets > Plastic SCM > Turn off Plastic SCM
- Added notification on the Plastic SCM tab title to indicate incoming changes. Users will no longer need to have the Plastic SCM window visible to know there are incoming changes.
- Auto configuration of SSO
- Added date column in incoming changes
### Changed
- Updating license to better conform with expected customer usage.
- Updated documentation file to meet standards.
- Updated third-party usage.
- No longer requires downloading of the full Plastic client. Basic features will work without additional installation. Features that require the full Plastic client will allow download and install as needed.
- Usability improvements around checking in code
- Improved update workspace tab UX
- Plastic SCM context menu is now available even if the Plastic SCM window is closed
### Fixed
- Stability and performance improvements

## [1.4.9] - 2021-06-03
### Unreleased
- The Version Control package will be expanding to include both Collaborate and Plastic SCM version control interfaces. This release is preparing for that move and contains no new functionality or bug fixes for Collaborate.
### Changed
- Collaborate Package renamed to Version Control with changes to package display name and description.
- Updating license to better conform with expected customer usage.
- Updated documentation file to meet standards.
- Updated third-party usage.

## [1.2.16] - 2019-02-11
Update stylesheet to pass USS validation

## [1.2.15] - 2018-11-16
Added support for non-experimental UIElements.

## [1.2.11] - 2018-09-04
Made some performance improvements to reduce impact on ReloadAssemblies.

## [1.2.9] - 2018-08-13
Test issues for the Collab History Window are now fixed.

## [1.2.7] - 2018-08-07
Toolbar drop-down will no longer show up when package is uninstalled.

## [1.2.6] - 2018-06-15
Fixed an issue where Collab's History window wouldn't load properly.

## [1.2.5] - 2018-05-21
This is the first release of *Unity Package CollabProxy*.

### Added
- Collab history and toolbar windows
- Collab view and presenter classes
- Collab Editor tests for view and presenter
