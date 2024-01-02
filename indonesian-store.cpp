#include <stdio.h>
#include <string.h>

struct dataPengiriman {
    char nama[100];
    int jumlah;
    int tanggal;
    char bulan[100];
};

void writeToFile(struct dataPengiriman produk[], int range, const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < range; i++) {
        fprintf(file, "%s %d %d %s\n", produk[i].nama, produk[i].jumlah, produk[i].tanggal, produk[i].bulan);
    }

    fclose(file);
}


void syncData(FILE *file, dataPengiriman produk[], int *range) {
    int dataSynced = fscanf(file, "%s %d %d %s", produk[*range].nama, &produk[*range].jumlah, &produk[*range].tanggal, produk[*range].bulan);
    
    if(dataSynced == 4){
        (*range)++;
        syncData(file, produk, range);
    }
}

void readFromFile(struct dataPengiriman produk[], int *range, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    *range = 0;

    syncData(file, produk, range);

    fclose(file);
}

void deleteData(struct dataPengiriman produk[], int *range, const char *namaToDelete) {
    int i, j;
    for (i = 0; i < *range; i++) {
        if (strcmp(produk[i].nama, namaToDelete) == 0) {
            // Jika nama barang cocok, geser semua data setelahnya ke atas
            for (j = i; j < *range - 1; j++) {
                strcpy(produk[j].nama, produk[j + 1].nama);
                produk[j].jumlah = produk[j + 1].jumlah;
                produk[j].tanggal = produk[j + 1].tanggal;
                strcpy(produk[j].bulan, produk[j + 1].bulan);
            }
            (*range)--;
            i--;  // Periksa lagi data yang bergeser ke posisi i
        }
    }
}

void daftarBarang() {
    printf("==============================\n");
    printf("\t MENU PENGIRIMAN \t\n");
    printf("==============================\n");
    printf("1. Masukkan identitas barang\n");
    printf("2. Data pengiriman\n");
    printf("3. Searching Data\n");
    printf("4. Mengurutkan data\n");
    printf("5. Hapus data\n");
    printf("6. Keluar\n");
}

void input_data(struct dataPengiriman produk[], int *range) {
    printf("===================================\n");
    printf("\t Masukkan identitas barang \t\n");
    printf("===================================\n");
    if (*range < 10000) {
        printf("Masukkan Nama barang : ");
        scanf("%s", produk[*range].nama);
        printf("Masukkan jumlah produk : ");
        scanf("%d", &produk[*range].jumlah);
        printf("Masukkan tanggal pengiriman : ");
        scanf("%d", &produk[*range].tanggal);
        printf("Masukkan bulan pengiriman : ");
        scanf("%s", produk[*range].bulan);
        (*range)++;
    } else {
        printf("Jumlah produk sudah mencapai batas maksimum.\n");
    }
}

void data(struct dataPengiriman produk[], int range) {
    printf("===================================\n");
    printf("\t Data Pengiriman \t\n");
    printf("===================================\n");
    for (int i = 0; i < range; i++) {
        printf("%s : %d, pengiriman pada tanggal %d bulan %s\n", produk[i].nama, produk[i].jumlah, produk[i].tanggal, produk[i].bulan);
    }
}

void cariProduk(struct dataPengiriman produk[], int range) {
    char barangDicari[100];
    printf("Masukkan Nama Produk yang Dicari : ");
    scanf("%s", barangDicari);

    int found = 0;
    for (int i = 0; i < range; i++) {
        if (strcmp(produk[i].nama, barangDicari) == 0) {
            printf("\nProduk ditemukan:\n");
            printf("%s : %d, pengiriman pada tanggal %d bulan %s\n", produk[i].nama, produk[i].jumlah, produk[i].tanggal, produk[i].bulan);
            found = 1;
            break;  // Hentikan pencarian setelah produk ditemukan
        }
    }

    if (!found) {
        printf("\nProduk tidak ditemukan\n");
    }
}

void PengirimanPerBulan(struct dataPengiriman produk[], int range) {
    // Mengurutkan pengiriman per bulan secara descending
    for (int i = 0; i < range - 1; i++) {
        for (int j = 0; j < range - i - 1; j++) {
            if (produk[j].jumlah < produk[j + 1].jumlah) {
                // Tukar nilai total dan bulan
                int tempJumlah = produk[j].jumlah;
                produk[j].jumlah = produk[j + 1].jumlah;
                produk[j + 1].jumlah = tempJumlah;

                // Tukar nama bulan
                char tempBulan[100];
                strcpy(tempBulan, produk[j].bulan);
                strcpy(produk[j].bulan, produk[j + 1].bulan);
                strcpy(produk[j + 1].bulan, tempBulan);
            }
        }
    }

    // Menampilkan pengurutan pengiriman per bulan
    printf("\nPengurutan Pengiriman per Bulan (descending):\n");
    for (int i = 0; i < range; i++) {
        printf("Bulan %s: %d\n", produk[i].bulan, produk[i].jumlah);
    }
}

int main() {
    struct dataPengiriman produk[10000];
    int range = 0;
    int pilih;

    // Membaca data dari file saat program dimulai
    readFromFile(produk, &range, "data_pengiriman.txt");

    do {
        daftarBarang();
        printf("Pilih Menu pengiriman (1-6): ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                input_data(produk, &range);
                break;
            case 2:
                data(produk, range);
                break;
            case 3:
                cariProduk(produk, range);
                break;
            case 4:
                PengirimanPerBulan(produk, range);
                printf("\nData Produk :\n");
                data(produk, range);
                break;
            case 5:
                // Hapus data berdasarkan nama barang
                {
                    char namaBarangHapus[100];
                    printf("Masukkan Nama Produk yang Akan Dihapus: ");
                    scanf("%s", namaBarangHapus);
                    deleteData(produk, &range, namaBarangHapus);
                    // Menyimpan data setelah dihapus ke dalam file
                    writeToFile(produk, range, "data_pengiriman.txt");
                    printf("Data berhasil dihapus.\n");
                }
                break;
            case 6:
                // Menyimpan data ke file sebelum keluar
                writeToFile(produk, range, "data_pengiriman.txt");
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilih != 6);

    return 0;
}
