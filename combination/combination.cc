#include <stdio.h>
#include <vector>
#include <algorithm>


static bool compare(int a, int b)
{
    return a > b ? true : false;
}

static void print(const std::vector<std::vector<int> > &vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        printf("combination no:%d   [ ", (i + 1) );
        for (unsigned int j = 0; j < vec[i].size(); j++)
        {
            printf("%d ", vec[i][j]);
        }

        printf("]\n");
    }
}

static void store_combination(int *arr, const std::vector<int> &ivec, std::vector<std::vector<int> > &result)
{
    std::vector<int> combination;
    for (unsigned int index = 0; index < ivec.size(); index++)
    {
        if (ivec[index] == 1)
        {
            combination.push_back(arr[index]);
        }
    }

    result.push_back(combination);
}

static void combination_total(int *arr, unsigned int total)
{
    printf("------------combination_total------------\n");

    std::vector<std::vector<int> > result;

    for (unsigned int i = 0; i < (1 << total); i++)
    {
        std::vector<int> combination;
        for (unsigned int j = 0; j < total; j++)
        {
            if (((i >> j) & 1) == 1)
            {
                combination.push_back(arr[j]);
            }
        }

        if (combination.size() != 0)
        {
            result.push_back(combination);
        }

    }

    print(result);
}

static void combination_k(int *arr, unsigned int k, unsigned int total)
{
    std::vector<std::vector<int> > result;

    //initial first combination like: 1, 1, 1, 0, 0, 0
    std::vector<int> ivec(total, 0);
    for (unsigned int i = 0; i < k; i++)
    {
        ivec[i] = 1;
    }
    store_combination(arr, ivec, result);

    for (unsigned int i = 0; i < total - 1; i++)
    {
        if (ivec[i] == 1 && ivec[i + 1] == 0)
        {
            //step1: exchange 1 and 0 to 0 1
            std::swap(ivec[i], ivec[i + 1]);

            //step2: move all 1 before ivce[i] to left
            std::sort(ivec.begin(), ivec.begin() + i, compare);

            store_combination(arr, ivec, result);

            //try do step1 and 2 over again
            i = 0;
        }
    }

    print(result);
}

static void combination_k_recursion(int *arr, unsigned int offset, unsigned int k, unsigned int total, std::vector<int> &combination, std::vector<std::vector<int> > &result)
{
    if (k == 0)
    {
        result.push_back(combination);
        return;
    }

    unsigned int size = total - k;
    for (unsigned int i = offset; i <= size; i++)
    {
        combination.push_back(arr[i]);
        combination_k_recursion(arr, i + 1, k - 1, total, combination, result);
        combination.pop_back();
    }

}


int main(int argc, char const *argv[])
{
    const unsigned int TOTAL = 5;
    int arr[TOTAL] = {0};
    for (unsigned int i = 0; i < TOTAL; i++)
    {
        arr[i] = (int)(i + 1);
    }

    combination_total(arr, TOTAL);

    for (unsigned int k = 1; k <= TOTAL; k++)
    {
        printf("\n------------combination_k:%d------------\n", k);
        combination_k(arr, k, TOTAL);
    }

    for (unsigned int k = 1; k <= TOTAL; k++)
    {
        std::vector<int> combination;
        std::vector<std::vector<int> > result;

        printf("\n------------combination_k_recursion:%d------------\n", k);
        combination_k_recursion(arr, 0, k, TOTAL, combination, result);
        print(result);
    }

    return 0;
}