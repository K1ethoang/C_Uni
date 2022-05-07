// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62

#include <stdio.h>
#include <math.h>

float lengthBetweenTwoPoints(float x1, float y1, float x2, float y2);
void printLine(int n);

int main()
{
    int n, Point1, Point2, count1 = 0, count2 = 0;
    float x[100], y[100], zigzagLength = 0, maxLength = 0;
    do
    {
        printf("\nNhap so diem M can co: ");
        scanf("%d", &n);
    } while (n < 1 || n > 100);

    printf("\n\t\tNHAP DIEM M (x, y)\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap M%d (x%d, y%d): ", i + 1, i + 1, i + 1);
        scanf("%f%f", &x[i], &y[i]);
    }

    printf("\n\t\tDIEM DA NHAP\n");
    for (int i = 0; i < n; i++)
    {
        printf("M%d (%.1f, %.1f)\n", i + 1, x[i], y[i]);
    }

    printLine(60);
    // y1: tính độ dài đường gấp khúc
    for (int i = 0; i < n - 1; i++) // i chạy từ [1, n - 1]
    {
        printf("\nM%dM%d = %.2f", i + 1, i + 2, lengthBetweenTwoPoints(x[i], y[i], x[i + 1], y[i + 1]));
        zigzagLength += lengthBetweenTwoPoints(x[i], y[i], x[i + 1], y[i + 1]);
    }
    printf("\n\nDo dai duong gap khuc: %.2f", zigzagLength);

    printLine(60);
    // y2: tìm đoạn có độ dài lớn nhất
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf("\nM%dM%d = %.2f", i + 1, j + 1, lengthBetweenTwoPoints(x[i], y[i], x[j], y[j]));
            if (maxLength < lengthBetweenTwoPoints(x[i], y[i], x[j], y[j]))
            {
                Point1 = i + 1;
                Point2 = j + 1;
                maxLength = lengthBetweenTwoPoints(x[i], y[i], x[j], y[j]);
            }
        }
    }
    printf("\n\nDoan M%dM%d co do dai lon nhat: %.2f", Point1, Point2, maxLength);

    printLine(60);
    // y3: số đoạn cắt trục Oy <=> 1 trong 2 điểm có điểm mà x < 0
    for (int i = 0; i < n; i++)
    {
        if (x[i] < 0)
            count1++; // số điểm nằm bên trái trục Oy
    }
    if (count1 != 0)
        printf("\n\nSo doan cat truc Oy: %d", count1 * (n - count1)); // bằng số điểm bên trái Oy * số điểm bên phải Oy
    else
        printf("\n\nKhong co doan nao cat truc Oy");

    printLine(60);
    // y4: số điểm thuộc góc phần tư thứ nhất <=> x > 0 và y > 0
    for (int i = 0; i < n; i++)
    {
        if (x[i] > 0 && y[i] > 0)
            count2++;
    }
    if (count2 != 0)
        printf("\n\nSo diem thuoc goc phan tu thu I: %d", count2);
    else
        printf("\n\nKhong co diem nao thuoc goc phan tu thu I");
    return 0;
}

// độ dài giữa 2 điểm
float lengthBetweenTwoPoints(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void printLine(int n)
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c", '-');
    }
}