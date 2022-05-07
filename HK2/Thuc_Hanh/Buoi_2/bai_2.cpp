// #############################################################################
// ###           Name: Hoang Gia Kiet                                        ###
// ###           Code: 6251071049                                            ###
// ###           Class: CNTT - K62                                           ###
// ###           Tool: VSCode                                                ###
// ###           BM CNTT - DH GIAO THONG VAN TAI - PHAN HIEU TP.HCM          ###
// #############################################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sach
{
    char tenSach[100];
    char tacGia[50];
    int namXuatBan;
};

void Nhap(int *n, Sach *&A);
void Xuat(int n, Sach A[]);
int DemSach(int n, Sach *a);
void Thongke(int n, Sach *a);
int Menu();

int main()
{
    int choose, n = 0;
    bool isExit = false;
    Sach *a = NULL;
    do
    {
        system("cls");
        choose = Menu();
        switch (choose)
        {
        case 1:
        {
            Nhap(&n, a);
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
            printf("\nSo cuon sach cua tac gia nay: %d\n", DemSach(n, a));
            system("pause");
            break;
        }
        case 4:
        {
            Thongke(n, a);
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

void Nhap(int *n, Sach *&A)
{
    do
    {
        printf("\nNhap so cuon sach: ");
        scanf("%d", n);
        if (*n < 1 || *n > 1000)
            printf("\nNhap lai!");
    } while (*n < 1 || *n > 1000);
    A = (Sach *)malloc(*n * sizeof(Sach));
    printf("\n\t\tNHAP SACH\n");
    for (int i = 0; i < *n; i++)
    {
        printf("\n\n\tNhap sach %d\n", i + 1);
        printf("\nNhap ten sach: ");
        fflush(stdin);
        gets(A[i].tenSach);
        printf("\nNhap ten tac gia: ");
        gets(A[i].tacGia);
        printf("\nNhap nam xuat ban: ");
        scanf("%d", &A[i].namXuatBan);
    }
}

void Xuat(int n, Sach A[])
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\n\t\tSach %d", i + 1);
        printf("\nTen sach: %s", A[i].tenSach);
        printf("\nTen tac gia: %s", A[i].tacGia);
        printf("\nNam xuat ban: %d", A[i].namXuatBan);
    }
}

int DemSach(int n, Sach *a)
{
    int count = 0;
    char ten[50];
    printf("\nNhap ten tac gia can xem co bao nhieu sach: ");
    fflush(stdin);
    gets(ten);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(a[i].tacGia, ten) == 0)
            count++;
    }
    return count;
}

void Thongke(int n, Sach *a)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[minIndex].namXuatBan > a[j].namXuatBan)
                minIndex = j;
        }
        if (minIndex != i)
        {
            Sach t = a[i];
            a[i] = a[minIndex];
            a[minIndex] = t;
        }
    }

    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i].namXuatBan == a[i + 1].namXuatBan)
            count++;
        else
        {
            printf("\n%d : %d cuon", a[i].namXuatBan, count);
            count = 1;
        }
    }
}

int Menu()
{
    int choose;
    printf("\n--------------------------------------");
    printf("\n 1. Nhap n cuon sach");
    printf("\n 2. Xuat n cuon sach");
    printf("\n 3. Dem theo tac gia");
    printf("\n 4. Thong ke");
    printf("\n 5. Thoat");
    printf("\n--------------------------------------");
    printf("\n    Lua chon cua ban -> ");
    scanf("%d", &choose);
    return choose;
}