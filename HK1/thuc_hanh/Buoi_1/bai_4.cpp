/*
    Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - K62
*/
#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    printf("\nNhap so nguyen a: ");
    scanf("%d", &a);
    if (a < 2)
        printf("\n%d khong phai so nguyen to", a);
    else
    {
        if (a == 2)
            printf("\n%d la so nguyen to", a);
        else
        {
            bool isPrime = true;
            for (int i = 2; i <= sqrt(a); i++)
            {
                if (a % i == 0)
                {
                    isPrime = false;
                    printf("\n%d khong phai so nguyen to", a);
                    break;
                }
            }
            if (isPrime)
                printf("\n%d la so nguyen to", a);
        }
    }
    return 0;
}