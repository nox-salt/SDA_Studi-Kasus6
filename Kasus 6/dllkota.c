/* ------------------------------------------------------------------------------------------------------------------ */
/* File : dllkota.c																									  */
/* Deskripsi : Berisi algoritma untuk memanipulasi list kota dari header dllkota.h  														  */
/* ------------------------------------------------------------------------------------------------------------------ */

#include "dllkota.h"

//Program prosedur manipulasi list Kota
Double *createKota(string input){
	Double *newKota = (Double *) malloc(sizeof(Double));
	if(newKota == NULL){
		printf("Alokasi Kota Gagal!\n");
		return NULL;
	}
	
	newKota->namaKota = strdup(input);
	newKota->prev = NULL;
	newKota->next = NULL;
	newKota->listNama = NULL;
	
	return newKota;
}

void insKotaAwal(Double **headKota, string input){
	Double *newKota = createKota(input);
	
	if(*headKota == NULL){
		*headKota = newKota;
	}
	else{
		newKota->next = *headKota;
		(*headKota)->prev = newKota;
		*headKota = newKota;
	}
}

void insKotaAkhir(Double **headKota, string input){
	Double *newKota = createKota(input);
	
	if(*headKota == NULL){
		*headKota = newKota;
		return;
	}
	else{
		Double *point = *headKota;
		while(point->next != NULL){
			point = point->next;
		}
		point->next = newKota;
		newKota->prev = point;
	}
}

void delKotaAwal(Double **headKota){
	if(*headKota == NULL){
		printf("List Kosong! Tidak ada yang bisa dihapus\n");
		return;
	}
	
	Double *toDelete = *headKota;
	
	*headKota = (*headKota)->next;
	
	if(*headKota != NULL){
		(*headKota)->prev = NULL;
	}
	
	clearNama(&(toDelete->listNama));
	free(toDelete->namaKota);
	free(toDelete);
}

void delKotaAkhir(Double **headKota){
	if(*headKota == NULL){
		printf("List Kosong! Tidak ada yang bisa dihapus\n");
		return;
	}
	
	if((*headKota)->next == NULL){
		free((*headKota)->namaKota);
		free(*headKota);
		*headKota = NULL;
		return;
	}
	
	Double *toDelete = *headKota;
	while(toDelete->next != NULL){
		toDelete = toDelete->next;
	}
	
	toDelete->prev->next = NULL;
	
	clearNama(&(toDelete->listNama));
	free(toDelete->namaKota);
	free(toDelete);
}

void delKotaTarget(Double **headKota, string target){
	if(*headKota == NULL){
		printf("List Kosong! Tidak ada yang bisa dihapus");
		return;
	}
	
	Double *kotaTarget = cariKota(*headKota, target);
	if(kotaTarget == NULL){
		printf("Link Kosong! Tidak bisa menambahkan nama ke kota kosong\n");
		return;
	}
	
	//Jika kota target ada di awal
	if(kotaTarget == *headKota){
		
		*headKota = kotaTarget->next;
		
		if(*headKota != NULL){
			(*headKota)->prev = NULL;
		}
		
		clearNama(&(kotaTarget->listNama));
		free(kotaTarget->namaKota);
		free(kotaTarget);
	}
	else if(kotaTarget->next == NULL){
		kotaTarget->prev->next = NULL;
		
		clearNama(&(kotaTarget->listNama));
		free(kotaTarget->namaKota);
		free(kotaTarget);
	}
	else{
		kotaTarget->prev->next = kotaTarget->next;
		kotaTarget->next->prev = kotaTarget->prev;
		
		clearNama(&(kotaTarget->listNama));
		free(kotaTarget->namaKota);
		free(kotaTarget);
	}
}

void clearKota(Double **headKota){
	if(*headKota == NULL){
		printf("List Kosong! Tidak ada yang bisa dihapus\n");
		return;
	}
	
	Double *current = *headKota;
	while(current != NULL){
		Double *next = current->next;
		clearNama(&(current->listNama));
		free(current->namaKota);
		free(current);
		current = next;
	}
	*headKota = NULL;
}

Double *cariKota(Double *headKota, string target){
	if(headKota == NULL){
		printf("List Kosong! Tidak ada yang bisa dicari\n");
		return NULL;
	}
	else{
		Double *current = headKota;
		while(current != NULL){
			if(strcmp(current->namaKota, target) == 0){
				return current;
			}
			current = current->next;
		}
		printf("Tidak dapat menemukan kota [%s]!\n", target);
		return NULL;
	}
}

void tambahNamaKeKota(Double *headKota, string target, string nama){
	if(headKota == NULL){
		printf("List Kosong! Tidak bisa menambahkan nama\n");
		return;
	}
	
	Double *kotaTarget = cariKota(headKota, target);
	if(kotaTarget == NULL){
		printf("List Kosong! Tidak bisa menambahkan nama ke kota kosong\n");
		return;
	}
	insNamaAkhir(&(kotaTarget->listNama), nama);
}


void tampilKota(Double *headKota){
	if(headKota == NULL){
		printf("List Kosong!\n");
		return;
	}
	
	printf("DAFTAR KOTA : \n");
	while(headKota != NULL){
		printf("%s -> ", headKota->namaKota);
		tampilNama(headKota->listNama);
		headKota = headKota->next;
	}
}
