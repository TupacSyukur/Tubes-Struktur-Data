#include "code.cpp"
#include <iostream>

using namespace std;

int main()
{
    listMatkul M;
    listSiswa S;
    adrSiswa s;
    adrMatkul m;
    adrRelation p;
    info_siswa is;
    info_matkul im;

    string n = "-1";

    cout << "Multi Linked List Gittinger\n";

    create_list_matkul(M);
    create_list_siswa(S);
    while (n != "0")
    {
        n = menu();
        if (n == "1")
        { // Insert Siswa
            insertSiswa(S);
        }
        else if (n == "2")
        { // Insert Matkul
            insertMatkul(M);
        }
        else if (n == "3")
        { // Insert Siswa ke Matkul;
            addSiswa2Mk(M, S);
        }
        else if (n == "4")
        { // Edit Siswa
            
        }
        else if (n == "5")
        { // Edit Matkul
        }
        else if (n == "6")
        { // Delete Siswa
        }
        else if (n == "7")
        { // Delete Matkul
        }
        else if (n == "8")
        { // Delete Siswa dalam Matkul
        }
        else if (n == "9")
        { // Print Siswa
            printSiswa(S);
        }
        else if (n == "10")
        { // Print Matkul
            printMatkul(M);
        }
        else if (n == "11")
        { // Print Siswa dalam Matkul
            printRelation(M);
        }
        else if (n == "12")
        { // Cari Siswa
        }
        else if (n == "13")
        { // Cari Matkul
        }
        else if (n == "14")
        { // Cari Siswa dalam Matkul
        }
        else if (n != "0")
        { // Exit
            cout << "\nWrong Input\n";
        }
        cout << endl;
    }
    return 0;
}