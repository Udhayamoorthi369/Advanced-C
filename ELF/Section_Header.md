# SECTIONS DESCRIPTION
There are some sections listed by 'readelf' whose importance may vary from person to person. So, I'll start with the sections which I feel are more important from software development, binary analysis and malware research domains. 


### .TEXT SECTION
This section stores bytes which correspond to executable instructions (i.e. the programmer's code plus the C Runtime support) of the program, this section goes into the `code` segment (having Read-Execute permissions) when the binary gets loaded into memory. The section header entry corresponding to the .text section is shown bellow. This section is the most interesting part to Reverse Engineers as it gives idea about the overall design of a software program.

```shell
Section Headers:
  [Nr] Name   Type      Address           Off        Size               ES              Flg Lk    Inf   Al
...
  [13] .text  PROGBITS  00000000000004f0  000004f0   00000000000001b2  0000000000000000  AX 0     0     16
...
```
This clearly shows that memory is allocated for this section at runtime i.e. the section gets loaded into the memory (indicated by `A` flag) and is *executable* section (identified by the `X` flag). 

Lets see the content of this section. In the raw form, this just contains opcode/operand bytes which won't make sense to a human eye until we have an `assembly instruction set opcode table` or some tool (a disassembler) to interpret these bytes into CPU instructions. The GNU binutils have a program called `objdump` which can be used to display some information from an ELF binary. This utility has a disassembler which we'll use to disassemble raw bytes of .text section (present in [main] program (compiled from the source [main.c]) into x86_64 Intel CPU instructions. Generate the disassembly by - `objdump -d main`, you'll see various `symbols` (explained later) with their disassembly, scroll down and look for \<main>  symbol, this is the main() described in the file [.c] and look at the source code [sd.c] and then the instructions constituting \<main> carefully.


 ![SE1](https://user-images.githubusercontent.com/89963356/133987167-85647575-2b59-46ea-8e4b-237583112507.png
You'll notice that the statements at 5fe, 605, 60c, 613 are the same instructions which we wrote in our source file [main.c]. I hope this gives a brief idea and understanding towards the .text section.

**NOTE**: The `-M intel` flag is used with objdump to show the disassembly in **intel syntax** (unlike the default AT&T dialect) which is easier to begin with.
 
### .RODATA SECTION
This section stores all the string literals defined in the program. Look at the source [main.c], the string used in the printf() is a string literal. To analyse any section for strings we use `-p` option with '**readelf**' which dumps the output content as strings.

```shell

![Se2](https://user-images.githubusercontent.com/89963356/133987317-26f9c593-8b03-4a16-80b2-7a20d470ace3.png)

```


### .DATA SECTION
This section holds the initialized data of the program. You will find the initialized global/static variables inside this section. Let's look for .data section is file [sd] via objdump.

```shell
![SE3](https://user-images.githubusercontent.com/89963356/133987478-7a5573a9-81c5-47a3-80f2-f18f1e9882e3.png)


```
Look at the address of the symbol `0804A01C <global_var>`, it is the name of the global variable which have the value 'a' defined in the source file [main.c]. Objdump shows the disassembly `or BYTE PTR [rax],dl` here since it is confused between code and data. 

### .BSS SECTION
BSS here stands for **B**lock **S**tarted by **S**ymbol. This section stores the uninitialized data of the program. Any variable in this section is cleared with 0. In SHT, this section header entry is marked as sh_type SHT_NOBITS as .bss section does not occupy any space on disk (to avoid wastage of disk space as the memory for this section is going to get cleared anyways)

### .SHSTRTAB 
This is a string table for section headers which stores **section names** (in the form of NULL terminated strings). It is used by compile-time linker and tools like readelf to identify sections. Use the following options with readelf -
* `-x` : To dump content of section in hexadecimal format.
* `-p` : To dump content of section in the form of strings.<br>

Usage : `readelf -p <section_name|section_index> <elf_binary>`<br>
Let's look at the `.shstrtab` section of the binary [main].

```shell
 ![SE4](https://user-images.githubusercontent.com/89963356/133987819-7ba5cf13-e7d8-45b8-9eb3-6c3f5597703a.png)

```

### .SYMTAB AND .DYNSYM 

In a computer program, symbols just represent memory locations (which may be a function or perhaps a variable location). The section **\.symtab** contains the static symbols used in the compile-time linking whereas the section **\.dynsym** contains the Runtime/Dynamic symbols refered by the dynamic linker during program execution. Static symbols are removed if the binary is stripped since they are resolved and wouldn't contribute to execution of a program. The symbols external to the program (one's that are exported by shared libraries - DLL's or SO's) are also stored in .dynsym section. 



### .STRTAB 
This section contains ASCII strings representing names of **static symbols** defined in *.symtab* section. Let's dump strings from .strtab section using readelf's -p flag.

```shell
![se5](https://user-images.githubusercontent.com/89963356/133987895-cecb4b7f-e453-4fe6-9359-683c98fe3a15.png)

```
we can see the symbols defined in source file [main.c] such as the file name `main.c`, the function `main` and the global variables defined `global_var_in_bss` and `global_var`.


### .DYNSTR 
This section contains ASCII strings representing names of **external/dynmaic symbols** defined in *.dynsym* section. Let's dump strings from .strtab section using readelf's -p flag.

```shell
![se6](https://user-images.githubusercontent.com/89963356/133987925-8a61fab1-40d8-4099-bb1f-f3df7b47230c.png)

```

### .INTERP 
Stores the location of the program interpreter, which is the program that is handed over the control after the loader (exec) creates a process. Program interpreter's path is usually set to path of dynamic linker (`ld.so`) which performs the `dependency resolution` (i.e. mapping any shared library required by the invoked program to the process address space), symbol resolution/relocations (as briefly discussed above) and basically any setup done to the environment for the program to begin smooth execution.

```shell
![se7](https://user-images.githubusercontent.com/89963356/133988121-4ca0537f-338f-419f-989f-76da3174d63a.png)


```

### .DYNAMIC 
It stores the information used by the runtime linker (i.e. `ld.so`) and is only present in dynamically-linked binaries. It contains a series of structures of type `ElfN_Dyn` defined in `/usr/include/elf.h`.

```
![se8](https://user-images.githubusercontent.com/89963356/133988174-22ad174c-d286-47c6-891a-4a3b397067b0.png)

```
Here, `d_tag` is the dynamic tag that defines the interpretation of `d_un` structure member. Some commonly used values for d_tag are -  
* DT_NULL : this entry marks as the end of .dynamic section.
* DT_NEEDED : all the libraries required as a dependency for the invoked program can be seen here as a DT_NEEDED entry whose `d_un` represents a **string table offset** to name of a needed library. These are the entries looked up by programs like `ldd` to list dependencies of a binary.
* DT_STRTAB : an entry for .dynstr section.
* DT_SYMTAB : an entry for .dynsym section.
* DT_BIND_NOW : an entry which instructs the linker to resolve all relocations before transferring control to the executable. This stops the dynamic linker to perform delay loading.
* DT_SYMBOLIC : according to `man 5 elf` - "Alert linker to search this shared object before the executable for symbols". Which might mean that if a shared object is compiled with this attribute set, it will be searched for symbols before the executable itself. These type of binaries should probably be flagged for such behavior.


### .GNU.HASH 
This section stores the hash table to speed up the `dynamic symbol lookup` process for dynamic linker. Along with a **hash function**, it is also having **bloom filter** (a probabilistic data structure) being used to eliminate false negatives for symbol in search (which can't comment if a symbol is present but can efficiently indicate a missing dynamic symbol). I'm looking forward to talk more about this section in upcoming commits.



### .INIT 
This section contains initialization code which is executed before the entry point of program.<br>


### .FINI 
This section includes termination code which is executed after the main() exits.

### .INIT_ARRAY 
This is an array of function pointers whose values (functions) and code inside .init section is executed before transferring control to the entry point of program. If we mark any function with the attribute `constructor`, its address will automatically be added to .init_array section by GCC. Furthur priorities in order of execution can be assigned for these initialization functions. The priority values can be set by giving values to `constructor` attribute from `101` onwards (since priority values from `0-100` are reserved for GCC). See for eg: the bellow source code. The usage of attributes is demonstrated bellow

```shell
__attribute__((constructor(102))) void func1() {}
__attribute__((constructor(101))) void func2() {} 
__attribute__((section(".fini"))) void abhi() {}
```
Here, func2 is given higher priority, i.e. 101, than func1(), i.e. 102, therefore will be executed before func1.<br>
The `attribute((section(".fini")))` makes sure that the corresponding function named `abhi` gets placed in `.fini` section rather than .text section and hence will execute when the program ends. This way you can add your own initialization and finalization code that you want to execute before the entry point or after main() exits respectively. If a section name (which does not exist) is used, then a new section will be created by that name specified and function will be placed in that newly created section. 

### .FINI_ARRAY 
It is an array of function pointers which execute right after the main() exits. Crashes will stop the functions from being executed, i.e. functions in this section are executed at the end of a normally terminated program. To place a function in .fini section, use with attribute `destructor` (usage is demonstrated above).

### .PREINIT_ARRAY
This section stores an array of function pointers which are executed before any function code in .init or .init_array section.
Below, given callgraph shows the calling sequence of code since program startup. Here, _start symbol is where the entry point of an ELF binary points to when compiled with GCC. One can also see `main` where the programmer specified code starts up.

<p align="center">
  <img src="./../../IMAGES/callgraph.png">
</p>

The above image is taken from [here] which is a good reference for someone who would like to understand a program startup.

### .RELA.DYN 
Stores the relocation table for the fixup of **data symbols** during dynamic/runtime linking. More in this later in the course.

### .RELA.PLT 
Stores the relocation table for the fixup of **function symbols** during dynamic/runtime linking.

