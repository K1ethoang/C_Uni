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

// áp dụng sắp xếp chèn để sắp xếp phân số

#include <stdio.h>
#include <stdlib.h>

struct PhanSo
{
    int tuSo, mauSo;
};

void nhapPhanSo(PhanSo &ps);
void xuatPhanSo(PhanSo ps);
void nhapMangPhanSo(PhanSo ps[], int n);
void xuatMangPhanSo(PhanSo ps[], int n);
void sapXep(PhanSo ps[], int n);

int main()
{
    int n;
    do
    {
        printf("\nNhap n: ");
        scanf("%d", &n);
        if (n <= 0)
            printf("\n\tNhap lai (n > 0)\n");
    } while (n <= 0);
    PhanSo *ps = (PhanSo *)calloc(n, sizeof(PhanSo));
    printf("\n\t\tNHAP PHAN SO\n");
    nhapMangPhanSo(ps, n);
    printf("\n\t\tPHAN SO VUA NHAP\n");
    xuatMangPhanSo(ps, n);
    sapXep(ps, n);
    printf("\n\t\tPHAN SO SAU KHI SAP XEP\n");
    xuatMangPhanSo(ps, n);
    free(ps);
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
    for (int i = 1; i < n; i++)
    {
        PhanSo key = ps[i];
        int j = i - 1;
        while (j >= 0 && (float)ps[j].tuSo / ps[j].mauSo > (float)key.tuSo / key.mauSo)
        {
            ps[j + 1] = ps[j];
            j--;
        }
        ps[j + 1] = key;
    }
}