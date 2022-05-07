// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float a[100], max;
    do
    {
        printf("\nNhap n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    printf("\n\t\tNHAP MANG\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i + 1);
        scanf("%f", &a[i]);
    }

    printf("\n\t\tMANG VUA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", a[i]);
    }

    // tìm phần tử có giá trị lớn nhất của mảng
    max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }

    printf("\n\nGia tri lon nhat cua mang: %.2f", max);

    return 0;
}