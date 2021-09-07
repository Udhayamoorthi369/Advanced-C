CC= gcc 

FLAGS = -G -O0 -o

a.out : file1 file_read

%.O : %.c

$(CC) $(FLAGS) %^

clean:

rm -rf *.o out
