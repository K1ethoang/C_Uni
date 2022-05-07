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

//              De bai                  //
// 1. Xây dựng cấu trúc Sinhvien gồm ThiSinh (Họ tên), Diem (Số điểm) và MST (Mã số trường).
// 2. Viết hàm nhập một danh sách n thí sinh (tham gia thi UTC2-Techwar) có cấu trúc như trên.
// 3. Viết hàm xuất danh sách thí sinh trên ra tệp văn bản theo dạng: dòng đầu là số thứ tự thí sinh, trên mỗi ba dòng tiếp theo là các thông tin (Hoten, Diem và Truong) của một thí sinh.
// 4. Nhập vào mã số của một trường, tính tổng số điểm và trung bình cộng số điểm của các thí sinh của trường đó.
// 5. Viết hàm main sử dụng các hàm đã viết ở trên và hoàn thiện chương trình.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Student
{
    char fullName[50];
    char schoolCode[10];
    float mark;
};

void inputAStudent(Student &s);                                        // nhập 1 thí sinh
void outputAStudent(Student s);                                        // xuất 1 thí sinh
void inputStudents(Student s[], int n);                                // nhập ds thí sinh
void outputStudents(Student s[], int n);                               // xuất ds thí sinh
void calculatingScoreOfASchool(Student s[], int n, char schoolCode[]); // tính tổng điểm và trung bình cộng số điểm của các thí sinh của 1 trường
void writeStudents(Student s[], int n);                                // xuất danh sách thí sinh ra tệp văn bản

int main()
{
    int choose, n = 0;
    bool exit = false, check = false;
    Student *s = NULL;
    do
    {
        system("cls");
        printf("######################################");
        printf("\n1. Nhap danh thi sinh");
        printf("\n2. Xem danh sach thi sinh");
        printf("\n3. Them 1 SV");
        printf("\n4. Diem tong va trung binh cua cac thi sinh cua 1 truong");
        printf("\n5. Xuat file danh sach thi sinh");
        printf("\n0. Thoat");
        printf("\n######################################");
        printf("\n\tLua chon cua ban -> ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
        {
            do
            {
                if (!check)
                {
                    check = true;
                    do
                    {
                        printf("\nNhap so luong SV: ");
                        scanf("%d", &n);
                        if (n < 1 || n > INT_MAX)
                            printf("\n\tKhong hop le - Nhap lai\n");
                    } while (n < 1 || n > INT_MAX);
                    s = (Student *)malloc(n * sizeof(Student));
                    system("cls");
                    inputStudents(s, n);
                    break;
                }
                else
                {
                    char c;
                    do
                    {
                        printf("\n\t\tBAN CO MUON NHAP LAI DANH SACH? (y/n): ");
                        fflush(stdin);
                        scanf("%c", &c);
                        if (c != 'y' && c != 'n')
                            printf("\n\t\tKhong hop le - Nhap lai");
                    } while (c != 'y' && c != 'n');
                    if (c == 'y')
                        check = false;
                }

            } while (!check);
            system("pause");
            break;
        }
        case 2:
        {
            if (check)
                outputStudents(s, n);
            else
                printf("\n\t\tBAN CHUA NHAP DANH SACH\n");
            system("pause");
            break;
        }
        case 3:
        {
            if (check)
            {
                Student t;
                inputAStudent(t);
                s = (Student *)realloc(s, (n + 1) * sizeof(Student));
                s[n++] = t;
                printf("\n\tTHI SINH VUA THEM\n");
                outputAStudent(t);
            }
            else
                printf("\n\t\tBAN CHUA NHAP DANH SACH\n");
            system("pause");
            break;
        }
        case 4:
        {
            if (check)
            {
                char schoolCode[10];
                printf("\nNhap ma so truong: ");
                fflush(stdin);
                gets(schoolCode);
                calculatingScoreOfASchool(s, n, schoolCode);
            }
            else
                printf("\n\t\tBAN CHUA NHAP DANH SACH\n");
            system("pause");
            break;
        }
        case 5:
        {
            if (check)
                writeStudents(s, n);
            else
                printf("\n\t\tBAN CHUA NHAP DANH SACH\n");
            system("pause");
            break;
        }
        case 0:
        {
            if (check)
                writeStudents(s, n);
            exit = true;
            system("pause");
            break;
        }
        default:
            printf("\n\t\tLua chon khong hop le - Nhap lai \n");
            system("pause");
            break;
        }
    } while (!exit);
    free(s);
    return 0;
}

void inputAStudent(Student &s)
{
    printf("\nNhap ho ten: ");
    fflush(stdin);
    gets(s.fullName);
    do
    {
        printf("\nNhap diem: ");
        scanf("%f", &s.mark);
        if (s.mark < 1 || s.mark > 10)
            printf("\n\tDiem khong hop le - Nhap lai\n");
    } while (s.mark < 1 || s.mark > 10);
    printf("\nNhap ma so truong: ");
    fflush(stdin);
    gets(s.schoolCode);
}

void outputAStudent(Student s)
{
    printf("\nHo ten: %s", s.fullName);
    printf("\nDiem: %.2f", s.mark);
    printf("\nMa so truong: %s", s.schoolCode);
}

void inputStudents(Student s[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("\n\n\t\tNHAP SINH VIEN %d", i + 1);
        inputAStudent(s[i]);
    }
}

void outputStudents(Student s[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("\n\n\t\tSINH VIEN %d", i + 1);
        outputAStudent(s[i]);
    }
}

void calculatingScoreOfASchool(Student s[], int n, char schoolCode[])
{
    bool exist = false;
    float sumScore;
    int count = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(s[i].schoolCode, schoolCode) == 0)
        {
            sumScore += s[i].mark;
            count++;
            exist = true;
        }
    }

    if (exist)
    {
        printf("\nMa so truong: %s", schoolCode);
        printf("\nDiem tong: %.2f", sumScore);
        printf("\nDiem trung binh: %.2f\n", sumScore / count);
    }
    else
        printf("\nKhong co thi sinh nao thuoc truong voi ma so: %s\n", schoolCode);
}

void writeStudents(Student s[], int n)
{
    FILE *fileOut = fopen("Students.txt", "w");
    if (fileOut == NULL)
    {
        printf("\n\tXuat file khong thanh cong\n");
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            fprintf(fileOut, "%d\n%s\n%.2f\n%s\n", i + 1, s[i].fullName, s[i].mark, s[i].schoolCode);
        }
        printf("\n\tFile vua xuat co ten: Students.txt\n");
    }
    fclose(fileOut);
}