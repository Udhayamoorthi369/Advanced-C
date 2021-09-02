all: output

output: main.o file1.0 file_read.o
        g++ main.o file1.o file_read.o output

main.o: main.c
        g++ -c main.c

file1.o: file1.c
         g++ -c file1.c

file_read.o: file_read.c
          g++ -c file_read.c

clean: 
       rm -rf *o output
