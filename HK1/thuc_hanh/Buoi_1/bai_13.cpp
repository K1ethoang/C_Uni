// Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT - K62

#include <stdio.h>

int main()
{
    int n;
    float sum = 0;
    do
    {
        printf("\nNhap so nguyen duong n: ");
        scanf("%d", &n);
    } while (n < 1);

    for (int i = 2; i <= n; i++)
    {
        sum += (1.0 / (i * (i + 1)));
    }

    printf("\nKet qua: %.2f", sum);

    return 0;
}