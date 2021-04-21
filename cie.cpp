#include "cie.h"
#include <math.h>
#include <time.h>  

CImageEncryption::CImageEncryption()
    :m_firstPrime(0),
    m_secondPrime(0),
    m_n(0),
    m_phi(0),
    m_publicKey(0),
    m_privateKey(0)
{}

bool CImageEncryption::checkForPrime(const int& prime)
{
    if (prime < 0)
    {
        throw "Number is less than 0!";
    }

    for(unsigned i = 2; i <= sqrt(prime); i++)
    {
        if (prime % i == 0)
            return false;
    }

    return true;
}

bool CImageEncryption::gcd(int a, int b)
{
    if (!a) 
    {
        if (b > 1)
            return false;
        else 
            return true;
    }

    return this->gcd(b % a, a);
}

void CImageEncryption::generatePrimeNumbers()
{
    double iSecret;

     /* initialize random seed: */
        srand(time(NULL));
        
    while(true)
    {
        iSecret = (rand() % 10) + 10;
        // iSecret = (rand() % 10000) + 1000;
        if(this->checkForPrime(iSecret) == true)
        {
            if(!this->m_firstPrime){
                this->m_firstPrime = iSecret;
            } 
            else if(!this->m_secondPrime){
                this->m_secondPrime = iSecret;
                break;
            }
        }
    }
}

void CImageEncryption::display()
{
    std::cout << "\nFirst choosen number : " << this->m_firstPrime; 
    std::cout << "\nSecond number : " << this->m_secondPrime;
    std::cout << "\nN number : " << this->m_n;
    std::cout << "\nPhi number : " << this->m_phi;
    std::cout << "\nPublic Key: " << this->m_publicKey;
    std::cout << "\nPrivate Key : " << this->m_privateKey;
}

void CImageEncryption::computeAlgorithm()
{
    this->m_n = m_firstPrime * m_secondPrime;
    this->m_phi = (m_firstPrime - 1) * (m_secondPrime - 1);

    // public key
    this->m_publicKey = this->coprime(this->m_n, this->m_phi);

    // private key 
    this->m_privateKey = std::fmod(1/this->m_publicKey, this->m_phi);
}

int CImageEncryption::coprime(const int& a, const int& b)
{
    std::vector<int> coprimesNumbers;

    for (int i = 2; i < b; i++)
    {
        if(this->gcd(i, a) && this->gcd(i, b))
            coprimesNumbers.push_back(i);
    }

    return coprimesNumbers[rand()%coprimesNumbers.size()];
}

void CImageEncryption::encrypt(const Magick::Image& image)
{   
    Magick::Image encryptImage(image);

    // get image width and height
    unsigned int rows = encryptImage.rows();
    unsigned int columns = encryptImage.columns();

    // Ensure that there are no other references to this image.
    encryptImage.modifyImage();

    Magick::Pixels view(encryptImage);

    // Declare default color
    Magick::Color green("GREEN");

    // std::cout << "\nEncrypted message : " << std::pow(a, this->m_publicKey);
    for(unsigned int i = 0; i < rows; i++)
    {
        for(unsigned int j = 0; j < columns; j++)
        {
            Magick::PixelPacket *pixelCache = view.get(i, j, 1, 1);
            // Magick::PixelPacket *pixel = pixelCache + row 
        }
    }

    // Save changes to image.
    view.sync();

}

void CImageEncryption::decrypt(const Magick::Image& image)
{   
    // double encrypt = std::pow(a, this->m_publicKey);
    // std::cout << "\nDecrypted message : " << std::pow(encrypt, this->m_privateKey);
    // std::cout << "\n";
}