# Day 1 — Environment setup

## Today's Tasks
* Install Ubuntu 22.04 (dual boot) or WSL2 on Windows
* Install VS Code + C/C++ extension + CMake tools
* Learn 15 essential Linux terminal commands (ls, cd, mkdir, grep, chmod)
* Write Hello World in C++, compile with g++

### Task 1 :
It is basically a checklist kind of thing which I had already done, The difference is that I have installed Ubuntu 24.04 and in dual boot. <br>
My suggestion to you will be that, you should also choose dual boot as your option as it may be difficult in initial phase but it will save your time from future debugging.

### Task 2 :
I have already installed vs code and c++ extensions the only thing remaining is CMake tools. While I am at it I wiil tell you what exactly CMake is ??
- CMake is a open source, cross platform system used to automate things such as building, testing and packaging of software.
- It is a tool that helps developers manage the build process of their software projects in a compiler and platform independent manner.
- Think of it as 'Builders of builder' <br>
Now some of you will ask, what's the use of it ? Right ? Why do we exactly use this CMake for ?
- CMake generates native makefiles and workspaces that can be used in the compiler environment of your choice.
- Consider you built a project and you have to share this project to your friend who uses Linux, unlike you ,as you uses windows. So it is not as simple as you will just share your package built by and for windows to linux device and it will start working. You would have to manually write a "Makefile" for your windows computer. Your friend would then have to manually create a "Visual Studio Solution" on their linux computer. Every time you add a new file, you both have to update your separate, complex setup files manually.
With CMake: You write one simple file called CMakeLists.txt.On your machine, CMake reads that file and builds a Makefile for you.On your friend's linux machine, CMake reads that exact same file and builds a Visual Studio Project for them.
- Installation :
1. Windows Vs code : Directly installable as extension 
2. Linux : open terminal and  paste the command : `sudo apt update && sudo apt install cmake`

### Task 3 :
Here are 15 essential Linux terminal commands that you should know:
1. `ls` - List the contents which are present in the current directory.

2. `cd` - Change the current directory to another directory.
  Example: `cd path/to/new_directory `

3. `pwd` - Show the current working directory.

4. `mkdir` - Create a new directory.
  Example: `mkdir new_directory`

5. `rm` - Remove files or directories
    Example: `rm file.txt` (to remove a file) or 
             `rm -r directory_name` (to remove a directory and its contents) 
             (for removing directory directly we can also use `rmdir`) 

6. `cp` - Copy files or directories 
    Example: for copying file in another file: `cp file_1 file_2`
             for copying file to a directory: cp file_1 path/to/destination/

7. `mv` - Move or renaming the file from one location to another. 
    Example: `mv file_1 path/to/new/location`
             `mv file_old_name file_new_name`   

8. `touch` - Create an empty file. 
    Example: `touch new_file`

9. `cat` - Display file contents.
    Example: `cat file.txt`

10. `nano` - Edit files in terminal.

11. `find` - Search for files in a directory. 
    Example: `find . -name "file.txt"`
    Example: `find . -iname "file.txt"` (case-insensitive)

12. `chmod` - Change file permissions and directory access.
    Example: `chmod 755 myfile.txt` 

13. `grep` - Search for specific text within files.
    Example: `grep "search_term" file.txt`
    Example: `grep -r "search_term" .` (search recursively in current directory)

14.`sudo` - Execute a command with superuser (root) privileges.
        Example: `sudo apt update`

15. `echo` - Print text to the terminal.
    Example: `echo "Hello, World!"`
   
16. `ssh ` - Connect to remote server securely
    Example: `ssh username@hostname`

17. `kill` - Terminate the current running process in the terminal 
    Example: `kill process_id`

### Task 4 : 
Here is how you can write a simple "Hello, World!" program in C++ and compile it using g++:
But before that what is g++ ?
- g++ is the GNU Compiler Collection's C++ compiler. It is a command-line tool that compiles C++ source code into executable programs. 
- But for now skip this shit you can think of it like 'use only if you are not in ide or something'.

1.Open your terminal and navigate to the directory where you want to create the file (using command cd).
2.Offcourse you know what's next: use nano or touch to make new file with the name of your choice I'm going with 'hello.cpp'
3.After that you just have to write the code. Yeah that's it. 
Here is the file: [hello](hello.cpp)

