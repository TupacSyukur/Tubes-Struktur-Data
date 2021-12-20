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
    adrRelation q;
    adrMatkul deleted_m;
    adrSiswa deleted_s;
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
        { // Delete Siswa
            deleted_s = delete_siswa(S, M);
        }
        else if (n == "5")
        { // Delete Matkul
            deleted_m = delete_matkul(M);
        }
        else if (n == "6")
        { // Delete Siswa dalam Matkul
            // q = delete_relation(M);
            q = delete_relation_(M);
        }
        else if (n == "7")
        { // Print Siswa
            printSiswa(S);
        }
        else if (n == "8")
        { // Print Matkul
            printMatkul(M);
        }
        else if (n == "9")
        { // Print Siswa dalam Matkul
            printRelation(M, NULL);
        }
        else if (n == "10")
        { // Cari Siswa
            cout << "Search Siswa Name : ";
            cin >> is.nama_siswa;
            s = find_siswa(S, is.nama_siswa);
            if (s != NULL)
            {
                cout << "\nFound\n";
                cout << info(s).nama_siswa << " | " << info(s).nim << " | " << info(s).kelas << " | " << info(s).jenis << "\n\n";
            }
            else
            {
                cout << "\nNot Found\n";
            }
        }
        else if (n == "11")
        { // Cari Matkul
            cout << "Search Matkul Name : ";
            cin >> im.nama_matkul;
            m = find_matkul(M, im.nama_matkul);
            if (m != NULL)
            {
                cout << "\nFound\n";
                cout << info(m).nama_matkul << " | " << info(m).kelas_matkul << " | " << info(m).jenis << " | " << info(m).total << "/" << info(m).max << "\n\n";
            }
            else
            {
                cout << "\nNot Found\n";
            }
        }
        else if (n == "12")
        { // Cari Siswa dalam Matkul
            find_siswa_in_matkul(S, M);
        }
        else if (n == "13")
        { // Print matkul serta info siswanya
            printInfoKelas(M);
        }
        else if (n == "14")
        {
            printAvailableMatkul(M);
        }
        else if (n == "15"){
            save_script(M,S);
        }
        else if (n == "16"){
            create_list_matkul(M);
            create_list_siswa(S);
            load_script(M,S);
        }
        else if (n != "0")
        { // Exit
            cout << "\nWrong Input\n";
        }
        cout << endl;
    }
    return 0;
}