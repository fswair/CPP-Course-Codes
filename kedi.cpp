#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum CatColour {
    Orange,
    White,
    Black,
    Blue,
    Gray,
    Yellow
};

std::string colours[] = {"Orange", "White", "Black", "Blue", "Gray", "Yellow"};

vector<int> arr = {2, 3, 4};

class Callback{
public:
bool odd_callback(int number){
    return number % 2 == 1;
}
};
class Kedi {
    friend Kedi& operator+(Kedi &k, int r) {
        k.age += r;
        return k;
    }
public:
    int operator[] (Callback &&r) {
        for (auto i: arr) {
            if (r.odd_callback(i)) {
                return i;
            }
        }

    }
    Kedi(const char *name) : age(0), catName(name){
        //
    }

    void miyav() const {
        std::cout << "Kedinin adı: " << catName << "\nKedinin göz rengi: " << colours[eyeName] << "\nKedinin ırkı:  " << (sokakKedisiMi ? "Sokak Kedisi" : "Ev Kedisi" )<< "\nKedinin Yaşı: " << age << "\n";
    }
    int age{};
    bool sokakKedisiMi = false;
    CatColour colour = CatColour::Black;
    CatColour eyeName = CatColour::Black;
    bool ikiGozuFarkliRenkMi = false;

    const char * catName{};
};

// main block closed to make codes are odr compatible
/*
int main() {
    Kedi kedi{"Ruby"};
    Kedi kedi2{"Mırnak"};
    kedi = kedi2;
    const Kedi kedi2 = kedi + 19;
    kedi.miyav();

    auto odd = kedi[Callback{}];

    std::cout << odd;
    return 0;
}
*/
