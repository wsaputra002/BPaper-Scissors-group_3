#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Fungsi untuk menampilkan pilihan
void displayChoices() {
    cout << "Pilihan:\n";
    cout << "1. Gunting\n";
    cout << "2. Batu\n";
    cout << "3. Kertas\n";
}

// Fungsi untuk mendapatkan pilihan pemain
int getPlayerChoice() {
    int choice;
    cout << "Masukkan pilihan Anda (1-3): ";
    cin >> choice;
    return choice;
}

// Fungsi untuk mendapatkan pilihan komputer
int getComputerChoice() {
    return rand() % 3 + 1;  // 1: Gunting, 2: Batu, 3: Kertas
}

// Fungsi untuk menentukan pemenang
int determineWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        return 0; // Seri
    } else if ((playerChoice == 1 && computerChoice == 2) ||
               (playerChoice == 2 && computerChoice == 3) ||
               (playerChoice == 3 && computerChoice == 1)) {
        return 1; // Pemain menang
    } else {
        return -1; // Komputer menang
    }
}

// Fungsi untuk mencari elemen dalam array
bool searchArray(int key, int array[], int size) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == key) {
            return true; // Elemen ditemukan
        }
    }
    return false; // Elemen tidak ditemukan
}

// Fungsi untuk mengurutkan array
void sortArray(int array[], int size) {
    sort(array, array + size);
}

int main() {
    srand(time(0));

    const int rounds = 3;
    int playerScore = 0;
    int computerScore = 0;
    int playerChoices[rounds];

    for (int round = 1; round <= rounds; ++round) {
        cout << "Round " << round << "\n";
        displayChoices();

        int playerChoice = getPlayerChoice();
        playerChoices[round - 1] = playerChoice;
        int computerChoice = getComputerChoice();

        cout << "Anda memilih: " << playerChoice << "\n";
        cout << "Komputer memilih: " << computerChoice << "\n";

        int result = determineWinner(playerChoice, computerChoice);

        if (result == 0) {
            cout << "Hasil: Seri!\n";
        } else if (result == 1) {
            cout << "Hasil: Anda menang!\n";
            playerScore++;
        } else {
            cout << "Hasil: Komputer menang!\n";
            computerScore++;
        }
    }

    cout << "\nSkor Akhir:\n";
    cout << "Anda: " << playerScore << " poin\n";
    cout << "Komputer: " << computerScore << " poin\n";

    // Menggunakan searching dan sorting pada array
    int searchKey;
    cout << "Masukkan nilai untuk dicari dalam array: ";
    cin >> searchKey;

    sortArray(playerChoices, rounds);

    if (searchArray(searchKey, playerChoices, rounds)) {
        cout << "Nilai ditemukan dalam array.\n";
    } else {
        cout << "Nilai tidak ditemukan dalam array.\n";
    }

  return 0;
}
