#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void displayChoices()
{
    cout << "pilihan:\n";
    cout << "1. Gunting\n";
    cout << "2. Batu\n";
    cout << "3. Kertas\n";
}

int getPlayerChoice()
{
    int choice;
    cout << "Masukan pilihan anda (1-3): ";
    cin >> choice;
    return choice;
}

int getComputerChoice()
{
    return rand() % 3 + 1;
}

int determineWinner(int playerChoice, int computerChoice)
{
    if (playerChoice == computerChoice)
    {
        return 0;
    }
    else if ((playerChoice == 1 && computerChoice == 2) ||
             (playerChoice == 2 && computerChoice == 3) ||
             (playerChoice == 3 && computerChoice == 1))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool searchArray(int key, int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == key)
        {
            return true;
        }
    }
    return false;
}

void sortArray(int array[], int size)
{
    sort(array, array + size);
}

int main()
{
    srand(time(0));

    const int rounds = 3;
    int playerScore = 0;
    int computerScore = 0;
    int playerChoices[rounds];

    for (int round = 1; round <= rounds; ++round)
    {
        cout << "Round " << round << "\n";
        displayChoices();

        int playerChoice = getPlayerChoice();
        playerChoices[round - 1] = playerChoice;
        int computerChoice = getComputerChoice();

        cout << "Anda memilih: " << playerChoice << "\n";
        cout << "Komputer memilih: " << computerChoice << "\n";

        int result = determineWinner(playerChoice, computerChoice);

        if (result == 0)
        {
            cout << "Hasil: Seri!\n";
        }
        else if (result == 1)
        {
            cout << "Hasil: Anda menang!\n";
            playerScore++;
        }
        else
        {
            cout << "Hasil: Komputer menang!\n";
            computerScore++;
        }
    }
    cout << "\nSkor Akhir:\n";
    cout << "Anda: " << playerScore << " poin\n";
    cout << "Komputer: " << computerScore << " poin\n";

    int searchKey;
    cout << "Masukan nilai untuk dicari dalam array: ";
    cin >> searchKey;

    sortArray(playerChoices, rounds);

    if (searchArray(searchKey, playerChoices, rounds))
    {
        cout << "Selamat Anda Pemenangnya.\n";
    }
    else
    {
        cout << "Anda Gagal.\n";
    }

    return 0;
}