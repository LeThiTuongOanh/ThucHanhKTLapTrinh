#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Hàm kiểm tra chuỗi chỉ chứa ký số
int kiem_tra_chuoi_ky_so(const char *s) {
	while (*s) {
		if (!isdigit(*s)) return 0;  // Nếu không phải ký số, trả về 0
		s++;
	}
	return 1;  // Trả về 1 nếu toàn ký số
}


void chuyen_hoa_chu_cai_dau_tu(char *s) {
	int la_bat_dau = 1;
	while (*s) {
		if (la_bat_dau) {
			*s = toupper(*s);
			la_bat_dau = 0;
		}
		else {
			*s = tolower(*s);
		}
		if (*s == ' ') la_bat_dau = 1;
		s++;
	}
}
int main() {
	int lua_chon;
	printf("----------MeNu------------ :\n");
	printf("1. Kiem tra chuoi co chua toan ky so\n");
	printf("2. Chuyen doi ky tu dau tien cua moi tu thanh chu in hoa\n");
	printf("3. Xoa khoang trang thua trong chuoi\n");
	printf("4. Tim kiem ten trong chuoi ho ten\n");
	printf("5. Cat chuoi ho ten thanh ho lot va ten\n");
	printf("Nhap lua chon cua ban: ");
	scanf_s("%d", &lua_chon);

	switch (lua_chon) {
	case 1: {
				char s[100];
				printf("Nhap chuoi can kiem tra: ");
				scanf_s(" %[^\n]", s, sizeof(s));  // Đọc chuỗi có khoảng trắng
				if (kiem_tra_chuoi_ky_so(s)) {
					printf("Chuoi chua toan ky so.\n");
				}
				else {
					printf("Chuoi khong chua toan ky so.\n");
				}
				break;
	}
	case 2: {
				char s[100];
				printf("Nhap chuoi can chuyen doi: ");
				scanf_s(" %[^\n]", s, sizeof(s));
				chuyen_hoa_chu_cai_dau_tu(s);
				printf("Chuoi sau khi chuyen doi: %s\n", s);
				break;
	}
	default:
		printf("Lua chon khong hop le!\n");
		break;
	}

	getchar();
	getchar();

	return 0;
}
