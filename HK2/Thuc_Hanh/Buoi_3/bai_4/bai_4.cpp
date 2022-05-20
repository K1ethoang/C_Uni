// Name: Hoàng Gia Kiệt
// Code: 6251071049
// Class: CNTT - K62

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    float Item;
    Node *Next;
};

Node *TaoMoi(float x);
Node *ThemDau(Node *H, float x);
void ThemCuoi(Node *&H, float x);
void FIFO(Node *&H);
void NhapVB(Node *&H, char *fname);
void NhapNP(Node *&H, char *fname);
void XuatVB(Node *H, char *fname);
void XuatNP(Node *H, char *fname);
void Xuat(Node *H);
int Menu();
void freeMemory(Node *&H);

int main()
{

    int n, choose;
    bool isExit = false;
    Node *A = NULL, *B = NULL, *C = NULL, *D = NULL;
    do
    {
        system("cls");
        choose = Menu();
        switch (choose)
        {
        case 1:
        {
            char fName[50];
            printf("\nNhap ten file van ban can doc: ");
            fflush(stdin);
            gets(fName);
            NhapVB(A, fName);
            system("pause");
            break;
        }
        case 2:
        {
            char fName[50];
            printf("\nNhap ten file van ban can doc: ");
            fflush(stdin);
            gets(fName);
            NhapNP(B, fName);
            system("pause");
            break;
        }
        case 3:
        {
            for (Node *t = A; t != NULL; t = t->Next)
            {
                ThemCuoi(C, t->Item);
            }
            for (Node *t = B; t != NULL; t = t->Next)
            {
                ThemCuoi(C, t->Item);
            }
            char fName[50];
            printf("\n\nNhap ten file van ban can luu: ");
            fflush(stdin);
            gets(fName);
            strcat(fName, ".txt");
            XuatVB(C, fName);
            system("pause");
            break;
        }
        case 4:
        {
            bool isExist;
            for (Node *t = A; t != NULL; t = t->Next)
            {
                float valueCheck = t->Item;
                isExist = false;
                for (Node *j = D; j != NULL; j = j->Next)
                {
                    if (j->Item == valueCheck)
                    {
                        isExist = true;
                        break;
                    }
                }
                if (!isExist)
                {
                    for (Node *h = B; h != NULL; h = h->Next)
                    {
                        if (valueCheck == h->Item)
                        {
                            ThemCuoi(D, valueCheck);
                            break;
                        }
                    }
                }
            }
            char fName[50];
            printf("\n\nNhap ten file nhi phan can luu: ");
            fflush(stdin);
            gets(fName);
            strcat(fName, ".bin");
            XuatNP(D, fName);
            system("pause");
            break;
        }
        case 5:
        {
            printf("\n\t---------- XUAT A -------------\n\n");
            Xuat(A);
            printf("\n\n\t---------- XUAT B -------------\n\n");
            Xuat(B);
            printf("\n\n\t---------- XUAT C -------------\n\n");
            Xuat(C);
            printf("\n\n\t---------- XUAT D -------------\n\n");
            Xuat(D);
            printf("\n");
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
    freeMemory(A);
    freeMemory(B);
    freeMemory(C);
    freeMemory(D);
    printf("\n\tThoat chuong trinh thanh cong\n");
    return 0;
}

Node *TaoMoi(float x = 0)
{
    Node *p = new Node;
    if (p == NULL)
    {
        printf("\n\tKhong du bo nho de cap phat!");
        return NULL;
    }
    else
    {
        p->Item = x;
        p->Next = NULL;
    }
    return p;
}

Node *ThemDau(Node *H, float x)
{
    Node *p = TaoMoi(x);
    if (H == NULL)
        H = p;
    else
        p->Next = H;
    return p;
}

void ThemCuoi(Node *&H, float x)
{
    Node *p = TaoMoi(x);
    if (H == NULL)
        H = p;
    else
    {
        for (Node *t = H; t != NULL; t = t->Next)
        {
            if (t->Next == NULL)
            {
                t->Next = p;
                return;
            }
        }
    }
}

void FIFO(Node *&H)
{
    int n;
    float value;
    do
    {
        printf("\nNhap so phan tu DS FIFO: ");
        scanf("%d", &n);
        if (n < 1)
            printf("\n\t\tNhap lai!");
    } while (n < 1);
    for (static int i = 1; i <= n; i++)
    {
        printf("\n\t\tNhap phan tu %d: ", i);
        scanf("%f", &value);
        ThemCuoi(H, value);
    }
}

void NhapVB(Node *&H, char *fname)
{
    FILE *fileIn = fopen(fname, "r");
    if (fileIn == NULL)
    {
        printf("\n\t\tKhong the mo file: %s\n", fname);
        printf("\n\tThu nhap them chuoi mo rong cua file (Vd: <ten-file>.txt,...");
    }
    else
    {
        freeMemory(H);
        printf("\n\t\tMo file \'%s\' thanh cong\n", fname);
        float value;
        while (!feof(fileIn))
        {
            fscanf(fileIn, "%f", &value);
            ThemCuoi(H, value);
        }
        Xuat(H);
    }
    fclose(fileIn);
}

void NhapNP(Node *&H, char *fname)
{
    FILE *fileIn = fopen(fname, "rb");
    if (fileIn == NULL)
    {
        printf("\n\t\tKhong the mo file: %s\n", fname);
        printf("\n\tThu nhap them chuoi mo rong cua file (Vd: <ten-file>.bin,...");
    }
    else
    {
        freeMemory(H);
        printf("\n\t\tMo file \'%s\' thanh cong\n", fname);
        float value;
        while (!feof(fileIn))
        {
            fread(&value, sizeof(float), 1, fileIn);
            ThemCuoi(H, value);
        }
        Xuat(H);
    }
    fclose(fileIn);
}

void XuatVB(Node *H, char *fname)
{
    FILE *fileOut = fopen(fname, "w");
    if (fileOut == NULL)
        printf("\n\t\tKhong the mo file: %s\n", fname);
    else
    {
        for (Node *t = H; t != NULL; t = t->Next)
        {
            fprintf(fileOut, "\n%f", t->Item);
        }
        printf("\n\t\tGhi du lieu ra file \'%s\' thanh cong\n", fname);
        Xuat(H);
    }
    fclose(fileOut);
}

void XuatNP(Node *H, char *fname)
{
    FILE *fileOut = fopen(fname, "wb");
    if (fileOut == NULL)
        printf("\n\t\tKhong the mo file: %s\n", fname);
    else
    {
        for (Node *t = H; t != NULL; t = t->Next)
        {
            fwrite(&(t->Item), sizeof(float), 1, fileOut);
        }
        printf("\n\t\tGhi du lieu ra file \'%s\' thanh cong\n", fname);
        Xuat(H);
    }
    fclose(fileOut);
}

void Xuat(Node *H)
{
    int count = 0;
    for (Node *t = H; t != NULL; t = t->Next)
    {
        count++;

        printf("%.2f ", t->Item);
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

int Menu()
{
    int choose;
    printf("\n--------------------------------------");
    printf("\n 1. Doc danh sach A tu file van ban");
    printf("\n 2. Doc danh sach B tu file nhi phan");
    printf("\n 3. Noi tung phan tu cua B vao A duoc danh sach C luu ra file van ban");
    printf("\n 4. Tim nhung phan tu vua nam trong A vua nam trong B tao ra danh sach D luu ra file nhi phan");
    printf("\n 5. Xuat A, B, C, D ra man hinh");
    printf("\n 6. Thoat");
    printf("\n--------------------------------------");
    printf("\n    Lua chon cua ban -> ");
    scanf("%d", &choose);
    return choose;
}

void freeMemory(Node *&H)
{
    Node *t = NULL;
    while (H != NULL)
    {
        t = H;
        H = H->Next;
        free(t);
    }
}