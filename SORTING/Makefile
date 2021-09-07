CC= gcc 

FLAGS = -G -O0 -o

a.out : bubblesort1 insertionsort

%.O : %.c

$(CC) $(FLAGS) %^

clean:

rm -rf *.o out
