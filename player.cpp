#include "player.h"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
	myside = side;
	if(myside == WHITE) otherside = BLACK;
	else otherside = WHITE;
    board = new Board();
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) { 
	board->doMove(opponentsMove, otherside);
	if(!board->hasMoves(myside)) return NULL;
   	vector<Move> moves = board->getMoves(myside);
	if(!testingMinimax)
	{
		Move bestie = moves[board->bestMove(moves, myside)];
		Move* outm = new Move(bestie.getX(), bestie.getY());
		board->doMove(outm, myside);
		return outm;
	}
	Board * future;
	vector<Move> moves_other;
	int maxscore = -1000;
	int indmax = 0;
	for(unsigned int i = 0; i < moves.size(); i++)
	{
		future = board->copy();
		future->doMove(&(moves[i]), myside);
		moves_other = future->getMoves(otherside);
		Move best_other = moves_other[future->simpBest(moves_other, otherside)];
		future->doMove(&best_other, otherside);
		if(future->score(myside) > maxscore)
		{
			maxscore = future->scoreBoard(&best_other, myside);
			indmax = i;
		}
	}
	Move bestie = moves[indmax];
	Move* outm = new Move(bestie.getX(), bestie.getY());
	board->doMove(outm, myside);
	return outm;
}
