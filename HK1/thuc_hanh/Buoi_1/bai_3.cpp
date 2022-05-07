/*
    Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - K62
*/
#include <stdio.h>
#include <math.h>
// 2. Tìm ước chung lớn nhất,
//  bội chung nhỏ nhất của hai số nguyên
int main()
{
    int a, b;
    int temp, temp_a, temp_b, ucln, bcnn;

    do
    {
        printf("\nNhap 2 so nguyen duong a va b: ");
        scanf("%d%d", &a, &b);
        if (a <= 0 || b <= 0)
        {
            printf("So vua nhap khong hop le! Vui long nhap lai (a,b > 0)\n");
        }
    } while (a <= 0 || b <= 0);

    printf("\n\t2 so vua nhap: %d va %d\n", a, b);

    (a > b) ? (temp_a = a, temp_b = b) : (temp_a = b, temp_b = a);
    while (temp_b != 0)
    {

        temp = temp_a % temp_b;
        temp_a = temp_b;
        temp_b = temp;
    }

    ucln = temp_a;
    bcnn = (a * b) / ucln;

    if (bcnn == 0)
    {

        printf("\nUCLN la: %d", ucln);
        printf("\nKhong co BCNN");
    }
    else
    {
        printf("\nUCLN la: %d", ucln);
        printf("\nBCNN la: %d", bcnn);
    }

    return 0;
}