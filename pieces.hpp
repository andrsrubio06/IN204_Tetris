#ifndef PIECES_H
#define PIECES_H
#include <SFML/Graphics.hpp>
#include "axes.hpp"
class Piece{

    public:

        Piece();
        ~Piece();
        
        /**
         * getting the color of the piece
         */
        int     getColor();
        /**
         *  rotating with a matematical solution
         */
        void    rotate();
        /**
         * change the value of the position to move
         */
        void    move(axes direction);

        /**
         * getting the positions of the piece
         * in a vector2i
         */
        std::vector<sf::Vector2i>   getPosXY();

    private:

    /**
     * the diferent atributs, one constant to define
     * the first presentation of the pieces
     * the vector related to the position to know where the piece is
     * the variable kind that sais what is the simbol of the piece
     * the variable color that define which color identify which piece
     */ 
        const static std::vector<std::vector<sf::Vector2i>> figuresAvalibles;

        std::vector<sf::Vector2i> posXY;

        int kind;

        int color;


};

#endif