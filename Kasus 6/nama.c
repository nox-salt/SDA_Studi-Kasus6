/* ------------------------------------------------------------------------------------------------------------------ */
/* File : nama.c																									  */
/* Deskripsi : Berisi algoritma untuk memanipulasi list nama dari header nama.h 									  */
/* ------------------------------------------------------------------------------------------------------------------ */


#include "nama.h"

//Program prosedur manipulasi list Nama
Single *createNama(string input){
	Single *newNama = (Single *) malloc(sizeof(Single));
	if(newNama == NULL){
		printf("Alokasi Nama Gagal!\n");
		return NULL;
	}
	
	newNama->namaOrang = strdup(input);
	newNama->next = NULL;
	
	return newNama;
}

void insNamaAwal(Single **headNama, string input){
	Single *newNama = createNama(input);
	
	if(*headNama == NULL){
		*headNama = newNama;
	}
	else{
		newNama->next = *headNama;
		*headNama = newNama;
	}
}

void insNamaAkhir(Single **headNama, string input){
	Single *newNama = createNama(input);
	if(*headNama == NULL){
		*headNama = newNama;
	}
	else{
		Single *point = *headNama;
		while(point->next != NULL){
			point = point->next;
		}
		point->next = newNama;
	}
}

void delNamaAwal(Single **headNama){
	if(*headNama == NULL){
		printf("List Kosong! Tidak ada yang bisa dihapus\n");
		return;
	}
	
	Single *toDelete = *headNama;
	*headNama = (*headNama)->next;
	
	free(toDelete->namaOrang);
	free(toDelete);
}

void delNamaAkhir(Single **headNama){
	if(*headNama == NULL){
		printf("List Kosong! Tidak ada yang bisa dihapus\n");
		return;
	}
	
	if((*headNama)->next == NULL){
		free((*headNama)->namaOrang);
		free(*headNama);
		*headNama = NULL;
		return;
	}
	
	Single *toDelete = *headNama;
	Single *prev;
	while(toDelete->next != NULL){
		prev = toDelete;
		toDelete = toDelete->next;
	}
	
	prev->next = NULL;
	free(toDelete->namaOrang);
	free(toDelete);
}

void clearNama(Single **headNama){
	if(*headNama == NULL){
		printf("List Kosong! Tidak ada yang bisa dihapus\n");
		return;
	}
	
	Single *toDelete = *headNama;
	while(toDelete != NULL){
		Single *next = toDelete->next;
		free(toDelete->namaOrang);
		free(toDelete);
		toDelete = next;
	}
	*headNama = NULL;
}

void tampilNama(Single *headNama){
	if(headNama == NULL){
		printf("List Kosong!\n");
		return;
	}
	printf("NAMA : ");
	while(headNama != NULL){
		printf("%s -> ", headNama->namaOrang);
		headNama = headNama->next;
	}
	printf("NULL\n");
}
