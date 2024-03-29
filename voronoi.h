#ifndef VONOROI_H
#define VONOROI_H
#include "wingededge.h"
#include <stack>

using namespace std;

/*
 * To run a vonoria diagram program using divide-and-conquer,
 * a stack is needed for recursion.
 * Because we need to run program step-by-step,
 * this Vonoroi class just for convenicence.
 * The true structure of (augumented) Vonoroi diagram is WingedEdge
 * Find it in "wingededge.h" .
 */
class Voronoi{
public:
    Voronoi();
    Voronoi(vector<double> p_x, vector<double> p_y);
    ~Voronoi();

    //One step is referred to be finishing merging 2 WingedEdge objects into 1.
    WingedEdge runOneStep();
    bool empty();
    bool stack_leak();

    int getNum_polygons() const;
    void setNum_polygons(int value);

    WingedEdge getResult();
private:

    int num_polygons;

    //Stack for run Vonoroi's diagram with divide-and-conquer strategy
    //No matter if the WingedEdge objects are To Be Divide or Wait For Merge, put them in this stack
    //and there will be no conflits.
    stack<WingedEdge> s_stack;

    //If the sub-WingedEdge is done, it will be put in this stack to wait for merging.
    stack<WingedEdge> done_stack;
};

#endif // VONOROI_H
