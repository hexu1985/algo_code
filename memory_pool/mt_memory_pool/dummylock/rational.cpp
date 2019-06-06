#include "rational.hpp"

MTMemoryPool<MemoryPool<Rational>, DummyLock> *Rational::memPool = 0;
