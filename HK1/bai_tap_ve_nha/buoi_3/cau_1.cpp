#include <stdio.h>
int main()
{
	// doc so <=9999
	// a = 1234
	int a;
	printf("Nhap vao so can doc: ");
	scanf("%d", &a);
	if (a >= 10000)
		printf("Chi doc cac so <=9999");
	else
	{
		int donvi, chuc, tram, nghin;
		donvi = a % 10;
		chuc = (a / 10) % 10;
		tram = (a / 100) % 10;
		nghin = a / 1000;
		switch (nghin)
		{
		case 1:
			printf("Mot nghin ");
			break;
		case 2:
			printf("Hai nghin ");
			break;
		case 3:
			printf("Ba nghin ");
			break;
		case 4:
			printf("Bon nghin ");
			break;
		case 5:
			printf("Nam nghin ");
			break;
		case 6:
			printf("Sau nghin ");
			break;
		case 7:
			printf("Bay nghin ");
			break;
		case 8:
			printf("Tam nghin ");
			break;
		case 9:
			printf("Chin nghin ");
			break;
		}
		switch (tram)
		{
		case 0:
			if (chuc != 0)
				printf("khong tram ");
			break;
		case 1:
			printf("Mot tram ");
			break;
		case 2:
			printf("Hai tram ");
			break;
		case 3:
			printf("Ba tram ");
			break;
		case 4:
			printf("Bon tram ");
			break;
		case 5:
			printf("Nam tram ");
			break;
		case 6:
			printf("Sau tram ");
			break;
		case 7:
			printf("Bay tram ");
			break;
		case 8:
			printf("Tam tram ");
			break;
		case 9:
			printf("Chin tram ");
			break;
		}
		switch (chuc)
		{
		case 0:
			if (donvi == 0)
				printf("");
			else
				printf("le ");
			break;
		case 1:
			printf(" muoi ");
			break;
		case 2:
			printf("hai muoi ");
			break;
		case 3:
			printf("ba muoi ");
			break;
		case 4:
			printf("bon muoi ");
			break;
		case 5:
			printf("nam muoi ");
			break;
		case 6:
			printf("sau muoi ");
			break;
		case 7:
			printf("bay muoi ");
			break;
		case 8:
			printf("tam muoi ");
			break;
		case 9:
			printf("chin muoi ");
			break;
		}
		switch (donvi)
		{
		case 1:
			printf("Mot");
			break;
		case 2:
			printf("Hai");
			break;
		case 3:
			printf("ba");
			break;
		case 4:
			printf("bon");
			break;
		case 5:
			printf("nam");
			break;
		case 6:
			printf("sau");
			break;
		case 7:
			printf("bay");
			break;
		case 8:
			printf("tam");
			break;
		case 9:
			printf("chin");
			break;
		}
	}
}