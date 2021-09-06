

 /*If more than one atexit functions are registered, they are executed in the reverse order. It means the function registered at last is executed at first. Let’s see the example code.*/

#include <stdio.h>
#include <stdlib.h>

/*
func – pointer to a function to be called on normal program termination
Return:

The atexit function returns zero if the registration succeeds, nonzero if it fails. It means,
*/
void Testfunction1() //defining the functions
{
    printf("This is Testfunction1\n");
}
void Testfunction2() // function 2
{
    printf("This is Testfunction2\n");
}
void Testfunction3() // function 3
{
    printf("This is Testfunction3\n");
}
int main ()
{
    int status;
    //register the termination functions

    status = atexit(Testfunction1);// status is updated
    status = (status == 0)? atexit(Testfunction2):1;    //if successfully register return 0
    status = (status == 0)? atexit(Testfunction3):1;
    if (status != 0)
    {
        printf("Registration Failed\n");
        exit(1);
    }
printf("registration succesfull\n\n"):
return 0;
}
