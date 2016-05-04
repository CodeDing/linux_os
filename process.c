#include <unistd.h>
#include <sys/types.h>

int main()
{
	printf("gid is %d\n", getgid);
	sleep(10);
	return 0;
}
