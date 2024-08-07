#include <stdio.h>

// Hàm thực hiện việc di chuyển đĩa
void MoveDisk(char from, char to) {
	printf("Chuyen dia tu %c sang %c\n", from, to);
}

// Hàm chính thực hiện thuật toán Tháp Hà Nội
void Tower(int n, char colA, char colB, char colC) {
	// Nếu chỉ có 1 đĩa, di chuyển trực tiếp từ colA sang colC
	if (n == 1) {
		MoveDisk(colA, colC);
	}
	else {
		// Bước 1: Chuyển n-1 đĩa từ colA sang colB, dùng colC làm trung gian
		Tower(n - 1, colA, colC, colB);

		// Bước 2: Chuyển đĩa thứ n từ colA sang colC
		MoveDisk(colA, colC);

		// Bước 3: Chuyển n-1 đĩa từ colB sang colC, dùng colA làm trung gian
		Tower(n - 1, colB, colA, colC);
	}
}

// Hàm main để chạy chương trình
int main() {
	int n = 3; // Số lượng đĩa
	printf("So luong dia: %d\n", n);
	Tower(n, 'A', 'B', 'C');

	getchar();

	getchar();
	return 0;
}
