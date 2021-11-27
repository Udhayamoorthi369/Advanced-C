

1. How do you execute the vulnerable program with AFL? what is the fuzzing result? List neccssary command you use.ALso show a Screeshot of AFL result with timestamp.

![fuzz](https://user-images.githubusercontent.com/89963356/143688444-8357c3b2-5559-4dc2-8014-43e18fdc80ba.png)

## Installing AFL

Installing AFL is quite straight-forward but before we install it, we need to have some prerequisite installed on our system.

    Note: This setup was tested with Ubuntu 16.04

Let’s start with installing the prerequisites. Follow the commands below to install gcc and clang:
```
sudo apt install gcc
sudo apt install clang
```
Now we’ll install AFL with the following commands:
```
wget http://lcamtuf.coredump.cx/afl/releases/afl-latest.tgz
tar -xzvf afl-latest.tgz
cd afl-2.52b/
make
sudo make install
```
AFL comes with multiple compilers to instrument binaries (we’ll talk about what instrumenting a binary means) which include the traditional gcc as well as clang and hence, even though after the previous step we’re ready to fuzz applications but the default gcc compiler that comes with AFL is slower compared to other upstream compilers that come with it. AFL leverages LLVM capabilities to make the fuzzing process faster. We can enable LLVM mode in AFL with the following commands:
```
cd afl-2.51b/llvm_mode/
sudo apt-get install llvm-dev llvm
make
cd ..
make
sudo make install
```
## Setting up a Target

Now, we’re ready to fuzz applications, all we need is a target. We’ll use fuzzgoat, which is an intentionally vulnerable application written to demonstrate fuzzing. We can clone fuzzgoat from its repository as follows:
```
git clone https://github.com/fuzzstati0n/fuzzgoat
cd fuzzgoat/
```
## Compiling with AFL

We start off by compiling the binary for the target application with AFL’s compilers. 
    Note: The following commands are being run inside the fuzzgoat’s root directory

So, to compile the application with AFL’s compilers, we have to explicitly mention which one to use. Generally, it’s best to stick to afl-clang-fast but one can also use afl-clang-fast++, afl-gcc or afl-g++ depending on the use case. We’ll use afl-clang-fast:
```
export CC=afl-clang-fast
make
mkdir afl_in
cp /bin/ps afl_in/
```
## Running AFL on Target
```
mkdir afl_out
afl-fuzz -i afl_in -o afl_out -- ./fuzzgoat @@
```

4.How does AFL measure the code coverage? List formula if available.

## Workflow
At a high level, the general workflow for afl-cov is:

   - Create a spare copy of the project sources compiled with gcov profiling support.
   - Run afl-cov while afl-fuzz is building test cases.
   - Review the cumulative code coverage results in the final web report.

Now, in more detail:

- Copy the project sources to two different directories /path/to/afl-fuzz-output/ and /path/to/project-gcov/. The first will contain the project binaries compiled for AFL fuzzing, and the second will contain the project binaries compiled for gcov profiling support. For the /path/to/project-gcov/ directory, compile the project with gcov profiling support (gcc -fprofile-arcs -ftest-coverage).

- Start up afl-cov in --live mode before also starting the afl-fuzz fuzzing cycle. The command line arguments to afl-cov must specify the path to the output directory used by afl-fuzz, and the command to execute along with associated arguments. This command and arguments should closely resemble the manner in which afl-fuzz executes the targeted binary during the fuzzing cycle. Note that if there is already an existing directory of AFL fuzzing results, then just omit the --live argument to process these results. Here is an example:
```
$ cd /path/to/project-gcov/
$ afl-cov -d /path/to/afl-fuzz-output/ --live --coverage-cmd \
"cat AFL_FILE | LD_LIBRARY_PATH=./lib/.libs ./bin/.libs/somebin -a -b -c" \
--code-dir .
```
Note the AFL_FILE string above refers to the test case file that AFL will build in the queue/ directory under /path/to/project-fuzz. Just leave this string as-is - afl-cov will automatically substitute it with each AFL queue/id:NNNNNN* in succession as is builds the code coverage reports.

Also, in the above command, this handles the case where the AFL fuzzing cycle is fuzzing the targeted binary via stdin. This explains the cat AFL_FILE | ... ./bin/.lib/somebin ... invocation. For the other style of fuzzing with AFL where a file is read from the filesystem, here is an example:
```
$ cd /path/to/project-gcov/
$ afl-cov -d /path/to/afl-fuzz-output/ --live --coverage-cmd \
"LD_LIBRARY_PATH=./lib/.libs ./bin/.libs/somebin -f AFL_FILE -a -b -c" \
--code-dir .
```
With afl-cov running, open a separate terminal/shell, and launch afl-fuzz:
```
$ cd /path/to/project-fuzzing/
$ LD_LIBRARY_PATH=./lib/.libs afl-fuzz -T somebin -t 1000 -i ./test-cases/ \
-o /path/to/afl-fuzz-output/ ./bin/.libs/somebin -a -b -c
```
The familiar AFL status screen will be displayed, and afl-cov will start generating code coverage data. AFL fuzzing status screen Here is a sample of what the afl-cov output looks like:
```
$ afl-cov -d /path/to/afl-fuzz-output/ --live --coverage-cmd \
"LD_LIBRARY_PATH=./lib/.libs ./bin/.libs/somebin -f AFL_FILE -a -b -c" --code-dir .
[+] Imported 184 files from: /path/to/afl-fuzz-output/queue
[+] AFL file: id:000000,orig:somestr.start (1 / 184)
    lines......: 18.6% (1122 of 6032 lines)
    functions..: 30.7% (100 of 326 functions)
    branches...: 14.0% (570 of 4065 branches)
[+] AFL file: id:000001,orig:somestr256.start (2 / 184)
    lines......: 18.7% (1127 of 6032 lines)
    functions..: 30.7% (100 of 326 functions)
    branches...: 14.1% (572 of 4065 branches)
[+] Coverage diff id:000000,orig:somestr.start id:000001,orig:somestr256.start
    Src file: /path/to/project-gcov/lib/proj_decode.c
      New 'line' coverage: 140
      New 'line' coverage: 141
      New 'line' coverage: 142
    Src file: /path/to/project-gcov/lib/proj_util.c
      New 'line' coverage: 217
      New 'line' coverage: 218
[+] AFL file: id:000002,orig:somestr384.start (3 / 184)
    lines......: 18.8% (1132 of 6032 lines)
    functions..: 30.7% (100 of 326 functions)
    branches...: 14.1% (574 of 4065 branches)
[+] Coverage diff id:000001,orig:somestr256.start id:000002,orig:somestr384.start
    Src file: /path/to/project-gcov/lib/proj_decode.c
      New 'line' coverage: 145
      New 'line' coverage: 146
      New 'line' coverage: 147
    Src file: /path/to/project-gcov/lib/proj_util.c
      New 'line' coverage: 220
      New 'line' coverage: 221
[+] AFL file: id:000003,orig:somestr.start (4 / 184)
    lines......: 18.9% (1141 of 6032 lines)
    functions..: 31.0% (101 of 326 functions)
    branches...: 14.3% (581 of 4065 branches)
[+] Coverage diff id:000002,orig:somestr384.start id:000003,orig:somestr.start
    Src file: /path/to/project-gcov/lib/proj_message.c
      New 'function' coverage: validate_cmd_msg()
      New 'line' coverage: 244
      New 'line' coverage: 247
      New 'line' coverage: 248
      New 'line' coverage: 250
      New 'line' coverage: 255
      New 'line' coverage: 262
      New 'line' coverage: 263
      New 'line' coverage: 266
.
.
.
[+] Generating lcov web report in: /path/to/afl-fuzz-output/cov/web/lcov-web-final
[+] Coverage diff id:000182,src:000000,op:havoc,rep:64 id:000184,src:000000,op:havoc,rep:4
[+] Final zero coverage report in: /path/to/afl-fuzz-output/cov/zero-cov/zero-cov-final
[+] Processed 184 / 184 files
```
In the last few lines above, the locations of the final web coverage and zero coverage reports are shown. The zero coverage reports contains function names that were never executed across the entire afl-fuzz run.

The code coverage results in `/path/to/afl-fuzz-output/cov/web/lcov-web-final` represent cumulative code coverage across all AFL test cases. This data can then be reviewed to ensure that all expected functions are indeed exercised by AFL - just point a web browser at `/path/to/afl-fuzz-output/cov/web/lcov-web-final/index.html.`

5.what is fork server why does AFL use it during the fuzzing?


To improve performance, afl-fuzz uses a "fork server", where the fuzzed process
goes through execve(), linking, and libc initialization only once, and is then
cloned from a stopped process image by leveraging copy-on-write. The
implementation is described in more detail here:

  http://lcamtuf.blogspot.com/2014/10/fuzzing-binaries-without-execve.html

The fork server is an integral aspect of the injected instrumentation and
simply stops at the first instrumented function to await commands from
afl-fuzz.

With fast targets, the fork server can offer considerable performance gains,
usually between 1.5x and 2x. It is also possible to:

  - Use the fork server in manual ("deferred") mode, skipping over larger,
    user-selected chunks of initialization code. It requires very modest
    code changes to the targeted program, and With some targets, can
    produce 10x+ performance gains.

  - Enable "persistent" mode, where a single process is used to try out
    multiple inputs, greatly limiting the overhead of repetitive fork()
    calls. This generally requires some code changes to the targeted program,
    but can improve the performance of fast targets by a factor of 5 or more
    - approximating the benefits of in-process fuzzing jobs while still
    maintaining very robust isolation between the fuzzer process and the
    targeted binary.
