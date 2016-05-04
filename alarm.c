#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void signal_handler(int signo)
{
	switch(signo)
	{
		case SIGALRM:
				printf("alarm timeout\n");
				break;
		default:
				printf("Singnal [%d] received\n",signo);
				break;
	}
}

int main()
{
	signal(SIGALRM, signal_handler);
	alarm(2);
	pause();
	return 0;
}
