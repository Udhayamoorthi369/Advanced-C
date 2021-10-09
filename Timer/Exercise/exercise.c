/* All of the includes for the project go here … 
 * those includes must support signals, interval timers,
 * read, open, and close. You will also need support for 
 * error numbers
 */
#include<errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include<stdarg.h>
#include<fcntl.h>
#include<string.h>
#include<sys/time.h>
//#include<sys/signals.h>
#include<semaphore.h>
#include<assert.h>
#include<time.h>
#include<pthread.h>
//#include "tlpi_hde.h"

/* Problem 1 – complete the list of include files */
#define STDOUT 1
#define STDIN 0
#define BUF_SIZE 1024
//#define MILLION 1000000
timer_t gTimerid;
static int timed;

/* the myPrint function takes a constant c-string
 * and outputs it to STDOUT using write
 * feel free to use string functions like strcmp, strcat, etc 
 * to make this one work
 * myPrint returns 0 on failure and 1 on success
 */
int myPrint(const char *str)
{

	/* Problem 2 – implement myPrint using write */ 
	//char buf[]="hello\n";
	if(write(1,str,strlen(str))==-1);
	{
		return 0;
	}


	return 1;
}

/* the myPrintInt function takes a constant int
 * and outputs it to STDOUT using write
 * feel free to use string functions like strcmp, strcat, etc 
 * to make this one work
 * myPrintInt returns 0 on failure and 1 on success
 * Note: you will need to convert the int to a c-string
 * to make it readable
 */
int myPrintInt(const int val)
{
	/* Problem 3 – Implement myPrintInt, you can use write or another existing function you have already defined */ 
	char buf[256];
	//numRead=3;
	sprintf(buf,"%d",val);
	if(write(1,buf,strlen(buf)) == -1)
	{ 
		return 0;
		//printf("\n the string for the num is %s ",buf);
	}
	return 1;
}

/* implement the signal hadler below ...
 * use the provided prototype
 * It must handle two signals, SIGINT and SIGALRM
 * if the signal handler receives SIGINT
 * prompt the user if they want to exit or not
 * on yes, exit successfully, on no, just return from the handler
 * on SIGALRM, set the timedout flag to 1
 */
void signalHandler(int sig)
{ 
	static const char *signals="\n Timer expired  \n";
	char option;	
	if(SIGINT==sig)
		printf("\n Exit: Are you sure {Y|N} ");
	scanf("%c", &option);
	if(option == 'y' || option == 'Y')
	{
		printf("\n Exit successfully \n ");
		exit(0);
	}
	else if (option == 'n' || option == 'N')
	{
		return main();
	}

	printf("received SIGINT \n");
	assert(sig == SIGALRM);
	write(2,signals,sizeof(signals)-1);
	exit(1);/*
      write(STDOUT,"\nexit:are you sure (Y/n)? ",strlen("\nexit:are you sure (Y/n)? "));
read(STDIN,buff,sizeof(buff));
if('Y'==buff[0])
{
exit(0);
}
else if(SIGALRM == sig)
{
printf("alarm occured\n");
}*/
}
/* Problem 4 – implement the signalHandler .. 
 * when writing the prompt for SIGINT and reading the reply
 * use system calls … please also remember to read more than 1
 * character when reading the response since that response has at least
 * two characters in it. Yes the responses of ‘Y’ and ‘n’ involve multiple 
 * characters
 */


/* This function reads a line of text from a file
 * we are simulating another functions behavior here ..
 * the basic idea is to read the file character by character til we find
 * the \n or \r
 * Go ahead and tack the null character on here for simplicity
 * Return a 0 if no characters were read, return a 1 otherwise
 */
int readLine(int fd, char *line)
{
	/* Problem 5 – implement readLine as described about ... again
	 * remember to use read to do this …. This is probably best accomplished by
	 * reading in 1 character at a time and then adding them to the array
	 * you passed in as line
	 */char ch;
	while(read(fd,&ch,1))
	{
		if(ch=='\n')
		{
			*line = '\0';
			return 1;
		}
		*line=ch;
		line++;}
	return 0;

}



/* This function reads a question answer pairing
 * from the provided pair of file descriptors
 * It returns 0 if the files are empty
 * and 1 if if successfully reads the pairing
 * notice it calls the custom function readLine since we
 * need to read only one line at a time
 */

int readQA(int questFd, int ansFd, char *quest, char *ans)
{
	if (readLine(questFd,quest) == 0) return 0; 
	if (readLine(ansFd, ans) == 0) return 0;
	return 1;
}
void DoStuff(void)
{
printf("timer went off \n");
}
int main(int argc, char *argv[])
{

	int numRead = 0;
	int numWrite = 0;
	int question = 1;
	int correct = 0;
	char buf[BUF_SIZE];
	char quest[BUF_SIZE];
	char ans[BUF_SIZE];
	int questFd, ansFd;
	struct itimerval it_val;
	char option;
	char string[BUFSIZ];
	//	signal(SIGINT, signalHandler);
	//struct itimerval tval;
	struct sigaction sa;
	int savedErrno;
if(signal(SIGALRM,(void (*)(int)) DoStuff) == SIG_ERR){
perror("unable to catch SIGALRM");
exit(1);
}it_val.it_value.tv_sec = 30;//waits for 30 seconds before sending timer signal
        it_val.it_value.tv_usec = 0;
it_val.it_interval = it_val.it_value;
if(setitimer(ITIMER_REAL,&it_val,NULL) == -1)
{
perror("error calling setitimer()");
exit(1);
while(1)
pause();
}

	/* declare structures for signals and timers. 
	 * you will have only one timer, but it has two 
	 * sets of values … one at 30 seconds and one at
	 * 0 seconds
	 *///sa.sa_handler = signalHandler;
           //sa.sa_flags =0;
// sigemptyset (&sa.sa_mask);

//sigaction (SIGINT,&sa,NULL);
//sigaction(SIGALRM,&sa,NULL);
	/* Problem 6a– declare the structures for the signals and timers */

it_val.it_value.tv_sec = 2;//waits for 30 seconds before sending timer signal
        it_val.it_value.tv_usec = 0;
it_val.it_interval = it_val.it_value;

//exit(0);       
// value.it_interval.tv_sec = 0;//sends timer signal every 30 seconds
        //value.it_interval.tv_usec = 0;

//printf("timer went off.\n");

	/* initialize structures for signals and timers 
	 * make certain to actually set a mask this time 
	 * add both SIGINT and SIGALRM to the mask 
	 */

	/* Problem 6b – initialize the structure for the signal handlers */ 

	/* you get 30 seconds a question ... 
	 * this time has no interval, just a value 
	 */

	//            tval.it_value.tv_sec = 10
	/* you get 30 seconds a question ... 
	 * this time has no interval, just a value 
	 */

	/* Problem 6c – initialize the structure for the 30 sec timer */


	/* you also need to disable the timer when testing
	 * this is done by setting interval and value to 0
	 */

	/* Problem 6d – initialize the structure for the 0 sec timer */


	/* set up the signal handlers */

	/* Problem 7 – associate the SIGINT and SIGALRM with their signal handler */

//signal(SIGINT,signalHandler);
//	signal(SIGALRM,signalHandler);
/* open the question and answer files .. these are simple text files 
	 * called quest.txt and ans.txt. 
	 */

	/* Problem 8 – open the files quest.txt and ans.txt */
	questFd =  open("quest.txt",O_RDONLY);
	if(questFd==-1){
		printf("Error while opening quest.txt file..\n");
		exit(0);
	}
	ansFd = open("ans.txt",O_RDONLY);
	if(ansFd == -1)
	{
		printf("Error while opening ans.txt file...\n");
		exit(0);
	}



//	(void) signal(SIGALRM, timer_callback);
//	start_timer();
//	while(1);

	/* this loop handles the Q/A stuff 
	 * I have included some of it to make you life simpler 
	 * I have also left some commnents to assist you as well 
	 *
	 * read the first question, answer pairing prior to entering the loop
	 */
	readQA(questFd, ansFd, quest, ans);
	while (1)
	{
		/* output the current question */
		myPrint("#");
		myPrintInt(question);
		myPrint(" ");
		myPrint(quest);
		myPrint("? ");
		/* we will set the timedout flag to 0, since it hasn't yet */
		timed = 0;

		/* now set the interval timer prior to reading in the user's response */

		/*  Problem 9 – set the interval timer to go off in 30 seconds */
//it_val.it_value.tv_sec = 2;//waits for 30 seconds before sending timer signal
//        it_val.it_value.tv_usec = 0;
//it_val.it_interval = it_val.it_value;



		/* read in the user's response, this is systems programming so don't use 
		 * scanf */

		/* Problem 10 – read a buffer from STDIN */
		numRead = read(0,buf,BUF_SIZE);

		/* test to see if the user responded and if an error has occurred 
		 * an error can actually occur as part of the functionality of this program 
		 * both SIGINT and SIGALRM will cause the read call to return a -1 
		 * this can be recognized by testing for a specific error number ...  
		 * The error is known as interrupted systems call 
		 * Should this be the case, do the following .... 
		 * If the read call was interrupted and the timedout flag isn't set 
		 * just continue 
		 * if the timedout flag was set, inform the user that time is up 
		 * then go to the next question
		 */
		if (numRead == 0) break;
		if (numRead == -1)
		{
			//savedErrno = errno;
			//alarm(0);
			//errno = savedErrno;

			if (errno == EINTR)
			{
				if (timed)
				{

					myPrint("\nTime's up, next question\n");
					if (readQA(questFd, ansFd, quest, ans) == 0) break;
					question++;
				}
				continue;
			}
			perror("read");
			exit(EXIT_FAILURE);
		}
		/* disable the timer here ...
		 * we are doing stuff that takes time
		 * you can disable the timer by passing
		 * do this by calling the interval time with a value and interval of 0 
		 */
		/* Problem 11 – disable the time by setting it to tvOff */
 //     it_val.it_value.tv_usec = 0;
//it_val.it_interval = it_val.it_value;


		/* we will convert the buf being read in to a c-string by tacking on a 0 */
		buf[numRead-1] = 0;
		/* check the answer */
		if (strcmp(buf,ans) == 0)
		{
			correct++;
			myPrint("\ncorrect\n");
		} else
		{
			myPrint(ans);
			myPrint("\nwrong\n");
		}
		/* read the next question .. break if there are no more questions */
		if (readQA(questFd, ansFd, quest, ans) == 0) break;

		question++;
	}

	myPrint("final score is ");
	myPrintInt(correct);
	myPrint(" out of ");
	myPrintInt(question);

	/* Problem 12 – close both files */
	//fclose(questFd);
	//fclose(ansFd);
}



