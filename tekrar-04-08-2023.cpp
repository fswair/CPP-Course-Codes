#include <iostream>
#include "ctime"
#include "string"

int func() {
    static constexpr int n[1000]{};
    return sizeof (n);
}

auto foo() {
    return 1;
}

enum class StatusCodes : int {Created = 200, Redirect=301, NotFound=404, ServerDown=500};

enum class Info {WARN = 1, ERROR = 2};
enum months {jan, feb, mar, apr, may, jun, july=7};

inline constexpr int _n[1000]{};
int main() {
    std::cout << "Hello, World!" << std::endl;
    time_t t;
    time_t timer = time(&t);
    tm* local = localtime(&timer);
    int year, mon, day;
    year = local->tm_year + 1900;
    mon = local->tm_mon + 1;
    day = local->tm_mday;
    printf("%d/%d/%d\n", day, mon, year);
    constexpr short age = 19;
    constexpr const char * p{"Mert"};
    if constexpr (p) {
        std::cout << "hell yeah\n";
    }
    std::cout << months::jan << months::feb << months::mar << months::apr;
    return 0;
}
