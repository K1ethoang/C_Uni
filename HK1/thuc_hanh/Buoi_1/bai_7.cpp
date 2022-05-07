/*
    Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - K62
*/
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, a1, b1, c1, d, dx, dy;
    printf("\nNhap a, b, c, a1, b1, c1 de giai he phuong trinh bac nhat 2 an x, y: ");
    scanf("%f%f%f%f%f%f", &a, &b, &c, &a1, &b1, &c1);

    d = a * b1 - a1 * b;
    dx = c * b1 - c1 * b;
    dy = a * c1 - a1 * c;

    if (d != 0)
    {
        printf("\nx = %.2f", dx / d);
        printf("\ny = %.2f", dy / d);
    }
    else // d == 0
    {
        if (dx == 0 && dy == 0)
            printf("\nVo so nghiem");
        else if (dx != 0 || dy != 0)
            printf("\nVo nghiem");
    }

    return 0;
}