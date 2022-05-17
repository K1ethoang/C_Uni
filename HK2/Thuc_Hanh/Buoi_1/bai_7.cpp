// Name: Hoàng Gia Kiệt
// Code: 6251071049
// Class: CNTT - K62

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Student
{
    char fullName[50];
    float mark;
    char codeSchool[10];
} Student;

void inputAStudent(Student &s);
void outputAStudent(Student s);
void inputStudents(Student s[], int &n);
void outputStudents(Student s[], int n);
float sumMarkOfASchool(Student s[], int n, char *codeSchool);
void sortDescendingStudentsOrderByMark(Student s[], int n);
void statistical(Student s[], int n);
void program();

int main()
{
    program();
    return 0;
}

void inputAStudent(Student &s)
{
    printf("\nNhap ho va ten: ");
    fflush(stdin);
    gets(s.fullName);
    do
    {
        printf("\nNhap diem: ");
        scanf("%f", &s.mark);
        if (s.mark <= 0 || s.mark > 10)
            printf("\nDiem khong hop le!");
    } while (s.mark <= 0 || s.mark > 10);
    printf("\nNhap ma truong: ");
    fflush(stdin);
    gets(s.codeSchool);
}

void outputAStudent(Student s)
{
    printf("\nHo va ten: %s", s.fullName);
    printf("\nDiem: %.2f", s.mark);
    printf("\nTruong: %s", s.codeSchool);
}

void inputStudents(Student s[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        Student t;
        printf("\n\t\tNHAP THI SINH %d", i + 1);
        inputAStudent(t);
        s[i] = t;
    }
}

void outputStudents(Student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\t\tTHI SINH %d", i + 1);
        outputAStudent(s[i]);
    }
}

float sumMarkOfASchool(Student s[], int n, char *codeSchool)
{
    float sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(s[i].codeSchool, codeSchool) == 0)
            sum += s[i].mark;
    }
    return sum;
}

void sortDescendingStudentsOrderByMark(Student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indexMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (s[indexMin].mark < s[j].mark)
            {
                indexMin = j;
            }
        }
        if (indexMin != i)
        {
            Student t = s[i];
            s[i] = s[indexMin];
            s[indexMin] = t;
        }
    }
}

void statistical(Student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indexMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(s[indexMin].codeSchool, s[j].codeSchool) > 0)
                indexMin = j;
        }
        if (indexMin != i)
        {
            Student t = s[i];
            s[i] = s[indexMin];
            s[indexMin] = t;
        }
    }
    float sumOfMaxSchool, res[n];
    for (int i = 0; i < n; i++)
    {
        char codeSchool[10];
        strcpy(codeSchool, s[i].codeSchool);
        float sum = sumMarkOfASchool(s, n, codeSchool);
        if (i == 0 || strcmp(codeSchool, s[i - 1].codeSchool) != 0)
        {
            res[i] = sum;
            printf("\nMa truong: %s - %.2f diem", codeSchool, sum);
        }
        if (i == 0 || (i != 0 && sum > sumOfMaxSchool))
        {
            sumOfMaxSchool = sum;
            res[i] = sum;
        }
    }
    printf("\n\t\tMa cua Truong co diem cao nhat - %d diem", sumOfMaxSchool);
    for (int i = 0; i < n; i++)
    {
        if (res[i] == sumOfMaxSchool)
            printf("\n%s", s[i].codeSchool);
    }
}

void program()
{
    int choose, n = 0;
    bool isExit = false;
    Student *s = NULL;
    do
    {
        system("cls");
        printf("1. Nhap ds thi sinh");
        printf("\n2. Xuat ds thi sinh");
        printf("\n3. Tinh tong diem truong x");
        printf("\n4. Thong ke tong diem moi truong va truong co diem cao nhat");
        printf("\n0. Thoat");
        printf("\n\n\tNhap lua chon -> ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
        {
            do
            {
                printf("\nNhap so thi sinh: ");
                scanf("%d", &n);
                if (n <= 0 || n > 100)
                    printf("\nNhap lai!");
            } while (n <= 0 || n > 100);
            s = (Student *)malloc(n * sizeof(Student));
            inputStudents(s, n);
            getch();
            break;
        }
        case 2:
        {
            sortDescendingStudentsOrderByMark(s, n);
            outputStudents(s, n);
            getch();
            break;
        }
        case 3:
        {
            char code[10];
            printf("\nNhap ma cua truong can tinh tong: ");
            fflush(stdin);
            gets(code);
            float sum = sumMarkOfASchool(s, n, code);
            if (sum != 0)
                printf("\nTong diem cua truong co ma: %s - %.2f diem", code, sum);
            else
                printf("\nKhong co truong voi ma: %s", code);
            getch();
            break;
        }
        case 4:
        {
            statistical(s, n);
            getch();
            break;
        }
        case 0:
        {
            isExit = true;
            break;
        }

        default:
            printf("\n\tKhong hop le - Nhap lai\n");
            getch();
            break;
        }
    } while (!isExit);
    free(s);
}
