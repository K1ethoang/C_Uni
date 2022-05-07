// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62
#include <stdio.h>

int main()
{
    int n, a[100], sum = 0;
    do
    {
        printf("\nNhap n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    printf("\n\t\tNHAP MANG\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i + 1);
        scanf("%d", &a[i]);
        sum += a[i];
    }

    printf("\n\t\tMANG VUA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nTong cac phan tu trong mang: %d", sum);

    return 0;
}