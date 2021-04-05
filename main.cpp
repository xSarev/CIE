#include "cie.h"
#include "utils.cpp"
#include <memory>
#include <iostream>
int main(int argc, char **argv)
{   
    // check if image path is valid 
    for (unsigned int i = 0; i < argc; i++)
    {
        if (!Utils::checkImageValid(argv[i]))
        {
            std::cout << "Wrong image path!\n";
            return 0;
        }
    }

    std::shared_ptr<CImageEncryption> pImageEncryption = std::make_shared<CImageEncryption>();
    pImageEncryption->generatePrimeNumbers();
    pImageEncryption->computeAlgorithm();
    pImageEncryption->display();
    pImageEncryption->encrypt(17);
    pImageEncryption->decrypt(17);
}