# win-bright

An application implemented in GTKMM4 for controlling brightness in `Windows` Desktops at software level by adjusting GammaRamp values.

## Table of Contents
1. [Issues](#issues)
2. [Setup](#setup)
    1. [Proxy Setup](#proxy-setup) 
    2. [Installations](#installations)
    3. [Setting up Code::Blocks Compiler](#setting-up-codeblocks-compiler)
    4. [Setting up Code::Blocks Project](#setting-up-codeblocks-project)
3. [VSCode](#vscode)
4. [Releases and Downloads](#releases)

<br/>
<hr/>
<br/>

## Issues

Refer [issues](https://github.com/charitra1022/win-bright/issues) for more detail on current and resolved issues

<br/>
<hr/>
<br/>

## Setup

To run this project, some things need to be setup.

<br/>


### Proxy Setup
If you are using a proxy server, then type the following commands on the **MSYS2** terminal by replacing the placeholders (on first line only) with your proxy details.
```
export HTTP_PROXY="username:password@proxy.server.address:port"
export HTTPS_PROXY=$HTTP_PROXY
export http_proxy=$HTTP_PROXY
export https_proxy=$HTTP_PROXY
```

<br/>


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

<br/>



### Setting up Code::Blocks Compiler

1. Open **Compiler** Settings.

    ![compiler1.png](/screenshots/compiler1.png)

2. Setup **mingw** compiler from *msys2* as default compiler in codeblocks.
`C:\msys64\mingw32` for x32 bit and `C:\msys64\mingw64` for x64 bit

    ![compiler2.png](/screenshots/compiler2.png)

<br/>
<br/>

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


<br/>
<hr/>
<br/>

## VSCode
For working with **vscode**, all above setup should be done. After that, install [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack).
Once installed, the setup will be done automatically as all the required setup files are present already in the [.vscode](/.vscode) folder.

Run the **main.cpp** file.
![vscode1.png](/screenshots/vscode1.png)

Select **GTK: Build executable** option in run options.
![vscode2.png](/screenshots/vscode2.png)

And the project files will be created in **obj** (as *main.o* file) and **bin** (as *main.exe* file) folders.

VSCode is just helpful for writing code as its better than Code::Blocks in terms of **syntax highlighting** and **autocomplete**.

Executables can also be created using Code::Blocks build and run method which is recommended over the vscode building.


<br/>
<hr/>
<br/>

## Releases
Visit the [releases](https://github.com/charitra1022/win-bright/releases) page for downloading the latest version or view release notes.

