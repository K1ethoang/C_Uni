
/*
    Ho Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - 62
 */

#include <stdio.h>
#include <math.h>

void main()
{
    int n;
    printf("Nhap so co 4 chu so: ");
    scanf("%d", &n);

    int d = n % 10;
    n /= 10;
    int c = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int a = n % 10;
    n /= 10;

    printf("%.0f", d * pow(10, 3) + c * pow(10, 2) + b * pow(10, 1) + a ;
}