/* ------------------------------------------------------------------------------------------------------------------ */
/* File : main.c 																									  */
/* Deskripsi : Program utama yang mengimpor program dllkota.h dan nama.h melalui display.h dan algoritma input user   */
/* ------------------------------------------------------------------------------------------------------------------ */

#include "display.h"
#define MAX_STR 100

int main() {
    Double *headKota = NULL;
    int choice;
    char namaKota[MAX_STR];
    char namaOrang[MAX_STR];
    char targetKota[MAX_STR];
    
    do {
        menu();
        scanf("%d", &choice);
        getchar(); // Clear the newline character
        
        switch(choice) {
            case 1: // Tambah Kota di Awal
                printf("Masukkan nama kota: ");
                fgets(namaKota, MAX_STR, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0; // Remove newline
                insKotaAwal(&headKota, namaKota);
                printf("Kota %s berhasil ditambahkan di awal!\n", namaKota);
                break;
                
            case 2: // Tambah Kota di Akhir
                printf("Masukkan nama kota: ");
                fgets(namaKota, MAX_STR, stdin);
                namaKota[strcspn(namaKota, "\n")] = 0; // Remove newline
                insKotaAkhir(&headKota, namaKota);
                printf("Kota %s berhasil ditambahkan di akhir!\n", namaKota);
                break;
                
            case 3: // Tambah Nama ke Kota
                printf("Masukkan nama kota target: ");
                fgets(targetKota, MAX_STR, stdin);
                targetKota[strcspn(targetKota, "\n")] = 0; // Remove newline
                
                printf("Masukkan nama orang: ");
                fgets(namaOrang, MAX_STR, stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0; // Remove newline
                
                tambahNamaKeKota(headKota, targetKota, namaOrang);
                printf("Nama %s berhasil ditambahkan ke kota %s!\n", namaOrang, targetKota);
                break;
                
            case 4: // Hapus Kota di Awal
                delKotaAwal(&headKota);
                printf("Kota di awal berhasil dihapus!\n");
                break;
                
            case 5: // Hapus Kota di Akhir
                delKotaAkhir(&headKota);
                printf("Kota di akhir berhasil dihapus!\n");
                break;
                
            case 6: // Hapus Kota Tertentu
                printf("Masukkan nama kota yang ingin dihapus: ");
                fgets(targetKota, MAX_STR, stdin);
                targetKota[strcspn(targetKota, "\n")] = 0; // Remove newline
                
                delKotaTarget(&headKota, targetKota);
                printf("Kota %s berhasil dihapus!\n", targetKota);
                break;
                
            case 7: // Hapus Semua Kota
                clearKota(&headKota);
                printf("Semua kota berhasil dihapus!\n");
                break;
                
            case 8: // Tampilkan Semua Kota
                tampilKota(headKota);
                break;
                
            case 9: // Tambah Nama di Awal Kota
                printf("Masukkan nama kota target: ");
                fgets(targetKota, MAX_STR, stdin);
                targetKota[strcspn(targetKota, "\n")] = 0; // Remove newline
                
                printf("Masukkan nama orang: ");
                fgets(namaOrang, MAX_STR, stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0; // Remove newline
                
                Double *kotaTarget = cariKota(headKota, targetKota);
                if(kotaTarget != NULL) {
                    insNamaAwal(&(kotaTarget->listNama), namaOrang);
                    printf("Nama %s berhasil ditambahkan di awal kota %s!\n", namaOrang, targetKota);
                }
                break;
                
            case 10: // Tambah Nama di Akhir Kota
                printf("Masukkan nama kota target: ");
                fgets(targetKota, MAX_STR, stdin);
                targetKota[strcspn(targetKota, "\n")] = 0; // Remove newline
                
                printf("Masukkan nama orang: ");
                fgets(namaOrang, MAX_STR, stdin);
                namaOrang[strcspn(namaOrang, "\n")] = 0; // Remove newline
                
                kotaTarget = cariKota(headKota, targetKota);
                if(kotaTarget != NULL) {
                    insNamaAkhir(&(kotaTarget->listNama), namaOrang);
                    printf("Nama %s berhasil ditambahkan di akhir kota %s!\n", namaOrang, targetKota);
                }
                break;
                
            case 11: // Hapus Nama di Awal Kota
                printf("Masukkan nama kota target: ");
                fgets(targetKota, MAX_STR, stdin);
                targetKota[strcspn(targetKota, "\n")] = 0; // Remove newline
                
                kotaTarget = cariKota(headKota, targetKota);
                if(kotaTarget != NULL) {
                    delNamaAwal(&(kotaTarget->listNama));
                    printf("Nama di awal kota %s berhasil dihapus!\n", targetKota);
                }
                break;
                
            case 12: // Hapus Nama di Akhir Kota
                printf("Masukkan nama kota target: ");
                fgets(targetKota, MAX_STR, stdin);
                targetKota[strcspn(targetKota, "\n")] = 0; // Remove newline
                
                kotaTarget = cariKota(headKota, targetKota);
                if(kotaTarget != NULL) {
                    delNamaAkhir(&(kotaTarget->listNama));
                    printf("Nama di akhir kota %s berhasil dihapus!\n", targetKota);
                }
                break;
                
            case 13: // Hapus Semua Nama di Kota
                printf("Masukkan nama kota target: ");
                fgets(targetKota, MAX_STR, stdin);
                targetKota[strcspn(targetKota, "\n")] = 0; // Remove newline
                
                kotaTarget = cariKota(headKota, targetKota);
                if(kotaTarget != NULL) {
                    clearNama(&(kotaTarget->listNama));
                    printf("Semua nama di kota %s berhasil dihapus!\n", targetKota);
                }
                break;
                
            case 0: // Keluar
                printf("Terima kasih telah menggunakan program ini!\n");
                break;
                
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
        
    } while (choice != 0);
    
    // Cleanup before exiting
    clearKota(&headKota);
    
    return 0;
}
