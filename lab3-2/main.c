#include <stdio.h>
#include <malloc.h>

int main() {

    int n; scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);

    }

    bubble_sort(&arr,n);

    for (int i = 0; i < n; i++) {

        printf("%d\n",arr[i]);

    }

    return 0;
}


void bubble_sort(int* arr, int n){

    for (int i = 0 ; i < n - 1; i++) {
        for (int j = 0 ; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j],&arr[j+1]);

            }
        }
    }

    return;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
