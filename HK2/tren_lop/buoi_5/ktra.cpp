// #############################################################################
// ###                       Copyright © K1ethoang                           ###
// #############################################################################
// ###           Name: Hoang Gia Kiet                                        ###
// ###           Code: 6251071049                                            ###
// ###           Class: CNTT - K62                                           ###
// ###           Tool: VSCode                                                ###
// ###           BM CNTT - DH GIAO THONG VAN TAI - PHAN HIEU TP.HCM          ###
// #############################################################################
// ###     Github: https://github.com/K1ethoang                              ###
// ###     Youtube: https://www.youtube.com/K1ethoang                        ###
// #############################################################################

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct PhanSo
{
    int tuSo, mauSo;
};

void nhapPhanSo(PhanSo &ps);
void xuatPhanSo(PhanSo ps);
int UCLN(PhanSo ps);
void rutGon(PhanSo &ps);
PhanSo tong(PhanSo ps1, PhanSo ps2);
PhanSo hieu(PhanSo ps1, PhanSo ps2);
PhanSo tich(PhanSo ps1, PhanSo ps2);
PhanSo thuong(PhanSo ps1, PhanSo ps2);
void nhapMangPhanSo(PhanSo ps[], int n);
void xuatMangPhanSo(PhanSo ps[], int n);
void sapXep(PhanSo ps[], int n);
bool timKiem(PhanSo ps[], int n, PhanSo x);
void menu();

int main()
{
    menu();
    return 0;
}

void nhapPhanSo(PhanSo &ps)
{
    printf("\nNhap tu so: ");
    scanf("%d", &ps.tuSo);
    do
    {
        printf("\nNhap mau so: ");
        scanf("%d", &ps.mauSo);
        if (ps.mauSo == 0)
            printf("\n\tMau so khong hop le - Nhap lai\n");
    } while (ps.mauSo == 0);
}

void xuatPhanSo(PhanSo ps)
{
    printf("\n%d/%d\n", ps.tuSo, ps.mauSo);
}

int UCLN(PhanSo ps)
{
    int temp;
    PhanSo t;
    t.tuSo = abs(t.tuSo);
    t.mauSo = abs(t.mauSo);
    (t.tuSo > t.mauSo) ? (t.tuSo = ps.tuSo, t.mauSo = ps.mauSo) : (t.tuSo = ps.mauSo, t.mauSo = ps.tuSo);
    while (t.mauSo != 0)
    {
        temp = t.tuSo % t.mauSo;
        t.tuSo = t.mauSo;
        t.mauSo = temp;
    }
    return t.tuSo;
}

void rutGon(PhanSo &ps)
{
    if (ps.tuSo == 0)
        ps.mauSo = 0;
    else if (ps.tuSo == ps.mauSo)
    {
        ps.tuSo = 1;
        ps.mauSo = 1;
    }
    else
    {
        int ucln = UCLN(ps);
        ps.tuSo /= ucln;
        ps.mauSo /= ucln;
    }
}

PhanSo tong(PhanSo ps1, PhanSo ps2)
{
    PhanSo c;
    if (ps1.mauSo = ps2.mauSo)
    {
        c.tuSo = ps1.tuSo + ps2.tuSo;
        c.mauSo = ps1.mauSo;
    }
    else
    {
        c.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
        c.mauSo = ps1.mauSo * ps2.mauSo;
    }
    return c;
}
PhanSo hieu(PhanSo ps1, PhanSo ps2)
{
    PhanSo c;
    if (ps1.mauSo = ps2.mauSo)
    {
        c.tuSo = ps1.tuSo - ps2.tuSo;
        c.mauSo = ps1.mauSo;
    }
    else
    {
        c.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
        c.mauSo = ps1.mauSo * ps2.mauSo;
    }
    return c;
}
PhanSo tich(PhanSo ps1, PhanSo ps2)
{
    PhanSo c;
    c.tuSo = ps1.tuSo * ps2.tuSo;
    c.mauSo = ps1.mauSo * ps2.mauSo;
    return c;
}

PhanSo thuong(PhanSo ps1, PhanSo ps2)
{
    PhanSo c;
    c.tuSo = ps1.tuSo * ps2.mauSo;
    c.mauSo = ps1.mauSo * ps2.tuSo;
    return c;
}

void nhapMangPhanSo(PhanSo ps[], int n)
{
    for (int i = 0; i < n; i++)
    {
        PhanSo c;
        printf("\n\tPhan so thu %d", i + 1);
        nhapPhanSo(c);
        ps[i] = c;
    }
}

void xuatMangPhanSo(PhanSo ps[], int n)
{
    for (int i = 0; i < n; i++)
        xuatPhanSo(ps[i]);
}

void sapXep(PhanSo ps[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if ((float)ps[minIndex].tuSo / ps[minIndex].mauSo < (float)ps[j].tuSo / ps[j].mauSo)
                minIndex = j;
        }
        if (minIndex != i)
        {
            PhanSo c = ps[minIndex];
            ps[minIndex] = ps[i];
            ps[i] = c;
        }
    }
}

bool timKiem(PhanSo ps[], int n, PhanSo x)
{
    for (int i = 0; i < n; i++)
    {
        if ((ps[i].tuSo == x.tuSo) && (ps[i].mauSo == x.mauSo))
            return true;
    }
    return false;
}

void menu()
{
    int luaChon, n;
    bool thoat = false;
    PhanSo ps[100];
    do
    {
        system("cls");
        printf("\n\t\tQUAN LY SINH VIEN");
        printf("\n1. Nhap ds phan so");
        printf("\n2. Xuat ds phan so");
        printf("\n3. Tinh tong 2 ps");
        printf("\n4. Tinh hieu 2 ps");
        printf("\n5. Tinh tich 2 ps");
        printf("\n6. Tinh thuong 2 ps");
        printf("\n7. Sap xep theo thu tu giam dan");
        printf("\n8. Tim kiem phan so trong ds");
        printf("\n9. Rut gon 1 phan so");
        printf("\n0. Thoat");
        printf("\n\t\tKET THUC");
        printf("\nLua chon cua ban: ");
        scanf("%d", &luaChon);
        switch (luaChon)
        {
        case 1:
        {
            do
            {
                printf("\nSo luong phan so can nhap: ");
                scanf("%d", &n);
                if (n <= 0 || n > 100)
                {
                    printf("\n\tNhap lai\n");
                }
            } while (n <= 0 || n > 100);
            nhapMangPhanSo(ps, n);
            system("pause");
            break;
        }
        case 2:
        {
            xuatMangPhanSo(ps, n);
            system("pause");
            break;
        }
        case 3:
        {
            PhanSo ps1, ps2;
            printf("\n\tPhan so 1\n");
            nhapPhanSo(ps1);
            printf("\n\tPhan so 2\n");
            nhapPhanSo(ps2);
            xuatPhanSo(ps1);
            xuatPhanSo(ps2);
            printf("\n\tKet qua\n");
            xuatPhanSo(tong(ps1, ps2));
            system("pause");
            break;
        }
        case 4:
        {
            PhanSo ps1, ps2;
            printf("\n\tPhan so 1\n");
            nhapPhanSo(ps1);
            printf("\n\tPhan so 2\n");
            nhapPhanSo(ps2);
            xuatPhanSo(ps1);
            xuatPhanSo(ps2);
            printf("\n\tKet qua\n");
            xuatPhanSo(hieu(ps1, ps2));
            system("pause");
            break;
        }
        case 5:
        {
            PhanSo ps1, ps2;
            printf("\n\tPhan so 1\n");
            nhapPhanSo(ps1);
            printf("\n\tPhan so 2\n");
            nhapPhanSo(ps2);
            xuatPhanSo(ps1);
            xuatPhanSo(ps2);
            printf("\n\tKet qua\n");
            xuatPhanSo(tich(ps1, ps2));
            system("pause");
            break;
        }
        case 6:
        {
            PhanSo ps1, ps2;
            printf("\n\tPhan so 1\n");
            nhapPhanSo(ps1);
            printf("\n\tPhan so 2\n");
            nhapPhanSo(ps2);
            xuatPhanSo(ps1);
            xuatPhanSo(ps2);
            printf("\n\tKet qua\n");
            xuatPhanSo(thuong(ps1, ps2));
            system("pause");
            break;
        }
        case 7:
        {
            sapXep(ps, n);
            xuatMangPhanSo(ps, n);
            system("pause");
            break;
        }
        case 8:
        {
            PhanSo ps1;
            printf("\n\tPhan so can tim\n");
            nhapPhanSo(ps1);
            xuatPhanSo(ps1);
            if (timKiem(ps, n, ps1) == false)
                printf("\nPhan so khong ton tai\n");
            else
                printf("\nPhan so ton tai\n");
            system("pause");
            break;
        }
        case 9:
        {
            PhanSo ps1;
            printf("\n\tPhan so can rut gon\n");
            nhapPhanSo(ps1);
            xuatPhanSo(ps1);
            rutGon(ps1);
            printf("\n\tSau khi rut gon\n");
            rutGon(ps1);
            xuatPhanSo(ps1);
            system("pause");
            break;
        }
        case 0:
        {
            thoat = true;
            break;
        }
        default:
            printf("\n\tKhong hop le\n");
            system("pause");
            break;
        }
    } while (!thoat);
}