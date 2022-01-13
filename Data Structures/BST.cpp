#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void printPreorder(node *root) {
  if (root != NULL)
    cout << root->data << " ";
  if (root->left)
    printPreorder(root->left);
  if (root->right)
    printPreorder(root->right);
}

void printPreorderIterative() {}

int main() { return 0; }
