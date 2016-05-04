#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int Allocation_handled = 0;
jmp_buf Allocate_Failed;

void *allocate(unsigned int n)
{
    void *new = (void *)malloc(n);
    if(new)
        return new;
    if(Allocation_handled)
        longjmp(Allocate_Failed, 1);
    assert(0);

}

int main()
{
    char *buf = 0;
    int count = 0;
    Allocation_handled = 1;
    if(setjmp(Allocate_Failed))
    {
        fprintf(stderr, "Except: couldn't allocate the buffer\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        buf = (char *)allocate(40960000);
        printf("Allocate successs, the coutn is %d\n",count++);
        
    }
    return 0;
}
