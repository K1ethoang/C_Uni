// Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT - K62

#include <stdio.h>

int main()
{
    int n;
    float a[100], sum = 0;
    do
    {
        printf("\nNhap n phan tu [0 < n <= 100]: ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    printf("\n\t\tNHAP MANG\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i + 1);
        scanf("%f", &a[i]);
        sum += a[i];
    }

    printf("\nKet qua %.2f", sum / n);

    return 0;
}