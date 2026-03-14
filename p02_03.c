#include <stdio.h>

void tampilMenu() {
    printf("=== MENU KAFETARIA IT DEL ===\n");
    printf("1. Nasi Goreng   - 15000\n");
    printf("2. Mie Goreng    - 12000\n");
    printf("3. Ayam Geprek   - 18000\n");
    printf("4. Teh Manis     - 5000\n");
    printf("5. Jus Alpukat   - 10000\n");
}

int hitungTotal(int harga, int jumlah) {
    int total;
    total = harga * jumlah;
    return total;
}

int main() {

    char menu[5][20] = {
        "Nasi Goreng",
        "Mie Goreng",
        "Ayam Geprek",
        "Teh Manis",
        "Jus Alpukat"
    };

    int harga[5] = {15000, 12000, 18000, 5000, 10000};

    int pilihan;
    int jumlah;
    int total;
    int harga_menu;

    tampilMenu();

    printf("\nMasukkan nomor menu: ");
    scanf("%d", &pilihan);

    printf("Masukkan jumlah pesanan: ");
    scanf("%d", &jumlah);

    switch(pilihan) {

        case 1:
            harga_menu = harga[0];
            break;

        case 2:
            harga_menu = harga[1];
            break;

        case 3:
            harga_menu = harga[2];
            break;

        case 4:
            harga_menu = harga[3];
            break;

        case 5:
            harga_menu = harga[4];
            break;

        default:
            printf("Menu tidak tersedia\n");
            return 0;
    }

    total = hitungTotal(harga_menu, jumlah);

    printf("\nMenu yang dipilih : %s\n", menu[pilihan-1]);
    printf("Jumlah pesanan    : %d\n", jumlah);
    printf("Total pembayaran  : %d\n", total);

    return 0;
}