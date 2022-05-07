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

/* Đề bài:
Viết chương trình bằng C, sử dụng kiến thức về con trỏ để giải quyết:
Nhập dãy số nguyên, tìm các số nguyên tố và số hoàn hảo trong dãy số nguyên đó.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void inputArray(int *a, int *n);
void outputArray(int *a, int n);
bool isPrimeNumber(int n);
void checkPrimNumbers(int *a, int n, int *b, int *m);
bool isPerfectNumber(int n);
void checkPerfectNumber(int *a, int n, int *b, int *m);
void handle(int *a, int n);

int main()
{
    int a[50], n;
    handle(a, n);
    return 0;
}

void inputArray(int *a, int *n)
{
    do
    {
        printf("Nhap so luong phan tu: ");
        scanf("%d", n);
    } while (*n <= 0 || *n > 50);
    for (int i = 0; i < *n; i++)
    {
        printf("\nNhap a[%d]: ", i);
        scanf("%d", (a + i));
    }
}

void outputArray(int *a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        printf("%d ", *(a + i));
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

bool isPrimeNumber(int n)
{
    if (n < 2)
        return 0;
    else
    {
        if (n == 2)
            return 1;
        else
        {
            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                    return 0;
            }
        }
    }
    return 1;
}

void checkPrimNumbers(int *a, int n, int *b, int *m)
{
    *m = 0;
    int c[n], d = 0;
    bool isExist = false;
    for (int i = 0; i < n; i++)
    {
        if (isPrimeNumber(*(a + i)))
            *(c + d++) = *(a + i);
    }
    if (d == 0)
        return;
    // duyệt để bỏ những kết quả trùng lặp
    *(b + (*m)++) = *(c + 0);
    for (int i = 1; i < d; i++)
    {
        isExist = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (*(c + i) == *(c + j))
            {
                isExist = 1; // đã tồn tại
                break;
            }
        }
        if (!isExist) // chưa tồn tại
            *(b + (*m)++) = *(c + i);
    }
}

bool isPerfectNumber(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            sum += i;
        if (sum == n)
            return 1;
        else if (sum > n)
            return 0;
    }
    return 0;
}

void checkPerfectNumber(int *a, int n, int *b, int *m)
{
    *m = 0;
    int c[n], d = 0;
    bool isExist = false;
    for (int i = 0; i < n; i++)
    {
        if (isPerfectNumber(*(a + i)))
            *(c + d++) = *(a + i);
    }
    if (d == 0)
        return;
    // duyệt để bỏ những kết quả trùng lặp
    *(b + (*m)++) = *(c + 0);
    for (int i = 1; i < d; i++)
    {
        isExist = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (*(c + i) == *(c + j))
            {
                isExist = 1; // đã tồn tại
                break;
            }
        }
        if (!isExist)
            *(b + (*m)++) = *(c + i);
    }
}

void handle(int *a, int n)
{
    int *b, m;
    inputArray(a, &n);
    printf("\n\n\tXUAT MANG\n");
    outputArray(a, n);
    printf("\n\n\tSO NGUYEN TO\n");
    checkPrimNumbers(a, n, b, &m);
    if (m != 0)
        outputArray(b, m);
    else
        printf("\n(!) Khong so nguyen to nao het :v");
    printf("\n\n\tSO HOAN HAO\n");
    checkPerfectNumber(a, n, b, &m);
    if (m != 0)
        outputArray(b, m);
    else
        printf("\n(!) Khong so hoan hao nao het :v");
}