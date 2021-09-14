void display_uid()
{
int r = getuid();
int euid = geteuid();
printf("the uid :%d\n",r);
printf("euid : %d\n",euid);
}
