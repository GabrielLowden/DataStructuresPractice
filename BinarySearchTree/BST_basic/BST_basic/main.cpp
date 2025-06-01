#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	//define node properties
	int key;
	Node* left;
	Node* right;
	
	//constructor
	Node(int item) {
		key = item;
		left = right = NULL;
	}
};

//A helper function to insert a new node
Node* insert(Node* node, int key) {

	//endcase -> empty tree, return a new node
	if (node == NULL) {
		return new Node(key);
	}

	//endcase -> If the key is already present, return the node
	if (node->key == key) {
		return node;
	}

	//move left or right
	if (node->key < key) {
		node->right = insert(node->right, key);
	}
	else {
		node->left = insert(node->left, key);
	}

	return node;
}

//Inorder Traversal
void printInorder(Node* node) {
	//check endcase
	if (node == NULL) {
		return;
	}

	//move left in tree
	printInorder(node->left);

	//output key
	cout << node->key << " ";

	//move right
	printInorder(node->right);
}

//Search function
Node* search(Node* root, int key) {
	
	//check endcase
	if (root == NULL || root->key == key) {
		return root;
	}

	//key is greater than reference key
	if (root->key < key) {
		return search(root->right, key);
	}

	//key is less than ref key
	return search(root->left, key);
}

//Find successor node
Node* getSuccessor(Node* node) {
	node = node->right;
	while (node != nullptr && node->left != nullptr) {
		node = node->left;
	}
	return node;
}

//Delete Function
Node* delNode(Node* node, int key) {
	
	//If the root node does not have a key, just return it
	if (node == NULL) {
		return node;
	}

	if (node->key > key) {
		node->left = delNode(node->left, key);
	}
	else if (node->key < key) {
		node->right = delNode(node->right, key);
	}
	else {
		if (node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			return temp;
		}
		
		if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			return temp;
		}

		Node* succ = getSuccessor(node);
		node->key = succ->key;
		node->right = delNode(node->right, succ->key);
	}
	return node;
}

//Function to check BST within a given range
bool isBST(Node* node, int min, int max) {
	if (node == nullptr) {
		return true;
	}

	if (node->key < min || node->key > max) {
		return false;
	}
	return isBST(node->left, min, node->key - 1) &&
		isBST(node->right, node->key + 1, max);
}

//sort a tree with inorder traversal
void storeInorder(Node* node, vector<int>& nodes) {
	if (node == nullptr) {
		return;
	}
	storeInorder(node->left, nodes);
	nodes.push_back(node->key);
	storeInorder(node->right, nodes);
}

//Builds a balanced BST from sorted array
Node* buildBalancedTree(vector<int>& nodes, int start, int end) {
	if (start > end) {
		return nullptr;
	}
	int mid = (start + end) / 2;
	Node* node = new Node(nodes[mid]);

	node->left = buildBalancedTree(nodes, start, mid - 1);
	node->right = buildBalancedTree(nodes, mid + 1, end);

	return node;
}

//fucntion to balance a BST
Node* balanceBST(Node* node) {
	vector<int> nodes;
	storeInorder(node, nodes);
	return buildBalancedTree(nodes, 0, nodes.size() - 1);
}

//Find min
Node* findMin(Node* node) {
	if (node == nullptr) {
		return nullptr;
	}
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

//Find max
Node* findMax(Node* node) {
	if (node == nullptr) {
		return nullptr;
	}
	while (node->right != nullptr) {
		node = node->right;
	}
	return node;
}

//

int main() {

	Node* root = new Node(100);
	insert(root, 30);
	printInorder(root);

	return 0;
}
