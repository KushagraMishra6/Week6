#include <stdio.h>
void revarr(int *p, int n, int i)
{
    if (i > n / 2)
        return;
    int temp = *(p + i);
    *(p + i) = *(p + n - 1 - i);
    *(p + n - 1 - i) = temp;
    revarr(p, n, i + 1);
}
void hailstoneSequence(int *num, int *steps)
{
    printf("%d ", *num);
    if ((*num) == 1)
    {
        printf("\n%d", *steps);
        return;
    }
    if ((*num) & 1)
        *num = 3 * (*num) + 1;
    else
        *num /= 2;
    (*steps)++;
    hailstoneSequence(num, steps);
}
void swap(int *a, int *b)
{
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}
void waveSort(int *arr1, int size)
{
    int *min;
    for (int i = 0; i < size; i++)
    {
        min = (arr1 + i);
        for (int j = i + 1; j < size; j++)
        {
            if (*(arr1 + j) < *min)
            {
                min = arr1 + j;
            }
        }
        swap(min, arr1 + i);
    }
    for (int i = 0; i + 1 < size; i += 2)
    {
        swap(arr1 + i, arr1 + i + 1);
    }
}
int main()
{
    // Question 1
    int n;
    scanf("%d", &n);
    int arr[n];
    int *p;
    p = &arr[0];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    revarr(p, n, 0);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Question 2
    int steps = 0;
    int num;
    int *p1, *p2;
    scanf("%d", &num);
    p1 = &num;
    p2 = &steps;
    hailstoneSequence(p1, p2);

    // Question 3
    int size;
    scanf("%d", &size);
    int arr1[size];
    int *p3;
    for (int i = 0; i < size; i++)
        scanf("%d", &arr1[i]);
    p3 = &arr1[0];
    waveSort(p3, size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr1[i]);
}