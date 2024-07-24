#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tao_ma_tran(int m, int n, int k, int ma_tran[][50]) {
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			ma_tran[i][j] = rand() % (k + 1);
		}
	}
}

void xuat_ma_tran(int m, int n, int ma_tran[][50]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", ma_tran[i][j]);
		}
		printf("\n");
	}
}


void tong_tung_dong(int m, int n, int ma_tran[][50], int tong[50]) {
	for (int i = 0; i < m; i++) {
		tong[i] = 0;
		for (int j = 0; j < n; j++) {
			tong[i] += ma_tran[i][j];
		}
	}
}

void xuat_tong_tung_dong(int m, int tong[50]) {
	for (int i = 0; i < m; i++) {
		printf("Tong dong %d: %d\n", i, tong[i]);
	}
}



int main() {
	int m,n, k = 10;
	int ma_tran[50][50];
	int tong[5];
	int max_cot[10];
	printf("Nhap so dong: ");
	scanf_s("%d", &m);
	printf("Nhap so cot: ");
	scanf_s("%d", &n);

	int choice;

	do {
		printf("\nMenu:\n");
		printf("1. Tao va xuat ma tran \n");
		printf("2. Tinh tong gia tri tren tung dong\n");
		
		printf(" Thoat\n");
		printf("Nhap lua chon cua ban ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			tao_ma_tran(m, n, k, ma_tran);
			printf("Ma tran ngau nhien:\n");
			xuat_ma_tran(m, n, ma_tran);
			break;
		case 2:
			tong_tung_dong(m, n, ma_tran, tong);
			printf("Tong gia tri tung dong:\n");
			xuat_tong_tung_dong(m, tong);
			break;
	
		case 0:
			break;
		default:
			printf("Lua chon khong hop le Vui long chon lai.\n");
		}
	} while (choice <10);

	return 0;
}
