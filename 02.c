#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char phonenumber[20];
    char email[50];
}Contact;

void addContact(Contact arr[], int *n){
    printf("Nhap ten: ");
    scanf("%s", arr[*n].name);
    printf("Nhap so dien thoai: ");
    scanf("%s", arr[*n].phonenumber);
    printf("Nhap email: ");
    scanf("%s", arr[*n].email);
    (*n)++;
}

void displayContact(Contact arr[], int n){
    if (n == 0){
        printf("Chua co du lieu!\n");
        return;
    }
    printf("Danh sach lien he:\n");
    for (int i = 0; i < n; i++){
        printf("Lien he %d:\n", i + 1);
        printf("Ten: %s\n", arr[i].name);
        printf("So dien thoai: %s\n", arr[i].phonenumber);
        printf("Email: %s\n", arr[i].email);
    }
}

void searchContact(Contact arr[], int n, char name[]){
    int found = 0;
    for (int i = 0; i < n; i++){
        if (strcmp(arr[i].name, name) == 0){
            printf("Lien he tim thay:\n");
            printf("Ten: %s\n", arr[i].name);
            printf("So dien thoai: %s\n", arr[i].phonenumber);
            printf("Email: %s\n", arr[i].email);
            found = 1;
            break;
        }
    }
    if (!found){
        printf("Khong tim thay lien he voi ten %s\n", name);
    }
}

void deleteContact (Contact arr[], int *n, char name[]){
    int found = 0;
    for (int i = 0; i < *n; i++){
        if (strcmp(arr[i].name, name) == 0){
            for (int j = i; j < *n - 1; j++){
                arr[j] = arr[j + 1];
            }
            (*n)--;
            found = 1;
            printf("Da xoa lien he ten %s\n", name);
            break;
        }
    }
    if (!found){
        printf("Khong tim thay lien he voi ten %s\n", name);
    }
}

int main(){
    Contact arr[100];

    int choice;
    int n = 0;
    char name[50];

    do{
        printf("===========MENU============\n");
        printf("1.Them lien he moi.\n");
        printf("2.Hien thi tat ca lien he.\n");
        printf("3.Tim kiem theo ten.\n");
        printf("4.Xoa lien he theo ten.\n");
        printf("5.Thoat chuong trinh.\n");
        printf("===========================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                addContact(arr, &n);
                break;
            case 2:
                displayContact(arr, n);
                break;
            case 3:
                printf("Nhap ten can tim: ");
                scanf("%s", name);
                searchContact(arr, n, name);
                break;
            case 4:
                printf("Nhap ten can xoa: ");
                scanf("%s", name);
                deleteContact(arr, &n, name);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    }while (choice != 5);

    return 0;
}