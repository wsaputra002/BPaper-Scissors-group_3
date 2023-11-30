#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Fungsi untuk menghasilkan pilihan acak komputer
string pilihanKomputer()
{
    int pilihan = rand() % 3;
    if (pilihan == 0)
    {
        return "Batu";
    }
    else if (pilihan == 1)
    {
        return "Gunting";
    }
    else
    {
        return "Kertas";
    }
}

// Fungsi untuk menentukan hasil pertandingan
string hasilPertandingan(string pilihanPemain, string pilihanKomputer)
{
    if (pilihanPemain == pilihanKomputer)
    {
        return "Seri!";
    }
    else if ((pilihanPemain == "Batu" && pilihanKomputer == "Gunting") ||
             (pilihanPemain == "Gunting" && pilihanKomputer == "Kertas") ||
             (pilihanPemain == "Kertas" && pilihanKomputer == "Batu"))
    {
        return "Anda Menang!";
    }
    else
    {
        return "Anda Kalah.";
    }
}

int main()
{
    // Mengatur seed acak berdasarkan waktu
    srand(static_cast<unsigned int>(time(0)));

    cout << "=== Game Batu, Gunting, Kertas ===" << endl;

    // Loop permainan
    bool mainLagi = true;
    while (mainLagi)
    {
        // Pilihan pemain
        string pilihanPemain;
        cout << "Pilih (Batu/Gunting/Kertas): ";
        cin >> pilihanPemain;

        // Validasi input pemain
        transform(pilihanPemain.begin(), pilihanPemain.end(), pilihanPemain.begin(), ::tolower);
        if (pilihanPemain != "batu" && pilihanPemain != "gunting" && pilihanPemain != "kertas")
        {
            cout << "Input tidak valid. Coba lagi." << endl;
            continue;
        }

        // Pilihan komputer
        string pilihanComp = pilihanKomputer();
        cout << "Komputer memilih: " << pilihanComp << endl;

        // Menentukan hasil pertandingan
        cout << hasilPertandingan(pilihanPemain, pilihanComp) << endl;

        // Meminta pemain apakah ingin bermain lagi
        cout << "Main lagi? (Ya/Tidak): ";
        string jawaban;
        cin >> jawaban;
        transform(jawaban.begin(), jawaban.end(), jawaban.begin(), ::tolower);
        if (jawaban != "ya")
        {
            mainLagi = false;
        }
    }

    cout << "Terima kasih telah bermain!" << endl;

    return 0;
}