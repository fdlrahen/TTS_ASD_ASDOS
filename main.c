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

void sama() {
          printf( "\t\t\t");
        printf("+");
         for(int i=0; i<51; i++)
        {
            printf("=");Sleep(1);
        }
        printf("+");printf("\n");
}

void kosong() {
        printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(0);
        }
        printf("|");printf("\n");
}

void garis() {
        printf( "\t\t\t");
        printf("|");
         for(int i=0; i<51; i++)
        {
            printf("-");Sleep(1);
        }
        printf("|");printf("\n");
}

void Tampilan_Tetap() {

    printf("\n\n");
    sama();
    kosong();
//v-spasi tulisan satu
        printf( "\t\t\t");printf("|");
        for(int i=0; i<12; i++)
        {
            printf(" ");Sleep(1);
        }
        printf("\033[1;34mSelamat Datang Dalam Program\033[0m");
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
        printf("\033[1;34m     Database Toko Klontong kami      \033[0m");
         for(int i=0; i<6; i++)
        {
            printf(" ");Sleep(1);
        } printf("|");printf("\n");

    kosong();
    garis();
    kosong();

         printf( "\t\t\t");
        for(int i=0; i<15; i++)
        {
            printf(" ");Sleep(1);
        }
//v-waktu

        printf("\033[1;32m");
        time_t mytime;
		mytime = time(NULL);
		printf(ctime(&mytime));
        printf("\033[0m");
//v-spasi dua
         printf( "\t\t\t");printf("|");
         for(int i=0; i<51; i++)
        {
            printf(" ");Sleep(0);
        }
        printf("|");printf("\n");
//v-garis penutup

    garis();
    kosong();kosong();kosong();kosong();kosong();kosong();kosong();kosong();kosong();kosong();kosong();
    kosong();kosong();kosong();kosong();

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
    Tampilan_Tetap();
    letak(26,13);
    printf(" --- Tambah Data Buku --- ");
    letak(26,14);
    printf(" Masukan Jumlah Data Buku Yang Dimasukan : "); scanf("%d", &jum);

    for(int i = 0; i < jum; i++) {
        system("cls");
        Tampilan_Tetap();
        letak(26,13);
        printf(" --- Tambah Data Buku --- ");
        letak(26,14);
        printf(" Masukan Jumlah Data Buku Yang Dimasukan : %d", jum);

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
        printf("\t\t\t Data berhasil ditambahkan\n");
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
            printf(" --- Daftar Data Buku --- \n\n");
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
    printf("\n\n\t\t\t Tekan Enter Untuk Kembali ke Menu"); getch();
}


// 8

void urut() {
    int temp;
    char temps[30];
    Tampilan_Tetap();
    for (int i = 0; i < tot -1; i++) {
    for (int j = 0; j < tot -i -1; j++) {
    if (dat[j].id > dat[j+1].id) {
        temp = dat[j].id;
        dat[j].id = dat[j+1].id;
        dat[j+1].id = temp;

            strcpy(temps, dat[j].nama);
            strcpy(dat[j].nama, dat[j+1].nama);
            strcpy(dat[j+1].nama, temps);

            strcpy(temps, dat[j].tanggal);
            strcpy(dat[j].tanggal, dat[j+1].tanggal);
            strcpy(dat[j+1].tanggal, temps);

            strcpy(temps, dat[j].harga);
            strcpy(dat[j].harga, dat[j+1].harga);
            strcpy(dat[j+1].harga, temps);

            strcpy(temps, dat[j].telp);
            strcpy(dat[j].telp, dat[j+1].telp);
            strcpy(dat[j+1].telp, temps);
        }
    }
}
printf("Data berhasil diurutkan berdasarkan ID Buku\n");
system("pause");
system("cls");
}

//11
void cari(){
    int oy;
    Tampilan_Tetap();
    letak(26,13);
    printf("==Pencarian Data Buku==");
    letak (26,15);
    printf("Masukkan Nomor ID Buku: ");
    scanf("%d", &oy);

    int result = 0, x;
    for (x=0; x < tot; x++) {
        if (oy == dat[x].id){
            result = 1;
            break;
        }
    }

    if (result == 1){
        letak (26,17);
        printf("~ Data Ditemukan ");
        letak (26,19);
        printf("Tanggal input : %s", dat[x].tanggal);
        letak (26,20);
        printf("Judul Buku : %s", dat[x].nama);
        letak (26,21);
        printf("Nomor ID Buku : %d", dat[x].id);
        letak (26,22);
        printf("Penerbit: %s", dat[x].harga);
    }
    else{
        letak (26,24);
        printf("\t\t\t --- Data Tidak Ditemukan ---");
    }

    letak (26,25);
    printf("\t\t\t Tekan Enter Untuk Kembali ke Menu");
    getch();
}


void hapus() {
    char jawab, search[30];
    Tampilan_Tetap();
    letak(26,13);
    printf(" --- Hapus Data Buku ---");
    letak(26,15);
    printf("Masukkan Nomor ID Buku : ");
    scanf("%d", &oy);
    Mencari();
    result = 0;
    for (x = 0; x <= tot; x++) {
        if (oy == dat[x].id) {
            result = 1;
            break;
        }
    }

    if (result == 1) {
        letak(26,17);
        printf("Data buku berikut akan dihapus :");
        letak(26,19);
        printf("Tanggal input : %s", dat[x].tanggal);
        letak(26,20);
        printf("Judul Buku : %s", dat[x].nama);
        letak(26,21);
        printf("Nomor ID Buku : %d", dat[x].id);
        letak(26,22);
        printf("Penerbit : %s", dat[x].harga);

        snprintf(temps, sizeof(temps), " ADMIN menghapus data Buku No. %d", dat[x].id);
        append(&head, temps);

        for (int i = x; i < tot - 1; i++) {
            strcpy(dat[i].nama, dat[i + 1].nama);
            dat[i].id = dat[i + 1].id;
            strcpy(dat[i].telp, dat[i + 1].telp);
            strcpy(dat[i].tanggal, dat[i + 1].tanggal);
            strcpy(dat[i].harga, dat[i + 1].harga);
        }
        tot--;
    } else {
        letak(26,24);
        printf(" --- Data Tidak Ditemukan ---");
    }
    letak(26,25);
    printf(" Tekan Enter Untuk Kembali ke Menu");
    getch();
}


//14
void edit() {
    char stemp[30], search[30], temps[100];
    int jaw = 0;
    Tampilan_Tetap();
    letak(26, 13);
    printf(" --- Ubah Data Buku ---");
    letak(26, 15);
    printf("Masukkan Nomor ID Buku: ");
    scanf("%d", &oy);

    Mencari();

    result = 0;
    for (x = 0; x <= tot; x++) {
        if (oy == dat[x].id) {
            result = 1;
            break;
        }
    }

    if (result == 1) {
        letak(26, 17);
        printf("Data Buku berikut akan Diubah :");
        letak(26, 19);
        printf("Tanggal input   : %s", dat[x].tanggal);
        letak(26, 20);
        printf("Judul Buku      : %s", dat[x].nama);
        letak(26, 21);
        printf("Nomor ID Buku   : %d", dat[x].id);
        letak(26, 22);
        printf("Penerbit        : %s", dat[x].harga);

        letak(26, 24);
        printf("Pilih Data yang akan diganti");
        letak(26, 26);
        printf("1. Tanggal input");
        letak(26, 27);
        printf("2. Judul Buku");
        letak(26, 28);
        printf("3. Nomor ID Buku");
        letak(26, 29);
        printf("4. Penerbit");
        letak(26, 30);
        printf("5. Selesai / Batal");
        letak(26, 32);
        printf("Pilihan : ");
        scanf("%d", &jaw);

        switch (jaw) {
            case 1:
                letak(26, 19);
                printf(" Tanggal Input Baru: ");
                scanf(" %[^\n]s", stemp);
                strcpy(search, dat[x].tanggal);
                strcpy(dat[x].tanggal, stemp);
                snprintf(temps, sizeof(temps), " ADMIN mengubah tanggal input buku No. %d dari %s menjadi %s", dat[x].id, search, dat[x].tanggal);
                append(&head, temps);
                break;

            case 2:
                letak(26, 21);
                printf(" Judul Baru: ");
                scanf(" %[^\n]s", stemp);
                strcpy(search, dat[x].nama);
                strcpy(dat[x].nama, stemp);
                snprintf(temps, sizeof(temps), " ADMIN mengubah judul buku No. %d dari %s menjadi %s", dat[x].id, search, dat[x].nama);
                append(&head, temps);
                break;

            case 3:
                letak(26, 23);
                printf(" Nomor ID Buku Baru: ");
                scanf("%d", &temp);
                jaw = dat[x].id;
                dat[x].id = temp;
                snprintf(temps, sizeof(temps), " ADMIN mengubah Nomor ID buku No. %d dari %d menjadi %d", jaw, jaw, dat[x].id);
                append(&head, temps);
                break;

        case 4:
        letak(26, 25);
        printf(" Penerbit Baru: ");
        scanf(" %[^\n]s", stemp);
        strcpy(search, dat[x].harga);
        strcpy(dat[x].harga, stemp);
        snprintf(temps, sizeof(temps), " ADMIN mengubah penerbit buku No. %d dari %s menjadi %s", dat[x].id, search, dat[x].harga);
        append(&head, temps);
        break;

        case 5:
        return;

        default:
        letak(26, 34);
        printf("Pilihan tidak tersedia!");
        break;
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
     int pilihan;
    char a=170,b=219, str[]="54321";;
    printf("\n\n\n\n\n\n\n");
    printf("\033[1;32m\n\n\n\t\t\t\t\tLoading...\033[0m");
    printf("\n\n");
    printf( "\t\t\t\t\t");

    for (int i=0; i<= 25; i++)
    {
          printf(">");
        Sleep(100);
    }
    printf ("\033[1;32m \n\n\t\t\t\t\t'PRESS ANY BUTTON TO LOGIN' \033[0m");
    system ("pause>0");

    char nama[10], psw[8];
    int ulang = 0;
    system ("cls");

    for(int i=0; i<1; i++)
    {
        sama();
        printf("\n");
        printf( "\t\t\t");printf("|");
        for(int i=0; i<7; i++)
        {
            printf(" ");Sleep(1);
        }
        printf("\033[1;34m     Login ke Toko Klontong KAMI      \033[0m");
         for(int i=0; i<6; i++)
        {
            printf(" ");Sleep(1);
        } printf("|");printf("\n");
        printf("\n");
        sama();
        printf("\n\n");

}

   char user[5]="tugas",pass[8]="kematian",word[8],name[5];
    int i,j,k,l,p,input,cek,nilai,salah;
    p=0;
    salah=0;
    awal:

    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t");
    printf("\033[1;34m--- SELAMAT DATANG! ---\n\033[0m");
    printf("\n\t\t\t\t\t");
    printf("USERNAME  :\033[1;32m \033[0m");
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
            printf("\033[1;32m*\033[0m");
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
        printf("\033[1;32mSelamat datang di Tugas Kematian\033[0m");
        printf("\n\n\t\t\t\t       ");
        printf("\033[1;32mKlik ENTER untuk lanjut\033[0m");
        getch();
        system("cls");
        goto muka;
    }else{
        if(cek==5){
            printf("\n\n\t\t\t\t\t   ");
            printf("\033[1;31mPassword salah\033[0m");
            goto bawah;
        }else if(nilai==8){
            printf("\n\n\t\t\t\t\t   ");
            printf("\033[1;31mUsername salah\033[0m");
            goto bawah;
        }else{
            printf("\n\n\t\t\t\t     ");
            printf("\033[1;31mUsername dan Password salah\033[0m");
            goto bawah;
        }
    }
    bawah:
    salah=salah+1;
    if(salah==3){
        printf("\n\n\t\t  ");
        printf("\033[1;31mAnda telah salah menginput username dan password sebanyak 3 kali\n\033[0m");
        printf("\033[1;31m\n\t\t\t\t\tAnda akan keluar dalam \033[0m");
        for( i =1 ; i<= 5; i++ ) {
            letak(51, 20);
            printf("%c", str[p++]);
            Sleep(1000);
            if(p == strlen(str))
            p = 0;
        }
        system("cls");
        return 0;
    }else{
        printf("\n\n\t\t\t\t     ");
        printf("\033[1;32mKlik ENTER untuk mengulangi\033[0m");
        printf("\n\n\t\t\t\t  ");
        printf("\033[1;32mAnda memiliki %d kesempatan lagi!\033[0m",3-salah);
        getch();
        goto awal;
    }

    muka:

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
        printf("7. Exit");
        letak (26,21);
        printf("\033[1;32mMasukkan Pilihan Anda : \033[0m"); scanf("%d", &pilihan);

        switch(pilihan) {
            case 1: system ("cls");
                    tambah();
                    break;
            case 2: system ("cls");
                    lihat();
                    break;
            case 3: system ("cls");
                    urut();
                    break;
            case 4: system ("cls");
                    cari();
                    break;
            case 5: system ("cls");
                    hapus();
                    break;
            case 6: system ("cls");
                    edit();
                    break;
            case 7: return 0;
            default: letak(6,21); printf("Pilihan Tidak Tersedia");getch();
        }
    } while(pilihan != 7);

}
