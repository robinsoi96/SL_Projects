# Vim Editor

Vim editor is 1 of the most common test editor used in Linux system.

If vim ediotr, you can opt to install it

## 3 Modes in Vim Editor

There are 3 modes:
- Command mode
- Insert mode (edit mode)
- Extended command mode

**NOTE: When you open the vim editor, it will be in the command mode by default**

### Command Mode

Below are some basic way to implement in command mode

| Key | Command Mode Action|
|:---:|---|
| `gg` | Go to the beginning of the page |
| `G` | Go to the end of the page |
| `w` | Move the curosr forward, word by word |
| `b` | Move the cursor backward, word by word |
| `nw` | Move the cursor forward to n words <br><br>E.g `4w` --> move cursor backward to 4 words |
| `nb` | Move the cursor backward to n words <br><br> E.g. `4b` --> move cursor backward to 4 words |
| `u` | Undo the last change (word) |
| `U` | Undo the previous changes (entire line) |
| `Ctrl + R` | Redo the changes |
| `yy` | Copy a line |
| `nyy` | Copy n lines <br><br> E.g. `4yy` ---> Copy 4 lines |
| `p` | Paste the line below the cursor position |
| `P` | Paste the line above the cursor position |
| `dw` | Delete  the word letter by letter (like Backspace) |
| `x` | Delete the word letter by letter (like DEL key) |
| `dd` | Delete entire line |
| `ndd` | Delete n number of lines from the cursor position <br><br> E.g. `4dd` --> Delete 4 lines from the cursor position |
| `yyp` | Copy paste |
| `ddp` | Cut paste |
| `/<KEYWORD>` | To search a word in the file <br><br> You can hit `n` for next search of the same word in the file |

NOTE: You can always search in the internet for more other info which is not listed in the table above

### Insert Mode

To edit the content of the file in vim editor, press `i` to proceed.

After pressing `i`, you are in insert mode or edit mode. There, you can start writing your content.

To exit insert mode, just hit `Esc` button.

### Extended Command Mode

To use extended command mode, press `Esc` with key `:`

Below are some basic implementation for extended command mode

| Key | Extended Command Mode Action |
|:---:|---|
| `:w` | Save changes |
| `:q` | Quit without saving |
| `:q!` | Quit forcefully without saving |
| `:wq` | Save and quit |
| `:wq!` | Save and quit forcefully |
| `:n` | n here is to type a number <br><br> E.g. `:4` --> Go to line no.4|
| `:se nu` | To show the line numbers in the file |
| `:se nonu` | To remove line numebrs shown in the file from previous key `: se nu` |

NOTE: You can always search in the internet for more other info which is not listed in the table above