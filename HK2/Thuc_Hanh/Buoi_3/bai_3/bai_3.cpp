// Name: Hoàng Gia Kiệt
// Code: 6251071049
// Class: CNTT - K62

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 100
#define COL 100

void CapPhat1(int m, int n, int **&a);
void XoaBN(int m, int **a);
void Nhap(int &m, int &n, int **&a);
void Xuat(int m, int n, int **a);
void NhapVB(int &m, int &n, int **&a, char *fname);
void XuatVB(int m, int n, int **a, char *fname);
void NhapNP(int &m, int &n, int **&a, char *fname);
void XuatNP(int m, int n, int **a, char *fname);
int Menu();
void addTwoMatrix(int m, int n, int **a, int **b, int **res);
void multiplyTwoMatrix(int **a, int **b, int mRes, int nRes, int **res);

int main()
{
    int mA, nA, mB, nB, mC, nC, choose;
    bool isExit = false;
    int **a, **b, **c;
    do
    {
        system("cls");
        choose = Menu();
        switch (choose)
        {
        case 1:
        {
            Nhap(mA, nA, a);
            printf("\n\t\t\tDAY VUA NHAP\n");
            Xuat(mA, nA, a);
            system("pause");
            break;
        }
        case 2:
        {
            char fName[50];
            printf("\nNhap ten file van ban can doc: ");
            fflush(stdin);
            gets(fName);
            NhapVB(mB, nB, b, fName);
            system("pause");
            break;
        }
        case 3:
        {
            char fName[50];
            printf("\nNhap ten file nhi phan can doc: ");
            fflush(stdin);
            gets(fName);
            NhapNP(mC, nC, c, fName);
            system("pause");
            break;
        }
        case 4:
        {
            char fName[50];
            if (mA == mB && nA == nB)
            {
                int **res;
                CapPhat1(mA, nA, res);
                addTwoMatrix(mA, nA, a, b, res);
                printf("\n\t\t2 MA TRAN SAU KHI CONG\n");
                Xuat(mA, nB, res);
                printf("\nNhap ten file van ban can xuat: ");
                fflush(stdin);
                gets(fName);
                strcat(fName, ".txt");
                XuatVB(mA, nA, res, fName);
                XoaBN(mA, res);
            }
            else
            {
                printf("\n\tKHONG THE CONG (KHONG CUNG CAP)\n");
            }
            system("pause");
            break;
        }
        case 5:
        {
            char fName[50];

            if (nB == mC)
            {
                int **res, mRes = mB, nRes = nC;
                CapPhat1(mRes, nRes, res);
                multiplyTwoMatrix(b, c, mRes, nRes, res);
                printf("\n\t\t2 MA TRAN SAU KHI KHAN\n");
                Xuat(mRes, nRes, res);
                printf("\nNhap ten file nhi phan can xuat: ");
                fflush(stdin);
                gets(fName);
                strcat(fName, ".bin");
                XuatNP(mRes, nRes, res, fName);
                XoaBN(mRes, res);
            }
            else
            {
                printf("\n\tKHONG THE NHAN (SO COT B != SO HANG C)\n");
            }
            system("pause");
            break;
        }
        case 6:
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
    XoaBN(mA, a);
    XoaBN(mB, b);
    XoaBN(mC, c);
    printf("\n\tThoat chuong trinh thanh cong\n");
    return 0;
}

void CapPhat1(int m, int n, int **&a)
{
    a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }
}

void XoaBN(int m, int **a)
{
    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    m = 0;
    free(a);
}

void Nhap(int &m, int &n, int **&a)
{
    do
    {
        printf("\nNhap so dong: ");
        scanf("%d", &m);
        if (m < 1 || m > ROW)
            printf("\nKhong hop le (%d <= so dong <= %d)", 1, ROW);
    } while (m < 1 || m > ROW);
    do
    {
        printf("\nNhap so cot: ");
        scanf("%d", &n);
        if (n < 1 || n > COL)
            printf("\nKhong hop le (%d <= so dong <= %d)", 1, COL);
    } while (n < 1 || n > COL);
    CapPhat1(m, n, a);
    printf("\n\t\tNHAP MA TRAN\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nNhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void Xuat(int m, int n, int **a)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void NhapVB(int &m, int &n, int **&a, char *fname)
{
    FILE *fileIn = fopen(fname, "r");
    if (fileIn == NULL)
    {
        printf("\n\t\tKhong the mo file: %s\n", fname);
        printf("\n\tThu nhap them chuoi mo rong cua file (Vd: <ten-file>.txt,...");
    }
    else
    {
        printf("\n\t\tMo file \'%s\' thanh cong\n", fname);
        fscanf(fileIn, "%d %d", &m, &n);
        CapPhat1(m, n, a);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fscanf(fileIn, "%d", &a[i][j]);
            }
        }
        Xuat(m, n, a);
    }
    fclose(fileIn);
}

void XuatVB(int m, int n, int **a, char *fname)
{
    FILE *fileOut = fopen(fname, "w");
    if (fileOut == NULL)
        printf("\n\t\tKhong the mo file: %s\n", fname);
    else
    {
        fprintf(fileOut, "%d %d", m, n);
        for (int i = 0; i < m; i++)
        {
            fprintf(fileOut, "\n");
            for (int j = 0; j < n; j++)
            {
                fprintf(fileOut, "%d ", a[i][j]);
            }
        }
        Xuat(m, n, a);
        printf("\n\t\tGhi du lieu ra file \'%s\' thanh cong\n", fname);
    }
    fclose(fileOut);
}

void NhapNP(int &m, int &n, int **&a, char *fname)
{
    FILE *fileIn = fopen(fname, "rb");
    if (fileIn == NULL)
    {
        printf("\n\t\tKhong the mo file: %s\n", fname);
        printf("\n\tThu nhap them chuoi mo rong cua file (Vd: <ten-file>.bin,...");
    }
    else
    {
        printf("\n\t\tMo file \'%s\' thanh cong\n", fname);
        fread(&m, sizeof(int), 1, fileIn);
        fread(&n, sizeof(int), 1, fileIn);
        CapPhat1(m, n, a);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fread(&a[i][j], sizeof(int), 1, fileIn);
            }
        }
        Xuat(m, n, a);
    }
    fclose(fileIn);
}

void XuatNP(int m, int n, int **a, char *fname)
{
    FILE *fileOut = fopen(fname, "wb");
    if (fileOut == NULL)
        printf("\n\t\tKhong the mo file: %s\n", fname);
    else
    {
        fwrite(&m, sizeof(int), 1, fileOut);
        fwrite(&n, sizeof(int), 1, fileOut);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fwrite(&a[i][j], sizeof(int), 1, fileOut);
            }
        }
        Xuat(m, n, a);
        printf("\n\t\tGhi du lieu ra file \'%s\' thanh cong\n", fname);
    }

    fclose(fileOut);
}

int Menu()
{
    int choose;
    printf("\n--------------------------------------");
    printf("\n 1. Nhap ma tran A tu ban phim");
    printf("\n 2. Doc ma tran B tu file van ban");
    printf("\n 3. Doc ma tran C tu file nhi phan");
    printf("\n 4. Xuat A+B ra file van ban neu cong duoc");
    printf("\n 5. Xuat B*C ra file van ban neu nhan duoc");
    printf("\n 6. Thoat");
    printf("\n--------------------------------------");
    printf("\n    Lua chon cua ban -> ");
    scanf("%d", &choose);
    return choose;
}

void addTwoMatrix(int m, int n, int **a, int **b, int **res)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyTwoMatrix(int **a, int **b, int mRes, int nRes, int **res)
{
    int sum;
    for (int row = 0; row < mRes; row++)
    {
        for (int col = 0; col < nRes; col++)
        {
            sum = 0;
            for (int i = 0; i < nRes; i++)
            {
                sum = sum + (a[row][i] * b[i][col]);
            }
            res[row][col] = sum;
        }
    }
}