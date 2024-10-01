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

        std::string to_string() const;

    private:
        unsigned char * number_;
        size_t size_;

        explicit Decimal(size_t n);

        Decimal(const std::string & s, size_t n);

        static void swap(Decimal & a, Decimal & b) noexcept;
    };
}

#endif //TASK_H
