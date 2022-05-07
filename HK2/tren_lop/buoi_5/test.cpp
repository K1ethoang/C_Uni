#include <stdio.h>

int findMin(int a[], int n);
void removeArr(int a[], int &n, int pos);
void input(int a[], int n);
void outputArr(int a[], int n);
void handle(int a[], int &n, int b[], int &m);

int main()
{
    int n, m;
    do
    {
        printf("\nNhap n: ");
        scanf("%d", &n);
        if (n <= 0)
            printf("\nNhap lai");
    } while (n <= 0);
    int a[n], b[n];
    input(a, n);
    outputArr(a, n);
    handle(a, n, b, m);
    printf("\n");
    outputArr(b, m);
    return 0;
}

void input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void outputArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int findMin(int a[], int n)
{
    int min = a[0];
    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            pos = i;
        }
    }
    return pos;
}

void removeArr(int a[], int &n, int pos)
{
    for (int i = pos + 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    n--;
}

void handle(int a[], int &n, int b[], int &m)
{
    m = 0;
    while (n != 0)
    {
        int minPos = findMin(a, n);
        b[m++] = a[minPos];
        removeArr(a, n, minPos);
    }
}