#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#include <stdbool.h>
// 1. Tạo mảng ngẫu nhiên
void taoMangNgauNhien(int *mang, int n, int tu, int den) {
	for (int i = 0; i < n; i++) {
		mang[i] = tu + rand() % (den - tu + 1);
	}
}


// Hàm in mảng
void inMang(int *mang, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", mang[i]);
	}
	printf("\n");
}

bool kiemTraSoNguyenTo(int num) {
	if (num < 2) {
		return false;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void Cau1(int *mang, int n, int x)
{
	printf("Phan tu so nguyen to: ");
	for (int i = 0; i < n; i++)
	{
		if (kiemTraSoNguyenTo(mang[i]))
		{
			if (mang[i]<x)
			printf("%d ", mang[i]);
		}

	}
}

void Cau2(int *mang, int n)
{
	for (int i = 0; i < n; i++)
	{
		int x = mang[i];
		x = x / 10;
		if (x % 2 != 0)
			printf("%d ", x);
	}
}

int timSoLanXuatHien(int arr[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			count++;
		}
	}
	return count;
}

void Cau3(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int x= timSoLanXuatHien(arr, n, arr[i]);
		printf("So lan xuat hien cua %d la %d\n",arr[i], x);
	}
}
void sapXepMangChanTangLeGiam(int *mang, int n)
{
	int *chan = (int *)malloc(n*sizeof(int));
	int *le = (int *)malloc(n*sizeof(int));
	int soLuongChan = 0, soLuongLe = 0;

	//Tach so chan va le
	for (int i = 0; i < n; i++)
	{
		if (mang[i] % 2 == 0)
		{
			chan[soLuongChan++] = mang[i];
		}
		else {
			le[soLuongLe++] = mang[i];
		}
	}

	//Sap xep so chan tang dan
	for (int i = 0; i < soLuongChan - 1; i++)
	{
		for (int j = i + 1; j < soLuongChan; j++)
		{
			if (chan[i]>chan[j])
			{
				int temp = chan[i];
				chan[i] = chan[j];
				chan[j] = temp;
			}
		}
	}

	// sap xep so le giam dan
	for (int i = 0; i < soLuongLe - 1; i++)
	{
		for (int j = i + 1; j < soLuongLe; j++)
		{
			if (le[i] < le[j])
			{
				int temp = le[i];
				le[i] = le[j];
				le[j] = temp;
			}
		}
	}

	//Gop lai vao mang goc


	//Gop vao va thay đổi vị trị
	/*int index = 0;
	for (int i = 0; i < soLuongChan; i++) {
		mang[index++] = chan[i];
	}
	for (int i = 0; i < soLuongLe; i++) {
		mang[index++] = le[i];
	}
	*/

	//Gop vao mang nhung giu nguyen vi tri
	int indexChan = 0, indexLe = 0;
	for (int i = 0; i < n; i++) {
		if (mang[i] % 2 == 0) {
			mang[i] = chan[indexChan++];
		}
		else {
			mang[i] = le[indexLe++];
		}
	}


	// Giải phóng bộ nhớ
	free(chan);
	free(le);


}
void Cau4(int *mang, int n) {
	sapXepMangChanTangLeGiam(mang, n);
	printf("Mang sau khi sap xep: ");
	inMang(mang, n);
}

void timDayConGiamDaiNhat(int *a, int n) {
	int *lds = (int *)malloc(n * sizeof(int));
	int *parent = (int *)malloc(n * sizeof(int));
	int maxLength = 0;
	int endIndex = 0;

	// Khởi tạo tất cả các giá trị trong lds bằng 1 và parent bằng -1
	for (int i = 0; i < n; i++) {
		lds[i] = 1;
		parent[i] = -1;
	}

	// Tính giá trị lds và cập nhật parent
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j] && lds[i] < lds[j] + 1) {
				lds[i] = lds[j] + 1;
				parent[i] = j;
			}
		}
	}

	// Tìm giá trị lớn nhất trong lds và chỉ số kết thúc của dãy con
	for (int i = 0; i < n; i++) {
		if (maxLength < lds[i]) {
			maxLength = lds[i];
			endIndex = i;
		}
	}

	// In độ dài của dãy con giảm dài nhất
	printf("Do dai day con giam dai nhat la: %d\n", maxLength);

	// In dãy con giảm dài nhất
	int *sequence = (int *)malloc(maxLength * sizeof(int));
	int index = maxLength - 1;
	while (endIndex != -1) {
		sequence[index--] = a[endIndex];
		endIndex = parent[endIndex];
	}

	printf("Day con giam dai nhat la: ");
	for (int i = 0; i < maxLength; i++) {
		printf("%d ", sequence[i]);
	}
	printf("\n");

	// Giải phóng bộ nhớ
	free(lds);
	free(parent);
	free(sequence);
}


void Cau5(int *mang, int n) {
	timDayConGiamDaiNhat(mang, n);
}

// Hàm tìm số nhỏ thứ hai trong mảng
int timSoNhoThuHai(int *mang, int n) {
	if (n < 2) {
		printf("Mang khong co du 2 phan tu!\n");
		return INT_MAX; // Trả về giá trị lớn nhất của kiểu int nếu mảng không đủ 2 phần tử
	}

	int nhat = INT_MAX, nhi = INT_MAX;

	for (int i = 0; i < n; i++) {
		if (mang[i] < nhat) {
			nhi = nhat;
			nhat = mang[i];
		}
		else if (mang[i] < nhi && mang[i] != nhat) {
			nhi = mang[i];
		}
	}

	if (nhi == INT_MAX) {
		printf("Khong ton tai so nho thu hai!\n");
		return INT_MAX;
	}

	return nhi;
}

void Cau6(int *mang, int n) {
	int soNhoThuHai = timSoNhoThuHai(mang, n);
	if (soNhoThuHai != INT_MAX) {
		printf("So nho thu hai trong mang la: %d\n", soNhoThuHai);
	}
}

// Hàm kiểm tra xem một số có chứa tất cả các chữ số của x không
bool chuaChuSo(int num, int x) {
	bool foundFirstDigit = false, foundSecondDigit = false;
	int firstDigit = x / 10;
	int secondDigit = x % 10;

	while (num > 0) {
		int digit = num % 10;
		if (digit == firstDigit) foundFirstDigit = true;
		if (digit == secondDigit) foundSecondDigit = true;
		num /= 10;
	}

	return foundFirstDigit && foundSecondDigit;
}

// Hàm tìm các phần tử chứa các chữ số của x
void timPhanTuChuaChuSoX(int *mang, int n, int x) {
	printf("Cac phan tu co chua chu so cua %d: ", x);
	for (int i = 0; i < n; i++) {
		if (chuaChuSo(mang[i], x)) {
			printf("%d ", mang[i]);
		}
	}
	printf("\n");
}

void Cau7(int *mang, int n, int x) {
	timPhanTuChuaChuSoX(mang, n, x);
}

// Hàm sắp xếp các phần tử chẵn tăng dần, lẻ giữ nguyên vị trí
void sapXepChanTangDanLeGiuNguyen(int *mang, int n) {
	int *chan = (int *)malloc(n * sizeof(int));
	int chanCount = 0;

	for (int i = 0; i < n; i++) {
		if (mang[i] % 2 == 0) {
			chan[chanCount++] = mang[i];
		}
	}

	// Sắp xếp mảng chẵn
	for (int i = 0; i < chanCount - 1; i++) {
		for (int j = i + 1; j < chanCount; j++) {
			if (chan[i] > chan[j]) {
				int temp = chan[i];
				chan[i] = chan[j];
				chan[j] = temp;
			}
		}
	}

	// Đặt lại các phần tử chẵn vào vị trí cũ
	chanCount = 0;
	for (int i = 0; i < n; i++) {
		if (mang[i] % 2 == 0) {
			mang[i] = chan[chanCount++];
		}
	}

	free(chan);
}

void Cau8(int *mang, int n) {
	sapXepChanTangDanLeGiuNguyen(mang, n);
}

// Hàm sắp xếp số lẻ ở đầu mảng, số chẵn ở cuối mảng
void sapXepLeDauChanCuoi(int *mang, int n) {
	int left = 0, right = n - 1;

	while (left < right) {
		while (left < right && mang[left] % 2 != 0) {
			left++;
		}
		while (left < right && mang[right] % 2 == 0) {
			right--;
		}
		if (left < right) {
			int temp = mang[left];
			mang[left] = mang[right];
			mang[right] = temp;
			left++;
			right--;
		}
	}
}

void Cau9(int *mang, int n) {
	sapXepLeDauChanCuoi(mang, n);
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
		printf("2. Cau1: Liet ke so nguyen to nho hon n \n");
		printf("3. Cau2: Tinh tong cac phan tu co chu so dau la chu so le\n");
		printf("4. Cau3: Liet ke so nhan xuat hien cua phan tu trong mang \n");
		printf("5. Cau4: Sap xep mang co so chan tang dan , so le giam dan\n");
		printf("6. Cau5: Tim day con giam dai nhat trong mang \n");
		printf("7. Cau6: Tim so nho thu 2 trong mang \n");
		printf("8. Cau7: Tim trong day phan tu co chua x( x gom 2 chu so) \n");
		printf("9. Cau8: Sap xep ptu chan tang dan ptu le giu nguyen vi tri\n");
		printf("10. Cau9: Sap xep so le dau mang so chan cuoi mang \n");
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
			printf("Nhap vao so ngguyen x: ");
				scanf_s("%d", &x);
				Cau1(mang, n, x);
				break;

		case 3:
			Cau2(mang, n);
			break;
		case 4:
			Cau3(mang, n);
			break;
		case 5:
			Cau4(mang, n);
			break;
		case 6:
			Cau5(mang, n);
			break;
		case 7:
			Cau6(mang, n);
			break;
		case 8:
			int x;
			printf("Nhap vao gia tri x: ");
			scanf_s("%d", &x);
			Cau7(mang, n,x);
			break;
		case 9:
			Cau8(mang, n);
			break;
		case 10:
			Cau9(mang, n);
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