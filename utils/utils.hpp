#include <random>
#include <iostream>
#include <algorithm>
#include <cassert>

using std::default_random_engine;
using std::generate_n;
using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

int randint(int min, int max) //[min, max]
{
    assert(max >= min && "max should not be less than min");
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(min, max); // distribution in range [1, 6]

    return dist(rng);
}

double randouble(double min, double max) //[min, max]
{
    assert(max >= min && "max should not be less than min");
    uniform_real_distribution<double> unif(min, max);
    random_device dev;
    default_random_engine re(dev());

    return unif(re);
}

std::string randstring(size_t length)
{
    auto randchar = []() -> char {
        const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}
