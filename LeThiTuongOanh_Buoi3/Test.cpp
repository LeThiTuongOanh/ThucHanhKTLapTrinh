#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MA_SAN_PHAM_LEN 6
#define TEN_SAN_PHAM_LEN 11

typedef struct {
	char ma_san_pham[MA_SAN_PHAM_LEN];
	char ten_san_pham[TEN_SAN_PHAM_LEN];
	float don_gia;
	int so_luong_trong_kho;
} SanPham;

// Hàm nhập danh sách sản phẩm từ file
void nhap_danh_sach_san_pham(SanPham **dssp, int *n) {
	FILE *file;
	errno_t err = fopen_s(&file, "san_pham.txt", "r");
	if (err != 0 || file == NULL) {
		printf("Khong the mo file.\n");
		exit(1);
	}

	if (fscanf_s(file, "%d", n) != 1) {
		printf("Loi doc so luong san pham.\n");
		fclose(file);
		exit(1);
	}

	*dssp = (SanPham *)malloc(*n * sizeof(SanPham));
	if (*dssp == NULL) {
		printf("Khong du bo nho.\n");
		fclose(file);
		exit(1);
	}

	for (int i = 0; i < *n; i++) {
		if (fscanf_s(file, "%5s %10s %f %d", (*dssp)[i].ma_san_pham, (unsigned)_countof((*dssp)[i].ma_san_pham),
			(*dssp)[i].ten_san_pham, (unsigned)_countof((*dssp)[i].ten_san_pham),
			&(*dssp)[i].don_gia, &(*dssp)[i].so_luong_trong_kho) != 4) {
			printf("Loi doc du lieu san pham.\n");
			free(*dssp);
			fclose(file);
			exit(1);
		}
	}

	fclose(file);
}

// Hàm xuất danh sách sản phẩm
void xuat_danh_sach_san_pham(SanPham *dssp, int n) {
	printf("Danh sach san pham:\n");
	for (int i = 0; i < n; i++) {
		printf("Ma san pham: %s, Ten san pham: %s, Don gia: %.2f, So luong trong kho: %d\n",
			dssp[i].ma_san_pham, dssp[i].ten_san_pham, dssp[i].don_gia, dssp[i].so_luong_trong_kho);
	}
}

// Hàm sắp xếp danh sách sản phẩm theo đơn giá
void sap_xep_danh_sach(SanPham *dssp, int n) {
	SanPham temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (dssp[i].don_gia > dssp[j].don_gia) {
				temp = dssp[i];
				dssp[i] = dssp[j];
				dssp[j] = temp;
			}
		}
	}
}

// Hàm xuất các sản phẩm có mã số "A01"
void xuat_san_pham_ma_A01(SanPham *dssp, int n) {
	printf("San pham co ma so 'A01':\n");
	for (int i = 0; i < n; i++) {
		if (strcmp(dssp[i].ma_san_pham, "A01") == 0) {
			printf("Ma san pham: %s, Ten san pham: %s, Don gia: %.2f, So luong trong kho: %d\n",
				dssp[i].ma_san_pham, dssp[i].ten_san_pham, dssp[i].don_gia, dssp[i].so_luong_trong_kho);
		}
	}
}

int main() {
	int n;
	SanPham *dssp;

	nhap_danh_sach_san_pham(&dssp, &n);
	xuat_danh_sach_san_pham(dssp, n);
	sap_xep_danh_sach(dssp, n);
	printf("Danh sach san pham sau khi sap xep:\n");
	xuat_danh_sach_san_pham(dssp, n);
	xuat_san_pham_ma_A01(dssp, n);

	free(dssp);
	getchar();
	getchar();
	return 0;
}
