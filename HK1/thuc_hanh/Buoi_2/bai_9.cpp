// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62
#include <stdio.h>
#include <math.h>

int main()
{
    int n, a[100], count = 0, sum = 1;
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
            sum *= a[i];
            count++;
        }
    }

    printf("\n\t\tMANG DA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nTrng binh nhan cua cac phan tu chan: %f", pow(sum, (1.0 / count)));

    return 0;
}