ZZ

/*modifies any data other than a variable of types pid_t
 * return from the function in which vfork was called\
 */
#include<stdio.h>

int main()
{
	if(vfork()==0)// create achild process & block parents
	{
		printf("in child..\n"); // in child
		sleep(10);//10ms sleep
		printf("child exit..\n");//when child is exit
		exit(0);
	}
	else
		printf("parents..\n");// in parents
}

