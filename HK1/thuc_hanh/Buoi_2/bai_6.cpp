// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62
#include <stdio.h>

int main()
{
    int n, sum = 0, a[100];
    do
    {
        printf("\nNhap n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    printf("\n\t\tNHAP MANG\n");
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("\nNhap a[%d] > 0: ", i + 1);
            scanf("%d", &a[i]);
            if (a[i] <= 0)
                printf("\n\t\t(!) NHAP LAI (!)\n");
        } while (a[i] <= 0);

        if (a[i] > 0 && a[i] % 2 != 0)
            sum += a[i];
    }

    printf("\n\t\tMANG VUA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nTong cac phan tu co gia tri le trong mang: %d", sum);

    return 0;
}