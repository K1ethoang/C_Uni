/* 
    Ho Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT-62
 */
#include <stdio.h>
#include <math.h>

void main()
{
    int n;
    printf("Nhap 1 so co 4 chu so:");
    scanf("%d", &n);
    int d = n % 10;
    n /= 10;
    int c = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int a = n % 10;
    n /= 10;
    printf("Hang nghin: %d", a);
    printf("\nHang tram: %d", b);
    printf("\nHang chuc: %d", c);
    printf("\nHang don vi: %d", d);
}