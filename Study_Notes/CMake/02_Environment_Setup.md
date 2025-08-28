# Environment Setup for CMake

## Installing CMake and Ninja on Windows

CMake download link: <a href="https://cmake.org/download/">https://cmake.org/download/</a>

Ninja donwload link: <a href="https://github.com/ninja-build/ninja/releases">https://github.com/ninja-build/ninja/releases</a>

<br>

For CMake installation:

- Download the right msi file for your Windows and perform installation accordingly
- Add the path of CMake application binary file (e.g. C:\\Program Files\\CMake\\bin) as the PATH for Windows system environment variables

For Ninja installation:

- Download the zip package for Windows, and then extracted the package
- Copy the Ninja executable file, and then paste it to the program file path you want [e.g. C:\\Program Files\\Ninja]
- Lastly, remember to add the path of Ninja file copied to as the PATH for Windows system environment variables

## Installing CMake and Ninja on Linux

The steps to be mentioned below in this chapter will be for Ubuntu OS.

If you are using other Linux distributions, may surf the internet for more information.

<br>

For CMake installation: 

- Follow this <a href="https://apt.kitware.com/">link using kitware</a> to perform installation accordingly

For Ninja installation, run the command below:

```bash
sudo apt install ninja-build build-essential
```

## Installing CMake and Ninja on MacOS

CMake download link: <a href="https://cmake.org/download/">https://cmake.org/download/</a>

Ninja donwload link: <a href="https://github.com/ninja-build/ninja/releases">https://github.com/ninja-build/ninja/releases</a>

<br>

For CMake installation:

- Download the right dmg file for your MacOS and perform installation accordingly.
- Drag CMake to Applications
- Add CMake to PATH, so that you can type with terminal
- Or paste the directory path of CMake application to /etc/paths

For Ninja installation:

- Download the zip package for MacOS, and then extracted the package
- Copy the Ninja executable file, and then paste it to the program file path you want
- Lastly, remember to add the path of Ninja file copied to /etc/paths
- Optionally, you can make use of <a href="https://brew.sh/">Home Brew</a> to install using command `brew install ninja-build`