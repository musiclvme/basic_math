#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N           10

/*we select a random value which is less than 101*/
#define RANDOM_VAL  101
int array[N] = {1,3,2,4,5,6,7,8,9,10};

void dump_data(int *array, int size)
{
    int num;
    for (num = 0; num < size; num++)
        printf("[%02X]:%d\n", num, array[num]);
}

void random_produce(int *array, int size)
{
    int num;
    srand(time(NULL));
    for (num = 0; num < size; num++) {
        array[num] = rand()%RANDOM_VAL;
    }
    printf("random_produce is done...\n");
}

/*bubble*/
/*冒泡排序*/
void bubble(int *array, int size)
{
    int num;
    int tmp;
    int j;
    bool swap;
    for (num = 0; num < size; num++) {
        swap = false;
        for (j = 0 ; j < size - num - 1; j++) {
            if (array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                swap = true;
            }
        }
        if (swap == false)
            break;

    }
    dump_data(array, size);
}

/*insert*/
/*插入排序*/
void insert(int *array, int size)
{
    int i;
    int j;
    int tmp;

    for (i = 1; i < size; i++) {
        tmp = array[i];
        j = i - 1;
        for (; j >= 0; j--) {
            if (tmp < array[j])
                array[j+1] = array[j];
            else
                break;
        }
        array[j+1] = tmp;
    }
    dump_data(array, size);
}


/*select*/
/*选择排序:和冒泡有点相似,但是每次在对比的时候不是直接交换,而是获取最小值的index
**然后在一次循环完成后就可以得到最小值的index,这样就可以再进行交换*/

void select_sort(int *array, int size)
{
    int num;
    int tmp;
    int j;
    int min;
    bool swap;
    for (num = 0; num < size - 1; num++) {
        j = num + 1;
        min = num;
        for (; j < size; j++)
            if (array[min] > array[j])
                min = j;
        
        if (min != num) {
            tmp = array[num];
            array[num] = array[min];
            array[min] = tmp;
        }
    }
    dump_data(array, size);
}

void main(void)
{
    random_produce(array, N);
    dump_data(array, N);
    bubble(array, N);
    
    #if 1
    random_produce(array, N);
    dump_data(array, N);
    insert(array, N);
    #endif

    random_produce(array, N);
    dump_data(array, N);
    select_sort(array, N);
}
