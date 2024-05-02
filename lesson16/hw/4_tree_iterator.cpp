/*
4.  Реализация алгоритма обхода дерева с использованием итераторов. 
    Например, можно написать алгоритм обхода дерева в глубину, который использует итераторы для доступа к узлам дерева. 
    Это поможет показать, как можно использовать итераторы для обработки иерархических данных и 
    как они могут быть полезны при работе с древовидными структурами данных.
*/

#include <iostream>

// Depth-First Search (DFS)
class BinaryTree{
public:
    struct Node
    {
        int data;
        Node* left;
        Node* right;
        Node(const int& data) : data(data), left(nullptr), right(nullptr){}
    };
    Node* root;

    BinaryTree() : root(nullptr) {}
    ~BinaryTree(){}

    void add(int& data){
        Node* newnode = new Node(data);
        if (root == nullptr){
            root = newnode;
        }
        else{

        }
    }

    int& goDeep(){
        Node* current = root;
        while (current->left != nullptr && current->right != nullptr){
            if (current->left == nullptr){
                current = current->right;
            }
            else{
                current = current->left;
            }
        }
    }


    
};

int main(){



    return 0;
}