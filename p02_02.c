#include <stdio.h>

int hitungTotalKategori(int stok[], int n, int kategori) {
    int total = 0;

    for(int i = 0; i < n; i++) {
        int kategori_elemen = (i % 3) + 1;

        if(kategori_elemen == kategori) {
            total = total + stok[i];
        }
    }

    return total;
}

int main() {
    int n;
    
    scanf("%d", &n);

    int stok[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &stok[i]);
    }

    int kategori;
    scanf("%d", &kategori);

    int total = hitungTotalKategori(stok, n, kategori);

    printf("Total stok kategori %d = %d\n", kategori, total);

    return 0;
}