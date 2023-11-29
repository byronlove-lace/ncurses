#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player
{
        public:
                Player(WINDOW * win, int y, int x, char c);

                void mvUp();
                void mvDown();
                void mvLeft();
                void mvRight();
                int getMv();
                void display();

        private:
                int xPos, yPos, xMax, yMax;
                char character; // ?
                WINDOW * curWin; // ?
};

Player::Player(WINDOW * win, int y, int x, char c)
{
        curWin = win;
        yPos = y;
        xPos = x;
        getmaxyx(curWin, yMax, xMax); // how can this access yMax, xMax?
        keypad(curWin, true);
        character = c;

}

void Player::mvUp()
{
        mvwaddch(curWin, yPos, xPos, ' ');
        --yPos;
        // border checking 
        // ??
        if (yPos < 1)
                yPos = 1;

}

void Player::mvDown()
{
        mvwaddch(curWin, yPos, xPos, ' ');
        ++yPos;
        if (yPos > yMax - 2) // border is yMax - 1; we wanna stay within the border
                yPos = yMax - 2;
}

void Player::mvLeft()
{
        mvwaddch(curWin, yPos, xPos, ' ');
        --xPos;
        if (xPos < 1)
                xPos = 1;

}

void Player::mvRight()
{
        mvwaddch(curWin, yPos, xPos, ' ');
        ++xPos;
        if (xPos > xMax - 2)
        {
                xPos = xMax - 2;
        }

}

int Player::getMv()
{
        int choice = wgetch(curWin);
        
        switch(choice)
        {
                case KEY_UP:
                        mvUp();
                        break;

                case KEY_DOWN:
                        mvDown();
                        break;

                case KEY_LEFT:
                        mvLeft();
                        break;

                case KEY_RIGHT:
                        mvRight();
                        break;
                default:
                        break;
                }
        return choice;
}


void Player::display()
{
        mvwaddch(curWin, yPos, xPos, character);
}

#endif
