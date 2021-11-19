// Fabio Silveira Tanikawa
// TIA: 32092563
// Júlia Carvalho de Souza Castro
// TIA: 32022298
// Gabriel Batista Cristiano
// TIA: 32090722

#ifndef AVLNODE_H
#define AVLNODE_H

class AVLNode {
    private:
        int data;
        int height;
        AVLNode* left, *right, *parent;

    protected:

    public:
        AVLNode();
        AVLNode(int);
        virtual ~AVLNode();

        int getData();
        void setData(int);

        int getHeight();
        void setHeight(int);

        AVLNode* getLeft();
        void setRight(AVLNode*);

        AVLNode* getRight();
        void setLeft(AVLNode*);
    
        AVLNode* getParent();
        void setParent(AVLNode*);
    
        bool IsRoot(AVLNode *n);
};

#endif // AVLNODE_H
