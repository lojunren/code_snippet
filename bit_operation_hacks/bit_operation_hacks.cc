#include <stdio.h>


static bool is_big_endian()
{
    bool ret = false;
    unsigned short test = 0x1234;
    if (*(unsigned char *)&test == 0x12)
    {
        ret = true;
        printf("big_endian\n");
    }
    else
    {
        ret = false;
        printf("little endian\n");
    }

    return ret;
}


static void print_byte_bit_value(char ch)
{
    int bit_size = sizeof(char) * 8;
    unsigned char bit[8] = {0};

    for (int i = 0; i < bit_size; i++)
    {
        bit[i] = (ch >> i) & 1;
    }

    if (is_big_endian())
    {
        printf("%d bit value: ", ch);
        for (int i = 0; i < bit_size; i++)
        {
            printf("%u", bit[i]);
        }
        printf("\n");
    }
    else
    {
        printf("%d bit value: ", ch);
        for (int i = bit_size - 1; i >= 0; i--)
        {
            printf("%u", bit[i]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    char num = -18;
    print_byte_bit_value(num);
    num = 85;
    print_byte_bit_value(num);

    return 0;
}