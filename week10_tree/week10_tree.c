#include <stdio.h>
#include <stdlib.h>
#include "def10.h"



TreeNode* create_tree_node(void)
{
	TreeNode *p =  (TreeNode*)malloc(sizeof(TreeNode));
	if (p != NULL) {
		p->data = NULL;
		p->left = NULL;
		p->right = NULL;
	}

	return p;
}


void preorder(TreeNode* root) //전위순회
{
	if (root) {
		printf(" %d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
	
}

void inorder(TreeNode* root) //중위순회
{
	if (root) {
		inorder(root->left);
		printf(" %d ", root->data);
		inorder(root->right);
	}

}

void postorder(TreeNode* root) //후위순회
{
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d ", root->data);
	}

}

/*int count_node(TreeNode* root)
{
	if (root == NULL) return 0;
	else {
		return 1 + count_node(root->left) + count_node(root->right);
	}
}*/

/*int calc_height(TreeNode* root)
{
	if (root == NULL) return 0;
	else {
		return 1 + MAX(calc_height(root->left), calc_height(root->right));
	}
}*/

int swap_node(TreeNode* left, TreeNode* right) //왼쪽과 오른쪽 위치 바꾸기
{
	TreeNode* tmp = left;
	left = right;
	right = tmp;
}

int reverse(TreeNode* root)
{
	if (root != NULL) {
		swap_node(root->left, root->right);
		reverse(root->left);
		reverse(root->right);
	}
}





/*void SetTreeNode(TreeNode* node, int data, TreeNode* left, TreeNode* right)
{
	node->data = data;
	node->left = left;
	node->right = right;
}*/


TreeNode* search_tree_data(TreeNode* p, int data)
{
	if (p == NULL) {
		return NULL;
	}
	else if (data == p->data) {
		return p;
	}
}


/*TreeNode init_tree_node1(void)
{
}*/

TreeNode* search(TreeNode* root, int key)
{
	if(root == NULL) return NULL;
	if (root->data == key) {
		return root;
	}
	else if (key < root->data) {
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}
}


/*이진 트리*/

TreeNode* insert_bst_node(TreeNode* parent, int data)
{
	if (parent == NULL) {
		TreeNode* child = create_tree_node();
		child->data = data;
		return child;
	}
	if (parent->data > data) {
		parent->left = insert_bst_node(parent->left, data);
	}	
	else if (parent->data < data) {
		parent->right = insert_bst_node(parent->right, data);
	}
	return parent;
	}

void test_delete_bst(void){
// node 찾기
TreeNode* delete_node = NULL;
TreeNode* node = root;
while (node->data != NULL && node->data != key) {
	delete_node = node;
	node = ? ?  // 키 값이 작으면 왼쪽, 크면 오른쪽 노드
}
case 1:
	각 case에 맞는 코드 작성
		if (n->left == NULL) && node->right == NULL) {
			// 코드 작성
}


void bst_test(void)
{
	TreeNode* root = NULL;

	root = insert_bst_node(root, 18);
	root = insert_bst_node(root, 27);
	root = insert_bst_node(root, 7);
	root = insert_bst_node(root, 12);
	root = insert_bst_node(root, 3);
	root = insert_bst_node(root, 26);
	root = insert_bst_node(root, 31);

	inorder(root);
	printf("\n");
	preorder(root);
}


/*void test_tree()
{
	TreeNode* n1 = create_tree_node();
	TreeNode* n2 = create_tree_node();
	TreeNode* n3 = create_tree_node();
	TreeNode* n4 = create_tree_node();
	TreeNode* n5 = create_tree_node();
	TreeNode* n6 = create_tree_node();

	n1->data = 15;
	n1->left = n2;
	n1->right = n3;

	n2->data = 4;
	n2->left = n4;
	n2->right = NULL;
	
	n3->data = 20;
	n3->left = n5;
	n3->right = n6;

	n4->data = 1;
	n4->left = NULL;
	n4->right = NULL;

	n5->data = 16;
	n5->left = NULL;
	n5->right = NULL;

	n6->data = 25;
	n6->left = NULL;
	n6->right = NULL;

	preorder(n1);
	inorder(n1);
	postorder(n1);

	free(n1); free(n2); free(n3); free(n4); free(n5); free(n6);
}*/




