#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int size;
    int length;
} Array;

Array new_array(int size)
{
    Array array;
    array.data = (int *)malloc(sizeof(int) * size);
    array.length = 0;
    array.size = size;
    return array;
}

void display(Array array)
{
    printf("{");
    for (int i = 0; i < array.length; ++i)
    {
        printf("%d", array.data[i]);
        if (i < array.length - 1)
            printf(", ");
    }
    printf("}\n");
}

void display_info(Array array)
{
    printf("data: ");
    display(array);
    printf("length: %d\n", array.length);
    printf("size: %d\n", array.size);
}

void resize(Array *array, int new_size)
{
    int *new_data = (int *)malloc(sizeof(int) * new_size);
    if (array->length > new_size)
        array->length = new_size;
    for (int i = 0; i < array->length; ++i)
        new_data[i] = array->data[i];
    free(array->data);
    array->data = new_data;
    array->size = new_size;
}

size_t expand(Array *array, int by)
{
    void *p;
    p = realloc(array->data, sizeof(int) * (array->size + by));
    if (p == NULL)
    {
        printf("expand failed\n");
        return array->size;
    }
    array->data = p;
    array->size += by;
    return array->size;
}

void append(Array *array, int x)
{
    if (array->length == array->size)
    {
        return;
    }
    array->data[array->length++] = x;
}

void insert(Array *array, int x, int index)
{
    for (int i = array->length; i > index; --i)
    {
        array->data[i] = array->data[i - 1];
    }
    array->data[index] = x;
    ++array->length;
}

void delete (Array *array, int index)
{
    for (int i = index; i < array->length - 1; ++i)
    {
        array->data[i] = array->data[i + 1];
    }
    --array->length;
}

int search(Array array, int value)
{
    for (int i = 0; i < array.length; ++i)
    {
        if (array.data[i] == value)
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
        if (value == array.data[m])
            return m;
        else if (value < array.data[m])
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int search_r_bi(int *data, int value, int l, int h)
{
    if (l > h)
        return -1;
    int m = (l + h) / 2;
    if (value == data[m])
        return m;
    else if (value < data[m])
        return search_r_bi(data, value, l, m - 1);
    else
        return search_r_bi(data, value, m + 1, h);
}

int get(Array array, int index) { return array.data[index]; }

void set(Array *array, int index, int value) { array->data[index] = value; }

int max(Array array)
{
    int max = array.data[0];
    for (int i = 1; i < array.length; ++i)
        if (max < array.data[i])
            max = array.data[i];

    return max;
}

int min(Array array)
{
    int min = array.data[0];
    for (int i = 1; i < array.length; ++i)
        if (min > array.data[i])
            min = array.data[i];
    return min;
}

int sum(Array array)
{
    int total = 0;
    for (int i = 0; i < array.length; i++)
        total += array.data[i];
    return total;
}

float avg(Array array)
{
    return (float)sum(array) / array.length;
}

void swap(int *a, int *b)
{
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
        temp = array->data[r];
        array->data[r] = array->data[l];
        array->data[l] = temp;
    }
}

void left_shift(Array *array)
{
    int temp = array->data[0];
    for (int i = 0; i < array->length - 1; ++i)
    {
        array->data[i] = array->data[i + 1];
    }
    array->data[array->length - 1] = temp;
}

void right_shift(Array *array)
{
    int temp = array->data[array->length - 1];
    for (int i = array->length - 1; i > 0; --i)
    {
        array->data[i] = array->data[i - 1];
    }
    array->data[0] = temp;
}

int is_sorted(Array array)
{
    for (int i = 0; i < array.length - 1; ++i)
        if (array.data[i] > array.data[i + 1])
            return 0;
    return 1;
}

int is_sorted_desc(Array array)
{
    for (int i = 0; i < array.length - 1; ++i)
        if (array.data[i] < array.data[i + 1])
            return 0;
    return 1;
}

Array concat(Array src1, Array src2)
{
    Array result = new_array(src1.size + src2.size);

    int src_i;
    int res_i = 0;

    for (src_i = 0; src_i < src1.length; ++src_i)
        result.data[res_i++] = src1.data[src_i];

    for (src_i = 0; src_i < src2.length; ++src_i)
        result.data[res_i++] = src2.data[src_i];

    result.length = res_i;
    return result;
}

Array set_union(Array src1, Array src2)
{
    Array result = new_array(src1.length + src2.length);

    for (int i = 0; i < src1.length; ++i)
        append(&result, src1.data[i]);

    for (int i = 0; i < src2.length; ++i)
    {
        if (search_l(src1, src2.data[i]) == -1)
            append(&result, src2.data[i]);
    }

    resize(&result, result.length);
    return result;
}

Array intersection(Array src1, Array src2)
{
    Array result = new_array(src1.length + src2.length);

    for (int i = 0; i < src1.length; ++i) {
        if (search_l(src2, src1.data[i]) != -1) {
            append(&result, src1.data[i]);
        }
    }

    resize(&result, result.length);
    return result;
}

Array difference(Array src1, Array src2)
{
    Array result = new_array(src1.length + src2.length);

    for (int i = 0; i < src1.length; ++i) {
        if (search_l(src2, src1.data[i]) == -1) {
            append(&result, src1.data[i]);
        }
    }
    
    for (int i = 0; i < src2.length; ++i) {
        if (search_l(src1, src2.data[i]) == -1) {
            append(&result, src2.data[i]);
        }
    }
    resize(&result, result.length);
    return result;
}