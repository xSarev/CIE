//  include guards.

#ifndef _UTILS_CIE_H_
#define _UTILS_CIE_H_

#include <iostream>
#include <fstream>
#include <ctime>

#if defined(__linux__)
#include "Magick++.h"
#endif

namespace CIEUtils{
    
    bool checkImageValid(std::string imagePath_);

    void displayImage(std::string imagePath_);

    int modularExp(int pixelValue, unsigned int power, long int maxRGB=65536);

    void startClock(std::clock_t& start);
    void stopClock(std::clock_t& stop, const std::string& text);
}

#endif // _UTILS_CIE_H_