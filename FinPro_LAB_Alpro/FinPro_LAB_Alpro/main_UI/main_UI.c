#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define CLEAN_SCREEN "cls"



struct data
{
    int hari;
    int bulan;
    int tahun;
    char nama[100];
    char jenisbarang[100];
    char namabarang[100];
    int jumlahbarang;
    int hargabarang;
    int totalharga;
};

struct waktu
{
    int hari;
    int bulan;
    int tahun;
};

struct struk
{
    struct waktu tanggal;
    char nama[100];
    char jenisBarang[100];
    char namaBarang[100];
    int jumlahBarang;
    int hargaBarang;
    int totalHarga;
};

struct header
{
    char tanggal[31];
    char nama[31];
    char jenisbarang[31];
    char namabarang[31];
    char jumlahbarang[31];
    char hargabarang[31];
    char totalharga[31];
}header;


struct barang
{
    char jenisBarang[100];
    char namaBarang[100];
    int stokBarang;
};


void eksport()
{
    char namaFile[100];
    FILE *file = fopen("Sales.txt", "r");
    if(file == NULL)
    {
        printf("Error\n");
        return;
    }
    struct struk struk[1000];
    char header[8][1000];
    int i=0;
    fscanf(file, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", header[0], header[1], header[2], header[3], header[4], header[5], header[6], header[7]);
    while(fscanf(file, "%d/%d/%d;%[^;];%[^;];%[^;];%d;%d;%d\n", &struk[i].tanggal.hari, &struk[i].tanggal.bulan, &struk[i].tanggal.tahun, struk[i].nama, struk[i].jenisBarang, struk[i].namaBarang, &struk[i].jumlahBarang, &struk[i].hargaBarang, &struk[i].totalHarga) != EOF)
    {
        i++;
    }
    fclose(file);
    printf("Masukkan nama file: ");
    scanf("%s", namaFile);
    printf("Pilih tipe file:\n");
    printf("1. .txt\n");
    printf("2. .csv\n");
    printf("Pilihan>> ");
    int pilihan;
    scanf("%d", &pilihan);
    if(pilihan == 1)
    {
        sprintf(namaFile, "%s.txt", namaFile);
    }
    else if(pilihan == 2)
    {
        sprintf(namaFile, "%s.csv", namaFile);
    }
    else
    {
        printf("Input salah\n");
        return;
    }
    FILE *file2 = fopen(namaFile, "w");
    if(file2 == NULL)
    {
        printf("Error\n");
        return;
    }
    fprintf(file2, "%s;%s;%s;%s;%s;%s;%s\n", header[0], header[1], header[2], header[3], header[4], header[5], header[6], header[7]);
    for(int j = 0; j<i; j++)
    {
        fprintf(file, "%d/%d/%d;%s;%s;%s;%d;%d;%d\n", struk[j].tanggal.hari, struk[j].tanggal.bulan, struk[j].tanggal.tahun, struk[j].nama, struk[j].jenisBarang, struk[j].namaBarang, struk[j].jumlahBarang, struk[j].hargaBarang, struk[j].totalHarga);
    }
    fclose(file2);
    printf("File berhasil dibuat\n");
}

void entryStruk()
{
    int pilihan;
    int k = 0;
    struct barang struk[4000];
    FILE *file10 = fopen("Database.txt", "r");
    if(file10 == NULL)
    {
        printf("Error\n");
    }
    fscanf(file10, "%[^;];%[^;];%[^\n]\n", header.jenisbarang, header.namabarang, header.jumlahbarang); // proses pembacaan database.txt
    while(fscanf(file10, "%[^;];%[^;];%d\n", struk[k].jenisBarang, struk[k].namaBarang, &struk[k].stokBarang) != EOF)
    {
        k++; 
    }
    fclose(file10);
    FILE *file3 = fopen("Sales.txt", "a");
    if(file3 == NULL)
    {
        printf("Error\n");
    }
    struct struk belanja;
    belanja.jumlahBarang = 0;
    printf("Masukkan Tahun Transaksi: ");
    scanf("%d", &belanja.tanggal.tahun);
    if(belanja.tanggal.tahun < 1)
    {
        printf("Tahun tidak valid\n");
        return;
    }
    printf("Masukkan Bulan Transaksi(dalam angka): ");
    scanf("%d", &belanja.tanggal.bulan);
    if(belanja.tanggal.bulan > 12 || belanja.tanggal.bulan < 1)
    {
        printf("Bulan tidak valid\n");
        return;
    }
    printf("Masukkan Tanggal Transaksi: ");
    scanf("%d", &belanja.tanggal.hari);
    if(belanja.tanggal.bulan == 2 && belanja.tanggal.hari > 29)
    {
        printf("Tanggal tidak valid\n");
        return;
    }
    else if(belanja.tanggal.bulan == 4 || belanja.tanggal.bulan == 6 || belanja.tanggal.bulan == 9 || belanja.tanggal.bulan == 11)
    {
        if(belanja.tanggal.hari > 30)
        {
            printf("Tanggal tidak valid\n");
            return;
        }
    }
    else if(belanja.tanggal.hari > 31)
    {
        printf("Tanggal tidak valid\n");
        return;
    }
    else if(belanja.tanggal.hari < 1)
    {
        printf("Tanggal tidak valid\n");
        return;
    }
    
    // if(belanja.tanggal.hari > 31 && belanja.tanggal.bulan != 2)
    // {
    //     printf("Tanggal tidak valid\n");
    //     return;
    // }
    // else if(belanja.tanggal.hari > 29 && belanja.tanggal.bulan == 2)
    // {
    //     printf("Tanggal tidak valid\n");
    //     return;
    // }
    // else if(belanja.tanggal.hari < 1)
    // {
    //     printf("Tanggal tidak valid\n");
    //     return;
    // }
    printf("Nama: ");
    scanf(" %[^\n]", belanja.nama); getchar();
    printf("Jenis barang: \n");
    printf("1. Frozen Food\n");
    printf("2. Minuman\n");
    printf("3. Peralatan\n");
    printf("4. Makanan Ringan\n");
    printf("5. Fresh Food\n");
    printf("6. Permen\n");
    printf("7. Other\n");
    printf("Pilih Jenis makanan (1-7): ");
    scanf(" %d", &pilihan);

    if(pilihan == 1)
    {
        strcpy(belanja.jenisBarang, "Frozen Food");
    }
    else if(pilihan == 2)
    {
        strcpy(belanja.jenisBarang, "Minuman");
    }
    else if(pilihan == 3)
    {
        strcpy(belanja.jenisBarang, "Peralatan");
    }
    else if(pilihan == 4)
    {
        strcpy(belanja.jenisBarang, "Makanan Ringan");
    }
    else if(pilihan == 5)
    {
        strcpy(belanja.jenisBarang, "Fresh Food");
    }
    else if(pilihan == 6)
    {
        strcpy(belanja.jenisBarang, "Permen");
    }
    else if(pilihan == 7)
    {
        strcpy(belanja.jenisBarang, "Other");
    }
    else
    {
        printf("input salah\n");
        printf("Program akan kembali ke menu utama\n");
        return;
    }
    // scanf(" %[^\n]", belanja.jenisBarang); getchar();
    printf("Nama barang: ");
    scanf(" %[^\n]", belanja.namaBarang); getchar();
    int ada = 0;
    for(int j = 0; j<k; j++) // kok ngga masuk loop nya yaa ?
    {
        if((strcmpi(belanja.namaBarang, struk[j].namaBarang) == 0) && (strcmpi(belanja.jenisBarang, struk[j].jenisBarang) == 0))
        {
            printf("\033[0;32m Stok %s saat ini : %d \033[0m\n", struk[j].namaBarang, struk[j].stokBarang);
            ada = 1;
            break;
        }
    }
    if(ada == 0)
    {
        printf("Barang tidak ada\n");
        return;
    }
    printf("Jumlah barang yang dibeli: ");
    scanf(" %d", &belanja.jumlahBarang);
    printf("Harga barang yang dibeli: ");
    scanf(" %d", &belanja.hargaBarang);
    belanja.totalHarga = belanja.jumlahBarang * belanja.hargaBarang;
    printf("Total harga: %d\n", belanja.totalHarga);
    fprintf(file3, "\n%d/%d/%d;%s;%s;%s;%d;%d;%d", belanja.tanggal.hari, belanja.tanggal.bulan, belanja.tanggal.tahun, belanja.nama, belanja.jenisBarang, belanja.namaBarang, belanja.jumlahBarang, belanja.hargaBarang, belanja.totalHarga);
    printf("Data berhasil di tambahkan\n"); // setelah di input akan di masukkan kedalam sales.txt
    fclose(file3);
    FILE *file4 = fopen("Database.txt", "r"); //setelah proses input struk selesai program akan membuka database.txt dan akan mengurangi jumlah stok barang yang ada di database.txt
    if(file4 == NULL)
    {
        printf("Error\n");
    }
    struct barang barang[4000];
    int i=0;
    fscanf(file4, "%[^;];%[^;];%[^\n]\n", header.jenisbarang, header.namabarang, header.jumlahbarang); // proses pembacaan database.txt
    while(fscanf(file4, "%[^;];%[^;];%d\n", barang[i].jenisBarang, barang[i].namaBarang, &barang[i].stokBarang) != EOF)
    {
        i++; 
    }
    fclose(file4);
    for(int j = 0; j<i; j++)
    {
        // printf("%s %s %d\n", barang[j].jenisBarang, barang[j].namaBarang, barang[j].stokBarang);
        // if(j==i-1)
        // {
        //     return;
        // }
        if(strcmpi(barang[j].namaBarang, belanja.namaBarang) == 0) // ngurangin stok barang berdasarkan barang yang dibeli
        {
            barang[j].stokBarang -= belanja.jumlahBarang;
            if(barang[j].stokBarang <= 0)
            {
                printf("Barang sudah habis");
            }
            printf("\033[0;32m Stok %s saat ini : %d \033[0m\n", struk[j].namaBarang, barang[j].stokBarang);
            break;
        }
        else if(j==i-1)
        {
            printf("barang tidak ada\n ");
            return;
        }
        else
        {
            continue;
        }
    }
    FILE *file5 = fopen("Database.txt", "w");
    if(file5 == NULL)
    {
        printf("Error\n");
    }
    fprintf(file5, "%s;%s;%s", header.jenisbarang, header.namabarang, header.jumlahbarang); // proses penulisan database.txt
    for(int j = 0; j<i; j++)
    {
        fprintf(file5, "\n%s;%s;%d", barang[j].jenisBarang, barang[j].namaBarang, barang[j].stokBarang);
    }
    fclose(file5); // proses pengurangan stok barang selesai
}
void entryBarang()
{
    struct header header;
    char jenisBarang[100];
    char namaBarang[100];
    int stokBarang, pilihan;
    FILE *file6 = fopen("Database.txt", "r");
    if(file6 == NULL)
    {
        printf("Error\n");
    }
    struct barang barang[1000];
    int i=0;
    fscanf(file6, "%[^;];%[^;];%[^\n]\n", header.jenisbarang, header.namabarang, header.jumlahbarang);
    while(fscanf(file6, "%[^;];%[^;];%d\n", barang[i].jenisBarang, barang[i].namaBarang, &barang[i].stokBarang) != EOF)
    {
        i++;
    }
    fclose(file6);
    printf("Jenis barang:\n"); // proses input barang
    printf("1. Frozen Food\n");
    printf("2. Minuman\n");
    printf("3. Peralatan\n");
    printf("4. Makanan Ringan\n");
    printf("5. Fresh Food\n");
    printf("6. Permen\n");
    printf("7. Other\n");
    printf("Pilih Jenis makanan (1-7): ");
    scanf(" %d", &pilihan);
    if(pilihan == 1)
    {
        strcpy(jenisBarang, "Frozen Food");
    }
    else if(pilihan == 2)
    {
        strcpy(jenisBarang, "Minuman");
    }
    else if(pilihan == 3)
    {
        strcpy(jenisBarang, "Peralatan");
    }
    else if(pilihan == 4)
    {
        strcpy(jenisBarang, "Makanan Ringan");
    }
    else if(pilihan == 5)
    {
        strcpy(jenisBarang, "Fresh Food");
    }
    else if(pilihan == 6)
    {
        strcpy(jenisBarang, "Permen");
    }
    else if(pilihan == 7)
    {
        strcpy(jenisBarang, "Other");
    }
    else
    {
        printf("input salah\n");
        printf("Program akan kembali ke menu utama\n");
        return;
    }
    printf("Nama barang: ");
    scanf(" %[^\n]", namaBarang); getchar();
    for(int j = 0; j<i; j++)
    {
        if((strcmpi(barang[j].namaBarang, namaBarang) == 0) && (strcmpi(barang[j].jenisBarang, jenisBarang) == 0))
        {
            printf("\033[0;32m Stok %s saat ini : %d \033[0m\n", barang[j].namaBarang, barang[j].stokBarang);
            break;
        }
        else if(j==i-1)
        {
            printf("barang tidak ada\n ");
            return;
        }
    }
    printf("Stok barang yang ditambahkan: ");
    scanf("%d", &stokBarang);
    for(int j = 0; j<i; j++)
    {
        
        // printf("%s %s %d\n", barang[j].jenisBarang, barang[j].namaBarang, barang[j].stokBarang);
        // if(j==i-1)
        // {
        //     return;
        // }
        if((strcmpi(barang[j].namaBarang, namaBarang) == 0) && (strcmpi(barang[j].jenisBarang, jenisBarang) == 0)) // proses mencari barang yang ingin di tambhakan stoknya
        {
            barang[j].stokBarang += stokBarang;
            printf("\033[0;32m Stok %s saat ini : %d \033[0m\n", barang[j].namaBarang, barang[j].stokBarang);
            break;
        }
        else if(j==i-1)
        {
            printf("barang tidak ada\n ");
            return;
        }
    }
    FILE *file7 = fopen("Database.txt", "w");
    if(file7 == NULL)
    {
        printf("Error\n");
    }
    fprintf(file7, "%s;%s;%s", header.jenisbarang, header.namabarang, header.jumlahbarang); // proses penulisan database.txt (menulis ulang
    for(int j = 0; j<i; j++)
    {
        fprintf(file7, "\n%s;%s;%d", barang[j].jenisBarang, barang[j].namaBarang, barang[j].stokBarang); // proses memasukkan barang yang sudah ditambahkan stoknya
    }
    printf("Data berhasil di tambahkan\n");
    fclose(file7);
}
void tambahBarang()
{
    char jenisBarang[100];
    char namaBarang[100];
    int stokBarang, pilihan;
    struct barang barang[1000];
    struct header header;
    FILE *file11 = fopen("Database.txt", "r");
    if(file11 == NULL)
    {
        printf("Error\n");
    }
    fscanf(file11, "%[^;];%[^;];%[^\n]\n", header.jenisbarang, header.namabarang, header.jumlahbarang);
    int i = 0;
    while(fscanf(file11, "%[^;];%[^;];%d\n", barang[i].jenisBarang, barang[i].namaBarang, &barang[i].stokBarang) != EOF)
    {
        i++;
    }
    fclose(file11);
    FILE *file8 = fopen("Database.txt", "a");
    if(file8 == NULL)
    {
        printf("Error\n");
    }
    printf("Jenis barang: \n");
    printf("1. Frozen Food\n");
    printf("2. Minuman\n");
    printf("3. Peralatan\n");
    printf("4. Makanan Ringan\n");
    printf("5. Fresh Food\n");
    printf("6. Permen\n");
    printf("7. Other\n");
    printf("Pilih Jenis makanan (1-7): ");
    scanf(" %d", &pilihan);

    if(pilihan == 1)
    {
        strcpy(jenisBarang, "Frozen Food");
    }
    else if(pilihan == 2)
    {
        strcpy(jenisBarang, "Minuman");
    }
    else if(pilihan == 3)
    {
        strcpy(jenisBarang, "Peralatan");
    }
    else if(pilihan == 4)
    {
        strcpy(jenisBarang, "Makanan Ringan");
    }
    else if(pilihan == 5)
    {
        strcpy(jenisBarang, "Fresh Food");
    }
    else if(pilihan == 6)
    {
        strcpy(jenisBarang, "Permen");
    }
    else if(pilihan == 7)
    {
        strcpy(jenisBarang, "Other");}
    else
    {
        printf("Jenis Barang Tidak Ada\n");
        return;
    }
    printf("Nama barang: ");
    scanf(" %[^\n]", namaBarang); getchar();
    for(int j = 0; j<i; j++)
    {
        if((strcmpi(barang[j].namaBarang, namaBarang) == 0) && (strcmpi(barang[j].jenisBarang, jenisBarang) == 0))
        {
            printf("Produk sudah ada dalam database\n", barang[j].namaBarang, barang[j].stokBarang);
            return;
        }
    }
    printf("Stok barang: ");
    scanf("%d", &stokBarang);
    fprintf(file8, "\n%s;%s;%d", jenisBarang, namaBarang, stokBarang);
    fclose(file8);
    printf("Data berhasil di tambahkan\n");
}

int sort()
{
    FILE *fp = fopen("Sales.txt", "r");
    if(fp == NULL)
    {
        printf("Error\n");
        return -1;
    }

    int n=0;
    int ch;
    
    
    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
        {
            n++;
        }
    }
    fseek(fp, 0, SEEK_SET);

    struct data file[n];
    struct data temp;
    
    fscanf(fp, " %[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);
    

    for(int a=0 ; a<n ; a++)
    {
        fscanf(fp, " %d/%d/%d;%[^;];%[^;];%[^;];%d;%d;%d\n", &file[a].hari, &file[a].bulan, &file[a].tahun, file[a].nama, file[a].jenisbarang, file[a].namabarang, &file[a].jumlahbarang, &file[a].hargabarang, &file[a].totalharga);
    }
    
    int i;

    
    char column[100];
    char choose[100];
    char stop[6];
    
    do
    {
        i=0;
        printf("List of column:\n");
        printf(MAG"1. Tanggal Transaksi\n");
        printf("2. Nama Pembeli\n");
        printf("3. Jenis Barang\n");
        printf("4. Nama Barang\n");
        printf("5. Jumlah Barang\n");
        printf("6. Harga Barang\n");
        printf("7. Total Pembayaran\n" RESET);
        printf(WHT"Which column do you want to sort? \n");
        printf(">> "RESET);
        scanf(" %[^\n]", column);
        if(strcmpi(column, "Tanggal Transaksi") == 0 || strcmp(column, "1") == 0)
        {
            printf(WHT"Want to sort ascending (asc) or descending (des)?\n>> " RESET);
            scanf(" %s", choose);
            if(strcmpi(choose, "asc") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(file[b].tahun > file[b+1].tahun)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                        else if(file[b].tahun == file[b+1].tahun)
                        {
                            if(file[b].bulan > file[b+1].bulan)
                            {
                                temp = file[b];
                                file[b] = file[b+1];
                                file[b+1] = temp;
                            }
                            else if(file[b].bulan == file[b+1].bulan)
                            {
                                if(file[b].hari > file[b+1].hari)
                                {
                                    temp = file[b];
                                    file[b] = file[b+1];
                                    file[b+1] = temp;
                                }
                            }
                        }
                    }
                }            
            }
            else if(strcmpi(choose, "des") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(file[b].tahun < file[b+1].tahun)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                        else if(file[b].tahun == file[b+1].tahun)
                        {
                            if(file[b].bulan < file[b+1].bulan)
                            {
                                temp = file[b];
                                file[b] = file[b+1];
                                file[b+1] = temp;
                            }
                            else if(file[b].bulan == file[b+1].bulan)
                            {
                                if(file[b].hari < file[b+1].hari)
                                {
                                    temp = file[b];
                                    file[b] = file[b+1];
                                    file[b+1] = temp;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                printf("Input not found\n\n");
                i=1;
            }
        }
        else if(strcmpi(column, "Nama Pembeli") == 0 || strcmp(column, "2") == 0)
        {
            printf(WHT"Want to sort ascending (asc) or descending (des)?\n>> "RESET);
            scanf(" %s", choose);
            if(strcmpi(choose, "asc") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(strcmpi(file[b].nama, file[b+1].nama) > 0)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }            
            }
            else if(strcmpi(choose, "des") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(strcmpi(file[b].nama, file[b+1].nama) < 0)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }
            }
            else
            {
                printf("Input not found\n\n");
                i=1;
            }
        }
        else if(strcmpi(column, "Jenis Barang") == 0 || strcmp(column, "3") == 0)
        {
            printf(WHT"Want to sort ascending (asc) or descending (des)\n>> "RESET);
            scanf(" %s", choose);
            if(strcmpi(choose, "asc") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(strcmpi(file[b].jenisbarang, file[b+1].jenisbarang) > 0)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }            
            }
            else if(strcmpi(choose, "des") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(strcmpi(file[b].jenisbarang, file[b+1].jenisbarang) < 0)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }
            }
            else
            {
                printf("Input not found\n\n");
                i=1;
            }
        }
        else if(strcmpi(column, "Nama Barang") == 0 || strcmp(column, "4") == 0)
        {
            printf(WHT"Want to sort ascending (asc) or descending (des)\n>> "RESET);
            scanf(" %s", choose);
            if(strcmpi(choose, "asc") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(strcmpi(file[b].namabarang, file[b+1].namabarang) > 0)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }            
            }
            else if(strcmpi(choose, "des") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(strcmpi(file[b].namabarang, file[b+1].namabarang) < 0)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }
            }
            else
            {
                printf("Input not found\n\n");
                i=1;
            }
        }
        else if(strcmpi(column, "Jumlah Barang") == 0 || strcmp(column, "5") == 0)
        {
            printf(WHT"Want to sort ascending (asc) or descending (des)\n>> "RESET);
            scanf(" %s", choose);
            if(strcmpi(choose, "asc") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(file[b].jumlahbarang > file[b+1].jumlahbarang)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }            
            }
            else if(strcmpi(choose, "des") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(file[b].jumlahbarang < file[b+1].jumlahbarang)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }
            }
            else
            {
                printf("Input not found\n\n");
                i=1;
            }
        }
        else if(strcmpi(column, "Harga Barang") == 0 || strcmp(column, "6") == 0)
        {
            printf(WHT"Want to sort ascending (asc) or descending (des)\n>> "RESET);
            scanf(" %s", choose);
            if(strcmpi(choose, "asc") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(file[b].hargabarang > file[b+1].hargabarang)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }            
            }
            else if(strcmpi(choose, "des") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++)
                    {
                        if(file[b].hargabarang < file[b+1].hargabarang)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }
            }
            else
            {
                printf("Input not found\n\n");
                i=1;
            }
        }
        else if(strcmpi(column, "Total Pembayaran") == 0 || strcmp(column, "7") == 0)
        {
            printf(WHT"Want to sort ascending (asc) or descending (des)\n>> "RESET);
            scanf(" %s", choose);
            if(strcmpi(choose, "asc") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++) // proses sorting
                    {
                        if(file[b].totalharga > file[b+1].totalharga)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }            
            }
            else if(strcmpi(choose, "des") == 0)
            {
                for(int a=0 ; a<n-1 ; a++)
                {
                    for(int b=0 ; b<n-1 ; b++) // proses sorting
                    {
                        if(file[b].totalharga < file[b+1].totalharga)
                        {
                            temp = file[b];
                            file[b] = file[b+1];
                            file[b+1] = temp;
                        }
                    }
                }
            }
            else
            {
                printf("Input not found\n\n");
                i=1;
            }
        }
        else
        {
            printf("Column not found\n\n");
            do
            {
                printf(WHT"Apakah masih ingin mencoba? (Ya = Y) (Tidak = T)\n>> "RESET);
                scanf(" %[^\n]", stop);
                if(strcmpi(stop, "Y")==0)
                {
                    i=1;
                }
                else if(strcmpi(stop, "T")==0)
                {
                    system("cls");
                    return 1;
                }
            }while(strcmpi(stop, "Y")!=0 && strcmpi(stop, "T")!=0);
        }
    }while(i==1);
    
    char choice[5];
    do
    {
        printf(WHT"How much data do you want to be displayed?\n"RESET);
        printf(MAG"1. All? (All)\n2. Few Number (FN)?\n"RESET);
        printf(WHT">> "RESET);
        scanf(" %s", &choice); getchar();
        if(strcmpi(choice,"all") == 0 || strcmp(choice, "1")==0)
        {
            printf(YEL"====================================================================================================================================\n"RESET);
            printf(CYN"%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n"RESET, header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
            printf(YEL"====================================================================================================================================\n"RESET);
            for(int a=0 ; a<n ; a++)
            {
                printf(CYN"%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n"RESET, file[a].hari, file[a].bulan, file[a].tahun, file[a].nama, file[a].jenisbarang, file[a].namabarang, file[a].jumlahbarang, file[a].hargabarang, file[a].totalharga);
            }
        }
        else if(strcmpi(choice, "FN") == 0 || strcmp(choice, "2")==0)
        {
            char check[10];
            long num;
            char *end;
            int checking;
            do
            {
                printf(WHT"Please input the amount of data want to be displayed!\n>> "RESET);
                fgets(check, sizeof(check), stdin);
                num = strtol(check, &end, 10);
                if(end == check || *end != '\n')
                {
                    printf(RED"Your Input is not an Integer\n\n"RESET);
                    checking=0;

                }
                else
                {
                    checking=1;
                    if(num > n)
                    {
                        printf(YEL"====================================================================================================================================\n"RESET);
                        printf(CYN"%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n"RESET, header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
                        printf(YEL"====================================================================================================================================\n"RESET);
                        for(int a=0 ; a<n ; a++)
                        {
                            printf(CYN"%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n"RESET, file[a].hari, file[a].bulan, file[a].tahun, file[a].nama, file[a].jenisbarang, file[a].namabarang, file[a].jumlahbarang, file[a].hargabarang, file[a].totalharga);
                        }
                        printf("\033[0;31m--Data hanya berjumlah %d!--\033[0m\n", n);
                
                    }
                    else
                    {
                        printf(YEL"====================================================================================================================================\n"RESET);
                        printf(CYN"%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n"RESET, header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
                        printf(YEL"====================================================================================================================================\n"RESET);
                        for(int a=0 ; a<num ; a++)
                        {
                            printf(CYN"%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n"RESET, file[a].hari, file[a].bulan, file[a].tahun, file[a].nama, file[a].jenisbarang, file[a].namabarang, file[a].jumlahbarang, file[a].hargabarang, file[a].totalharga);
                        }
                    }
                }
            }while(checking == 0); //check if num is a integer
        }
        else
        {
            printf("Input not found\n\n");
        }
    }while(strcmpi(choice, "all") != 0 && strcmpi(choice, "FN") != 0 && strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0);

    printf("-------------------------------------\n");
    printf("Tekan enter jika ingin kembali ke menu utama\n");
    while(getchar() != '\n');
    system("cls");
}   

void search(int choose, struct struk p[], struct header head[], char keyword[])
{

    char pilihan[2];
    char ya[2] = "y";
    FILE *f=fopen("Sales.txt", "r");
    if(f==NULL){
        printf("Error\n");
    }
    int i = 0;
    fscanf(f, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);
    while(fscanf(f, "%d/%d/%d;%[^;];%[^;];%[^;];%d;%d;%d\n", &p[i].tanggal.hari, &p[i].tanggal.bulan, &p[i].tanggal.tahun, p[i].nama, p[i].jenisBarang, p[i].namaBarang, &p[i].jumlahBarang, &p[i].hargaBarang, &p[i].totalHarga) != EOF)
    {
        i++;
    }
    
    int found=0;
    
    do
    {
        //SINI SORTING SEMUA, BERDASARKAN : 
        // 1. TANGGAL TRANSAKSI sama --> bulan --> tahun (kalau sudah tersortir, lanjut sortir nama pembeli)
        // 2. NAMA PEMBELI
        for(int a=0 ; a<i-1 ; a++)
        {
            for(int b=0 ; b<i-1 ; b++)
            {
                if(p[b].tanggal.tahun > p[b+1].tanggal.tahun)
                {
                    struct struk temp = p[b];
                    p[b] = p[b+1];
                    p[b+1] = temp;
                }
                else if(p[b].tanggal.tahun == p[b+1].tanggal.tahun)
                {
                    if(p[b].tanggal.bulan > p[b+1].tanggal.bulan)
                    {
                        struct struk temp = p[b];
                        p[b] = p[b+1];
                        p[b+1] = temp;
                    }
                    else if(p[b].tanggal.bulan == p[b+1].tanggal.bulan)
                    {
                        if(p[b].tanggal.hari > p[b+1].tanggal.hari)
                        {
                            struct struk temp = p[b];
                            p[b] = p[b+1];
                            p[b+1] = temp;
                        }
                        else if(p[b].tanggal.hari == p[b+1].tanggal.hari)
                        {
                            if(strcmpi(p[b].nama, p[b+1].nama) > 0)
                            {
                                struct struk temp = p[b];
                                p[b] = p[b+1];
                                p[b+1] = temp;
                            }
                        }
                    }
                }
            }
        }

    if(choose==1) 
    {
        char tanggal[50];
        int bulan;
        char tahun[50];
        char opsi[2];  

        printf("Masukkan tanggal penjualan : ");
        scanf("%s", tanggal);
        do
        {
            printf("PILIH BULAN PENJUALAN : \n");
            printf("1. Januari\n");
            printf("2. Februari\n");
            printf("3. Maret\n");
            printf("4. April\n");
            printf("5. Mei\n");
            printf("6. Juni\n");
            printf("7. Juli\n");
            printf("8. Agustus\n");
            printf("9. September\n");
            printf("10. Oktober\n");
            printf("11. November\n");
            printf("12. Desember\n");
            printf("Masukkan bulan penjualan [1-12] : ");
            scanf("%d", &bulan); 
            if(bulan < 1 || bulan > 12)
            {
                printf("\033[0;31m-Input tidak valid-\033[0m\n");
                printf("Apakah masih ada yang ingin anda cari ? [y/t]: ");
                scanf("%s", opsi);
                if(strcmpi(opsi, ya) == 0)
                {
                    continue;
                }
                else
                {
                    sleep(2);
                    system("cls");
                    return;
                }
            }
        } while(bulan < 1 || bulan > 12);
        printf("Masukkan tahun penjualan : ");  
        scanf("%s", tahun);
        printf("_____________________________________\n");
        for(int j=0; j<i; j++)
        {
            if(p[j].tanggal.hari == atoi(tanggal) && p[j].tanggal.bulan == bulan && p[j].tanggal.tahun == atoi(tahun))
            {
                found=1;
                break;
            }
        }
        
        if(found==1)
        {
            printf("\033[0;32m** Penjualan berdasarkan tanggal yang diminta ** \033[0m\n");
            printf("====================================================================================================================================\n");
            printf("%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n", header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
            printf("====================================================================================================================================\n");
            
            for(int j=0; j<i; j++)
            {
                if(p[j].tanggal.hari == atoi(tanggal) && p[j].tanggal.bulan == bulan && p[j].tanggal.tahun == atoi(tahun))
                {
                    printf("%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n",p[j].tanggal.hari,p[j].tanggal.bulan,p[j].tanggal.tahun, p[j].nama, p[j].jenisBarang, p[j].namaBarang, p[j].jumlahBarang, p[j].hargaBarang, p[j].totalHarga);
                }
            }
            // ini syntax buat jika tekan enter dia kembali menu utama
            char balik[2];
            printf("-------------------------------------\n");
            printf("Tekan enter jika ingin kembali ke menu utama\n");
            getchar();
            while(getchar() != '\n');
            system("cls");

            return;
        }
        else
        {
            printf("\033[0;31m-Data tidak ditemukan-\033[0m\n");
            printf("Apakah masih ada yang ingin anda cari ? [y/t]: ");
            scanf("%s", pilihan);
            if(strcmpi(pilihan, ya) == 0)
            {
                continue;
            }
            else
            {
                sleep(2);
                system("cls");
                return;
            }
        }
        
    }


    else if(choose==2) 
    {
        printf("Masukkan nama pembeli : ");
        scanf(" %[^\n]", keyword);
        printf("_____________________________________\n");
        for(int j=0; j<i; j++)
        {
            if(strcmpi(p[j].nama, keyword)==0)
            {
                found=1;
                break;
            }
        }
        
        if(found==1)
        {
            printf("\033[0;32m** Nama pembeli yang dicari ** \033[0m\n");
            printf("====================================================================================================================================\n");
            printf("%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n", header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
            printf("====================================================================================================================================\n");            
            for(int j=0; j<i; j++)
            {
                 if(strcmpi(p[j].nama, keyword)==0) 
                 {
                    printf("%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n",p[j].tanggal.hari,p[j].tanggal.bulan,p[j].tanggal.tahun, p[j].nama, p[j].jenisBarang, p[j].namaBarang, p[j].jumlahBarang, p[j].hargaBarang, p[j].totalHarga);
                 }
            }
            char balik[2];
            printf("-------------------------------------\n");
            printf("Tekan enter jika ingin kembali ke menu utama\n");
            getchar();
            while(getchar() != '\n');
            system("cls");

            return;
        }
        else if(found == 0)
        {
            printf("\033[0;31m-Data tidak ditemukan-\033[0m\n");
            printf("Apakah masih ada yang ingin anda cari ? [y/t]: ");
            scanf("%s", pilihan);
            if(strcmpi(pilihan, ya) == 0)
            {
                continue;
            }
            else
            {
                sleep(2);
                system("cls");
                return;
            }
        }
    }

    else if(choose==3)
    {
        int opsi;
        char keyword[100];
        do{
            printf("PILIH JENIS BARANG : \n");
            printf("1. Frozen Food\n");
            printf("2. Minuman\n");
            printf("3. Peralatan\n");
            printf("4. Makanan Ringan\n");
            printf("5. Fresh Food\n");
            printf("6. Permen\n");
            printf("7. Other\n");
            printf("Masukkan jenis barang : ");
            scanf("%d", &opsi);
            printf("_____________________________________\n");
            if(opsi < 1 || opsi > 7)
            {
                printf("\033[0;31m-Input tidak valid-\033[0m\n");
                printf("Apakah masih ada yang ingin anda cari ? [y/t]: ");
                scanf("%s", pilihan);
                if(strcmpi(pilihan, ya) == 0)
                {
                    continue;
                }
                else
                {
                    sleep(2);
                    system("cls");
                    return;
                }
            }
        } while(opsi < 1 || opsi > 7);

        if(opsi == 1)
        {
            strcpy(keyword, "Frozen Food");
        }
        else if(opsi == 2)
        {
            strcpy(keyword, "Minuman");
        }
        else if(opsi == 3)
        {
            strcpy(keyword, "Peralatan");
        }
        else if(opsi == 4)
        {
            strcpy(keyword, "Makanan Ringan");
        }
        else if(opsi == 5)
        {
            strcpy(keyword, "Fresh Food");
        }
        else if(opsi == 6)
        {
            strcpy(keyword, "Permen");
        }
        else if(opsi == 7)
        {
            strcpy(keyword, "Other");
        }
        else
        {
            printf("Jenis Barang Tidak Ada\n");
            return;
        }

        for(int j=0; j<i; j++)
        {
            if(strcmp(p[j].jenisBarang, keyword) == 0)
            {
                found=1;
                break;
            }
            
            
        }
        
        if(found==1)
        {
            printf("\033[0;32m** Data jenis barang yang dicari ** \033[0m\n");
            printf("====================================================================================================================================\n");
            printf("%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n", header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
            printf("====================================================================================================================================\n");            
            for(int j=0; j<i; j++)
            {
                 if(strcmpi(p[j].jenisBarang, keyword) == 0) 
                 {
                    printf("%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n",p[j].tanggal.hari,p[j].tanggal.bulan,p[j].tanggal.tahun, p[j].nama, p[j].jenisBarang, p[j].namaBarang, p[j].jumlahBarang, p[j].hargaBarang, p[j].totalHarga);
                 }
            }
            char balik[2];
            printf("-------------------------------------\n");
            printf("Tekan enter jika ingin kembali ke menu utama\n");
            getchar();
            while(getchar() != '\n');
            system("cls");

            return;
        }
        else
        {
            printf("\033[0;31m-Data tidak ditemukan-\033[0m\n");
            printf("Apakah masih ada yang ingin anda cari ? [y/t]: ");
            scanf("%s", pilihan);
            if(strcmpi(pilihan, ya) == 0)
            {
                continue;
            }
            else
            {
                sleep(2);
                system("cls");
                return;
            }
        }
    }

    else if(choose==4){ 
        printf("Masukkan nama barang : ");
        scanf(" %[^\n]", keyword);
        printf("_____________________________________\n");

        for(int j=0; j<i; j++)
        {
            if(strcmpi(p[j].namaBarang, keyword)==0)
            {
                found=1;
                break;
            }
        }
        
        if(found==1)
        {
            printf("\033[0;32m** Data nama barang yang dicari **\033[0m\n");
            printf("====================================================================================================================================\n");
            printf("%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n", header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
            printf("====================================================================================================================================\n");            
            for(int j=0; j<i; j++)
            {
                 if(strcmpi(p[j].namaBarang, keyword)==0) 
                 {
                    printf("%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n",p[j].tanggal.hari,p[j].tanggal.bulan,p[j].tanggal.tahun, p[j].nama, p[j].jenisBarang, p[j].namaBarang, p[j].jumlahBarang, p[j].hargaBarang, p[j].totalHarga);
                 }
            }
            char balik[2];
            printf("-------------------------------------\n");
            printf("Tekan enter jika ingin kembali ke menu utama\n");
            getchar();
            while(getchar() != '\n');
            system("cls");

            return;
        }
        else
        {
            char ya[2] = "y";
            printf("\033[0;31m-Data tidak ditemukan-\033[0m\n");
            printf("Apakah masih ada yang ingin anda cari ? [y/t]: ");
            scanf("%s", pilihan);
            if(strcmpi(pilihan, ya) == 0)
            {
                continue;
            }
            else
            {
                sleep(2);
                system("cls");
                return;
            }
        }
    }

    else if(choose==5) 
    {
            int max=0;
            int jumlahTerbesar = 0;
            int baris;
            struct struk terbesar[1000];
            for(int j = 0; j<i; j++)
            {
                if(p[j].jumlahBarang > max)
                {
                    max = p[j].jumlahBarang;
                }
            }
            for(int j = 0; j<i; j++)
            {
                if(p[j].jumlahBarang == max)
                {
                    terbesar[jumlahTerbesar] = p[j];
                    jumlahTerbesar++;
                }
            }
            
            printf("Menampilkan baris data sebanyak[angka] : ");
            scanf("%d", &baris);
            printf("\n");

            printf("\033[0;32m** Barang yang paling banyak terjual ** \033[0m\n");            

    
            printf("====================================================================================================================================\n");
            printf("%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n", header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
            printf("====================================================================================================================================\n");            
            if(baris > jumlahTerbesar)
            {
                for(int j = 0; j<jumlahTerbesar; j++)
                {
                    printf("%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n",terbesar[j].tanggal.hari,terbesar[j].tanggal.bulan,terbesar[j].tanggal.tahun, terbesar[j].nama, terbesar[j].jenisBarang, terbesar[j].namaBarang, terbesar[j].jumlahBarang, terbesar[j].hargaBarang, terbesar[j].totalHarga);\
                }
                printf("\ndata hanya ada sebanyak %d\n", jumlahTerbesar);
            }
            else
            {
                for(int j = 0; j<baris; j++)
                {
                    printf("%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n",terbesar[j].tanggal.hari,terbesar[j].tanggal.bulan,terbesar[j].tanggal.tahun, terbesar[j].nama, terbesar[j].jenisBarang, terbesar[j].namaBarang, terbesar[j].jumlahBarang, terbesar[j].hargaBarang, terbesar[j].totalHarga);
                }
            }
            // for(int j=0; j<baris; j++) 
            // {
            //     // if(p[j].jumlahBarang==max)
            //     // {
            //     //     printf("%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n",p[j].tanggal.hari,p[j].tanggal.bulan,p[j].tanggal.tahun, p[j].nama, p[j].jenisBarang, p[j].namaBarang, p[j].jumlahBarang, p[j].hargaBarang, p[j].totalHarga);
            //     // }
            // }
        }

    else if(choose==6) 
    {
        int min, max;
        printf("Masukkan kisaran harga barang (min-max): ");
        scanf("%d-%d", &min, &max);
        printf("_____________________________________\n");
        for(int j=0; j<i; j++)
        {
            if(p[j].hargaBarang >=min && p[j].hargaBarang <=max)
            { //p=pembeli
                found=1;
                break;
            }
        }
        if(found==1)
        {
            printf("\033[0;32m** Kisaran harga barang yang anda cari ** \033[0m\n");
            printf("====================================================================================================================================\n");
            printf("%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n", header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
            printf("====================================================================================================================================\n");            
            for(int j=0; j<i; j++)
            {
                if(p[j].hargaBarang >=min && p[j].hargaBarang <=max)
                {
                    printf("%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n",p[j].tanggal.hari,p[j].tanggal.bulan,p[j].tanggal.tahun, p[j].nama, p[j].jenisBarang, p[j].namaBarang, p[j].jumlahBarang, p[j].hargaBarang, p[j].totalHarga);
                }
            }
            char balik[2];
            printf("-------------------------------------\n");
            printf("Tekan enter jika ingin kembali ke menu utama\n");
            getchar();
            while(getchar() != '\n');
            system("cls");

            return;
          
        }
        
        else
        {
            printf("\033[0;31m-Data tidak ditemukan-\033[0m\n");
            printf("Apakah masih ada yang ingin anda cari ? [y/t]: ");
            scanf("%s", pilihan);
            if(strcmpi(pilihan, ya) == 0)
            {
                continue;
            }
            else
            {
                sleep(2);
                system("cls");
                return;
            }
        }
    }

        else if(choose==7) 
        {
            int min, max;
            printf("Masukkan kisaran total harga (min-max): ");
            scanf("%d-%d", &min, &max);
            printf("_____________________________________\n");

            for(int j=0; j<i; j++)
            {
                if(p[j].totalHarga >=min && p[j].totalHarga <=max)
                {
                    found=1;
                    break;
                }
            }
            if(found==1)
            {
                printf("\033[0;32m** Total harga yang anda cari ** \033[0m\n");
                printf("====================================================================================================================================\n");
                printf("%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n", header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
                printf("====================================================================================================================================\n");            
                for(int j=0; j<i; j++)
                {
                    if(p[j].totalHarga >=min && p[j].totalHarga <=max)
                    {
                        printf("%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n",p[j].tanggal.hari,p[j].tanggal.bulan,p[j].tanggal.tahun, p[j].nama, p[j].jenisBarang, p[j].namaBarang, p[j].jumlahBarang, p[j].hargaBarang, p[j].totalHarga);
                    }
                }
                char balik[2];
                printf("-------------------------------------\n");
                printf("Tekan enter jika ingin kembali ke menu utama\n");
                getchar();
                while(getchar() != '\n');
                system("cls");

                return;
            }
            else
            {
                printf("\033[0;31m-Data tidak ditemukan-\033[0m\n");
                printf("Apakah masih ada yang ingin anda cari ? [y/t]: ");
                scanf("%s", pilihan);
                if(strcmpi(pilihan, ya) == 0)
                {
                    continue;
                }
                else
                {
                    printf("Program akan kembali ke menu utama\n");
                    sleep(2);
                    system("cls");
                }
            }
        }
    } while(strcmpi(pilihan, ya) == 0);
    char balik[2];
    printf("-------------------------------------\n");
    printf("Tekan entar jika ingin kembali ke menu utama\n");
    getchar();
    while(getchar() != '\n');
    system("cls");
}

void searchStok()
{
    char pilihan[2];
    char ya[2] = "y";
    FILE *file8 = fopen("Database.txt", "r");
    if(file8 == NULL)
    {
        printf("Error\n");
    }
    struct barang barang[1000];
    int i=0;
    fscanf(file8, "%[^;];%[^;];%[^\n]\n", header.jenisbarang, header.namabarang, header.jumlahbarang);
    while(fscanf(file8, "%[^;];%[^;];%d\n", barang[i].jenisBarang, barang[i].namaBarang, &barang[i].stokBarang) != EOF)
    {
        i++;
    }
    fclose(file8);
    int min, max;
    int ada = 0;
    do
    {
 
    printf("Masukkan kisaran stock (min-max): ");
    scanf("%d-%d", &min, &max);
    for(int j = 0; j<i; j++)
    {
        if(barang[j].stokBarang >= min && barang[j].stokBarang <= max)
        {
            ada = 1;
            break;
        }
        else
        {
            continue;
        }
    }
    if(ada == 1)
    {
        printf("==========================================================\n");
        printf("%-20s | %-15s | %-15s \n", header.jenisbarang, header.namabarang, header.jumlahbarang);//print header file
        printf("==========================================================\n");
        for(int j = 0; j<i; j++)
        {
            if(barang[j].stokBarang >= min && barang[j].stokBarang <= max)
            {
                printf("%-22s %-17s %-20d\n", barang[j].jenisBarang, barang[j].namaBarang, barang[j].stokBarang);
                ada = 1;
            }
            else
            {
                continue;
            }
        }
        return;

    }
    else if(ada == 0)
    {
        printf("Barang tidak ada\n");
        printf("Apakah masih ada yang ingin anda cari ? [y/t]: ");
        scanf("%s", pilihan);
        if(strcmpi(pilihan, ya) == 0)
        {
            continue;
        }
        else
        {
            return;
        }
    }
    } while(strcmpi(pilihan, ya) == 0);
}

void garis()
{
    
    printf("    \033[1;33m***********************\n");
    printf("    *---------Menu--------*\n");
    printf("    ***********************\n");
}

int menu()
{
    int i;
    garis();
    printf("1. Entry data\n");
    printf("2. Sortir data\n");
    printf("3. Search data\n");
    printf("4. Eksport data\n");
    printf("5. Display data\n");
    printf("6. Exit\n");
    printf(">> \033[0m");
    
    return i;

    printf("-----------------------\n");
}

int display()
{
    FILE *file13 = fopen("Sales.txt", "r");
    if(file13 == NULL)
    {
        printf("Error\n");
    }
    struct struk struk[1000];
    struct header header;
    int i=0;
    fscanf(file13, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);
    while(fscanf(file13, "%d/%d/%d;%[^;];%[^;];%[^;];%d;%d;%d\n", &struk[i].tanggal.hari, &struk[i].tanggal.bulan, &struk[i].tanggal.tahun, struk[i].nama, struk[i].jenisBarang, struk[i].namaBarang, &struk[i].jumlahBarang, &struk[i].hargaBarang, &struk[i].totalHarga) != EOF)
    {
        i++;
    }
    printf(WHT"Berapa banyak data yang ingin ditampilkan: \n>> "RESET);

    // check input user int / char
    char check[10];
    int display;
    char *end;
    
    fgets(check, sizeof(check), stdin);
    display = strtol(check, &end, 10);
    if(end == check || *end != '\n')
    {
        printf(RED"Your Input is not an Integer\n\n"RESET);
        return 0;
    }
    else
    // check kalo user benar int


    fclose(file13);
    printf(YEL"====================================================================================================================================\n"RESET);
    printf(BLU"%-20s | %-15s | %-15s | %-15s | %-15s | %-15s | %-20s\n"RESET, header.tanggal, header.nama, header.jenisbarang, header.namabarang, header.jumlahbarang, header.hargabarang, header.totalharga);//print header file
    printf(YEL"====================================================================================================================================\n"RESET);
    if(display > i)
    {
        for(int j = 0; j<i; j++)
        {
            printf(BLU"%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n"RESET,struk[j].tanggal.hari,struk[j].tanggal.bulan,struk[j].tanggal.tahun, struk[j].nama, struk[j].jenisBarang, struk[j].namaBarang, struk[j].jumlahBarang, struk[j].hargaBarang, struk[j].totalHarga);
        }
        printf("\033[0;31m--Data hanya berjumlah %d!--\033[0m\n", i);
    }
    else
    {
        for(int j = 0; j<display; j++)
        {
            printf(BLU"%2d/%2d/%-16d %-17s %-17s %-17s %-17d %-17d %-20d\n"RESET,struk[j].tanggal.hari,struk[j].tanggal.bulan,struk[j].tanggal.tahun, struk[j].nama, struk[j].jenisBarang, struk[j].namaBarang, struk[j].jumlahBarang, struk[j].hargaBarang, struk[j].totalHarga);
        }
    }
    printf("-------------------------------------\n");
    printf("Tekan enter jika ingin kembali ke menu utama\n");
    while(getchar() != '\n');
    system("cls");

}

int main()
{
    char check[10];
    long i;
    char *end;
    int checking;
    do
    {
        checking = 1;
        menu();
        fgets(check, sizeof(check), stdin);
        i = strtol(check, &end, 10);
        if(end == check || *end != '\n')
        {
            printf(RED"Your Input is not an Integer\n\n"RESET);
            checking=0;
        }
        else
        {
            checking=1;
        }
        switch (i)
        {
        case(1):
        {
            int pilihan;
            do
            {
                printf("1. Entry data struk\n");
                printf("2. tambah stok produk sudah ada\n");
                printf("3. tambah produk baru\n");
                printf("Pilihan >> ");
                scanf("%d", &pilihan);
                if(pilihan == 1)
                {
                    entryStruk();
                }
                else if(pilihan == 2)
                {
                    entryBarang();
                }
                else if(pilihan == 3)
                {
                    tambahBarang();
                }
                else
                {
                    printf("Pilihan tidak tersedia\n");
                }
            }
            while(pilihan != 1 && pilihan != 2 && pilihan != 3); 
            printf("-------------------------------------\n");
            printf("Tekan enter jika ingin kembali ke menu utama\n");
            getchar();
            getchar();
            system("cls");
            break;
        }
        case(2): sort(); break;
        case(3): 
        {
            struct struk p[100];
            struct header head[100];
           
            int choose;
            char keyword[100];
            printf("1. Tanggal Transaksi\n");
            printf("2. Nama Pembeli\n");
            printf("3. Jenis Barang\n");
            printf("4. Nama Barang\n");
            printf("5. Jumlah Barang paling banyak terjual\n");
            printf("6. Kisaran Harga Barang\n");
            printf("7. Kisaran Total Pembayaran\n");
            printf("8. Kisaran Stock\n");
            printf("_____________________________________\n");
            printf("Pilih kategori yang ingin dicari[1-8]: ");
            scanf("%d", &choose); // 1
            
            if(choose == 8)
            {
                searchStok();
                printf("-------------------------------------\n");
                printf("Tekan enter jika ingin kembali ke menu utama\n");
                getchar();
                getchar();
                system("cls");
            }
            else if(choose == 1 || choose == 2 || choose == 3 || choose == 4 || choose == 5 || choose == 6 || choose == 7)
            {
                search(choose, p, head, keyword); 
        
            }
            else
            {
                printf("Pilihan tidak tersedia\n");
                printf("---program akan kembali ke menu utama---\n");
                sleep(2);
                system("cls");
            }
            break; 
        }
         
        case(4):
        {
            eksport();
            printf("-------------------------------------\n");
            printf("Tekan enter jika ingin kembali ke menu utama\n");
            getchar();
            while(getchar() != '\n');
            system("cls");
            break;
        }
        case(5):
        {
            display();
            // getchar();
            // while(getchar() != '\n');
            // system("cls");
            break;
        }
        case(6): 
        // printf("\n");
        printf("\033[0;36m--------------------------------------------\n");
        printf("Terima kasih telah menggunakan program ini\n"); 
        printf("--------------------------------------------\033[0m\n");
        break;
        default:
            break;
        }

    } while(i != 6 || checking == 0);

    sleep(2);
    system("cls");
    return 0;
}