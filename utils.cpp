#include <iostream>
#include <fstream>

#if defined(__linux__)
#include "Magick++.h"
#endif

namespace Utils{
    inline bool checkImageValid(std::string path){
        std::ifstream readImage (path);
        if (readImage)
            return true;
        return false;
    }
}