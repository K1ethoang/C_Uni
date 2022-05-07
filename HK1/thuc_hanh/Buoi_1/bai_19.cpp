// Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT - K62

#include <stdio.h>

int main()
{
    int n, count = 0;
    float a[100];
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
        if (a[i] > 0)
            count++;
    }

    printf("\nTrong mang co %d phan tu duong", count);

    return 0;
}