// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62

#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float p, s;
    printf("\nNhap 3 canh tam giac a b c: ");
    scanf("%f%f%f", &a, &b, &c);
    if (a + b > c && b + c > a && c + a > b)
    {
        p = a + b + c;
        printf("\nChu vi tam giac: %.2f", p);
        p = p / 2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("\nDien tich tam giac: %.2f", s);
    }
    else
        printf("\nTam giac khong hop le");
    return 0;
}
