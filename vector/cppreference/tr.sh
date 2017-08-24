#!/usr/bin/env bash

sed -i 's/std::vector/vector/g' *.cpp
sed -i 's/<vector>/"vector.h"/g' *.cpp

