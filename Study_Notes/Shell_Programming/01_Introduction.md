# Shell in UNIX system

## What is the Shell?

Shell provides you with an interface to the Unix system.
It gathers input from you and execute programs based on that input.
When a program finishes executing, it displays that program's output.

Shell is an environment in which we can run our commands, programs, and shell scripts. 
There are different flavors of a shell, just as there are different flavors of operating systems. 
Each flavor of shell has its own set of recognized commands and functions.

<br>

## Different Types of Shells

In UNIX, there are two major types of shells:

* **Bourne shell** (includes `sh`, `ksh` and `bash`)
* **C shell** (includes `csh` and  `tcsh`)

<br>

If you are using a `Bourne-type shell`, the default prompt is the `$` character.

If you are using a `C-type shell`, the default prompt is the `%` character.

If you are using the `root account`, both the Bourne and C shells display the `#` character as a prompt.

```
In UNIX, there are two types of accounts, regular user accounts and root account.

Normal users are given regular user accounts.

The root account is an account with special privileges the administrator of a UNIX system (called the sysadmin)
uses to perform maintenance and upgrades.

Be extremely careful when executing commands as the root user because your commands effect the whole system.
```

<br>

Different **Bourne-type shells** follow:

* Bourne shell (sh)
* Korn shell (ksh)
* Bourne Again shell (bash)
* POSIX shell (sh)

<br>

Different **C-type shells** follow:

* C shell (csh)
* TENEX/TOPS C shell (tcsh)