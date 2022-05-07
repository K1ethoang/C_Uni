// Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT - K62

#include <stdio.h>

int main()
{
    int n, sum = 0;
    do
    {
        printf("\nNhap so nguyen duong n: ");
        scanf("%d", &n);
    } while (n < 1);

    for (int i = 1; i <= (n * 2 + 1); i += 2)
    {
        sum += i;
    }

    printf("\nKet qua: %d", sum);

    return 0;
}