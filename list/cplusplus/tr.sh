#!/usr/bin/env bash

sed -i 's/std::list/list/g' *.cpp
sed -i 's/<list>/"list.h"/g' *.cpp

