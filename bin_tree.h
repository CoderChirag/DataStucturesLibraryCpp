#ifndef BIN_TREE_H
#define BIN_TREE_H
namespace bin_tree_node{
    template<class T>
    struct Node{
        Node(T data=static_cast<T>(0), struct Node<T> *lchild=NULL, struct Node<T> *rchild=NULL);
        struct Node<T>* lchild;
        T data;
        struct Node<T>* rchild;
    };
}
template<class T>
class BinTree{
    private:
        struct bin_tree_node::Node<T> *root;
        int nodeCount;
        
        void preorder(T* pre, bin_tree_node::Node<T> *root) const;
        int preorderAndCount(T* pre, bin_tree_node::Node<T> *root) const;
        void inorder(T* in, bin_tree_node::Node<T> *root) const;
        int inorderAndCount(T* in, bin_tree_node::Node<T> *root) const;
        void postorder(T* post, bin_tree_node::Node<T> *root) const;
        int postorderAndCount(T* post, bin_tree_node::Node<T> *root) const;
        void levelorder(T* level, bin_tree_node::Node<T> *root) const;
        int levelorderAndCount(T* level, bin_tree_node::Node<T> *root) const;
    public:
        // Constructors
        BinTree();
        BinTree(T root_val);
        BinTree(bin_tree_node::Node<T> *root);
        BinTree(BinTree<T>& bin_tree);

        // Accessors (Getter Functions)
        T* preorder() const;
        T* preorder(bin_tree_node::Node<T>* root) const;
        T* inorder() const;
        T* inorder(bin_tree_node::Node<T>* root) const;
        T* postorder() const;
        T* postorder(bin_tree_node::Node<T>* root) const;
        T* levelorder() const;
        T* levelorder(bin_tree_node::Node<T>* root) const;
        bin_tree_node::Node<T>* getRootNode() const;
        int height() const;
        int height(bin_tree_node::Node<T> *root) const;
        int nodesCount() const;
        int nodesCount(bin_tree_node::Node<T> *root) const;

        // Mutators (Setter Functions)
        void createTreeFromUserInput();
        void destroyCurrentBinaryTree();
        void destroyCurrentBinaryTree(bin_tree_node::Node<T>* root);


        // Facilitators
        void displayAsPreorder() const;
        void displayAsPreorder(bin_tree_node::Node<T>* root) const;
        void displayAsPostorder() const;
        void displayAsPostorder(bin_tree_node::Node<T>* root) const;
        void displayAsInorder() const;
        void displayAsInorder(bin_tree_node::Node<T>* root) const;
        void displayAsLevelorder() const;
        void displayAsLevelorder(bin_tree_node::Node<T>* root) const;

        // Enquiry Functions
        bool isEmpty() const;

        // Destructor
        ~BinTree();
};
#endif