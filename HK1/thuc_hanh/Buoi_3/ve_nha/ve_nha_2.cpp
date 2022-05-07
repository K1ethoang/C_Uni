// Ho Ten: Hoang Gia Kiet
// MSSV: 6251071049
// Lop: IT-62
#include <stdio.h>
#include <string.h>

struct FootballTeam
{
    char teamName[30];
    int numberOfFootballer;
    int score;
};

void inputOneFootballTeam(FootballTeam &team);                           // nhập 1 đội bóng
void inputListOfFootballTeam(FootballTeam team[], int n);                // nhập danh sách đội bóng
void outputOneFootballTeam(FootballTeam team);                           // xuất 1 đội bóng
void outputListOfFootballTeam(FootballTeam team[], int n);               // xuất danh sách đội bóng
void sortScoreInDecendingOrder(FootballTeam team[], int n);              // sắp xếp giảm dần theo điểm
void sortNumberOfFootballerInDecendingOrder(FootballTeam team[], int n); // sắp xếp giảm dần theo số lượng cầu thủ
void sortNameInAscendingOrder(FootballTeam team[], int n);               // sắp xếp tăng dần theo tên đội
void swap(FootballTeam &team1, FootballTeam &team2);                     // hoán vị
void printLine(int n);

int main()
{
    int n;
    FootballTeam team[100];
    do
    {
        printf("\nNhap so doi bong (0 < n <= 100): ");
        scanf("%d", &n);
        if (n < 1 || n > 100)
            printf("\n\t(!) Nhap lai (!)\n");
    } while (n < 1 || n > 100);

    printf("\n\n\t\t\tNHAP DANH SACH DOI BONG\n");
    inputListOfFootballTeam(team, n);

    printLine(100);
    printf("\n\n\t\t\tDANH SACH DOI BONG VUA NHAP\n");
    outputListOfFootballTeam(team, n);

    printLine(100);
    printf("\n\n\t\t\t3 DOI CO DIEM CAO NHAT\n");
    sortScoreInDecendingOrder(team, n);
    outputListOfFootballTeam(team, 3);

    printLine(100);
    printf("\n\n\t\t\t3 DOI CO SO LUONG CAU THU NHIEU NHAT\n");
    sortNumberOfFootballerInDecendingOrder(team, n);
    outputListOfFootballTeam(team, 3);

    printLine(100);
    printf("\n\n\t\t\tDANH SACH DOI BONG THEO THU TU ABC\n");
    sortNameInAscendingOrder(team, n);
    outputListOfFootballTeam(team, n);

    return 0;
}
void inputOneFootballTeam(FootballTeam &team)
{
    fflush(stdin);
    printf("\n(?) Nhap ten doi bong: ");
    gets(team.teamName);
    printf("\n(?) Nhap so luong cau thu: ");
    scanf("%d", &team.numberOfFootballer);
    printf("\n(?) Nhap diem: ");
    scanf("%d", &team.score);
}

void inputListOfFootballTeam(FootballTeam team[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\t\tDoi bong [%d]\n", i + 1);
        inputOneFootballTeam(team[i]);
    }
}

void outputOneFootballTeam(FootballTeam team)
{
    printf("\n++++++++++++++++++++++++++++++++++++");
    printf("\n+     Ten doi: %s", team.teamName);
    printf("\n+     So luong: %d", team.numberOfFootballer);
    printf("\n+     Diem : %d", team.score);
    printf("\n++++++++++++++++++++++++++++++++++++");
}

void outputListOfFootballTeam(FootballTeam team[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\n\t\tDoi bong [%d]", i + 1);
        outputOneFootballTeam(team[i]);
    }
}

void swap(FootballTeam &team1, FootballTeam &team2)
{
    FootballTeam temp = team1;
    team1 = team2;
    team2 = temp;
}

void sortScoreInDecendingOrder(FootballTeam team[], int n)
{
    // selection sort
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (team[maxIndex].score < team[j].score)
                maxIndex = j;
        }
        if (maxIndex != i)
            swap(team[i], team[maxIndex]);
    }
}

void sortNumberOfFootballerInDecendingOrder(FootballTeam team[], int n)
{
    // selection sort
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (team[maxIndex].numberOfFootballer < team[j].numberOfFootballer)
                maxIndex = j;
        }
        if (maxIndex != i)
            swap(team[i], team[maxIndex]);
    }
}

void sortNameInAscendingOrder(FootballTeam team[], int n)
{
    // bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(team[j].teamName, team[j + 1].teamName) > 0)
                swap(team[j], team[j + 1]);
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
