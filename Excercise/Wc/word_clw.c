#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


#define MAX_LEN 1024


void usage(char* prog)
{
fprintf(stderr,"usage: %s [-lcw] [filename]\n",prog);
exit(EXIT_FAILURE);
}
int main(int argc,char *argv[]) {
  /*Read the file.*/

  char ch;


int c=0;
int l=0;
int w=0;
  int char_count = 0, word_count = 0, line_count = 0;
  int in_word = 0;
  char file_name[MAX_LEN];
  FILE *fp=fopen("1.txt","r");
int paramcnt;
  //printf("Enter a file name: ");
// scanf("%s", file_name);
void cword()
{
char str[50];
int c=0;
int l=0;
int w=0;
int i=0;
while((ch=fgetc(fp))!=-1)//,"%s",str)!=-1)
{
/*c++;
if(ch == '\n' || ch == '\0')
l++;
*/if(ch==' ' || ch == '\t' || ch =='\n' || ch == '\0' )
w++;
//printf("%s\n",str);
//count++;
}
if (c>0)
{
w++;
l++;
}
printf("no of words = %d\n",w);

}

void l_char()
{
char str[50];
int c=0;
int l=0;
int w=0;
int i=0;
while((ch=fgetc(fp))!=-1)//,"%s",str)!=-1)
{
;
if(ch == '\n' || ch == '\0')
l++;

}
if (c>0)
{
w++;
l++;
}
printf("no of lines = %d\n",l);

}
void c_char()
{
char str[50];
int c=0;
int l=0;
int w=0;
int i=0;
while((ch=fgetc(fp))!=-1)//,"%s",str)!=-1)
{

c++;

}
;

printf("no of char = %d\n",c);


}
int i;
/*! get commadline option information*/
while ((ch=getopt(argc,argv,"clw"))!=-1)
/*! check for option passed*/
{
switch(ch)
{
/*!check if c is passed*/
case 'c':
{
c=1;
c_char();

}
break;
/*!check if option l is passed*/
case 'l':
{
l=1;
l_char();
}
break;
/*!check if option w is passed*/
case 'w':
{
w=1;
cword();
 
}
break;
/*!check if unknown option is passed*/
case '?':
{
usage(argv[0]);
}
break;
}
}

  return 0;
}


