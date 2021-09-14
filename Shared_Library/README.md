### Step 1: Compiling with Position Independent Code
We need to compile our library source code into position-independent code (PIC):1

$ gcc -c -Wall -Werror -fpic displayuid.c
Step 2: Creating a shared library from an object file
Now we need to actually turn this object file into a shared library. We will call it libfoo.so:

gcc -shared -o libdisplayuid.so displayuid.o
Step 3: Linking with a shared library

![Uploading IMG_0355.jpg…]()
$ gcc -Wall -o test main.c -lfoo
/usr/bin/ld: cannot find -lfoo
collect2: ld returned 1 exit status
Telling GCC where to find the shared library
Uh-oh! The linker does not know where to find libfoo. GCC has a list of places it looks by default, but our directory is not in that list.2 We need to tell GCC where to find libfoo.so. We will do that with the -L option. In this example, we will use the current directory, /home/username/foo:

$ gcc -L/home/username/foo -Wall -o test main.c -lfoo
Step 4: Making the library available at runtime
Good, no errors. Now let us run our program:

$ ./test
./test: error while loading shared libraries: libfoo.so: cannot open shared object file: No such file or directory
Oh no! The loader cannot find the shared library.3 We did not install it in a standard location, so we need to give the loader a little help. We have a couple of options: we can use the environment variable LD_LIBRARY_PATH for this, or rpath. Let us take a look first at LD_LIBRARY_PATH:

Using LD_LIBRARY_PATH
$ echo $LD_LIBRARY_PATH
There is nothing in there. Let us fix that by prepending our working directory to the existing LD_LIBRARY_PATH:

$ LD_LIBRARY_PATH=/home/username/foo:$LD_LIBRARY_PATH
$ ./test
./test: error while loading shared libraries: libfoo.so: cannot open shared object file: No such file or directory
What happened? Our directory is in LD_LIBRARY_PATH, but we did not 
export it. In Linux, if you do not export the changes to an environment variable, they will not be inherited by the child processes. The loader and our test program did not inherit the changes we made. Thankfully, the fix is easy:

$ export LD_LIBRARY_PATH=/home/username/foo:$LD_LIBRARY_PATH
$ ./test
This is a shared library test...
Hello, I am a shared library
Good, it worked! LD_LIBRARY_PATH is great for quick tests and for systems on which you do not have admin privileges. As a downside, however, exporting the LD_LIBRARY_PATH variable means it may cause problems with other programs you run that also rely on LD_LIBRARY_PATH if you do not reset it to its previous state when you are done.

Using rpath
Now let s try rpath (first we will clear LD_LIBRARY_PATH to ensure it is rpath that is finding our library). Rpath, or the run path, is a way of embedding the location of shared libraries in the executable itself, instead of relying on default locations or environment variables. We do this during the linking stage. Notice the lengthy â€œ-Wl,-rpath=/home/username/fooâ€ option. The -Wl portion sends comma-separated options to the linker, so we tell it to send the -rpath option to the linker with our working directory.

$ unset LD_LIBRARY_PATH
$ gcc -L/home/username/foo -Wl,-rpath=/home/username/foo -Wall -o test main.c -lfoo
$ ./test
This is a shared library test...
Hello, I am a shared library
Excellent, it worked. The rpath method is great because each program gets to list its shared library locations independently, so there are no issues with different programs looking in the wrong paths like there were for LD_LIBRARY_PATH.

rpath vs. LD_LIBRARY_PATH
There are a few downsides to rpath, however. First, it requires that shared libraries be installed in a fixed location so that all users of your program will have access to those libraries in those locations. That means less flexibility in system configuration. Second, if that library refers to a NFS mount or other network drive, you may experience undesirable delays - or worse - on program startup.

Using ldconfig to modify ld.so
What if we want to install our library so everybody on the system can use it? For that, you will need admin privileges. You will need this for two reasons: first, to put the library in a standard location, probably /usr/lib or /usr/local/lib, which normal users do not have write access to. Second, you will need to modify the ld.so config file and cache. As root, do the following:

$ cp /home/username/foo/libfoo.so /usr/lib
$ chmod 0755 /usr/lib/libfoo.so
Now the file is in a standard location, with correct permissions, readable by everybody. We need to tell the loader it is available for use, so let us update the cache:

$ ldconfig
That should create a link to our shared library and update the cache so it is available for immediate use. Let us double check:

$ ldconfig -p | grep foo
libfoo.so (libc6) => /usr/lib/libfoo.so
Now our library is installed. Before we test it, we have to clean up a few things:

Clear our LD_LIBRARY_PATH once more, just in case:

$ unset LD_LIBRARY_PATH
Re-link our executable. Notice we do not need the -L option since our library is stored in a default location and we are not using the rpath option:

$ gcc -Wall -o test main.c -lfoo
Let us make sure we are using the /usr/lib instance of our library using ldd:

$ ldd test | grep foo
libfoo.so => /usr/lib/libfoo.so (0x00a42000)
Good, now let us run it:

$ ./test
This is a shared library test...
Hello, I am a shared library
