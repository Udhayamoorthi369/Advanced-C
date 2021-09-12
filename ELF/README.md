
The Structure of an ELF File
On a Linux terminal, the command man elf gives you a handy summary about the structure of an ELF file:

### Listing 1: The manpage of the ELF structure

![Screenshot from 2021-09-12 16-08-22](https://user-images.githubusercontent.com/89963356/132994853-801cca1c-0305-47d1-ab2e-23ed292692da.png)

As you can see from the description above, an ELF file consists of two sections – an ELF header, and file data. The file data section can consist of a program header table describing zero or more segments, a section header table describing zero or more sections, that is followed by data referred to by entries from the program header table, and the section header table. Each segment contains information that is necessary for run-time execution of the file, while sections contain important data for linking and relocation. Figure 1 illustrates this schematically.

![1-7](https://user-images.githubusercontent.com/89963356/132694268-69dc84e0-28d6-4865-a5ba-407a2de84fd3.png)




The ELF Header
The ELF header is 32 bytes long, and identifies the format of the file. It starts with a sequence of four unique bytes that are 0x7F followed by 0x45, 0x4c, and 0x46 which translates into the three letters E, L, and F. Among other values, the header also indicates whether it is an ELF file for 32 or 64-bit format, uses little or big endianness, shows the ELF version as well as for which operating system the file was compiled for in order to interoperate with the right application binary interface (ABI) and cpu instruction set.

The hexdump of the binary file touch looks as follows:

### .Listing 2: The hexdump of the binary file
```

.Listing 3: Displaying the header of an ELF file
$ readelf -h /usr/bin/touch
ELF Header:
  
```
  ![Screenshot from 2021-09-12 13-14-27](https://user-images.githubusercontent.com/89963356/132989171-6e7b1c9f-05a8-434b-bbe1-c8d91064f8ab.png)




The Program Header
The program header shows the segments used at run-time, and tells the system how to create a process image. The header from Listing 2 shows that the ELF file consists of 9 program headers that have a size of 56 bytes each, and the first header starts at byte 64.


Again, the readelf command helps to extract the information from the ELF file. The switch -l (short for –program-headers or –segments) reveals more details as shown in Listing 4.
```
.Listing 4: Display information about the program headers
$ readelf -l /usr/bin/touch

Elf file type is EXEC (Executable file)
Entry point 0x4025e3
There are 9 program headers, starting at offset 64

Program Headers:
```
![Screenshot from 2021-09-12 15-53-18](https://user-images.githubusercontent.com/89963356/132994330-ab56d53f-6627-4182-a20f-20d64fa740c6.png)
![Screenshot from 2021-09-12 15-53-58](https://user-images.githubusercontent.com/89963356/132994399-4001dd16-905d-4ffe-b4ae-eac57521b23f.png)


The Section Header
The third part of the ELF structure is the section header. It is meant to list the single sections of the binary. The switch -S (short for –section-headers or –sections) lists the different headers. As for the touch command, there are 27 section headers, and Listing 5 shows the first four of them plus the last one, only. Each line covers the section size, the section type as well as its address and memory offset.


### .Listing 5: Section details revealed by readelf
```
$ readelf -S /usr/bin/touch
There are 27 section headers, starting at offset 0xe428:

Section Headers:
  [Nr] Name              Type             Address           Offset
       Size              EntSize          Flags  Link  Info  Align
  [ 0]                   NULL             0000000000000000  00000000
       0000000000000000  0000000000000000           0     0     0
  [ 1] .interp           PROGBITS         0000000000400238  00000238
       000000000000001c  0000000000000000   A       0     0     1
  [ 2] .note.ABI-tag     NOTE             0000000000400254  00000254
       0000000000000020  0000000000000000   A       0     0     4
  [ 3] .note.gnu.build-i NOTE             0000000000400274  00000274
...
...
  [26] .shstrtab         STRTAB           0000000000000000  0000e334
       00000000000000ef  0000000000000000           0     0     1
```
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), l (large)
  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)
  O (extra OS processing required) o (OS specific), p (processor specific)
Tools to Analyze an ELF file
As you may have noted from the examples above, GNU/Linux is fleshed out with a number of useful tools that help you to analyze an ELF file. The first candidate we will have a look at is the file utility.

file displays basic information about ELF files, including the instruction set architecture for which the code in a relocatable, executable, or shared object file is intended. In listing 6 it tells you that /bin/touch is a 64-bit executable file following the Linux Standard Base (LSB), dynamically linked, and built for the GNU/Linux kernel version 2.6.32.

### .Listing 6: Basic information using file
```
$ file /bin/touch
/bin/touch: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/l,
for GNU/Linux 2.6.32, BuildID[sha1]=ec08d609e9e8e73d4be6134541a472ad0ea34502, stripped
$
The second candidate is readelf. It displays detailed information about an ELF file. The list of switches is comparably long, and covers all the aspects of the ELF format. Using the switch -n (short for –notes) Listing 7 shows the note sections, only, that exist in the file touch – the ABI version tag, and the build ID bitstring.
```
### .Listing 7: Display Selected sections of an ELF file
```
$ readelf -n /usr/bin/touch

Displaying notes found at file offset 0x00000254 with length 0x00000020:
  Owner                 Data size   Description
  GNU                  0x00000010   NT_GNU_ABI_TAG (ABI version tag)
    OS: Linux, ABI: 2.6.32

Displaying notes found at file offset 0x00000274 with length 0x00000024:
  Owner                 Data size   Description
  GNU                  0x00000014   NT_GNU_BUILD_ID (unique build ID bitstring)
    Build ID: ec08d609e9e8e73d4be6134541a472ad0ea34502
```
Note that under Solaris and FreeBSD, the utility elfdump [7] corresponds with readelf. As of 2019, there has not been a new release or update since 2003.

Number three is the package named elfutils [6] that is purely available for Linux. It provides alternative tools to GNU Binutils, and also allows validating ELF files. Note that all the names of the utilities provided in the package start with eu for ‘elf utils’.

Last but not least we will mention objdump. This tool is similar to readelf but focuses on object files. It provides a similar range of information about ELF files and other object formats.


### .Listing 8: File information extracted by objdump
```
$ objdump -f /bin/touch

/bin/touch:     file format elf64-x86-64
architecture: i386:x86-64, flags 0x00000112:
EXEC_P, HAS_SYMS, D_PAGED
start address 0x00000000004025e3
```
![Screenshot from 2021-09-12 15-59-42](https://user-images.githubusercontent.com/89963356/132994540-8385dc3a-aa35-4e36-9495-2ff1d3241c8c.png)

$

