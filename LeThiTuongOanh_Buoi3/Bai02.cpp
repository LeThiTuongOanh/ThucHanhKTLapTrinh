#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void taoMaTran(int a[][50], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 101;// Số nguyên ngẫu nhiên từ 1 đến 100;
	}
}

void xuatMaTran(int a[][50], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
		
}
void Menu()
{
	printf("\n------Menu---------\n");
	printf("1. Tao ma tran vuong cap n>5. ");

}
int main()
{
	int n ;
	printf("Nhap cap cua ma tran \n");
		scanf_s("%d",&n);
		int a[50][50];
		int choice;

		do
		{
			Menu();
			printf("\nNhap lua chon cua ban: ");
			scanf_s("%d", &choice);
			switch (choice)
			{
			case 1:
				taoMaTran(a, n);
				xuatMaTran(a, n);
			case 2:

			default: 
				break;
			}
		} while (choice !=0);

}