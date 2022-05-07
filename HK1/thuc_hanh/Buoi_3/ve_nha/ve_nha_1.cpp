// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62
#include <stdio.h>
#include <string.h>

struct Student
{
    char fullName[30];
    char sex[3];
    float mediumScore;
};

void inputOneStudent(Student &s);                  // nhập 1 sinh viên
void inputListOfStudents(Student s[], int n);      // nhập danh sách sinh viên
void outputOneStudent(Student s);                  // xuất 1 sinh viên
void outputListOfStudents(Student s[], int n);     // xuất danh sách sinh viên
void sortNameInAscendingOrder(Student s[], int n); // sắp xếp tên theo thứ tự tăng dần
void swap(Student &s1, Student &s2);               // hoán vị
void printLine(int n);

int main()
{
    int n;
    Student student[100];
    do
    {
        printf("\nNhap so sinh vien (0 < n <= 100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100)
            printf("\n\t(!) Nhap lai (!)\n");
    } while (n < 1 || n > 100);

    printf("\n\n\t\t\tNHAP DANH SACH SINH VIEN\n");
    inputListOfStudents(student, n);
    printLine(100);
    printf("\n\n\t\t\tDANH SACH SINH VIEN VUA NHAP\n");
    outputListOfStudents(student, n);
    printLine(100);
    printf("\n\n\t\t\tDANH SACH SINH VIEN SAU KHI SAP XEP TANG DAN THEO TEN\n");
    sortNameInAscendingOrder(student, n);
    outputListOfStudents(student, n);

    return 0;
}
void inputOneStudent(Student &s)
{
    fflush(stdin);
    printf("\n(?) Nhap ho ten: ");
    gets(s.fullName);
    printf("\n(?) Nhap gioi tinh: ");
    gets(s.sex);
    do
    {
        printf("\n(?) Nhap diem trung binh: ");
        scanf("%f", &s.mediumScore);
        if (s.mediumScore < 1 || s.mediumScore > 10)
        {
            printf("\n\t(!) Diem khong hop le (!)\n");
        }
    } while (s.mediumScore < 1 || s.mediumScore > 10);
}

void inputListOfStudents(Student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\t\tSinh vien [%d]\n", i + 1);
        inputOneStudent(s[i]);
    }
}

void outputOneStudent(Student s)
{
    printf("\n++++++++++++++++++++++++++++++++++++");
    printf("\n+     Ho ten: %s", s.fullName);
    printf("\n+     Gioi tinh: %s", s.sex);
    printf("\n+     Diem trung binh: %.1f", s.mediumScore);
    printf("\n++++++++++++++++++++++++++++++++++++");
}

void outputListOfStudents(Student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\n\t\tSinh vien [%d]", i + 1);
        outputOneStudent(s[i]);
    }
}

void swap(Student &s1, Student &s2)
{
    Student temp = s1;
    s1 = s2;
    s2 = temp;
}

void sortNameInAscendingOrder(Student s[], int n)
{
    // bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(s[j].fullName, s[j + 1].fullName) > 0)
                swap(s[j], s[j + 1]);
        }
    }
}

void printLine(int n)
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c", '-');
    }
}
