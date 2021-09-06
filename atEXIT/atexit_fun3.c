/* the same function can be registered more than once */

#include <stdio.h>
#include <stdlib.h>
void Testfunction1() //defining the function
{
    printf("This is Testfunction1\n");
}
int main ()
{
    int status;
    //register the termination functions
    //if successfully register return 0
    status = atexit(Testfunction1);
    status = (status == 0)? atexit(Testfunction1):1;
    status = (status == 0)? atexit(Testfunction1):1;
    if (status != 0)
    {
        printf("Registration Failed\n");
        exit(1);
    }
    printf("Registration successful\n\n");
    return 0;
}
