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

    std::clock_t rsaTime;

    CIEUtils::startClock(rsaTime);
    pImageEncryption->encrypt(inputImage);
    CIEUtils::stopClock(rsaTime, "Encrypted Time");
    
    CIEUtils::startClock(rsaTime);
    pImageEncryption->decrypt(inputImage);
    CIEUtils::stopClock(rsaTime, "Decrypted Time");

    // wait thread to finish
    // thread1.join();
}