#include <sys/select.h>
#include <stdio.h>

int main(int argc, char **argv)
{
#ifdef _STDIO_H
   printf("_STDIO_H has been defined!\n");
#endif

#ifdef __USE_MISC
   printf("__USE_MISC has been defined!\n");
#endif

#ifdef __KERNEL__
   printf("__KERNEL__ has been defined!\n");
#endif

#ifdef __WORDSIZE
   printf("__WORDSIZE has been defined!\n");
#endif

#ifdef FD_SETSIZE
   printf("FD_SETSIZE has been defined, FD_SETSIZE = %d\n", FD_SETSIZE);
#endif

#ifdef __USE_XOPEN2K
   printf("__USER_XOPEN2K has been defined!\n");
#else
   printf("__USER_XOPEN2K has not been defined!\n");
#endif

#ifdef __USE_GNU
   printf("__USE_GNU has been defined!\n");
#else
   printf("__USE_GNU has not been defined!\n");
#endif

#ifndef __LITTLE_ENDIAN__
   printf("__LITTLE_ENDIAN__ has not been defined!\n");
#else
   printf("__LITTLE_ENDIAN__ has been defined!\n");
#endif


#ifndef __STRICT_ANSI__
   printf("__STRICT_ANSI__ has not been defined!\n");
#endif

#ifdef __x86_64__
   printf("__x86_64__ has been defined!\n");
#endif

#ifdef __GNUC__
   printf("__GNUC__ has been defined!\n");
#else
   printf("__GNUC__ has been not defined!\n");
#endif

#if __GNUC__ >= 2
   printf("__GNUC__ >= 2!\n");
#endif

#ifdef __STDC_VERSION__
   printf("__STDC_VERSION__ has been defined!\n");
#else
   printf("__STDC_VERSION__ hse not been defined!\n");
#endif
   return 0;

}

