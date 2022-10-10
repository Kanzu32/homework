#include <iostream>
using namespace std;

class Player {
    private:
        int _x;
        int _y;
    public:
        void moveUp();
        void moveLeft();
        void moveDown();
        void moveRight();
        int playerSpeed;
        int getX() { return _x; };
        int getY() { return _y; };
    Player() {
        this->_x = 0;
        this->_y = 0;
        this->playerSpeed = 3;
    }
    Player(int _x, int _y): _x(_x), _y(_y){};
    Player(int _x, int _y, int spd): Player(_x, _y) {
        this->playerSpeed = spd;
    }
    Player(const Player &original);
    ~Player() {};
};

Player::Player(const Player &original) {
    _x = original._x;
    _y = original._y;
    playerSpeed = original.playerSpeed;
};

int main() {
    Player pl1 = Player();
    Player pl2 = Player(2, 3);
    Player copy = Player(pl2);
    cout << "Player 1: " << pl1.getX() << "\t" << pl1.getY() << endl;
    cout << "Player 2: " << pl2.getX() << "\t" << pl2.getY() << endl;
    cout << "Player 2 Copy: " << copy.getX() << "\t" << copy.getY() << endl;
    Player arr[10];
    arr[0] = Player(2, 3);
    
}

