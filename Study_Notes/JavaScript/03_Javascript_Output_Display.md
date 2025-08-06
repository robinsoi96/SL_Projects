# JavaScript Output Display

JavaScript can "display" data in different ways:

- Writing into an HTML element, using `innerHTML` or `innerText`
- Writing into the HTML output using `document.write()`
- Writing into alert box, using `window.alert()`
- Writing into the browser console, using `console.log()`

## Using `innerHTML`

To access an HTML element, you can use the `document.getElementById(id)` method.

Use the `id` attribute to identify the HTML element.

Then use the `innerHTML` property to change the HTML content of the HTML element.

**Example:**

```html
<!DOCTYPE html>
<html>
    <body>
        <p id="demo"></p>

        <script>
            document.getElementById("demo").innerHTML = "<h2>Hello World</h2>";
        </script>
    </body>
</html>
```

From the example above, you will see the paragraph with id "demo" shows "Hello World" with heading level 2.

## Using `innerText`

To access an HTML element, use the `document.getElementById(id)` method.

Then use the `innerText` property to change the inner text of the HTML element

**Example:**

```html
<!DOCTYPE html>
<html>
    <body>
        <p id="demo"></p>

        <script>
            document.getElementById("demo").innerText = "Hello World";
        </script>
    </body>
</html>
```

From the example above, you will see the paragraph with id "demo" shows text "Hello World".

**NOTE:**

- Use `innerHTML` when you want to change HTML element
- Use `innerText` when you only want to change the plain text

## Using `document.write()`

`document.write()` is used to write into HTML output stream.

Example:

```html
<!DOCTYPE html>
<html>
    <body>
        <p>My first paragraph</p>

        <script>
            document.write(5)
        </script>
    </body>
</html>
```

From the example above, the HTML page will print "My first paragraph" and followed by "5" in the next line.

**NOTE:**

Example:

```html
<!DOCTYPE html>
<html>
    <body>
        <p>My first paragraph</p>

        <button type="button" onclick="document.write(5)">Try it</button>
    </body>
</html>
```

- From example above, by default, the line "My first paragraph" and a button "Try it" at below will be shown
- When the button is clicked, all default content will disappear, and "5" will be shown
- Using `document.write()` after HTML document is loaded, will **show content in `document.write()`** but will **delete all existing HTML content**

## Using `window.alert()`

You can use `window.alert()` or `alert()` to use an alert box to display data.

As soon you the web page (if having `alert()`), an alert box will pop out with its display data written in `alert()`. 

You can click "OK" button on the alert box to close the alert box, and then you will see the content in HTML content

## Using `console.log()`

For debugging purposes, you can use `console.log()` to display data under **console section** when you attempt to **inspect** in the web page.

## JavaScript Print

You can use `windows.print()` method to print the content of the current window.

**Example:**

```html
<!DOCTYPE html>
<html>
    <body>
        <button onclick="window.print()">Print this page</button>
    </body>
</html>
```

From the example above, a button "Print this page" will be available in the web page, and Print Preview page will appear when you click on the button.