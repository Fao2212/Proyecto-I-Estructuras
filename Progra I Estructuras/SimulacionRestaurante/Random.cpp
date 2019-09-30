#include "Random.h"
#include "QRandomGenerator"
#include "time.h"
#include "QDebug"

int Random::Random1(int seed,int range){
    std::uniform_int_distribution<int>dist(1,seed);
    int o =  1+dist(*QRandomGenerator::global())%range;
    return o;
}
bool Random :: Probabilidad(int seed,int prob){
    int rand = Random1(seed,100);
    if(rand < prob)
        return true;
    else
        return false;
}

int Random :: RandomRange(int min, int max){
    std::uniform_int_distribution<int>dist(min,max);
    int o =  dist(*QRandomGenerator::global())%(max+1);
    return o;
}

//convertir en template con typename e int
int Random :: Shuffle(Mesa * array[20],int seed,int nonulos){
    std::random_shuffle(&array[0],&array[nonulos]);
    std::random_shuffle(&array[0],&array[nonulos], seed);
}
