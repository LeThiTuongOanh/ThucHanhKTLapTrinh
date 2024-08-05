#include <stdio.h>
#include <math.h>

// Hàm tính tổng 1 + 2 + 3 + ... + n (Đệ quy)
int tong_day_de_quy(int n) {
	if (n == 1)
		return 1;
	return n + tong_day_de_quy(n - 1);
}

// Hàm tính tổng 1 + 2 + 3 + ... + n (Khử đệ quy)
/*int tong_day_khu_de_quy(int n) {
	int tong = 0;
	for (int i = 1; i <= n; i++) {
		tong += i;
	}
	return tong;
}
*/

int main() {
	int n;
	printf("Nhap vao so nguyen duong n: ");
	scanf_s("%d", &n);

	printf("Tong day 1 + 2 + ... + %d (De quy): %d\n", n, tong_day_de_quy(n));
//	printf("Tong day 1 + 2 + ... + %d (Khu de quy): %d\n", n, tong_day_khu_de_quy(n));

	getchar();
	getchar();
	return 0;
}
