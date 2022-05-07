// viết chương trình máy tính cầm tay
// thực hiện các phep toán +, -, *, /
// dùng con trỏ cho các hàm tính +, -, *, /

// @author: Kiet && Nhu
#include <stdio.h>
#include <stdlib.h>

void input(int *a, int *b);
void menu();
int add(int *a, int *b);
int minus(int *a, int *b);
int multi(int *a, int *b);
float divise(int *a, int *b);

int main()
{
    menu();
    return 0;
}

void input(int *a, int *b)
{
    printf("Nhap a va b: ");
    scanf("%d%d", a, b);
}

void menu()
{
    int a, b, choose;
    bool exit = false;
    input(&a, &b);
    do
    {
        system("cls");
        printf("a = %d va b = %d\n", a, b);
        printf("+ ------------------------------------- +\n");
        printf("|               May tinh                |\n");
        printf("+ ------------------------------------- +\n");
        printf("|       1. Phep cong                    |\n");
        printf("|       2. Phep tru                     |\n");
        printf("|       3. Phep nhan                    |\n");
        printf("|       4. Phep chia                    |\n");
        printf("|       0. Thoat chuong trinh           |\n");
        printf("+ ------------------------------------- +\n");
        printf("\nNhap lua chon: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 0:
            exit = true;
            break;
        case 1:
            printf("\nKet qua: %d\n", add(&a, &b));
            system("pause");
            break;
        case 2:
            printf("\nKet qua: %d\n", minus(&a, &b));
            system("pause");
            break;
        case 3:
            printf("\nKet qua: %d\n", multi(&a, &b));
            system("pause");
            break;
        case 4:
            printf("\nKet qua: %.2f\n", divise(&a, &b));
            system("pause");
            break;
        default:
            printf("\nNhap lai\n");
            system("pause");
            break;
        }

    } while (!exit);
}

int add(int *a, int *b)
{
    return *a + *b;
}

int minus(int *a, int *b)
{
    return *a - *b;
}

int multi(int *a, int *b)
{
    return *a * *b;
}

float divise(int *a, int *b)
{
    return (float)*a / *b;
}
