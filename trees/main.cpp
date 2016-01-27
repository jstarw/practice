#include "bstnode.h"
#include <iostream>
#include <cmath>

using namespace std;

BstNode* getNewNode(int a) {
	BstNode* root = new BstNode();
	root->data = a;
	root->right = root->left = NULL;
	return root;
}

BstNode* insert(int a, BstNode * root) {
	if (root == NULL) {
		root = getNewNode(a);
		return root;
	} else if (root->data >= a) {
		root->left = insert(a, root->left);
	} else {
		root->right = insert(a, root->right);
	}
	return root;
}

void inOrder(BstNode* root) {
	if (root != NULL) {
		cout<<root->data<< " ";
		inOrder(root->left);
		inOrder(root->right);
	}
}

void search (BstNode* root, int a) {
	if (root == NULL) {
		cout<<"not found"<<endl;
		return;
	} else if (root->data == a) {
		cout<<"found!"<<endl;
		return;
	} else if (a < root->data) {
		search(root->left, a);
	} else if (a > root->data) {
		search(root->right, a);
	}
}

BstNode* findMin(BstNode* root) {
	while(root->left != NULL) {
		root = root->left;
	} 
	return root;
}

BstNode* deleteNode(BstNode* root, int a) {
	if (root == NULL) {
		return root;
	} else if (a < root->data) {
		root->left = deleteNode(root->left, a);
	} else if (a > root->data) {
		root->right = deleteNode(root->right, a);
	} else {
		if (root->left!=NULL && root->right!=NULL) {
			BstNode* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
		} else if (root->left != NULL) {
			root = root->left;
		} else if (root->right != NULL) {
			root = root->right;
		} else {
			delete root;
			root = NULL;
		}
	}
	return root;
}

int findHeight(BstNode* root) {
	if (root==NULL) return 0;
	return fmax(findHeight(root->left), findHeight(root->right))+1;
}

//4.1
bool isBalanced(BstNode* root) {
	if (root == NULL) return true;
	int diff  = findHeight(root->right) - findHeight(root->left);
	if (abs(diff)>1) {
		return false;
	} else {
		return isBalanced(root->left) && isBalanced(root->right);
	}
}



int main() {
	BstNode * root = new BstNode();
	root = insert(9, NULL);
	root = insert(1, root);
	root = insert(1, root);
	root = insert(5, root);
	root = insert(4, root);
	root = insert(3, root);
	root = insert(6, root);
	root = insert(22, root);
	root = insert(11, root);

	inOrder(root);
	search(root, 1);
	root = deleteNode(root, 1);
	inOrder(root);
	cout<<isBalanced(root);

}