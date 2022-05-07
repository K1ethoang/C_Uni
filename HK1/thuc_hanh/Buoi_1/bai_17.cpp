// Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT - K62

#include <stdio.h>

int main()
{
    int n;
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
    }

    printf("\n\t\tTRUOC KHI SAP XEP GIAM DAN\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[maxIndex])
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            float temp = a[i];
            a[i] = a[maxIndex];
            a[maxIndex] = temp;
        }
    }

    printf("\n\t\tSAU KHI SAP XEP GIAM DAN\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }

    return 0;
}