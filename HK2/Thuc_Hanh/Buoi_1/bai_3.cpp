// #############################################################################
// ###           Name: Hoang Gia Kiet                                        ###
// ###           Code: 6251071049                                            ###
// ###           Class: CNTT - K62                                           ###
// ###           Tool: VSCode                                                ###
// ###           BM CNTT - DH GIAO THONG VAN TAI - PHAN HIEU TP.HCM          ###
// #############################################################################

/*
Bài 3. Viết chương trình nhập vào một dãy điểm trên mặt phẳng tọa độ x0y và thực hiện:
Tính độ dài đường gấp khúc lần lượt đi qua các điểm 1, 2,..n.
Tìm các điểm xa trục hoành nhất.
Đếm và in các đoạn cắt trục tung.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct Point
{
    int x;
    int y;
};

void program();
void inputPoints(Point p[], int n);
void outputPoints(Point p[], int n);
float calculatingLengthTwoPoints(Point p1, Point p2);
void lengthPoints(Point p[], int n);
void PointFarthestFromHorizontalAxis(Point p[], int n);
void countAndPrintLineSegmentsCutVerticalAxis(Point p[], int n);

int main()

{
    program();
    return 0;
}

void program()
{
    int n;
    do
    {
        printf("\nNhap so phan tu can co: ");
        scanf("%d", &n);
        if (n < 1 || n > INT_MAX)
            printf("\nKhong hop le - Nhap lai!");
    } while (n < 1 || n > INT_MAX);
    Point *p = (Point *)malloc(n * sizeof(Point));
    printf("\n\t\tNHAP DIEM\n");
    inputPoints(p, n);
    printf("\n\t\tCAC DIEM VUA NHAP\n");
    outputPoints(p, n);
    printf("\n----------------------------------------------------\n");
    lengthPoints(p, n);
    printf("\n----------------------------------------------------\n");
    PointFarthestFromHorizontalAxis(p, n);
    printf("\n----------------------------------------------------\n");
    countAndPrintLineSegmentsCutVerticalAxis(p, n);
}

void inputPoints(Point p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\n\t\tNHAP DIEM P%d", i);
        printf("\nNhap x: ");
        scanf("%d", &p[i].x);
        printf("\nNhap y: ");
        scanf("%d", &p[i].y);
    }
}

void outputPoints(Point p[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        printf("P%d (%d ; %d)  ", i, p[i].x, p[i].y);
        if (count == 10)
        {
            printf("\n");
            count = 0;
        }
    }
}

float calculatingLengthTwoPoints(Point p1, Point p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void lengthPoints(Point p[], int n)
{
    float sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        float lengthTwoPoints = calculatingLengthTwoPoints(p[i], p[i + 1]);
        printf("\nP%d -> P%d = %f", i, i + 1, lengthTwoPoints);
        sum += lengthTwoPoints;
    }
    printf("\nDo dai duong gap khuc di qua cac diem: %.3f", sum);
}

void PointFarthestFromHorizontalAxis(Point p[], int n)
{
    // điểm xa trục hoành (trục x) là điểm có độ điểm y lớn nhất
    Point result = p[0];
    int tempYOfResult, tempYOfCurrent, indexMax = 0;
    for (int i = 1; i < n; i++)
    {
        tempYOfCurrent = p[i].y;
        tempYOfResult = result.y;
        if (abs(tempYOfCurrent) > abs(tempYOfResult))
        {
            result = p[i];
            indexMax = i;
        }
    }
    printf("\nDiem xa truc hoanh nhat: P%d (%d ; %d)", indexMax, result.x, result.y);
}

void countAndPrintLineSegmentsCutVerticalAxis(Point p[], int n)
{
    int count = 0;
    printf("\nCac doan thang cat truc tung: ");
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].x < 0 && p[j].x > 0 || p[i].x > 0 && p[j].x < 0)
            {
                printf("\nP%d (%d ; %d) P%d (%d ; %d)", i, p[i].x, p[i].y, j, p[j].x, p[j].y);
                count++;
            }
        }
    }
    printf("\nSo doan thang cat truc tung: %d", count);
}