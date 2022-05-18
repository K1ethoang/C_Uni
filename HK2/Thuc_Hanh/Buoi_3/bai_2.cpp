// Name: Hoàng Gia Kiệt
// Code: 6251071049
// Class: CNTT - K62

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NhanSu
{
    char fullName[50];
    float coefficientsSalary;
    char position[50];
};

void Nhap(int &n, NhanSu *&DS);
void removeEnterChar(char *string);
void NhapFileVB(int &n, NhanSu *&a, char *fname);
void NhapFileNP(int &n, NhanSu *&a, char *fname);
void XuatMH(int n, NhanSu *a);
void XuatFileVB(int n, NhanSu *a, char *fname);
void XuatFileNP(int n, NhanSu *a, char *fname);
int Menu();

int main()
{
    int n, choose;
    bool isExit = false;
    NhanSu *a = NULL;
    do
    {
        system("cls");
        choose = Menu();
        switch (choose)
        {
        case 1:
        {
            Nhap(n, a);
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

void Nhap(int &n, NhanSu *&DS)
{
    do
    {
        printf("\nNhap so luong nhan su: ");
        scanf("%d", &n);
        if (n < 1)
        {
            printf("\nKhong hop le!");
        }
    } while (n < 1);
    DS = (NhanSu *)malloc(n * sizeof(NhanSu));
    for (int i = 0; i < n; i++)
    {
        printf("\n\n\t\tNHAP NHAN SU %d", i + 1);
        printf("\nNhap ho ten: ");
        fflush(stdin);
        gets(DS[i].fullName);
        printf("\nNhap he so luong: ");
        scanf("%f", &DS[i].coefficientsSalary);
        printf("\nNhap chuc vu: ");
        fflush(stdin);
        gets(DS[i].position);
    }
}

void removeEnterChar(char *string)
{
    size_t length = strlen(string);
    if (string[length - 1] == '\n')
        string[length - 1] = '\0';
}

void NhapFileVB(int &n, NhanSu *&a, char *fname)
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
        fgetc(fileIn);
        a = (NhanSu *)malloc(n * sizeof(NhanSu));
        for (int i = 0; i < n; i++)
        {
            fgets(a[i].fullName, sizeof(a[i].fullName), fileIn);
            removeEnterChar(a[i].fullName);
            fscanf(fileIn, "%f", &a[i].coefficientsSalary);
            fgetc(fileIn);
            fgets(a[i].position, sizeof(a[i].position), fileIn);
            removeEnterChar(a[i].position);
        }
        XuatMH(n, a);
    }
    fclose(fileIn);
}

void NhapFileNP(int &n, NhanSu *&a, char *fname)
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
        a = (NhanSu *)malloc(n * sizeof(NhanSu));
        for (int i = 0; i < n; i++)
        {
            fread(&a[i], sizeof(NhanSu), 1, fileIn);
        }
        XuatMH(n, a);
    }
    fclose(fileIn);
}

void XuatMH(int n, NhanSu *a)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\n\t\tNHAN SU %d", i + 1);
        printf("\nHo ten: %s", a[i].fullName);
        printf("\nHe so luong: %f", a[i].coefficientsSalary);
        printf("\nChuc vu: %s", a[i].position);
    }
}

void XuatFileVB(int n, NhanSu *a, char *fname)
{
    FILE *fileOut = fopen(fname, "w");
    if (fileOut == NULL)
        printf("\n\t\tKhong the mo file: %s\n", fname);
    else
    {
        fprintf(fileOut, "%d", n);
        for (int i = 0; i < n; i++)
        {
            fprintf(fileOut, "\n%s\n%f\n%s", a[i].fullName, a[i].coefficientsSalary, a[i].position);
        }
    }
    printf("\n\t\tGhi du lieu ra file \'%s\' thanh cong\n", fname);
    fclose(fileOut);
}

void XuatFileNP(int n, NhanSu *a, char *fname)
{
    FILE *fileOut = fopen(fname, "wb");
    if (fileOut == NULL)
        printf("\n\t\tKhong the mo file: %s\n", fname);
    else
    {
        fwrite(&n, sizeof(int), 1, fileOut);
        for (int i = 0; i < n; i++)
        {
            fwrite(&a[i], sizeof(NhanSu), 1, fileOut);
        }
    }
    printf("\n\t\tGhi du lieu ra file \'%s\' thanh cong\n", fname);
    fclose(fileOut);
}

int Menu()
{
    int choose;
    printf("\n--------------------------------------");
    printf("\n 1. Nhap day NhanSu a tu ban phim");
    printf("\n 2. Xuat day NhanSu a ra file van ban");
    printf("\n 3. Xuat day NhanSu a ra file nhi phan");
    printf("\n 4. Doc day tu file van ban xuat ra man hinh");
    printf("\n 5. Doc day tu file nhi phan xuat ra man hinh");
    printf("\n 6. Thoat");
    printf("\n--------------------------------------");
    printf("\n    Lua chon cua ban -> ");
    scanf("%d", &choose);
    return choose;
}