#include <random>
/**
 * @see https://cpprefjp.github.io/reference/random/uniform_real_distribution.html
 */
std::random_device seed_gen;
std::default_random_engine engine(seed_gen);
using Random_int = std::uniform_int_distribution<int>;
using Random_double = std::uniform_real_distribution<double>;
