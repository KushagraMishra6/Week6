#include <stdio.h>
int cols, rows;
void question1()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    if (k >= n)
    {
        while (k >= n)
        {
            k -= n;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i + k < n)
        {
            arr1[i + k] = arr[i];
        }
        else
        {
            int a = i + k - n;
            arr1[a] = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
}
int question2(int arr[], int n, int arr2[])
{
    int a = 0;
    for (int i = 0; i < n;)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                int temp = arr[i + count - 1];
                arr[i + count - 1] = arr[j];
                for (int k = i + count; k <= j; k++)
                {
                    int temp1 = arr[k];
                    arr[k] = temp;
                    temp = temp1;
                }
            }
        }
        arr2[a] = count;
        i += count;
        a++;
    }
    return a;
}
int question3(int arr[rows][cols])
{
    int a;
    for (int i = 0; i + 1 < rows; i++)
    {
        int j1 = 0, j2 = 0;
        while ((arr[i][j1] == 0) && (j1 < cols))
        {
            j1++;
        }
        while ((arr[i + 1][j2] == 0) && (j2 < cols))
        {
            j2++;
        }
        if (j1 >= j2)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    printf("question 1 start\n");
    question1();
    printf("\nquestion 1 end\n\n----------------------------------------------------------------------------------------------------------------------------------------------\n\nquestion 2 start\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int arr2[n];
    n = question2(arr, n, arr2);
    arr2[n];
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\nquestion 2 end\n\n----------------------------------------------------------------------------------------------------------------------------------------------\n\nquestion 3 start\n");
    scanf("%d\n%d", &rows, &cols);
    int arr1[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("%d", question3(arr1));
    printf("\nquestion 3 end");
}