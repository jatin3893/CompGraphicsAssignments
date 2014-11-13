#ifndef TREE_H
#define TREE_H

#include "Object.h"

class Tree: public Object
{
public:
    Tree();
    ~Tree();
    virtual void Render();
private:
    void FractalTree(int branch, int depth, int x, int y, int z);
	float height;
	static const float diameter = 1;
    static const float LeafWidth = 2;
    static const int MaxDepth = 5;
    static const int MaxBranch = 10;
    static const int MaxLeaf = 10;

    void Initialise();
    float data[MaxBranch][MaxDepth][3];
    float leafData[MaxBranch][MaxDepth][MaxLeaf][3];
};

#endif
