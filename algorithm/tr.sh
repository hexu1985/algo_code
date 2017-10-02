#!/usr/bin/env bash

#sed -i 's/std::list/list/g' *.cpp
sed -i '' 's/<algorithm>/"algorithm.h"/g' *.cpp

