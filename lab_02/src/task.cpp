//
// Created by Aleksandr Mikhailov on 21.09.2024.
//

#include "task.h"

namespace decimal {
    Decimal::Decimal(): number_(nullptr), size_(0) {
        // pass
    }

    Decimal::Decimal(const size_t n) {
        size_ = n;
        number_ = new unsigned char[n + 1];
        number_[n] = '\0';
    }

    Decimal::Decimal(const std::string &s, size_t n) {
        size_ = n;
        number_ = new unsigned char[n + 1];
        number_[n] = '\0';

        for (size_t i = 0; i < n; ++i) {
            number_[i] = s[i];
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

    Decimal::Decimal(const Decimal &other): Decimal(other.size_) {
        for (size_t i = 0; i < size_; ++i) {
            number_[i] = other.number_[i];
        }
    }

    Decimal::Decimal(Decimal &&other) noexcept {

    }

    Decimal::~Decimal() noexcept {
        delete [] number_;
        size_ = 0;
    }

    Decimal Decimal::operator+(const Decimal & other) const {
        size_t shared_length = std::max(size_, other.size_);
        auto first_aligned = LeftPad(number_, size_, shared_length);
        auto second_aligned = LeftPad(other.number_, other.size_, shared_length);
        int buffer = 0;

        for (size_t i = 0; i < shared_length; ++i) {
            buffer += get_decimal(first_aligned[i]) + get_decimal(second_aligned[i]);
            first_aligned[i] = get_char(buffer % 10);
            buffer /= 10;
        }

        if (buffer != 0) {
            first_aligned.push_back(get_char(buffer));
            ++shared_length;
        }

        return Decimal(first_aligned, shared_length);
    }

    Decimal Decimal::operator-(const Decimal &other) const {
        if (*this < other) {
            throw std::out_of_range("Decimal::operator-");
        }

        auto first_copy = LeftPad(number_, size_, size_);
        auto second_copy = LeftPad(other.number_, other.size_, size_);
        bool borrow = false;

        for (size_t i = 0; i < size_; ++i) {
            int left_digit = get_decimal(first_copy[i]);
            int right_digit = get_decimal(second_copy[i]);

            if (borrow) {
                --left_digit;
                borrow = false;
            }

            if (left_digit < right_digit) {
                left_digit += 10;
                borrow = true;
            }

            first_copy[i] = get_char(left_digit - right_digit);
        }

        size_t non_zero_count = size_;
        while (non_zero_count > 1 && first_copy[non_zero_count - 1] == '0') {
            --non_zero_count;
        }


        return Decimal(first_copy, non_zero_count);
    }

    Decimal & Decimal::operator+=(const Decimal &other) {
        auto result = *this + other;
        swap(*this, result);

        return *this;
    }

    Decimal & Decimal::operator-=(const Decimal &other) {
        auto result = *this - other;
        swap(*this, result);

        return *this;
    }

    bool Decimal::operator==(const Decimal &other) const {
        if (size_ != other.size_) {
            return false;
        }

        for(size_t i = 0; i < size_; ++i) {
            if (number_[i] != other.number_[i]) {
                return false;
            }
        }

        return true;
    }

    bool Decimal::operator!=(const Decimal &other) const {
        return !(*this == other);
    }

    bool Decimal::operator>(const Decimal &other) const {
        if (size_ != other.size_) {
            return size_ > other.size_;
        }

        for(size_t i = 0; i < size_; ++i) {
            if (number_[i] == other.number_[i]) {
                continue;
            }

            return number_[i] > other.number_[i];
        }

        return false;
    }

    bool Decimal::operator<(const Decimal &other) const {
        if (size_ != other.size_) {
            return size_ < other.size_;
        }

        for(size_t i = 0; i < size_; ++i) {
            if (number_[i] == other.number_[i]) {
                continue;
            }

            return number_[i] < other.number_[i];
        }

        return false;
    }

    Decimal & Decimal::operator=(const Decimal & other) {
        auto copy = Decimal(other);
        swap(*this, copy);

        return *this;
    }

    Decimal & Decimal::operator=(Decimal &&other)  noexcept {
        swap(*this, other);
        return *this;
    }

    std::string LeftPad(const unsigned char * old_str, const size_t & current_size,
                        const size_t & new_size) {
        std::string new_str(new_size, '0');

        for (size_t i = 0; i < current_size; ++i) {
            new_str[i] = old_str[i];
        }

        return new_str;
    }

    int get_decimal(const unsigned char & t) {
        return t - '0';
    }

    unsigned char get_char(const int & t) {
        return '0' + t;
    }

    void Decimal::swap(Decimal & a, Decimal & b) noexcept {
        a.number_ = b.number_;
        a.size_ = b.size_;

        b.size_ = 0;
        b.number_ = nullptr;
    }
}
