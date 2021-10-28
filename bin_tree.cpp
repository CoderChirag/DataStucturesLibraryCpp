#include <iostream>
#include <stdexcept>
#include "bin_tree.h"
#include "queue.h"
#include "queue.cpp"

// ------------------ Constructors -----------------------------------
template<class T>
BinTree<T>::BinTree(){
    root = NULL;
    nodeCount = 0;
}
template<class T>
BinTree<T>::BinTree(T root_val){
    root = new bin_tree_node::Node<T>;
    root->lchild = root->rchild = NULL;
    root->data = root_val;
    nodeCount++;
}
template<class T>
BinTree<T>::BinTree(bin_tree_node::Node<T>* root): BinTree{}{
    if(root){
        bin_tree_node::Node<T>* r = root;
        this->root = new bin_tree_node::Node<T>;
        nodeCount++;
        this->root->lchild = this->root->rchild = NULL;
        bin_tree_node::Node<T>* p = this->root;
        p->data = r->data;
        Queue<bin_tree_node::Node<T>*> q1{};
        Queue<bin_tree_node::Node<T>*> q2{};
        q1.enqueue(r);
        q2.enqueue(p);
        // std::cout << "r->data: " << r->data << ", p->data: " << p->data << std::endl;
        while(!q1.isEmpty()){
            r = q1.dequeue();
            p = q2.dequeue();
            if(r->lchild){
                bin_tree_node::Node<T> *t = new bin_tree_node::Node<T>;
                nodeCount++;
                t->data = r->lchild->data;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q1.enqueue(r->lchild);
                q2.enqueue(p->lchild);
                // std::cout << "r->lchild: " << r->lchild->data << ", p->lchild: " << p->lchild->data << std::endl;
            }
            if(r->rchild){
                bin_tree_node::Node<T> *t = new bin_tree_node::Node<T>;
                nodeCount++;
                t->data = r->rchild->data;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                q1.enqueue(r->rchild);
                q2.enqueue(p->rchild);
                // std::cout << "r->rchild: " << r->rchild->data << ", p->rchild: " << p->rchild->data << std::endl;
            }
        }
        // std::cout << nodeCount << std::endl;
        // std::cout << this->root->data << std::endl;
    }
}
template<class T>
BinTree<T>::BinTree(BinTree<T>& bin_tree): BinTree{}{
    if(bin_tree.root){
        bin_tree_node::Node<T>* r = bin_tree.root;
        this->root = new bin_tree_node::Node<T>;
        nodeCount++;
        this->root->lchild = this->root->rchild = NULL;
        bin_tree_node::Node<T>* p = this->root;
        p->data = r->data;
        Queue<bin_tree_node::Node<T>*> q1{};
        Queue<bin_tree_node::Node<T>*> q2{};
        q1.enqueue(r);
        q2.enqueue(p);
        // std::cout << "r->data: " << r->data << ", p->data: " << p->data << std::endl;
        while(!q1.isEmpty()){
            r = q1.dequeue();
            p = q2.dequeue();
            if(r->lchild){
                bin_tree_node::Node<T> *t = new bin_tree_node::Node<T>;
                nodeCount++;
                t->data = r->lchild->data;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q1.enqueue(r->lchild);
                q2.enqueue(p->lchild);
                // std::cout << "r->lchild: " << r->lchild->data << ", p->lchild: " << p->lchild->data << std::endl;
            }
            if(r->rchild){
                bin_tree_node::Node<T> *t = new bin_tree_node::Node<T>;
                nodeCount++;
                t->data = r->rchild->data;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                q1.enqueue(r->rchild);
                q2.enqueue(p->rchild);
                // std::cout << "r->rchild: " << r->rchild->data << ", p->rchild: " << p->rchild->data << std::endl;
            }
        }
        // std::cout << nodeCount << std::endl;
        // std::cout << this->root->data << std::endl;

    }
}

// --------------- Accessors (Getters) ---------------------------------------
template<class T>
T* BinTree<T>::preorder() const{
    T *pre = new T[nodeCount];
    preorder(pre, this->root);
    return pre;
}
template<class T>
T* BinTree<T>::preorder(bin_tree_node::Node<T>* root) const{
    T *pre = new T[nodeCount];
    int len = preorderAndCount(pre, root);
    T *preOrder = new T[len];
    for (int i = 0; i < len; i++){
        preOrder[i] = pre[i];
    }
    return preOrder;
} 
template<class T>
void BinTree<T>::preorder(T* pre, bin_tree_node::Node<T> *root) const{
    static int count = 0;
    if(count >= nodeCount){
        return;
    }
    if(root){
        pre[count] = root->data;
        count++;
        preorder(pre, root->lchild);
        preorder(pre, root->rchild);
    }
}
template<class T>
int BinTree<T>::preorderAndCount(T* pre, bin_tree_node::Node<T>* root) const{
    static int count = 0;
    if(count >= nodeCount){
        throw std::runtime_error(std::string("Error: The node provided is not of this Binary Tree"));
    }
    if(root){
        pre[count] = root->data;
        count++;
        preorderAndCount(pre, root->lchild);
        preorderAndCount(pre, root->rchild);
        return count;
    }
    return 0;
}