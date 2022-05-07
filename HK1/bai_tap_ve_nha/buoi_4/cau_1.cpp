/*
    Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - K62
*/
#include <stdio.h>
#include <math.h>
// 1. Nhập dãy số nguyên, in ra các số nguyên tố

int main()
{
    int n, m = 0;
    int a[100], b[100];

    do
    {
        printf("\nNhap n ( 0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    // Nhập
    printf("\n\n\tNHAP MANG\n");
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }

    // Xuất
    printf("\n\n\tMANG VUA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // Kiểm tra số nguyên tố rồi cho vào mảng b
    for (int i = 0; i < n; i++)
    {
        bool check = true;
        if (a[i] < 2)
        {
            check = false;
        }
        else
        {
            if (a[i] == 2)
            {
                check = true;
            }
            else
            {
                if (a[i] % 2 == 0)
                {
                    check = false;
                }
                else
                {
                    for (int j = 2; j <= sqrt(a[i]); j++)
                    {
                        if (a[i] % j == 0)
                        {
                            check = false;
                            break;
                        }
                    }
                }
            }
        }
        if (check == true)
        {
            b[m] = a[i]; // Xếp các số nguyên tố sang mảng phụ
            m++;
        }
    }

    // Xuất số nguyên tố
    if (m == 0)
    {
        printf("\n\n\tKHONG CO SO NGUYEN TO TRONG MANG");
    }
    else
    {
        printf("\n\n\tSO NGUYEN TO CO TRONG MANG\n");
        for (int i = 0; i < m; i++)
        {
            bool check = true;
            for (int j = i - 1; j >= 0; j--)
            {
                if (b[i] == b[j])
                {
                    check = false;
                    break;
                }
            }
            if (check == true)
                printf("%d ", b[i]);
        }
    }

    return 0;
}