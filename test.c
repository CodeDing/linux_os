#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
	double ans;
	ans = log10(100);
	printf("log10(100) = %f\n",ans);

    char a[16];
    size_t i;

    i=snprintf(a,13,"%012d",12345);
    printf("i = %lu, a = %s\n",i,a);
 
    i=snprintf(a,9,"%012d",12345);
    printf("i = %lu, a = %s\n",i,a);

    char str[10]={0};
    int nLen=snprintf(str,strlen("0123456789012345678")+1,"0123456789112345678");
    printf("str = %s\n",str);
    printf("nLen = %d\n",nLen);
    printf("The size of str is %d\n",sizeof(str));

	int fd;  
    char *file = "/dev/tty";
    fd = open(file, O_RDONLY);
    printf("%s ", file);
    if(isatty(fd)){
		printf(" is a tty.\n");
		printf("ttyname = %s\n", ttyname(fd));
    }
    else 
		printf("is not a tty!\n");
    close(fd);
    
	char name[13];
	tmpnam(name);
	printf("Temporary name: %s\n", name);

	printf("%x\n", a);
	printf("%x\n", a+1);
	printf("%x\n", &a);
	printf("%x\n", &a+1);	
    return 0;

}
