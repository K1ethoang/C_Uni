#include <stdio.h>
#include <stdlib.h>

void input(int &a, int &b);
void sum(const int &a, const int &b);
int minus(const int &a, const int &b);
void handle(const int &a, const int &b, int *tich, float *thuong);

int main()
{
    int a, b;
    float *thuong = (float *)calloc(1, sizeof(float));
    int *tich = (int *)malloc(sizeof(int));

    input(a, b);
    sum(a, b);
    printf("\nhieu: %d", minus(a, b));
    handle(a, b, tich, thuong);
    printf("\ntich: %d", *tich);
    printf("\nthuong: %.2f", *thuong);

    free(tich);
    free(thuong);
    return 0;
}

void input(int &a, int &b)
{
    printf("\nNhap a: ");
    scanf("%d", &a);
    printf("\nNhap b: ");
    scanf("%d", &b);
}

void sum(const int &a, const int &b)
{
    printf("\ntong: %d", a + b);
}
int minus(const int &a, const int &b)
{
    return a - b;
}

void handle(const int &a, const int &b, int *tich, float *thuong)
{
    *tich = a * b;
    *thuong = (float)a / b;
}