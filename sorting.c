#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

struct Mahasiswa {
    char nama[50];
    char NPM[20];
    int semester;
    int umur;
    char Jurusan[50];
    char fakultas[50];
    char univ[50];
};
int jumlahmhs;
typedef struct Mahasiswa;
struct Mahasiswa info[50],temp;

bool baru(int jumlahmhs){ //fungsi untuk input data baru
	int a;
    for( a = 1; a <= jumlahmhs; a++) {
        printf("\nMasukkan nama: ");
        scanf(" %[^\n]s", &info[a].nama);
        printf("\nMasukkan NPM: ");
        scanf(" %[^\n]c", &info[a].NPM);
        printf("\nMasukkan Semester: ");
        scanf(" %d", &info[a].semester);
        printf("\nMasukkan Umur: ");
        scanf(" %d", &info[a].umur);
        printf("\nMasukkan Jurusan: ");
        scanf(" %[^\n]c", &info[a].Jurusan);
        printf("\nMasukkan Fakultas: ");
        scanf(" %[^\n]c", &info[a].fakultas);
        printf("\nMasukkan Universitas: ");
        scanf(" %[^\n]c", &info[a].univ);
      
    }
    return true;
}

void view() { //fungsi untuk menampilkan
	int a;
    for(a = 1; a<= jumlahmhs; a++) {
            printf("\n\nNPM   : %s", info[a].nama);
            printf("\nNama    : %s", info[a].NPM);
            printf("\nSemester: %d", info[a].semester);
            printf("\nUmur    : %d", info[a].umur);
            printf("\nProdi   : %s", info[a].Jurusan);
            printf("\nFakultas: %s", info[a].fakultas);
            printf("\nUniveristas  : %s", info[a].univ);
             
        }
        
    }


bool Update(int array) { //fungsi untuk memperbarui data
	
            int j = array;
            printf("/nMasukkan nama : ");
            scanf(" %[^\n]s", &info[j].nama);
            printf("\nMasukkan NPM baru: ");
            scanf(" %[^\n]c", &info[j].NPM);
            printf("\nMasukkan Semester: ");
            scanf(" %d", &info[j].semester);
            printf("\nMasukkan Umur: ");
            scanf(" %d", &info[j].umur);
            printf("\nMasukkan Jurusan: ");
            scanf(" %[^\n]c", &info[j].Jurusan);
            printf("\nMasukkan Fakultas: ");
            scanf(" %[^\n]c", &info[j].fakultas);
            printf("\nMasukkan Universitas: ");
            scanf(" %[^\n]c", &info[j].univ);
           
            return true;
}

bool Delet(int array) { //fungsi untuk menghapus
    strcpy(info[array].nama, "");
    strcpy(info[array].NPM, "");
    info[array].semester = 0;
    info[array].umur = 0;
    strcpy(info[array].Jurusan, "");
    strcpy(info[array].fakultas, "");
    strcpy(info[array].univ, "");;
    return true; 
}

int main() {
    //Menu
    int pilih;
    int i;
    char input[20];
    bool run = true;

    while(run == true) {
        printf("\n=== Pilihan Opsi ===\n");
      	printf("1. Opsi input mahasiswa baru\n2. Data semua mahasiswa\n3. Merbarui data mahasiswa\n4. Hapus data mahasiswa\n5. Urutkan data\n6.keluar pilih :  ");
        scanf("%d", &pilih);
        if(pilih > 0 && pilih < 6) {
            if(pilih == 1) {
            	system("cls");
                printf("jumlah mahasiswa: ");
                scanf(" %d", &jumlahmhs);
                if(jumlahmhs > 0) {
                    if(baru(jumlahmhs) == true) printf("Mahasiswa berhasil ditambahkan.\n\n");
                    else printf("Gagal menambahkan. \n\n");
                } else printf("Input tidak valid \n\n");
            }
            if(pilih == 2) {
            	system("cls");
                printf("Menampilkan semua data mahasiswa : \n");
                view();
            }
            if(pilih == 3) {
            	system("cls");
            	int i;
                printf("Masukkan nama yang akan di ganti: ");
                scanf(" %[^\n]s", &input);
                for( i = 1; i <= jumlahmhs; i++) {
                    if(!strcmp(info[i].nama, input)) {
                        if(Update(i)==true) printf("\nData mahasiswa diperbarui!\n\n");
                    } 
                }      
            }
            if (pilih == 4) {
            	system("cls");
            	int i;
                printf("\nMasukkan nama yang akan di hapus: ");
                scanf(" %[^\n]s", &input);
                for( i = 1; i<= jumlahmhs; i++) {
                    if(!strcmp(info[i].nama, input)) {
                        if(Delet(i)==true) printf("Data mahasiswa %s berhasil dihapus! \n\n", input);
                    }
                }
            }
            if (pilih == 5) {
            	system("cls");
                printf("\nMengurutkan berdasarkan NPM\n");
                int a, b;
                
                for(a=1;a<=jumlahmhs;a++) {
                    for( b=1;b<=jumlahmhs-1;b++) {
                        if(strcmp(info[b].nama, info[b+1].nama)>0) {
                            temp = info[b];
                            info[b] = info[b+1];
                            info[b+1] = temp;
                        }
                    }
                }
                printf("\nBerhasil diurutkan, Silahkan lihat di menu lihat semua data.");
            }
            
        } else if (pilih ==0) return 0;
    }

}
