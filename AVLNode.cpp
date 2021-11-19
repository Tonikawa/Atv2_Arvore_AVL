// Fabio Silveira Tanikawa
// TIA: 32092563
// Júlia Carvalho de Souza Castro
// TIA: 32022298
// Gabriel Batista Cristiano
// TIA: 32090722

#include "AVLNode.h"
#include <iostream>

AVLNode::AVLNode()
{
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::AVLNode(int valor)
{
    left = NULL;
    right = NULL;
    data = valor;
    height = 0;
}
AVLNode::~AVLNode()
{
    //dtor
}
void AVLNode::setData(int d)
{
    data = d;
}
int AVLNode::getData()
{
    return data;
}

void AVLNode::setLeft(AVLNode *n)
{
    left = n;
}
AVLNode* AVLNode::getLeft()
{
    return left;
}

void AVLNode::setRight(AVLNode *n)
{
    right = n;
}
AVLNode* AVLNode::getRight()
{
    return right;
}

void AVLNode::setParent(AVLNode *n)
{
    parent = n;
}

AVLNode* AVLNode::getParent()
{
    return parent;
}

void AVLNode::setHeight(int h)
{
    height = h;
}

int AVLNode::getHeight()
{
    return height;
}

bool AVLNode::IsRoot(AVLNode *n)
{
    bool root = n->getParent() == nullptr ? true : false;
    return root;
}
