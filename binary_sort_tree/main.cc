#include "binary_sort_tree.h"
#include <stdio.h>
#include <string>

#define ARR_LEN 16

static int compare(void *elem1, void *elem2)
{
    int *vp1 = (int *)elem1;
    int *vp2 = (int *)elem2;

    return *vp1 - *vp2;
}

static void print(const std::string &str, int ret)
{
    if (ret == E_FAILURE)
    {
        printf("%s failed!\n", str.data());
    }
    else if (ret == E_SUCCESS)
    {
        printf("%s success!\n", str.data());
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
    print("find_node:10", ret);

    printf("------------key is 20--------\n");
    key = 20;
    ret = ptree.delete_node(&key, compare);
    print("delete_node:20", ret);

    printf("------------key is 25---------\n");
    key = 25;
    ret = ptree.find_node(&key, compare);
    print("find_node:25", ret);

    printf("------------key is 30---------\n");
    key = 30;
    ret = ptree.insert_node(&key, sizeof(int), compare);
    print("insert_node:30", ret);
    ret = ptree.find_node(&key, compare);
    print("find_node:30", ret);
    ret = ptree.delete_node(&key, compare);
    print("delete_node:30", ret);
    ret = ptree.find_node(&key, compare);
    print("find_node:30", ret);
}


int main(int argc, char const *argv[])
{
    test();
    return 0;
}
