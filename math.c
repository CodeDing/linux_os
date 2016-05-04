#include <math.h>
#include <stdio.h>

int main()
{
	int exp;
	double fraction;
	
	fraction = frexp(512, &exp);
	printf(" exp = %d\n", exp);
	printf(" fraction = %f\n", fraction);
	return 0;
}
