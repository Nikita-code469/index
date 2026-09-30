#include <iostream>

class Date {
private:
    int day, month, year;

    bool isLeap(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) const {
        int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (m == 2 && isLeap(y)) return 29;
        return months[m - 1];
    }

    long long toTotalDays() const {
        long long total = 0;
        for (int y = 1; y < year; ++y) {
            total += isLeap(y) ? 366 : 365;
        }
        for (int m = 1; m < month; ++m) {
            total += daysInMonth(m, year);
        }
        total += day;
        return total;
    }

    static Date fromTotalDays(long long total) {
        int y = 1;
        while (total > (Date{1, 1, y}.isLeap(y) ? 366 : 365)) {
            total -= (Date{1, 1, y}.isLeap(y) ? 366 : 365);
            y++;
        }
        int m = 1;
        Date temp{1, 1, y};
        while (total > temp.daysInMonth(m, y)) {
            total -= temp.daysInMonth(m, y);
            m++;
        }
        return Date{(int)total, m, y};
    }

public:

    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}


    long long operator-(const Date& other) const {
        return this->toTotalDays() - other.toTotalDays();
    }


    Date operator+(int days) const {
        long long total = this->toTotalDays() + days;
        return fromTotalDays(total);
    }


    void print() const {
        if (day < 10) std::cout << "0";
        std::cout << day << ".";
        if (month < 10) std::cout << "0";
        std::cout << month << "." << year << std::endl;
    }
};

int main() {
    Date d1(18, 5, 2026);
    Date d2(10, 5, 2026);

    std::cout << "Дата 1: "; d1.print();
    std::cout << "Дата 2: "; d2.print();


    long long diff = d1 - d2;
    std::cout << "Разница в днях: " << diff << std::endl;


    Date d3 = d1 + 15;
    std::cout << "Дата 1 + 15 дней: "; d3.print();

    return 0;
}
