// Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT - K62

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float x1, x2, delta;
    printf("\nNhap a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);

    if (a == 0) // giai phuong trinh bac nhat bx + c = 0
    {
        if (b == 0)
        {
            if (c == 0)
                printf("\nVo so nghiem");
            else // c != 0
                printf("\nVo nghiem");
        }
        else
        {
            if (c == 0)
                printf("\nx = 0.00");
            else // c != 0
                printf("\nx = %.2f", -c / b);
        }
    }
    else // a != 0 => Giai pt ax2 + bx + c = 0
    {
        delta = b * b - (4 * a * c);
        if (delta > 0)
        {
            x1 = ((-b - sqrt(delta)) / (2 * a));
            x2 = ((-b + sqrt(delta)) / (2 * a));
            printf("\nx1 = %.2f ; x2 = %.2f", x1, x2);
        }
        else if (delta < 0)
        {
            printf("\nVo nghiem");
        }
        else
        {
            x1 = x2 = -b / (2 * a);
            printf("\n x1 = x2 = %.2f", x1);
        }
    }

    return 0;
}