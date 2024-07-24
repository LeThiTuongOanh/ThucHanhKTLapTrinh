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
	float giaTriA = a.phan_nguyen + (float)a.tu_so / a.mau_so;
	float giaTriB = b.phan_nguyen + (float)b.tu_so / b.mau_so;
	if (giaTriA < giaTriB) return -1;
	if (giaTriA > giaTriB) return 1;
	return 0;
}

// 1. Tìm hỗn số x trong mảng b theo giải thuật Linear Search
int linearSearch(HonSo *arr, int n, HonSo x) {
	for (int i = 0; i < n; i++) {
		if (soSanhHonSo(arr[i], x) == 0) {
			return i;
		}
	}
	return -1;
}

// 2. Sắp xếp mảng sao cho các phần tử có phần nguyên chẵn lên đầu, phần tử có phần nguyên lẻ ở cuối mảng
void sapXepChanLe(HonSo *arr, int n) {
	int left = 0, right = n - 1;
	while (left < right) {
		while (left < right && arr[left].phan_nguyen % 2 == 0) left++;
		while (left < right && arr[right].phan_nguyen % 2 != 0) right--;
		if (left < right) {
			HonSo temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
}

// 3. Tìm hỗn số x theo giải thuật binary search trong mảng b đã được sắp xếp tăng/giảm
int binarySearch(HonSo *arr, int n, HonSo x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cmp = soSanhHonSo(arr[mid], x);
		if (cmp == 0) return mid;
		if (cmp < 0) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

// 4. Chia mảng b thành 2 mảng s1 và s2, với s1 chứa các phần nguyên, s2 chứa phân số
void chiaMang(HonSo *arr, int n, int *s1, float *s2) {
	for (int i = 0; i < n; i++) {
		s1[i] = arr[i].phan_nguyen;
		s2[i] = (float)arr[i].tu_so / arr[i].mau_so;
	}
}

// 5. Xóa phần tử thứ k trong mảng b
void xoaPhanTu(HonSo *arr, int *n, int k) {
	for (int i = k; i < *n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	(*n)--;
}

// 6. Thêm hỗn số x vào mảng b tại vị trí k
void themPhanTu(HonSo *arr, int *n, HonSo x, int k) {
	for (int i = *n; i > k; i--) {
		arr[i] = arr[i - 1];
	}
	arr[k] = x;
	(*n)++;
}

// 7. Tạo mảng c chứa các phần tử là phân số được đổi từ các phần tử hỗn số của mảng b
void taoMangPhanSo(HonSo *arr, int n, float *c) {
	for (int i = 0; i < n; i++) {
		c[i] = arr[i].phan_nguyen + (float)arr[i].tu_so / arr[i].mau_so;
	}
}

// 8. Tính tổng các phần tử của mảng b
float tongMang(HonSo *arr, int n) {
	float tong = 0;
	for (int i = 0; i < n; i++) {
		tong += arr[i].phan_nguyen + (float)arr[i].tu_so / arr[i].mau_so;
	}
	return tong;
}

// 9. Tìm phần tử lớn nhất/nhỏ nhất của b
HonSo timMax(HonSo *arr, int n) {
	HonSo max = arr[0];
	for (int i = 1; i < n; i++) {
		if (soSanhHonSo(arr[i], max) > 0) {
			max = arr[i];
		}
	}
	return max;
}

HonSo timMin(HonSo *arr, int n) {
	HonSo min = arr[0];
	for (int i = 1; i < n; i++) {
		if (soSanhHonSo(arr[i], min) < 0) {
			min = arr[i];
		}
	}
	return min;
}

// 10. Xuất vị trí phần tử có phần nguyên chẵn của b
void xuatViTriChan(HonSo *arr, int n) {
	printf("Vi tri phan tu co phan nguyen chan: ");
	for (int i = 0; i < n; i++) {
		if (arr[i].phan_nguyen % 2 == 0) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

// 11. Xuất vị trí của phần tử lớn nhất/nhỏ nhất của b
void xuatViTriMaxMin(HonSo *arr, int n) {
	int viTriMax = 0, viTriMin = 0;
	HonSo max = arr[0], min = arr[0];
	for (int i = 1; i < n; i++) {
		if (soSanhHonSo(arr[i], max) > 0) {
			max = arr[i];
			viTriMax = i;
		}
		if (soSanhHonSo(arr[i], min) < 0) {
			min = arr[i];
			viTriMin = i;
		}
	}
	printf("Vi tri phan tu lon nhat: %d\n", viTriMax);
	printf("Vi tri phan tu nho nhat: %d\n", viTriMin);
}

// Hàm hiển thị menu
void menu() {
	printf("0. Thoat khoi chuong trinh\n");
	printf("1. Tao ngau nhien hon so\n");
	printf("2. Xuat danh sach hon so\n");
	printf("3. Tim hon so x theo Linear Search\n");
	printf("4. Sap xep phan tu co phan nguyen chan len dau\n");
	printf("5. Tim hon so x theo Binary Search\n");
	printf("6. Chia mang b thanh s1 va s2\n");
	printf("7. Xoa phan tu thu k trong mang\n");
	printf("8. Them hon so x vao mang tai vi tri k\n");
	printf("9. Tao mang phan so tu mang hon so\n");
	printf("10. Tinh tong cac phan tu cua mang\n");
	printf("11. Tim phan tu lon nhat/nho nhat cua mang\n");
	printf("12. Xuat vi tri phan tu co phan nguyen chan\n");
	printf("13. Xuat vi tri phan tu lon nhat/nho nhat\n");
}

int main() {
	int n;
	printf("Nhap so luong hon so: ");
	scanf_s("%d", &n);
	HonSo *arr = (HonSo *)malloc(n * sizeof(HonSo));
	int chon;
	menu();
	do {
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
		case 3:
		{
				  HonSo x;
				  printf("Nhap hon so can tim (phan nguyen, tu so, mau so): ");
				  scanf_s("%d %d %d", &x.phan_nguyen, &x.tu_so, &x.mau_so);
				  int index = linearSearch(arr, n, x);
				  if (index != -1) {
					  printf("Tim thay hon so tai vi tri %d\n", index);
				  }
				  else {
					  printf("Khong tim thay hon so\n");
				  }
		}
			break;
		case 4:
			sapXepChanLe(arr, n);
			break;
		case 5:
		{
				  HonSo x;
				  printf("Nhap hon so can tim (phan nguyen, tu so, mau so): ");
				  scanf_s("%d %d %d", &x.phan_nguyen, &x.tu_so, &x.mau_so);
				  int index = binarySearch(arr, n, x);
				  if (index != -1) {
					  printf("Tim thay hon so tai vi tri %d\n", index);
				  }
				  else {
					  printf("Khong tim thay hon so\n");
				  }
		}
			break;
		case 6:
		{
				  int *s1 = (int *)malloc(n * sizeof(int));
				  float *s2 = (float *)malloc(n * sizeof(float));
				  chiaMang(arr, n, s1, s2);
				  printf("Mang s1 (phan nguyen):\n");
				  for (int i = 0; i < n; i++) {
					  printf("%d ", s1[i]);
				  }
				  printf("\nMang s2 (phan so):\n");
				  for (int i = 0; i < n; i++) {
					  printf("%.2f ", s2[i]);
				  }
				  printf("\n");
				  free(s1);
				  free(s2);
		}
			break;
		case 7:
		{
				  int k;
				  printf("Nhap vi tri can xoa: ");
				  scanf_s("%d", &k);
				  if (k >= 0 && k < n) {
					  xoaPhanTu(arr, &n, k);
				  }
				  else {
					  printf("Vi tri khong hop le\n");
				  }
		}
			break;
		case 8:
		{
				  HonSo x;
				  int k;
				  printf("Nhap hon so can them (phan nguyen, tu so, mau so): ");
				  scanf_s("%d %d %d", &x.phan_nguyen, &x.tu_so, &x.mau_so);
				  printf("Nhap vi tri can them: ");
				  scanf_s("%d", &k);
				  if (k >= 0 && k <= n) {
					  themPhanTu(arr, &n, x, k);
				  }
				  else {
					  printf("Vi tri khong hop le\n");
				  }
		}
			break;
		case 9:
		{
				  float *c = (float *)malloc(n * sizeof(float));
				  taoMangPhanSo(arr, n, c);
				  printf("Mang c (phan so):\n");
				  for (int i = 0; i < n; i++) {
					  printf("%.2f ", c[i]);
				  }
				  printf("\n");
				  free(c);
		}
			break;
		case 10:
		{
				   float tong = tongMang(arr, n);
				   printf("Tong cac phan tu cua mang: %.2f\n", tong);
		}
			break;
		case 11:
		{
				   HonSo max = timMax(arr, n);
				   HonSo min = timMin(arr, n);
				   printf("Phan tu lon nhat: %d %d/%d\n", max.phan_nguyen, max.tu_so, max.mau_so);
				   printf("Phan tu nho nhat: %d %d/%d\n", min.phan_nguyen, min.tu_so, min.mau_so);
		}
			break;
		case 12:
			xuatViTriChan(arr, n);
			break;
		case 13:
			xuatViTriMaxMin(arr, n);
			break;
		default:
			printf("Lua chon khong hop le\n");
			break;
		}
	} while (chon != 0);

	free(arr);
	return 0;
}
