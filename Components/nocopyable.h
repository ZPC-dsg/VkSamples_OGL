#pragma once

class NoCopyable {
protected:
    NoCopyable() = default;
    ~NoCopyable() = default;

    NoCopyable(const NoCopyable&) = delete;
    NoCopyable(NoCopyable&&) = delete;
    NoCopyable& operator=(const NoCopyable&) = delete;
    NoCopyable& operator=(NoCopyable&&) = delete;
};