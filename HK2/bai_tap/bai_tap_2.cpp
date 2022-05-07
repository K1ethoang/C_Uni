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

/*
Xay dung bai toan quan ly sinh vien.
gom nhung thong tin
+ sinh vien (masv, hoten, ngaysinh, diem THDC, diem KTLT)
+ giangvien (magv, hoten, ngaysinh)
+ monhoc (mamonhoc, tenmonhoc, sotinchi)
-- Nhap xuat thong tin sinh vien, giang vien, mon hoc
-- Tinh diem trung binh cho sv = (THDC+KTLT)/2
-- Sap xep giang vien tang dan theo ngay sinh
-- Tim nhung mon hoc co so tin chi = 2
 */

#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day, month, year;
};

struct Student
{
    char id[15];
    char fullName[30];
    Date birthDay;
    float THDC_score;
    float KTLT_score;
};

struct Teacher
{
    char id[15];
    char fullName[30];
    Date birthDay;
};

struct Subject
{
    char code[15];
    char name[30];
    int credit; // tín chỉ
};

void menu();
bool isValidDate(Date date);
void inputDate(Date &date);
void outputDate(Date date);
void inputAStudent(Student &student);
void outputAStudent(Student student);
void inputATeacher(Teacher &teacher);
void outputATeacher(Teacher teacher);
void inputASubject(Subject &subject);
void outputASubject(Subject &subject);
float calculatingAverageScore(float score1, float score2);
void swapTwoTeacher(Teacher &t1, Teacher &t2);
void sortTeacherInAscendingByBirthday(Teacher teacher[], int n);
void findSubjectsHaveCreditEqualToTwo(Subject subject[], int n);
void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    Student student[100];
    Teacher teacher[100];
    Subject subject[100];
    int choose, nStudent = 0, nTeacher = 0, nSubject = 0;
    bool exit = false;
    do
    {
        system("cls");
        printf("\n\t\tQUAN LY SINH VIEN");
        printf("\n1. Nhap 1 sinh vien");
        printf("\n2. Xuat ds sinh vien");
        printf("\n3. Nhap 1 giang vien");
        printf("\n4. Xuat ds giang vien");
        printf("\n5. Nhap 1 mon hoc");
        printf("\n6. Xuat ds mon hoc");
        printf("\n7. Tinh diem trung binh sv");
        printf("\n8. Sap xep giang vien tang dan theo ngay sinh");
        printf("\n9. Mon hoc co so tin chi = 2");
        printf("\n0. Thoat");
        printf("\n\t\tKET THUC");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            inputAStudent(student[nStudent++]); // student[i]
            break;
        case 2:
        {
            int count = 1;
            for (int i = 0; i < nStudent; i++)
            {
                printf("\n\tSinh vien thu [%d]", count++);
                outputAStudent(student[i]);
            }
            system("pause");
            break;
        }
        case 3:
            inputATeacher(teacher[nTeacher++]); // teacher[i]
            break;
        case 4:
        {
            int count = 1;
            for (int i = 0; i < nTeacher; i++)
            {
                printf("\n\tGiang vien thu [%d]", count++);
                outputATeacher(teacher[i]);
            }
            system("pause");
            break;
        }
        case 5:
            inputASubject(subject[nSubject++]); // subject[i]
            break;
        case 6:
        {
            int count = 1;
            for (int i = 0; i < nSubject; i++)
            {
                printf("\n\tMon hoc thu [%d]", count++);
                outputASubject(subject[i]);
            }
            system("pause");
            break;
        }
        case 7:
        {
            int count = 1;
            for (int i = 0; i < nStudent; i++)
                printf("\n%-3d\t%-30s\t%.2f", count++, student[i].fullName, calculatingAverageScore(student[i].THDC_score, student[i].KTLT_score));
            system("pause");
            break;
        }
        case 8:
        {
            sortTeacherInAscendingByBirthday(teacher, nTeacher);
            int count = 1;
            for (int i = 0; i < nTeacher; i++)
            {
                printf("\n\tGiang vien thu [%d]", count++);
                outputATeacher(teacher[i]);
            }
            system("pause");
            break;
        }
        case 9:
        {
            printf("\n\tNhung mon hoc so tin chi = 2\n");
            int count = 1;
            findSubjectsHaveCreditEqualToTwo(subject, nSubject);
            system("pause");
            break;
        }
        case 0:
        {
            exit = 1;
            break;
        }
        default:
            printf("\n\tKhong hop le\n");
            break;
        }
    } while (!exit);
}

bool isValidDate(Date date)
{
    if (date.year <= 0 || date.month <= 0 || date.month > 12 || date.day <= 0 || date.day > 31)
        return 0;
    if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12)
    {
        if (date.day <= 31)
            return 1;
    }
    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
    {
        if (date.day <= 30)
            return 1;
    }
    if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0)
    {
        if (date.day <= 29)
            return 1;
    }
    else
    {
        if (date.day <= 28)
            return 1;
    }
    return 0;
}

void inputDate(Date &date)
{
    do
    {
        printf("\nNhap ngay sinh (dd): ");
        scanf("%d", &date.day);
        printf("\nNhap thang sinh (mm): ");
        scanf("%d", &date.month);
        printf("\nNhap nam sinh (yyyy): ");
        scanf("%d", &date.year);
        if (!isValidDate(date))
            printf("\n\tNgay sinh khong hop le\n");
    } while (!isValidDate(date));
}

void outputDate(Date date)
{
    printf("\nNgay sinh: %.2d/%.2d/%.4d", date.day, date.month, date.year);
}

void inputAStudent(Student &student)
{
    printf("\nNhap mssv: ");
    scanf("%s", &student.id);
    printf("\nNhap ho va ten sinh vien: ");
    fflush(stdin);
    gets(student.fullName);
    inputDate(student.birthDay);
    do
    {
        printf("\nNhap diem THDC : ");
        scanf("%f", &student.THDC_score);
        if (student.THDC_score <= 0 || student.THDC_score > 10)
            printf("\nNhap lai\n");
    } while (student.THDC_score <= 0 || student.THDC_score > 10);

    do
    {
        printf("\nNhap diem KTLT : ");
        scanf("%f", &student.KTLT_score);
        if (student.KTLT_score <= 0 || student.KTLT_score > 10)
            printf("\nNhap lai\n");
    } while (student.KTLT_score <= 0 || student.KTLT_score > 10);
}

void outputAStudent(Student student)
{
    printf("\nMssv: %s", student.id);
    printf("\nHo va ten: %s", student.fullName);
    outputDate(student.birthDay);
    printf("\nDiem THDC: %.2f", student.THDC_score);
    printf("\nDiem KTLT: %.2f", student.KTLT_score);
}

void inputATeacher(Teacher &teacher)
{
    printf("\nNhap ma gv: ");
    scanf("%s", &teacher.id);
    printf("\nNhap ho ten giao vien: ");
    fflush(stdin);
    gets(teacher.fullName);
    inputDate(teacher.birthDay);
}
void outputATeacher(Teacher teacher)
{
    printf("\nMa gv: %s", teacher.id);
    printf("\nHo va ten: %s", teacher.fullName);
    outputDate(teacher.birthDay);
}

void inputASubject(Subject &subject)
{
    printf("\nNhap ma mon hoc: ");
    scanf("%s", subject.code);
    printf("\nNhap ten mon hoc: ");
    fflush(stdin);
    gets(subject.name);
    printf("\nNhap so tin chi: ");
    scanf("%d", &subject.credit);
}

void outputASubject(Subject &subject)
{
    printf("\nMa mon hoc: %s", subject.code);
    printf("\nTen mon hoc: %s", subject.name);
    printf("\nSo tin chi: %d", subject.credit);
}

float calculatingAverageScore(float score1, float score2)
{
    return (score1 + score2) / 2;
}

void swapTwoTeacher(Teacher &t1, Teacher &t2)
{
    Teacher temp = t1;
    t1 = t2;
    t2 = temp;
}

void sortTeacherInAscendingByBirthday(Teacher teacher[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; // gíao viên có ngày sinh bé nhất
        for (int j = i + 1; j < n; j++)
        {
            if (teacher[minIndex].birthDay.year > teacher[j].birthDay.year) // nếu năm lớn hơn -> đưa xuống cuối
                minIndex = j;
            else if (teacher[minIndex].birthDay.year == teacher[j].birthDay.year) // năm bằng -> so tháng
            {
                if (teacher[minIndex].birthDay.month > teacher[j].birthDay.month) // tháng lớn hơn -> đưa xuống cuối
                    minIndex = j;
                else if (teacher[minIndex].birthDay.month == teacher[j].birthDay.month) // tháng bằng -> so ngày
                {
                    if (teacher[minIndex].birthDay.day > teacher[j].birthDay.day)
                        minIndex = j;
                }
            }
            if (minIndex != i)
                swapTwoTeacher(teacher[i], teacher[minIndex]);
        }
    }
}

void findSubjectsHaveCreditEqualToTwo(Subject subject[], int n)
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (subject[i].credit == 2)
        {
            printf("\n\tMon hoc thu [%d]", count++);
            outputASubject(subject[i]);
        }
    }
}