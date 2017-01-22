# 测试的环境设置过程

(1) 下载安装 [Visual Studio Code](https://code.visualstudio.com)；

(2) 下载并安装 [MSYS2 installer](http://msys2.github.io/)（建议使用迅雷下载，浏览器下载巨慢）；

(3)  MSYS 环境更新

*c:\mysy64\msys2_shell.exe*

```bash
# 更新软件数据库
$ pacman --needed -Sy bash pacman pacman-mirrors msys2-runtime
# 更新系统（重新打开 MSYS SHELL）
$ pacman -Syu
```

(4) 安装基本开发环境和常用工具

*c:\mysy64\msys2_shell.exe*

```bash
$ pacman -S  base-devel  git  mercurial  cvs  wget  p7zip  perl  ruby  python2
```

(5) 安装 MinGW-w64

*c:\mysy64\msys2_shell.exe*

```bash
$ pacman -S  mingw-w64-x86_64-toolchain
```

(6) 安装 qt5
*c:\mysy64\msys2_shell.exe*

```bash
$ pacman -S mingw-w64-x86_64-qt5 mingw-w64-x86_64-qt-creator
```

# PATH 环境变量

+ `C:\msys64\mingw64\bin`
* `C:\msys64\usr\bin`

# 参考

+ [Win7 64位中MinGW和MSYS的安装 - yangyangyang20092010的专栏博客频道 - CSDN.NET](http://blog.csdn.net/yangyangyang20092010/article/details/46350519)（过时）

+ [安装MSYS2+MinGW-w64+Qt5](http://www.jianshu.com/p/181e3fe0b545)

+ [在Win7上用MSYS2打造开发环境 - 简书](http://www.jianshu.com/p/91d5448891f6)
