#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include<iostream>
#include "pieces.hpp"
#include "colorCells.hpp"
#include "availableColors.hpp"
#include "axes.hpp"
#include <constants.hpp>

/**
 * defining the default pieces
 */ 
const std::vector<std::vector<sf::Vector2i>> Piece::figuresAvalibles = {
        // T
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(-1,0),
            sf::Vector2i(0,-1)
        },
        // Z
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(0,-1),
            sf::Vector2i(-1,-1)
        },
        // S
        {
            sf::Vector2i(0,0),
            sf::Vector2i(-1,0),
            sf::Vector2i(1,-1),
            sf::Vector2i(0,-1)
        },
        // I
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(-1,0),
            sf::Vector2i(-2,0)
        },
        // O
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(1,-1),
            sf::Vector2i(0,-1)
        },
        // L
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(-1,-1),
            sf::Vector2i(-1,0)
        },
        // J
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(1,-1),
            sf::Vector2i(-1,0)
        },

};
/***
 * creating the piece in the constructor with one kind
 * randomly assigned, that will store after the position of the cells
 * that correspond to that kind and the color that diferentiate
 * from one piece to other piece
 */ 
Piece::Piece() {

    kind=rand()%7;
    
    posXY = figuresAvalibles[kind];
    
    color = AvailableColors(kind);

}

std::vector<sf::Vector2i>   Piece::getPosXY(){
    return posXY;
}

int Piece::getColor(){
    return color;
} 
/**
 * function of rotation that simply change
 * the positions of the piece with multiplying
 */
void Piece::rotate(){
    
    for (int i = 0; i < 4; i++){
        
        int x=posXY[i].y*-1;
        int y=posXY[i].x;
        
        posXY[i].x=x;
        posXY[i].y=y;    
    }


}
/**
 * function that use the axes to know where to move
 * its depending the one event of presskey to be called
 */
void Piece::move(axes direction){

        switch(direction) {
   case EAST:
        for (int i = 0; i < 4; i++){
            posXY[i].x++;
        }
      break; 
   case WEST:
        for (int i = 0; i < 4; i++){
            posXY[i].x--;
        }
      break; 
   default : 
        for (int i = 0; i < 4; i++){
            posXY[i].y++;
        }
}


}