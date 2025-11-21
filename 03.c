#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    char id[20];
    char fullName[50];
    struct Date birthDate;
    char address[100];
    char phone[20];
};

void inputStudent(struct Student sv[], int index) {
    getchar(); 
    printf("Enter student ID: ");
    fgets(sv[index].id, 20, stdin);
    sv[index].id[strcspn(sv[index].id, "\n")] = '\0';

    printf("Enter full name: ");
    fgets(sv[index].fullName, 50, stdin);
    sv[index].fullName[strcspn(sv[index].fullName, "\n")] = '\0';

    printf("Enter birth date (dd mm yyyy): ");
    scanf("%d %d %d", &sv[index].birthDate.day, &sv[index].birthDate.month, &sv[index].birthDate.year);

    getchar();
    printf("Enter address: ");
    fgets(sv[index].address, 100, stdin);
    sv[index].address[strcspn(sv[index].address, "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(sv[index].phone, 20, stdin);
    sv[index].phone[strcspn(sv[index].phone, "\n")] = '\0';
}

void inputStudentList(struct Student sv[], int *n) {
    printf("Enter number of students: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("\nStudent %d:\n", i + 1);
        inputStudent(sv, i);
    }
}

void displayStudents(struct Student sv[], int n) {
    if (n == 0) {
        printf("Danh sach rong\n");
        return;
    }

    printf("\nSTUDENT LIST\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("ID: %s\n", sv[i].id);
        printf("Full Name: %s\n", sv[i].fullName);
        printf("Birth Date: %d/%d/%d\n", sv[i].birthDate.day, sv[i].birthDate.month, sv[i].birthDate.year);
        printf("Address: %s\n", sv[i].address);
        printf("Phone: %s\n", sv[i].phone);
    }
}

void addStudent(struct Student sv[], int *n) {
    inputStudent(sv, *n);
    (*n)++;
    printf("Them sinh vien thanh cong\n");
}

void deleteStudent(struct Student sv[], int *n) {
    char idDelete[20];
    getchar();
    printf("Enter student ID to delete: ");
    fgets(idDelete, 20, stdin);
    idDelete[strcspn(idDelete, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strcmp(sv[i].id, idDelete) == 0) {
            for (int j = i; j < *n - 1; j++) {
                sv[j] = sv[j + 1];
            }
            (*n)--;
            printf("Xoa sinh vien thanh cong\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien\n");
}

void updateStudent(struct Student sv[], int n) {
    char idUpdate[20];
    getchar();
    printf("Enter student ID to update: ");
    fgets(idUpdate, 20, stdin);
    idUpdate[strcspn(idUpdate, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].id, idUpdate) == 0) {
            inputStudent(sv, i);
            printf("Cap nhap thanh cong\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien\n");
}

void sortStudent(struct Student sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(sv[i].fullName, sv[j].fullName) > 0 ) {
                struct Student temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    printf("\nSap xep thanh cong\n");
}

void searchStudent(struct Student sv[], int n) {
    char idSearch[20];
    getchar();
    printf("Enter student ID to search: ");
    fgets(idSearch, 20, stdin);
    idSearch[strcspn(idSearch, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(sv[i].id, idSearch) == 0) {
            printf("ID: %s\n", sv[i].id);
            printf("Full Name: %s\n", sv[i].fullName);
            printf("Birth Date: %d/%d/%d\n", sv[i].birthDate.day, sv[i].birthDate.month, sv[i].birthDate.year);
            printf("Address: %s\n", sv[i].address);
            printf("Phone: %s\n", sv[i].phone);
            return;
        }
    }
    printf("Khong tim thay sinh vien\n");
}

int main() {
    struct Student sv[100];
    int n = 0, choice;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Them sinh vien\n");
        printf("4. Xoa sinh vien theo ma\n");
        printf("5. Cap nhat thong tin sinh vien\n");
        printf("6. Sap xep theo ho ten (A-Z)\n");
        printf("7. Tim kiem theo ma sinh vien\n");
        printf("8. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
				inputStudentList(sv, &n);
				break;
				
            case 2:
				displayStudents(sv, n);
				break;
				
            case 3:
				addStudent(sv, &n);
				break;
				
            case 4:
				deleteStudent(sv, &n);
				break;
				
            case 5:
				updateStudent(sv, n);
				break;
				
            case 6:
				sortStudent(sv, n); 
				break;
            case 7:
				searchStudent(sv, n);
				break;
				
            case 8:
				printf("Ket thuc chuong trinh\n");
				break;
				
            default:
				printf("Lua chon khong hop le\n");
        }
    } while (choice != 8);
    
    return 0;
}
