#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// dùng con trỏ
/*  nhập 1 dãy số nguyên gồm n phần tử
    Xuất dãy số ra màn hình
    Tính TBC, TBN các số lẻ
 */

void input(int *&a, int *n);
void output(int *a, const int &n);
float TBC(int *a, const int &n);
float TBN(int *a, const int &n);
void handle(int *a, const int &n);

int main()
{
    int n, *a;
    input(a, &n);
    handle(a, n);
    free(a);
    return 0;
}

void input(int *&a, int *n)
{
    do
    {
        printf("Nhap so luong phan tu: ");
        scanf("%d", n);
    } while (*n <= 0 || *n > 50);
    a = (int *)calloc(*n, sizeof(int));
    for (int i = 0; i < *n; i++)
    {
        printf("\nNhap a[%d]: ", i);
        scanf("%d", (a + i));
    }
}

void output(int *a, const int &n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        printf("%d ", *(a + i));
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

float TBC(int *a, const int &n)
{
    float sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 != 0)
        {
            sum += *(a + i);
            count++;
        }
    }
    return sum / count;
}

float TBN(int *a, const int &n)
{
    float sum = 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 != 0)
        {
            sum *= *(a + i);
            count++;
        }
    }
    return pow(sum, 1.0 / count);
}

void handle(int *a, const int &n)
{
    printf("\n\n\tXUAT MANG\n");
    output(a, n);
    printf("\n\n\tKET QUA\n");
    printf("\nTrung binh cong: %.2f", TBC(a, n));
    printf("\nTrung binh nhan: %.2f", TBN(a, n));
}