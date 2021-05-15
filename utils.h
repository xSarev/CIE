#ifndef _UTILS_CIE_H_
#define _UTILS_CIE_H_

#include <iostream>
#include <fstream>

#if defined(__linux__)
#include "Magick++.h"
#endif

namespace CIEUtils{
    
    bool checkImageValid(std::string imagePath_);

    void displayImage(std::string imagePath_);
}

#endif // _UTILS_CIE_H_