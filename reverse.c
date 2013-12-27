#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int x = 12345;
	int order = 0;
	int tmp = 0;
	int i = 0;
	int result = 0;

	tmp = x;

	while(tmp = tmp / 10)
	{
		printf("tmp = %u\n", tmp);
		order += 1;
	}


	printf("order = %u\n", order);
	tmp = 0;
	//for( i = 0; order >= 0; order-=1, i++)
	while(order >= 0)
	{
		tmp = x / (int)pow(10, order);
		printf("tmp=%u\n", tmp);
		result += tmp * (int)pow(10, i);
		printf("result=%u\n", result);
		x = x % (int)pow(10, order);
		printf("x=%u, order=%u\n", x, order);
		i++;
		order--;
		//if(order == 0)
		//	break;
	}
	
	printf("result=%u\n", result);




	return 0;
}
