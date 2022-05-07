// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// y1
// nhập mảng
void inputArray(int a[], int n);
// y2
// xuất mảng
void outputArray(int a[], int n);
// y3
// tìm phần tử lớn nhất và nhỏ nhất
void findMaxAndMinElements(int a[], int n);
// y4
// tìm và in ra vị trí phần tử dương nhỏ nhất
void findPostionOfMinPositiveElement(int a[], int n);
// y5
// tổng của mảng
int sumOfArray(int a[], int n);
// y6
// trung bình cộng và trung bình nhân
void averageAndMultiplyAverage(int a[], int n);
// y7
// tìm 1 phần tử (x nhập từ bàn phím)
int findXElement(int a[], int n, int x);
// y8
// hoán vị
void swap(int &a, int &b);
// sắp xếp tăng dần và giảm dần
void ascendingSort(int a[], int n);
void descendingSort(int a[], int n);
void sort(int a[], int n);
// y9
// xuất dãy đảo ngược của dãy ban đầu
void outputReverseArray(int a[], int n);
// y10
// thêm 1 phần tử x vào vị trí k (x,k nhập từ bàn phím)
void addOneElement(int a[], int &n, int x, int k);
// y11
// xoá 1 phần tử ở vị trí k (k nhập từ bàn phím)
void deleteOneElement(int a[], int &n, int k);
// y12
// đếm số phần tử dương và in ra tổng các phần tử dương
void countPositiveElementsAndOuputSum(int a[], int n);
// y13
// kiểm tra mảng có đối xứng hay không
bool checkPalindromicArray(int a[], int n);
// y14
// kiểm tra mảng có sắp thứ tự tăng hay không
bool checkAscendingArray(int a[], int n);
// y15
// kiểm tra 1 số nguyên tố
bool checkPrimeNumber(int n);
// đếm số nguyên tố trong mảng
int countPrimeNumberInArray(int a[], int n);
// y16
// đếm số cặp có số sau = tổng 2 số trước
int countNextNumberEqualSumOfTwoPreviousNumber(int a[], int n);
// y17
// đếm có bao nhiêu cặp ai + aj (i!=j) là số nguyên tố
int countElementIAddElementJIsPrimeNumber(int a[], int n);

void menu();
void pressAnyKey();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choose, n, a[100];
    bool exit = false, isInputArray = false;
    do
    {
        system("cls");
        printf("+---------------------------- MENU -----------------------------");
        printf("\n|  1. Nhap mang");
        printf("\n|  2. Xuat mang");
        printf("\n|  3. Phan tu lon nhat va nho nhat");
        printf("\n|  4. Vi tri phan tu duong nho nhat");
        printf("\n|  5. Tong cua mang");
        printf("\n|  6. Tinh trung binh cong, trung binh nhan");
        printf("\n|  7. Tim 1 phan tu x");
        printf("\n|  8. Sap xep mang tang dan - giam dan");
        printf("\n|  9. Xuat day dao nguoc cua day ban dau");
        printf("\n|  10. Them 1 phan tu");
        printf("\n|  11. Xoa 1 phan tu");
        printf("\n|  12. So phan tu duong va tong cua cac phan tu duong");
        printf("\n|  13. Kiem tra mang doi xung");
        printf("\n|  14. Kiem tra mang co sap thu tu tang");
        printf("\n|  15. So nguyen to co trong mang");
        printf("\n|  16. So cap ma so sau bang tong 2 so truoc");
        printf("\n|  17. So cap ai + aj (i != j) la so nguyen to");
        printf("\n|  0. Thoat chuong trinh");
        printf("\n+--------------------------- <3<3<3 ----------------------------");

        printf("\n  Nhap lua chon: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 0:
            exit = true;
            printf("\n\t\tTHOAT CHUONG TRINH THANH CONG");
            pressAnyKey();
            break;
        case 1:
            isInputArray = true;
            printf("\n\t\tNHAP MANG\n");
            do
            {
                printf("\nNhap n (0 < n <= 100): ");
                scanf("%d", &n);
                if (n < 1 || n > 100)
                {
                    printf("\n\t(!) Nhap lai (!)");
                    pressAnyKey();
                }
            } while (n < 1 || n > 100);
            inputArray(a, n);
            pressAnyKey();
            break;
        case 2:
            if (isInputArray)
            {
                printf("\n\t\tXUAT MANG\n");
                outputArray(a, n);
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 3:
            if (isInputArray)
            {
                printf("\n\t\tPHAN TU LON NHAT VA NHO NHAT");
                findMaxAndMinElements(a, n);
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 4:
            if (isInputArray)
            {
                printf("\n\t\tVI TRI PHAN TU DUONG NHO NHAT\n");
                outputArray(a, n);
                findPostionOfMinPositiveElement(a, n);
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 5:
            if (isInputArray)
            {
                printf("\n\t\tTONG CUA MANG");
                printf("\nTong la: %d", sumOfArray(a, n));
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 6:
            if (isInputArray)
            {
                printf("\n\t\tTINH TRUNG BINH CONG, TRUNG BINH NHAN");
                averageAndMultiplyAverage(a, n);
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 7:
            if (isInputArray)
            {
                printf("\n\t\tTIM 1 PHAN TU X");
                int x;
                printf("\nNhap phan tu x can tim kiem: ");
                scanf("%d", &x);
                int pos = findXElement(a, n, x);
                if (pos != -1)
                    printf("\nPhan tu x co trong mang");
                else
                    printf("\nKhong co phan tu x trong mang");
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 8:
            if (isInputArray)
            {
                sort(a, n);
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 9:
            if (isInputArray)
            {
                printf("\n\t\tDAY DAO NGUOC CUA DAY BAN DAU\n");
                outputReverseArray(a, n);
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 10:
            if (isInputArray)
            {
                printf("\n\t\tTHEM 1 PHAN TU\n");
                outputArray(a, n);
                int x, pos;
                printf("\nNhap gia tri cua phan tu x: ");
                scanf("%d", &x);
                do
                {
                    printf("\nNhap vi tri k can them (0 < k <= %d): ", n + 1);
                    scanf("%d", &pos);
                    if (pos < 1 || pos > n + 1)
                        printf("\n\t(!) Nhap lai (!)\n");
                } while (pos < 1 || pos > n + 1);
                addOneElement(a, n, x, pos);
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 11:
            if (isInputArray)
            {
                printf("\n\t\tXOA 1 PHAN TU\n");
                int pos;
                outputArray(a, n);
                do
                {
                    printf("\nNhap vi tri k can xoa (0 < k <= %d): ", n);
                    scanf("%d", &pos);
                    if (pos < 1 || pos > n)
                        printf("\n\t(!) Nhap lai (!)\n");
                } while (pos < 1 || pos > n);
                deleteOneElement(a, n, pos);
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 12:
            if (isInputArray)
            {
                printf("\n\t\tSO PHAN TU DUONG VA TONG\n");
                countPositiveElementsAndOuputSum(a, n);
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 13:
            if (isInputArray)
            {
                printf("\n\t\tKIEM TRA MANG DOI XUNG\n");
                outputArray(a, n);
                if (checkPalindromicArray(a, n))
                    printf("\nMang doi xung");
                else
                    printf("\nMang khong doi xung");
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 14:
            if (isInputArray)
            {
                printf("\n\t\tKIEM TRA MANG CO SAP THU TU TANG\n");
                outputArray(a, n);
                if (checkAscendingArray(a, n))
                    printf("\nMang sap xep tang");
                else
                    printf("\nMang khong sap xep tang");
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 15:
            if (isInputArray)
            {
                printf("\n\t\tSO NGUYEN TO CO TRONG MANG\n");
                outputArray(a, n);
                printf("\nTrong mang co %d so nguyen to", countPrimeNumberInArray(a, n));
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 16:
            if (isInputArray)
            {
                printf("\n\t\tSO CAP MA SO SAU BANG TONG 2 SO TRUOC\n");
                outputArray(a, n);
                printf("\nCo %d cap", countNextNumberEqualSumOfTwoPreviousNumber(a, n));
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        case 17:
            if (isInputArray)
            {
                printf("\n\t\tSO CAP AI + AJ LA SO NGUYEN \n");
                outputArray(a, n);
                printf("\nCo %d cap", countElementIAddElementJIsPrimeNumber(a, n));
            }
            else
                printf("\n\t(!) Ban chua nhap mang (!)");
            pressAnyKey();
            break;
        default:
            printf("\n\t(!) Khong xac dinh (!)");
            pressAnyKey();
            break;
        }
    } while (!exit);
}

void pressAnyKey()
{
    printf("\n\n");
    system("pause");
    printf("\n");
}

// y1
void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }
}

// y2
void outputArray(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        printf("%d ", a[i]);
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

// y3
void findMaxAndMinElements(int a[], int n)
{
    int maxElement = a[0], minElement = a[0];
    for (int i = 0; i < n; i++)
    {
        if (maxElement < a[i])
            maxElement = a[i];
        if (minElement > a[i])
            minElement = a[i];
    }

    printf("\nPhan tu lon nhat: %d", maxElement);
    printf("\nPhan tu nho nhat: %d", minElement);
}

// y4
void findPostionOfMinPositiveElement(int a[], int n)
{
    int minElement, minIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            minIndex = i; // vị trí phần tử dương
            minElement = a[minIndex];
            for (int j = minIndex + 1; j < n; j++)
            {
                if (minElement > a[j] && a[j] > 0)
                {
                    minElement = a[j];
                    minIndex = j;
                }
            }
            break;
        }
    }

    if (minIndex != -1)
        printf("\nVi tri phan tu duong nho nhat: %d (so %d)", minIndex + 1, minElement);
    else
        printf("\nKhong co phan tu duong nho nhat");
}

// y5
int sumOfArray(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

// y6
void averageAndMultiplyAverage(int a[], int n)
{
    int sumAverage = 0, sumMultiplyAverage = 1;
    for (int i = 0; i < n; i++)
    {
        sumAverage += a[i];
        sumMultiplyAverage *= a[i];
    }

    printf("\nTrung binh cong: %.2f", sumAverage * 1.0 / n);
    printf("\nTrung binh nhan: %.2f", pow(sumMultiplyAverage, (1.0 / n)));
}

// y7
int findXElement(int a[], int n, int x)
{
    // Linear search
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}

// y8
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void ascendingSort(int a[], int n)
{
    // tăng dần -> Insertion sort
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void descendingSort(int a[], int n)
{
    // giam dan -> bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void sort(int a[], int n)
{
    printf("\n\t\tSAP XEP MANG TANG DAN\n\n");
    ascendingSort(a, n); // tang dan
    outputArray(a, n);
    printf("\n\t\tSAP XEP MANG GIAM DAN\n\n");
    descendingSort(a, n); // giam dan
    outputArray(a, n);
}

// y9
void outputReverseArray(int a[], int n)
{
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        count++;
        printf("%d ", a[i]);
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

// y10
void addOneElement(int a[], int &n, int x, int k)
{
    for (int i = n; i >= k - 1; i--)
    {
        a[i] = a[i - 1]; // giá trị sau = giá trị trước
    }
    a[k - 1] = x;
    n++;
}

// y11
void deleteOneElement(int a[], int &n, int k)
{
    for (int i = k - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}

// y12
void countPositiveElementsAndOuputSum(int a[], int n)
{
    int count = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            count++;
            sum += a[i];
        }
    }

    if (count != 0)
    {
        printf("\nSo cac phan tu duong: %d", count);
        printf("\nTong cac phan tu duong: %d", sum);
    }
    else
        printf("\nKhong co phan tu nao duong");
}

// y13
bool checkPalindromicArray(int a[], int n)
{
    // mảng đối xứng
    // n = 5 -> 12321 là đối xứng
    // n = 6 -> 123321 là đối xứng
    if (n % 2 != 0)
    {
        // duyệt [0, (n - 1) / 2)
        // vd: n = 5 -> [0, 1];
        for (int i = 0; i < (n - 1) / 2; i++)
        {
            if (a[i] != a[n - 1 - i])
                return false;
        }
    }
    else
    {
        // duyệt [0, n / 2)
        // vd: n = 6 -> [0, 2];
        for (int i = 0; i < n / 2; i++)
        {
            if (a[i] != a[n - 1 - i]) // so sánh phần tử đầu và cuối
                return false;
        }
    }
    return true;
}

// y14
bool checkAscendingArray(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

// y15
bool checkPrimeNumber(int n)
{
    if (n < 2)
        return false;
    else
    {
        if (n == 2)
            return true;
        else
        {
            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                    return false;
            }
        }
    }
    return true;
}

int countPrimeNumberInArray(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkPrimeNumber(a[i]))
            count++;
    }
    return count;
}

// y16
int countNextNumberEqualSumOfTwoPreviousNumber(int a[], int n)
{
    int count = 0;
    // bắt đầu duyệt từ phần tử thứ 3
    for (int i = 2; i < n; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            for (int k = j - 1; k >= 0; k--)
            {
                if (a[j] + a[k] == a[i])
                    count++;
            }
        }
    }
    return count;
}

// y17
int countElementIAddElementJIsPrimeNumber(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (checkPrimeNumber(a[i] + a[j])) // true
                count++;
        }
    }
    return count;
}
