#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *right;
	Node *left;

	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};


Node *insert(Node *root, int data){
	if( !root ) return new Node(data);	

	if( root->data > data ){
		root->left = insert(root->left, data);
	}else{
		root->right = insert(root->right, data);
	}

	return root;

}


void inOrder(Node *root){
	if( !root ) return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right); 

}

void postOrder(Node *root){
	if( !root ) return;

	postOrder(root->left);
	postOrder(root->right); 
	cout << root->data << " ";

}

void preOrder(Node *root){
	if( !root ) return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right); 

}

void search(Node *root, int searchValue){

	if( !root ) {
		cout << "Value not found!" << endl;
		return;
	}

	if( root->data == searchValue ){
		cout << "Value is found!" << endl;
		return;
	}

	if( root->data > searchValue ){
		search(root->left, searchValue);
	}else{
		search(root->right, searchValue);
	}
}


Node* deleteNode(Node *root, int data){
	if( !root ) return NULL;

	if( root->data > data ) {
		root->left = deleteNode(root->left, data);
	}else if( root->data < data ){
		root->right = deleteNode(root->right, data);
	}else{

		if( !root->left && !root->right ){
			return NULL;
		}
		else if( !root->left ) {
			return root->right;
		}
		else if( !root->right ){
			return root->left;
		}else{

			Node *curr = root->right;
			
			if( !curr->left ){
				root->data = curr->data;
				root->right = curr->right;
			}else{
				Node *prev = NULL;
				while( curr->left ){
					prev = curr;
					curr = curr->left;
				}

				root->data = curr->data;
				prev->left = curr->right;

			}
			
		}

	}

	return root;
}	


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = NULL;

	while( true ){
		int input;
		cin >> input;

		if( input == -1 ) break;
		
		root = insert(root, input);
	}


	preOrder(root);

	cout << endl;

	search(root, 4);

	deleteNode(root, 15);
	
	preOrder(root);
}