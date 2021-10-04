#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<error.h>

void create_struct(char *dir,mode_t mode)
{
char tmp[512];
size_t length;
char *p;

snprintf(tmp, sizeof(tmp),"%s",dir);    

tmp[sizeof(tmp)-1]=='\0';  
    length = strlen(tmp);
            if(tmp[length - 1] == '/')
                    tmp[length - 1] = '\0';
 

for (char* p = strchr(tmp + 1, '/'); p; p = strchr(p + 1, '/')) {
        *p = '\0';
        if (*p == '/') {
            if (*p != '\0') {
                *p = '/';
                //return -1;
            }
        
        *p = '/';
}



if(access(tmp,F_OK))                            
mkdir(tmp, S_IRWXU);
                          *p = '/';
}        
                                    if(access(tmp,F_OK))
mkdir(tmp, S_IRWXU);

}



int main(int argc,char* argv[])
{
char root[512]="23sysprog";
struct stat s;
int cnt;
char buff[1024];
if(argc>1)
{
strcpy(root,argv[1]);
}

if(stat(root,&s)==0){
printf("The Directory already exist\n");
exit(EXIT_FAILURE);
}

create_struct(root,0755);

chdir(root);

mkdir("test",0755);

for(cnt=0;cnt<3;cnt++){
sprintf(buff,"test/test%d",cnt+1);
create_struct(buff,0755);
}

mkdir("program",0755);

for(cnt=0;cnt<5;cnt++){
sprintf(buff,"program/program%d",cnt+1);
create_struct(buff,0755);
}

//mkdir("excercise",0755);

for(cnt=0;cnt<10;cnt++){
sprintf(buff,"exercise/exec%d",cnt+1);
create_struct(buff,0755);
}
return 0;
}
