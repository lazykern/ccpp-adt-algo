#include <stdio.h>
#include "array.c"

int main()
{
    Array array = new_array(10);
    for (int i = 0; i < 100; ++i)
        append(&array, i);
    printf("%d", search_bi(array, 0));
    return 0;
}