// 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct data {
    int id;
    char nama[30], tanggal[20], harga[30], telp[20];
}dat[15];

struct node {
    char hist[100];
    struct node *next;
};

int jum=0, tot=0, temp, oy, result, x;
char temps[100];
struct node*head = NULL;

void letak();
void Ulang_Login();
void Tampilan_Tetap();
void Mencari();

// 2

 void letak (int x, int y){
        COORD CRD;
        CRD.X=x;
        CRD.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
    }

void Tampilan_Tetap() {
//v-garis pembuka
          printf("\n\n");
          printf( "\t\t\t");
        printf("|");
         for(int i=0; i<51; i++)
        {
            printf("=");Sleep(1);
        }
        printf("|");printf("\n");
//v-spasi satu
          printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(0);
        }
        printf("|");printf("\n");
//v-spasi tulisan satu
        printf( "\t\t\t");printf("|");
        for(int i=0; i<12; i++)
        {
            printf(" ");Sleep(1);
        }
        printf("SELAMAT DATANG DALAM PROGRAM");
 //v-spasi tulisan dua
         for(int i=0; i<11; i++)
        {
            printf(" ");Sleep(1);
        } printf("|");printf("\n");
 //v-spasi tulisan satu
         printf( "\t\t\t");printf("|");
        for(int i=0; i<7; i++)
        {
            printf(" ");Sleep(1);
        }
        printf("     DATABASE TOKO KLONTONG KAMI      ");
         for(int i=0; i<6; i++)
        {
            printf(" ");Sleep(1);
        } printf("|");printf("\n");
//v-spasi tulisan dua
         printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(0);
        }
        printf("|");printf("\n");
//v-garis pembatas tengah
       printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf("-");Sleep(1);
        }
        printf("|");printf("\n");
//v-spasi satu
        printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(0);
        }
        printf("|");printf("\n");
//v-spasi tulisan satu
         printf( "\t\t\t");
        for(int i=0; i<15; i++)
        {
            printf(" ");Sleep(1);
        }
//v-waktu
        time_t mytime;
		mytime = time(NULL);
		printf(ctime(&mytime));

//v-spasi dua
         printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(0);
        }
        printf("|");printf("\n");
//v-garis penutup
        printf( "\t\t\t");
        printf("|");
         for(int i=0; i<51; i++)
        {
            printf("-");Sleep(1);
        }
        printf("|");printf("\n");
//v-menu utama
        printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(0);
        }
        printf("|");printf("\n");
}

void Mencari(){
    int i, j;
    struct data temp;

    // sorting the data array by book ID in ascending order using bubble sort
    for(i=0; i<tot-1; i++){
        for(j=0; j<tot-i-1; j++){
            if(dat[j].id > dat[j+1].id){
                temp = dat[j];
                dat[j] = dat[j+1];
                dat[j+1] = temp;
            }
        }
    }
}


void append(struct node** head_ref, char histo[]) {

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = * head_ref;

    strcpy(new_node->hist, histo);
    new_node->next = NULL;

    if(*head_ref == NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// 3

void printlist(struct node *node){
    while(node != NULL){
        printf("%s \n", node->hist);
        node = node->next;
    }
}

// 4
void tambah(){

    letak(26,13);
    printf(" ===== Tambah Data Buku ===== ");
    letak(26,14);
    printf(" Masukan Jumlah Data Buku Yang Dimasukan (max = 15): "); scanf("%d", &jum);

    for(int i = 0; i < jum; i++) {
        system("cls");
        Tampilan_Tetap();
        letak(26,13);
        printf(" ===== Tambah Data Buku ===== ");
        letak(26,14);
        printf(" Masukan Jumlah Data Buku Yang Dimasukan (max = 15): %d", jum);

        letak(26,16);
        printf(" Data ke %d", i+1);
        letak(26,17);
        printf(" Tanggal       : ");
        letak(26,18);
        printf(" Judul Buku    : ");
        letak(26,19);
        printf(" ID Buku       : ");
        letak(26,20);
        printf(" Penerbit      : ");

        letak(43,17);
        scanf(" %[^\n]%*c", &dat[i+tot].tanggal);
        letak(43,18);
        scanf(" %[^\n]%*c", &dat[i+tot].nama);
        letak(43,19);
        scanf(" %d", &dat[i+tot].id);
        letak(43,20);
        scanf(" %[^\n]%*c", &dat[i+tot].harga);
    }
// 5
    snprintf(temps, sizeof(temps), " ADMIN menambahkan %d data buku", jum);
    append(&head, temps);
    tot += jum;
    letak(26,22);
    printf(" ===== NOTIFIKASI ===== ");
    letak(26,23);
    printf(" %d Data Buku Berhasil Ditambahkan", tot);
    letak(26,24);
    printf(" Tekan Enter Untuk Kembali ke Menu"); getch();

}

// 6

void lihat() {
    for(int i = 0; i < tot; i++) {
        if(i==0 || i%3==0) {
            system("cls");
            Tampilan_Tetap();
            letak(26,13);
            printf(" ===== Daftar Data Buku ===== \n\n");
            letak(26,15);
            printf(" Data ke %d", i+1);
            letak(26,16);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(26,17);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(26,18);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(26,19);
            printf(" Penerbit           :%s", dat[i].harga);
        }else if(i==1 || i==4 || i==7 || i==10 || i==13) {
            letak(26,21);
            printf(" Data ke %d", i+1);
            letak(26,22);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(26,23);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(26,24);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(26,25);
            printf(" Penerbit           :%s", dat[i].harga);
// 7
        }else {
            letak(26,27);
            printf(" Data ke %d", i+1);
            letak(26,28);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(26,29);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(26,30);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(26,31);
            printf(" Penerbit           :%s", dat[i].harga);
            getch();
        }
    }
    letak(26,33);
    printf(" Tekan Enter Untuk Kembali ke Menu"); getch();
}

// 8

void urut() {
    int j=0;
    for (int i = 0; i < tot -1; j++) {
        for (int j = 0; j < tot -i -1; j++) {
            if (dat[j].id > dat[j+1].id) {
                temp = dat[j].id;
                dat[j].id = dat[j+1].id;
                dat[j+1].id = temp;

                strcpy(temps, dat[j].nama);
                strcpy(dat[j].nama, dat[j+1].nama);
                strcpy(dat[j+1].nama, temps);

                strcpy(temps, dat[j].telp);
                strcpy(dat[j].telp, dat[j+1].telp);
                strcpy(dat[j+1].telp, temps);

                strcpy(temps, dat[j].tanggal);
                strcpy(dat[j].tanggal, dat[j+1].tanggal);
                strcpy(dat[j+1].tanggal, temps);

                strcpy(temps, dat[j].harga);
                strcpy(dat[j].harga, dat[j+1].harga);
                strcpy(dat[j+1].harga, temps);
            }
        }
    }

// 9

    for(int i = 0; i < tot; i++) {
        if(i == 0 || i% 3 == 0 ) {
            system("cls");
            Tampilan_Tetap();
            letak(26,13);
            printf(" ===== Daftar Data Buku ===== \n\n");
            letak(26,15);
            printf(" Data ke %d", i+1);
            letak(26,16);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(26,17);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(26,18);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(26,19);
            printf(" Penerbit           :%s", dat[i].harga);
        }else if(i==1 || i==4 || i==7 || i==10 || i==13) {
            letak(26,21);
            printf(" Data ke %d", i+1);
            letak(26,22);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(26,23);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(26,24);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(26,25);
            printf(" Penerbit           :%s", dat[i].harga);
// 7
        }else {
            letak(26,27);
            printf(" Data ke %d", i+1);
            letak(26,28);
            printf(" Tanggal Input      :%s", dat[i].tanggal);
            letak(26,29);
            printf(" Judul Buku         :%s", dat[i].nama);
            letak(26,30);
            printf(" Nomor ID Buku      :%s", dat[i].id);
            letak(26,31);
            printf(" Penerbit           :%s", dat[i].harga);
            getch();
        }
    }
    letak (26,33);
    strcpy (temps, " ADMIN mengurutkan data buku");
    append (&head, temps);

    letak (26,34);
    printf(" `Tekan Enter Untuk Kembali ke Menu");
}

//11
void cari(){
    letak(26,13);
    printf("==Pencarian Data Buku==");
    letak (26,15);
    printf("Masukkan Nomor ID Buku: "); scanf("%d", &oy);
    result = 0;
    Mencari ();
    for (x=0; x <= tot; x++) {
        if (oy == dat[x].id){
            result = 1;
            break;
        }
    }
    if (result == 1){
        letak (26,17);
        printf("~ Data Ditemukan ");
        letak (26,19);
        printf("Tanggal input : %s", dat [x].tanggal);
        letak (26,20);
        printf("Judul Buku : %s", dat [x].nama);
        letak (26,21);
        printf("Nomor ID Buku : %d", dat [x].id);
        letak (26,22);
        printf("Penerbit: %s", dat [x].harga);
    }
    else{
        letak (26,24);
        printf("~ Data Tidak Ditemukan ~");
    }

    letak (26,24);
    snprintf(temps, sizeof(temps), "ADMIN mencari data Buku No. %d", oy);
    append(&head, temps);
    letak (26,25);
    printf("Tekan Enter Untuk Kembali ke Menu"); getch();
}

void hapus () {
    char jawab, search[30];
    letak(26,13);
    printf("=== Hapus Data Buku ===");
    letak(26,15);
    printf("Masukkan Nomor ID Buku : "); scanf("%d", &oy);
    Mencari ();
    result = 0;
    for ( x = 0; x <= tot; x++) {
            if (oy == dat [x].id) {
                result = 1;
                break;
            }
    }

    if (result == 1) {
        letak (26,17);
        printf("Data buku berikut akan dihapus :");
        letak (26,19);
        printf("Tanggal input : %s", dat [x].tanggal);
        letak (26,20);
        printf("Judul Buku : %s", dat [x].nama);
        letak (26,21);
        printf("Nomor ID Buku : %d", dat [x].id);
        letak (26,22);
        printf("Penerbit : %s", dat [x].harga);

        snprintf(temps, sizeof(temps), " ADMIN menghapus data Buku No. %d", dat [x].id);
        append(&head, temps);

        for (int i = 0; i < tot; i++) {
            strcpy(dat [x+i].nama, dat [x+1+i].nama);
            dat [x+i].id = dat [x+1+i].id;
            strcpy(dat [x+i].telp, dat [x+1+i].telp);
            strcpy(dat [x+i].tanggal, dat [x+1+i].tanggal);
            strcpy(dat [x+i].harga, dat [x+1+i].harga);
        }
        tot -= 1;
    }
    else{
        letak (26,24);
        printf("~ Data Tidak Ditemukan ");
    }
    letak (26,25);
    printf("Tekan Enter Untuk Kembali ke Menu"); getch();

}

//14
void edit () {
    char stemp [30], search [30];
    int jaw= 0;

    letak (26,13);
    printf("=== Ubah Data Buku ===");
    letak (26,15);
    printf("Masukkan Nomor ID Buku: "); scanf("%d", &oy);
    Mencari ();
    result = 0;
    for ( x = 0; x <= tot; x++) {
        if (oy == dat [x].id) {
            result = 1;
            break;
        }
    }

    if (result == 1) {
        letak (26,17);
        printf("Data Buku berikut akan Diubah :");
        letak (26,19);
        printf("Tanggal input   : %s", dat [x].tanggal);
        letak (26,20);
        printf("Judul Buku      : %s", dat [x].nama);
        letak (26,21);
        printf("Nomor ID Buku   : %d", dat [x].id);
        letak (26,22);
        printf("Penerbit        : %s", dat [x].harga);

        letak (26,24);
        printf("Pilih Data yang akan diganti");
        letak (26,26);
        printf("1. Tanggal input");
        letak (26,27);
        printf("2. Judul Buku");
        letak (26,28);
        printf("3. Nomor ID Buku");
        letak (26,29);
        printf("4. Penerbit");
        letak (26,30);
        printf("5. Selesai / Batal");
        letak (26,32);
        printf("Pilihan : "); scanf("%d", &jaw);

        switch (jaw) {
            case 1: letak (26,19); printf(" Tanggal Input Baru: "); scanf("%[^\n]*c", &stemp);
            strcpy (search, dat [x]. tanggal);
            strcpy (dat [x].tanggal, stemp);
            snprintf(temps, sizeof(temps), " ADMIN mengubah tanggal input buku No. %d dari %s menjadi %s", dat [x].id, search, dat [x]. tanggal);
            append(&head, temps);
            break;

            case 2: letak (26,21); printf(" Judul Baru "); scanf(" %[^\n]*c", &stemp);
            strcpy (search, dat [x].nama);
            strcpy(dat [x].nama, stemp);
            snprintf(temps, sizeof(temps), " ADMIN mengubah judul buku No. %d dari %s menjadi %s", dat [x].id, search, dat [x].nama); append(head, temps);
            break;

            case 3: letak (26,23); printf(" Nomor ID Buku: "); scanf("%d", &temp);
            jaw = dat [x]. id;
            dat [x].id = temp;
            snprintf(temps, sizeof(temps), " ADMIN mengubah Nomor ID buku No. %d dari %d menjadi %d", dat [x].id, jaw, dat [x].id);
            append(&head, temps);
            break;

            case 4:
            letak (26,25); printf(" Penerbit Baru: "); scanf("%[^\n]*c", stemp);
            strcpy(search, dat[x].harga);
            strcpy(dat[x].harga, stemp);
            snprintf(temps, sizeof(temps), " ADMIN mengubah Penerbit buku No. %d dari %s menjadi %s", dat[x].id, search, dat[x].harga);
            append(&head, temps);
            break;

            case 5:break;

            default: letak (26,27); printf("Pilihan Tidak Tersedia"); break;
            }
    }
    else{
            letak (26,34);
            printf(" Data Tidak Ditemukan ");
        }
        letak (26,37);
            printf("Tekan Enter Untuk Kembali ke Menu");
            getch();
}

//17
void riwayat () {
     system("cls");
     printf("\n printlist (head); Riwayat Perubahan Data Buku =====\n\n");
     printf("\n\n Tekan Enter Untuk Kembali ke Menu"); getch();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
     int pilihan;
    char a=170,b=219;
    printf("\n\n\n\n\n\n\n");
    printf("\n\n\n\t\t\t\t\tLoading...");
    printf("\n\n");
    printf( "\t\t\t\t\t");

    for (int i=0; i<= 50; i++)
    {
          printf(">");
        Sleep(1);
    }
    printf ("\n\n\t\t\t\t\t'PRESS ANY BUTTON TO LOGIN'");
    system ("pause>0");


    char nama[10], psw[8];
    int ulang = 0;
    system ("cls");

    for(int i=0; i<3; i++)
    {
        for(int i=0; i<120; i++)
        {
            printf("_");Sleep(0);
        }
        printf("\n\n");
        for(int i=0; i<46; i++)
        {
            printf("=");Sleep(1);
        }
        printf(" | LOGIN KE TOKO KLONTONG KAMI | ");

        for(int i=0; i<41; i++)
        {
            printf("=");Sleep(1);
        }
        printf("\n");
         for(int i=0; i<120; i++)
        {
            printf("_");Sleep(0);
        }
        printf("\n\n");
        printf(" Username: ");
        scanf ( "%s", &nama);
        printf(" Password: ");
        scanf("%s", &psw);

        if ((strcmp(nama,"admin")==0)&&(strcmp(psw,"1234")==0))
        {
            break;
        } else
        {
            printf("\n Password atau username yang anda masukan salah.");
            ulang = ulang + 1;
            Sleep(2000);
        }
        system ("cls");
    }

    if(ulang<3)
    {
        printf("\n Anda berhasil login");
     {system ("cls"); goto menu;}
    }

    else
    {
        printf("\n Anda terlalu banyak membuat kesalahan, Anda bisa ngopi dulu kemudian merenungkan kesalahan Anda,\nlalu setelah itu Anda bisa mencoba login kembali.");
    }
    printf("\n-----------------------------------\n\n");return 0;

    menu:
        do {
        system ("cls");
        Tampilan_Tetap();
        letak (26,13);
        printf("1. Tambah Data Buku");
        letak (26,14);
        printf("2. Lihat Data Buku");
        letak (26,15);
        printf("3. Urutkan Data Buku");
        letak (26,16);
        printf("4. Pencarian Data Buku");
        letak (26,17);
        printf("5. Hapus Data Buku");
        letak (26,18);
        printf("6. Ubah Data Buku");
        letak (26,19);
        printf("7. Lihat Riwayat Perubahan");
        letak (26,20);
        printf("8. Exit");
        letak (26,21);
        printf("Masukkan Pilihan Anda : "); scanf("%d", &pilihan);

        switch(pilihan) {
            case 1: system ("cls");
                    Tampilan_Tetap();
                    tambah();
                    break;
            case 2: system ("cls");
                    Tampilan_Tetap();
                    lihat();
                    break;
            case 3: system ("cls");
                    Tampilan_Tetap();
                    urut();
                    break;
            case 4: system ("cls");
                    Tampilan_Tetap();
                    cari();
                    break;
            case 5: system ("cls");
                    Tampilan_Tetap();
                    hapus();
                    break;
            case 6: system ("cls");
                    Tampilan_Tetap();
                    edit();
                    break;
            case 7: system ("cls");
                    Tampilan_Tetap();
                    riwayat();
                    break;
            case 8: return 0;
            default: letak(6,21); printf("Pilihan Tidak Tersedia");getch();
        }
    } while(pilihan != 8);

}
