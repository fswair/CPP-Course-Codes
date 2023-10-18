#include <iostream>
int ** funcptr(double, int&, int=0){
    std::cout<<1;
}
void* funcptr(int, const int&, double=0.0){
    std::cout<<2;
}

int foop(int &) {

}
// ambigious
/*
 int foop(int) {

}
*/

class Neco {
    static Neco x; // x variable is static, thats why decl. is legal
    //Neco xf; illegal
};

class Mert {
private:
    int m;
    int n;
public:
    Mert () : m(0), n(0) { ; }
protected:
    virtual void func()  { ; }
public:
    int callfunc() {
        func();
        return 1;
    }
};

class Mertcan : Mert {
public:
    int m;
    int n;
    void func() override {
        std::cout << "Hi";
    };

    static void repr()  {
        Mertcan m;
        std::cout << (m.callfunc() == 1);
    }

};

int main() {
    constexpr int t = 5;
    funcptr(t, t, 1.1);
    float f = 3.14f;

    auto g = static_cast<float &> (f);
    auto e = reinterpret_cast<void *> (&g); // float& to void*

    Mert m;
    auto & k = m;

    (&k)->callfunc();

    constexpr int age = 19;
    // derleme zamanında bulunabilir

    const int & age_reference = age;

    // age_reference 'e ilk değer veren ifade sabittir. sabit ifade olduğunu ise derleme zamanında öğrenilebilir oluşundan biliyoruz.

    bool expressions = (age == age_reference | &age_reference == &age);
    true;

    Mertcan::repr();
    int sum = 0, value = 0;
    // read until end-of-life, calculating a running total of all values read
    while (true)
        if (std::cin >> value; value != 0)
           sum += value; //   equivalent to sum = sum + value
        else
           break;
        std::cout << "Sum is: " << sum << std::endl;
        int& w = sum;
        foop(sum);
        return 0;


}

