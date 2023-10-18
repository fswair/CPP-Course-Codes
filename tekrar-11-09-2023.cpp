#include <iostream>

//Reference Qualifiers

//1) LValue&
//2) RValue&&
//3) LValue&const
//4) RValue&const

class Date {
public:
    Date() = default;
    ~Date(){
        std::cout << "Date'in hayatı bitiyor..\n";
    }
    Date(int md, int mm, int my): md(md), mm(mm), my(my) {
        std::cout << "ctor called\n";
    }
    void print()const{
        std::cout << "(" << md << "/" << mm << "/" << my << ")\n";
    }
    void foo() & {

    }
    void foo() &&;
    void foo()const&;
    void foo()const&&;
    //void foo(); // illegal, if overloads has a ref. qualifier, all must be ref. qualified

    Date& operator=(const Date&m) {
        std::cout << "copy assign. called\n";
        return *this;
    }

    Date(const Date&r) {
        std::cout << "copy ctor called";
    }

    Date& operator=(Date&&) noexcept {
        std::cout << "move assign. called\n";
        return *this;
    }

    Date(Date&&r) noexcept {
        std::cout << "move ctor called";
    }

    Date& operator+=(int day) {
        if (md + day >= 31) {
            std::cout << "please give a number less than 31\n";
        } else
            md += day;

        return *this;
    }
private:
    int md{1}, mm{1}, my{1970};
};

class DatePtr {
public:
    DatePtr(Date*m) : mptr(m) {
    }

    Date* operator->() {
        return mptr;
    }
    ~DatePtr(){
        delete mptr;
        std::cout << "DatePtr'in hayatı bitiyot..\n";
    }
private:
    Date *mptr{nullptr};
};


namespace ali {
    int emre = 5;
}


class NoExceptBase {
public:
    virtual void foo() noexcept;
    NoExceptBase() {
    };
};

class ExceptBase : NoExceptBase {

public:

    void foo() noexcept override; // legal
    //void foo() override; //illegal, cannot overrided
};


template<typename T, int N>
class M {

public:
    int n = N;
    M() {

    };

    T* foo() noexcept {
        return *t;
    }
private:
    T* t[N];

};



template <typename T>
class A {

public:
    T value;
    A(int n) {
        value = n;
    }
};


int main() {

    //using ali::emre; syntax error
    // using namespace ali; legal

    /*DatePtr mptr = new Date;
    int emre = 45;

    emre = ((++emre = 5) = emre) = 67;
    emre;*/


    // noexcept specifier

    void func() noexcept;

    void func() noexcept(true);

    //syntax error
    //void func() noexcept(false);
    //void func();

    //noexcept logic with ternary predict expr
    constexpr bool con = true;

    void func() noexcept(con ? true : false);

    //noexcept operator
    constexpr bool m = noexcept(func());

    M<int, 10> ma;

    for (int i = 0; i<ma.n; ++i) {
        std::cout << i << ": " << ma.foo()[i] << "\n";
    }

    A<int> abc = 1881;

    std::cout <<  abc.value;

}
