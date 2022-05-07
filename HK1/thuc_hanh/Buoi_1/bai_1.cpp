// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62

#include <stdio.h>

int main()
{
    float width, length, p, s;
    printf("\nNhap chieu dai - chieu rong: ");
    scanf("%f%f", &length, &width);
    if (length < 0 || width < 0)
        printf("\nKhong tinh duoc");
    else
    {
        p = (width + length) * 2;
        s = width * length;
        printf("\nChu vi hinh chu nhat: %.2f", p);
        printf("\nDien tich hinh chu nhat: %.2f", s);
    }

    return 0;
}
