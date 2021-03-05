#ifndef GRID_CLASS
#define GRID_CLASS

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "constants.hpp"

class Grid
{
   /**
    * the idea here was to create a matrix which help to understand
    * what happen with the states of the game, before showing 
    * 
    */
    public:
        Grid(int x, int y);
        ~Grid();

        /**
         * here it supossed to check the matrix with the
         * intencion to send an answer if its possible to move or to rotate
         */
        bool collision();
        /**
         *the idea here was to move the values related to
         *the pieces in rows+1 if possible after do points
         */
        void move();
        /**
         * get the position x
         */
        int getPosx();
        /**
         * get the position x
         */
        int getPosy();
        /**
         * update the matrix that will be printed and
         * before checked
         */
        void updateGrid(int px, int py, int val);

    private:
        /**
         * creating the atributs for this grid
         */
        //std::vector<std::vector<int>> matrix;
        std::vector<int> posXY;


};
#endif