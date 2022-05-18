// Name: Hoàng Gia Kiệt
// Code: 6251071049
// Class: CNTT - K62

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Nhap(int *n, float **a);
void NhapFileVB(int &n, float *&a, char *fname);
void NhapFileNP(int &n, float *&a, char *fname);
void XuatMH(int n, float *a);
void XuatFileVB(int n, float *a, char *fname);
void XuatFileNP(int n, float *a, char *fname);
int Menu();

int main()
{
    int n, choose;
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
            Nhap(&n, &a);
            printf("\n\t\t\tDAY VUA NHAP\n");
            XuatMH(n, a);
            system("pause");
            break;
        }
        case 2:
        {
            char fName[50];
            printf("\nNhap ten file van ban can xuat: ");
            fflush(stdin);
            gets(fName);
            strcat(fName, ".txt");
            XuatFileVB(n, a, fName);
            system("pause");
            break;
        }
        case 3:
        {
            char fName[50];
            printf("\nNhap ten file nhi phan can xuat: ");
            fflush(stdin);
            gets(fName);
            strcat(fName, ".bin");
            XuatFileNP(n, a, fName);
            system("pause");
            break;
        }
        case 4:
        {
            char fName[50];
            printf("\nNhap ten file van ban can doc: ");
            fflush(stdin);
            gets(fName);
            NhapFileVB(n, a, fName);
            system("pause");
            break;
        }
        case 5:
        {
            char fName[50];
            printf("\nNhap ten file nhi phan can doc: ");
            fflush(stdin);
            gets(fName);
            NhapFileNP(n, a, fName);
            system("pause");
            break;
        }
        case 6:
        {
            isExit = true;
            printf("\n\tThoat chuong trinh thanh cong\n");
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

void Nhap(int *n, float **a)
{
    do
    {
        printf("\nNhap so phan tu: ");
        scanf("%d", n);
        if (*n < 1)
            printf("\nNhap lai!");
    } while (*n < 1);
    *a = (float *)malloc(*n * sizeof(float));
    for (int i = 0; i < *n; i++)
    {
        printf("\nNhap a[%d] -> ", i);
        scanf("%f", &(*a)[i]);
    }
}

void NhapFileVB(int &n, float *&a, char *fname)
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
        fscanf(fileIn, "%d", &n);
        a = (float *)malloc(n * sizeof(float));
        for (int i = 0; i < n; i++)
        {
            fscanf(fileIn, "%f", &a[i]);
        }
        XuatMH(n, a);
    }
    fclose(fileIn);
}

void NhapFileNP(int &n, float *&a, char *fname)
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
        fread(&n, sizeof(int), 1, fileIn);
        a = (float *)malloc(n * sizeof(float));
        for (int i = 0; i < n; i++)
        {
            fread(&a[i], sizeof(float), 1, fileIn);
        }
        XuatMH(n, a);
    }
    fclose(fileIn);
}

void XuatMH(int n, float *a)
{
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
}

void XuatFileVB(int n, float *a, char *fname)
{
    FILE *fileOut = fopen(fname, "w");
    if (fileOut == NULL)
        printf("\n\t\tKhong the mo file: %s\n", fname);
    else
    {
        fprintf(fileOut, "%d\n", n);
        for (int i = 0; i < n; i++)
        {
            fprintf(fileOut, "%f ", a[i]);
        }
    }
    printf("\n\t\tGhi du lieu ra file \'%s\' thanh cong\n", fname);
    fclose(fileOut);
}

void XuatFileNP(int n, float *a, char *fname)
{
    FILE *fileOut = fopen(fname, "wb");
    if (fileOut == NULL)
        printf("\n\t\tKhong the mo file: %s\n", fname);
    else
    {
        fwrite(&n, sizeof(int), 1, fileOut);
        for (int i = 0; i < n; i++)
        {
            fwrite(&a[i], sizeof(float), 1, fileOut);
        }
    }
    printf("\n\t\tGhi du lieu ra file \'%s\' thanh cong\n", fname);
    fclose(fileOut);
}

int Menu()
{
    int choose;
    printf("\n--------------------------------------");
    printf("\n 1. Nhap day a tu ban phim");
    printf("\n 2. Xuat day a ra file van ban");
    printf("\n 3. Xuat day a ra file nhi phan");
    printf("\n 4. Doc day tu file van ban xuat ra man hinh");
    printf("\n 5. Doc day tu file nhi phan xuat ra man hinh");
    printf("\n 6. Thoat");
    printf("\n--------------------------------------");
    printf("\n    Lua chon cua ban -> ");
    scanf("%d", &choose);
    return choose;
}