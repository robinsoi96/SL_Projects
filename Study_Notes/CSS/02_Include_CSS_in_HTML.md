# Include CSS in HTML

## Method to add CSS in HTML

There are 3 methods to include CSS in HTML.

**`Only Method #1 and #3 are recommended`**

### Method #1: External CSS [Recommended]

- Need to create external CSS file with `.css` extension to add all CSS syntax to be included in HTML file

- Including CSS external file in HTML file:

```html
<head>
    <link rel="stylesheet" href="<External_CSS_file>.css">
</head>
```

### Method #2: Internal CSS [Not Preferred]

- Example to add CSS syntax in HTML file (not recommended)

```html
<head>
    <style>
        Add all CSS syntax here...
    </style>
</head>
```

### Method #3: Inline CSS [If wish to style the specific element]

- Example to add CSS syntax to specific element, using `style` attribute

```html
<p style="<List_all_CSS_Syntax_Here>;">Paragraph</p>
```

## Cascading Order

1) [Inline style (inside an HTML element)](#method-3-inline-css-if-wish-to-style-the-specific-element) **\*\*Highest Priority**
2) [External](#method-1-external-css-recommended) & [internal](#method-2-internal-css-not-preferred) style sheets (in the head section)
3) Browser default **\*\*Lowest Priority**