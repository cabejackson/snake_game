#include <iostream>
#include <curses.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score = 0;
enum eDirection{ STOP = 0, LEFT, RIGHT, UP , DOWN};
eDirection dir;

void setUp(){
    gameOver = false;

    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;

};

void draw(){

    system("clear");
    for (int i = 0; i < width; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i <= height; i++){
        for (int j = 0; j <= width; j++){
            if(j == 0 || j == (width - 1)) //if on the edge  
                cout << "#";
            else if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else //otherwise you're in the middle
                cout << " ";
        };
        cout << endl;
    }

    for (int i = 0; i < width; i++)
        cout << "#";
    cout << endl;

};

void input(){
    if ( keypad(stdscr, TRUE))
 {
        switch(getch()){
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
        }
    }

};

void logic(){

};

int main(){

    setUp();
    while(!gameOver){
        draw();
        input();
        logic();
    }

    return 0;
};