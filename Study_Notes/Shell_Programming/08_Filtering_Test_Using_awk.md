# Filtering Text using `awk`

## Syntax of `awk` Command

Perform *`<actions>`* :

```
    awk '{ <actions> ; }'
```

Perform *`<actions>`* based on *`<pattern>`* :

```
    awk '/<pattern>/ { <actions> ; }'
```

Perform *`<actions>`* based on *`<conditions>`* :

```
    awk '<conditions> { <actions> ; }'
```