#ifndef __BOARD_H__
#define __BOARD_H__

#include <bitset>
#include "common.h"
#include <vector>
#include <iostream>
using namespace std;

class Board {
   
private:
    bitset<64> black;
    bitset<64> taken;    
       
    bool occupied(int x, int y);
    bool get(Side side, int x, int y);
    void set(Side side, int x, int y);
    bool onBoard(int x, int y);
      
public:
    Board();
    ~Board();
    Board *copy();
        
    bool isDone();
    bool hasMoves(Side side);
	vector<Move> getMoves(Side side);
    bool checkMove(Move *m, Side side);
    void doMove(Move *m, Side side);
    int count(Side side);
    int countBlack();
    int countWhite();
	int score(Side side);
	int scoreMove(Move *m, Side side);
	int bestMove(vector<Move> moves, Side side);
	int scoreBoard(Move *m, Side side);
	int simpBest(vector<Move> moves, Side side);
    void setBoard(char data[]);
};

#endif
