// Name: Hoàng Gia Kiệt
// Code: 6251071049
// Class: CNTT - K62

#include <stdio.h>
#include <stdlib.h>

void CapPhat(int n, int **&a);
void XoaBN(int n, int **a);
void Nhap(int &n, int **&a);
void Xuat(int n, int **a);
int DoiXungPhu(int n, int **a);
void LietKe(int n, int **a);
int Menu();

int main()
{
    int choose, n = 0;
    bool isExit = false;
    int **a = NULL;
    do
    {
        system("cls");
        choose = Menu();
        switch (choose)
        {
        case 1:
        {
            Nhap(n, a);
            system("pause");
            break;
        }
        case 2:
        {
            Xuat(n, a);
            system("pause");
            break;
        }
        case 3:
        {
            if (DoiXungPhu(n, a))
                printf("\nMa tran nay doi xung qua duong cheo phu\n");
            else
                printf("\nMa tran nay khong doi xung qua duong cheo phu\n");
            system("pause");
            break;
        }
        case 4:
        {
            LietKe(n, a);
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

void CapPhat(int n, int **&a)
{
    a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }
}

void XoaBN(int n, int **a)
{
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
}

void Nhap(int &n, int **&a)
{
    do
    {
        printf("\nNhap cap cho ma tran vuong: ");
        scanf("%d", &n);
        if (n < 1)
            printf("\nNhap lai!");
    } while (n < 1);
    CapPhat(n, a);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nNhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void Xuat(int n, int **a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int DoiXungPhu(int n, int **a)
{
    // đường chéo phụ -> hàng tăng - cột giảm hoặc hàng + cột == n - 1
    int *b = (int *)malloc(n * sizeof(int));
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
                b[index++] = a[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (b[i] == b[n - i - 1])
            count++;
    }
    free(b);
    if (count == n / 2)
        return 1;
    else
        return 0;
}

void LietKe(int n, int **a)
{
    int *b = (int *)malloc(n * sizeof(int));
    int index = 0, maxValue;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        printf("\nTong hang %d: %d", i + 1, sum);
        b[index++] = sum;
        if (i == 0)
            maxValue = sum;
        else if (maxValue < sum)
            maxValue = sum;
    }
    printf("\n\tCac hang co tong max: ");
    for (int i = 0; i < index; i++)
    {
        if (maxValue == b[i])
            printf("\nHang %d", i + 1);
    }
    free(b);
}

int Menu()
{
    int choose;
    printf("\n--------------------------------------");
    printf("\n 1. Nhap ma tran");
    printf("\n 2. Xuat ma tran");
    printf("\n 3. Kiem tra doi xung");
    printf("\n 4. Liet ke hang co tong max");
    printf("\n 5. Thoat");
    printf("\n--------------------------------------");
    printf("\n    Lua chon cua ban -> ");
    scanf("%d", &choose);
    return choose;
}