#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MAX 30
int *makedata(int *data, int x)
{
    for (int i = 0; i < x; i++)
    {
        *(data + i) = rand();
    }
    return data;
}
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
void adjust(int *data, int i, int size)
{
    int j;
    int reference = 1;
    while (2 * i <= size && reference == 1)
    {
        j = 2 * i;
        if (j + 1 <= size && *(data + j + 1) > *(data + j))
        {
            j = j + 1;
        }
        if (*(data + j) < *(data + i))
        {
            reference = 0;
        }
        else
        {
            swap(&*(data + i), &*(data + j));
            i = j;
        }
    }
}
void MakeHeap(int *data, int size)
{
    int i;
    int k = size;
    for (i = size / 2; i >= 1; i--)
    {
        adjust(data, i, size);
    }
}
void selectionsort(int *data, int max)
{
    int i, j, index;
    for (i = 0; i < max - 1; i++)
    {
        index = i;
        for (j = 0; j < max; j++)
            if (*(data + i) > *(data + j))
                index = j;
        swap(&*(data + i), &*(data + j));
    }
}
void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = *(arr + i);
        j = i - 1;

        /* Di chuyển các phần tử có giá trị lớn hơn giá trị 
       key về sau một vị trí so với vị trí ban đầu
       của nó */
        while (j >= 0 && *(arr + j) > key)
        {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j + 1) = key;
    }
}
void bubbleSort(int *arr, int n)
{
    int i, j;
    bool haveSwap = false;
    for (i = 0; i < n - 1; i++)
    {
        // i phần tử cuối cùng đã được sắp xếp
        haveSwap = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                swap(&*(arr + j), &*(arr + j + 1));
                haveSwap = true; // Kiểm tra lần lặp này có swap không
            }
        }
        // Nếu không có swap nào được thực hiện => mảng đã sắp xếp. Không cần lặp thêm
        if (haveSwap == false)
        {
            break;
        }
    }
}

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}
int main()
{
    clock_t start_t, end_t, total_t;
    start_t = clock();
    srand((int)time(0));
    int *data = (int *)malloc(sizeof(int) * MAX);
    int n;
    int size, x, k;
    size = x = k = MAX;
    do
    {
        printf("----------MENU----------\n");
        printf("1.Tao du lieu\n");
        printf("2.Sap xep them dan\n");
        printf("3.Lua chon\n");
        printf("4.Noi bot\n");
        printf("5.Heap\n");
        printf("6.Exit.");
        printf("Your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            //// Tao du lieu
            start_t = clock();
            data = makedata(data, size);
            end_t = clock();
            printf("Ket thuc vong lap, end_t = %ld\n", end_t);
            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            printf("Tong thoi gian su dung boi CPU: %f\n", total_t);
            printf("Thoat chuong trinh ...\n");
            break;
        case 2:
            /////Sap xep kieu chen
            start_t = clock();
            printf("start case 2:\n");
            insertionSort(data, MAX);
            printArray(data, MAX);
            end_t = clock();
            printf("Ket thuc vong lap, end_t = %ld\n", end_t);
            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            printf("Tong thoi gian su dung boi CPU: %f\n", total_t);
            printf("Thoat chuong trinh ...\n");
            break;
        case 3:
            /////Sap xep lua chon
            start_t = clock();
            selectionsort(data, MAX);
            printArray(data, MAX);
            end_t = clock();
            printf("Ket thuc vong lap, end_t = %ld\n", end_t);
            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            printf("Tong thoi gian su dung boi CPU: %f\n", total_t);
            printf("Thoat chuong trinh ...\n");
            break;
        case 4:
            /////Sap xep noi bot
            start_t = clock();
            bubbleSort(data, MAX);
            printArray(data, MAX);
            end_t = clock();
            printf("Ket thuc vong lap, end_t = %ld\n", end_t);
            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            printf("Tong thoi gian su dung boi CPU: %f\n", total_t);
            printf("Thoat chuong trinh ...\n");
            break;
        case 5:
            /////Sap xep heap
            start_t = clock();
            MakeHeap(data, size);
            while (k > 1)
            {
                int x = k;
                swap(&*(data + 1), &*(data + x));
                k--;
                adjust(data, 1, k);
            }
            printArray(data, MAX);
            end_t = clock();
            printf("Ket thuc vong lap, end_t = %ld\n", end_t);
            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            printf("Tong thoi gian su dung boi CPU: %f\n", total_t);
            printf("Thoat chuong trinh ...\n");
            break;
        case 6:
            free(data);
            break;
        }
    } while (n != 6);
    return 0;
}
