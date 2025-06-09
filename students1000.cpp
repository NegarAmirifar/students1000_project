#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream file("students1000.txt");
    string name;
    int score1, score2, score3, score4;
    float total = 0;
    int count = 0;

    if (!file.is_open()) {
        cout << "خطا در باز کردن فایل!" << endl;
        return 1;
    }

    while (file >> name >> score1 >> score2 >> score3 >> score4) {
        float average = (score1 + score2 + score3 + score4) / 4.0f;
        total += average;
        count++;
        
        cout << name << ": " << fixed << setprecision(2) << average << endl;
    }

    file.close();

    if (count > 0) {
        float overall = total / count;
        cout << "\nمعدل کل: " << fixed << setprecision(2) << overall << endl;
    } else {
        cout << "هیچ دانشجویی یافت نشد!" << endl;
    }

    return 0;
}
