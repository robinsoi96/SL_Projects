# Include JavaScript in HTML

There are 2 ways to include JavaScript in HTML.

## Method #1: Insert JavaScript Code in HTML

In HTML, JavaScript code is inserted between `<script>` and `</script>` tags

```html
    <script>
        Insert your JavaScript code here...
    </script>
```

## Method #2: Include External JavaScript File to HTML

You can prepare your own external JavaScript file to be included in HTML.

This method is **much preferred**, especially when same code is used in many different web pages.

To use an external script, put the name of the script file in the `src` attribute of a `<script>` tag:

```html
    <script src="Your_JavaScript_filename.js"></script>
```

## JavaScript in `<head>` or `<body>`

JavaScript can be placed in the `<body>` section, or in the `<head>` section, or in both, regardless it is using [Method #1](#method-1-insert-javascript-code-in-html) or [Method #2](#method-2-include-external-javascript-file-to-html) mentioned in the sections above.