#include<stdio.h>

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high){
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j<= high - 1; j++){
        if (array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[high]);
    return (i + 1);
}

int quicksort(int array[], int low, int high){
    if (low < high){
        int pi = partition(array, low, high);

        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

void printf_function(int array[], int n){
    for (int i = 0; i < n; i++)
        printf("%d | ", array[i]);
        printf("\n");
}

int main(){
    int array[10];
    int n;

    printf("Enter the size of array (MAX 10):");
    scanf("%d",&n);

    printf("Enter the elements in array:");
    for(int i = 0; i<n; i++){
        scanf("%d",&array[i]);
    }
    quicksort(array, 0, n - 1);
    printf("Sorted array:\n");
    printf_function(array, n);

    return 0;
}