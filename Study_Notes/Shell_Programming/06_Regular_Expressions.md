# Regular Expressions

The basic building blocks of a regular expression are:
- Ordinary characters
- Metacharacters

## Ordinary Characters
 
Ordinary characters are:
- Uppercase and lowercase letters
- Numerals
- Characters such as a space or an underscore

## Metacharacters

Metacharacters are characters that have `special meaning` inside a regular expression. They are expanded to match ordinary characters.

By using metacharacters, you need not explicitly specify all the different combinations of ordinary characters that you want to match.

### Metacharacters Used in Regular Expressions

| Character | Description |
|:---:|---|
| `.` | Match `any single character except a new line` |
| `*` | Match `zero or more occurrences of character immediately proceeding it` |
| `[`*`<chars>`*`]`| Matches any one of the characters given in *`<chars>`*, where *`<chars>`* is a sequence of characters <br><br> You can use `-` to indicate a range of characters <br><br> If `^` is the first character in *`<chars>`*, one occurance of any character that is not specified by *`<chars>`* is matched |
| `^` | Matches the `beginning of a line` |
| `$` | Matches the `end of a line` |
| `\` | Treats the character that immediately follows the `\` literally <br><br> This is used to specify patterns that contain one of the preceding wildcards |