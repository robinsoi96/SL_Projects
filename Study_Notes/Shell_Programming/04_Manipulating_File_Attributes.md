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