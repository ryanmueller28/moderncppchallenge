#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <cmath>

std::vector<unsigned long long> primeFactors (unsigned long long N)
{
    std::vector<unsigned long long> factors;

    while (N % 2 == 0)
    {
        factors.push_back(2);
        N = N / 2;
    }

    for (unsigned long long i = 3; i <= std::sqrt(N); i += 2)
    {
        while (N % i == 0)
        {
            factors.push_back(i);
            N = N / i;
        }
    }

    if (N > 2)
    {
        factors.push_back(N);
    }

    return factors;
}


int main(int argc, char** argv)
{
    unsigned long long initVal;
    if (argc != 2)
    {
        std::cout << "Not enough arguments.";
    }else
    {
        initVal = strtoull(argv[1], NULL, 10);
    }

    auto factors = primeFactors(initVal);
    std::copy(std::begin(factors), std::end(factors), std::ostream_iterator<unsigned long long>(std::cout, " "));
    

    return EXIT_SUCCESS;
}