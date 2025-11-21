#include <stdio.h>
#include <string.h>

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char maDon[20];
    char tenKH[50];
    Date ngayDat;
    double tongTien;
    char trangThai[20]; 
} DonHang;

DonHang ds[100];
int soLuong = 0;

void removeNewLine(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void nhapDonHang(DonHang *d) {
    printf("Nhap ma don hang: ");
    fgets(d->maDon, sizeof(d->maDon), stdin);
    removeNewLine(d->maDon);

    printf("Nhap ten khach hang: ");
    fgets(d->tenKH, sizeof(d->tenKH), stdin);
    removeNewLine(d->tenKH);

    printf("Nhap ngay dat hang (ngay thang nam): ");
    scanf("%d %d %d", &d->ngayDat.day, &d->ngayDat.month, &d->ngayDat.year);

    printf("Nhap tong tien: ");
    scanf("%lf", &d->tongTien);
    getchar(); 

    printf("Nhap trang thai (Dang xu ly / Da giao / Huy): ");
    fgets(d->trangThai, sizeof(d->trangThai), stdin);
    removeNewLine(d->trangThai);
}

void hienThi1(DonHang d) {
    printf("%-10s | %-20s | %02d/%02d/%04d | %10.2lf | %-15s\n",
           d.maDon, d.tenKH, d.ngayDat.day, d.ngayDat.month, d.ngayDat.year,
           d.tongTien, d.trangThai);
}

void hienThiTatCa() {
    printf("\n===== DANH SACH DON HANG =====\n");
    for (int i = 0; i < soLuong; i++) {
        hienThi1(ds[i]);
    }
}

int timTheoMa(char *ma) {
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(ds[i].maDon, ma) == 0)
            return i;
    }
    return -1;
}

void capNhatTrangThai() {
    char ma[20];
    printf("Nhap ma don hang can cap nhat: ");
    fgets(ma, sizeof(ma), stdin);
    removeNewLine(ma);

    int vt = timTheoMa(ma);
    if (vt == -1) {
        printf("Khong tim thay don hang!\n");
        return;
    }

    printf("Nhap trang thai moi: ");
    fgets(ds[vt].trangThai, sizeof(ds[vt].trangThai), stdin);
    removeNewLine(ds[vt].trangThai);

    printf("Cap nhat thanh cong!\n");
}

void xoaDonHang() {
    char ma[20];
    printf("Nhap ma don hang can xoa: ");
    fgets(ma, sizeof(ma), stdin);
    removeNewLine(ma);

    int vt = timTheoMa(ma);
    if (vt == -1) {
        printf("Khong tim thay don hang!\n");
        return;
    }

    for (int i = vt; i < soLuong - 1; i++) {
        ds[i] = ds[i + 1];
    }
    soLuong--;

    printf("Xoa thanh cong!\n");
}

void sapXep(int tang) {
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            int dk = tang ? (ds[i].tongTien > ds[j].tongTien)
                          : (ds[i].tongTien < ds[j].tongTien);

            if (dk) {
                DonHang temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void timKiem() {
    char ma[20];
    printf("Nhap ma don hang can tim: ");
    fgets(ma, sizeof(ma), stdin);
    removeNewLine(ma);

    int vt = timTheoMa(ma);
    if (vt == -1) {
        printf("Khong tim thay don hang!\n");
        return;
    }

    printf("Thong tin don hang:\n");
    hienThi1(ds[vt]);
}

int main() {
    int choice;

    do {
        printf("\n=========== MENU ===========\n");
        printf("1. Nhap thong tin don hang\n");
        printf("2. Hien thi tat ca don hang\n");
        printf("3. Cap nhat trang thai don hang\n");
        printf("4. Xoa don hang theo ma\n");
        printf("5. Sap xep don hang theo tong tien\n");
        printf("6. Tim kiem don hang theo ma\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                nhapDonHang(&ds[soLuong]);
                soLuong++;
                break;
            case 2:
                hienThiTatCa();
                break;
            case 3:
                capNhatTrangThai();
                break;
            case 4:
                xoaDonHang();
                break;
            case 5: {
                int t;
                printf("Nhap 1 de sap xep tang, 0 giam: ");
                scanf("%d", &t);
                getchar();
                sapXep(t);
                break;
            }
            case 6:
                timKiem();
                break;
            case 7:
                printf("Thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 7);

    return 0;
}
