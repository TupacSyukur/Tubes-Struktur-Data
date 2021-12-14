#ifndef init_H_INCLUDED
#define init_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(P) ((P).first)
#define last(P) ((P).last)

struct matkul
{
    string nama_matkul, kelas_matkul, jenis;
    int total, max;
};

struct siswa
{
    string nama_siswa, nim, kelas, jenis;
};

typedef siswa info_siswa;
typedef matkul info_matkul;

typedef struct elmSiswa *adrSiswa;
typedef struct elmMatkul *adrMatkul;

// typedef struct elmParent *adrParent;
typedef struct elmRelation *adrRelation;

// List Relasi (element relasi)
struct elmRelation
{
    adrSiswa info;
    adrRelation next;
};

struct elmSiswa
{
    info_siswa info;
    adrSiswa next;
    adrSiswa prev;
};

struct elmMatkul
{
    info_matkul info;
    adrMatkul next;
    adrMatkul prev;
    adrRelation goRelation;
};

struct listMatkul
{
    adrMatkul first;
    adrMatkul last;
};

struct listSiswa
{
    adrSiswa first;
    adrSiswa last;
};

//
void create_list_siswa(listSiswa &S);
void create_list_matkul(listMatkul &M);

//
adrSiswa newSiswa(info_siswa x);
adrMatkul newMatkul(info_matkul x);
adrRelation newRelation(adrSiswa x);
//
void insert_first_siswa(listSiswa &P, adrSiswa p);
void insert_first_matkul(listMatkul &P, adrMatkul p);
void insert_last_matkul(listMatkul &P, adrMatkul p);
void insert_last_siswa(listSiswa &P, adrSiswa p);
void insert_after_siswa(listSiswa &P, adrSiswa p, adrSiswa prec);
void insert_after_matkul(listMatkul &P, adrMatkul p, adrMatkul prec);
// Delete
adrRelation delete_first_relation(listMatkul &M, adrMatkul &m);
adrRelation delete_last_relation(listMatkul &M, adrMatkul &m);
adrRelation delete_after_relation(listMatkul &M, adrMatkul &m, adrRelation prec);
adrRelation delete_relation(listMatkul &M, adrMatkul &m);
adrRelation delete_relation_(listMatkul &M, adrMatkul &m);
adrMatkul delete_first_matkul(listMatkul &M);
adrMatkul delete_last_matkul(listMatkul &M);
adrMatkul delete_after_matkul(listMatkul &M, adrMatkul prec);
adrMatkul delete_matkul(listMatkul &M);
adrSiswa delete_first_siswa(listSiswa &S);
adrSiswa delete_last_siswa(listSiswa &S);
adrSiswa delete_after_siswa(listSiswa &S, adrSiswa prec);
adrSiswa delete_siswa(listSiswa &S, listMatkul &M);
//
void printSiswa(listSiswa P);
void printMatkul(listMatkul P);
void printRelation(listMatkul P, adrMatkul m);
//
string menu();
adrSiswa find_siswa(listSiswa S, string data);
adrMatkul find_matkul(listMatkul M, string data);
void find_siswa_in_matkul(listSiswa S, listMatkul M);
adrRelation find_Relasi(adrMatkul m, string t);

// ETC
void insertSiswa(listSiswa &S);
void insertMatkul(listMatkul &M);
void addSiswa2Mk(listMatkul &M, listSiswa &S);

#endif // init_H_INCLUDED