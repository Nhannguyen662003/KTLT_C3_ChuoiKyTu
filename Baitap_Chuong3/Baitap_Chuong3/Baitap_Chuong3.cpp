#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
// Ham dem so khoang trang trong chuoi
int demKhoangTrang(char* str) {
    int count = 0;
    while (*str) {
        if (isspace(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char str[100], hoLot[50], ten[50], tu[50];
    int choice, viTri;

    do {
        system("cls");
        printf("Danh sach bai tap:\n");
        printf("1. Dem khoang trang trong chuoi\n");
        printf("2. Xoa khoang trang thua trong chuoi\n");
        printf("3. Chuan hoa chuoi\n");
        printf("4. Tim kiem ten trong chuoi ho ten\n");
        printf("5. Cat ho ten\n");
        printf("6. Chen tu vao vi tri chi dinh\n");
        printf("7. Xoa tu trong chuoi\n");
        printf("8. Liet ke ky tu xuat hien\n");
        printf("9. Tim ky tu xuat hien nhieu nhat\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("So khoang trang: %d\n", demKhoangTrang(str));
            _getch();
            break;
        case 2:           
            break;
        case 3:           
            break;
        case 4:           
            break;
        case 5:          
            break;
        case 6:           
            break;
        case 7:           
            break;
        case 8:          
            break;
        case 9:           
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            _getch();
            break;
        default:
            printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 0);

    return 0;
}
