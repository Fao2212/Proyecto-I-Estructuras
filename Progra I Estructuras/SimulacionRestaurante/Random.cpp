#include "Random.h"
#include "QRandomGenerator"
#include "time.h"
#include "QDebug"
#include "Mesa.h"

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

void Random :: Shuffle(Mesa * array[20],int nonulos){
    nonulos -= 1;

    for(int i = 0; i < nonulos;i++){
        int index = RandomRange(0,nonulos);
        Mesa * temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
    }

/*
int main(int argc, char *argv[])
{
    for(int i = 0;i<2000;i++){
        qDebug()<<Random::RandomRange(0,20);
    }

    Mesa * array[20];
    for(int i = 0;i<20;i++){
        array[i] = new Mesa(i);
    }
    for(int i = 0;i<1000;i++){
        qDebug()<<i;
    Random::Shuffle(array,20);
    for(int i = 0;i<20;i++){
    qDebug()<<array[i]->numeroDeMesa;
    }
    }
    return 0;
}
*/
