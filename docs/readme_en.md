![](https://img.shields.io/badge/Build-Passing-brightgreen?style=plastic) ![](https://img.shields.io/badge/Version-3.1.0-blue?style=plastic) ![](https://img.shields.io/badge/Qt-5.12.12-green?style=plastic) ![](https://img.shields.io/badge/Made%20with-Love-red?style=plastic) ![](https://img.shields.io/badge/User%20Guide-https%3A%2F%2Fwiki.biligame.com%2Fys%2FNPC%E5%9B%BE%E9%89%B4%E5%8F%AF%E8%A7%86%E5%8C%96%E7%BC%96%E8%BE%91%E5%B7%A5%E5%85%B7%E7%94%A8%E6%88%B7%E6%96%87%E6%A1%A3-ff69b4?style=plastic)

[中文版](readme.md) | English
## Table of Contents
- [Background](#Background)
- [Status](#Status)
- [Installation](#Installation)
- [Usage](#Usage)
- [Contributors](#Contributers)
- [Changelog](#Changelog)
- [License](#license)

## Background
Due to editing the WIKI using NPC template requires the mastery of certain syntax, and editing using some outdated laptop may return the error "There was a problem with this page, it has been reloaded" (then the editor loses all the work). In order to making the editing process easier and provide an offline editor, this project was launched.

## Status
| Platform | Architecture | Status |
| ------------ | ------------ | ------------ |
| Windows | x86_64 | ![](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge) |
| macOS |  x64 | ![](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge) |
| Linux | x86_64 | ![](https://img.shields.io/badge/Build-Failed-critical?style=for-the-badge) |
| Android | AArch64 | ![](https://img.shields.io/badge/Build-Pending-yellow?style=for-the-badge) |
| iOS | AArch64 | ![](https://img.shields.io/badge/Build-Pending-yellow?style=for-the-badge) |

## Installation
- Windows: Extract all files from the archive to somewhere you want.
- macOS: mount the `.dmg`file and drag the `.app` file to `/Applications`.
- Linux: Build is required.
- Android: Install with native PackageManager.
- iOS: Please note that the `.ipa` provided is **without sign** and one needs to sign the application oneself, then install to their devices.

## Usage
We provided [manual](docs/manual/en-us/index.md) here, or you can visit [here](https%3A%2F%2Fwiki.biligame.com%2Fys%2FNPC%E5%9B%BE%E9%89%B4%E5%8F%AF%E8%A7%86%E5%8C%96%E7%BC%96%E8%BE%91%E5%B7%A5%E5%85%B7%E7%94%A8%E6%88%B7%E6%96%87%E6%A1%A3-ff69b4) to use the online version.

## Contributers
Special thanks to following developers who contribute to this project: 
| Job | Contributer|
| ------------ | ------------ |
| Programming | 屑机主 |
| Programming | Gaoily |
| UI Design | 大猫雷恩 |
## Changelog
- **v.1.0**: This version provides plain text and syntax highlighting feature to help one editing the NPC.
- **v.1.1**: UI update and the drag & drop opreation is supported.
- **v.1.2**: Implementation of the "Insert special character" function.
- **v.2.3.2**: Rebuild all the code and implemented the visual editor.
- **v.2.3.5**：Update to support the parameter of NPC template.
- **v.2.3.6**: fixed an error that caused by reading the project file and supports to open the project file by default. This version is not commited to GitHub/released.
- **v.3.1.0**: Rebuild all the code and will support the new parameter of NPC template. Updated the user interface and is currently been building.

## License
[GNU General Public License v2.0](LICENSE.md)