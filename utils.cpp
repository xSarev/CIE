#include "utils.h"

bool CIEUtils::checkImageValid(std::string imagePath_)
{
    std::ifstream readImage (imagePath_);
    if (readImage)
        return true;
    throw "Provided path doesn't exist!";
}

void CIEUtils::displayImage(std::string imagePath_)
{   
    Magick::Image image;
    try {
        CIEUtils::checkImageValid(imagePath_);
        image.read(imagePath_);
        image.display();
    }
    catch(std::exception &error)
    {
        std::cout << error.what() << std::endl;
        return;
    }
}

int CIEUtils::modularExp(int pixelValue, unsigned int power, long int maxRGB)
{
    int res = 1;

    // update if pixelValue is greater than maxRGB
    pixelValue = pixelValue % maxRGB;

    if (pixelValue == 0)
        return 0;

    while (power > 0)
    {
        if (power & 1)
        {
            res = (res*pixelValue) % maxRGB;
        }
        power = power >> 1;
        pixelValue = (pixelValue * pixelValue) % maxRGB;
    }

    return res;
}

void CIEUtils::startClock(std::clock_t& clock)
{
    clock = std::clock();
}

void CIEUtils::stopClock(std::clock_t& clock, const std::string& text)
{
    std::cout << text << " " << (std::clock() - clock) / (double) CLOCKS_PER_SEC << std::endl;
}