// Name: Hoàng Gia Kiệt
// Code: 6251071049
// Class: CNTT - K62

/*
Bài 8. Viết các hàm thực hiện:

- Kiểm tra một xâu s có phải là một chuỗi số.
- Đếm số từ của xâu
- Lấy ra n ký tự bên trái của chuỗi s.
- Lấy ra n ký tự bên phải của chuỗi s.
- Lấy ra n ký tự bắt đầu từ vị trí thứ m của chuỗi s.
 */

#include <stdio.h>
#include <string.h>

#define max 1000000

void program();
bool isStringOfNumbers(char s[]);
int countWord(char s[]);
void getLeft(char s[], int n);
void getRight(char s[], int n);
void getSubString(char s[], int n, int m);

int main()
{
    program();
    return 0;
}

void program()
{
    int n, m;
    char s[max];
    printf("\nNhap chuoi: ");
    fflush(stdin);
    gets(s);
    printf("\nChuoi vua nhap: \'%s\'", s);
    printf("\n----------------------------------------------------\n");
    if (isStringOfNumbers(s))
        printf("\nDay la chuoi so");
    else
        printf("\nDay khong phai chuoi so");
    printf("\n----------------------------------------------------\n");
    printf("\nSo tu cua xau: %d", countWord(s));
    printf("\n----------------------------------------------------\n");
    printf("\nNhap n ki tu can lay ben trai: ");
    scanf("%d", &n);
    getLeft(s, n);
    printf("\n----------------------------------------------------\n");
    printf("\nNhap n ki tu can lay ben phai: ");
    scanf("%d", &n);
    getRight(s, n);
    printf("\n----------------------------------------------------\n");
    printf("\nNhap n ki tu can lay: ");
    scanf("%d", &n);
    printf("\nNhap vi tri bat dau: ");
    scanf("%d", &m);
    getSubString(s, n, m);
}

bool isStringOfNumbers(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int countWord(char s[])
{
    int count = 1;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
            count++;
    }
    return count;
}

void getLeft(char s[], int n)
{
    printf("\'");
    for (int i = 0; i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\'");
}

void getRight(char s[], int n)
{
    printf("\'");
    for (int i = strlen(s) - n; i < strlen(s); i++)
    {
        printf("%c", s[i]);
    }
    printf("\'");
}

void getSubString(char s[], int n, int m)
{
    int count = 0;
    printf("\'");
    for (int i = m - 1;; i++)
    {
        count++;
        printf("%c", s[i]);
        if (count == n)
            break;
    }
    printf("\'");
}