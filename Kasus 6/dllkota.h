/* ------------------------------------------------------------------------------------------------------------------ */
/* File : dllkota.h																									  */
/* Deskripsi : File header yang berperan untuk mendeklarasikan fungsi/prosedur yang digunakan untuk                   */
/* manipulasi data list dari struct kota dengan bentuk Doubley 														  */
/* ------------------------------------------------------------------------------------------------------------------ */
#ifndef DLLKOTA_H
#define DLLKOTA_H

#include "nama.h"

#define string char *

// Deklarasi struct kota
typedef struct kota{
	string namaKota;
	struct kota *prev;
	struct kota *next;
	Single *listNama;
}Double;

/*--------------------------------------------------*/
/*          Prosedur manipulasi list Kota :         */
/*--------------------------------------------------*/

Double *createKota(string input);
// Tujuan : Alokasi memori untuk node kota

void insKotaAwal(Double **headKota, string input);
// Tujuan : Menambahkan node kota di awal list kota;

void insKotaAkhir(Double **headKota, string input);
// Tujuan : Menambahkan node kota di akhir list kota

void delKotaAwal(Double **headKota);
// Tujuan : Menghapus (free()) node kota pada awal list kota

void delKotaAkhir(Double **headKota);
// Tujuan : Menghapus (free()) node kota pada akhir list kota

void delKotaTarget(Double **headKota, string target);
// Tujuan : Menghapus (free()) node kota yang diinginkan dengan menggunakan perbandingan

void clearKota(Double **headKota);
// Tujuan : Menghapus seluruh isi dari list kota

Double *cariKota(Double *headKota, string target);
// Tujuan : Mencari kota dengan perbandingan. Mengembalikkan alamat node

void tambahNamaKeKota(Double *headKota, string target, string nama);
// Tujuan : Menambahkan nama ke list kota

void tampilKota(Double *headKota);
// Tujuan : Menampilkan list kota (beserta list nama di dalamnya)

#endif
