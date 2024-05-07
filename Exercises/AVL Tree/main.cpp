#include "AVLTree.h"

int main() {
    AVLTree *tree;
    int arrayNode[] = {20, 10, 30, 25, 50, 40};
    int findNode = 40, deleteNode = 25;
    
    tree = new AVLTree();
    for (int i : arrayNode) tree->root = tree->insert_node(tree->root, i);

    cout << "- Inorder traversal: ";
    tree->inorder(tree->root);
    cout << endl;
    cout << "- Preorder traversal: ";
    tree->preorder(tree->root);
    cout << endl;
    cout << "- Postorder traversal: ";
    tree->postorder(tree->root);
    cout << endl;
    
    cout << "- The result of node " << findNode << " in the tree: " << (tree->search_node(tree->root, 40) != nullptr ? "available" : "unavailable") << endl;
    tree->delete_node(tree->root, deleteNode);
    cout << "- The tree after deletion of " << deleteNode << ": ";
    tree->inorder(tree->root);
    cout << endl;
    delete[] tree;
    return 0;
}