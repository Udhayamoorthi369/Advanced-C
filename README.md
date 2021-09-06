# Advanced-C

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
