//
// Created by Aleksandr Mikhailov on 21.09.2024.
//

#ifndef TASK_H
#define TASK_H
#include <initializer_list>
#include <string>

namespace decimal {
    class Decimal {
    public:
        Decimal();

        Decimal(const std::initializer_list<unsigned char> & t);

        explicit Decimal(const std::string & s);

        Decimal(const Decimal & other);

        Decimal(Decimal && other) noexcept;

        ~Decimal() noexcept;

        Decimal operator+(const Decimal & other) const;

        Decimal operator-(const Decimal & other) const;

        Decimal &operator+=(const Decimal & other);

        Decimal &operator-=(const Decimal & other);

        bool operator==(const Decimal & other) const;

        bool operator!=(const Decimal & other) const;

        bool operator>(const Decimal & other) const;

        bool operator<(const Decimal & other) const;

        Decimal & operator=(Decimal && other) noexcept;

        Decimal & operator=(const Decimal & other);


    private:
        unsigned char * number_;
        size_t size_;

        explicit Decimal(size_t n);

        Decimal(const std::string & s, size_t n);

        static void swap(Decimal & a, Decimal & b) noexcept;
    };

    std::string LeftPad(const unsigned char * old_str, const size_t & current_size, const size_t & new_size);

    int get_decimal(const unsigned char & t);

    unsigned char get_char(const int & t);
}

#endif //TASK_H
