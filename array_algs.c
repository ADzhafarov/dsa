#include <stdio.h>

void _swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void myqsort(int *arr, int left, int right) {
    int i, last;

    if (left >= right)
        return;

    last = left;
    _swap(arr + left, arr + left + (right - left) / 2);
    for (i = left + 1; i <= right; i++) {
        if (arr[i] <= arr[left])
            _swap(arr + ++last, arr + i);
    }

    _swap(arr + left, arr + last);
    myqsort(arr, left, last - 1);
    myqsort(arr, last + 1, right);
}

#define ARRSIZ      100


/* Straightforward linear search */
/* Can be used on unsorted arrays */
int mylinsearch(int *arr, int len, int val) {
    int i;

    for (i = 0; i < len; i++)
        if (arr[i] == val)
            return i;

    return -1;
}

/* Binary search */
/* Designed for use with sorted arrays */
int mybinsearch(int *arr, int len, int val) {
    int left, right, mid;

    left = 0, right = len - 1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] < val) {
            left = mid + 1;
        } else if (arr[mid] > val) {
            right = mid - 1;
        } else
            return mid;
    }

    return -1;
}

void arrprint(int *arr, int len) {
    while (--len >= 0)
        printf("%d%c", *arr++, len == 0 ? '\n' : ' ');
}

int main(void) {
    int i;
    int arr[ARRSIZ];

    for (i = 0; i < ARRSIZ; i++) {
        arr[i] = i; //rand() % 100;
    }

    printf("lin: %d\n", mylinsearch(arr, ARRSIZ, 50));
    printf("bin: %d\n", mybinsearch(arr, ARRSIZ, 50));
}
