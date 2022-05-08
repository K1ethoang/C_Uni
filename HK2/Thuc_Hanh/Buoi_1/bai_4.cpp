// #############################################################################
// ###           Name: Hoang Gia Kiet                                        ###
// ###           Code: 6251071049                                            ###
// ###           Class: CNTT - K62                                           ###
// ###           Tool: VSCode                                                ###
// ###           BM CNTT - DH GIAO THONG VAN TAI - PHAN HIEU TP.HCM          ###
// #############################################################################

/*
Bài 4: Viết chương trình nhập vào một ma trận thực cấp nxn rồi thực hiện:
- Tính tổng ma trân.
- Tìm giá trị lớn nhất của ma trận
- Tính tích các phần tử của từng cột của ma trận và cho biết những cột nào có tích nhỏ nhất.
- Ma trận trên có phải là ma trận tam giác không.
 */

#include <stdio.h>
#include <stdlib.h>

#define GRANT 100

void program();
void inputMatrix(int a[][GRANT], int n);
void outputMatrix(int a[][GRANT], int n);
double sumOfMatrix(int a[][GRANT], int n);
double maxValueOfMatrix(int a[][GRANT], int n);
void productOfColAndColumnWithTheSmallestProduct(int a[][GRANT], int n);
void checkTriangleMatrix(int a[][GRANT], int n);

int main()

{
    program();
    return 0;
}

void program()
{
    int n;
    int a[GRANT][GRANT];
    do
    {
        printf("\nNhap cap cua ma tran: ");
        scanf("%d", &n);
        if (n < 1 || n > GRANT)
            printf("\nKhong hop le - Nhap lai!");
    } while (n < 1 || n > GRANT);
    printf("\n\t\tNHAP MA TRAN\n");
    inputMatrix(a, n);
    printf("\n\t\tMA TRAN VUA NHAP\n");
    outputMatrix(a, n);
    printf("\n----------------------------------------------------\n");
    printf("\nTong cua ma tran: %.2lf", sumOfMatrix(a, n));
    printf("\n----------------------------------------------------\n");
    printf("\nGia tri lon nhat cua ma tran: %.2f", maxValueOfMatrix(a, n));
    printf("\n----------------------------------------------------\n");
    productOfColAndColumnWithTheSmallestProduct(a, n);
    printf("\n----------------------------------------------------\n");
    checkTriangleMatrix(a, n);
}

void inputMatrix(int a[][GRANT], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nNhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void outputMatrix(int a[][GRANT], int n)
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

double sumOfMatrix(int a[][GRANT], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            sum += a[i][j];
    }
    return sum;
}

double maxValueOfMatrix(int a[][GRANT], int n)
{
    double max = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (max < a[i][j])
                max = a[i][j];
    }
    return max;
}

void productOfColAndColumnWithTheSmallestProduct(int a[][GRANT], int n)
{
    double *b = (double *)malloc(n * sizeof(double));
    int index = 0;
    double minValue;
    for (int i = 0; i < n; i++)
    {
        double productOfColumn = 1;
        for (int j = 0; j < n; j++)
        {
            productOfColumn *= a[j][i];
        }
        b[index++] = productOfColumn;
        printf("\nTich cot %d: %.2lf", i + 1, productOfColumn);
        if (i == 0)
            minValue = productOfColumn;
        else if (minValue > productOfColumn)
            minValue = productOfColumn;
    }
    printf("\n\tNhung cot co tich nho nhat: ");
    for (int i = 0; i < index; i++)
    {
        if (minValue == b[i])
            printf("\nCot %d", i + 1);
    }
    free(b);
}

void checkTriangleMatrix(int a[][GRANT], int n)
{
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j && a[i][j] != 0)
            {
                check = false;
                break;
            }
        }
    }
    if (check)
    {
        printf("\nDay la ma tran tam giac Tren");
        return;
    }
    check = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j && a[i][j] != 0)
            {
                check = false;
                break;
            }
        }
    }
    if (check)
    {
        printf("\nDay la ma tran tam giac Duoi");
        return;
    }
    printf("\nDay khong phai ma tran tam giac");
}