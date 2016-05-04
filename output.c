#include <stdio.h>
#include <stdlib.h>

int main()
{
   struct args {
        long    arg1;
        long    arg2;
    }args;

    struct result {
        long    sum;
    };
#define MAXLINE 1024
    char sendline[MAXLINE];

    while(fgets(sendline, MAXLINE, stdin) != NULL){
        if(sscanf(sendline, "%ld%ld", &args.arg1, &args.arg2) != 2){
            printf("invalid input: %s", sendline);
            continue;
        }
		break;
    }
    printf("args.arg1 = %ld\n", args.arg1);
    printf("args.arg2 = %ld\n", args.arg2);
    return 0;

}
