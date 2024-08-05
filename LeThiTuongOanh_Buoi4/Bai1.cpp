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

int main() {
	int n;
	printf("Nhap vao so nguyen duong n: ");
	scanf_s("%d", &n);

	printf("Tong day 1 + 2 + ... + %d (De quy): %d\n", n, tong_day_de_quy(n));
	printf("Tong day 1 + 2 + ... + %d (Khu de quy): %d\n", n, tong_day_khu_de_quy(n));

	printf("Tong 1/2 + 2/3 + ... + %d/(%d+1) (De quy): %f\n", n, n, tong_phan_so_de_quy(n));
	printf("Tong 1/2 + 2/3 + ... + %d/(%d+1) (Khu de quy): %f\n", n, n, tong_phan_so_khu_de_quy(n));

	getchar();
	getchar();
	return 0;
}
