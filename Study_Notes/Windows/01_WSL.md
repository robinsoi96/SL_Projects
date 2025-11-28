# WSL (Windows Subsystem for Linux)

## Introduction

WSL, or Windows Subsystem for Linux, is a **feature in Windows that lets you run a Linux environment directly on Windows without needing a virtual machine or dual-booting**.

For more details regarding WSL, may refer to this <a href="https://learn.microsoft.com/en-us/windows/wsl/">link</a>

## Prerequisites

You need to have Windows 10 version 2004 and higher (Build 19041 and higher) or Windows 11, to have WSL.

### WSL1

- Virtualization not required to be enabled in BIOS menu

- Must enable `"Windows Subsystem for Linux"` under "Windows Feature" 

- Or run the below command in PowerShell as Administrator, and then restart:

    ```powershell
    dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
    ```

### WSL2

- Virtualization is required to be enabled in BIOS menu

- Must enable `"Windows Subsystem for Linux"` and `"Virtual Machine Platform"` under "Windows Feature" 

- Or run the below commands in PowerShell as Administrator, and then restart accordingly:

    ```powershell
    dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
    ```

    ```powershell
    dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart
    ```

- **NOTE:** It might not work well with most VMs which need to disable Windows virtualization feature to avoid conflict.

For more information on comparison between WSL1 and WSL2, please refer to this <a href="https://learn.microsoft.com/en-us/windows/wsl/compare-versions">link</a>.

## Installation

Run the command below to perform WSL installation with PowerShell in administrator mode:

```powershell
wsl --install
```

This will by default install Ubuntu for you.

But if plan to change the default Linux distribution installed, can run the command below:

```powershell
wsl --install -d <DistroName>
```

To check available Linux distro available, can run this command:

```powershell
wsl --list --online
```

## Appendix

All most documentation related WSL, can refer <a href="https://learn.microsoft.com/en-us/windows/wsl/">here</a>