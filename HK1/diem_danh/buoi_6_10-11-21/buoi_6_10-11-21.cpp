
/*
    Ho Ten: Hoang Gia Kiet
    MSSV: 6251071049
    Lop: IT - K62
 */

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct doi_bong
{
    char ten_doi[100];
    int so_luong;
    int diem;
};

void nhap_1_doi_bong(doi_bong *input);
void xuat_1_doi_bong(doi_bong *output);

void nhap_ds_doi_bong(doi_bong *input, int n);
void xuat_ds_doi_bong(doi_bong *output, int n);

void hoan_vi(doi_bong *a, doi_bong *b);
void ba_doi_co_diem_cao_nhat(doi_bong *db, int n);
void ba_doi_co_so_luong_cao_nhat(doi_bong *db, int n);

void sap_xep_ten_doi(doi_bong *db, int n);

void tim_kiem_theo_ten_doi_bong(doi_bong *db, int n, char x[]);

int tinh_tong_diem_cac_doi(doi_bong *db, int n);

void line(int n);

int main()
{
    char s[100];
    int n;
    do
    {
        printf("\nSo doi bong can nhap: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    doi_bong *db = (doi_bong *)calloc(n, sizeof(doi_bong));
    nhap_ds_doi_bong(db, n);

    line(130);
    printf("\n\n\t\t\t\tDANH SACH DA NHAP\n");
    xuat_ds_doi_bong(db, n);

    line(130);
    printf("\n\n\t\t\t\t3 DOI CO DIEM CAO NHAT\n");
    ba_doi_co_diem_cao_nhat(db, n);

    line(130);
    printf("\n\n\t\t\t\t3 DOI CO SO LUONG CAU THU NHIEU NHAT\n");
    ba_doi_co_so_luong_cao_nhat(db, n);

    line(130);
    printf("\n\n\t\t\t\tDANH SACH DOI BONG SAU KHI XEP LAI\n");
    sap_xep_ten_doi(db, n);
    xuat_ds_doi_bong(db, n);

    line(130);
    printf("\nNhap ten doi bong can tim: ");
    fflush(stdin);
    gets(s);
    printf("\n\n\t\t\t\tTHONG TIN CAC DOI BONG CO KET QUA TRUNG KHOP\n");
    tim_kiem_theo_ten_doi_bong(db, n, s);

    line(130);
    printf("\n\n\t\t\t\tTONG DIEM CAC DOI BONG\n");
    printf("\n%d", tinh_tong_diem_cac_doi(db, n));

    free(db);
    getch();
    return 0;
}

void nhap_1_doi_bong(doi_bong *input)
{
    printf("\nNhap ten doi bong: ");
    fflush(stdin);
    gets(input->ten_doi);
    printf("\nNhap so luong cau thu: ");
    scanf("%d", &input->so_luong);
    printf("\nNhap diem: ");
    scanf("%d", &input->diem);
}

void xuat_1_doi_bong(doi_bong *output)
{
    printf("\nTen doi: %s", output->ten_doi);
    printf("\nSo luong cau thu: %d", output->so_luong);
    printf("\nDiem: %d", output->diem);
}

void nhap_ds_doi_bong(doi_bong *input, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\n\t\tNHAP DOI BONG %d", i + 1);
        nhap_1_doi_bong(input + i);
    }
}

void xuat_ds_doi_bong(doi_bong *output, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\n\t\tTHONG TIN DOI BONG %d", i + 1);
        xuat_1_doi_bong((output + i));
    }
}

void hoan_vi(doi_bong *a, doi_bong *b)
{
    doi_bong *temp;
    temp = (doi_bong *)malloc(sizeof(doi_bong));
    *temp = *a;
    *a = *b;
    *b = *temp;
    free(temp);
}

void ba_doi_co_diem_cao_nhat(doi_bong *db, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if ((db + i)->diem < (db + j)->diem)
            {
                pos = j;
            }
        }
        if (pos != i)
        {
            hoan_vi(db + i, db + pos);
        }
    }
    xuat_ds_doi_bong(db, 3);
}
void ba_doi_co_so_luong_cao_nhat(doi_bong *db, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if ((db + i)->so_luong < (db + j)->so_luong)
            {
                pos = j;
            }
        }
        if (pos != i)
        {
            hoan_vi(db + i, db + pos);
        }
    }
    xuat_ds_doi_bong(db, 3);
}

void sap_xep_ten_doi(doi_bong *db, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp((db + i)->ten_doi, (db + j)->ten_doi) > 0)
            {
                pos = j;
            }
        }
        if (pos != i)
        {
            hoan_vi(db + i, db + pos);
        }
    }
}

void tim_kiem_theo_ten_doi_bong(doi_bong *db, int n, char x[])
{
    int j = 1;
    for (int i = 0; i < n; i++)
    {
        if (strstr(db[i].ten_doi, x) != NULL)
        {
            printf("\n\n\t\tTHONG TIN DOI BONG %d", j);
            xuat_1_doi_bong(db + i);
            j++;
        }
    }
}

int tinh_tong_diem_cac_doi(doi_bong *db, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (db + i)->diem;
    }
    return sum;
}

void line(int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("-");
    }
    printf("\n");
}
