// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62

#include <stdio.h>
#include <math.h>

int main()
{
    int n, a[100], count = 0;
    bool isPrimeNumber;
    do
    {
        printf("\nNhap n (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    printf("\n\t\tNHAP MANG\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\n\t\tMANG VUA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // kiểm tra số nguyên tố có trong mảng
    for (int i = 0; i < n; i++)
    {
        bool isPrimeNumber = true;
        if (a[i] < 2)
            isPrimeNumber = false;
        else
        {
            if (a[i] == 2)
                isPrimeNumber == true;
            else
            {
                for (int j = 2; j <= sqrt(a[i]); j++)
                {
                    if (a[i] % j == 0)
                    {
                        isPrimeNumber = false;
                        break;
                    }
                }
            }
        }
        if (isPrimeNumber)
            count++;
    }

    if (count != 0)
        printf("\n\nTrong mang co %d so nguyen to", count);
    else
        printf("\n\nTrong mang khong co so nguyen to nao");

    return 0;
}