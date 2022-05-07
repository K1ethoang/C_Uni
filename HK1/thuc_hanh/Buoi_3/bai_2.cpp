// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62
#include <stdio.h>
#include <conio.h>

#define ROW 100
#define COLUMN 100

// y1: nhập mảng 2 chiều
void inputArray(int a[][COLUMN], int m, int n);
// y2: xuất mảng 2 chiều
void outputArray(int a[][COLUMN], int m, int n);
// y3: phần tử có giá trị lớn nhất và nhỏ nhất của mảng
void maxAndMinElement(int a[][COLUMN], int m, int n);

int main()
{
    int m, n, a[ROW][COLUMN];

    printf("\nNhap so hang (0 < m <= 100): ");
    scanf("%d", &m);
    while (m < 1 || m > 100)
    {
        printf("\nNhap lai so hang: ");
        scanf("%d", &m);
    }

    printf("\nNhap so cot (0 < n <= 100): ");
    scanf("%d", &n);
    while (n < 1 || n > 100)
    {
        printf("\nNhap lai so cot: ");
        scanf("%d", &n);
    }

    printf("\n\n\t\tNHAP MANG 2 CHIEU\n");
    inputArray(a, m, n);

    printf("\n\n\t\tMANG DA NHAP\n");
    outputArray(a, m, n);

    maxAndMinElement(a, m, n);

    getch();
    return 0;
}

void inputArray(int a[][COLUMN], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\nNhap a[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void outputArray(int a[][COLUMN], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

void maxAndMinElement(int a[][COLUMN], int m, int n)
{
    int maxElement = a[0][0], minElement = a[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (maxElement < a[i][j])
                maxElement = a[i][j];
            if (minElement > a[i][j])
                minElement = a[i][j];
        }
    }
    printf("\nPhan tu lon nhat: %d", maxElement);
    printf("\nPhan tu nho nhat: %d", minElement);
}