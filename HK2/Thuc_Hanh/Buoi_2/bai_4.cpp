// Name: Hoàng Gia Kiệt
// Code: 6251071049
// Class: CNTT - K62

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int item;
    Node *pNext;
} Node;

Node *TaoMoi(int x /* = 0 */);
Node *ThemDau(Node *H, int x);
void ThemCuoi(Node *&H, int x);
void LIFO(Node *&H);
void FIFO(Node *&H);
void Xuat(Node *H);
void Xoa(Node *&H, int x);
int Menu();

int main()
{
    int choose;
    bool isExit = false;
    Node *a = NULL, *b = NULL;
    do
    {
        system("cls");
        choose = Menu();
        switch (choose)
        {
        case 1:
        {
            LIFO(a);
            system("pause");
            break;
        }
        case 2:
        {
            FIFO(b);
            system("pause");
            break;
        }
        case 3:
        {
            Xuat(a);
            system("pause");
            break;
        }
        case 4:
        {
            Xuat(b);
            system("pause");
            break;
        }
        case 5:
        {
            int x;
            printf("\nNhap gia tri x can xoa: ");
            scanf("%d", &x);
            Xoa(a, x);
            Xuat(a);
            system("pause");
            break;
        }
        case 6:
        {
            for (Node *t = a; t != NULL; t = t->pNext)
            {
                if (t->pNext == NULL)
                {
                    t->pNext = b;
                    break;
                }
            }
            Xuat(a);
            system("pause");
            break;
        }
        case 7:
        {
            isExit = true;
            break;
        }
        default:
            printf("\n\tKhong hop le - Nhap lai\n");
            system("pause");
            break;
        }
    } while (!isExit);
    free(a);
    free(b);
    return 0;
}

Node *TaoMoi(int x /* = 0 */)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("\nKhong du bo nho de cap phat");
        return NULL;
    }
    else
    {
        p->item = x;
        p->pNext = NULL;
    }
    return p;
}

Node *ThemDau(Node *H, int x)
{
    Node *p = TaoMoi(x);
    if (H == NULL)
        H = p;
    else
        p->pNext = H;
    return p;
}

void ThemCuoi(Node *&H, int x)
{
    Node *p = TaoMoi(x);
    if (H == NULL)
        H = p;
    else
    {
        for (Node *t = H; t != NULL; t = t->pNext)
        {
            if (t->pNext == NULL)
            {
                t->pNext = p;
                return;
            }
        }
    }
}

void LIFO(Node *&H)
{
    int value;
    for (static int i = 1;; i++)
    {
        printf("\n\t\tNhap phan tu %d: ", i);
        scanf("%d", &value);
        if (value != 0)
            H = ThemDau(H, value);
        else
            break;
    }
}

void FIFO(Node *&H)
{
    int n, value;
    do
    {
        printf("\nNhap so phan tu DS FIFO: ");
        scanf("%d", &n);
        if (n < 1)
            printf("\n\t\tNhap lai!");
    } while (n < 1);
    for (static int i = 1; i <= n; i++)
    {
        printf("\n\t\tNhap phan tu %d: ", i);
        scanf("%d", &value);
        ThemCuoi(H, value);
    }
}

void Xuat(Node *H)
{
    int count = 0;
    for (Node *t = H; t != NULL; t = t->pNext)
    {
        count++;
        printf("%d ", t->item);
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

void Xoa(Node *&H, int x)
{
    Node *del;
    // nằm đầu
    if (H->item == x && H->pNext != NULL)
    {
        del = H;
        H = H->pNext;
    }
    else
    {
        Node *prev;
        for (Node *t = H; t != NULL; t = t->pNext)
        {
            if (t->item == x)
            {
                prev->pNext = t->pNext;
                del = t;
                break;
            }
            prev = t;
        }
    }
    free(del);
}

int Menu()
{
    int choose;
    printf("\n--------------------------------------");
    printf("\n 1. Tao DS LIFO a");
    printf("\n 2. Tao DS FIFO b");
    printf("\n 3. Xuat a");
    printf("\n 4. Xuat b");
    printf("\n 5. Nhap x va xoa 1 x ra khoi a");
    printf("\n 6. noi lan luot phan tu cua b vao cuoi day a");
    printf("\n 7. Thoat");
    printf("\n--------------------------------------");
    printf("\n    Lua chon cua ban -> ");
    scanf("%d", &choose);
    return choose;
}