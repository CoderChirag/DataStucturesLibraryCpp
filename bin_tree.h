#ifndef BIN_TREE_H
#define BIN_TREE_H
namespace bin_tree_node{
    template<class T>
    struct Node{
        struct Node *lchild;
        T data;
        struct Node *rchild;
    };
}
template<class T>
class BinTree{
    private:
        struct bin_tree_node::Node<T> *root;
        int nodeCount;
    public:
        // Constructors
        BinTree();
        BinTree(T root_val);
        BinTree(bin_tree_node::Node<T> *root);
        BinTree(BinTree<T>& bin_tree);

        // // Accessors (Getter Functions)
        // T* preorder() const;
        // T* preorder(bin_tree_node::Node *root) const;
        // T* postorder() const;
        // T* postorder(bin_tree_node::Node *root) const;
        // T* inorder() const;
        // T* inorder(bin_tree_node::Node *root) const;
        // T* levelorder() const;
        // T* levelorder(bin_tree_node::Node *root) const;
        // T lChild() const;
        // T lChild(bin_tree_node::Node* root) const;
        // T rChild() const;
        // T rChild(bin_tree_node::Node* root) const;
        // int height() const;
        // int height(bin_tree_node::Node *root) const;
        // int nodesCount() const;
        // int nodesCount(bin_tree_node::Node *root) const;

        // // Mutators (Setter Functions)
        // void createTreeFromUserInput();
        // void setLChild(T data);
        // void setLChild(bin_tree_node::Node* node);
        // void setLChild(BinTree& bin_tree);
        // void setRChild(T data);
        // void setRChild(bin_tree_node::Node* node);
        // void setRChild(BinTree& bin_tree);
        // void deleteLChild(bin_tree_node::Node* node);
        // void deleteRChild(bin_tree_node::Node* node);

        // // Facilitators
        // void displayAsPreorder() const;
        // void displayAsPostorder() const;
        // void displayAsInorder() const;
        // void displayAsLevelorder() const;

        // // Enquiry Functions
        // bool isEmpty() const;

        // // Operator Overloads
        // template <class U>
        // friend std::ostream &operator<<(std::ostream &cout, const BinTree<T> &q);

        // // Destructor
        // ~BinTree();
};
#endif