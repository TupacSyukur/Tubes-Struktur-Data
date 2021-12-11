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
//
void printSiswa(listSiswa P);
void printMatkul(listMatkul P);
void printParent(listMatkul P);
//
string menu();

adrSiswa find_siswa(listSiswa S, string data);
adrMatkul find_matkul(listMatkul M, string data);

// ETC
void insertSiswa(listSiswa &S);
void insertMatkul(listMatkul &M);
void addSiswa2Mk(listMatkul &M, listSiswa &S);

#endif // init_H_INCLUDED