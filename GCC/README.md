# The C Build Process Explained


![](pdp7.jpg)

The exact linking process in C and C++ isn't standard, it's up to each compiler
to make things work. Most compilers behave in the same way with small
differences but we'll be focusing on the GNU tools to keep things simple.

## An Overview

Computers in 1972 weren't very powerful and so the process had to be broken down
into smaller steps. This also allows you to rebuild only the parts that change.

- we have many C/C++ source files,
- for each source file, we run an independent compiler,
  - we run the pre-processor over the current file,
  - this pulls in every header and its parents into the file,
  - the file gets compiled and transformed into an object,
- we group every object we generated into an executable or library.

![](tree.svg)

Entering a command to compile every source file separately is annoying and so we
have a build tool that knows how to compile each of our source files. Not only
that but it can also regenerate the objects for the source files that have
changed saving us a lot of time when recompiling with minor changes.

## Trivial C Program

Let's use a trivial C program to illustrate the build process. We can build it
with the following commands:

```
cc -Wall -O0 -std=c99 -g -c -o add.o add.c
cc -Wall -O0 -std=c99 -g -c -o simple.o simple.c
```

### add.h

```c
#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

int add(int a, int b);
int sub(int a, int b);

#endif // ADD_H_INCLUDED
```

### add.c

```c
#include "add.h"

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}
```

### simple.c

```c
#include <stdio.h>

#include "add.h"

int main(int argv, char **argc)
{
    printf("%i\n", sub(add(5, 6), 6));

    return 0;
}
```

## Why Headers?

> TLDR we need to know the size of structures and function arguments

When our main function wants to call the `add` function, it needs to know what
it returns and what it takes in as an argument before it can call the function.
A typical call to `add` from our main would look like:

- our `main` function,
  - push space for the return value onto a stack (an int),
  - push the parameters onto the stack (`a` and `b`),
  - push the return address (the next part of our main function),
  - jump to the add function,

- our `add` function
  - store the execution state,
  - add `a` and `b` placing the result in the return value space,
  - restore the execution state,
  - jump to the return address,

- back in our `main` function,
  - pop the parameters (`a` and `b`),
  - use the return value that is now on the stack.

The way to call a function and the method for building the stack make up most of
an ABI (Application Binary Interface) definition. Every compiler is free to have
its own ABI. The same compiler usually has a different ABI for the different
processors it supports. This makes things complex but efficient.

Since we are making space on the stack for our return value and parameters, we
have to know their size. If any of those are a structure, we have to know what
it's made of so that we can know its size. We let the compiler know all this
with function declarations and structure definitions.

You could put a function's declaration in every source file that needs it but
that's a terrible idea since the declaration has to be the same everywhere if you
want anything to work. Instead of having the same declaration everywhere, we put
the declaration in a common file and include it where it is necessary. This
common file is what we know as a header.

> Sometimes, we only use a structure through pointers or references which means
> we don't really have to know that structure's exact size. This leads to a
> clever trick known as pointer implementation (PIMPL) which is really useful
> for speeding up compilation and hiding implementation details. For
> [more information](https://marcmutz.wordpress.com/translated-articles/pimp-my-pimpl/)
> on PIMPL.

## Pre-processor

In those header files and source files, you've hopefully noticed lines that
start with `#`. Whenever you see a directive that starts with `#`, we are
dealing with the C pre-processor. The pre-processor does the following:

- include files (`#include`),
- macro expansions (`#define RADTODEG(x) ((x) * 57.29578)`),
- conditional compilation (`#if`, `#ifdef`, etc.),
- line control (`__FILE__`, `__LINE__`).

Basically, the compiler has a state which can be modified by these directives.
Since every `*.c` file is treated independently, every `*.c` file that is being
compiled has its own state. The headers that are included modify that file's
state. The pre-processor works at a string level and replaces the tags in the
source file by the result of basic functions based on the state of the compiler.

The `#include` pre-processor is probably the most important. Luckily, it is
really simple: it finds the file and replaces the `#include` line with the
contents of that file.

Where does it find the files?

- `#include <sum.h>` looks for `sum.h` in a list of include directories,
- `#include "sum.h"` does the same but looks in the current folder first.

C and C++ don't actually define a mechanism for providing the list of include
directories, that is up to the compiler. This causes many problems with cross
platform development which some build tools can solve.

## Include Guards

When you include a header, there is usually a `#ifndef` and `#define` statement
at the top of the file and a corresponding `#endif` at the bottom. We call this
an include guard. It is responsible for setting a variable the first time it is
run so that including the same file a second time doesn't redefine things that already
exist and cause the compiler to panic.

```
#ifndef FILENAME_INCLUDED
#define FILENAME_INCLUDED

// code

#endif
```

This is a very useful trick but it's also one of the more fundamental problems of
C:

- you include a file a first time,
- it modifies the compiler state,
- you include the same file a second time,
- based on the compiler state, it pretends to be empty.

That is completely crazy - the file you include can change based on the state of
the compiler. Not only that but the included files themselves can modify the
state of the compiler (windows.h is infamous for doing this).

Because of this, compiling becomes slow and complex. Suppose that we want to
compile two files which both include `<string.h>` and that `<string.h>` itself
includes about 50 other files. We are not able to cache `<string.h>` without
proving that the compiler state is the same when we include it!

So what started out as a simple, easy to implement solution turns out to scale
really poorly. This wasn't an issue in 1972 when the computers limited the
complexity but almost 50 years later, it's a big problem. The C++ standards
committee has been trying to introduce a module system to fix this but it's a
difficult task to change such a fundamental system in an established language.

## Header Trees

When you include a header, this header can include others and it can quickly get
messy. If we compile a file with the `-H` flag, we can visualize the various header graphs:

```
gcc -H -O0 -std=c99 -g -c -o simple.o simple.c
```

- /usr/include/stdio.h
  - /usr/include/bits/libc-header-start.h
    - /usr/include/features.h
      - /usr/include/sys/cdefs.h
        - /usr/include/bits/wordsize.h
        - /usr/include/bits/long-double.h
      - /usr/include/gnu/stubs.h
        - /usr/include/gnu/stubs-64.h
  - /usr/lib/gcc/x86_64-pc-linux-gnu/8  2  1/include/stddef.h
  - /usr/lib/gcc/x86_64-pc-linux-gnu/8  2  1/include/stdarg.h
  - /usr/include/bits/types.h
    - /usr/include/bits/wordsize.h
    - /usr/include/bits/typesizes.h
  - /usr/include/bits/types/__fpos_t.h
    - /usr/include/bits/types/__mbstate_t.h
  - /usr/include/bits/types/__fpos64_t.h
  - /usr/include/bits/types/__FILE.h
  - /usr/include/bits/types/FILE.h
  - /usr/include/bits/types/struct_FILE.h
  - /usr/include/bits/stdio_lim.h
  - /usr/include/bits/sys_errlist.h
- add.h



## An Object File

After all this work, the compiler can do the actual compiling of our source file
with all the headers pasted into it. Once the compilation is finished, we have
an object file.

An object file is an organized way to store assembly functions that aren't yet
linked together. We can examine the object file we generate with the `simple.c`
source file with the following command:

```
objdump -dr simple.o
```

### simple.o

```
simple.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 10          	sub    $0x10,%rsp
   8:	89 7d fc             	mov    %edi,-0x4(%rbp)
   b:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
   f:	be 06 00 00 00       	mov    $0x6,%esi
  14:	bf 05 00 00 00       	mov    $0x5,%edi
  19:	e8 00 00 00 00       	callq  1e <main+0x1e>
			1a: R_X86_64_PLT32	add-0x4
  1e:	be 06 00 00 00       	mov    $0x6,%esi
  23:	89 c7                	mov    %eax,%edi
  25:	e8 00 00 00 00       	callq  2a <main+0x2a>
			26: R_X86_64_PLT32	sub-0x4
  2a:	89 c6                	mov    %eax,%esi
  2c:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # 33 <main+0x33>
			2f: R_X86_64_PC32	.rodata-0x4
  33:	b8 00 00 00 00       	mov    $0x0,%eax
  38:	e8 00 00 00 00       	callq  3d <main+0x3d>
			39: R_X86_64_PLT32	printf-0x4
  3d:	b8 00 00 00 00       	mov    $0x0,%eax
  42:	c9                   	leaveq
  43:	c3                   	retq
```

This is what the most complex file in our tiny example looks like. The important
thing to notice is that the assembly code is grouped into the `<main>` function
and that there are calls to functions that don't yet exist like the call to
`sub` copied below:

```
25:	e8 00 00 00 00       	callq  2a <main+0x2a>
			26: R_X86_64_PLT32	sub-0x4
```

## A Linker's Job

To get an executable, we put many object files together and link the undefined
function calls to their implementations found in other object files. There are
two ways to do this:

1. Linking the functions directly together by jumping directly to the function.
2. Having a table that contains our functions and look up where to jump before
   jumping to the desired function.

The first option describes static linking. This is more efficient, less flexible
and rarely used.

The second option describes dynamic linking. It is a little bit slower but much
more flexible and is the standard way to ship a library.

### GCC Compiler Options
An Example C Code
The following basic C code (main.c) will used in this article :
```c
#include<stdio.h>

int main(void)
{
   printf("\n xtreme silica\n");
   return 0;
}
```
GCC Compiler Options
1. Specify the Output Executable Name
In its most basic form, gcc compiler can be used as :

## gcc main.c

The above command executes the complete compilation process and outputs an executable with name a.out.

Use option -o, as shown below, to specify the output file name for the executable.

## gcc main.c -o main

2. Enable all warnings set through -Wall option
This option enables all the warnings in GCC.
```c
#include<stdio.h>

int main(void)
{
   int i;
   printf("\n Xtream silica [%d]\n", i);
   return 0;
}
```
If the above code is compiled, the following warning related to uninitialized variable i is produced :

## $ gcc -Wall main.c -o main
```
main.c: In function â€˜mainâ€™:
main.c:6:10: warning: â€˜iâ€™ is used uninitialized in this function [-Wuninitialized]
```
3. Produce only the preprocessor output with -E option
The output of preprocessing stage can be produced using the -E option.

```
$ gcc -E main.c > main.i
```
The gcc command produces the output on stdout so you can redirect the output in any file. In our case(above), the file main.i would contain the preprocessed output.

4. Produce only the assembly code using -S option
The assembly level output can be produced using the -S option.
```
gcc -S main.c > main.s
```
In this case, the file main.s would contain the assembly output.

5. Produce only the compiled code using the -C option
To produce only the compiled code (without any linking), use the -C option.
```
gcc -C main.c
```
The command above would produce a file main.o that would contain machine level code or the compiled code.

6. Produce all the intermediate files using -save-temps function
The option -save-temps can do all the work done in example 4,5 and 6 above. Through this option, output at all the stages of compilation is stored in the current directory. Please note that this option produces the executable also.

For example :
```
$ gcc -save-temps main.c

$ ls
a.out  main.c  main.i  main.o  main.s
```
So we see that all the intermediate files as well as the final executable was produced in the output.

7. Link with shared libraries using -l option
The option -l can be used to link with shared libraries. For example:
```

gcc  -Wall main.c -o main -lCPPfile
```

The gcc command mentioned above links the code main.c with the shared library libCPPfile.so to produce the final executable ‘main’.

8. Create position independent code using -fPIC option
While creating the shared libraries, position independent code should be produced. This helps the shared library to get loaded as any address instead of some fixed address. For this -fPIC option is used.

For example, the following commands create a shared library libCfile.so from source file Cfile.c:
```
$ gcc -c -Wall -Werror -fPIC Cfile.c
$ gcc -shared -o libCfile.so Cfile.o
```
So we see that the option -fPIC was used in creation of a shared library.

9. Print all the executed commands using -V option
The option -v can be used to provide verbose information on all the steps gcc takes while compiling a source file.

For example :
```
$ gcc -Wall -v main.c -o main
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/i686-linux-gnu/4.6/lto-wrapper
Target: i686-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu/udhay 4.6.3-1ubuntu5' --with-bugurl=file:///usr/share/doc/gcc-4.6/README.Bugs --enable-languages=c,c++,fortran,objc,obj-c++ --prefix=/usr --program-suffix=-4.6 --enable-shared --enable-linker-build-id --with-system-zlib --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --with-gxx-include-dir=/usr/include/c++/4.6 --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --enable-gnu-unique-object --enable-plugin --enable-objc-gc --enable-targets=all --disable-werror --with-arch-32=i686 --with-tune=generic --enable-checking=release --build=i686-linux-gnu --host=i686-linux-gnu --target=i686-linux-gnu
Thread model: posix
gcc version 4.6.3 (Ubuntu/Linaro 4.6.3-1ubuntu5)
```
...
...
...
So we see that detailed information was produced in the output.

10. Enable the support of ISO C89 programs using -ansi option
Through -ansi option the support for ISO C89 style is enabled.

Consider the following code :
```c
#include<stdio.h>

int main(void)
{
  // Print the string
   printf("\n Xtream silica\n");
   return 0;
}
```
If the above code is compiled with -ansi option then gcc would produce an error because the C++ comments are not allowed in ISO C89 style.

Here is the output :
```
$ gcc -Wall -ansi main.c -o main
main.c: In function â€˜mainâ€™:
main.c:5:3: error: expected expression before â€˜/â€™ token
```
So we see that gcc threw an error related to commenting style.

11. Interpret char as unsigned char using -funsigned-char option
Through this option, the char type is treated as unsigned type.

Here is an example :
```c
#include<stdio.h>

int main(void)
{
  char c = -10;
  // Print the string
   printf("\n xtream silica [%d]\n", c);
   return 0;
   }
   ```
   When the above code is compiled with funsigned-char option, here is the output :
 
 ```
$ gcc -Wall -funsigned-char main.c -o main
$ ./main

 xtream silica [246]
    
 ```

So we see that the char was indeed treated as unsigned.

12. Interpret char as signed char using -fsigned-char option
This is the opposite of what we discussed in (12) above. Using this flag, the char variables are treated as signed.

Here is an example :
```
$ gcc -Wall -fsigned-char main.c -o main
$ ./main

xtream silica [-10]

```
The output confirms that char was treated as signed.

13. Use compile time macros using -D option
The compiler option D can be used to define compile time macros in code.

Here is an example :
```c
#include<stdio.h>

int main(void)
{
#ifdef MY_MACRO
  printf("\n Macro defined \n");
#endif
  char c = -10;
  // Print the string
   printf("\n The Geek Stuff [%d]\n", c);
   return 0;
}
```

The compiler option -D can be used to define the macro MY_MACRO from command line.
```
$ gcc -Wall -DMY_MACRO main.c -o main
$ ./main
 Macro defined 

 xtreme silica [-10]
 
 ```
The print related to macro in the output confirms that the macro was defined.

14. Convert warnings into errors with -Werror option
Through this option, any warning that gcc could report gets converted into error.

Here is an example :
```c
#include<stdio.h>

int main(void)
{
  char c;
  // Print the string
   printf("\n The Geek Stuff [%d]\n", c);
   return 0;
}
```

The compilation of above code should generate warning related to undefined variable c and this should get converted into error by using -Werror option.
```

$ gcc -Wall -Werror main.c -o main
main.c: In function â€˜mainâ€™:
main.c:7:10: error: â€˜câ€™ is used uninitialized in this function [-Werror=uninitialized]
cc1: all warnings being treated as errors
```

15. Provide gcc options through a file using @ option
The options to gcc can also be provided through a file. This can be done using the @ option followed by the file name containing the options. More than one options are separated by a white space.

Here is an example :
```
$ cat opt_file 
Wall -omain
The opt_file contains the options.

Now compile the code by providing opt_file along with option @.

$ gcc main.c @opt_file
main.c: In function ‘main’:
main.c:6:11: warning: ‘i’ is used uninitialized in this function [-Wuninitialized]

$ ls main
main
```

The output confirms that file opt_file was parsed to get the options and the compilation was done accordingly
