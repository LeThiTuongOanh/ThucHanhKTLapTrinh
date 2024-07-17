#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Tạo mảng ngẫu nhiên
void taoMangNgauNhien(int *mang, int n, int tu, int den) {
	for (int i = 0; i < n; i++) {
		mang[i] = tu + rand() % (den - tu + 1);
	}
}

// 2. Tạo mảng chứa toàn số chẵn
void taoMangSoChan(int *mang, int n, int tu, int den) {
	for (int i = 0; i < n; i++) {
		mang[i] = tu + rand() % (den - tu + 1);
		if (mang[i] % 2 != 0) {
			mang[i]++;
		}
	}
}

// 3. Tìm kiếm tuyến tính
int timKiemTuyenTinh(int *mang, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (mang[i] == x) {
			return i;
		}
	}
	return -1;
}

// 4. Sắp xếp Interchange Sort
void sapXepInterchange(int *mang, int n, int tang_dan) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (tang_dan ? mang[i] > mang[j] : mang[i] < mang[j]) {
				int temp = mang[i];
				mang[i] = mang[j];
				mang[j] = temp;
			}
		}
	}
}

// 5. Tìm kiếm nhị phân
int timKiemNhiPhan(int *mang, int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (mang[mid] == x) {
			return mid;
		}
		if (mang[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

// 6. Sắp xếp Selection Sort
void sapXepSelection(int *mang, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (mang[j] < mang[min]) {
				min = j;
			}
		}
		int temp = mang[min];
		mang[min] = mang[i];
		mang[i] = temp;
	}
}

// 7. Sắp xếp Quick Sort
void sapXepQuick(int *mang, int low, int high) {
	if (low < high) {
		int pivot = mang[high];
		int i = (low - 1);

		for (int j = low; j < high; j++) {
			if (mang[j] < pivot) {
				i++;
				int temp = mang[i];
				mang[i] = mang[j];
				mang[j] = temp;
			}
		}
		int temp = mang[i + 1];
		mang[i + 1] = mang[high];
		mang[high] = temp;

		int pi = i + 1;
		sapXepQuick(mang, low, pi - 1);
		sapXepQuick(mang, pi + 1, high);
	}
}

// Hàm in mảng
void inMang(int *mang, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", mang[i]);
	}
	printf("\n");
}

int main() {
	int n;
	int *mang = NULL;
	int tu = 0, den = 100;
	int luaChon, x, viTri;

	// Khởi tạo số ngẫu nhiên
	srand(time(NULL));

	// Tạo mảng ngẫu nhiên
	do {
		printf("Nhap so phan tu cua mang (>= 15): ");
		scanf_s("%d", &n);
	} while (n < 15);

	// Cấp phát bộ nhớ cho mảng
	mang = (int *)malloc(n * sizeof(int));
	if (mang == NULL) {
		printf("Khong the cap phat bo nho!\n");
		return 1; // Kết thúc chương trình nếu không thể cấp phát bộ nhớ
	}

	do {
		printf("\n======= MENU =======\n");
		printf("1. Tao mang ngau nhien\n");
		printf("2. Tao mang chua toan so chan\n");
		printf("3. Tim kiem x trong mang \n");
		printf("4. Sap xep mang tang dan \n");
		printf("5. Sap xep mang giam dan \n");
		printf("6. Tim kiem x trong mang \n");
		printf("7. Sap xep mang tang dan \n");
		printf("8. Sap xep mang tang dan \n");
		printf("0. Thoat\n");
		printf("Chon: ");
		scanf_s("%d", &luaChon);

		switch (luaChon) {
		case 1:
			taoMangNgauNhien(mang, n, tu, den);
			printf("Mang ngau nhien: ");
			inMang(mang, n);
			break;
		case 2:
			taoMangSoChan(mang, n, tu, den);
			printf("Mang chua toan so chan: ");
			inMang(mang, n);
			break;
		case 3:
			printf("Nhap gia tri can tim kiem: ");
			scanf_s("%d", &x);
			viTri = timKiemTuyenTinh(mang, n, x);
			if (viTri != -1) {
				printf("Gia tri %d xuat hien tai vi tri %d\n", x, viTri);
			}
			else {
				printf("Gia tri %d khong xuat hien trong mang\n", x);
			}
			break;
		case 4:
			sapXepInterchange(mang, n, 1);
			printf("Mang sap xep tang dan bang Interchange Sort: ");
			inMang(mang, n);
			break;
		case 5:
			sapXepInterchange(mang, n, 0);
			printf("Mang sap xep giam dan bang Interchange Sort: ");
			inMang(mang, n);
			break;
		case 6:
			sapXepInterchange(mang, n, 1); // Đảm bảo mảng được sắp xếp tăng dần
			printf("Nhap gia tri can tim kiem bang Binary Search: ");
			scanf_s("%d", &x);
			viTri = timKiemNhiPhan(mang, n, x);
			if (viTri != -1) {
				printf("Gia tri %d xuat hien tai vi tri %d (Binary Search)\n", x, viTri);
			}
			else {
				printf("Gia tri %d khong xuat hien trong mang (Binary Search)\n", x);
			}
			break;
		case 7:
			sapXepSelection(mang, n);
			printf("Mang sap xep tang dan bang Selection Sort: ");
			inMang(mang, n);
			break;
		case 8:
			sapXepQuick(mang, 0, n - 1);
			printf("Mang sap xep tang dan bang Quick Sort: ");
			inMang(mang, n);
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le! Vui long chon lai.\n");
			break;
		}
	} while (luaChon != 0);

	// Giải phóng bộ nhớ
	free(mang);

	return 0;
}
