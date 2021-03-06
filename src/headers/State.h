#ifndef STATE_H
#define STATE_H

#include "Globals.h"
#include "Column.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class State
{
public:
    State(int nRows, int nCols, int move=-1);
    State(const State& s);
    State& operator=(const State& s);
    ~State();

    int getMove() const;
    void setMove(int move);
    
    bool play(int player, int column);
    vector<State*> makeDescendants(int player) const;
    int isTerminal() const;
    bool isFull() const;
    void print() const;

    int getUtility() const;
    // TODO << SUPPORT
    
private:
    int r;
    int c;
    Column *board;
    int move;
    int utility;

    void eval(); 
    int runEval(int x, int y, int dirX, int dirY) const;
    int segmentPoints(int humanCount, int pcCount) const;
    bool testPoints(int points);
};

// The sucessor function comparator.
// The order is ascendent for MAX sucessors and
// descendent for MIN.
class CompareUtility
{   
public:

    CompareUtility(const bool& reverse)
	: reverse(reverse)
    {
    }

    bool operator()(const State* lhs, const State* rhs) const
    {
	if(reverse)
	    return(lhs->getUtility() > rhs->getUtility());
	else
	    return(lhs->getUtility() < rhs->getUtility());
    }
    
private:
    bool reverse;
};

#endif
