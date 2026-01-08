#include <iostream>
#include <algorithm>
#include <unordered_map>

std::unordered_map<int, int> days_in_month = {{1, 31}, {2, 28}, {3, 31,}, {4 , 30},
                                              {5, 31}, {6, 30}, {7, 31}, {8 , 31},
                                              {9, 30}, {10, 31}, {11, 30}, {12, 31}};

int date_to_days(int day, int month, int year);
std::tuple<int, int, int> days_to_date(int days);
bool is_leap_year(int year) {return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year);


    [[nodiscard]] int GetDay() const;
    [[nodiscard]] int GetMonth() const;
    [[nodiscard]] int GetYear() const;

    Date operator+(int days) const;
    Date operator-(int days) const;
};

Date::Date(int day, int month, int year) {
    if (year <= 2099 && year >=  1970 && month >= 1 && month <= 12 && day > 1 && ((month == 2 && is_leap_year(year) && day < 29) ||
        day <= days_in_month[month])) {
        this->day = day;
        this->month = month;
        this->year = year;
    } else {
        this->day = 1;
        this->month = 1;
        this->year = 1970;
    }

}

int date_to_days(int day, int month, int year) {
    int days = 0;

    for (int y = 1970; y < year; ++y) {
        days += is_leap_year(y) ? 366 : 365;
    }

    for (int m = 1; m < month; ++m) {
        days += days_in_month[m];
        if (m == 2 && is_leap_year(year)) {
            days += 1;
        }
    }

    days += day;

    return days;
}

std::tuple<int, int, int> days_to_date(int days) {
    int month = 1, years = 1970;

    while (days > 364) {
        if (is_leap_year(years)) {
            days -= 366;
        } else {
            days -= 365;
        }
        ++years;
    }

    while (true) {
        if (is_leap_year(years + 1) && month == 2) {
            if (days - days_in_month[month] + 1 <= 0) {
                return {days, month, years};
            }
        } else {
            if (days - days_in_month[month] <= 0) {
                return {days, month, years};
            }
        }
        month += 1;
        days -= days_in_month[month];
    }
}


int Date::GetDay() const {
    return this->day;
}

int Date::GetMonth() const {
    return this->month;
}

int Date::GetYear() const {
    return this->year;
}

Date Date::operator+(int days) const {
    int new_days = date_to_days(GetDay(), GetMonth(), GetYear()) + days;
    if (new_days < 0)
        return {1, 1, 1970};
    auto [new_day, new_month, new_year] = days_to_date(new_days);
    return {new_day, new_month, new_year};
}

Date Date::operator-(int days) const {
    int new_days = date_to_days(GetDay(), GetMonth(), GetYear()) - days;
    if (new_days < 0)
        return {1, 1, 1970};
    auto [new_day, new_month, new_year] = days_to_date(new_days);
    return {new_day, new_month, new_year};
}

int operator-(const Date& date1, const Date& date2) {
    return abs(date_to_days(date1.GetDay(), date1.GetMonth(), date1.GetYear()) -
            date_to_days(date2.GetDay(), date2.GetMonth(), date2.GetYear()));
}

std::ostream& operator << (std::ostream& out, const Date& date) {
    out << date.GetYear() << ":" << date.GetMonth() << ":" << date.GetDay();
    return out;
}

int main() {
    // Тест 1: Создание корректной даты
    Date date1(4, 1, 2026);
    std::cout << "Date1: " << date1 << std::endl;

    // Тест 2: Создание некорректной даты (должно стать 1:1:1970)
    Date date2(31, 2, 2025); // 31 февраля не существует
    std::cout << "Date2: " << date2 << std::endl;

    // Тест 3: Добавление дней
    Date date3 = date1 + 10;
    std::cout << "Date1 + 10 дней: " << date3 << std::endl;

    // Тест 4: Вычитание дней
    Date date4 = date1 - 10;
    std::cout << "Date1 - 10 дней: " << date4 << std::endl;

    // Тест 5: Разность дат
    Date date5(1, 3, 2026);
    int diff = date5 - date1;
    std::cout << "Разность между " << date5 << " и " << date1 << ": " << diff << " дней" << std::endl;

    // Тест 6: Високосный год
    Date date6(28, 2, 2024);
    Date date7 = date6 + 1;
    std::cout << "28.02.2024 + 1 день: " << date7 << std::endl;

    return 0;
}