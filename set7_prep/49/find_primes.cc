#include "main.ih"

std::vector<size_t> findPrimes(size_t count, bool &isFinished)
{
    std::vector<size_t> primes;
    primes.push_back(2);
    size_t next = 3;
    while (primes.size() < count)
    {
        bool isPrime = std::find_if(primes.begin(), primes.end(),
            [next](size_t prime) { return next % prime == 0; }) == primes.end();
        if (isPrime)
            primes.push_back(next);
        next += 2;
    }
    isFinished = true;
    return primes;
}