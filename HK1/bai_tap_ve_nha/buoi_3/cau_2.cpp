/*
    Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - K62
*/

/* // ! 2. Viết chương trình bằng ngôn ngữ lập trình C:
//*Cho dãy điểm M1(x1, y1), M2(x2, y2),…,Mn(xn,  yn) trên mặt phẳng. Hãy:
//*a.Tìm độ dài đường gấp khúc M1M2..Mn
//*b.Tìm đoạn MiMj (i≠j) có độ dài lớn nhất
//*c.Có bao nhiêu điểm thuộc góc phần tư thứ nhất.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int n, j = 1, sum = 0;
    int a[100];
    bool check;

    do
    {
        printf("\nNhap n: ");
        scanf("%d", &n);
        if (n <= 0 || n > 50)
            printf("So vua nhap khong hop le! Vui long nhap lai (0 < n <= 50)\n");
    } while (n <= 0 || n > 50);

    // Nhập điểm Mi
    for (int i = 0; i < n * 2; i += 2)
    {
        printf("\n\tNhap diem M[%d]\n", j);
        printf("\nNhap x[%d]: ", j);
        scanf("%d", &a[i]);
        printf("Nhap y[%d]: ", j);
        scanf("%d", &a[i + 1]);
        j++;
    }
    j = 1; // Reset lại biến đếm điểm

    printf("\n\n\t Cac diem vua nhap\n");
    for (int i = 0; i < n * 2; i += 2)
    {
        printf("\nM%d (%d, %d)\n", j, a[i], a[i + 1]);
        j++;
    }
    j = 1; // reset

    //*a.Tìm độ dài đường gấp khúc M1M2..Mn
    for (int i = 0; i < n * 2; i += 2)

        return 0;
}