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
int xuatMaxTamGiacTren(int a[][50], int n)
{
	int max = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	return max;
}
void sapXepZicZac(int a[][50], int n)
{
	int temp[50];
	int index = 0;

	// Chuyển ma trận thành mảng
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[index++] = a[i][j];
		}
	}

	// Sắp xếp mảng
	for (int i = 0; i < n*n - 1; i++) {
		for (int j = i + 1; j < n*n; j++) {
			if (temp[i] > temp[j]) {
				int t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}
	}

	// Chuyển mảng lại thành ma trận theo kiểu zic-zắc
	index = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; j++) {
				a[i][j] = temp[index++];
			}
		}
		else {
			for (int j = n - 1; j >= 0; j--) {
				a[i][j] = temp[index++];
			}
		}
	}
}
void sapXepDuongCheoChinh(int a[][50], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][i] > a[j][j]) {
				int temp = a[i][i];
				a[i][i] = a[j][j];
				a[j][j] = temp;
			}
		}
	}
}

void sapXepDuongCheoPhuTangDan(int a[][50], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][n - 1 - i] > a[j][n - 1 - j]) {
				int temp = a[i][n - 1 - i];
				a[i][n - 1 - i] = a[j][n - 1 - j];
				a[j][n - 1 - j] = temp;
			}
		}
	}
}
void sapXepDuongCheoPhuGiamDan(int a[][50], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][n - 1 - i] < a[j][n - 1 - j]) {
				int temp = a[i][n - 1 - i];
				a[i][n - 1 - i] = a[j][n - 1 - j];
				a[j][n - 1 - j] = temp;
			}
		}
	}
}
void sapXepDong(int n, int row[], int tangDan) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (tangDan) {
				if (row[i] > row[j]) {
					int temp = row[i];
					row[i] = row[j];
					row[j] = temp;
				}
			}
			else {
				if (row[i] < row[j]) {
					int temp = row[i];
					row[i] = row[j];
					row[j] = temp;
				}
			}
		}
	}
}

void sapXepMaTranDong( int a[][50], int n) {
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			sapXepDong(n, a[i], 0); // Sắp xếp giảm dần
		}
		else {
			sapXepDong(n, a[i], 1); // Sắp xếp tăng dần
		}
	}
}

void sapXepCot(int n, int a[][50], int col, int tangDan) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (tangDan) {
				if (a[i][col] > a[j][col]) {
					int temp = a[i][col];
					a[i][col] = a[j][col];
					a[j][col] = temp;
				}
			}
			else {
				if (a[i][col] < a[j][col]) {
					int temp = a[i][col];
					a[i][col] = a[j][col];
					a[j][col] = temp;
				}
			}
		}
	}
}

void sapXepMaTranCot(int n, int a[][50]) {
	for (int j = 0; j < n; j++) {
		if (j % 2 == 0) {
			sapXepCot(n, a, j, 1); // Sắp xếp tăng dần
		}
		else {
			sapXepCot(n, a, j, 0); // Sắp xếp giảm dần
		}
	}
}
/*void sapXepMangTangDan(int n, int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void sapXepCheoChinhVaSongSong(int a[][50], int n) {
	int size = (2 * n) - 1;
	int index, temp[50];

	for (int d = 0; d < size; d++) {
		index = 0;

		// Duyệt từ dưới lên trên cho đường chéo phụ
		if (d < n) {
			for (int i = d, j = 0; i >= 0 && j < n; i--, j++) {
				temp[index++] = a[i][j];
			}
		}
		else {
			for (int i = n - 1, j = d - n + 1; i >= 0 && j < n; i--, j++) {
				temp[index++] = a[i][j];
			}
		}

		sapXepMangTangDan(n, temp, index);

		index = 0;
		if (d < n) {
			for (int i = d, j = 0; i >= 0 && j < n; i--, j++) {
				a[i][j] = temp[index++];
			}
		}
		else {
			for (int i = n - 1, j = d - n + 1; i >= 0 && j < n; i--, j++) {
				a[i][j] = temp[index++];
			}
		}
	}
}
*/

int kiemTraDoiXungDuongCheoChinh(int n, int a[][50]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i][j] != a[j][i]) {
				return 0; // Không đối xứng
			}
		}
	}
	return 1; // Đối xứng
}

void Menu()
{
	printf("\n------Menu---------\n");
	printf("1. Tao ma tran vuong cap n>5.\n ");
	printf("2. Xuat cac phan tu tren duong cheo chinh.\n");
	printf("3. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh.\n");
	printf("4.  Tim phan tu lon nhat thuoc tam giac tren cua duong cheo chinh\n");
	printf("5. Sap xep ma tran tang dan theo kieu zic-zac\n");
	printf("6. Sap xep duong cheo chinh tang dan tu tren xuong duoi\n");
	printf("7. Sap xep duong cheo phu tang dan\n");
	printf("8. Sap xep duong cheo phu giam dan\n");
	printf("9. Sap xep cac dong le tang dan, dong chan giam dan\n");
	printf("10. Sap xep cac cot le giam dan, cot chan tang dan\n");
	printf("11. Kiem tra ma tran co doi xung qua duong cheo chinh khong\n");

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
			case 4:
				printf("Phan tu lon nhat thuoc tam giac tren cua duong cheo chinh: %d\n", xuatMaxTamGiacTren(a,n));
				break;
			case 5:
				sapXepZicZac(a, n);
				printf("Ma tran sau khi sap xep zic-zac:\n");
				xuatMaTran(a,n);
				break;
			case 6:
				sapXepDuongCheoChinh(a,n);
				printf("Ma tran sau khi sap xep duong cheo chinh:\n");
				xuatMaTran(a,n);
				break;
			case 7:
				sapXepDuongCheoPhuTangDan(a,n);
				printf("Ma tran sau khi sap xep duong cheo phu tang dan:\n");
				xuatMaTran(a,n);
				break;
			case 8:
				sapXepDuongCheoPhuGiamDan(a,n);
				printf("Ma tran sau khi sap xep duong cheo phu giam dan:\n");
				xuatMaTran(a,n);
				break;
			case 9:
				sapXepMaTranDong(a,n);
				printf("Ma tran sau khi sap xep cac dong le tang dan, dong chan giam dan:\n");
				xuatMaTran(a,n);
				break;
			case 10:
				sapXepMaTranCot(n, a);
				printf("Ma tran sau khi sap xep cac cot le giam dan, cot chan tang dan:\n");
				xuatMaTran(a,n);
				break;
			case 11:
				if (kiemTraDoiXungDuongCheoChinh(n, a)) {
					printf("Ma tran doi xung qua duong cheo chinh.\n");
				}
				else {
					printf("Ma tran khong doi xung qua duong cheo chinh.\n");
				}
				break;
			default: 
				break;
			}
		} while (choice !=0);

}