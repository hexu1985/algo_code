#!/usr/bin/env bash

sed -i 's/std::array/array/g' *.cpp
sed -i 's/<array>/"array.h"/g' *.cpp

