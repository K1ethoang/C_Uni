// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62
#include <stdio.h>
#include <math.h>

int main()
{
    int n, a[100], count = 0;
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
        if ((a[i] % 3 == 0 || a[i] % 7 == 0) && (a[i] >= 1 && a[i] <= 100))
            count++;
    }

    printf("\n\t\tMANG DA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nSo cac phan tu chia het cho 3 hoac 7 trong doan [1, 100]: %d", count);

    return 0;
}