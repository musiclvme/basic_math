#include <stdio.h>

// find local minimum value in a scope of L length

int array[24] = {1,2,3,4,
				 9,5,11,9,
				 10,20,18,17,
				 5,4,3,2,
				 1,3,7,6,
				 5,4,10,1};

#define BATCH_SIZE 4
#define L 2

void main(void)
{
	int i,j;
	int min[BATCH_SIZE];
	int tmp[BATCH_SIZE];
	int val[BATCH_SIZE];
	int len = sizeof(array)/sizeof(int);
	int loop = len / BATCH_SIZE;
	int batch_num = 0;

	for (i = 0; i < len; i++) {
		if ( i % BATCH_SIZE == 0)
			printf("\n[%02d]:", i);
		printf("%3d ", array[i]);
	}
	printf("\n");
	for (j = 0; j < loop; j++) {
		memcpy(&val[0], &array[j*BATCH_SIZE], BATCH_SIZE * sizeof(int));
		batch_num++;
		if (batch_num == 1) {
			memcpy(&min[0], &val[0], BATCH_SIZE * sizeof(int));
			memcpy(&tmp[0], &val[0], BATCH_SIZE * sizeof(int));
		}

		if (batch_num % L == 0) {
			for (i = 0; i< BATCH_SIZE; i++) {
				min[i] = tmp[i] < val[i]? tmp[i]:val[i];
				tmp[i] = val[i];
			}
		} else {
			for (i = 0; i < BATCH_SIZE; i++) {
				min[i] = min[i] < val[i]? min[i]:val[i];
				tmp[i] = tmp[i] < val[i]? tmp[i]:val[i];
			}
		}

		printf("------end-------batch_num=%d----------------\n", batch_num);
		printf("min[%d %d %d %d]\n", min[0],min[1],min[2],min[3]);
		printf("tmp[%d %d %d %d]\n", tmp[0],tmp[1],tmp[2],tmp[3]);
		printf("\n");
	}
}

