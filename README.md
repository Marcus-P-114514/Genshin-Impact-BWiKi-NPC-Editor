[We have English version here, click here to switch to English version if you want.](README_EN.MD)

[![standard-readme compliant](https://img.shields.io/badge/version-0.9.1-brightgreen)](https://github.com/Marcus-P-114514/Genshin-Impact-BWiKi-NPC-Editor) [![standard-readme compliant](https://img.shields.io/badge/User%20Guide-https%3A%2F%2Fwiki.biligame.com%2Fys%2FNPC%E5%9B%BE%E9%89%B4%E5%8F%AF%E8%A7%86%E5%8C%96%E7%BC%96%E8%BE%91%E5%B7%A5%E5%85%B7%E7%94%A8%E6%88%B7%E6%96%87%E6%A1%A3-ff69b4)](https://wiki.biligame.com/ys/NPC%E5%9B%BE%E9%89%B4%E5%8F%AF%E8%A7%86%E5%8C%96%E7%BC%96%E8%BE%91%E5%B7%A5%E5%85%B7%E7%94%A8%E6%88%B7%E6%96%87%E6%A1%A3) [![standard-readme compliant](https://img.shields.io/badge/Made%20With-Love-critical)]()
[![standard-readme compliant](https://img.shields.io/badge/Qt%20Version-6.2.4-9cf)]()
# 目录

 - [开发背景](#%E5%BC%80%E5%8F%91%E8%83%8C%E6%99%AF)
 - [分支](#%E5%88%86%E6%94%AF)
 - [安装](#%E5%AE%89%E8%A3%85)
 - [使用教程](#%E4%BD%BF%E7%94%A8%E6%95%99%E7%A8%8B)
 - [主要项目负责人](#%E4%B8%BB%E8%A6%81%E9%A1%B9%E7%9B%AE%E8%B4%9F%E8%B4%A3%E4%BA%BA)
 - [开源协议](#%E5%BC%80%E6%BA%90%E5%8D%8F%E8%AE%AE)
 - [更新日志](#%E6%9B%B4%E6%96%B0%E6%97%A5%E5%BF%97)

# 开发背景

由于编辑NPC需要遵循特定的语法，编辑起来比较麻烦，某些性能较为差的电脑可能会在编辑到一半的时候提示「此页面出现问题，现已重新载入」从而损失未保存的编辑，故而为降低NPC图鉴编辑门槛以及提供一个离线编辑工具，此程序便诞生了。

# 分支
最初的设想是支持全平台，目前正在开发[Windows版](https://github.com/Marcus-P-114514/Genshin-Impact-BWiKi-NPC-Editor/tree/Windows-Version)。

目前，Windows版需要调用另外一个分支中的项目来实现清除缓存，该分支在[这里](https://github.com/Marcus-P-114514/Genshin-Impact-BWiKi-NPC-Editor/tree/Windows-Version-Cache-Cleaner)

# 安装

## Windows版
此为便携版，直接解压缩运行`npc-editor.exe`即可，也可以选择添加快捷方式到桌面以及%ProgramData%\Microsoft\Windows\Start Menu\Programs

如果要自行编译，请先下载分支`Windows-Version-Cache`内的所有文件并放到名为cache的文件夹内，然后编译Windows-Version分支内的项目，命名为`clear-cache.exe`

然后，请下载分支`Windows-Version`内所有文件，以release编译，命名为`npc-editor.exe`。

新建一个空文件夹，把cache文件夹、clear-cache.exe、npc-editor.exe放在一起，进入该目录后，执行：

> windeployqt npc-editor.exe
> windeployqt clear-cache.exe

# 使用教程

请看[用户文档](https://wiki.biligame.com/ys/NPC%E5%9B%BE%E9%89%B4%E5%8F%AF%E8%A7%86%E5%8C%96%E7%BC%96%E8%BE%91%E5%B7%A5%E5%85%B7%E7%94%A8%E6%88%B7%E6%96%87%E6%A1%A3)。

# 主要项目负责人

@Marcus-P-114514

# 开源协议

[### GNU General Public License v3.0](https://github.com/Marcus-P-114514/Genshin-Impact-BWiKi-NPC-Editor/blob/main/LICENSE) (c) Marcus-P-114514

# 更新日志

 - ver 0.9.1：初次提交的版本
