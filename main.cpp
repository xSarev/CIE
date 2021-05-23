#include <memory>
#include <iostream>
#include <thread>

#include "cie.h"
#include "utils.h"

static void displayImages(int argc, char **argv)
{
    // check if image path is valid 
    for (unsigned int i = 0; i < argc; i++)
    {
        CIEUtils::displayImage(argv[i]);
    }   
}

int main(int argc, char **argv)
{   
    Magick::InitializeMagick(*argv);

    // std::thread thread1(displayImages, argc, argv);

    std::shared_ptr<CImageEncryption> pImageEncryption = std::make_shared<CImageEncryption>();
    Magick::Image inputImage;

    try {
        CIEUtils::checkImageValid(argv[1]);
        inputImage.read(argv[1]);
    }
    catch(std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }

    pImageEncryption->generatePrimeNumbers();
    pImageEncryption->computeAlgorithm();
    pImageEncryption->display();
    pImageEncryption->encrypt(inputImage);

    try {
        CIEUtils::checkImageValid("encrypted_image.png");
        inputImage.read("encrypted_image.png");
    }
    catch(std::exception &error)
    {
        std::cout << error.what() << std::endl;
    }
    
    pImageEncryption->decrypt(inputImage);

    // wait thread to finish
    // thread1.join();
}