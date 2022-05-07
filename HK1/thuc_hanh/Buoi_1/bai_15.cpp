// Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT - K62

#include <stdio.h>

int main()
{
    int n, count = 0;
    int a[100];
    do
    {
        printf("\nNhap n phan tu [0 < n <= 100]: ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    printf("\n\t\tNHAP MANG\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\n\t\tXUAT MANG\n");

    for (int i = 0; i < n; i++)
    {
        count++;
        printf("%4d", a[i]);
        if (count == 10)
        {
            count = 0;
            printf("\n");
        }
    }

    return 0;
}