/*
    Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - k62
 */
#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    int sum_cong = 0;
    float sum_nhan = 1;
    int arr[100];

    printf("Nhap n: ");
    scanf("%d", &n);

    printf("\nNhap mang\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nSo da nhap\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // TBC
    for (int i = 0; i < n; i++)
    {
        sum_cong += arr[i];
    }

    // TBN
    for (int i = 0; i < n; i++)
    {
        sum_nhan *= arr[i];
    }

    printf("\n\nTrung binh cong la: %f", (float)sum_cong / n);
    printf("\n\nTrung binh nhan la: %f", pow(sum_nhan, 1.0 / n));

    return 0;
}