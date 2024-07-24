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
void xuatCacPhanTuTrenDuongCheoChinh(int a[][50], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				printf("%4d", a[i][j]);
		}											
	}
}

void xuatDuongCheoSongSong(int a[][50], int n)
{
	printf("Duong cheo song song phia tren duong cheo chinh:\n");
	for (int k = 1; k < n-1; k++) {
		for (int i = 0; i < n - k; i++) {
			printf("%4d", a[i][i + k]);
		}
		printf("\n");
	}

	printf("Duong cheo song song phia duoi duong cheo chinh:\n");
	for (int k = 1; k < n-1; k++) {
		for (int i = k; i < n; i++) {
			printf("%4d", a[i][i - k]);
		}
		printf("\n");
	}


}
void Menu()
{
	printf("\n------Menu---------\n");
	printf("1. Tao ma tran vuong cap n>5.\n ");
	printf("2. Xuat cac phan tu tren duong cheo chinh.\n");
	printf("3. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh.\n");
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
				break;
			case 2:
				printf("Cac phan tu tren duong cheo chinh: ");
				xuatCacPhanTuTrenDuongCheoChinh(a, n);
				break;
			case 3:
				xuatDuongCheoSongSong(a, n);
				break;
			default: 
				break;
			}
		} while (choice !=0);

}