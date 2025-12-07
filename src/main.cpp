#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Симуляция датчика температуры
int simulateTemperature() {
    return rand() % 41 - 10; // от -10 до +30 °C
}

// Анализ данных
void analyzeData(const vector<int>& data, double& avg, int& mn, int& mx) {
    int sum = 0;
    mn = data[0];
    mx = data[0];

    for (int t : data) {
        sum += t;
        if (t < mn) mn = t;
        if (t > mx) mx = t;
    }
    avg = sum / (double)data.size();
}

int main() {
    srand(time(0));

    vector<int> temperatures;

    cout << "Симуляция IoT-системы: температурный датчик + вентилятор\n\n";

    // 1. Измерения
    cout << "Полученные измерения температуры:\n";
    for (int i = 0; i < 10; i++) {
        int value = simulateTemperature();
        temperatures.push_back(value);
        cout << "Измерение " << i + 1 << ": " << value << " °C\n";
    }

    // 2. Анализ
    double avg;
    int minVal, maxVal;
    analyzeData(temperatures, avg, minVal, maxVal);

    cout << "\n--- Анализ данных ---\n";
    cout << "Среднее значение: " << avg << " °C\n";
    cout << "Минимальная температура: " << minVal << " °C\n";
    cout << "Максимальная температура: " << maxVal << " °C\n";

    // 3. Управление актуатором
    cout << "\n--- Решение системы ---\n";

    if (avg > 25) {
        cout << "Температура высокая. Включаем ВЕНТИЛЯТОР.\n";
    }
    else if (avg < 5) {
        cout << "Температура низкая. Включаем ОБОГРЕВАТЕЛЬ.\n";
    }
    else {
        cout << "Температура в норме. Ничего не делаем.\n";
    }

    return 0;
}
