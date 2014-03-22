#include <stdio.h>
#include <vector>
#include <algorithm>


static bool compare(int a, int b)
{
    return a > b ? true : false;
}

static void print(const std::vector<std::vector<int> > &ivec)
{
    for (unsigned int i = 0; i < ivec.size(); i++)
    {
        for (unsigned int j = 0; j < ivec[i].size(); j++)
        {
            printf("%d ", ivec[i][j]);
        }
        printf("\n");
    }
}

static void store_result(int *arr, const std::vector<int> &ivec, std::vector<std::vector<int> > &result)
{
    std::vector<int> res;
    for (unsigned int index = 0; index < ivec.size(); index++)
    {
        if (ivec[index] == 1)
        {
            res.push_back(arr[index]);
        }
    }

    result.push_back(res);
}

static void combination_total(int *arr, int total)
{
	printf("------------combination_total------------\n");

    std::vector<std::vector<int> > result;

    for (int i = 0; i < (1 << total); i++)
    {
        std::vector<int> res;
        for (int j = 0; j < total; j++)
        {
            if (((i >> j) & 1) == 1)
            {
                res.push_back(arr[j]);
            }
        }
        result.push_back(res);
    }

    print(result);
}

static void combination_num(int *arr, int num, int total)
{
	printf("\n------------combination_num:%d------------\n", num);

    std::vector<std::vector<int> > result;

    //initial first combination like: 1, 1, 1, 0, 0, 0
    std::vector<int> ivec(total, 0);
    for (int i = 0; i < num; i++)
    {
        ivec[i] = 1;
    }
    store_result(arr, ivec, result);

    for (int i = 0; i < total - 1; i++)
    {
        if (ivec[i] == 1 && ivec[i + 1] == 0)
        {
            //step1: exchange 1 and 0 to 0 1
            std::swap(ivec[i], ivec[i + 1]);

            //step2: move all 1 before ivce[i] to left
            std::sort(ivec.begin(), ivec.begin() + i, compare);

            store_result(arr, ivec, result);

            //try do step1 and 2 over again
            i = -1;
        }
    }

    print(result);
}


int main(int argc, char const *argv[])
{
    const int TOTAL = 3;
    int arr[TOTAL] = {1, 2, 3};
    combination_total(arr, TOTAL);

    for (int num = 1; num <= TOTAL; num++)
    {
        combination_num(arr, num, TOTAL);
    }

    return 0;
}