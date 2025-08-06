# JavaScript HTML DOM

## What is DOM?

DOM stands for **Document Object Model**.

DOM is a W3C (World Wide Web Consortium) standard, defines a standard for accessing documents.

W3C DOM standard is separated unto 3 different parts:

- `Core DOM` - standard model for all document types
- `HTML DOM` - standard model for HTML documents **[to be discussed in this chapter]**
- `XML DOM` - standard model for XML documents **[to be discussed in another chapter]**

## HTML DOM

With the object model, JavaScript gets all power it needs to create dynamic HTML:

- Change all HTML elements in the page
- Change all HTML attributes in the page
- Change all CSS styles in the page
- Remove existing HTML elements and attributes
- Add new HTML elements and attributes
- React to all existing HTML events in the page
- Create new HTML events in the page

## The DOM Programming Interface

In the DOM, all HTML elements are defined as **objects**.

The programming interface is the properties and methods of each object.

- A **property** is a **value** that you can get or set (e.g. changing the content of HTML element)
- A **method** is an **action** you can do (e.g. add or delete an HTML element)

Example:

```
document.getElementById("demo").innerHTML = "Hello World";
```

In the example above, `getElementById` is a **method**, while `innerHTML` is a **property**

## JavaScript HTML DOM Document Object

Document object represents your web page.

If you want to access any element in HTML page, you always start with accessing the document object.

Below are some examples of how you can use document object to access and manipulate HTML:

### Finding HTML Elements

| Method | Description |
|---|---|
| `document.getElementById`(*id*) | Find an element based on its element *id*|
| `document.getElementsByTagName`(*name*) | Find elements by tag name |
| `document.getElementsByClassName`(*name*) | Find elements by class name |
| `document.querySelectorAll`(*CSS selector*) | Find elements by *CSS selector* <br><br> More information, can refer to: <br> - <a href="https://www.w3schools.com/jsref/met_document_queryselectorall.asp">HTML DOM Document querySelectorAll()</a> <br> - <a href="https://www.w3schools.com/cssref/css_selectors.php">CSS Selector Reference</a>|

### Changing HTML Elements

| Property | Description |
|---|---|
| *element*.`innerHTML` = *new html content* | Change the inner HTML of an element |
| *element*.`attribute` = *new value* | Change the attribute value of HTML element |
| *element*.`style.property` = *new style* | Change the style of HTML element |

| Method | Description |
|---|---|
| *element*.`setAttribute`(*attribute*, *value*) | Change the attribute value of HTML element |

### Adding and Deleting Elements

| Method | Description |
|---|---|
| `document.createElement`(*element*) | Create HTML element |
| `document.removeChild`(*element*) | Remove HTML element |
| `document.appendChild`(*element*) | Add HTML content |
| `document.replaceChild`(*new*, *old*) | Replace HTML content |
| `document.write`(*text*) | Write into HTML output stream |

### Adding Events Handlers

| Method | Description |
|---|---|
| `document.getElementById`(*id*).`onclick` = *function(){code}* | Adding event handler code to an onclick event |

### Finding HTML Objects

The first HTML DOM Level 1 (1998), defined 11 HTML objects, object collections and properties. These are still valid in HTML5.

Later, in HTML DOM Level 3, more objects, collections, and properties were added.

| Property | Description | DOM |
|---|---|:--:|
| `document.baseURI` | Returns the absolute base URI of the document | 3 |
| `document.body` | Returns the \<body\> element | 1 |
| `document.cookie` | Returns the document's cookie | 1 |
| `document.doctype` | Returns the document's doctype | 3 |
| `document.documentElement` | Returns the \<html\> element | 3 |
| `document.documentMode` | Returns the mode used by the browser | 3 |
| `document.documentURI` | Return the URI of the document | 3 |
| `document.embeds` | Returns all \<embed\> elements | 3 |
| `document.forms` | Returns all \<forms\> elements | 1 |
| `document.head` | Returns all \<head\> elements | 3 |
| `document.img` | Returns all \<img\> elements | 1 |
| `document.implementation` | Returns the DOM implementation | 3 |
| `docuement.inputEncoding` | Returns the document's encoding (character set) | 3 |
| `document.lastModified` | Returns the date and time the document was updated | 3 |
| `document.links` | Returns all \<area\> and \<a\> elements that have a href attribute | 1 |
| `document.readyState` | Returns the (loading) status of the document | 3 |
| `document.referrer` | Returns the URI of the referrer (the linking document) | 1 |
| `document.scripts`| Return all \<script\> elements | 3 |
| `document.strictErrorChecking` | Returns if error checking is enforced | 3 |
| `document.title` | Returns the \<title\> element | 1 |
| `docuemnt.URL` | Returns the complete URL of the document | 1 |

## Appendix

Reference link: <a href="https://www.w3schools.com/js/js_htmldom.asp">JavaScript HTML DOM</a>