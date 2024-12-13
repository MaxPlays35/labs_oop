//
// Created by MaxPlays on 13/12/2024.
//
#pragma once
#include <functional>
#include <thread>

class ScopedThread {
private:
    std::thread thread_;
public:
    ScopedThread() = delete;

    explicit ScopedThread(const std::function<void()>& func);

    ScopedThread(ScopedThread & other);

    ScopedThread(ScopedThread && other) noexcept ;

    ScopedThread& operator=(ScopedThread &&other) noexcept;

    ~ScopedThread();
};
