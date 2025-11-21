#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

void inputStudents(Student arr[], int *n) {
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", n);
    getchar(); 

    for (int i = 0; i < *n; i++) {
        printf("Hoc sinh thu %d \n", i + 1);

        printf("Nhap ten: ");
        fgets(arr[i].name, sizeof(arr[i].name), stdin);
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';

        printf("Nhap tuoi: ");
        scanf("%d", &arr[i].age);
        getchar();

        printf("Nhap diem: ");
        scanf("%f", &arr[i].grade);
        getchar();
    }
}

void displayStudents(Student arr[], int *n) {
    printf("\n===== DANH SACH HOC SINH =====\n");
    for (int i = 0; i < n; i++) {
        printf("%d. Ten: %s | Tuoi: %d | Diem: %.2f\n", i + 1, arr[i].name, arr[i].age, arr[i].grade);
    }
}

void averageGrade(Student arr[], int *n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i].grade;

    printf("Diem trung binh cua tat ca hoc sinh: %.2f\n", sum / n);
}

int main() {
    Student arr[100];
    int n = 0;
    int choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Nhap thong tin hoc sinh\n");
        printf("2. Hien thi danh sach hoc sinh\n");
        printf("3. Tinh diem trung binh\n");
        printf("4. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                inputStudents(arr, &n);
                break;
            case 2:
                displayStudents(arr, &n);
                break;
            case 3:
                averageGrade(arr, &n);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 4);

    return 0;
}
