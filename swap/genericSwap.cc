#include <iostream>

void swap(void *vp1, void *vp2, int size)
{
    if (vp1 == NULL || vp2 == NULL)
        return;

    char *buffer = (char *)malloc(size);

    memcpy(buffer, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, buffer, size);

    free(buffer);
}


int main(int argc, char const *argv[])
{
    int x = 28;
    int y = 4;

    swap(&x, &y, sizeof(int));
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    return 0;
}

