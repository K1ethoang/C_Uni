// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62
#include <stdio.h>

int main()
{
    int n, a[100], count = 0;
    float x, y;
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
    }

    printf("\n\t\tMANG DA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nNhap x: ");
    scanf("%f", &x);
    printf("\nNhap y: ");
    scanf("%f", &y);

    for (int i = 0; i < n; i++)
    {
        if ((a[i] >= x && a[i] <= y) && a[i] % 5 == 2)
            count++;
    }

    printf("\nSo phan tu chia 5 du 2 va nam trong doan [%.1f, %.1f]: %d", x, y, count);

    return 0;
}