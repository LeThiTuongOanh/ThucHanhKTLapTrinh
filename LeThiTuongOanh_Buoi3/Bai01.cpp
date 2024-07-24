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

void phan_tu_lon_nhat_cot(int m, int n, int ma_tran[][50], int max_cot[50]) {
	for (int j = 0; j < n; j++) {
		max_cot[j] = ma_tran[0][j];
		for (int i = 1; i < m; i++) {
			if (ma_tran[i][j] > max_cot[j]) {
				max_cot[j] = ma_tran[i][j];
			}
		}
	}
}


void xuat_max_cot(int n, int max_cot[50]) {
	for (int j = 0; j < n; j++) {
		printf("Phan tu lon nhat cot %d la : %d\n", j, max_cot[j]);
	}
}




void xuat_duong_bien(int m, int n, int ma_tran[50][50]) {
	printf("Phan tu duong bien :\n");


	for (int j = 0; j < n; j++) {
		printf("%d ", ma_tran[0][j]);
	}
	printf("\n");


	for (int j = 0; j < n; j++) {
		printf("%d ", ma_tran[m - 1][j]);
	}
	printf("\n");


	for (int i = 1; i < m - 1; i++) {
		printf("%d ", ma_tran[i][0]);
	}
	printf("\n");

	for (int i = 1; i < m - 1; i++) {
		printf("%d ", ma_tran[i][n - 1]);
	}
	printf("\n");
}

void xuat_phan_tu_cuc_dai(int m, int n, int ma_tran[50][50]) {
	printf("Phan tu cuc dai :\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int is_max = 1;
			if (i > 0 && ma_tran[i][j] <= ma_tran[i - 1][j]) is_max = 0;
			if (i < m - 1 && ma_tran[i][j] <= ma_tran[i + 1][j]) is_max = 0;
			if (j > 0 && ma_tran[i][j] <= ma_tran[i][j - 1]) is_max = 0;
			if (j < n - 1 && ma_tran[i][j] <= ma_tran[i][j + 1]) is_max = 0;
			if (is_max) printf("%d ", ma_tran[i][j]);
		}
	}
	printf("\n");
}

void xuat_phan_tu_hoang_hau(int m, int n, int ma_tran[50][50]) {
	printf("Phan tu hoang hau:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int is_queen = 1;
			for (int k = 0; k < n; k++) {
				if (ma_tran[i][j] < ma_tran[i][k]) {
					is_queen = 0;
					break;
				}
			}
			for (int k = 0; k < m; k++) {
				if (ma_tran[i][j] < ma_tran[k][j]) {
					is_queen = 0;
					break;
				}
			}
			if (is_queen) printf("%d ", ma_tran[i][j]);
		}
	}
	printf("\n");
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
		printf("3. Xuat phan tu lon nhat tren tung cot\n");
		printf("4. Xuat duong bien trai phai tren duoi\n");
		printf("5. Xuat cac phan tu cuc dai\n");
		printf("6. Xuat phan tu hoang hau\n");
		printf("0. Thoat\n");
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
		case 3:
			phan_tu_lon_nhat_cot(m, n, ma_tran, max_cot);
			printf("Phan tu lon nhat tren cot:\n");
			xuat_max_cot(n, max_cot);
			break;

		case 4:
			xuat_duong_bien(m, n, ma_tran);
			break;
		case 5:
			xuat_phan_tu_cuc_dai(m, n, ma_tran);
			break;
		case 6:
			xuat_phan_tu_hoang_hau(m, n, ma_tran);
			break;
		case 7:
		//	xuat_phan_tu_diem_yen_ngua(m, n, ma_tran);
			break;
		case 8:
		//	xuat_dong_chi_chua_so_chan(m, n, ma_tran);
			break;
		case 9:
		//	sap_xep_tang_theo_tung_dong(m, n, ma_tran);
		//	xuat_ma_tran_sap_xep(m, n, ma_tran);
			break;
		case 0:
			printf("Thoat.\n");
			break;
		default:
			printf("Lua chon khong hop le Vui long chon lai.\n");
		}
	} while (choice <10);

	return 0;
}
