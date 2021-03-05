#include <SFML/Graphics.hpp>
#include <grid.hpp>
#include <iostream>

#include "availableColors.hpp"
#include "colorCells.hpp"
#include "grid.hpp"
#include "constants.hpp"

/**
 * this is the position to show in the window
 */ 
Grid::Grid(int x,int y){

    
    posXY[0]=x;
    posXY[1]=y;


}

int Grid::getPosx(){
    return posXY[0];
}
int Grid::getPosy(){
    return posXY[1];
}

