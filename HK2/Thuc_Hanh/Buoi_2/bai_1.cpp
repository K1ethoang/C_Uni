// #############################################################################
// ###           Name: Hoang Gia Kiet                                        ###
// ###           Code: 6251071049                                            ###
// ###           Class: CNTT - K62                                           ###
// ###           Tool: VSCode                                                ###
// ###           BM CNTT - DH GIAO THONG VAN TAI - PHAN HIEU TP.HCM          ###
// #############################################################################

#include <stdio.h>
#include <stdlib.h>

int Nhap(float **a);
int MaxDuong(int n, float *a, float *max);
int Fibo(int n, float *a);
int Menu();

int main()
{
    int choose, n = 0;
    bool isExit = false;
    float *a = NULL;
    do
    {
        system("cls");
        choose = Menu();
        switch (choose)
        {
        case 1:
        {
            n = Nhap(&a);
            system("pause");
            break;
        }
        case 2:
        {
            printf("\n\t\tMANG VUA NHAP\n");
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                count++;
                printf("%.2f ", *(a + i));
                if (count == 10)
                {
                    printf("\n");
                    count = 0;
                }
            }
            printf("\n");
            system("pause");
            break;
        }
        case 3:
        {
            float max;
            if (MaxDuong(n, a, &max))
                printf("\nMax duong: %.2f\n", max);
            else
                printf("\nKhong co max duong\n");
            system("pause");
            break;
        }
        case 4:
        {
            if (Fibo(n, a))
                printf("\nDay nay co tinh fibonaccy\n");
            else
                printf("\nDay nay khong co tinh fibonaccy\n");
            system("pause");
            break;
        }
        case 5:
        {
            isExit = true;
            break;
        }
        default:
            printf("\n\tKhong hop le - Nhap lai\n");
            system("pause");
            break;
        }
    } while (!isExit);
    free(a);
    return 0;
}

int Nhap(float **a)
{
    int n;
    do
    {
        printf("\nNhap so phan tu: ");
        scanf("%d", &n);
        if (n < 1 || n > 1000)
            printf("\nNhap lai!");
    } while (n < 1 || n > 1000);
    *a = (float *)malloc(n * sizeof(float));
    printf("\n\t\tNHAP MANG\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d] -> ", i);
        scanf("%f", &*(*a + i));
    }
    return n;
}

int MaxDuong(int n, float *a, float *max)
{
    float result = a[0];
    bool isExist = false;
    for (int i = 1; i < n; i++)
    {
        if (result < a[i] && a[i] > 0)
        {
            result = a[i];
            isExist = true;
        }
    }
    if (isExist)
    {
        *max = result;
        return 1;
    }
    else
        return 0;
}

int Fibo(int n, float *a)
{
    bool isRight;
    for (int i = 2; i < n; i++)
    {
        if (a[i] == a[i - 1] + a[i - 2] && a[i] > 0)
            isRight = true;
        else
        {
            isRight = false;
            break;
        }
    }
    if (isRight)
        return 1;
    else
        return 0;
}

int Menu()
{
    int choose;
    printf("\n--------------------------------------");
    printf("\n 1. Nhap day");
    printf("\n 2. Xuat day");
    printf("\n 3. Tim max duong");
    printf("\n 4. Kiem tra tinh fibonacci");
    printf("\n 5. Thoat");
    printf("\n--------------------------------------");
    printf("\n    Lua chon cua ban -> ");
    scanf("%d", &choose);
    return choose;
}