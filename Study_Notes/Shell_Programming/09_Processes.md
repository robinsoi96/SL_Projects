# Processes in Linux/Unix

## Starting a Process

The operating system tracks processes through a `five digit ID` number known as `PID` or `process ID`.

- Each process in the system has a unique PID
- Used up PIDs can be used in again for a newer process since all the possible combinations are used
- At any point of time, `no two processed with the same PID exist` in the system because it is the PID that Unix uses to track each process.

You can use `ps` command to see what processes you are running and all processes on the system

When you start a process (run a command), there are two ways you can run it, either in `foreground` or `background`. 

The difference is how th process interacts with you at the terminal.

## Foreground Processes

By default, every command you executed is in the foreground.

When the command is running, you cannot run any other commands until the current command is done executed.

**NOTE:**
- When you log off or are disconnected from the system by a communication problem, your process will be termined
- If you have a long running process that you do not want terminated, you need to use the nohup command, where nohup stands for no HUP (Hang UP) 
- Th nohup command will be explained in later section

## Background Processes

Background process runs without keyboard input and waits until keyboard input is required.

The advantage of running a process in the background is that you can run other commands, where you do not have to wait until it completes to start another.

The simplest way to start a background process is to **add an ampersand (`&`) at the end of the command**.

### Running background process

1) When you run a background process, you will **instantly see an output line** where: <br> - **1st field** is the **job number or ID** <br> - **2nd field** is the **process ID (PID)**

2) After that, you will **see the output of the background process as the process is running in the background.**

3) When you **press Enter key after the background process has done its execution**, you will **see a line**, where: <br> - **1st field** is the **job number or ID** <br> - **2nd field** is the **status of the job or exit code of the job** <br> - **3rd field** is the **command**

**NOTE:**

If you do not see the completion message of the background process command, it might be because your shell has been told not to show it to you.

- You can **enable monitoring** with the following command: `set -o monitor`
- To **disable the monitoring messages**, run this command: `set +o monitor`
- You can also **check all the shell options** with the following: `set -o`

## `top` Command

`top` command is used to show all the running processes within the working environment of Linux.

It works very similar to Task Manager in Windows OS.

To quit the `top` command, just enter `q`.

## Types of Processes

### Parent and Child Process

The 2nd and 3rd column of the `ps -f` comamnd shows `process id (PID)` and `parent's process id (PPID)` number.

**For each user process, there's a parent process in the system**, with most of the commands having shell as their parent.

When a **child** is forked or created from its parent, it **receives a copy of the parent's environment, including environment variables**. The child **can change its own environment, but those changes do not reflect in the parent and go away when the child exits**.

### Zombie and Orphan Process

After completing its execution a child process is terminated or killed and SIGCHLD updates the parent process about the termination and thus can continue the task assigned to it.

But at times **when the parent process is killed before the termination of the child process** (e.g. force kill the parent process using kill -9 command, but did not kill its child proceess), **the child processes become orphan processes**, with the parent of all processes "init" process, becomes their new pid.

A **process which is killed but still shows its entry in the process status or the process table** is called a **zombie process**, they are dead and are not used.

### Daemon Process

They are **system-related background processes** that often run with the permissions of root and services requests from other processes, they most of the time run in the background and wait for processes it can work along with (e.g. print daemon).

When `ps -ef` is executed, the process with `?` in the `tty` field are daemon processes.