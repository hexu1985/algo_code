#!/usr/bin/env bash

sed -i 's/std::priority_queue/priority_queue/g' *.cpp
sed -i 's/<queue>/"priority_queue.h"/g' *.cpp

