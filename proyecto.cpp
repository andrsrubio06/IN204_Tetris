#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include<iostream>

/**************************************
 * 
 *  * 
 * this is the file of testing where the ideas have been taken 
 *  * 
 * 
 */






using namespace std;    // standard namespace (std)
using namespace sf;             // Simple and Fast Multimedia Library namespace (sf)

//window.clear(Color(255,255,255,255));

/**
 *  utils constants
 */
const int SIZE = 25;
const int WIDTHFIELD=10;
const int HEIGHTFIELD=25;
const int POSITION_INIT_X=10;
const int POSITION_INIT_Y=5;

/**
 * default colors of sfml and one costum color
 * 
 */
    const Color AvailableColors[] = {
    sf::Color::Green,
    sf::Color::Blue,
    sf::Color::Red, 
    sf::Color::Yellow,
    sf::Color::White,
    sf::Color::Magenta,
    sf::Color::Cyan,
    sf::Color(220,145,0), //orange
    sf::Color::Transparent
    };



int main()
{
    /**
     * the matrix that will be used to show after check
     * 
     * I had problems here because I did not understand how move the pieces
     * if I put them inside with different int values, not in first time
     * but when have to pieces of the same kind
     */

    int matriz[HEIGHTFIELD][WIDTHFIELD];

    /**
     * creating the objects of SFML to show
     * the window
     * the cube that represent each cell of the piece
     */
    sf::RenderWindow window(sf::VideoMode(1000, 800), "El Tetris!!!");
    sf::RectangleShape cube(sf::Vector2f(SIZE, SIZE));
    sf::RectangleShape field(sf::Vector2f(WIDTHFIELD*SIZE,HEIGHTFIELD*SIZE));
    /**
     * adding some details of showing the pieces
     */
    cube.setOutlineColor(sf::Color::Black);
    cube.setOutlineThickness(1);

   /***
    * 
    * this is the matrix i suppossed to use filled with valuo of 8
    * that represent one of the color above, with that i can add
    * differents ints in the matrix and show them all, without thinking
    * the problem of move
    */
   for (size_t i = 0; i < HEIGHTFIELD; i++)
    {
        for (size_t j = 0; j < WIDTHFIELD; j++)
        {
            matriz[i][j]=8;
        }
        
    }
    /**
     * defining the random variable that create 1 piece
     */
    srand(time(NULL));
    int type= rand() %7;


    /**
     * the default pieces with respective positions
     */
    std::vector<std::vector<sf::Vector2i>> figuresAvalibles = {
        // T
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(0,1),
            sf::Vector2i(0,-1)
        },
        // Z
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(0,1),
            sf::Vector2i(1,-1)
        },
        // S
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(1,1),
            sf::Vector2i(0,-1)
        },
        // I
        {
            sf::Vector2i(0,0),
            sf::Vector2i(0,1),
            sf::Vector2i(0,-1),
            sf::Vector2i(0,-2)
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
        }


    };



    /**
     *  initial position of showing
     */
    int x_position=POSITION_INIT_X*SIZE;
    int y_position=POSITION_INIT_Y*SIZE;


    /**
     * adding details to the field before showing
     */
    field.setOutlineThickness(5);
    field.setOutlineColor(AvailableColors[2]);
    field.setFillColor(AvailableColors[8]);
    field.setPosition(SIZE*10,SIZE*5);

    /**
     * seting the clock to take care of the time in the event
     */
    sf::Clock Clock;
    float Timer=0, delay=0.3;
    
    while (window.isOpen())
    {
        /**
         * setting the time of execution of the event
         * in the variable of Time
         * and adding to Timer
         * the clock will start again to be sure not to add
         * more than the time of execution of the bucle 
         */
        float Time = Clock.getElapsedTime().asSeconds();
        Clock.restart();
        Timer+=Time;
        
        /**
         * launching the event
         * and processing the piles
         */
        sf::Event event;
        while (window.pollEvent(event))
        {
            /**
             * ckecking if close boton is selected to close the window
             */
            
            if (event.type == sf::Event::Closed)
                window.close();

            /**
             * subtracting the size of one cell to the position x
             * to move to the left
             * after cheking if the position of the cell
             * is not bigger than the position of thr field
             */
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (cube.getPosition().x > field.getPosition().x)){
                    x_position-=SIZE;
            }
            /**
             * adding the size of one cell to the position x
             * to move to the right
             * after cheking if the position of the cell
             * is not smaller than the position of the field
             * plus the width of the field
             */
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (cube.getPosition().x < field.getPosition().x+WIDTHFIELD*SIZE-SIZE)){
                    x_position+=SIZE;
            }
            /**
             * doing the multiplication to the positions
             * to rotate to the piece
             * after cheking just if the key Up was pressed
             */
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                for (int i = 0; i < 4; i++){
                    float x=figuresAvalibles[type][i].x;
                    float y=figuresAvalibles[type][i].y*-1;

                    figuresAvalibles[type][i].x=y;
                    figuresAvalibles[type][i].y=x;    
                }
            }
            /**
             * adding the size of one cell to the position x
             * to move down
             * after cheking if the position of the cell
             * is not smaller than the position of the field
             * plus the height of the field
             */
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && (cube.getPosition().y < field.getPosition().y+HEIGHTFIELD*SIZE-SIZE)){
                    y_position+=SIZE;
                   
            }
        }


             /**
             * adding the size of one cell to the position y
             * to move down
             * after cheking if the position of the cell
             * is not smaller than the position of the field
             * plus the height of the field
             * using as reference the delay of timing
             */
        if(Timer>delay){
            
            if(cube.getPosition().y < field.getPosition().y+HEIGHTFIELD*SIZE-SIZE)
            y_position+=SIZE;
            Timer=0;
        }


        window.clear();
        /***
         *  here is where one cell is printed
         * just depending of the four positions of the piece
         * 
         */
        auto draw_cell = [&]() {
                /**
                 * setting the color of the typo of piece
                 */
                cube.setFillColor(AvailableColors[type]);
                    for (int i = 0; i < 4 ; i++){

                       /**
                        * setting the position with the reference
                        * of the first position of the field, to be sure be there
                        * and checking that will not show before the position is in the field
                        * related to the position y
                        */ 
                        cube.setPosition(Vector2f(x_position+SIZE*figuresAvalibles[type][i].x,y_position+SIZE*figuresAvalibles[type][i].y-5*SIZE));
                        if(cube.getPosition().y>=POSITION_INIT_Y*SIZE){
                        window.draw(cube);
                        }
                    }             
            };
/******
 * 
 * this is the way i wanted to print the matrix that i didnt be sure
 * how to be implemented
 * 
 */
       /* auto draw_cell = [&]() {
                    for (int i = 0; i < HEIGHTFIELD ; i++){
                        for (int j = 0; j < WIDTHFIELD; j++)
                        {
                            cube.setPosition(Vector2f(x_position+SIZE*j,y_position+SIZE*i));
                            cube.setFillColor(AvailableColors[matriz[i][j]]);
                            window.draw(cube);  
                        }
                    }              
            };
*/
        
        //drawing the cells
        draw_cell();

        //adding to the window
        window.draw(field);
        
        //showing the window
        window.display();
    }

    return 0;
}