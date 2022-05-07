// #############################################################################
// ###           Name: Hoang Gia Kiet                                        ###
// ###           Code: 6251071049                                            ###
// ###           Class: CNTT - K62                                           ###
// ###           Tool: VSCode                                                ###
// ###           BM CNTT - DH GIAO THONG VAN TAI - PHAN HIEU TP.HCM          ###
// #############################################################################

/*
 Bài 1. Cấu trúc điều khiển
1.1 Viết chương trình nhập vào hai số a và b, nhập một trong các phép toán pt: +, -,* , /. ^. In
lên màn hình kết quả của biểu thức a pt b. Ví dụ: a=5, b=2, pt=^ thì trên màn hình hiển thị
5 ^ 2 = 25.
1.2 Sửa lại chương trình trên để người dùng có thể thực hiện nhiều cho đến khi muốn kết thúc
bằng ấn nhấn phím thoát (ESC, n…).
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void program();
void inputNumber(float *a, float *b);
void inputChar(char *c);

int main()
{
    program();
    return 0;
}

void program()
{
    float a, b;
    char c, key_press;
    bool exit = false;
    while (!exit)
    {
        inputNumber(&a, &b);
        inputChar(&c);
        switch (c)
        {
        case '+':
            printf("\n\n\t%.2f %c %.2f = %.2f\n", a, c, b, a + b);
            break;
        case '-':
            printf("\n\n\t%.2f %c %.2f = %.2f\n", a, c, b, a - b);
            break;
        case '*':
            printf("\n\n\t%.2f %c %.2f = %.2f\n", a, c, b, a * b);
            break;
        case '/':
            printf("\n\n\t%.2f %c %.2f = %.2f\n", a, c, b, a / b);
            break;
        case '^':
            printf("\n\n\t%.2f %c %.2f = %.2f\n", a, c, b, pow(a, b));
            break;
        }
        printf("\n\tTiep tuc (Phim bat ky) - Thoat (Phim 'ESC') ");
        key_press = getch();
        if ((int)key_press == 27)
            exit = true;
        else
            system("cls");
    }
}

void inputNumber(float *a, float *b)
{
    printf("\nNhap a: ");
    scanf("%f", a);
    printf("\nNhap b: ");
    scanf("%f", b);
    printf("\n\ta = %.2f va b = %.2f", *a, *b);
}

void inputChar(char *c)
{
    do
    {
        printf("\nNhap 1 trong cac phep toan de tinh (+ , - , * , / , ^): ");
        fflush(stdin);
        *c = getc(stdin);
        if (*c != '+' && *c != '-' && *c != '*' && *c != '/' && *c != '^')
            printf("\n\n\tPhep toan khong hop le! - Nhap lai");
    } while (*c != '+' && *c != '-' && *c != '*' && *c != '/' && *c != '^');
}