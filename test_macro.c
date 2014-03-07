#include <stdio.h>
#include <stdlib.h>

#define DECLARE_SYSRES(id, size) [id] = {id, size, 0}

typedef struct sysgResource_s{
	unsigned int id;
	unsigned int size;
	void *addr;
}sysgResource_t;

static sysgResource_t sysResArray[] = {
	
	DECLARE_SYSRES(0, 3*1024),
	DECLARE_SYSRES(1, 1),
	DECLARE_SYSRES(2, 2),
	DECLARE_SYSRES(3, 3),

	DECLARE_SYSRES(0x10, 0x10),
	DECLARE_SYSRES(0x11, 0x11),

};

int main()
{
	unsigned int i = 0;
	sysgResource_t *res = sysResArray;

	for(i = 0; i < sizeof(sysResArray)/sizeof(sysgResource_t); i++)
	{

		printf("res[%u].id = %u, res[%u].size = %u\n", 
			i, res[i].id, i, res[i].size);
	}

	return 0;
}
