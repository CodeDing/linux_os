/*
*  ./a.out -a1 -b2 -c -d
   argc = 5;
   argv[0] = ./a.out
   argv[1] = -a1
   argv[2] = -b2
   argv[3] = -c
   argv[4] = -d
   :表示该选项带有额外的参数，全域变量optarg指向额外参数
　::表示该额外的参数可选，有些系统可能不支持
　optind:指示下一个要读取的参数在argv中的位置，从下标１开始计数

*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char**argv)
{
	int ch;
	opterr = 0;
	while( (ch=getopt(argc,argv,"a:b::cde"))!=-1 )
	{
		printf("optind:%d\n",optind);
		printf("optarg:%s\n",optarg);
		printf("ch:%c\n",ch);
		switch(ch)
		{
		  case 'a':
			  printf("option a: '%s'\n",optarg);
			  break;
		  case 'b':
			  printf("option b: '%s'\n",optarg);
			  break;
		  case 'c':
			  printf("option c\n");
			  break;
		  case 'd':
			  printf("option d\n");
		  	  break;
		  case 'e':
			  printf("option e\n");
			  break;
		  default:
			  printf("other option: %c\n",ch);
		}
		printf("optopt + %c\n",optopt);
	}
	return 0;
}
