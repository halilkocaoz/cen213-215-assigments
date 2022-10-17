#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void showAnIntArray(int values[], long len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", values[i]);

    printf("\n");
}

void passRandomValuesToIntArray(int values[], long len)
{
    int value;
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        value = rand();
        values[i] = value;
    }
}

double insertionSort(int array[], long len)
{
    clock_t begin = clock();
    for (int step = 1; step < len; step++)
    {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
    clock_t end = clock();
    double spentTime = (double)(end - begin) / CLOCKS_PER_SEC;
    return spentTime;
}

int main()
{
    long valuesLen = 0;
inputtingLen:
    printf("Please input the length of the values: ");
    scanf("%ld", &valuesLen);
    if (valuesLen < 2)
    {
        printf("Length must be bigger than 2.\n");
        goto inputtingLen;
    }
    int values[valuesLen];
    passRandomValuesToIntArray(values, valuesLen);
    printf("1 - Insertion sort\n2 - Selection sort\n3 - Bubble sort\n4 - Mergesort \n5 - Quicksort\n6 - Heap sort\n");
    printf("Choose the sorting algorithm from the list above to compute the running time in seconds: ");
    int selectedSortingAlgorithm = 0;
    double spentTime = 0;
inputtingSortingAlgorithm:
    scanf("%d", &selectedSortingAlgorithm);
    switch (selectedSortingAlgorithm)
    {
    case 1:
        spentTime = insertionSort(values, valuesLen);
        break;
    case 2:
        spentTime = insertionSort(values, valuesLen);
        break;
    case 3:
        spentTime = insertionSort(values, valuesLen);
        break;
    case 4:
        spentTime = insertionSort(values, valuesLen);
        break;
    case 5:
        spentTime = insertionSort(values, valuesLen);
        break;
    case 6:
        spentTime = insertionSort(values, valuesLen);
        break;
    default:
        printf("\nPlease, choose the one of the above: ");
        goto inputtingSortingAlgorithm;
    }
    printf("The running time of the sorting algorithm is: %f seconds\n", spentTime);
    return 0;
}