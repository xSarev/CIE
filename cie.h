#include <iostream>
#include <vector>

class CImageEncryption 
{
public:
    CImageEncryption();
    virtual ~CImageEncryption(){};

    /**
     * @brief Will generate our prime numbers 
     */
    void generatePrimeNumbers();

    /**
     * @brief Check if provided number is prime
     */
    bool checkForPrime(const int& prime);

    /**
     * @brief Greatest Common Divisor of two numbers
     */
    bool gcd(int a, int b);

    /**
     * @brief Choose a random coprime number between a and b
     */ 
    int coprime(const int& a, const int& b);

    /**
     * @brief Encrypt provided image
     */
    void encrypt(const int& a);

    /**
     * @brief Decrypt provided image
     */
    void decrypt(const int& a);

    /**
     * dispalye choosen numbers --> to be deleted after
     */
    void display();

    /**
     * @brief Compute RSA keys
     */
    void computeAlgorithm();

private:

    double m_firstPrime;
    double m_secondPrime;
    double m_n;
    // Totient Function
    double m_phi;

    // Public key, should be co-prime it should not 
    // multiple by factors of phi and also not divide by phi
    double m_publicKey;
    double m_privateKey;
};