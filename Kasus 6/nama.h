/* ------------------------------------------------------------------------------------------------------------------ */
/* File : nama.h																									  */
/* Deskripsi : File header yang berperan untuk mendeklarasikan fungsi/prosedur yang digunakan untuk                   */
/* manipulasi data list dari struct nama dengan bentuk Single  														  */
/* ------------------------------------------------------------------------------------------------------------------ */

#ifndef NAMA_H
#define NAMA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define string char *

// Deklarasi struct nama
typedef struct nama{
	string namaOrang;
	struct nama *next;
}Single;

/*--------------------------------------------------*/
/*          Prosedur manipulasi list Nama :         */
/*--------------------------------------------------*/

Single *createNama(string input);
// Tujuan : Alokasi memori untuk node nama

void insNamaAwal(Single **headNama, string input);
// Tujuan : Menambahkan Node nama di awal list nama

void insNamaAkhir(Single **headNama, string input);
// Tujuan : Menambahkan Node nama di akhir list nama

void delNamaAwal(Single **headNama);
// Tujuan : Menghapus (free()) Node nama pada awal list nama
 
void delNamaAkhir(Single **headNama);
// Tujuan : Menghapus (free()) Node nama pada akhir list nama

void clearNama(Single **headNama);
// Tujuan : Menghapus SELURUH isi dari list nama

void tampilNama(Single *headNama);
// Tujuan : Menampilkan isi dari list nama

#endif
