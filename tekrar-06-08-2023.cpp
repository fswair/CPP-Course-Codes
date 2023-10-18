//
// Created by Mert on 6.08.2023.
//

#include <iostream>
//#include "random"
//#include "math.h"
//#include <ctime>

constexpr inline int q = 1;


int barfoo()
{
    return 1;
};

typedef struct birthdate {
    int year;
    int mday;
    int mon;
} BDate;
bool foo2() {
    void* ptr;
    return ptr;
}
class Emre {
public:
    int age = 26;
    const char* name = "Emre";
    const char * profession = "Accountant";
    const char * city = "Istanbul";

    BDate n;
    bool operator ==(Emre &emre) {
        if (age == emre.age) {
            return true;
        }
        return false;

    }
};

class Math {
public:
    inline static double m_pow(auto x, auto y) {
        return pow(x, y);
    }

    inline static int m_abs(int x) {
        return abs(x);
    }};

constexpr int bar(int x, int y) {
    return (x * y);
}
// doesnt generate really random numbers
long rand_callback(time_t t) {
    t = time(&t);
    if (t % 3 == 0)
        return (long) t / 5;
    if ((long)t % 5 == 0)
        return (long) t / 2;
    if ((long)t % 7 == 0)
        return (int ) ((long) t / 1.7);
    return long(t);

}

enum class ScopedEnum : const
int{HTTP = 0, HTTPS = 1};

int main() {
    time_t t{};
    const auto y = Math::m_pow(7, 2);
    long int n = rand_callback(t);
    //std::srand(time(NULL));
    std::cout << "random number: " << n;
    std::cout << std::endl;

    enum ScopedEnum status = ScopedEnum::HTTP;


    switch (status) {
        case ScopedEnum::HTTP:
            std::cout << "\nHTTP";
        case ScopedEnum::HTTPS:
            std::cout << "\nHTTPS";
    }

    // assignments in if idioms


    if (int baz = barfoo(); baz) {
        std::cout << baz << " is valid\n";
    } else {
        std::cout << baz << " is invalid\n";
    }

    // if with initializor

    if (int i=0, j=4, f=5; i<j && j<f) {
        std::cout << "i less than j and j less than t.\n";
    }

    if (t; t) {

    }

    if (time_t tx, f=1000000000000000; true) {
        std::cout << (((f-tx) / 86400) / 365) / 100 <<" century left to request year";
    }

    int g;

    int fd = 1;

    g = static_cast<unsigned char> (fd);

    int __;

    char *_p;

    //[[nodiscard]]
    int * zed = reinterpret_cast<int *> (_p);

    int* mert;

    const int *mertinyasi;

    mert = const_cast<int *> (mertinyasi);

    int *a;
    const int *b = 0;

    const_cast<int *> (b);

    using enum ScopedEnum;

    int ggg;
    unsigned char fff;
    char temp = fff;
    fff = static_cast<unsigned char> (ggg);

    std::cout << std::endl <<temp << std::endl << fff;

    Emre emre1,emre2;
    emre1.age = 25;
    emre2.age = 26;
    emre1.age = emre1.age+1;

    std::cout << "emre1.age == emre2.age : " << (emre1 == emre2);

    auto abc = [](int ass) {return ass;} ;

    std::cout << abc(5) << "\n";

    std::cout << "res: "<< foo2();

    // function overloading

    int func1(int, int);
    double func1(double, double);

    // function redeclaration

    int func2(int, int); // original overload
    int func2(int, int); // redec
    int func2(int, int*); // overloaded
    // overloaded aabs in both type
    int aabs(int);
    float aabs(float);



}
