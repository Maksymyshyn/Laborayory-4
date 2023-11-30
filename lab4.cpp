#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10; 

struct NOTE {
    string NAME;
    string TEL;
    int BDAY[3];
};

void inputNotes(NOTE blockNote[], int n) {
    setlocale(LC_ALL, "ukr");
    for (int i = 0; i < n; ++i) {
        setlocale(LC_ALL, "ukr");
        cout << "Введіть кількість записів: " << i + 1 << ":\n";
        cout << "Ім'я: ";
        cin >> blockNote[i].NAME;
        cout << "Номер телефону: ";
        cin >> blockNote[i].TEL;
        cout << "Дата народження(день, мфсяць, рік): ";
        for (int j = 0; j < 3; ++j) {
            cin >> blockNote[i].BDAY[j];
        }
    }
}

bool compareBirthdays(const NOTE& note1, const NOTE& note2) {
    return lexicographical_compare(note1.BDAY, note1.BDAY + 3, note2.BDAY, note2.BDAY + 3);
}

void sortNotesByBirthday(NOTE blockNote[], int n) {
    sort(blockNote, blockNote + n, compareBirthdays);
}

void displayBirthdaysInMonth(NOTE blockNote[], int n, int targetMonth) {
    bool found = false;

    for (int i = 0; i < n; ++i) {
        setlocale(LC_ALL, "ukr");
        if (blockNote[i].BDAY[1] == targetMonth) {
            cout << "Ім'я: " << blockNote[i].NAME << "\n";
            cout << "Номер телефону: " << blockNote[i].TEL << "\n";
            cout << "Дата народження: ";
            for (int j = 0; j < 3; ++j) {
                cout << blockNote[i].BDAY[j] << " ";
            }
            cout << "\n\n";
            found = true;
        }
    }

    if (!found) {
        setlocale(LC_ALL, "ukr");
        cout << "У вказаному місяці немає днів народження.\n";
    }
}

int main() {
    NOTE blockNote[N];
    setlocale(LC_ALL, "ukr");
    int N; 
    cout << "Введіть кількість записів: ";
    cin >> N;

    inputNotes(blockNote, N);
    sortNotesByBirthday(blockNote, N);

    int targetMonth;
    cout << "Введіть місяць для виконання пошуку: ";
    cin >> targetMonth;

    displayBirthdaysInMonth(blockNote, N, targetMonth);

    return 0;
}
