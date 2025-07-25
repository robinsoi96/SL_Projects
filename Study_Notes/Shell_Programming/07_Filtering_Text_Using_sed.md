# Filering Text using `sed`

## Printing Lines with `sed`

| `sed` syntax | Explanation |
|:---:|---|
| `sed -n '`*`<line_number>`*`p'` | Print line number # *`<line_number>`* |
| `sed -n '`*`<starting_num>`*`,`*`<ending_num>`*`p'` | Print from line number # *`<starting_num>`* until # *`<ending_num>`* |
| `sed -n '`*`<random_num>`*`p;`*`<random_num>`*`p;`*`<random_num>`*`p'` <br><br> `sed -n -e '`*`<random_num>`*`p' -e '`*`<random_num>`*`p' -e '`*`<random_num>`*`p'` | Print non-contiguous lines <br><br> Simple explanation: <br> Print only lines number # *`<random_num>`* , #... |
| `sed -n '`*`<starting_num>`*`~`*`<next_line_count>`*`p'`| Print every *`<next_line_count>`* th line starting line number #*`<starting_num>`*|
| `sed -n '/`*`<pattern>`*`/p'`| Print lines with matching pattern or regular expression *`<pattern>`* |
| `sed -n '/`*`<PATTERN#1>`*`/,`*`<PATTERN#2>`*`/p'`| Print lines within a range defined by *`<PATTERN#1>`* and *`<PATTERN#2>`* (inclusive) |


## Deleting Lines with `sed`

| `sed` Command | Explanation |
|:---:|---|
| `sed '`*`<line_number>`*`d'` | Delete line number # *`<line_number>`* |
| `sed '`*`<starting_num>`*`,`*`<ending_num>`*`d'` | Delete from line number # *`<starting_num>`* until # *`<ending_num>`* |
| `sed '`*`<random_num>`*`d;`*`<random_num>`*`d;`*`<random_num>`*`d'` <br><br> `sed -e '`*`<random_num>`*`d' -e '`*`<random_num>`*`d' -e '`*`<random_num>`*`d'` | Delete non-contiguous lines <br><br> Simple explanation: <br> Delete only lines number # *`<random_num>`* , #... |
| `sed '/`*`<pattern>`*`/d'`| Delete lines with matching pattern or regular expression *`<pattern>`* |
| `sed '/`*`<START_PATTERN>`*`/,`*`<END_PATTERN>`*`/d'`| Print lines within a range defined by *`<START_PATTERN>`* and *`<END_PATTERN>`* (inclusive) |

## Performing Substitutions with `sed`

| `sed` Command | Explanation |
|:---:|---|
| `sed 's/`*`<pattern_#1>`*`/`*`<pattern_#2>`*`/'` | Replace only the first keyword with *`<pattern_#1>`* to *`<pattern_#2>`* in the line <br><br> **NOTE:** Here only perform only 1 substitution in each line |
| `sed 's/`*`<pattern_#1>`*`/`*`<pattern_#2>`*`/g'` | Replace all keywords with *`<pattern_#1>`* to *`<pattern_#2>`* <br><br> **NOTE:** `g` indicates global substitution |

<br>

**Extra NOTE:**

If would like to reuse *`<pattern_#1>`* in *`<pattern_#2>`*, <br>Instead of rewriting *`<pattern_#1>`* in *`<pattern_#2>`*, <br>You can use `&` operator to indicate *`<pattern_#1>`* in *`<pattern_#2>`* region.

E.g.

If *`<pattern_#2>`* region == *`<pattern_#1><pattern_#2>`*

```
    sed 's/<pattern_#1>/&<pattern#2>/'
```

```
    sed 's/<pattern_#1>/&<pattern#2>/g'
```

<br>

If *`<pattern_#2>`* region == *`<pattern_#2><pattern_#1>`*

```
    sed 's/<pattern_#1>/<pattern#2>&/'
```
```
    sed 's/<pattern_#1>/<pattern#2>&/g'
```

## Using Multiple `sed` Commands

Sample command is as below:

```
    sed -e '<command_#1>' -e '<command_#2>' ... -e '<command_#N>'
```