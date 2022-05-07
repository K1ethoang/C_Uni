/*
    Ho Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - 62
 */

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Nhap 1 so co 4 chu so: ");
    scanf("%d", &n);
    // 1234
    int d = n % 10; // d = 1234 % 10 = 4
    n /= 10;        // <=> n = n / 10 = 123

    int c = n % 10; // c = 123 % 10 = 3
    n /= 10;        // n = 12

    int b = n % 10; // b = 12 % 10 =2
    n /= 10;        // n = 1

    int a = n % 10; // a = 1;
    n /= 10;        // n = 1 / 10 = 0,1 (int) => n =0

    int m = d * pow(10, 3) + c * pow(10, 2) + b * pow(10, 1) + a * pow(10, 0);
    printf("%d", m);

    return 0;
}