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

        Decimal(const size_t n, const unsigned char t);

        Decimal(const std::initializer_list<unsigned char> & t);

        Decimal(const std::string & s);

        Decimal(const Decimal & other);

        Decimal(Decimal && other) noexcept;

        virtual ~Decimal() noexcept;

        Decimal operator+(const Decimal & other);

        Decimal operator-(const Decimal & other);

        Decimal &operator+=(const Decimal & other);

        Decimal &operator-=(const Decimal & other);

        bool operator==(const Decimal & other) const;

        bool operator>(const Decimal & other) const;

        bool operator<(const Decimal & other) const;

    private:
        unsigned char * number_;
        size_t size_;

        Decimal(size_t n);

        Decimal(size_t n, unsigned char * t);

        unsigned char * LeftPad(const unsigned char * old_str, const size_t & current_size, const size_t & new_size);

        static int get_decimal_(const unsigned char & t);

        static unsigned char get_char_(const int & t);
    };
}

#endif //TASK_H
