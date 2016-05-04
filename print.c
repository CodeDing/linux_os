#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
errno = 12;
int main()
{
	printf("Hello");
	fflush(stdout);	
	sleep(5);
	int 	skfd;
	skfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Default socket buffer is %lu\n", fpathconf(skfd, _PC_SOCK_MAXBUF));	

    printf("Hello, world\n");	
	perror("x");
	return 0;
}
