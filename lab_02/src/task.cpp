//
// Created by Aleksandr Mikhailov on 21.09.2024.
//

#include "task.h"

namespace decimal {
    Decimal::Decimal(): size_(0), number_(nullptr) {
        // pass
    }

    Decimal::Decimal(size_t n) {
        size_ = n;
        number_ = new unsigned char[n + 1];
        number_[n] = '\0';
    }

    Decimal::Decimal(size_t n, unsigned char * t) {
        size_ = n;
        number_ = t;
    }

    unsigned char * Decimal::LeftPad(const unsigned char * old_str, const size_t & current_size,
                                     const size_t & new_size) {
        auto * new_str = new unsigned char[new_size + 1];
        new_str[new_size] = '\0';

        for (size_t i = 0; i < current_size; ++i) {
            new_str[i] = old_str[i];
        }

        for (size_t i = current_size; i < new_size; ++i) {
            new_str[i] = '0';
        }

        return new_str;
    }

    Decimal::Decimal(const size_t n, const unsigned char t): Decimal(n) {
        for (size_t i = 0; i < n; ++i) {
            number_[n - i - 1] = t;
        }
    }

    Decimal::Decimal(const std::initializer_list<unsigned char> & t): Decimal(t.size()) {
        size_t i{0};
        for (const auto & e: t) {
            number_[size_ - i - 1] = e;
            ++i;
        }
    }

    Decimal::Decimal(const std::string & s): Decimal(s.size()) {
        for (size_t i = 0; i < s.size(); ++i) {
            number_[size_ - i - 1] = s[i];
        }
    }

    Decimal::~Decimal() noexcept {
        delete [] number_;
        size_ = 0;
    }

    Decimal Decimal::operator+(const Decimal & other) {
        size_t shared_length = std::max(size_, other.size_);
        auto * first_aligned = LeftPad(number_, size_, shared_length);
        auto * second_aligned = LeftPad(other.number_, other.size_, shared_length);
        int buffer = 0;

        for (size_t i = 0; i < shared_length; ++i) {
            buffer += get_decimal_(first_aligned[i]) + get_decimal_(second_aligned[i]);
            first_aligned[i] = get_char_(buffer % 10);
            buffer /= 10;
        }

        delete [] second_aligned;

        if (buffer != 0) {
            auto * new_str = LeftPad(first_aligned, shared_length, shared_length + 1);
            delete [] first_aligned;
            new_str[shared_length] = get_char_(buffer);

            return Decimal(shared_length + 1, new_str);
        }

        return Decimal(shared_length, first_aligned);
    }

    int Decimal::get_decimal_(const unsigned char & t) {
        return t - '0';
    }

    unsigned char Decimal::get_char_(const int & t) {
        return '0' + t;
    }
}
