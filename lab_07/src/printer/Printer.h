//
// Created by MaxPlays on 13/12/2024.
//
#pragma once
#include <iostream>
#include <shared_mutex>

static std::shared_mutex printMutex;

class Printer {
private:
    std::shared_mutex mutex_;
    std::ostream & os_;
public:
    explicit Printer(std::ostream & os);

    template<class T>
    Printer & operator<<(T t) {
        std::shared_lock lock(printMutex);
        os_ << t;
        return *this;
    }

    Printer & operator<<(std::ostream& (*fun)(std::ostream&));
};

static Printer printer(std::cout);
