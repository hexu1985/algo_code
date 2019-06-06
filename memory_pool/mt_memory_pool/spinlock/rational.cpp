#include "rational.hpp"

MTMemoryPool<MemoryPool<Rational>, spinlock_mutex> *Rational::memPool = 0;
