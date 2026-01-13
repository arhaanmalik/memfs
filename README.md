# memFS — A Fast In-Memory File System

memFS (pronounced *memphis*) is a high-performance **in-memory file system** implemented in **C/C++**.  
It stores all files directly in **RAM**, enabling extremely fast file operations by eliminating disk I/O.  
The system provides a **command-line interface**, supports **multithreaded operations**, and is designed for **benchmarking and performance analysis**.



---

##  Key Features

- Fully in-memory (volatile) file system
- Interactive command-line interface
- Multithreaded support for batch operations
- Low-latency execution (milliseconds)
- Thread-safe file operations
- Designed for performance benchmarking
- Files exist only during program execution

---

##  Motivation

Traditional disk-based file systems incur high latency due to disk I/O.  
memFS demonstrates how **RAM-based storage** can significantly improve performance for:
- Temporary storage
- Caching systems
- Testing environments
- Understanding OS-level file system design

All data is stored in volatile memory and is **lost when the program exits**.

---

##  System Overview

- memFS runs as an interactive shell
- Users issue commands to manipulate files
- Files are stored using in-memory data structures
- Supports parallel execution using multithreading
- Number of files limited only by available RAM

---

##  File Constraints

- Maximum number of files: **limited by available RAM**
- File size range: **32 bytes to 2 KB**
- Each file maintains:
  - Filename
  - File size (bytes)
  - Creation timestamp
  - Last modified timestamp
  - File contents

---

##  Supported Commands

##  Supported Commands

### `create`
Creates one or more files.

```bash
create -n <number_of_files> <filename1> <filename2> ...

```



### `write`


Writes text content into one or more files.

```bash
 write [-n<number_of_files>] <filename> "text" 
```

### `read`

Reads and displays the content of a file.
```bash
read <filename>
```

### `delete`

Deletes one or more files.
```bash
delete [-n <number_of_files>] <filename1> <filename2> ...
```
### `ls`

Lists files in the memory file system.

```bash
ls
ls -l
```
- ls → lists file names

- ls -l → lists file details (size, created date, last modified date)

### `exit`

Exits the memFS shell.
```bash
exit
```

###  *Examples (Sample memFS Session)*

Below is a complete example interaction showing how memFS works end-to-end.

### `Starting memFS`
```bash 
$ ./memFS
```

### `Creating File`
```bash

memfs> create todo.txt
file created successfully


memfs> create -n 2 notes.txt tasks.txt
files created successfully
```

### `Writing to Files`
```bash
memfs> write todo.txt "Wake up at 7 AM"
successfully written to todo.txt

memfs> write -n 2 notes.txt "Meeting at 10" tasks.txt "Finish assignment"
successfully written to the given files
```

### `Reading Files`
```bash
memfs> read todo.txt
Wake up at 7 AM


memfs> read hello.txt
Error: hello.txt does not exist
```
### `Listing Files`
```bash
memfs> ls
todo.txt
notes.txt
tasks.txt

memfs> ls -l
size  created     last_modified  filename
18    27/10/2024  27/10/2024     todo.txt
14    27/10/2024  27/10/2024     notes.txt
18    27/10/2024  27/10/2024     tasks.txt

Deleting Files
memfs> delete tasks.txt
file deleted successfully

memfs> delete -n 2 todo.txt notes.txt
files deleted successfully

Exiting memFS
memfs> exit
exiting memFS
```
