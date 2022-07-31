#include <stdlib.h>
#include <stdio.h>

typedef struct treenode {
    int value;
    struct treenode *leftNode;
    struct treenode *rightNode;
} treenode;

treenode *create_tree_node(int val) {
    treenode *node = malloc(sizeof(treenode));

    if(node != NULL) {
        node->leftNode = NULL;
        node->rightNode = NULL;
        node->value = val;
    }

    return node;
}

void print_tree(treenode *root) {
    if(root == NULL || (root->rightNode == NULL && root->leftNode == NULL)) {
        return;
    }

    printf("   %d\n    |\n _______\n", root->value);
    printf("|\t|\n");
    if(root->rightNode != NULL) {
        printf("%d", root->rightNode->value);
    }
    if(root->leftNode != NULL) {
        printf("\t%d\n\n", root->leftNode->value);
    }
    print_tree(root->rightNode);
    print_tree(root->leftNode);
}

int is_binary_search_tree(treenode *root, int accumulative) {

    if(root == NULL) {
        return 1;
    }

    if((root->leftNode != NULL && root->leftNode->value > root->value) || (root->rightNode != NULL && root->rightNode->value < root->value)) {
        return 0;
    }

    if(root->leftNode != NULL) {
        accumulative = accumulative && is_binary_search_tree(root->leftNode, accumulative);
    }

    if(root->rightNode != NULL) {
        accumulative =  accumulative && is_binary_search_tree(root->rightNode, accumulative);
    }
    
    return accumulative;
}

int main() {
    treenode *root = create_tree_node(15);
    treenode *n2 = create_tree_node(20);
    treenode *n3 = create_tree_node(10);
    treenode *n4 = create_tree_node(17);
    treenode *n5 = create_tree_node(25);
    treenode *n6 = create_tree_node(8);
    treenode *n7 = create_tree_node(12);

    root->leftNode = n3;
    root->rightNode = n2;
    n2->leftNode = n4;
    n2->rightNode = n5;
    n3->leftNode = n6;
    n3->rightNode = n7;

    // print_tree(root);

    printf("%d\n", is_binary_search_tree(root, 1));

    free(root);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}

