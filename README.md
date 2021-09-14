# Advanced-C

[![Anurag's GitHub stats](https://github-readme-stats.vercel.app/api?username=udhayamoorthi369)](https://github.com/anuraghazra/github-readme-stats)


### Hi there 👋, udhayamoorthi
#### Design and Engineering
I am udhayamoorthi and I do programming and development.

Skills: C / C++ 

- 🔭 I’m currently working on this page. 


[<img src='https://cdn.jsdelivr.net/npm/simple-icons@3.0.1/icons/github.svg' alt='github' height='40'>](https://github.com/         udhayamoorthi)  [<img src='https://cdn.jsdelivr.net/npm/simple-icons@3.0.1/icons/stackoverflow.svg' alt='stackoverflow' height='40'>](https://stackoverflow.com/users/https://stackexchange.com/users/22656471/udhayamoorthi) 

# Github-Documentation-With-Doxygen

Automatically deploy your documentation of your project without any CI pipelines. This is achieved by using github actions along with github pages.

Doxygen with auto deployment has been setup in this repository. The documentation for this repository is available at https://github.com/Udhayamoorthi98/udhayamoorthi98.github.io/

## Doxygen - Documentation Setup
Skip this if you already have doxygen configured 
* Install `doxygen`
    * macOS - `brew install doxygen`
    * Ubuntu - `sudo apt-get install -y doxygen`
* Create doxygen config file (Doxyfile). Run `doxygen -g`
* Configure `Doxyfile`
    * Set `RECURSIVE` to `YES`
    * Set `EXCLUDE` and `EXCLUDE_PATTERNS` to exclude directories you don't want documented. Typically library code and plugins come here. 
    * Set `PROJECT_NAME` to the name of your project
* Optionally add `html` and `latex` to `.gitignore` file
* Document your code according to Doxygen guidlines
    * Check `src/main.c` for C style documentation. Output can be seen [here](https://udhayamoorthi98.github.io/).
   
## Configuring automatic publishing using github actions
* Copy the action file `main.yml` to `.github/workflows/main.yml`
* Commit and Push to github
* Github action should automatically start running
* Confirm that github is set to deploy `gh-pages` branch in settings page

## Notes
* Ensure that `publish_dir` in `main.yml` is set correctly

<h2> Contents </h2>

<table style = "width : 80%" border = "1px solid black"> 
<tr>
<th>Folder</th>
<th>Description</th>
<th>Link</th>
</tr>


<tr>
<td> File </td>
<td> A file is an abstract data type. For defining a file properly, we need to consider the operations that can be performed on files. The operating system can provide system calls to create, write, read, reposition, delete, and truncate files.
</td>
<td><a href="https://github.com/Udhayamoorthi369/Advanced-C/tree/main/FILES"> code </a></td>
</tr>

  
<tr>
<td> Sort </td>
<td> A sorting algorithm is a method for reorganizing a large number of items into a specific order, such as alphabetical, highest-to-lowest value or shortest-to-longest distance
</td>
<td><a href="https://github.com/Udhayamoorthi369/Advanced-C/tree/main/SORTING"> code </a></td>
</tr>

   
<tr>
<td> Fork </td>
<td> 
Fork() is system call which is used to create new process. New process created by fork() system call is called child process and process that invoked fork() system call is called parent process.
</td>
<td><a href="https://github.com/Udhayamoorthi369/Advanced-C/tree/main/Fork"> code </a></td>
</tr>
   
<tr>
<td> File_system </td>
<td>A file system is a process that manages how and where data on a storage disk, typically a hard disk drive (HDD), is stored, accessed and managed.
</td>
<td><a href="https://github.com/Udhayamoorthi369/Advanced-C/tree/main/File_system"> code </a></td>
</tr>

  
 <tr>
<td> atExit </td>
<td> The function pointed by atexit() is automatically called without arguments when the program terminates normally. In case more than one function has been specified by different calls to the atexit() function, all are executed in the order of a stack (i.e. the last function specified is the first to be executed at exit).
</td>
<td><a href="https://github.com/Udhayamoorthi369/Advanced-C/tree/main/atEXIT"> code </a></td>
</tr>
   
  <tr>
<td> systemcall </td>
<td>A system call is just what its name implies -- a request for the operating system to do something on behalf of the user's program.  The system calls are functions used in the kernel itself.  To the programmer, the system call appears as a normal C function call.
</td>
<td><a href="https://github.com/Udhayamoorthi369/Advanced-C/tree/main/systemcalls"> code </a></td>
</tr>

   <tr>
<td> shared library </td>
<td>Shared libraries (also called dynamic libraries) are linked into the program in two stages. First, during compile time, the linker verifies that all the symbols (again, functions, variables and the like) required by the program, are either linked into the program, or in one of its shared libraries.
</td>
<td><a href="https://github.com/Udhayamoorthi369/Advanced-C/tree/main/Shared_Library"> code </a></td>
</tr>
   
    <tr>
<td> VFORK </td>
<td> Vfork() is also system call which is used to create new process. New process created by vfork() system call is called child process and process that invoked vfork() system call is called parent process.
</td>
<td><a href="https://github.com/Udhayamoorthi369/Advanced-C/tree/main/VFork"> code </a></td>
</tr>
