#!/usr/bin/env bash

sed -i 's/std::queue/queue/g' *.cpp
sed -i 's/<queue>/"queue.h"/g' *.cpp

