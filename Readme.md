# File Copy Application Using `sendfile()` in C

## Overview

This application is a simple file copying utility written in C. It utilizes the Linux `sendfile()` system call to efficiently copy the contents of one file to another. The program is divided into two parts: a static library containing the core file-copying logic, and the main application that handles user interaction and calls the library function. 

## Features

- **Efficient File Copying**: Uses the Linux `sendfile()` system call for optimized file transfer.
- **Command-Line Arguments**: Specify source and destination file names through arguments.
- **Interactive Mode**: If no arguments are passed, the program will prompt the user to input the source and destination file paths.
- **Static Library**: The file copying logic is compiled into a static library (`libcopy.a`) and linked to the executable during the build process.

## Requirements

- Linux-based system with GCC installed
- `make` for building the project

## How It Works

Here's the basic flow:
1. **File copy logic**: The file copying logic is defined in a separate C file (`copy.c`) and compiled into a static library (`libcopy.a`).
2. **Main function**: The `main.c` file is responsible for interacting with the user, either via command-line arguments or input prompts.
3. **Build Process**: The `Makefile` handles the build process, including compiling the library, linking it, and generating the final executable.

## Build and Run Instructions

To build the project, simply run:
```bash
make

Once the build is complete, you can run the application in two ways:

1. Using Command-Line Arguments:
```bash
./main source_file.txt dest_file.txt

2. Interactive Mode:
```bash
./main

### Clone the Repository

```bash
git clone https://github.com/dominiksmolinski3/staticlibcopy.git
cd staticlibcopy
