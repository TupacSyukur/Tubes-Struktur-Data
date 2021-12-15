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
void insert_last_siswa(listSiswa &P, adrSiswa p)
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
        next(last(P)) = p;
        next(p) = first(P);
        prev(p) = last(P);
        prev(first(P)) = p;
        last(P) = p;
    }
}

void insert_after_siswa(listSiswa &P, adrSiswa p, adrSiswa prec)
{
    if (first(P) != NULL)
    {
        if (next(prec) == first(P))
        {
            insert_last_siswa(P, p);
        }
        else
        {
            adrSiswa q = next(prec);
            next(prec) = p;
            prev(p) = prec;
            next(p) = q;
            prev(q) = p;
        }
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

void insert_last_matkul(listMatkul &P, adrMatkul p)
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
        next(last(P)) = p;
        next(p) = first(P);
        prev(p) = last(P);
        prev(first(P)) = p;
        last(P) = p;
    }
}

void insert_after_matkul(listMatkul &P, adrMatkul p, adrMatkul prec)
{
    if (first(P) != NULL)
    {
        if (next(prec) == first(P))
        {
            insert_last_matkul(P, p);
        }
        else
        {
            adrMatkul q = next(prec);
            next(prec) = p;
            prev(p) = prec;
            next(p) = q;
            prev(q) = p;
        }
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

// Delete Section

// Delete Relation
adrRelation delete_first_relation(listMatkul &M, adrMatkul &m)
{
    adrRelation p = m->goRelation;
    m->goRelation = next(p);
    next(p) = NULL;
    info(m).total--;
    return p;
}

adrRelation delete_last_relation(listMatkul &M, adrMatkul &m)
{
    adrRelation p = m->goRelation;
    while (next(p) != NULL)
    {
        p = next(p);
    }
    adrRelation q = next(p);
    next(p) = NULL;
    info(m).total--;
    return q;
}

adrRelation delete_after_relation(listMatkul &M, adrMatkul &m, adrRelation prec)
{
    adrRelation p = next(prec);
    next(prec) = next(p);
    next(p) = NULL;
    info(m).total--;
    return p;
}

adrRelation delete_relation_(listMatkul &M)
{
    adrRelation r = NULL, prec = NULL;
    adrMatkul m = NULL;
    string data;
    if (first(M) != NULL)
    {
        printMatkul(M);
        cout << "Choose Matkul Name: ";
        cin >> data;
        m = find_matkul(M, data);
    }
    if (m != NULL)
    {
        printRelation(M, m);
        cout << "Choose Siswa Name : ";
        cin >> data;
        r = find_Relasi(m, data);
        if (r != NULL)
        {
            if (r == m->goRelation)
            {
                r = delete_first_relation(M, m);
            }
            else if (next(r) == NULL)
            {
                r = delete_last_relation(M, m);
            }
            else
            {
                prec = m->goRelation;
                while (prec != NULL && next(prec) != r)
                {
                    prec = next(prec);
                }
                r = delete_after_relation(M, m, prec);
            }
        }
    }
    else
    {
        cout << "\nFailed\n";
    }
    return r;
}

adrRelation delete_relation(listMatkul &M)
{
    adrRelation p = NULL;

    printMatkul(M);

    string matkul;
    cout << "Pilih mata kuliah : ";
    cin >> matkul;
    adrMatkul m = find_matkul(M, matkul);
    adrMatkul n = m;
    cout << n << endl;
    if (n == NULL)
    {
        cout << "Mata kuliah tidak ditemukan." << endl;
        return p;
    }

    adrRelation q = m->goRelation;

    string mahasiswa;
    cout << "Nama Mahasiswa : ";
    cin >> mahasiswa;

    while (info(q)->info.nama_siswa != mahasiswa && q != NULL)
        q = next(q);

    if (q == NULL)
    {
        cout << "Tidak ada siswa yang bernama " << mahasiswa << " di mata kuliah ini." << endl;
        return p;
    }
    else
    {
        if (q == m->goRelation)
        {
            p = delete_first_relation(M, m);
        }
        else if (next(q) == NULL)
        {
            p = delete_last_relation(M, m);
        }
        else
        {
            adrRelation prec = m->goRelation;
            while (next(prec) != q)
                prec = next(prec);
            p = delete_after_relation(M, m, prec);
        }
    }

    return p;
}

// Delete Matkul
adrMatkul delete_first_matkul(listMatkul &M)
{
    adrMatkul p = first(M);

    if (next(p) == first(M))
    {
        first(M) = NULL;
        last(M) = NULL;
        //next(p) = NULL;
        //prev(p) = NULL;
    }
    else
    {
        prev(next(p)) = last(M);
        next(last(M)) = next(p);
        first(M) = next(p);
        next(p) = NULL;
        prev(p) = NULL;
    }

    return p;
}

adrMatkul delete_last_matkul(listMatkul &M)
{
    adrMatkul p = last(M);

    next(prev(p)) = first(M);
    prev(first(M)) = prev(p);
    last(M) = prev(p);
    prev(p) = NULL;
    next(p) = NULL;

    return p;
}

adrMatkul delete_after_matkul(listMatkul &M, adrMatkul prec)
{
    adrMatkul p = next(prec);

    next(prec) = next(p);
    prev(next(p)) = prec;
    next(p) = NULL;
    prev(p) = NULL;

    return p;
}

adrMatkul delete_matkul(listMatkul &M)
{
    adrMatkul p;
    adrMatkul prec;
    string matkul;
    if (first(M) != NULL)
    {
        printMatkul(M);
        cout << "Pilih mata kuliah : ";
        cin >> matkul;
        p = find_matkul(M, matkul);

        if (p != NULL)
        {
            if (p == first(M))
            {
                p = delete_first_matkul(M);
            }
            else if (p == last(M))
            {
                p = delete_last_matkul(M);
            }
            else
            {
                prec = prev(p);
                p = delete_after_matkul(M, prec);
            }
        }
        else
        {
            cout << "Matkul tidak ditemukan." << endl;
        }
    }
    else
    {
        cout << "\nFailed\n";
    }

    return p;
}

adrSiswa delete_first_siswa(listSiswa &S)
{
    adrSiswa p = first(S);

    if (next(p) == first(S))
    {
        first(S) = NULL;
        last(S) = NULL;
        //next(p) = NULL;
        //prev(p) = NULL;
    }
    else
    {
        prev(next(p)) = last(S);
        next(last(S)) = next(p);
        first(S) = next(p);
        next(p) = NULL;
        prev(p) = NULL;
    }

    return p;
}

adrSiswa delete_last_siswa(listSiswa &S)
{
    adrSiswa p = last(S);

    next(prev(p)) = first(S);
    prev(first(S)) = prev(p);
    last(S) = prev(p);
    prev(p) = NULL;
    next(p) = NULL;

    return p;
}

adrSiswa delete_after_siswa(listSiswa &S, adrSiswa prec)
{
    adrSiswa p = next(prec);

    next(prec) = next(p);
    prev(next(p)) = prec;
    next(p) = NULL;
    prev(p) = NULL;

    return p;
}

adrSiswa delete_siswa(listSiswa &S, listMatkul &M)
{
    adrSiswa p = NULL, prec1 = NULL;
    adrRelation prec = NULL, r = NULL;
    adrMatkul m = NULL;
    string siswa;
    if (first(S) != NULL)
    {
        printSiswa(S);

        cout << "Nama siswa yang akan dihapus : ";
        cin >> siswa;
        p = find_siswa(S, siswa);

        if (p == first(S))
        {
            p = delete_first_siswa(S);
        }
        else if (p == last(S))
        {
            p = delete_last_siswa(S);
        }
        else
        {
            prec1 = prev(p);
            p = delete_after_siswa(S, prec1);
        }
        adrSiswa q = p;

        if (first(M) != NULL)
        {
            m = first(M);
            r = find_Relasi(m, info(q).nama_siswa);
            if (r->info == q)
            {
                if (r == m->goRelation)
                {
                    r = delete_first_relation(M, m);
                }
                else if (next(r) == NULL)
                {
                    r = delete_last_relation(M, m);
                }
                else
                {
                    prec = m->goRelation;
                    while (prec != NULL && next(prec) != r)
                    {
                        prec = next(prec);
                    }
                    r = delete_after_relation(M, m, prec);
                }
                // m->info.total -= 1;
            }
            m = next(m);
            while (m != first(M))
            {
                r = find_Relasi(m, q->info.nama_siswa);
                if (r->info == q)
                {
                    if (r == m->goRelation)
                    {
                        r = delete_first_relation(M, m);
                    }
                    else if (next(r) == NULL)
                    {
                        r = delete_last_relation(M, m);
                    }
                    else
                    {
                        prec = m->goRelation;
                        while (prec != NULL && next(prec) != r)
                        {
                            prec = next(prec);
                        }
                        r = delete_after_relation(M, m, prec);
                    }
                    // m->info.total -= 1;
                }
                m = next(m);
            }
        }
    }
    else
    {
        cout << "Tidak ada data mahasiswa." << endl;
    }

    return p;
}

// Double Linked List (dengan last)
void printSiswa(listSiswa P)
{
    if (first(P) != NULL)
    {
        int n = 1;
        adrSiswa p = first(P);
        cout << n << ". " << info(p).nama_siswa << " | " << info(p).nim << " | " << info(p).kelas << " | " << info(p).jenis << endl;
        p = next(p);
        while (p != first(P))
        {
            n++;
            cout << n << ". " << info(p).nama_siswa << " | " << info(p).nim << " | " << info(p).kelas << " | " << info(p).jenis << endl;
            p = next(p);
        }
    }
    else
    {
        cout << "Empty\n";
    }
}
// Double Linked List (dengan last)
void printMatkul(listMatkul P)
{
    if (first(P) != NULL)
    {
        int n = 1;
        adrMatkul p = first(P);
        cout << "[" << n << "] " << info(p).nama_matkul << " | " << info(p).kelas_matkul << " | " << info(p).jenis << " | " << info(p).total << "/" << info(p).max;
        p = next(p);
        cout << endl;
        while (p != first(P))
        {
            n++;
            cout << "[" << n << "] " << info(p).nama_matkul << " | " << info(p).kelas_matkul << " | " << info(p).jenis << " | " << info(p).total << "/" << info(p).max << endl;
            p = next(p);
        }
    }
    else
    {
        cout << "Empty\n";
    }
}

// Single Linked List (without last)
void printRelation(listMatkul P, adrMatkul p)
{
    if (first(P) != NULL)
    {
        adrMatkul m = NULL;
        if (p == NULL)
        {
            printMatkul(P);
            cout << "Choose Matkul Name : ";
            string t;
            cin >> t;
            p = find_matkul(P, t);
        }
        m = p;
        if (m != NULL)
        {
            int n = 1;
            adrRelation c = m->goRelation;
            cout << "Siswa dari Mata Kuliah " << info(m).nama_matkul << " | " << info(m).kelas_matkul << " | " << info(m).jenis << " :\n";
            while (c != NULL)
            {
                cout << n << ". " << info(c)->info.nama_siswa << " | " << info(c)->info.nim << endl;
                c = next(c);
                n++;
            }
        }
    }
    else
    {
        cout << "Empty\n";
    }
    cout << endl;
}

void addSiswa2Mk(listMatkul &M, listSiswa &S)
{
    if (first(M) != NULL)
    {
        string t;
        printMatkul(M);
        cout << "Choose Matkul Name : ";
        cin >> t;
        adrMatkul m;
        m = find_matkul(M, t);
        if (m != NULL && info(m).total != info(m).max)
        {
            adrSiswa s;
            adrRelation p;

            cout << "1. Masukan siswa yang sudah ada\n2. Masukan siswa yang baru\nChoose : ";
            cin >> t;
            if (t == "1")
            {
                printSiswa(S);
                cout << "Choose Siswa Name : ";
                cin >> t;
                s = find_siswa(S, t);

                if (s != NULL)
                {
                    p = newRelation(s);

                    insert_relation(M, m, p);
                    info(m).total++;
                }
            }
            else if (t == "2")
            {
                info_siswa is;
                cout << "Nama               : ";
                cin >> is.nama_siswa;
                cout << "NIM                : ";
                cin >> is.nim;
                cout << "Kelas              : ";
                cin >> is.kelas;
                cout << "Jenis Mahasiswa    : ";
                cin >> is.jenis;
                if (is.jenis != "INT" && is.jenis != "Reguler")
                {
                    cout << "Invalid\nSet to Reguler by default\n";
                    is.jenis = "Reguler";
                }
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
        p = first(S);
        bool cek = true;
        if (info(p).nama_siswa != data)
        {
            p = next(p);
        }
        else
        {
            cek = false;
        }
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
        {
            p = NULL;
        }
    }
    return p;
}

// Circular Double Linked List (dengan last)
adrMatkul find_matkul(listMatkul M, string data)
{
    adrMatkul p = NULL;
    if (first(M) != NULL)
    {
        p = first(M);
        bool cek = true;
        if (info(p).nama_matkul != data)
        {
            p = next(p);
        }
        else
        {
            cek = false;
        }
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
        {
            p = NULL;
        }
    }
    return p;
}

adrRelation find_Relasi(adrMatkul m, string t)
{
    adrRelation r;
    if (m != NULL)
    {
        bool cek = true;
        r = m->goRelation;
        while (r != NULL && cek)
        {
            if (r->info->info.nama_siswa != t)
            {
                r = next(r);
            }
            else
            {
                cek = false;
            }
        }
    }
    return r;
}

void find_siswa_in_matkul(listSiswa S, listMatkul M)
{
    info_siswa is;
    adrSiswa s;
    adrMatkul m;
    adrRelation r;
    int n = 0;
    if (first(S) != NULL && first(M) != NULL)
    {
        cout << "Search Siswa Name : ";
        cin >> is.nama_siswa;
        s = find_siswa(S, is.nama_siswa);
        if (s != NULL)
        {
            m = first(M);
            r = m->goRelation;
            while (r != NULL)
            {
                if (r->info->info.nama_siswa == s->info.nama_siswa)
                {
                    cout << info(m).nama_matkul << " | ";
                    n = 1;
                }
                r = next(r);
            }
            m = next(m);
            while (m != first(M))
            {
                r = m->goRelation;
                while (r != NULL)
                {
                    if (r->info->info.nama_siswa == s->info.nama_siswa)
                    {
                        cout << info(m).nama_matkul << " | ";
                    }
                    r = next(r);
                }
                m = next(m);
            }
        }
        if (n == 0)
        {
            cout << "\nNot Found\n";
        }
    }
    else
    {
        cout << "\nEmpty\n";
    }
}

void insertSiswa(listSiswa &P)
{
    adrSiswa s, prec;
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
        if (is.jenis != "INT" && is.jenis != "Reguler")
        {
            cout << "Invalid\nSet to Reguler by default\n";
            is.jenis = "Reguler";
        }
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
        if (is.jenis != "INT" && is.jenis != "Reguler")
        {
            cout << "Invalid\nSet to Reguler by default\n";
            is.jenis = "Reguler";
        }
        s = newSiswa(is);
        insert_last_siswa(P, s);
    }
    else if (t == "3" && first(P) != NULL)
    {
        printSiswa(P);
        cout << "Input after (Student name): ";
        cin >> t;
        prec = find_siswa(P, t);
        if (s != NULL)
        {
            cout << "Nama               : ";
            cin >> is.nama_siswa;
            cout << "NIM                : ";
            cin >> is.nim;
            cout << "Kelas              : ";
            cin >> is.kelas;
            cout << "Jenis Mahasiswa    : ";
            cin >> is.jenis;
            if (is.jenis != "INT" && is.jenis != "Reguler")
            {
                cout << "Invalid\nSet to Reguler by default\n";
                is.jenis = "Reguler";
            }
            s = newSiswa(is);
            insert_after_siswa(P, s, prec);
        }
    }
    else
    {
        cout << "\nGagal";
    }
    cout << endl;
}

void insertMatkul(listMatkul &M)
{
    adrMatkul m, prec;
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
        if (im.jenis != "INT" && im.jenis != "Reguler")
        {
            cout << "Invalid\nSet to Reguler by default\n";
            im.jenis = "Reguler";
        }
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
        if (im.jenis != "INT" && im.jenis != "Reguler")
        {
            cout << "Invalid\nSet to Reguler by default\n";
            im.jenis = "Reguler";
        }
        m = newMatkul(im);
        insert_last_matkul(M, m);
    }
    else if (t == "3" && first(M) != NULL)
    {
        printMatkul(M);
        cout << "Input after (Matkul name) : ";
        cin >> t;
        prec = find_matkul(M, t);
        if (m != NULL)
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
            if (im.jenis != "INT" && im.jenis != "Reguler")
            {
                cout << "Invalid\nSet to Reguler by default\n";
                im.jenis = "Reguler";
            }
            m = newMatkul(im);
            insert_after_matkul(M, m, prec);
        }
    }
    else
    {
        cout << "\nGagal";
    }
    cout << endl;
}