/* 
    Ho Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT-62
 */
#include <stdio.h>

void main()
{
    int n;
    printf("Nhap 1 so gom 3 chu so: ");
    scanf("%d", &n);
    int c = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int a = n % 10;
    printf("\n%d + %d + %d = %d", a, b, c, a + b + c);
}