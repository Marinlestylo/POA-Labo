//
// Created by Lazar on 02.06.2022.
//
#include "Displayer.hpp"

using namespace std;

Displayer::Displayer(unsigned gridSize, list<Humanoid*>::const_iterator begin,
							list<Humanoid*>::const_iterator end)
							: gridSize(gridSize), begin(begin), end(end) {}
