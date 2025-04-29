#include<stdio>
int main(){
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Visit the node
        preorder(root->left);       // Traverse left subtree
        preorder(root->right);      // Traverse right subtree
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);      // Traverse left subtree
        postorder(root->right);     // Traverse right subtree
        printf("%d ", root->data);  // Visit the node
    }
}
)
