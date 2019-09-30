#include "Structs.h"

struct Random{
	
    static int SeedGenerator(int i, int a, int b, int c, int d, int f);
    static int Random1(int seed,int range);
    static bool Probabilidad(int seed,int prob);
    static int RandomRange(int min,int max);
    static int Shuffle(Mesa * array[20],int seed,int nonulos);//luego puede hacerse un template
};
