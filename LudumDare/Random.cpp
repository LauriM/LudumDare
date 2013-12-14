#include <cstdlib>

int randomRange(int min,int max){
	return min + (rand() % (int)(max - min + 1));
}
