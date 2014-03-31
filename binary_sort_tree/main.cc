#include "binary_sort_tree.h"
#include <stdio.h>

#define ARR_LEN 16

static int compare(void *elem1, void *elem2)
{
    int *vp1 = (int *)elem1;
    int *vp2 = (int *)elem2;

    return *vp1 - *vp2;
}

static void print(int ret)
{
    if (ret == E_FAILURE)
    {
        printf("return failed!\n");
    }
    else if (ret == E_SUCCESS)
    {
        printf("return success!\n");
    }
}


static void test()
{
    int arr[ARR_LEN] = {0};
    for (int i = 0; i < ARR_LEN; i++)
    {
        arr[i] = i + 1;
    }

    BinarySortTree ptree;
    ptree.init(arr, ARR_LEN, sizeof(int), compare);

    printf("------------key is 10---------\n");
    int key = 10;
    int ret = ptree.find_node(&key, compare);
    print(ret);

    printf("------------key is 20---------\n");
    key = 20;
    ret = ptree.insert_node(&key, sizeof(int), compare);
    print(ret);
    ret = ptree.find_node(&key, compare);
    print(ret);
    ret = ptree.delete_node(&key, compare);
    print(ret);

    printf("------------key is 30---------\n");
    key = 30;
    ret = ptree.find_node(&key, compare);
    print(ret);
    ret = ptree.delete_node(&key, compare);
    print(ret);

}


int main(int argc, char const *argv[])
{
    test();
    return 0;
}