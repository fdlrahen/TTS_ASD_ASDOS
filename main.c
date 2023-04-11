// 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
COORD coord={0,0};

void SetColor(unsigned short);
void SetColor(unsigned short color) {
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleOutput,color);
}

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
        FILE *file = fopen("data_barang.txt", "a");
    if (file == NULL) {
    printf("Gagal membuka file\n");
    return;
    }

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
    // tulis data ke file
    fprintf(file, "%s %s %d %s\n", dat[i+tot].tanggal, dat[i+tot].nama, dat[i+tot].id, dat[i+tot].harga);
    }
    tot += jum;

    fclose(file);
    printf("Data berhasil ditambahkan\n");
    system("pause");
    system("cls");

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
            printf(" Nomor ID Buku      :%d", dat[i].id);
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
            printf(" Nomor ID Buku      :%d", dat[i].id);
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
            printf(" Nomor ID Buku      :%d", dat[i].id);
            letak(26,31);
            printf(" Penerbit           :%s", dat[i].harga);
            getch();
        }
    }
    letak(26,35);
    printf("/n/n Tekan Enter Untuk Kembali ke Menu"); getch();
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
    SetColor(10);
    system("color 8F");
    getch();
    fflush(stdin);

     int pilihan;
    char a=170,b=219, str[]="54321";;
    printf("\n\n\n\n\n\n\n");
    printf("\n\n\n\t\t\t\t\tLoading...");
    printf("\n\n");
    printf( "\t\t\t\t\t");

    for (int i=0; i<= 25; i++)
    {
          printf(">");
        Sleep(100);
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
            printf("_");Sleep(10);
        }
        printf("\n\n");
        for(int i=0; i<46; i++)
        {
            printf("=");Sleep(10);
        }
        printf(" | LOGIN KE TOKO KLONTONG KAMI | ");
    }

   char user[5]="tugas",pass[8]="kematian",word[8],name[5];
    int i,j,k,l,p,input,cek,nilai,salah;
    p=0;
    salah=0;
    awal:
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t");
    printf("--SELAMAT DATANG!--\n");
    printf("\n\t\t\t\t\t");
    printf("USERNAME  : ");
    scanf("%s",&name);
    cek=0;
    for(i=0;i<5;i++){
        if(name[i]==user[i]){
            cek=cek+1;
        }else{
            cek=0;
        }
    }
    printf("\n\t\t\t\t\t");
    printf("PASSWORD  : ");
    for(i=0;i<8;i++){
        input=getch();
        if(input==13){
            goto cek;
        }else{
            word[i]=input;
            printf("*");
        }
    }
    nilai=0;
    for(i=0;i<8;i++){
        if(pass[i]==word[i]){
            nilai=nilai+1;
        }else{
            nilai=0;
        }
    }
    getch();
    cek:
    if(cek==5&&nilai==8){
        printf("\n\n\t\t\t\t  ");
        printf("Selamat datang di Tugas Kematian");
        printf("\n\n\t\t\t\t       ");
        printf("Klik ENTER untuk lanjut");
        getch();
        system("cls");
        return home();
    }else{
        if(cek==5){
            printf("\n\n\t\t\t\t\t   ");
            printf("Password salah");
            goto bawah;
        }else if(nilai==8){
            printf("\n\n\t\t\t\t\t   ");
            printf("Username salah");
            goto bawah;
        }else{
            printf("\n\n\t\t\t\t     ");
            printf("Username dan Password salah");
            goto bawah;
        }
    }
    bawah:
    salah=salah+1;
    if(salah==3){
        printf("\n\n\t\t  ");
        printf("Anda telah salah menginput username dan password sebanyak 3 kali\n");
        printf("\n\t\t\t\t\tAnda akan keluar dalam ");
        for( i =1 ; i<= 5; i++ ) {
            gotoxy(51, 20);
            printf("%c", str[p++]);
            Sleep(1000);
            if(p == strlen(str))
            p = 0;
        }
        system("cls");
        return 0;
    }else{
        printf("\n\n\t\t\t\t     ");
        printf("Klik ENTER untuk mengulangi");
        printf("\n\n\t\t\t\t  ");
        printf("Anda memiliki %d kesempatan lagi!",3-salah);
        getch();
        goto awal;
    }

    return 0;
}

void sama(){
    for(int h=0; h<100; h++){
        printf("=");
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////v-tabel pembuka
int home(){

    int pilihan;
    menu:
//////////////////////////////////////////////////v-garis pembuka

    system("cls");
    letak(8, 0);
    sama();
    letak(8, 2);
    printf("|===                                 SELAMAT DATANG DALAM PROGRAM                               ===|\n");
    letak(8, 4);
    sama();
    letak(8, 6);
    printf("|===                                    DATABASE KELOMPOK KAMI                                  ===|\n\n");
    letak(8, 8);
    sama();
    letak(8, 9);
    printf("|===                                   SILAHKAN MEMBUAT PESANAN                                 ===|\n");
    letak(8, 10);
    sama();


        do {
        letak (8,12);
        printf("= Menu Utama =");
        letak (9,13);
        printf("1. Tambah Data Buku");
        letak (9, 14);
        printf("2. Lihat Data Buku");
        letak (9,15);
        printf("3. Urutkan Data Buku");
        letak (9,16);
        printf("4. Pencarian Data Buku");
        letak (9, 17);
        printf("5. Hapus Data Buku");
        letak(9,18);
        printf("6. Ubah Data Buku");
        letak (9, 19);
        printf("7. Lihat Riwayat Perubahan");
        letak (9,20);
        printf("8. Exit");
        letak (8,21);
        printf("= Masukkan Pilihan Anda : "); scanf("%d", &pilihan);
        system("cls");


        switch(pilihan) {
            case 1: tambah(); break;
            case 2: lihat(); break;
            case 3: urut(); break;
            case 4: cari(); break;
            case 5: hapus(); break;
            case 6: edit(); break;
            case 7: riwayat(); break;
            case 8: return 0;
            default: letak(6,21); printf("Pilihan Tidak Tersedia");getch();
        }
    } while(pilihan != 8);

    return 0;
}
