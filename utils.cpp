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
