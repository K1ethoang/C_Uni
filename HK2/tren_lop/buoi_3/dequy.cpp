#include <stdio.h>

int tongDeQuy(int n)
{
    if (n == 1)
        return 1;
    else
        return tongDeQuy(n - 1) + n;
}

int main()
{
    int n;
    printf("\nNhap n can tinh tong bang de quy: ");
    scanf("%d", &n);
    printf("\nKet qua: %d", tongDeQuy(n));
}