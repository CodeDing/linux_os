#include <stdio.h>
#include <stdlib.h>

int main()
{
	char   *p;
	int 	backlog;
	if((p = getenv("USER")))
	    printf("USER = %s\n", p);
	setenv("USER", "test", 1);
	printf("USER = %s\n", getenv("USER"));
	unsetenv("USER");
	printf("USER = %s\n", getenv("USER"));
	if( (p = getenv("LISTENQ")) != NULL)
		backlog = atoi(p);
	printf("backlog = %d\n", backlog);
	return 0;

}
