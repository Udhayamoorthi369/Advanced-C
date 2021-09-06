


#include <stdio.h>
#include <stdlib.h>

/*
func – pointer to a function to be called on normal program termination
Return:

The atexit function returns zero if the registration succeeds, nonzero if it fails. It means,
*/

void Testfunction ()  // defining the function
{
    printf("This is Testfunction\n");
}
int main ()
{
    int status;
    //register the termination function
    status = atexit(Testfunction); // status is updated
    if (status != 0)
    {
        printf("Registration Failed\n");
    //    Non zero if the function registration failed.

        exit(1);
    }
    printf("Registration successful\n");// Zero if the function registration is successful.
   
    return 0;
}


