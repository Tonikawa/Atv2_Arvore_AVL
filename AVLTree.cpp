// Fabio Silveira Tanikawa
// TIA: 32092563
// Júlia Carvalho de Souza Castro
// TIA: 32022298
// Gabriel Batista Cristiano
// TIA: 32090722

#include "AVLTree.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree() { root = NULL; }


AVLTree::~AVLTree() {}


bool AVLTree::isEmpty() { return root==NULL;}


int AVLTree::height() { return height(root); }


int AVLTree::height(AVLNode *no) { return no==NULL? -1:no->getHeight(); }

int AVLTree::maximo(int lhs, int rhs) { return lhs>rhs? lhs: rhs; }


int AVLTree::qtNodes() { return qtNodes(root); }

AVLNode* AVLTree::getRoot()
{
    return root;
}


int AVLTree::qtNodes(AVLNode* no) {
    if (no == NULL)
		return 0;
	int qtleft = qtNodes (no->getLeft());
	int qtright = qtNodes (no->getRight());
	return qtleft + qtright + 1;
}



void AVLTree::inserir (int valor) { root = inserir(root,valor); }


AVLNode* AVLTree::inserir(AVLNode* node, int valor) {
    if (node == NULL)
       	return new AVLNode(valor);

    if (valor < node->getData()) {
        node->setLeft(inserir(node->getLeft(), valor));
        node->getLeft()->setParent(node);
        if (height( node->getRight() ) - height( node->getLeft() ) == -2 ) {
            if(valor < node->getLeft()->getData())
            {
                node = rotateLL( node );
                cout << "Rotacao LL" << endl;
            }
            else
            {
                node = rotateLR( node );
                cout << "Rotacao LR" << endl;
            }
        }
    }
    else {
        if (valor > node->getData()) {
            node->setRight(inserir(node->getRight(),valor));
            node->getRight()->setParent(node);
            if( height( node->getRight() ) - height( node->getLeft() ) == 2 ) {
                if( valor > node->getRight()->getData())
                {
                    node = rotateRR( node );
                    cout << "Rotacao RR" << endl;
                }
                else
                {
                    node = rotateRL( node );
                    cout << "Rotacao RL" << endl;
                }
            }
        }
    }
    
    node->setHeight(maximo( height(node->getLeft()), height(node->getRight()) ) + 1);
    return node;
}

AVLNode* AVLTree::procuraMenor(AVLNode *no)
{
    AVLNode *node = no;
    AVLNode *nodeL = no->getLeft();
    while (nodeL != nullptr) {
        node = nodeL;
        nodeL = nodeL->getLeft();
    }
    return node;
}

//void AVLTree::remover (int valor) {remover(root, valor);}
//
//AVLNode* AVLTree::remover(AVLNode *no, int valor)
//{
//    AVLNode *ret = nullptr;
//    if(no != nullptr)
//    {
//        if(valor > no->getData())
//        {
//            ret = remover(no->getRight(), valor);
//            if (height(no) >= 2)
//            {
//                if(height(no->getLeft()->getRight()) <= height(no->getLeft()->getLeft()))
//                {
//                    rotateLL(no);
//                }else
//                {
//                    rotateLR(no);
//                }
//            }
//        }else if (valor < no->getData())
//        {
//            ret = remover(no->getLeft(), valor);
//            if(height(no) >= 2)
//            {
//                if (height(no->getRight()->getLeft()) <= height(no->getRight()->getRight()))
//                {
//                    rotateRR(no);
//                }else
//                {
//                    rotateRL(no);
//                }
//            }
//        }else // Código da remoção
//        {
//            ret = no;
//            if ((no->getLeft() != nullptr) && (no->getRight() != nullptr))
//            {
//                AVLNode *temp = procuraMenor(no->getRight());
//                no->setData(temp->getData());
//                remover(no->getRight(), no->getData());
//                if(height(no) >= 2)
//                {
//                    if(height(no->getLeft()->getRight()) <= height(no->getLeft()->getLeft()))
//                    {
//                        rotateLL(no);
//                    }else
//                    {
//                        rotateLR(no);
//                    }
//                }
//            }else if (no->getLeft() != nullptr)
//            {
//                no = no->getLeft();
//            }else
//            {
//                no = no->getRight();
//            }
//            return ret;
//        }
//    }
//    return ret;
//}

AVLNode* AVLTree::deleteNode(AVLNode* root, int data)
{
    
     
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
 
    // If the chave to be deleted is smaller
    // than the raiz's chave, then it lies
    // in left subtree
    if ( data < root->getData())
      root->setLeft(deleteNode(root->getLeft(), data));
 
    // If the chave to be deleted is greater
    // than the raiz's chave, then it lies
    // in right subtree
    else if( data > root->getData() )
        root->setRight(deleteNode(root->getRight(), data));
 
    // if chave is same as raiz's chave, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->getLeft() == NULL) ||
            (root->getRight() == NULL) )
        {
            AVLNode *temp = root->getLeft() ?root->getLeft() :root->getRight();
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of
                           // the non-empty child
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            AVLNode* temp = procuraMenor(root->getRight());
 
            // Copy the inorder successor's
            // data to this node
            root->setData(temp->getData());
 
            // Delete the inorder successor
            root->setRight(deleteNode(root->getRight(), temp->getData()));
        }
    }
 
    // If the tree had only one node
    // then return
    if (root == NULL){
      return root;
    }
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->setHeight(1 + max(height(root->getLeft()), height(root->getRight())));
    return root;
  }



void AVLTree::DesenhaArvore(){
        DesenhaArvore(root,0);
    }

void AVLTree::DesenhaArvore(AVLNode* node, int spc )
    {
        if(node != nullptr)
        {
            DesenhaArvore(node->getRight(), spc + 4 );

            for(int i = 0 ; i < spc; i++ )
                cout << " ";

            cout << node->getData()<< "[" << node->getHeight()<< "]\n";

            DesenhaArvore(node->getLeft(), spc + 4 );
        }
    }

AVLNode* AVLTree::rotateLL(AVLNode *node) {
    AVLNode *leftSubTree = node->getLeft();
    node->setLeft(leftSubTree->getRight());
    leftSubTree->setRight( node );
    leftSubTree->setParent(nullptr);
    node->setParent(leftSubTree);
    node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
    leftSubTree->setHeight( maximo(height(leftSubTree->getLeft()), height(node) + 1));
    return leftSubTree;
}


AVLNode* AVLTree::rotateRR(AVLNode *node) {
    AVLNode *rightSubTree = node->getRight();
    node->setRight(rightSubTree->getLeft());
    rightSubTree->setLeft( node );
    rightSubTree->setParent(nullptr);
    node->setParent(rightSubTree);
    node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
    rightSubTree->setHeight( maximo(height(rightSubTree->getRight()), height(node) + 1));
    return rightSubTree;
}


AVLNode* AVLTree::rotateLR(AVLNode *node) {
    node->setLeft(rotateRR(node->getLeft()));
    return rotateLL(node);
}


AVLNode* AVLTree::rotateRL(AVLNode *node) {
    node->setRight(rotateLL(node->getRight()));
    return rotateRR(node);
}


void AVLTree::preOrder() { preOrder(root); }


void AVLTree::inOrder() { inOrder(root); }


void AVLTree::posOrder() { posOrder(root); }


void AVLTree::reverseOrder() { reverseOrder(root); }


void AVLTree::preOrder(AVLNode *no) {
    if (no!=NULL) {
        cout<<no->getData();
        if(no->IsRoot(no))
        {
            cout << " Nó pai. / Fator: " << no->getHeight() << endl;
        }else
        {
            if(no->getData() == procuraMenor(no)->getData())
            {
                cout << " Nó Filho da esquerda. / Fator: " << no->getHeight() << endl;
            }
            if(no->getData() == no->getParent()->getRight()->getData())
            {
                cout << " Nó Filho da direita. / Fator: " << no->getHeight() << endl;
            }
        }
        preOrder(no->getLeft());
        preOrder(no->getRight());
    }
}


void AVLTree::posOrder(AVLNode *no) {
    if (no!=NULL) {
        posOrder(no->getLeft());
        posOrder(no->getRight());
        cout<<no->getData()<<endl;
    }
}


void AVLTree::inOrder(AVLNode *no) {
    if (no!=NULL) {
        inOrder(no->getLeft());
        cout<<no->getData()<<endl;
        inOrder(no->getRight());
    }
}


void AVLTree::reverseOrder(AVLNode *no) {
    if (no!=NULL) {
        reverseOrder(no->getRight());
        cout<<no->getData()<<endl;
        reverseOrder(no->getLeft());
    }
}
