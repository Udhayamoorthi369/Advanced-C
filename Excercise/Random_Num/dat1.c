

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char    str[10];
    FILE    *fptr;
    int     i;
    int     num;
    char    num2;
    i = 0;
    int x=rand()%255+1;
    fptr = fopen("dataX1.dat", "w");

    if (fptr == NULL)
    {
        printf("ERROR Creating File!");
        exit(1);
    }
//    while (str[i] != '\0')

for (int i = 0; i < 60; ++i)
{
  fprintf(fptr, "%d\n", rand() % 100);
}
fprintf(fptr, "\n");  
  puts(str);
    fprintf(fptr,"%s", str);
    fclose(fptr);
    printf("%d\n",x);
    return (0);
}


