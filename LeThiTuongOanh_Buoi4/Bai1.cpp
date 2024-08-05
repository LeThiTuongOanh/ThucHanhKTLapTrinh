#include <stdio.h>
#include <math.h>

// Hàm tính tổng 1 + 2 + 3 + ... + n (Đệ quy)
int tong_day_de_quy(int n) {
	if (n == 1)
		return 1;
	return n + tong_day_de_quy(n - 1);
}

// Hàm tính tổng 1 + 2 + 3 + ... + n (Khử đệ quy)
int tong_day_khu_de_quy(int n) {
	int tong = 0;
	for (int i = 1; i <= n; i++) {
		tong += i;
	}
	return tong;
}
double tong_phan_so_de_quy(int n) {
	if (n == 1)
		return 1.0 / 2;
	return (double)n / (n + 1) + tong_phan_so_de_quy(n - 1);
}

double tong_phan_so_khu_de_quy(int n) {
	double tong = 0;
	for (int i = 1; i <= n; i++) {
		tong += (double)i / (i + 1);
	}
	return tong;
}


int tong_cau_3_de_quy(int n) {
	if (n == 1)
		return 1 * 2;
	return n * (n + 1) + tong_cau_3_de_quy(n - 1);
}

// (Khử đệ quy)
int tong_cau_3_khu_de_quy(int n) {
	int tong = 0;
	for (int i = 1; i <= n; i++) {
		tong += i * (i + 1);
	}
	return tong;
}


// Hàm tính tổng S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n + 1) (Đệ quy)
double tong_cau_4_de_quy(int n) {
	if (n == 0)
		return 1.0;  // Trường hợp cơ bản: S(0) = 1
	return 1.0 / (2 * n + 1) + tong_cau_4_de_quy(n - 1);
}

// Hàm tính tổng S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n + 1) (Khử đệ quy)
double tong_cau_4_khu_de_quy(int n) {
	double tong = 0.0;
	for (int i = 0; i <= n; i++) {
		tong += 1.0 / (2 * i + 1);
	}
	return tong;
}


int main() {
	int n;
	printf("Nhap vao so nguyen duong n: ");
	scanf_s("%d", &n);

	printf("Tong day 1 + 2 + ... + %d (De quy): %d\n", n, tong_day_de_quy(n));
	printf("Tong day 1 + 2 + ... + %d (Khu de quy): %d\n", n, tong_day_khu_de_quy(n));

	printf("Tong 1/2 + 2/3 + ... + %d/(%d+1) (De quy): %f\n", n, n, tong_phan_so_de_quy(n));
	printf("Tong 1/2 + 2/3 + ... + %d/(%d+1) (Khu de quy): %f\n", n, n, tong_phan_so_khu_de_quy(n));


	printf("Tong 1*2 + 2*3 + ... + %d*(%d+1) (De quy): %d\n", n, n, tong_cau_3_de_quy(n));
	printf("Tong 1*2 + 2*3 + ... + %d*(%d+1) (Khu de quy): %d\n", n, n, tong_cau_3_khu_de_quy(n));

	printf("Tong S(n) (De quy): %f\n", tong_cau_4_de_quy(n));
	printf("Tong S(n) (Khu de quy): %f\n", tong_cau_4_khu_de_quy(n));

	getchar();
	getchar();
	return 0;
}
