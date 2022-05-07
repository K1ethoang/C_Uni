/*
    Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - k62
*/
#include <stdio.h>
//! in số âm lớn thứ 2
int main()
{
    int n, m = 0;
    float a[100], b[100];
    float temp; // biến phụ

    printf("Nhap n: ");
    scanf("%d", &n);

    // Nhập mảng
    printf("\nNhap mang\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%f", &a[i]);
    }

    // Xuất mảng
    printf("\nMang vua nhap\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }

    // Lấy các phần tử < 0 vào mảng b
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            b[m] = a[i];
            m++;
        }
    }

    // Tìm số ấm lớn thứ 2
    if (m == 0)
    {
        printf("\n\nMang khong co so am");
    }
    else // nếu trong mảng b có số âm
    {
        // Sắp xếp mảng b
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < m - i - 1; j++)
            {
                if (b[j] < b[j + 1])
                {
                    temp = b[j + 1];
                    b[j + 1] = b[j];
                    b[j] = temp;
                }
            }
        }

        if (b[0] == b[m - 1]) // Nếu phần tử đầu và cuối trong mảng b = nhau (vd: -3 -3 -3)
        {
            printf("\n\nMang co 1 so am lon nhat: %.2f", b[0]);
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                if (b[i] != b[0])
                {
                    printf("\n\nSo am lon thu 2: %.2f", b[i]);
                    break;
                }
            }
        }
    }

    return 0;
}