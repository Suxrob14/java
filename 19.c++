#include <iostream>
#include <vector>

using namespace std;

void showTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Список задач пуст!" << endl;
    } else {
        cout << "Ваши задачи:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        cout << "\nМенеджер задач\n";
        cout << "1. Добавить задачу\n";
        cout << "2. Удалить задачу\n";
        cout << "3. Показать задачи\n";
        cout << "4. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        cin.ignore(); // Очистка буфера

        if (choice == 1) {
            string task;
            cout << "Введите задачу: ";
            getline(cin, task);
            tasks.push_back(task);
        } else if (choice == 2) {
            showTasks(tasks);
            if (!tasks.empty()) {
                int index;
                cout << "Введите номер задачи для удаления: ";
                cin >> index;
                if (index > 0 && index <= tasks.size()) {
                    tasks.erase(tasks.begin() + index - 1);
                } else {
                    cout << "Неверный номер!" << endl;
                }
            }
        } else if (choice == 3) {
            showTasks(tasks);
        }

    } while (choice != 4);

    cout << "До свидания!" << endl;
    return 0;
}
