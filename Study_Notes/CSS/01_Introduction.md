# CSS Introduction

CSS stands for **Cascading Style Sheets**. 

It specifies layout of web page.

## CSS Comment

All CSS comments (regardless it is **single-line comment** or **multiple-line comments**) share the **same comment syntax**:

- Start with `/*`
- End with `*/`

## Basic CSS Syntax

```css
    <selector>{
        <property>:<value>; //Declaration
    }
```

**NOTE:**

- *`<selector>`* points to the HTML element you want to style
- Declaration block contains one or more declarations separated by semicolons `;`.
- Each *`<declaration>`* includes a CSS *`<property>`* and its *`<value>`*, separated by a colon `:`
- Multiple CSS declarations are separated with semicolons, and declaration blocks are surrounded by curly braces `{}`