#include <stdio.h>
#include <string.h>

/* Menentukan tarif ongkir per kg */
int getTarif(char kode[]) {
    if (strcmp(kode, "MDN") == 0) return 8000;
    if (strcmp(kode, "BLG") == 0) return 5000;
    if (strcmp(kode, "JKT") == 0) return 12000;
    if (strcmp(kode, "SBY") == 0) return 13000;
    return 0;
}

/* Menentukan nama kota */
void getNamaKota(char kode[], char kota[]) {
    if (strcmp(kode, "MDN") == 0) strcpy(kota, "Medan");
    else if (strcmp(kode, "BLG") == 0) strcpy(kota, "Balige");
    else if (strcmp(kode, "JKT") == 0) strcpy(kota, "Jakarta");
    else if (strcmp(kode, "SBY") == 0) strcpy(kota, "Surabaya");
}

/* Menentukan keterangan dalam/luar pulau */
void getKeterangan(char kode[], char ket[]) {
    if (strcmp(kode, "MDN") == 0 || strcmp(kode, "BLG") == 0)
        strcpy(ket, "Dalam Pulau");
    else
        strcpy(ket, "Luar Pulau");
}

/* Menentukan promo */
void hitungPromo(double totalBerat, char keterangan[], int *diskon, int *asuransi) {

    *diskon = 0;
    *asuransi = 0;

    if (totalBerat > 10)
        *diskon = 1;

    if (strcmp(keterangan, "Luar Pulau") == 0)
        *asuransi = 1;
}

int main() {

    char kode[10];
    char kota[20];
    char keterangan[20];

    double berat_butet;
    double berat_ucok;
    double total_berat;
    double total_ongkir;

    int tarif;
    int diskon;
    int asuransi;

    while (1) {

        scanf("%s", kode);

        if (strcmp(kode, "END") == 0)
            break;

        scanf("%lf", &berat_butet);

        /* Hitung berat Ucok */
        berat_ucok = 1.5 * berat_butet;

        /* Hitung total berat */
        total_berat = berat_butet + berat_ucok;

        /* Ambil tarif */
        tarif = getTarif(kode);

        /* Ambil nama kota dan keterangan */
        getNamaKota(kode, kota);
        getKeterangan(kode, keterangan);

        /* Hitung ongkir */
        total_ongkir = total_berat * tarif;

        /* Cek promo */
        hitungPromo(total_berat, keterangan, &diskon, &asuransi);

        if (diskon)
            total_ongkir = total_ongkir * 0.9;

        /* Cetak struk */
        printf("\n===== STRUK DEL EXPRESS =====\n");
        printf("Kota Tujuan       : %s\n", kota);
        printf("Berat Paket Butet : %.2lf kg\n", berat_butet);
        printf("Berat Paket Ucok  : %.2lf kg\n", berat_ucok);
        printf("Total Berat       : %.2lf kg\n", total_berat);
        printf("Total Ongkir      : Rp%.0lf\n", total_ongkir);

        if (!diskon && !asuransi)
            printf("Promo             : Tidak ada promo\n");
        else if (diskon && asuransi)
            printf("Promo             : Diskon 10%% + Asuransi Gratis\n");
        else if (diskon)
            printf("Promo             : Diskon 10%%\n");
        else
            printf("Promo             : Asuransi Gratis\n");

        printf("=============================\n\n");
    }

    return 0;
}