#include <stdio.h>
#include "array.c"

int main()
{
    Array array = new_array(10);
    display_info(array);
    resize(&array, 20);
    display_info(array);
    return 0;
}