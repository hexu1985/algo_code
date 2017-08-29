#!/usr/bin/env bash

sed -i 's/std::map/map/g' *.cpp
sed -i 's/<map>/"map.h"/g' *.cpp

