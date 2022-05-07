// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62
#include <stdio.h>

int main()
{
    int n, a[100], count = 0, sum = 0;
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
        if (a[i] % 2 == 0)
        {
            count++;
            sum += a[i];
        }
    }

    printf("\n\t\tMANG DA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nTrung binh cong cac phan tu chan: %.2f", sum / count * 1.0);

    return 0;
}