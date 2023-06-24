#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <unistd.h>
#include <chrono>
#include <cstdio>
#include <ctime>

class Time {
public:
    Time(double milli_seconds);

    void wait();


private:
    double milli_seconds;
    // std::chrono::system_clock::time_point before;
    // std::chrono::system_clock::time_point after;

};


#endif