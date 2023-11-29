#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"

using namespace std;

int main()
{
        //NCURSES START
        initscr();
        noecho();
        cbreak();

        // get screen size
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        // create window for input 
        WINDOW *gameWin = newwin(20, 50, (yMax/2) - 10, 10);
        box(gameWin, 0, 0);
        refresh();
        wrefresh(gameWin);

        Player * playerPtr = new Player(gameWin, 1, 1, '@');
        do 
        {
                playerPtr->display();
                wrefresh(gameWin);
        } while (playerPtr->getMv() != 'x');

        // wait before exiting
        getch();
        endwin();
        
        // NCURSES END
}
