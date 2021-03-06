#include "Map.h"
#include "drawTiles.h"

int world[64][64] = {  //matrix for the world but will be read from a database in the future
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,3,0,3,0,2,0,0,0,0,0,0,0,2,3,0,0,0,0,0,3,3,0,2,0,0,0,0,3,0,0,0,0,0,3,2,3,2,0,0,3,0,0,0,3,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,2,1},
{1,0,0,0,2,2,0,0,3,2,2,2,0,2,0,0,2,2,3,0,3,2,0,0,0,0,0,2,3,0,0,3,2,0,0,0,2,0,0,0,2,2,0,2,0,0,0,0,2,0,0,0,2,0,0,2,0,0,2,0,2,2,0,1},
{1,0,2,2,0,0,0,0,2,0,3,0,2,0,0,0,0,0,0,0,0,0,2,0,2,2,0,0,2,2,0,3,0,2,0,0,0,2,2,0,0,0,0,3,0,0,2,3,0,3,2,0,2,2,0,0,0,3,0,2,0,0,0,1},
{1,0,0,0,0,0,0,2,2,3,0,3,0,0,3,3,0,0,0,2,0,0,0,0,2,2,0,0,2,0,2,0,3,0,2,0,0,0,0,0,0,0,3,2,3,0,0,0,0,0,0,0,0,2,3,0,3,3,0,0,2,0,2,1},
{1,0,2,0,2,2,0,2,0,0,0,0,0,2,0,0,0,3,0,0,0,0,0,0,0,3,2,0,2,0,2,0,0,3,0,0,2,0,3,0,3,0,0,0,3,3,0,0,0,0,0,0,2,3,0,0,3,3,0,2,0,0,0,1},
{1,0,3,3,0,0,2,0,2,3,0,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,3,0,0,0,2,0,0,3,3,0,0,0,3,3,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,3,2,2,2,0,3,0,0,0,0,0,2,0,0,2,2,0,0,0,0,0,3,0,0,3,2,0,0,0,1},
{1,0,0,2,2,0,0,3,3,0,0,2,0,0,1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3,0,2,0,0,0,0,0,2,0,0,2,2,0,0,0,2,0,2,3,2,2,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,3,2,0,0,2,2,0,0,0,3,0,0,0,2,0,0,0,0,2,2,3,0,2,0,0,0,0,0,0,3,0,0,0,3,0,3,0,2,0,0,3,2,0,0,2,2,0,3,0,2,0,0,0,1},
{1,0,2,0,0,0,2,0,0,3,0,0,3,2,0,0,0,0,3,0,0,0,0,0,0,2,0,3,0,3,2,0,0,0,0,0,0,3,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,2,0,2,1},
{1,2,0,0,0,0,0,0,3,3,2,0,0,0,3,2,0,0,1,0,0,3,2,2,2,0,2,0,0,0,0,0,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,2,3,0,0,0,0,2,0,3,0,3,0,0,3,1},
{1,0,0,0,0,0,0,0,2,3,0,2,0,0,1,0,0,0,0,2,0,0,2,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,2,0,0,0,0,2,0,0,0,2,2,0,2,2,0,0,0,0,0,2,0,0,2,2,1},
{1,2,0,0,3,2,2,0,0,0,2,0,0,3,0,3,0,0,0,2,2,0,0,0,3,0,2,0,0,0,0,0,2,2,0,2,0,2,3,0,3,0,0,2,0,0,2,0,0,0,2,0,3,0,0,0,0,0,0,2,0,2,0,1},
{1,2,0,0,2,0,0,0,0,2,0,3,0,3,0,3,0,0,0,0,0,0,0,0,2,0,0,2,1,3,0,0,0,3,0,3,3,0,2,0,0,0,0,0,3,0,0,3,0,0,0,0,0,2,0,0,0,3,0,0,0,0,2,1},
{1,0,0,0,0,0,3,0,0,2,2,0,3,3,0,0,0,2,0,0,0,2,2,0,2,0,2,2,0,3,0,0,0,2,2,0,3,0,1,0,3,3,0,3,0,2,0,2,3,0,2,0,2,0,0,0,0,0,3,0,0,0,2,1},
{1,0,0,0,0,0,0,3,0,0,0,3,0,0,0,2,0,0,0,2,0,0,2,2,0,0,3,0,3,0,0,2,0,0,0,0,3,0,0,2,3,0,0,0,0,0,3,2,0,0,0,0,3,0,0,3,0,3,0,0,0,2,0,1},
{1,0,0,3,2,0,0,0,0,0,0,0,0,3,2,0,0,0,0,0,2,0,2,0,0,0,3,0,0,0,0,0,0,2,0,0,0,0,0,3,2,0,0,0,0,2,0,0,3,0,2,2,2,3,0,0,2,0,2,0,0,0,2,1},
{1,0,0,0,0,0,0,3,0,3,0,2,0,0,3,0,0,0,0,0,0,0,0,0,2,0,0,0,0,3,0,2,2,0,3,0,2,2,0,0,2,0,0,2,0,0,0,0,3,3,3,0,0,0,3,2,0,3,0,0,3,0,0,1},
{1,2,0,3,0,0,0,3,2,2,0,0,0,2,3,2,0,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,2,3,0,2,3,0,0,0,0,2,3,0,0,0,2,0,0,2,0,2,0,0,0,0,0,0,3,0,3,1},
{1,2,2,3,0,2,0,0,3,2,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,3,0,0,3,0,0,0,0,2,0,0,0,0,0,0,0,2,2,0,0,2,0,0,0,0,2,0,1,0,0,0,3,0,3,2,0,2,0,1},
{1,0,0,2,2,2,3,2,0,0,2,0,2,2,1,3,0,0,3,2,0,0,0,0,2,0,2,0,0,2,0,0,0,0,2,0,0,0,0,2,2,0,0,3,2,3,0,0,2,0,0,0,3,2,0,0,0,3,0,1,0,3,0,1},
{1,0,2,0,0,0,0,2,2,0,0,0,0,2,2,0,2,2,0,0,0,2,3,0,0,0,1,0,2,0,0,2,0,0,0,0,0,2,0,0,0,2,0,0,0,2,0,3,3,2,0,0,0,0,3,0,0,0,0,2,0,3,0,1},
{1,2,3,2,0,0,0,0,0,0,2,3,0,0,3,0,0,3,0,0,3,0,0,0,0,1,2,2,0,0,0,2,0,0,0,2,3,0,3,0,2,0,0,0,0,0,0,3,0,2,3,3,3,0,0,2,2,0,0,0,0,3,0,1},
{1,3,2,0,0,0,3,2,3,2,0,2,2,0,3,0,2,2,0,0,3,0,2,0,0,3,0,3,3,3,3,2,0,0,0,0,0,0,2,3,0,0,0,1,2,0,2,0,0,2,0,0,0,0,0,0,0,2,0,0,3,0,2,1},
{1,0,3,0,3,0,0,0,0,0,3,0,0,2,0,0,3,2,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,3,0,2,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,3,0,0,2,3,0,3,0,0,0,1},
{1,2,0,2,0,0,0,3,0,3,0,0,2,0,3,2,2,0,0,0,0,2,0,3,0,0,0,0,3,2,0,0,0,0,0,0,0,0,2,3,2,0,0,0,0,0,0,3,2,0,0,2,0,0,0,3,0,0,0,2,0,3,0,1},
{1,3,2,0,2,0,0,0,0,0,0,0,0,0,0,3,0,3,0,0,2,3,0,2,0,2,0,0,0,2,2,0,0,3,0,0,2,0,2,0,2,2,2,2,0,0,3,0,3,0,0,0,0,0,0,0,0,0,0,0,2,0,0,1},
{1,1,3,2,0,0,1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,2,0,0,2,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,2,3,0,0,0,2,0,2,0,2,0,0,0,0,3,0,0,1},
{1,3,2,0,1,0,2,0,0,0,0,3,0,0,2,2,0,0,0,0,0,0,0,3,0,3,0,0,0,0,2,2,0,0,0,0,0,2,0,0,0,3,0,0,0,0,0,0,0,0,0,2,0,2,3,2,2,0,2,0,0,2,0,1},
{1,0,2,0,3,0,0,3,2,0,0,1,0,2,2,0,0,3,2,0,0,3,3,0,0,0,0,0,0,1,2,0,0,0,0,2,3,0,0,2,0,3,2,0,2,0,0,0,0,3,0,2,0,1,0,0,0,2,0,0,0,0,0,1},
{1,0,0,0,3,3,0,2,0,3,2,0,0,3,3,0,3,0,3,3,0,0,1,2,3,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,3,0,0,0,3,0,0,0,2,2,0,1},
{1,3,0,0,0,0,3,0,0,2,0,0,0,3,3,0,0,0,0,0,3,2,0,0,0,0,2,0,2,2,2,0,0,0,2,3,0,0,0,0,0,0,0,0,0,0,3,3,2,0,3,2,2,2,0,2,0,0,0,0,0,0,2,1},
{1,0,0,0,0,0,0,0,0,0,2,0,2,3,0,0,0,0,0,0,0,0,0,2,2,0,2,0,3,0,0,0,2,0,0,3,0,2,0,0,0,2,0,0,0,0,3,0,0,2,0,0,3,0,0,0,0,2,0,2,0,0,0,1},
{1,2,2,0,2,0,0,0,0,2,3,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,3,3,0,2,2,0,3,3,0,0,0,3,2,2,2,0,3,0,0,0,0,2,2,2,3,0,0,2,0,0,3,0,2,0,3,1},
{1,2,0,2,0,3,2,3,2,0,0,2,2,0,0,1,2,0,0,2,2,3,2,2,3,2,3,0,3,2,0,1,0,2,0,0,2,2,0,0,3,0,0,0,0,0,0,0,2,2,3,0,2,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,2,0,2,0,0,2,0,0,0,3,0,0,0,0,3,3,0,2,0,0,3,0,0,0,0,3,2,2,0,2,0,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,0,3,0,3,3,0,0,0,0,0,0,0,0,1},
{1,3,0,0,0,0,0,0,0,2,3,3,2,0,2,0,0,0,0,3,0,3,0,2,0,0,2,2,0,0,0,0,2,0,0,0,0,0,0,0,2,2,3,0,0,0,0,0,2,0,0,0,0,3,0,0,0,0,2,2,0,0,0,1},
{1,0,0,0,0,3,0,0,3,3,0,2,0,2,2,2,0,0,3,2,3,3,2,2,0,3,0,2,0,0,0,0,0,0,0,3,0,0,2,0,0,0,0,2,0,3,0,0,0,0,0,2,0,2,2,0,0,2,0,0,2,0,2,1},
{1,0,3,3,0,0,2,0,0,3,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,3,2,0,3,0,0,0,0,0,0,0,0,2,0,3,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,3,0,0,1},
{1,0,0,3,0,0,2,0,0,0,2,0,2,0,0,0,3,3,0,0,0,0,0,3,0,2,0,0,0,2,0,2,0,3,0,2,0,0,2,2,0,3,3,0,2,0,3,0,0,3,2,3,0,3,2,0,0,0,0,2,0,0,0,1},
{1,3,0,2,3,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0,0,0,2,3,0,0,0,0,3,2,0,0,2,0,0,2,2,3,0,0,0,0,2,0,0,0,0,1,0,0,1},
{1,0,0,0,2,0,3,0,0,3,2,3,0,2,0,0,0,0,0,2,3,0,0,0,0,5,5,5,5,5,2,3,2,0,0,3,0,0,3,0,0,0,0,0,3,0,0,2,3,3,0,0,0,3,0,0,0,0,0,0,0,0,0,1},
{1,0,0,3,2,0,3,0,0,2,0,3,2,0,0,0,3,3,0,0,0,0,0,2,5,5,5,5,5,6,6,3,0,2,0,3,0,2,0,0,0,2,0,0,2,0,0,0,0,0,0,0,3,3,0,0,0,2,0,0,2,2,2,1},
{1,0,0,0,0,0,0,0,0,0,2,3,2,0,0,3,0,0,2,0,0,0,2,0,5,6,5,5,5,5,5,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,2,3,0,0,0,1,2,0,0,0,0,0,0,3,1},
{1,0,2,0,0,0,2,2,3,0,0,2,0,0,0,0,0,0,0,0,0,3,3,0,5,5,5,4,5,6,5,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,2,0,0,2,0,0,0,0,0,0,0,3,0,0,2,0,2,1},
{1,2,0,0,2,0,1,3,0,0,0,0,0,0,2,3,3,0,0,0,2,0,2,2,5,5,5,5,5,6,5,3,3,0,0,0,0,0,0,0,0,2,0,2,2,1,3,0,0,3,0,0,0,2,0,2,2,2,0,0,0,0,0,1},
{1,0,2,2,0,0,2,3,0,3,0,0,2,0,2,3,0,0,0,2,0,0,0,0,5,5,5,5,5,5,5,0,0,0,3,0,0,3,0,2,0,2,3,0,2,3,2,0,0,0,0,2,0,0,0,0,2,0,2,2,0,0,0,1},
{1,0,0,2,2,3,2,0,2,0,0,0,0,3,0,0,0,2,0,0,0,0,0,0,0,6,5,5,5,5,3,0,0,3,0,0,0,0,0,0,2,0,0,3,0,0,0,0,0,2,0,0,0,2,0,0,0,3,3,0,0,0,0,1},
{1,2,2,0,0,2,0,2,0,2,0,0,0,2,0,3,2,0,2,0,0,0,2,0,3,2,2,2,0,0,3,0,0,2,2,0,0,0,2,2,0,2,2,0,0,0,0,0,3,0,2,3,0,0,0,3,0,0,3,0,3,0,3,1},
{1,0,0,2,2,0,0,0,0,0,0,2,3,0,0,0,0,2,0,0,0,0,2,0,0,3,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,3,0,0,2,0,3,1,0,0,0,0,3,2,2,0,0,0,0,0,2,3,0,1},
{1,2,2,0,3,0,2,3,2,0,0,0,2,0,0,2,0,2,0,0,0,2,0,2,0,0,3,0,2,2,0,0,3,0,0,2,0,0,0,0,2,0,2,0,2,0,2,0,0,0,0,0,0,0,2,0,0,0,0,3,0,2,2,1},
{1,0,0,0,3,0,0,0,0,3,2,0,0,2,0,2,0,0,0,2,2,3,0,3,3,0,0,2,2,0,3,0,0,2,0,2,2,2,0,0,0,2,0,0,0,0,0,0,0,0,3,0,2,3,0,2,0,2,0,2,0,0,0,1},
{1,3,0,0,0,0,3,0,2,0,2,0,0,0,0,3,2,3,0,0,2,0,0,0,0,0,0,0,0,0,0,3,2,0,2,0,3,0,2,3,3,2,0,0,0,0,0,3,0,0,2,0,0,0,2,2,0,0,0,3,0,0,0,1},
{1,2,3,0,0,0,0,0,0,0,3,0,0,0,2,0,2,0,0,0,0,0,0,0,2,3,0,2,0,3,0,0,0,0,0,2,0,2,0,2,0,0,0,0,3,0,0,3,0,0,0,0,0,0,0,0,2,3,2,0,0,2,2,1},
{1,0,0,0,2,3,2,0,0,3,0,0,0,3,3,0,2,0,0,0,0,0,0,0,2,0,0,0,0,0,0,3,2,0,0,3,0,3,0,0,0,0,0,2,0,0,0,0,3,3,2,2,0,3,0,0,0,0,0,2,0,2,0,1},
{1,2,0,3,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,0,2,0,0,2,0,3,0,3,0,0,3,0,2,2,0,3,0,2,2,0,0,3,0,2,2,0,0,3,2,0,1,0,0,3,0,0,2,3,2,2,0,0,0,1},
{1,2,2,0,2,0,2,3,3,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,2,0,2,0,0,3,2,0,0,3,2,0,2,0,0,0,2,2,0,0,0,0,2,0,0,0,3,0,0,1},
{1,0,0,0,2,2,0,2,0,0,0,0,2,2,0,2,0,0,0,3,0,0,3,0,0,3,0,2,0,0,0,0,0,0,0,0,2,2,0,0,0,0,3,0,0,3,3,0,0,2,2,0,0,0,2,0,0,0,2,0,3,0,3,1},
{1,3,0,2,0,0,2,2,2,2,2,3,0,0,0,0,0,0,0,0,0,0,3,0,3,0,0,0,0,0,0,0,0,0,2,0,0,0,2,0,0,2,0,0,3,0,2,0,0,3,0,0,0,0,0,2,0,0,2,3,0,2,3,1},
{1,0,2,2,0,0,0,3,0,0,0,0,0,2,0,0,2,0,0,2,0,2,2,2,0,3,0,0,0,0,0,0,3,0,0,2,2,2,0,0,2,0,2,0,0,0,0,0,0,0,2,2,0,2,0,0,3,0,0,0,0,0,0,1},
{1,0,0,2,3,0,3,0,3,2,0,2,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,3,0,0,2,3,3,2,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,3,0,0,0,1},
{1,0,0,2,1,0,0,3,0,0,2,0,0,0,0,0,0,0,0,0,3,0,2,0,0,3,3,0,0,0,0,2,0,3,0,0,0,0,0,2,0,0,0,2,0,2,2,0,0,0,3,0,0,2,0,0,3,2,2,0,3,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

Map::Map(SDL_Renderer * render)
{
	xmoved = 0;
	ymoved = 0;
	night = false;


	grass = TextureController::LoadTexture("Images/grass.png", render);
	darkGrass = TextureController::LoadTexture("Images/darkGrass.png", render);
	water = TextureController::LoadTexture("Images/water.png", render);
	darkWater = TextureController::LoadTexture("Images/darkwater.png", render);
	tree = TextureController::LoadTexture("Images/tree.png", render);
	darkTree = TextureController::LoadTexture("Images/darkTree.png", render);
	longGrass = TextureController::LoadTexture("Images/longGrass.png", render);
	darkLongGrass = TextureController::LoadTexture("Images/darklongGrass.png", render);
	fire = TextureController::LoadTexture("Images/fire.png", render);
	fireGrass = TextureController::LoadTexture("Images/fireGrass.png", render);
	fireTree = TextureController::LoadTexture("Images/fireTree.png", render);
	fadedFire = TextureController::LoadTexture("Images/fadedFire.png", render);

	//TextureController::LoadTexture(texturePanel, render);

	LoadMap(world);

	int zoom = 1;
	int zoomSize = 32 * zoom;

	scr.x = scr.y = 0;
	scr.w = dest.w = zoomSize;
	scr.h = dest.h = zoomSize;

	dest.x = dest.y = 0;
}


void Map::LoadMap(int arr[64][64]) {
	for (int row = 0; row < 64; row++) {
		for (int column = 0; column < 64; column++) {
			world[row][column] = arr[row][column]; 
		}
	}
}

void Map::DrawMap(int xmoved, int ymoved, bool night) {

	int type = 0;
	for (int row = ymoved; row < (64 + ymoved); row++) {
		for (int column = xmoved; column < (64 + xmoved); column++) {

			type = world[row][column];

			int zoom = 1;
			int zoomSize = 32 * zoom;

			dest.x = (column - xmoved) * zoomSize; //zoomSize;
			dest.y = (row - ymoved) * zoomSize;


			switch (type) {
			case 0: //renders the grass texture
				if (night) {
					drawTiles::Draw(darkGrass, scr, dest);
				}
				else {
					drawTiles::Draw(grass, scr, dest);
				}
				break;
			case 1: //renders the water
				if (night) {
					drawTiles::Draw(darkWater, scr, dest);
				}
				else {
					drawTiles::Draw(water, scr, dest);
				}
				break;
			case 2: //renders any trees
				//TextureController::Draw(tree, scr, dest);
				if (night) {
					drawTiles::Draw(darkTree, scr, dest);
				}
				else {
					drawTiles::Draw(tree, scr, dest);
				}
				break;
			case 3: //renders the long grass
				//TextureController::Draw(longGrass, scr, dest);
				if (night) {
					drawTiles::Draw(darkLongGrass, scr, dest);
				}
				else {
					drawTiles::Draw(longGrass, scr, dest);
				}
				break;
			case 4:
				if (night) {
					drawTiles::Draw(fire, scr, dest);
				}
				else {
					drawTiles::Draw(fadedFire, scr, dest);
				}
				break;
			case 5:
				if (night) {
					drawTiles::Draw(fireGrass, scr, dest);
				}
				else {
					drawTiles::Draw(grass, scr, dest);
				}
				break;
			case 6:
				if (night) {
					drawTiles::Draw(fireTree, scr, dest);
				}
				else {
					drawTiles::Draw(tree, scr, dest);
				}
				break;
			default:
				break;
			}
		}
	}
}

Map::~Map()
{
}