CC= gcc 

FLAGS = -G -O0 -o

a.out : atexit_fun1 atexit_2 atexit_fun3

%.O : %.c

$(CC) $(FLAGS) %^

clean:

rm -rf *.o out
