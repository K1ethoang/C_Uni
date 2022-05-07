/*
    Ho Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT-62
 */
#include <stdio.h>

void main()
{
    int n;
    printf("Nhap so giay: ");
    scanf("%d", &n);
    if (n > 0 && n <= 86400)
    {

        printf("%.2d:%.2d:%.2d", n / 3600, (n % 3600) / 60, ((n % 3600) % 60) % 60);
    }
    else
    {
        printf("\nMoi nhap lai!");
    }
}