#include <stdio.h>
#include <stdlib.h>
#include "def_tree.h"


TreeNode* create_tree_node(void)
{
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	if (p != NULL) {
		p->data = 0;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

void inorder(TreeNode* root) //중위순회
{
	if (root) {
		inorder(root->left);
		printf(" %d ", root->data);
		inorder(root->right);
	}

}

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



TreeNode* bst_sample1(void)
{
	TreeNode* root = NULL;

	root = insert_bst_node(root, 35);
	root = insert_bst_node(root, 18);
	root = insert_bst_node(root, 7);
	root = insert_bst_node(root, 3);
	root = insert_bst_node(root, 12);
	root = insert_bst_node(root, 26);
	root = insert_bst_node(root, 22);
	root = insert_bst_node(root, 30);
	root = insert_bst_node(root, 68);
	root = insert_bst_node(root, 99);
	return root;
}

void test_delete_bst(void) {
	printf("test bst\n");
	
	TreeNode* root = bst_sample1();
	TreeNode* delete_node = NULL;
	TreeNode* partent_node = NULL;
	inorder(root);
	int key = 22;
	TreeNode* temp_node = NULL;
	TreeNode* temp_parent = NULL;
	printf("\n");



	// 삭제할 노드를 찾는 코드(키 값이 일치)
	delete_node = root;
	partent_node = NULL;
	while (delete_node != NULL && delete_node->data != key) 
	{
		partent_node = delete_node;
		if (delete_node->data < key)
		{
			delete_node = delete_node->right;
		}
		else
		{
			delete_node = delete_node->left;
		}
	
	}


	//case 1 단말노드인 경우
	if (delete_node->left == NULL && delete_node->right == NULL)
	{
		if (partent_node != NULL) {
			if (partent_node->left == delete_node)
			{
				partent_node->left = NULL;
			}
			else
			{
				partent_node->right = NULL;
			}
		}
		else
		{
			root = NULL;
		}
		free(delete_node);
	}

	//case 2 하나의 서브 트리만 가지고 있는 경우
	else if (delete_node->left != NULL && delete_node->right == NULL)
	{	
		if (delete_node == root)
		{
			root = delete_node->left;
		}

		else if (partent_node->left == delete_node)
		{
			partent_node->left = delete_node->left;
		}
		else
		{
			partent_node->right = delete_node->left;
		}
		free(delete_node);
	}
	else if (delete_node->left == NULL && delete_node->right != NULL)
	{
		if (delete_node == root)
		{
			root = delete_node->right;
		}

		if (partent_node->left == delete_node)
		{
			partent_node->left = delete_node->right;
		}
		else
		{
			partent_node->right = delete_node->right;
		}
		free(delete_node);
	}


	//case 3 두 개의 서브 트리를 가지고 있는 경우, 노드보다 큰 값중 가장 작은 값의 노드로 대체
	else
	{
	//큰 값중 가장 작은 키 값을 가지고 있는 노드를 찾는다
		temp_node = delete_node->right;
		
		while (temp_node != NULL)
		{
			temp_parent = temp_node;
			temp_node = temp_node->left;
		}
		if (partent_node->left = delete_node)
		{	
			partent_node->left = temp_node;
			/*temp_parent->left = NULL;
			free(delete_node);*/
		}
		else
		{
			partent_node->right = temp_node;
			/*temp_parent->right = NULL;
			free(delete_node);*/
		}
		temp_parent->left = NULL;
		free(delete_node);
	}
		
	inorder(root);
}