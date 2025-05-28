# Manipulating Files Attributes

Before proceed to the sub-topics, below is the sample picture of `ls -l` output.

<img src="images/ls-l_cmd_sample_output.png" alt="Samput output of ls -l command">

In this chapter, `File Type` and `File Permission` will be the main topics to be studied.

## Identify File Type

| Character | File Type |
|:---:|:---:|
|`-`| Regular file |
| `l` | Symbolic link |
| `c` | Character special |
| `b` | Block special |
| `p` | Named pipe |
| `s` | Socket |
| `d` | Directory file |

### Regular Files

- Most common type of files you will encounter
- Store any kind of data, where it could be plain text, application-specific format or a special binary format that system can execute
- To help you what understand what data type is stored in regular file, just execute this sample command `file <FILENAME>`

### Symbolic Links

Symbolic link is a special file that points to another file on the system. 

It is `similar to shortcut or alias` if familiar with Windows or Mac OS.

Symbolic links `can point to any type of file or directory`.

If you run `ls -l` command, you will see the sample filename format as below if it is a symbolic link or commonly called `symlink`.

<img src="images/ls-l_symlink_output.png" alt="ls -l output for a symbolic link">

<br>

Use the command `ln -s <SOURCE> <SYMLINK>` to create symbolic link

### Device Files

Device files are access points to the device within the file systems.

Usualy, device files are located under `/dev` directory.

2 main types of device files are:
- Character special files
- Block special files

### Character Special Files

Character special files provide a mechanism for `communicating with a device one character at a time`. 

Usually, character devices represent a "raw" device.

<img src="images/ls-l_character_special_output.png" alt="ls -l output for a character special file">

Above is the sample picture of ls -l output for a character special file.

### Block Special Files

Block special files also provide a mechanism for communicating with device drivers via the file system, but `transfer large blocks of data at a time`.

This type of file typically represents hard drives and removable media.

<img src="images/ls-l_block_special_output.png" alt="ls -l output for a block special file">

Above is the sample picture of ls -l output for a block special file.

### Major Number VS Minor Number

For device drivers, you will see major number and minor number when running `ls -l` command in device file.

| Category | Explanation |
|:---:|---|
| Major Number | Major number is a `unique identifier` assigned to a device driver in the Linux kernel. <br><br> Each device driver has a unique major number, which is used by the kernel to identify the device and determine which driver to use when a device is accessed. <br><br> The major number is also known as `device number` or `device major`. <br><br> Major number of the device can be checked in `proc/devices`. |
| Minor Number | Minor number is a `smaller identifier` that is used in conjunction with the major number to uniquely idetify a specific device within a class of devices. <br><br> Minor numbers are used to identify specific devices within a major device class, such as `different partitions` on a hard disk drive or different USB drives. |

