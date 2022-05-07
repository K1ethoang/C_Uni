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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char fullName[50];
    char code[12];
    float mathMark, physicsMark, chemistryMark;
} Student;

typedef struct Node
{
    Student data;
    Node *pNext;
} Node;

typedef struct List
{
    Node *pHead;
    Node *pTail;
    int size; // số lượng phần tử
} List;

void inputStudent(Student &s);                            // nhập 1 sv
void outputStudent(Student s);                            // xuất 1 sv
void initList(List &list);                                // khỏi tạo dslk
Node *createNode(Student value);                          // tạo 1 node
void insertHead(List &list, Node *New);                   // thêm vào đầu
void insertTail(List &list, Node *New);                   // thềm vào cuối
void insertNodeRandomPos(List &list, Node *New, int pos); // thêm vào vị trí bất kì
void removeNodeInHead(List &list);                        // xoá đầu
void removeNodeInTail(List &list);                        // xoá cuối
void removeNodeRandomPos(List &list, int pos);            // xoá vị trí bất kì
void display(List list);                                  // xuất dslk
float calculatingAverageScore(Student s);                 // tính điểm trung bình
void printStudentsHaveStudentship(List list);             // in những sinh viên được học bổng
void printStudentsLearnAgain(List list);                  // in những sinh viên hoc lai
void clear(List &list);                                   // xoá tất cả node trong dslk
void menu();

int main()
{
    menu();
    return 0;
}

void inputStudent(Student &s)
{
    printf("\nNhap ho ten: ");
    fflush(stdin);
    gets(s.fullName);
    do
    {
        printf("\nNhap ma so: ");
        scanf("%s", &s.code);
        if (strlen(s.code) != 10)
            printf("\n\t\tMa so khong hop le! (10 ki tu)\n");
    } while (strlen(s.code) != 10);
    do
    {
        printf("\nNhap diem toan: ");
        scanf("%f", &s.mathMark);
        if (s.mathMark < 0 || s.mathMark > 10)
            printf("\n\t\tDiem khong hop le!\n");
    } while (s.mathMark < 0 || s.mathMark > 10);
    do
    {
        printf("\nNhap diem ly: ");
        scanf("%f", &s.physicsMark);
        if (s.physicsMark < 0 || s.physicsMark > 10)
            printf("\n\t\tDiem khong hop le!\n");
    } while (s.physicsMark < 0 || s.physicsMark > 10);
    do
    {
        printf("\nNhap diem hoa: ");
        scanf("%f", &s.chemistryMark);
        if (s.chemistryMark < 0 || s.chemistryMark > 10)
            printf("\n\t\tDiem khong hop le!\n");
    } while (s.chemistryMark < 0 || s.chemistryMark > 10);
}

void outputStudent(Student s)
{
    printf("\nHo ten: %s", s.fullName);
    printf("\nMa so: %s", s.code);
    printf("\nDiem toan: %.2f", s.mathMark);
    printf("\nDiem ly: %.2f", s.physicsMark);
    printf("\nDiem hoa: %.2f", s.chemistryMark);
}

void initList(List &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
    list.size = 0;
}

Node *createNode(Student value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("\n\tKhong du bo nho de cap phat");
        return NULL;
    }
    else
    {
        p->data = value;
        p->pNext = NULL;
    }
    return p;
}

void insertHead(List &list, Node *New)
{
    // ds chưa có phần tử nào
    if (list.pHead == NULL)
        list.pHead = list.pTail = New;
    else
    {
        New->pNext = list.pHead;
        list.pHead = New; // cập nhật lại Head là node vừa thêm
    }
    list.size++;
}

void insertTail(List &list, Node *New)
{
    // ds chưa có phần tử nào
    if (list.pHead == NULL)
        list.pHead = list.pTail = New;
    else
    {
        list.pTail->pNext = New;
        list.pTail = New; // cập nhật lại Tail là node vừa thêm
    }
    list.size++;
}

void insertNodeRandomPos(List &list, Node *New, int pos)
{
    // ds đang rỗng hoặc thêm vào đầu
    if (list.pHead == NULL || pos == 1)
        insertHead(list, New);
    // thêm vào cuối ds
    else if (pos == list.size + 1)
        insertTail(list, New);
    // thêm vào [2; size]
    else
    {
        int currentPos = 0;
        Node *ptr = (Node *)malloc(sizeof(Node));
        for (Node *t = list.pHead; t != NULL; t = t->pNext)
        {
            currentPos++;
            if (pos == currentPos)
            {
                list.size++;
                Node *p = createNode(New->data);
                p->pNext = t;
                ptr->pNext = p;
                break;
            }
            ptr = t;
        }
    }
}

void removeNodeInHead(List &list)
{
    // ds không có phần tử nào
    if (list.pHead == NULL)
        return;
    else
    {
        list.size--;
        Node *delPtr = list.pHead;
        list.pHead = list.pHead->pNext;
        free(delPtr);
    }
}

void removeNodeInTail(List &list)
{ // ds không có phần tử nào
    if (list.pHead == NULL)
        return;
    // có 1 node (nằm đầu)
    else if (list.pHead == list.pTail)
        removeNodeInHead(list);
    // node nằm ở cuối
    else
    {
        Node *ptr = list.pHead;
        while (ptr != NULL)
        {
            if (ptr->pNext == list.pTail)
            {
                list.size--;
                free(list.pTail);
                ptr->pNext = NULL;
                list.pTail = ptr;
                break;
            }
            ptr = ptr->pNext;
        }
    }
}

void removeNodeRandomPos(List &list, int pos)
{
    // nằm đầu
    if (pos == 1)
        removeNodeInHead(list);
    else
    {
        int currentPos = 0;
        Node *ptr = (Node *)malloc(sizeof(Node));
        for (Node *t = list.pHead; t != NULL; t = t->pNext)
        {
            currentPos++;
            if (pos == currentPos)
            {
                list.size--;
                ptr->pNext = t->pNext;
                free(t);
                break;
            }
            ptr = t;
        }
    }
}

void display(List list)
{
    int count = 1;
    for (Node *ptr = list.pHead; ptr != NULL; ptr = ptr->pNext)
    {
        printf("\n\n\tSINH VIEN %d", count++);
        outputStudent(ptr->data);
    }
    printf("\n\n\tSo sinh vien hien co %d\n", list.size);
}

float calculatingAverageScore(Student s)
{
    float averageScoreByDecSystem = (s.mathMark + s.physicsMark + s.chemistryMark) / 3; // điểm theo hệ 10
    return (averageScoreByDecSystem / 10) * 4;                                          // hệ 4
}

void printStudentsHaveStudentship(List list)
{
    int count = 0;
    for (Node *ptr = list.pHead; ptr != NULL; ptr = ptr->pNext)
    {
        // điểm trung bình theo hệ 4 >= 3.2 là đc nhận học bổng
        if (calculatingAverageScore(ptr->data) >= 3.2)
        {
            count++;
            printf("\n\n\tSINH VIEN %d", count);
            printf("\nHo ten: %s", ptr->data.fullName);
            printf("\nMa so: %s", ptr->data.code);
            printf("\nDiem trung binh: %.2f", calculatingAverageScore(ptr->data));
        }
    }
    printf("\n\n\tSo sinh vien hien co %d\n", count);
}

void printStudentsLearnAgain(List list)
{
    int count = 0;
    for (Node *ptr = list.pHead; ptr != NULL; ptr = ptr->pNext)
    {
        // điểm trung bình theo hệ 4 < 2 là học lại
        if (calculatingAverageScore(ptr->data) < 2)
        {
            count++;
            printf("\n\n\tSINH VIEN %d", count);
            printf("\nHo ten: %s", ptr->data.fullName);
            printf("\nMa so: %s", ptr->data.code);
            printf("\nDiem trung binh: %.2f", calculatingAverageScore(ptr->data));
        }
    }
    printf("\n\n\tSo sinh vien hien co %d\n", count);
}

void clear(List &list)
{
    Node *t = (Node *)malloc(sizeof(Node));
    while (list.pHead != NULL)
    {
        t = list.pHead;
        list.pHead = list.pHead->pNext;
        free(t);
    }
    list.size = 0;
}

void menu()
{
    int choose;
    bool exit = false;
    List list;
    initList(list);
    do
    {
        system("cls");
        printf("######################################");
        printf("\n1. Them 1 SV vao dau");
        printf("\n2. Them 1 SV vao cuoi");
        printf("\n3. Them 1 SV vao bat ki");
        printf("\n4. Xuat danh sach sinh vien");
        printf("\n5. Xoa 1 SV o dau");
        printf("\n6. Xoa 1 SV o cuoi");
        printf("\n7. Xoa 1 SV bat ki");
        printf("\n8. In sinh vien duoc hoc bong");
        printf("\n9. In sinh vien hoc lai");
        printf("\n0. Thoat");
        printf("\n######################################");
        printf("\n\tLua chon cua ban -> ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
        {
            system("cls");
            printf("\n1. Them 1 SV vao dau");
            Student s;
            inputStudent(s);
            outputStudent(s);
            Node *New = createNode(s);
            insertHead(list, New);
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            printf("\n2. Them 1 SV vao cuoi");
            Student s;
            inputStudent(s);
            outputStudent(s);
            Node *New = createNode(s);
            insertTail(list, New);
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            printf("\n3. Them 1 SV vao bat ki");
            Student s;
            inputStudent(s);
            outputStudent(s);
            Node *New = createNode(s);
            int pos;
            do
            {
                printf("\nNhap vi tri can them (1 <= vi tri <= %d): ", list.size + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > list.size + 1)
                    printf("\n\t\tVi tri khong hop le\n");
            } while (pos < 1 || pos > list.size + 1);
            insertNodeRandomPos(list, New, pos);
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            printf("\n4. Xuat danh sach sinh vien");
            display(list);
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            printf("\n5. Xoa 1 SV o dau");
            if (list.size == 0)
                printf("\n\tDanh sach trong\n");
            else
            {
                removeNodeInHead(list);
                printf("\n\tXoa thanh cong\n");
            }
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            printf("\n6. Xoa 1 SV o cuoi");
            if (list.size == 0)
                printf("\n\tDanh sach trong\n");
            else
            {
                removeNodeInTail(list);
                printf("\n\tXoa thanh cong\n");
            }
            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            printf("\n7. Xoa 1 SV bat ki");
            if (list.size == 0)
                printf("\n\tDanh sach trong\n");
            else
            {
                int pos;
                do
                {
                    printf("\nNhap vi tri can xoa (1 <= vi tri <= %d): ", list.size);
                    scanf("%d", &pos);
                    if (pos < 1 || pos > list.size)
                        printf("\n\t\tVi tri khong hop le\n");
                } while (pos < 1 || pos > list.size);
                removeNodeRandomPos(list, pos);
                printf("\n\tXoa thanh cong\n");
            }
            system("pause");
            break;
        }
        case 8:
        {
            system("cls");
            printf("\n8. In sinh vien duoc hoc bong");
            if (list.size == 0)
                printf("\n\tDanh sach trong\n");
            else
                printStudentsHaveStudentship(list);
            system("pause");
            break;
        }
        case 9:
        {
            system("cls");
            printf("\n9. In sinh vien hoc lai");
            if (list.size == 0)
                printf("\n\tDanh sach trong\n");
            else
                printStudentsLearnAgain(list);
            system("pause");
            break;
        }
        case 0:
        {
            exit = true;
            break;
        }
        default:
            break;
        }
    } while (!exit);
    clear(list);
}