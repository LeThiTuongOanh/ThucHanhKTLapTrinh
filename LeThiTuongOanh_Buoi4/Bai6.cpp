#include <stdio.h>

int dem_so_chu_so(int n) {
	int dem = 0;
	while (n != 0) {
		n /= 10;  // Loại bỏ chữ số cuối cùng của n
		dem++;    // Tăng biến đếm
	}
	return dem;
}

int main() {
	int n;
	printf("Nhap vao so nguyen duong n: ");
	scanf_s("%d", &n);

	if (n <= 0) {
		printf("Vui long nhap vao so nguyen duong!\n");
	}
	else {
		int so_chu_so = dem_so_chu_so(n);
		printf("So chu so cua %d la: %d\n", n, so_chu_so);
	}

	getchar();
	getchar();
	return 0;
}
