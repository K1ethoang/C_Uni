// Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT - K62

#include <stdio.h>

int main()
{
    int n, i1 = 0, i2 = 1, iN;
    do
    {
        printf("\nNhap so nguyen duong n: ");
        scanf("%d", &n);
    } while (n < 1);

    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
        {
            iN = i;
        }
        else
        {
            iN = i1 + i2;
            i1 = i2;
            i2 = iN;
        }
        printf("%d ", iN);
    }

    return 0;
}