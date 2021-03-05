#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <iostream>

#include "pieces.hpp"
#include "grid.hpp"
#include "constants.hpp"
#include "colorCells.hpp"
#include "availableColors.hpp"

/********************
 * here i tried to implement the classes
 * taking as expamle the file proyect.cpp that is the file of testing
 * where i found a lot of problems i think
 * for not being able to think as an object pretty well 
 * 
 */


using namespace std;    // standard namespace (std)
using namespace sf;             // Simple and Fast Multimedia Library namespace (sf)


int main()
{
 
 /*******************************************************
  * here i tried to implement the matrix paralele
  * that help me to check the colissions to understand
  * the implementation of the class
  *
  *
  */

   /*std::vector<std::vector<int>> matrix;
   for (int j = 0; j < HEIGHTFIELD; j++)
    {
        for (int i = 0; i < WIDTHFIELD; i++)
        {
            matrix[j][i]=-2;
        }
        
    }
    
    /************************************************************
     * 
     * here is where i found the problems of implement the class
     * im not sure why this happen but after using the * I found some
     * new problems when trying to show values
     */

    /*Grid *player = new Grid(HOSTX,HOSTY);
    sf::RectangleShape field();

    field.setPosition(player->getPosx(),player->getPosy());
    field.setSize(sf::Vector2f(WIDTHFIELD,HEIGHTFIELD));
    field.setOutlineThickness(5);
    field.setOutlineColor(colorCell[RED]);
    field.setFillColor(sf::Color::Transparent);   
   */ 

    /**
     * defining a cude shape
     */
    sf::RectangleShape cube(sf::Vector2f(SIZEHOST, SIZEHOST));

    /*********
     * here i found the same error as befire
     * i did not understand wath is the diferent type
     *  of using * or not using in the object
     */
    Piece a = new Piece();
    std::vector<sf::Vector2i> coordinates = a->getPosXY();
    
    /**
     * defining a render window
     */
    sf::RenderWindow window(sf::VideoMode(1000, 800), "El Tetris!!!");
  
    /**
     * opening the window
     */    
     while (window.isOpen())
     {
         /**
          * launching event
          * and processing the piles
          */
         sf::Event event;
         while (window.pollEvent(event))
         {
             // Si el evento es de tipo Closed cerramos la ventana
             if (event.type == sf::Event::Closed)
                 window.close();
         }
 
    /*********************
     * changing the showing to be adapted
     * with the classes
     * 
     */  
      /*  auto draw_cell = [&]() {

            cube.setFillColor(AvailableColors[]);
              for (int i = 0; i < 4 ; i++){ 
                cube.setPosition(Vector2f();
                window.draw(cube);
            } 
        */ 
       /****************
        * 
        * here is where i tried to do that, i thought i did bad tha function
        * so i tried to print a simple cube, because i did not know how to
        * implement the object
        */
        for (int i = 0; i < 4 ; i++){
                        
            cube.setPosition(Vector2f(5+SIZEHOST*coordinates[i].x,5+SIZEHOST*coordinates[i].y));
            window.draw(cube);
        }

        window.clear();
         // updateing the window
         window.display();
     }



    return 0;
}