// Fabio Silveira Tanikawa
// TIA: 32092563
// Júlia Carvalho de Souza Castro
// TIA: 32022298
// Gabriel Batista Cristiano
// TIA: 32090722

#include <iostream>

#include "AVLNode.h"
#include "AVLTree.h"


using namespace std;

int main() {
    AVLTree* treeA = new AVLTree;
    AVLTree* treeB = new AVLTree;
    AVLTree* treeC = new AVLTree;
    AVLTree* treeD = new AVLTree;
    AVLTree* treeE = new AVLTree;
    
    
    cout << "----- Questao 1 -----" << endl;
    cout << "Inserindo os nós: 1, 2 e 3" << endl;
    treeA->inserir(1);
    treeA->inserir(2);
    treeA->inserir(3);
    cout << "Arvore Balanceada: " << endl;
    treeA->preOrder();
    treeA->DesenhaArvore();
    cout << "------------------------\n\n";
    delete treeA;
    cout << "----- Questao 2 -----" << endl;
    cout << "Inserindo os nós: 3, 2 e 1" << endl;
    treeB->inserir(3);
    treeB->inserir(2);
    treeB->inserir(1);
    cout << "Arvore Balanceada: " << endl;
    treeB->preOrder();
    treeB->DesenhaArvore();
    cout << "------------------------\n\n";
    delete treeB;
    cout << "----- Questao 3 -----" << endl;
    cout << "Inserindo os nós: 3, 1 e 2" << endl;
    treeC->inserir(3);
    treeC->inserir(1);
    treeC->inserir(2);
    cout << "Arvore Balanceada: " << endl;
    treeC->preOrder();
    treeC->DesenhaArvore();
    cout << "------------------------\n\n";
    delete treeC;
    cout << "----- Questao 4 -----" << endl;
    cout << "Inserindo os nós: 1, 3 e 2" << endl;
    treeD->inserir(1);
    treeD->inserir(3);
    treeD->inserir(2);
    cout << "Arvore Balanceada: " << endl;
    treeD->preOrder();
    treeD->DesenhaArvore();
    cout << "------------------------\n\n";
    delete treeD;
    cout << "----- Alternativa e -----" << endl;
    cout << "Inserindo os nós: 5, 4, 3, 1, 2, 6, 7, 9 e 8" << endl;
    treeE->inserir(5);
    treeE->inserir(4);
    treeE->inserir(3);
    treeE->inserir(1);
    treeE->inserir(2);
    treeE->inserir(6);
    treeE->inserir(7);
    treeE->inserir(9);
    treeE->inserir(8);
    cout << "Arvore Balanceada: " << endl;
    treeE->preOrder();
    treeE->DesenhaArvore();
    cout << "------------------------\n\n";
    treeE->preOrder();
    treeE->deleteNode(treeE->getRoot(), 4);
    treeE->DesenhaArvore();
    
    cout << "------------------------\n\n";
    treeE->preOrder();
    treeE->deleteNode(treeE->getRoot(), 5);
    treeE->DesenhaArvore();
    
    cout << "------------------------\n\n";
    treeE->deleteNode(treeE->getRoot(), 1);
    treeE->DesenhaArvore();
    
    delete treeE;

    system("pause");
    return 0;
}
