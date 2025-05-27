#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void saveToFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
        cout << "Файл сохранен: " << filename << endl;
    } else {
        cout << "Ошибка при сохранении файла!" << endl;
    }
}

string loadFromFile(const string& filename) {
    ifstream file(filename);
    string content, line;
    if (file.is_open()) {
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    } else {
        cout << "Ошибка при открытии файла!" << endl;
    }
    return content;
}

int main() {
    string filename, content;
    int choice;

    do {
        cout << "\nТекстовый редактор\n";
        cout << "1. Написать текст\n";
        cout << "2. Сохранить в файл\n";
        cout << "3. Загрузить из файла\n";
        cout << "4. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore(); // Очистка буфера

        if (choice == 1) {
            cout << "Введите ваш текст (нажмите Enter для завершения):\n";
            getline(cin, content);
        } else if (choice == 2) {
            cout << "Введите имя файла для сохранения: ";
            cin >> filename;
            saveToFile(filename, content);
        } else if (choice == 3) {
            cout << "Введите имя файла для загрузки: ";
            cin >> filename;
            content = loadFromFile(filename);
            cout << "Содержимое файла:\n" << content << endl;
        }

    } while (choice != 4);

    cout << "До свидания!" << endl;
    return 0;
}