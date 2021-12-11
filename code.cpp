#include "init.h"

#include <iostream>

using namespace std;
//
void create_list_siswa(listSiswa &S)
{
    first(S) = NULL;
    last(S) = NULL;
}

void create_list_matkul(listMatkul &M)
{
    first(M) = NULL;
    last(M) = NULL;
}

//
adrSiswa newSiswa(info_siswa x)
{
    adrSiswa p = new elmSiswa;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
adrMatkul newMatkul(info_matkul x)
{
    adrMatkul p = new elmMatkul;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    p->goRelation = NULL;
    return p;
}
adrRelation newRelation(adrSiswa x)
{
    adrRelation p = new elmRelation;
    info(p) = x;
    next(p) = NULL;
    return p;
}
// Jadiin Circular Double Linked list (dengan last)
void insert_first_siswa(listSiswa &P, adrSiswa p)
{
    if (first(P) == NULL)
    {
        first(P) = p;
        last(P) = p;
        next(p) = p;
        prev(p) = p;
    }
    else
    {
        next(p) = first(P);
        prev(first(P)) = p;
        next(last(P)) = p;
        prev(p) = last(P);
        first(P) = p;
    }
}
// Jadiin Circular Double Linked list (dengan last)
void insert_first_matkul(listMatkul &P, adrMatkul p)
{
    if (first(P) == NULL)
    {
        first(P) = p;
        last(P) = p;
        next(p) = p;
        prev(p) = p;
    }
    else
    {
        next(p) = first(P);
        prev(first(P)) = p;
        next(last(P)) = p;
        prev(p) = last(P);
        first(P) = p;
    }
}
// Single Linked List (tanpa last)
void insert_relation(listMatkul &M, adrMatkul &m, adrRelation p)
{
    if (first(M) != NULL)
    {
        if (m->goRelation == NULL)
        {
            m->goRelation = p;
        }
        else
        {
            adrRelation c = m->goRelation;
            while (next(c) != NULL)
            {
                c = next(c);
            }
            next(c) = p;
        }
    }
}
// Double Linked List (dengan last)
void printSiswa(listSiswa P)
{
    if (first(P) != NULL)
    {
        adrSiswa p = first(P);
        cout << info(p).nama_siswa << " | ";
        p = next(p);
        cout << endl;
        while (p != first(P))
        {
            cout << info(p).nama_siswa << " | ";
            p = next(p);
        }
        cout << endl;
    }
    else
    {
        cout << "Empty";
    }
}
// Double Linked List (dengan last)
void printMatkul(listMatkul P)
{
    if (first(P) != NULL)
    {
        adrMatkul p = first(P);
        cout << info(p).nama_matkul << " | ";
        p = next(p);
        cout << endl;
        while (p != NULL)
        {
            cout << info(p).nama_matkul << " | ";
            p = next(p);
        }
        cout << endl;
    }
    else
    {
        cout << "Empty";
    }
}

// Single Linked List (without last)
void printRelation(listMatkul P)
{
    if (first(P) != NULL)
    {
        printMatkul(P);
        cout << "Choose : ";
        string t;
        cin >> t;
        adrMatkul m = find_matkul(P, t);
        if (m != NULL)
        {
            adrRelation c = m->goRelation;
            while (c != NULL)
            {
                cout << info(c)->info.nama_siswa << " | ";
                c = next(c);
            }
        }
    }
    cout << endl;
}

void addSiswa2Mk(listMatkul &M, listSiswa &S)
{
    if (first(M) != NULL)
    {
        string t;
        printMatkul(M);
        cout << "Choose Matkul : ";
        cin >> t;
        adrMatkul m = find_matkul(M, t);
        if (m != NULL && info(m).total != info(m).max)
        {
            adrSiswa s;
            adrRelation p;

            cout << "1. Masukan siswa yang sudah ada\n2. Masukan siswa yang baru\nChoose : ";
            cin >> t;
            if (t == "1")
            {
                printSiswa(S);
                cout << "Choose Siswa : ";
                cin >> t;
                s = find_siswa(S, t);
                if (s != NULL)
                {
                    p = newRelation(s);

                    insert_relation(M, m, p);
                    info(m).total++;
                }
            }
            else
            {
                info_siswa is;
                cout << "Nama Siswa : ";
                cin >> is.nama_siswa;
                s = newSiswa(is);
                insert_first_siswa(S, s);
                p = newRelation(s);

                insert_relation(M, m, p);
                info(m).total++;
            }
        }
        else
        {
            cout << "Gagal\n";
        }
    }
    cout << endl;
}

string menu()
{
    string n = "0";
    cout << "1. Insert Siswa\n2. Insert Matkul\n3. Insert Siswa ke Matkul\n";
    cout << "4. Edit Siswa\n5. Edit Matkul\n6. Delete Siswa\n";
    cout << "7. Delete Matkul\n8. Delete Siswa dalam Matkul\n9. Print Siswa\n";
    cout << "10. Print Matkul\n11. Print Siswa dalam Matkul\n12. Cari Siswa\n13. Cari Matkul\n14. Cari Siswa dalam Matkul\n0. Exit\nChoose : ";
    cin >> n;
    return n;
}

// Circular Double Linked List (dengan last)
adrSiswa find_siswa(listSiswa S, string data)
{
    adrSiswa p = NULL;
    if (first(S) != NULL)
    {
        bool cek;
        p = first(S);
        if (info(p).nama_siswa == data)
        {
            cek = false;
        }
        else
        {
            cek = true;
        }
        p = next(p);
        while (p != first(S) && cek)
        {
            if (info(p).nama_siswa != data)
            {
                p = next(p);
            }
            else
            {
                cek = false;
            }
        }
        if (cek)
            p = NULL;
    }
    return p;
}

// Circular Double Linked List (dengan last)
adrMatkul find_matkul(listMatkul M, string data)
{
    adrMatkul p = NULL;
    if (first(M) != NULL)
    {
        bool cek;
        p = first(M);
        if (info(p).nama_matkul == data)
        {
            cek = false;
        }
        else
        {
            cek = true;
        }
        p = next(p);
        while (p != first(M) && cek)
        {
            if (info(p).nama_matkul != data)
            {
                p = next(p);
            }
            else
            {
                cek = false;
            }
        }
        if (cek)
            p = NULL;
    }
    return p;
}

void insertSiswa(listSiswa &P)
{
    adrSiswa s;
    info_siswa is;
    string t;
    cout << "1. Insert First\n2. Insert Last\n3. Insert After\nChoose : ";
    cin >> t;
    if (t == "1")
    {
        cout << "Nama               : ";
        cin >> is.nama_siswa;
        cout << "NIM                : ";
        cin >> is.nim;
        cout << "Kelas              : ";
        cin >> is.kelas;
        cout << "Jenis Mahasiswa    : ";
        cin >> is.jenis;
        s = newSiswa(is);
        insert_first_siswa(P, s);
    }
    else if (t == "2")
    {
        cout << "Nama               : ";
        cin >> is.nama_siswa;
        cout << "NIM                : ";
        cin >> is.nim;
        cout << "Kelas              : ";
        cin >> is.kelas;
        cout << "Jenis Mahasiswa    : ";
        cin >> is.jenis;
        s = newSiswa(is);
        //-----
    }
    else if (t == "3")
    {
        printSiswa(P);
        cout << "Where do you want to input : ";
        cin >> t;
        s = find_siswa(P, t);
        //-----
    }
    else
    {
        cout << "\nGagal";
    }
    cout << endl;
}

void insertMatkul(listMatkul &M)
{
    adrMatkul m;
    info_matkul im;
    string t;
    cout << "1. Insert First\n2. Insert Last\n3. Insert After\nChoose : ";
    cin >> t;
    if (t == "1")
    {
        im.total = 0;
        cout << "Nama Mata Kuliah   : ";
        cin >> im.nama_matkul;
        cout << "Kelas yang Diajar  : ";
        cin >> im.kelas_matkul;
        cout << "Kuota Maksimal     : ";
        cin >> im.max;
        cout << "Jenis Mahasiswa    : ";
        cin >> im.jenis;
        m = newMatkul(im);
        insert_first_matkul(M, m);
    }
    else if (t == "2")
    {
        im.total = 0;
        cout << "Nama Mata Kuliah   : ";
        cin >> im.nama_matkul;
        cout << "Kelas yang Diajar  : ";
        cin >> im.kelas_matkul;
        cout << "Kuota Maksimal     : ";
        cin >> im.max;
        cout << "Jenis Mahasiswa    : ";
        cin >> im.jenis;
        m = newMatkul(im);
        //-----
    }
    else if (t == "3")
    {
        printMatkul(M);
        cout << "Where do you want to input : ";
        cin >> t;
        m = find_matkul(M, t);
    }
    else
    {
        cout << "\nGagal";
    }
    cout << endl;
}