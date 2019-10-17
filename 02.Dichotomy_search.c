#include <stdio.h>

/*二分法测试*/

/*无重复的序列*/
int array[10] = {8, 11, 20, 22, 25, 30, 46, 58, 66, 100};

/*查找有重复的序列*/
int brray[10] = {8, 11, 20, 22, 25, 46, 46, 46, 66, 100};

int dichotomy_search1(int *arr, int size, int value)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] > value)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}


int dichotomy_search2(int *arr, int size, int value)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (arr[mid] == value) {
            if (mid == 0 || arr[mid -1] != value)
                return mid;
            else
                high = mid - 1;
        }
        else if (arr[mid] > value)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

void dump_data(int *array, int size)
{
    int num;
    for (num = 0; num < size; num++)
        printf("[%02X]:%d\n", num, array[num]);
}

void main(void)
{
    /*test array*/
    int ret;
    ret = dichotomy_search1(array, 10, 30);
    printf("get pos %d\n", ret);

    /*查找第一个值为４６的位置，dichotomy_search1不适用*/
    ret = dichotomy_search1(brray, 10, 46);
    printf("get pos %d\n", ret);

    /**/
    ret = dichotomy_search2(brray, 10, 46);
    printf("get pos %d\n", ret);
    
    printf("-------------brray-------------\n");
    dump_data(brray, 10);
}
