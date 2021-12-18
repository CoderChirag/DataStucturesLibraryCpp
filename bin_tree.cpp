#include <iostream>
#include <stdexcept>
#include "bin_tree.h"
#include "queue.h"
#include "queue.cpp"

// ------------------ Constructors -----------------------------------
template<class T>
bin_tree_node::Node<T>::Node(T data, struct bin_tree_node::Node<T>* lchild, struct bin_tree_node::Node<T>* rchild){
    this->data = data;
    this->lchild = lchild;
    this->rchild = rchild;
}

template<class T>
BinTree<T>::BinTree(){
    root = NULL;
    nodeCount = 0;
}
template<class T>
BinTree<T>::BinTree(T root_val){
    root = new bin_tree_node::Node<T>{root_val};
    // root->lchild = root->rchild = NULL;
    // root->data = root_val;
    nodeCount++;
}
template<class T>
BinTree<T>::BinTree(bin_tree_node::Node<T>* root): BinTree{}{
    if(root){
        bin_tree_node::Node<T>* r = root;
        this->root = new bin_tree_node::Node<T>{};
        nodeCount++;
        // this->root->lchild = this->root->rchild = NULL;
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
                bin_tree_node::Node<T> *t = new bin_tree_node::Node<T>{r->lchild->data};
                nodeCount++;
                // t->data = r->lchild->data;
                // t->lchild = t->rchild = NULL;
                p->lchild = t;
                q1.enqueue(r->lchild);
                q2.enqueue(p->lchild);
                // std::cout << "r->lchild: " << r->lchild->data << ", p->lchild: " << p->lchild->data << std::endl;
            }
            if(r->rchild){
                bin_tree_node::Node<T> *t = new bin_tree_node::Node<T>{r->rchild->data};
                nodeCount++;
                // t->data = r->rchild->data;
                // t->lchild = t->rchild = NULL;
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
        this->root = new bin_tree_node::Node<T>{};
        nodeCount++;
        // this->root->lchild = this->root->rchild = NULL;
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
                bin_tree_node::Node<T> *t = new bin_tree_node::Node<T>{r->lchild->data};
                nodeCount++;
                // t->data = r->lchild->data;
                // t->lchild = t->rchild = NULL;
                p->lchild = t;
                q1.enqueue(r->lchild);
                q2.enqueue(p->lchild);
                // std::cout << "r->lchild: " << r->lchild->data << ", p->lchild: " << p->lchild->data << std::endl;
            }
            if(r->rchild){
                bin_tree_node::Node<T> *t = new bin_tree_node::Node<T>{r->rchild->data};
                nodeCount++;
                // t->data = r->rchild->data;
                // t->lchild = t->rchild = NULL;
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
template<class T>
T* BinTree<T>::inorder() const{
    T *in = new T[nodeCount];
    inorder(in, this->root);
    return in;
}
template<class T>
T* BinTree<T>::inorder(bin_tree_node::Node<T>* root) const{
    T *in = new T[nodeCount];
    int len = inorderAndCount(in, root);
    T *inOrder = new T[len];
    for (int i = 0; i < len; i++){
        inOrder[i] = in[i];
    }
    return inOrder;
} 
template<class T>
void BinTree<T>::inorder(T* in, bin_tree_node::Node<T> *root) const{
    static int count = 0;
    if(count >= nodeCount){
        return;
    }
    if(root){
        inorder(in, root->lchild);
        in[count] = root->data;
        count++;
        inorder(in, root->rchild);
    }
}
template<class T>
int BinTree<T>::inorderAndCount(T* in, bin_tree_node::Node<T>* root) const{
    static int count = 0;
    if(count >= nodeCount){
        throw std::runtime_error(std::string("Error: The node provided is not of this Binary Tree"));
    }
    if(root){
        inorderAndCount(in, root->lchild);
        in[count] = root->data;
        count++;
        inorderAndCount(in, root->rchild);
        return count;
    }
    return 0;
}
template<class T>
T* BinTree<T>::postorder() const{
    T *post = new T[nodeCount];
    postorder(post, this->root);
    return post;
}
template<class T>
T* BinTree<T>::postorder(bin_tree_node::Node<T>* root) const{
    T *post = new T[nodeCount];
    int len = postorderAndCount(post, root);
    T *postOrder = new T[len];
    for (int i = 0; i < len; i++){
        postOrder[i] = post[i];
    }
    return postOrder;
} 
template<class T>
void BinTree<T>::postorder(T* post, bin_tree_node::Node<T> *root) const{
    static int count = 0;
    if(count >= nodeCount){
        return;
    }
    if(root){
        postorder(post, root->lchild);
        postorder(post, root->rchild);
        post[count] = root->data;
        count++;
    }
}
template<class T>
int BinTree<T>::postorderAndCount(T* post, bin_tree_node::Node<T>* root) const{
    static int count = 0;
    if(count >= nodeCount){
        throw std::runtime_error(std::string("Error: The node provided is not of this Binary Tree"));
    }
    if(root){
        postorderAndCount(post, root->lchild);
        postorderAndCount(post, root->rchild);
        post[count] = root->data;
        count++;
        return count;
    }
    return 0;
}
template<class T>
T* BinTree<T>::levelorder() const{
    T *level = new T[nodeCount];
    levelorder(level, this->root);
    return level;
}
template<class T>
T* BinTree<T>::levelorder(bin_tree_node::Node<T>* root) const{
    T *level = new T[nodeCount];
    int len = levelorderAndCount(level, root);
    T *levelOrder = new T[len];
    for (int i = 0; i < len; i++){
        levelOrder[i] = level[i];
    }
    return levelOrder;
}
template<class T>
void BinTree<T>::levelorder(T* level, bin_tree_node::Node<T> *root) const{
    static int count = 0;
    if(count >= nodeCount){
        return;
    }
    if(root){
        bin_tree_node::Node<T> *p = root;
        Queue<bin_tree_node::Node<T> *> q{};
        q.enqueue(root);
        level[count++] = root->data;
        while(!q.isEmpty()){
            p = q.dequeue();
            if(p->lchild){
                level[count++] = p->lchild->data;
                q.enqueue(p->lchild);
            }
            if(p->rchild){
                level[count++] = p->rchild->data;
                q.enqueue(p->rchild);
            }
        }
    }
}
template<class T>
int BinTree<T>::levelorderAndCount(T* level, bin_tree_node::Node<T> *root) const{
    static int count = 0;
    if(count >= nodeCount){
        throw std::runtime_error(std::string("Error: The node provided is not of this Binary Tree"));
    }
    if(root){
        bin_tree_node::Node<T> *p = root;
        Queue<bin_tree_node::Node<T> *> q{};
        q.enqueue(root);
        level[count++] = root->data;
        while(!q.isEmpty()){
            p = q.dequeue();
            if(p->lchild){
                level[count++] = p->lchild->data;
                q.enqueue(p->lchild);
            }
            if(p->rchild){
                level[count++] = p->rchild->data;
                q.enqueue(p->rchild);
            }
        }
        return count;
    }
    return 0;
}
template<class T>
bin_tree_node::Node<T>* BinTree<T>::getRootNode() const{
    return root;
}
template<class T>
int BinTree<T>::height() const{
    return height(root);
}
template<class T>
int BinTree<T>::height(bin_tree_node::Node<T>* root) const{
    int x = 0, y = 0;
    if(!root){
        return 0;
    }
    x = height(root->lchild);
    y = height(root->rchild);
    if(x > y){
        return ++x;
    }else{
        return ++y;
    }
}
template<class T>
int BinTree<T>::nodesCount() const{
    return nodeCount;
}
template<class T>
int BinTree<T>::nodesCount(bin_tree_node::Node<T>* root) const{
    int x, y;
    if(root){
        x = nodesCount(root->lchild);
        y = nodesCount(root->rchild);
        return x + y + 1;
    }
    return 0;
}
//---------------------- Mutators (Setters) -----------------------------
template<class T>
void BinTree<T>::createTreeFromUserInput(){
    if(root){
        destroyCurrentBinaryTree();
    }
    root = new bin_tree_node::Node<T>{};
    Queue<bin_tree_node::Node<T>*> q{};
    // root->lchild = root->rchild = NULL;
    std::cout << "Enter the root value: ";
    std::cin >> root->data;
    q.enqueue(root);
    while(!q.isEmpty()){
        bin_tree_node::Node<T>* p = q.dequeue();
        T x;
        std::cout << std::endl << "Enter the Left Child of " << p->data << ": ";
        std::cin >> x;
        if(x != -1){
            p->lchild = new bin_tree_node::Node<T>{x};
            // p->lchild->lchild = p->lchild->rchild = NULL;
            // p->lchild->data = x;
            q.enqueue(p->lchild);
        }
        std::cout << std::endl << "Enter the Right Child of " << p->data << ": ";
        std::cin >> x;
        if(x != -1){
            p->rchild = new bin_tree_node::Node<T>{x};
            // p->rchild->lchild = p->rchild->rchild = NULL;
            // p->rchild->data = x;
            q.enqueue(p->rchild);
        }
    }
}
template<class T>
void BinTree<T>::destroyCurrentBinaryTree(){
    destroyCurrentBinaryTree(root);
    root = NULL;
} 
template<class T>
void BinTree<T>::destroyCurrentBinaryTree(bin_tree_node::Node<T>* root){
    if(root){
        destroyCurrentBinaryTree(root->lchild);
        destroyCurrentBinaryTree(root->rchild);
        // std::cout << root->data << " ";
        delete root;
    }
}

// ------------- Facilitators -------------------------------------------
template<class T>
void BinTree<T>::displayAsPreorder() const{
    displayAsPreorder(root);
}
template<class T>
void BinTree<T>::displayAsInorder() const{
    displayAsInorder(root);
}
template<class T>
void BinTree<T>::displayAsPostorder() const{
    displayAsPostorder(root);
}
template<class T>
void BinTree<T>::displayAsLevelorder() const{
    displayAsLevelorder(root);
}
template<class T>
void BinTree<T>::displayAsPreorder(bin_tree_node::Node<T>* root) const{
    if(root){
        std::cout << root->data << " ";
        displayAsPreorder(root->lchild);
        displayAsPreorder(root->rchild);
    }
}
template<class T>
void BinTree<T>::displayAsInorder(bin_tree_node::Node<T>* root) const{
    if(root){
        displayAsInorder(root->lchild);
        std::cout << root->data << " ";
        displayAsInorder(root->rchild);
    }
}
template<class T>
void BinTree<T>::displayAsPostorder(bin_tree_node::Node<T>* root) const{
    if(root){
        displayAsPostorder(root->lchild);
        displayAsPostorder(root->rchild);
        std::cout << root->data << " ";
    }
}
template<class T>
void BinTree<T>::displayAsLevelorder(bin_tree_node::Node<T>* root) const{
    if(root){
        std::cout << root->data << " ";
        Queue<bin_tree_node::Node<T> *> q{};
        q.enqueue(root);
        while(!q.isEmpty()){
            bin_tree_node::Node<T> *p = q.dequeue();
            if(p->lchild){
                std::cout << p->lchild->data << " ";
                q.enqueue(p->lchild);
            }
            if(p->rchild){
                std::cout << p->rchild->data << " ";
                q.enqueue(p->rchild);
            }
        }
        std::cout << std::endl;
    }else{
        std::cout << std::endl;
    }

}

// ----------------------- EnquiryFunctions --------------------------------
template<class T>
bool BinTree<T>::isEmpty() const{
    return root ? false : true;
}

// -------------------------- Destructor ---------------------------
template<class T>
BinTree<T>::~BinTree(){
    destroyCurrentBinaryTree();
}