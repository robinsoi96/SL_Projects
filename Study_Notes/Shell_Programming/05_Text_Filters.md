# Text Filters

## The `head` Command

| Common `head` command usage | Explanation |
|:---:|---|
| `head <filename>` | Print **first 10 lines of the file** |
| `head -<number> <filename>` <br> or <br> `head -n <number> <filename>` | Print **first \<number> lines of the file** |
| `<command> \| head` | Show **first 10 lines of output of `<command>`** |
| `<command> \| head -<number>` <br> or <br> `<command> \| head -n <number>` | Show **first \<number> lines of output of `<command>`** |

## The `tail` Command
| Common `tail` command usage | Explanation |
|:---:|---|
| `tail <filename>` | Print **last 10 lines of the file** |
| `tail -<number> <filename>` <br> or <br> `tail -n <number> <filename>` | Print **last \<number> lines of the file** |
| `<command> \| tail` | Show **last 10 lines of output of `<command>`** |
| `<command> \| tail -<number>` <br> or <br> `<command> \| tail -n <number>` | Show **last \<number> lines of output of `<command>`** |

## The `grep` Command

| Command `grep` command usage | Explanation |
|:---:|---|
| `grep <keyword> <filename>` | Displays all lines with `<keyword>` in the file |
| `grep -i <keyword> <filename>` | Display all lines with `<keyword>` (case-insensitive) in the file |
| `grep -n <keyword> <filename>` | Displays all lines with `<keyword>` in the file, and showing the line number as well |
| `grep -v <keyword> <filename>` | Displays all lines **without** `<keyword>` in the file |
| `grep -c <keyword> <filename>` | Count the number of lines with `<keyword>` in the file |
| `<command> \| grep <keyword>` | Displays all lines of output of `<command>` with `<keyword>` |
| `grep -r <keyword> <directory>` | Display all lines with `<keyword>` in the file of the `<directory>` |

**NOTE:** If the `<keyword>` is more than just 1 word (e.g. New York), then your sample `grep` command will look as below:

```
    grep '<keyword>' <filename>
```

## The `tr` Command

Basic syntax of `tr` command is as below:

```
    tr '<set1>' '<set2>'
```

- `<set1>` is the character set to be transliterated (changed / replaced)
- `<set2>` is the final character set transliterated (changed / replaced)
- In short, `<set1>` --> `<set2>`
- Character sets can be solely characters, or characters with wildcard, or special characters
- To make sure `tr` works well regardless version installed in Linux, it is best to have both `<set1>` and `<set2>` having same number of character sets
- `tr` command has many options to play around with. For more info, can search on internet, or run `man tr` or `tr --help`.

## The `sort` Command

`sort` command basically sorts the lines of output in order.

For more info, can run `man sort` or `sort --help`

## The `uniq` Command

`uniq` command removes duplicate lines of the output, but `only able to remove continuous duplicate lines`.

For more info, can run `man uniq` or `uniq --help`