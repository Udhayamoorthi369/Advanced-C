C= gcc 

FLAGS = -G -O0 -o

a.out : word_clw.c

word_clw: word_clw.c

         $(CC) $(CFLAGS) -o word_clw word_clw.c

%.O : %.c

$(CC) $(FLAGS) %^

clean:

rm -rf *.o out
