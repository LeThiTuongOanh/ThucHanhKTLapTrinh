#include <stdio.h>
#include <stdlib.h>

// Cấu trúc hỗn số
typedef struct {
	int phan_nguyen;
	int tu_so;
	int mau_so;
} HonSo;

// Hàm tạo mảng hỗn số ngẫu nhiên
void taoMangHonSo(HonSo *arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i].phan_nguyen = rand() % 10; // phần nguyên ngẫu nhiên từ 0 đến 9
		arr[i].tu_so = rand() % 10; // tử số ngẫu nhiên từ 0 đến 9
		arr[i].mau_so = rand() % 9 + 1; // mẫu số ngẫu nhiên từ 1 đến 9 (mẫu khác 0)
	}
}

// Hàm xuất danh sách hỗn số
void xuatMangHonSo(HonSo *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %d/%d\n", arr[i].phan_nguyen, arr[i].tu_so, arr[i].mau_so);
	}
}

// Hàm so sánh hai hỗn số
int soSanhHonSo(HonSo a, HonSo b) {
	double gia_tri_a = a.phan_nguyen + (double)a.tu_so / a.mau_so;
	double gia_tri_b = b.phan_nguyen + (double)b.tu_so / b.mau_so;
	if (gia_tri_a > gia_tri_b) return 1;
	if (gia_tri_a < gia_tri_b) return -1;
	return 0;
}

// Hàm chuyển hỗn số sang phân số
void chuyenHonSoThanhPhanSo(HonSo a, int *tu_so, int *mau_so) {
	*tu_so = a.phan_nguyen * a.mau_so + a.tu_so;
	*mau_so = a.mau_so;
}

// Hàm chuyển phân số sang hỗn số
HonSo chuyenPhanSoThanhHonSo(int tu_so, int mau_so) {
	HonSo hs;
	hs.phan_nguyen = tu_so / mau_so;
	hs.tu_so = tu_so % mau_so;
	hs.mau_so = mau_so;
	return hs;
}

// Hàm tính tổng hai hỗn số
HonSo tongHonSo(HonSo a, HonSo b) {
	int tu_a, mau_a, tu_b, mau_b;
	chuyenHonSoThanhPhanSo(a, &tu_a, &mau_a);
	chuyenHonSoThanhPhanSo(b, &tu_b, &mau_b);
	int tu_kq = tu_a * mau_b + tu_b * mau_a;
	int mau_kq = mau_a * mau_b;
	return chuyenPhanSoThanhHonSo(tu_kq, mau_kq);
}

// Hàm tính hiệu hai hỗn số
HonSo hieuHonSo(HonSo a, HonSo b) {
	int tu_a, mau_a, tu_b, mau_b;
	chuyenHonSoThanhPhanSo(a, &tu_a, &mau_a);
	chuyenHonSoThanhPhanSo(b, &tu_b, &mau_b);
	int tu_kq = tu_a * mau_b - tu_b * mau_a;
	int mau_kq = mau_a * mau_b;
	return chuyenPhanSoThanhHonSo(tu_kq, mau_kq);
}

// Hàm tính tích hai hỗn số
HonSo tichHonSo(HonSo a, HonSo b) {
	int tu_a, mau_a, tu_b, mau_b;
	chuyenHonSoThanhPhanSo(a, &tu_a, &mau_a);
	chuyenHonSoThanhPhanSo(b, &tu_b, &mau_b);
	int tu_kq = tu_a * tu_b;
	int mau_kq = mau_a * mau_b;
	return chuyenPhanSoThanhHonSo(tu_kq, mau_kq);
}

// Hàm tính thương hai hỗn số
HonSo thuongHonSo(HonSo a, HonSo b) {
	int tu_a, mau_a, tu_b, mau_b;
	chuyenHonSoThanhPhanSo(a, &tu_a, &mau_a);
	chuyenHonSoThanhPhanSo(b, &tu_b, &mau_b);
	int tu_kq = tu_a * mau_b;
	int mau_kq = mau_a * tu_b;
	return chuyenPhanSoThanhHonSo(tu_kq, mau_kq);
}

// Hàm hoán đổi hai hỗn số
void hoanDoiHonSo(HonSo *a, HonSo *b) {
	HonSo temp = *a;
	*a = *b;
	*b = temp;
}

// Hàm sắp xếp mảng hỗn số tăng dần (Interchange Sort)
void sapXepTangDanInterchangeSort(HonSo *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (soSanhHonSo(arr[i], arr[j]) > 0) {
				hoanDoiHonSo(&arr[i], &arr[j]);
			}
		}
	}
}

// Hàm sắp xếp mảng hỗn số giảm dần (Interchange Sort)
void sapXepGiamDanInterchangeSort(HonSo *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (soSanhHonSo(arr[i], arr[j]) < 0) {
				hoanDoiHonSo(&arr[i], &arr[j]);
			}
		}
	}
}

// Hàm sắp xếp mảng hỗn số tăng dần (Selection Sort)
void sapXepTangDanSelectionSort(HonSo *arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (soSanhHonSo(arr[j], arr[min_idx]) < 0) {
				min_idx = j;
			}
		}
		hoanDoiHonSo(&arr[i], &arr[min_idx]);
	}
}

// Hàm sắp xếp mảng hỗn số tăng dần (Quick Sort)
int partition(HonSo *arr, int low, int high) {
	HonSo pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (soSanhHonSo(arr[j], pivot) < 0) {
			i++;
			hoanDoiHonSo(&arr[i], &arr[j]);
		}
	}
	hoanDoiHonSo(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quickSort(HonSo *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Hàm hiển thị menu
void menu() {
	printf("\n");
	printf("------------MeNu----------\n");
	printf("0. Thoat khoi chuong trinh\n");
	printf("1. Tao ngau nhien hon so\n");
	printf("2. Xuat danh sach hon so\n");
	printf("3. So sanh 2 hon so\n");
	printf("4. Chuyen hon so thanh phan so\n");
	printf("5. Chuyen phan so thanh hon so\n");
	printf("6. Tinh tong, hieu, tich, thuong 2 hon so\n");
	printf("7. Sap xep mang tang dan (Interchange Sort)\n");
	printf("8. Sap xep mang giam dan (Interchange Sort)\n");
	printf("9. Sap xep mang tang dan (Selection Sort)\n");
	printf("10. Sap xep mang tang dan (Quick Sort)\n");
}

int main() {
	int n;
	printf("Nhap so luong hon so: ");
	scanf_s("%d", &n);
	HonSo *arr = (HonSo *)malloc(n * sizeof(HonSo));
	int chon;

	
	do {
		menu();
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &chon);
		switch (chon) {
		case 0:
			break;
		case 1:
			taoMangHonSo(arr, n);
			break;
		case 2:
			printf("Danh sach hon so:\n");
			xuatMangHonSo(arr, n);
			break;
		case 3: {
					HonSo a, b;
					printf("Nhap hon so thu nhat (phan nguyen, tu so, mau so): ");
					scanf_s("%d %d %d", &a.phan_nguyen, &a.tu_so, &a.mau_so);
					printf("Nhap hon so thu hai (phan nguyen, tu so, mau so): ");
					scanf_s("%d %d %d", &b.phan_nguyen, &b.tu_so, &b.mau_so);
					int result = soSanhHonSo(a, b);
					if (result == 1) {
						printf("Hon so thu nhat lon hon hon so thu hai\n");
					}
					else if (result == -1) {
						printf("Hon so thu nhat nho hon hon so thu hai\n");
					}
					else {
						printf("Hai hon so bang nhau\n");
					}
					break;
		}
		case 4: {
					HonSo a;
					int tu, mau;
					printf("Nhap hon so (phan nguyen, tu so, mau so): ");
					scanf_s("%d %d %d", &a.phan_nguyen, &a.tu_so, &a.mau_so);
					chuyenHonSoThanhPhanSo(a, &tu, &mau);
					printf("Phan so tuong ung: %d/%d\n", tu, mau);
					break;
		}
		case 5: {
					int tu, mau;
					printf("Nhap phan so (tu so, mau so): ");
					scanf_s("%d %d", &tu, &mau);
					HonSo hs = chuyenPhanSoThanhHonSo(tu, mau);
					printf("Hon so tuong ung: %d %d/%d\n", hs.phan_nguyen, hs.tu_so, hs.mau_so);
					break;
		}
		case 6: {
					HonSo a, b;
					printf("Nhap hon so thu nhat (phan nguyen, tu so, mau so): ");
					scanf_s("%d %d %d", &a.phan_nguyen, &a.tu_so, &a.mau_so);
					printf("Nhap hon so thu hai (phan nguyen, tu so, mau so): ");
					scanf_s("%d %d %d", &b.phan_nguyen, &b.tu_so, &b.mau_so);
					HonSo tong = tongHonSo(a, b);
					HonSo hieu = hieuHonSo(a, b);
					HonSo tich = tichHonSo(a, b);
					HonSo thuong = thuongHonSo(a, b);
					printf("Tong: %d %d/%d\n", tong.phan_nguyen, tong.tu_so, tong.mau_so);
					printf("Hieu: %d %d/%d\n", hieu.phan_nguyen, hieu.tu_so, hieu.mau_so);
					printf("Tich: %d %d/%d\n", tich.phan_nguyen, tich.tu_so, tich.mau_so);
					printf("Thuong: %d %d/%d\n", thuong.phan_nguyen, thuong.tu_so, thuong.mau_so);
					break;
		}
		case 7:
			sapXepTangDanInterchangeSort(arr, n);
			printf("Danh sach sau khi sap xep tang dan (Interchange Sort):\n");
			xuatMangHonSo(arr, n);
			break;
		case 8:
			sapXepGiamDanInterchangeSort(arr, n);
			printf("Danh sach sau khi sap xep giam dan (Interchange Sort):\n");
			xuatMangHonSo(arr, n);
			break;
		case 9:
			sapXepTangDanSelectionSort(arr, n);
			printf("Danh sach sau khi sap xep tang dan (Selection Sort):\n");
			xuatMangHonSo(arr, n);
			break;
		case 10:
			quickSort(arr, 0, n - 1);
			printf("Danh sach sau khi sap xep tang dan (Quick Sort):\n");
			xuatMangHonSo(arr, n);
			break;
		default:
			printf("Lua chon khong hop le\n");
			break;
		}
	} while (chon != 0);

	free(arr);
	return 0;
}
