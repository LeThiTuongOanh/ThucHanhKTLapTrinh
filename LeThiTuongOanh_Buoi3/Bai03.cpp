#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void taoMaTran(int m, int n, int k, int maTran[][MAX]) {
	srand(time(0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			maTran[i][j] = rand() % (k + 1);
		}
	}
}

void xuatMaTran(int m, int n, int maTran[][MAX]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", maTran[i][j]);
		}
		printf("\n");
	}
}

void xuatCacCotSoLe(int m, int n, int maTran[][MAX]) {
	printf("Cac cot chi chua so le:\n");
	for (int j = 0; j < n; j++) {
		int soLe = 1;
		for (int i = 0; i < m; i++) {
			if (maTran[i][j] % 2 == 0) {
				soLe = 0;
				break;
			}
		}
		if (soLe) {
			for (int i = 0; i < m; i++) {
				printf("%d ", maTran[i][j]);
			}
			printf("\n");
		}
	}
}

int timPhanTuMaxTrenBien(int m, int n, int maTran[][MAX]) {
	int max = maTran[0][0];
	for (int i = 0; i < m; i++) {
		if (maTran[i][0] > max) max = maTran[i][0];
		if (maTran[i][n - 1] > max) max = maTran[i][n - 1];
	}
	for (int j = 0; j < n; j++) {
		if (maTran[0][j] > max) max = maTran[0][j];
		if (maTran[m - 1][j] > max) max = maTran[m - 1][j];
	}
	return max;
}

int demChuSo2(int x) {
	int count = 0;
	while (x > 0) {
		if (x % 10 == 2) count++;
		x /= 10;
	}
	return count;
}

int demPhanTuCoChuSo2(int m, int n, int maTran[][MAX]) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (demChuSo2(maTran[i][j]) > 0) count++;
		}
	}
	return count;
}

void lietKeChiSoDongToanChan(int m, int n, int maTran[][MAX]) {
	printf("Chi so cac dong chua toan gia tri chan:\n");
	for (int i = 0; i < m; i++) {
		int toanChan = 1;
		for (int j = 0; j < n; j++) {
			if (maTran[i][j] % 2 != 0) {
				toanChan = 0;
				break;
			}
		}
		if (toanChan) printf("%d ", i);
	}
	printf("\n");
}

//cau 4

void xuatCacPhanTuCucTieu(int m, int n, int matran[][MAX])
{
	printf("Cac phan tu cuc tieu:\n ");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int laCucTieu = 1;
			int giaTri = matran[i][j];

			if (i>0 && matran[i - 1][j] <= giaTri) laCucTieu = 0;
			if (i < m - 1 && matran[i + 1][j] <= giaTri) laCucTieu = 0;
			if (j>0 && matran[i][j - 1] <= giaTri) laCucTieu = 0;
			if (j < n - 1 && matran[i][j + 1] <= giaTri) laCucTieu = 0;

			if (laCucTieu) printf("%d ", giaTri);
		}
	}
	
}

void hoanViHaiCot(int m, int n, int matran[][MAX], int cot1, int cot2)
{
	for (int i = 0; i < m; i++)
	{
		int temp = matran[i][cot1];
		matran[i][cot1] = matran[i][cot2];
		matran[i][cot2] = temp;
	}
	printf("Ma tran sau khi hoan vi cot %d va cot %d:\n", cot1, cot2);
	xuatMaTran(m, n, matran);
}
void hoanViHaiDong(int m, int n, int matran[][MAX], int dong1, int dong2)
{
	for (int j = 0; j < n; j++) {
		int temp = matran[dong1][j];
		matran[dong1][j] = matran[dong2][j];
		matran[dong2][j] = temp;
	}
	printf("Ma tran sau khi hoan vi dong %d va dong %d:\n", dong1, dong2);
	xuatMaTran(m, n, matran);
}
int main() {
	int m, n, k = 100;
	int maTran[MAX][MAX];
	printf("Nhap so dong: ");
	scanf_s("%d", &m);
	printf("Nhap so cot: ");
	scanf_s("%d", &n);

	taoMaTran(m, n, k, maTran);
	printf("Ma tran ngau nhien:\n");
	xuatMaTran(m, n, maTran);

	int choice;

	do {
		printf("\nMenu:\n");
		printf("1. Xuat cac cot chi chua so le\n");
		printf("2. Tim phan tu lon nhat tren bien cua ma tran\n");
		printf("3. Dem so phan tu co chu so 2 trong cac chu so\n");
		printf("4. Xuat cac phan tu cuc tieu\n");
		printf("5. Sap xep dong tang le, giam chan\n");
		printf("6. Sap xep cot tang chan, giam le\n");
		printf("7. Kiem tra cac gia tri trong ma tran co giam dan theo cot va dong\n");
		printf("8. Liet ke chi so dong chua toan gia tri chan\n");
		printf("9. Liet ke cac dong chua gia tri giam dan\n");
		printf("10. Tim gia tri xuat hien nhieu nhat trong ma tran\n");
		printf("11. Tim cac chu so xuat hien nhieu nhat trong ma tran\n");
		printf("12. Liet ke cac cot co tong nho nhat trong ma tran\n");
		printf("13. Hoan vi hai cot trong ma tran\n");
		printf("14. Hoan vi hai dong trong ma tran\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			xuatCacCotSoLe(m, n, maTran);
			break;
		case 2:
			printf("Phan tu lon nhat tren bien: %d\n", timPhanTuMaxTrenBien(m, n, maTran));
			break;
		case 3:
			printf("So phan tu co chu so 2: %d\n", demPhanTuCoChuSo2(m, n, maTran));
			break;
		case 4:
			xuatCacPhanTuCucTieu(m, n, maTran);
			break;
		case 8:
			lietKeChiSoDongToanChan(m, n, maTran);
			break;
		case 13:
			int cot1, cot2;
			printf("Nhap 2 cot can hoan vi: ");
			scanf_s("%d%d", &cot1, &cot2);
			hoanViHaiCot(m, n, maTran, cot1, cot2);
			break;
		case 14:
			int dong1, dong2;
			printf("Nhap 2 cot can hoan vi: ");
			scanf_s("%d%d", &dong1, &dong2);
			hoanViHaiDong(m, n, maTran, dong1, dong2);
			break;
		case 0:
			printf("Thoat.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
		}
	} while (choice != 0);

	return 0;
}