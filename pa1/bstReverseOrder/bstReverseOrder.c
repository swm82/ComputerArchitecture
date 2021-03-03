#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct bstNode {
    int val;
    struct bstNode* l_child;
    struct bstNode* r_child;
};

struct bstNode *newNode(int val);
struct bstNode *insertFromFile(FILE *fp, struct bstNode *root);
bool search(struct bstNode *root, int value);
struct bstNode *insert(struct bstNode *root, int value);
void printInorder(struct bstNode* root);
void printReverseOrder(struct bstNode* root);
void freeTree(struct bstNode *root);

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    struct bstNode* root = NULL;
    root = insertFromFile(fp, root);

    printReverseOrder(root);
    


    fclose(fp);
    freeTree(root);
    return 0;
}

// Read input from file, insert into tree
struct bstNode *insertFromFile(FILE *fp, struct bstNode *root) {
    char buff[256];
    while ( fscanf(fp, "%s", buff)!=EOF ) {
        int val = atoi(buff);
        root = insert(root, val);
    }
    return root;
}

// Search for value recursively, return boolean
bool search(struct bstNode *root, int value) {
    if (root == NULL) return false;
    if (value == root->val) return true;
    if (value < root->val) return search(root->l_child, value);
    return search(root->r_child, value);
}

// Create and return new node with given value
struct bstNode *newNode(int val) {
    struct bstNode *node = (struct bstNode*)malloc(sizeof(struct bstNode));
    node->val = val;
    node->l_child = node->r_child = NULL;
    return node;
}

// Insert iteratively
struct bstNode *insert(struct bstNode *root, int value) {
    if (root == NULL) {
        struct bstNode *node = newNode(value);
        return node;
    }
    struct bstNode *curr = root;
    struct bstNode *prev = NULL;
    while (curr != NULL) {
        if (value == curr->val) {
            return root;
        } else if (value < curr->val) {
            prev = curr;
            curr = curr->l_child;
        } else {
            prev = curr;
            curr = curr->r_child;
        }
    }
    struct bstNode *node = newNode(value);
    if (value < prev->val) prev->l_child = node;
    else prev->r_child = node;
    return root;
}

void printInorder(struct bstNode* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->l_child);
    printf("%d ", root->val);
    printInorder(root->r_child);
}

void printReverseOrder(struct bstNode* root) {
    if (root == NULL) {
        return;
    }
    printReverseOrder(root->r_child);
    printf("%d ", root->val);
    printReverseOrder(root->l_child);
}

void freeTree(struct bstNode *root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->l_child);
    freeTree(root->r_child);
    free(root);
}