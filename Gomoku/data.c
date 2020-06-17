#include"data.h"

int FlipCoin(void)
{
	srand(time(NULL));
	return rand() % 2;
}
