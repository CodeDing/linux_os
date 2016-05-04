/*
	stty -icanon min 1 time 0 //关闭终端标准模式 min:min个字符可以读取时,read才返回 
*/
#include <stdio.h>
#include <unistd.h>

#define MAXSIZE  10

int main()
{
	int 	n;
	char	buf[MAXSIZE];
	while( (n = read(fileno(stdin), buf, MAXSIZE)) > 0){
		printf(" n = %d\n", n);
		printf("buf[n - 1] = %d\n", buf[n - 1]);
	}
	return 0;
}
