#include <memory>
#include <iostream>
#include <thread>

#include "cie.h"
#include "utils.cpp"

static void displayImages(int argc, char **argv)
{
    // check if image path is valid 
    for (unsigned int i = 0; i < argc; i++)
    {
        Utils::displayImage(argv[i]);
    }   
}

int main(int argc, char **argv)
{   
    Magick::InitializeMagick(*argv);

    std::thread thread1(displayImages, argc, argv);

    std::shared_ptr<CImageEncryption> pImageEncryption = std::make_shared<CImageEncryption>();
    pImageEncryption->generatePrimeNumbers();
    pImageEncryption->computeAlgorithm();
    pImageEncryption->display();
    pImageEncryption->encrypt(17);
    pImageEncryption->decrypt(17);

    // wait thread to finish
    thread1.join();
}