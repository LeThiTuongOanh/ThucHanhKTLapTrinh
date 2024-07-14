#include <stdio.h>

void main() {
	int a, b, c;
	float ket_qua;

	printf("Nhap a: ");
	scanf_s("%d", &a);
	printf("Nhap b: ");
	scanf_s("%d", &b);
	printf("Nhap c: ");
	scanf_s("%d", &c);

	if (c > 0) {
		ket_qua = (float)c / (a - b);
		printf("Ket qua bieu thuc c/(a-b) la: %.2f\n", ket_qua);
	}
	else {
		printf("C phai lon hon 0\n");
	}

	// Đợi người dùng nhấn phím trước khi thoát
	printf("Nhan phim bat ky de thoat...");
	getchar(); // Đọc phím Enter từ lần nhập cuối
	getchar(); // Đợi người dùng nhấn phím

	return;
}