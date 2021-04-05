#include <iostream>
#include <fstream>

#if defined(__linux__)
#include "Magick++.h"
#endif

namespace Utils{
    inline bool checkImageValid(std::string imagePath_)
    {
        std::ifstream readImage (imagePath_);
        if (readImage)
            return true;
        throw "Provided path doesn't exist!";
    }

    inline void displayImage(std::string imagePath_)
    {   
        Magick::Image image;
        try {
            checkImageValid(imagePath_);
            image.read(imagePath_);
            image.display();
        }
        catch( std::exception &error)
        {
            std::cout << error.what() << std::endl;
            return;
        }
    }
}