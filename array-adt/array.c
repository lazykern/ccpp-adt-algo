#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *A;
    int size;
    int length;
} Array;

void display(Array array) {
    int i;
    printf("{");
    for (i=0; i<array.length; ++i) {
        printf("%d", array.A[i]);
        if (i < array.length - 1) printf(", ");
    }
    printf("}\n");
}

void append(Array array, int x) {
    if (array.length == array.size) {
        return;
    }
    array.A[array.length++] = x;
}

void insert(Array array, int x, int index) {
    int i;
    for (i=array.length; i>index; --i) {
        array.A[i] = array.A[i-1];
    }
    array.A[index] = x;
    ++array.length;
} 

void delete(Array array, int index) {
    int i;
    for (i=index; i<array.length-1; ++i) {
        array.A[i] = array.A[i+1];
    }
    --array.length;
}

int search_linear(Array array, int value) {
    int i;
    for (i = 0; i<array.length; ++i) {
        if (array.A[i] == value) {
            return i;
        }
    }
    return -1;
}

int main()
{
    Array array;
    int i;
    scanf("%d", &array.size);
    array.A = (int *) malloc(array.size*sizeof(int));
    array.length = 0;
    for (i=0; i<array.size; ++i) {
        scanf("%d", &array.A[i]);
        ++array.length;
    }
    display(array);
}