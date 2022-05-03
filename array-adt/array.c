#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *A;
    int size;
    int length;
} Array;

void display(Array array)
{
    int i;
    printf("{");
    for (i = 0; i < array.length; ++i)
    {
        printf("%d", array.A[i]);
        if (i < array.length - 1)
            printf(", ");
    }
    printf("}\n");
}

void append(Array *array, int x)
{
    if (array->length == array->size)
    {
        return;
    }
    array->A[array->length++] = x;
}

void insert(Array *array, int x, int index)
{
    int i;
    for (i = array->length; i > index; --i)
    {
        array->A[i] = array->A[i - 1];
    }
    array->A[index] = x;
    ++array->length;
}

void delete (Array *array, int index)
{
    int i;
    for (i = index; i < array->length - 1; ++i)
    {
        array->A[i] = array->A[i + 1];
    }
    --array->length;
}

int search_l(Array array, int value)
{
    int i;
    for (i = 0; i < array.length; ++i)
    {
        if (array.A[i] == value)
        {
            return i;
        }
    }
    return -1;
}

/**
 * An implementation of binary search algorithm.
 * Only work with sorted array.
 * Might work with unsorted array if you are lucky enough.
 */
int search_bi(Array array, int value)
{

    int l = 0;
    int h = array.length - 1;
    int m;

    while (l <= h)
    {
        m = (l + h) / 2;
        if (value == array.A[m])
            return m;
        else if (value < array.A[m])
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int search_r_bi(int *A, int value, int l, int h)
{
    if (l > h)
        return -1;
    int m = (l + h) / 2;
    if (value == A[m])
        return m;
    else if (value < A[m])
        return search_r_bi(A, value, l, m - 1);
    else
        return search_r_bi(A, value, m + 1, h);
}

int get(Array array, int index) { return array.A[index]; }

void set(Array *array, int index, int value) { array->A[index] = value; }

int max(Array array)
{
    int max = array.A[0];
    int i;
    for (i = 1; i < array.length; ++i)
        if (max < array.A[i])
            max = array.A[i];

    return max;
}

int min(Array array)
{
    int min = array.A[0];
    int i;
    for (i = 1; i < array.length; ++i)
        if (min > array.A[i])
            min = array.A[i];
    return min;
}

int sum(Array array)
{
    int i, total = 0;
    for (i = 0; i < array.length; i++)
        total += array.A[i];
    return total;
}

float avg(Array array)
{
    return (float)sum(array) / array.length;
}

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
}

void reverse(Array *array)
{
    int l = 0, r = array->length - 1;
    int temp;
    for (l; l < r; ++l, --r)
    {
        temp = array->A[r];
        array->A[r] = array->A[l];
        array->A[l] = temp;
    }
}

void left_shift(Array *array)
{
    int i, temp;
    temp = array->A[0];
    for (i=0; i < array->length-1; ++i) {
        array->A[i] = array->A[i+1];
    }
    array->A[array->length-1] = temp;
}

void right_shift(Array *array)
{
    int i, temp;
    temp = array->A[array->length-1];
    for (i = array->length-1; i > 0; --i) {
        array->A[i] = array->A[i-1];
    }
    array->A[0]= temp;
}



int main()
{
    Array array;
    int i;
    scanf("%d", &array.size);
    array.A = (int *)malloc(array.size * sizeof(int) + 1);
    array.length = 0;
    for (i = 0; i < array.size; ++i)
    {
        scanf("%d", &array.A[i]);
        ++array.length;
    }
    display(array);    
}