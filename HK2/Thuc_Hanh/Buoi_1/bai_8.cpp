// #############################################################################
// ###           Name: Hoang Gia Kiet                                        ###
// ###           Code: 6251071049                                            ###
// ###           Class: CNTT - K62                                           ###
// ###           Tool: VSCode                                                ###
// ###           BM CNTT - DH GIAO THONG VAN TAI - PHAN HIEU TP.HCM          ###
// #############################################################################

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

int main()
{
    program();
    return 0;
}

void program()
{
    char s[max];
    printf("\nNhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    printf("\nChuoi vua nhap: %s", s);
    printf("\n----------------------------------------------------\n");
    // if (isStringOfNumbers)
    //     printf("\nDay la chuoi so");
    // else
    //     printf("\nDay khong phai chuoi so");
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c ", s[i]);
    }
    printf("\n");
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%d ", s[i]);
    }
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