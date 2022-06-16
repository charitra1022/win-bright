## WinBright

A desktop application for Windows computers made in GTK4 and GTKMM to control screen brightness at software level.
It manipulates the GammaRamp values obtained from the GDI+ API of the Windows API for setting the brightness at software level.


## Table of Contents
1. [Issues](#issues)
2. [Setup](#setup)
    1. [Installations](#installations)
    2. [Setup Compiler](#setting-up-codeblocks-compiler)
    3. [Setup Project](#setting-up-codeblocks-project)
3. [Releases and Downloads](#releases)

## Issues

Refer [issues](https://github.com/charitra1022/win-bright/issues) for more detail on current and resolved issues

## Setup

To run this project, some things need to be setup.

### Installations

1. Install [MSYS2](https://www.msys2.org/)
2. Open **MSYS2** and run `pacman -Syu`
3. Open **MSYS2** and run `pacman -Syu` again.
4. Open **MSYS2** and run the following commands one by one:

    For x64 compiler and builds

   ```
   pacman -S --needed base-devel mingw-w64-x86_64-toolchain
   pacman -S pkgconf
   pacman -S mingw-w64-x86_64-gtk4
   pacman -S mingw-w64-x86_64-gtkmm-4.0
   pacman -S pkgconf
   ```

    For x32 compiler and builds

   ```
   pacman -S mingw-w64-i686-toolchain
   pacman -S pkgconf
   pacman -S mingw-w64-i686-gtk4
   pacman -S mingw-w64-i686-gtkmm-4.0
   pacman -S pkgconf
   ```

5. Add the follwing to path on your system.
   
    For x32 bit
   ```
   C:\msys64\mingw32\bin
   ```
   For x64 bit
   ```
   C:\msys64\mingw64\bin
   ```

### Setting up Code::Blocks Compiler

1. Open **Compiler** Settings.

    ![compiler1.png](/screenshots/compiler1.png)

2. Setup **mingw** compiler from *msys2* as default compiler in codeblocks.
`C:\msys64\mingw32` for x32 bit and `C:\msys64\mingw64` for x64 bit

    ![compiler2.png](/screenshots/compiler2.png)

### Setting up Code::Blocks Project

**Option 1: Cloning the master branch.**

Clone the master branch and open the **win-bright.cbp** file with codeblocks.

**Option 2: Creating a new project.**

1. Create a **C++** **console** application project in codeblocks.

    ![compiler3.png](/screenshots/compiler3.png)

    ![compiler4.png](/screenshots/compiler4.png)

    ![compiler5.png](/screenshots/compiler5.png)

    Give any **title** to the project.

    ![compiler6.png](/screenshots/compiler6.png)

    ![compiler7.png](/screenshots/compiler7.png)

2. Setup project build options. Right click the **project name** in Workspace pane.

    ![compiler8.png](/screenshots/compiler8.png)

    Click on **Other Compiler Options** and paste the following code:
   ```
   `pkgconf --cflags gtk4`
   `pkgconf --cflags glib-2.0`
   `pkgconf --cflags glibmm-2.68`
   `pkgconf --cflags gtkmm-4.0`
   `pkgconf --cflags gdkmm-2.4`
   ```
    ![compiler9.png](/screenshots/compiler9.png)

    Click on **Linker Settings** and paste the following code, and click **OK**:
   ```
   `pkgconf --libs gtk4`
   `pkgconf --libs glib-2.0`
   `pkgconf --libs glibmm-2.68`
   `pkgconf --libs gtkmm-4.0`
   `pkgconf --libs gdkmm-2.4`
   -static-libgcc -static-libstdc++ -mwindows
   ```
    ![compiler10.png](/screenshots/compiler10.png)


## Releases
Visit the [releases](https://github.com/charitra1022/win-bright/releases) page for downloading the latest version or view release notes.
