![](https://img.shields.io/badge/Build-Passing-brightgreen?style=plastic) ![](https://img.shields.io/badge/Version-3.1.0-blue) ![](https://img.shields.io/badge/Qt-5.12.12-green) ![](https://img.shields.io/badge/Made%20with-Love-red) ![](https://img.shields.io/badge/User%20Guide-https%3A%2F%2Fwiki.biligame.com%2Fys%2FNPC%E5%9B%BE%E9%89%B4%E5%8F%AF%E8%A7%86%E5%8C%96%E7%BC%96%E8%BE%91%E5%B7%A5%E5%85%B7%E7%94%A8%E6%88%B7%E6%96%87%E6%A1%A3-ff69b4)
中文版 | [English](docs/readme_en.md)
## 目录
- [开发背景](#开发背景)
- [开发状态](#开发状态)
- [安装](#安装)
- [使用](#使用)
- [贡献者](#贡献者)
- [更新日志](#更新日志)
- [许可证](#许可证)

## 开发背景
由于编辑NPC需要遵循特定的语法，编辑起来比较麻烦，某些性能较为差的电脑可能会在编辑到一半的时候提示「此页面出现问题，现已重新载入」从而损失未保存的编辑，故而为降低NPC图鉴编辑门槛以及提供一个离线编辑工具，此程序便诞生了。

## 开发状态
| 平台 | 架构  | 状态 |
| ------------ | ------------ | ------------ |
| Windows | x86_64 | ![](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge) |
| macOS |  x64 | ![](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge) |
| Linux | x86_64 | ![](https://img.shields.io/badge/Build-Failed-critical?style=for-the-badge) |
| Android | AArch64 | ![](https://img.shields.io/badge/Build-Pending-yellow?style=for-the-badge) |
| iOS | AArch64 | ![](https://img.shields.io/badge/Build-Pending-yellow?style=for-the-badge) |

## 安装
- Windows版：解压Zip中的所有内容到所需位置即可。
- macOS版：挂载`.dmg`文件，拖拽其中`.app`文件至`/Applications`文件夹即可。
- Linux版：需要自行Build。
- Android版：使用PackageManager安装即可。
- iOS版：需要注意的是，所提供的`.ipa`文件**不提供签名**，请使用计算机签名后安装到本机。

## 使用
本程序自带支持文档，请阅读[使用文档](docs/manual/zh-cn/index.md)，或者转到[这里](https%3A%2F%2Fwiki.biligame.com%2Fys%2FNPC%E5%9B%BE%E9%89%B4%E5%8F%AF%E8%A7%86%E5%8C%96%E7%BC%96%E8%BE%91%E5%B7%A5%E5%85%B7%E7%94%A8%E6%88%B7%E6%96%87%E6%A1%A3-ff69b4)以获取在线版。

## 贡献者
本程序的问世离不开各位的努力，特别感谢以下开发者对本程序的支持：
| 分工 | 贡献者|
| ------------ | ------------ |
| 程序 | 屑机主 |
| 程序  | Gaoily |
| 美工  | 大猫雷恩 |
## 更新日志
- **v.1.0**：这个版本仅提供纯文本编辑（外加代码高亮），以及集成了一些额外小工具来帮助您快速在本地编辑NPC图鉴。
- **v.1.1**：更新界面并且支持了拖拽文件。
- **v.1.2**：加入了对特殊字符插入的支持。
- **v.2.3.2**：重构代码，新增了可视化编辑。
- **v.2.3.5**：适应WIKI模板新参数。
- **v.2.3.6**：修复了读取工程文件时不显示特定参数的问题且可以默认打开工程文件，此版本未推送/发布。
- **v.3.1.0**：重构代码，更新了用户界面，支持NPC模板中新增的「心声」参数，此更新仍在进行中。

## 许可证
[GNU General Public License v2.0](LICENSE)