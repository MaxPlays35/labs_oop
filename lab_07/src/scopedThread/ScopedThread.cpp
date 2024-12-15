//
// Created by MaxPlays on 13/12/2024.
//

#include "ScopedThread.h"

ScopedThread::ScopedThread(const std::function<void()> & func) {
    auto thread = std::thread(func);

    if (!thread.joinable()) {
        throw std::logic_error("Can't join thread");
    }

    thread_ = std::move(thread);
}

ScopedThread::ScopedThread(ScopedThread & other) : thread_(std::move(other.thread_)) {
}

ScopedThread::ScopedThread(ScopedThread && other) noexcept : thread_(std::move(other.thread_)) {
}

ScopedThread & ScopedThread::operator=(ScopedThread && other) noexcept {
    thread_ = std::move(other.thread_);
    return *this;
}

ScopedThread::~ScopedThread() {
    if (thread_.joinable()) thread_.join();
};
