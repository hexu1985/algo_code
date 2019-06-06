#include "rational.hpp"

MTMemoryPool<MemoryPool<Rational>, std::mutex> *Rational::memPool = 0;
