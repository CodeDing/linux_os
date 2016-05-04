#include <stdio.h>

typedef void *(Func)(void *);
typedef void *(*pFunc)(void *);

void *print_msg(void * msg)
{
    printf("%s\n", (char *)msg);
    return NULL;
}

int main()
{
   pFunc print_p;
   print_p = &print_msg;
   print_p("world");
   return 0; 
}
