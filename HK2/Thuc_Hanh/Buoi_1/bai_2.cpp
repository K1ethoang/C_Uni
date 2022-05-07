// #############################################################################
// ###           Name: Hoang Gia Kiet                                        ###
// ###           Code: 6251071049                                            ###
// ###           Class: CNTT - K62                                           ###
// ###           Tool: VSCode                                                ###
// ###           BM CNTT - DH GIAO THONG VAN TAI - PHAN HIEU TP.HCM          ###
// #############################################################################

/*
Bài 2. Viết chương trình nhập vào một dãy số nguyên và thực hiện:
Tính tổng dãy
Tính trung bình cộng dãy
Tìm giá trị lớn nhất của dãy
Tìm giá trị nhỏ nhất của dãy
Thống kê số phần tử chẵn của dãy nhỏ hơn x (x nhập từ bàn phím)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void program();
void inputArr(int a[], int n);
void outputArr(int a[], int n);
float sumArr(int a[], int n);
int maxIndex(int a[], int n);
int minIndex(int a[], int n);
int numberOfEvenElementSmallerX(int a[], int n, int x);

int main()
{
    program();
    return 0;
}

void program()
{
    int n, x;
    do
    {
        printf("\nNhap so phan tu can co: ");
        scanf("%d", &n);
        if (n < 1 || n > INT_MAX)
            printf("\nKhong hop le - Nhap lai!");
    } while (n < 1 || n > INT_MAX);
    int *a = (int *)malloc(n * sizeof(int));
    printf("\n\t\tNHAP MANG\n");
    inputArr(a, n);
    printf("\n\t\tMANG VUA NHAP\n");
    outputArr(a, n);
    printf("\nNhap x de tim so phan tu chan nho hon x: ");
    scanf("%d", &x);
    printf("\n--------------------------------------------\n");
    float sum = sumArr(a, n);
    printf("\nTong day: %.2f", sum);
    printf("\nTrung binh cong: %.2f", sum / n);
    printf("\nGia tri lon nhat: %d", a[maxIndex(a, n)]);
    printf("\nGia tri nho nhat: %d", a[minIndex(a, n)]);
    printf("\nSo phan tu chan nho hon %d: %d", x, numberOfEvenElementSmallerX(a, n, x));
    free(a);
}

void inputArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap A[%d] -> ", i);
        scanf("%d", &a[i]);
    }
}

void outputArr(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        printf("%d ", a[i]);
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

float sumArr(int a[], int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int maxIndex(int a[], int n)
{
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[maxIndex] < a[i])
            maxIndex = i;
    }
    return maxIndex;
}

int minIndex(int a[], int n)
{
    int minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[minIndex] > a[i])
            minIndex = i;
    }
    return minIndex;
}

int numberOfEvenElementSmallerX(int a[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && a[i] < x)
            count++;
    }
    return count;
}