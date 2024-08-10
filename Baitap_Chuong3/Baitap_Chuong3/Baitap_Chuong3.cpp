#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


// 1.Ham dem so khoang trang trong chuoi
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

// 2.Ham xoa khoang trang thua trong chuoi
void xoaKhoangTrangThua(char* str) {
    int i, x = 0;
    for (i = 0; str[i]; i++) {
        if (!isspace(str[i]) || (i > 0 && !isspace(str[i - 1]))) {
            str[x++] = str[i];
        }
    }
    if (x > 0 && isspace(str[x - 1])) {
        x--;
    }
    str[x] = '\0';
}

// 3.Ham chuyen chu cai thuong thanh in hoa, cac chu con lai thanh chu thuong
void chuanHoaChuoi(char* str) {
    int i = 0;
    int dauTu = 1;
    while (str[i]) {
        if (isspace(str[i])) {
            dauTu = 1;
        }
        else if (dauTu) {
            str[i] = toupper(str[i]);
            dauTu = 0;
        }
        else {
            str[i] = tolower(str[i]);
        }
        i++;
    }
}

// 4.Ham tim kiem ten trong chuoi ho ten 
int timTen(char* hoTen, char* ten) {
    return strstr(hoTen, ten) != NULL;
}

// 5.Ham chuyen chuoi ho ten thanh ho lot va ten 
void catHoTen(char* hoTen, char* hoLot, char* ten) {
    char* token = strrchr(hoTen, ' ');
    if (token != NULL) {
        strcpy(ten, token + 1);
        strncpy(hoLot, hoTen, token - hoTen);
        hoLot[token - hoTen] = '\0';
    }
    else {
        strcpy(hoLot, "");
        strcpy(ten, hoTen);
    }
}

// 6.Ham chen tu vao vi tri 
void chenTu(char* str, char* tu, int viTri) {
    int len = strlen(str);
    int lenTu = strlen(tu);
    for (int i = len - 1; i >= viTri; i--) {
        str[i + lenTu] = str[i];
    }
    for (int i = 0; i < lenTu; i++) {
        str[viTri + i] = tu[i];
    }
    str[len + lenTu] = '\0';
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
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            xoaKhoangTrangThua(str);
            printf("Chuoi sau khi xoa khoang trang thua: %s\n", str);
            _getch();
            break;
        case 3:           
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            chuanHoaChuoi(str);
            printf("Chuoi sau khi chuan hoa: %s\n", str);
            _getch();
            break;
        case 4:           
            printf("Nhap ho ten: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("Nhap ten can tim: ");
            fgets(ten, sizeof(ten), stdin);
            ten[strcspn(ten, "\n")] = '\0';
            if (timTen(str, ten)) {
                printf("Ten '%s' da nhap dung.\n", ten);
            }
            else {
                printf("Ten '%s' da nhap sai.\n", ten);
            }
            _getch();
            break;
        case 5:          
            printf("Nhap ho ten: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            catHoTen(str, hoLot, ten);
            printf("Ho lot: %s\n", hoLot);
            printf("Ten: %s\n", ten);
            _getch();
            break;
        case 6:           
            printf("Nhap chuoi: ");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("Nhap tu can chen: ");
            fgets(tu, sizeof(tu), stdin);
            tu[strcspn(tu, "\n")] = '\0';
            printf("Nhap vi tri chen: ");
            scanf("%d", &viTri);
            getchar();
            chenTu(str, tu, viTri);
            printf("Chuoi sau khi chen: %s\n", str);
            _getch();
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
