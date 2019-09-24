#include "Random.h"
#include "QRandomGenerator"
#include "time.h"
#include "QDebug"

int Random::Random1(int seed,int range){
    std::uniform_int_distribution<int>dist(1,seed);
    int o =  1+dist(*QRandomGenerator::global())%range;
    return o;
}

