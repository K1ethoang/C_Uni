// Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT - K62

#include <stdio.h>

int main()
{
    int n, result = 1;
    do
    {
        printf("\nNhap so nguyen duong n: ");
        scanf("%d", &n);
    } while (n < 1);

    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    printf("\nKet qua: %d", result);

    return 0;
}