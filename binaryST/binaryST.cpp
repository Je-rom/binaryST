

#include <iostream>
#define SPACE 10

using namespace std;


class TreeNode
{
public:
	int value;
	TreeNode* left;
	TreeNode* right;

	TreeNode() 
	{
		value = 0;
		left = NULL;
		right = NULL;
	}
	TreeNode(int value)
	{
		this->value = value;
		left = NULL;
		right = NULL;
	}
};

class BST
{
public:
	TreeNode *root;

	BST()
	{
		root = NULL; // root is point nothing (null)
	}

	bool isEmpty()
	{
		if (root == NULL)
		{
			return true; // tree is empty
		}
		else
		{
			return false;
		}
	}

	void insertNode(TreeNode* new_node)
	{
		if (root == NULL)
		{
			root = new_node;
			cout << "Value inserted as root node" << endl;
		}
		else
		{
			TreeNode* temp = root; //creating a temp treenode to traverse through the tree
			while (temp != NULL)
			{
				if (new_node->value == temp->value) // if new node value is same as a value already in the tree
				{
					cout << "No duplicates allowed, insert another value" << endl;
					return;
				}
				else if ((new_node->value < temp->value) && (temp->left == NULL))
				{
					temp->left = new_node;
					cout << "Value inserted to the left" << endl;
					break;
				}
				else if (new_node->value < temp->value)
				{
					temp = temp->left; // traverse when left side is not null
				}
				else if ((new_node->value > temp->value && temp->right == NULL))
				{
					temp->right = new_node;
					cout << "Value inserted to the right" << endl;
					break;
				}
				else
				{
					temp = temp->right; // traverse when right side is not null
				}
			}
		}
	}

	TreeNode* recursiveSearch(TreeNode* r, int val)
	{
		if (r == NULL || r->value == val)
		{
			return r;
		}
		else if(val < r->value)
		{
			return recursiveSearch(r->left, val);
		}
		else
		{
			return recursiveSearch(r->right, val);
		}
	}

	TreeNode* iterativeSearch(int v) 
	{
		if (root == NULL)
		{
			return root;
		}
		else
		{
			TreeNode* temp = root;
			while (temp!= NULL)
			{
				if (v == temp->value)
				{
					return temp;
				}
				else if (v < temp->value)
				{
					temp = temp->left;
				}
				else
				{
					temp = temp->right;
				}
			}
			return NULL;
		}
	}

	int height(TreeNode* r)
	{
		if (r == NULL)
		{
			return -1;
		}
		else
		{
			int lheight = height(r->left);
			int rheight = height(r->right);

			if (lheight > rheight)
				return(lheight + 1);
			else return(rheight + 1);
		}
	}

	void printGivenLevel(TreeNode* r, int level)
	{
		if (r == NULL)
			return;
		else if (level == 0)
			cout << r->value << " ";
		else
		{
			printGivenLevel(r->left, level - 1);
			printGivenLevel(r->right, level - 1);
		}
	}
	void printLevelOrder(TreeNode* r)
	{
		int h = height(r);
		for (int i = 0; i <= h; i++)
		{
			printGivenLevel(r, i);
		}
	}


	void printPreorder(TreeNode* r) // (root, left, right)
	{
		if (r == NULL)
			return;
		//first print current data of node
		cout << r->value << " ";

		// now recur on left subtree
		printPreorder(r->left);

		// now recur on right subtree
		printPreorder(r->right);
	}

	void printInorder(TreeNode* r) // (left, root, right)
	{
		if (r == NULL)
			return; // return current value of node

		// now recur on left subtree
		printInorder(r->left);

		//first print data of node
		cout << r->value << " ";

		// now recur on right subtree
		printInorder(r->right);
	}

	void printPostorder(TreeNode* r)  // (left, right, node)
	{
		if (r == NULL)
			return;
		// now recur on left subtree
		printPostorder(r->left);

		// now recur on right subtree
		printPostorder(r->right);

		//first print data of node
		cout << r->value << " ";
	}

	void print2D(TreeNode* r, int space)
	{
		if (r == NULL) //base case
			return;
		space += SPACE; // increase distance between levels
		print2D(r->right, space);
		cout << endl;
		for (int i = SPACE; i < space; i++) //print current node after space count
			cout << " ";
		cout << r->value << "\n";
		print2D(r->left, space); //process left child
	}
	 
};  
 




int main() {

	BST bs;
	int option, val;

	do {
		
		cout << "What operation do you want to perform? Select option number. Enter 0 to exit" << endl;
		cout << "1. insert node" << endl;
		cout << "2. search node" << endl;
		cout << "3. delete node" << endl;
		cout << "4. print BST values" << endl;
		cout << "5. height of tree" << endl;
		cout << "6. clear screen" << endl;
		cout << "0. exit program" << endl;

		cin >> option;

		TreeNode* new_node = new TreeNode();

		switch (option)
		{
			case 0: 
				break;

			case 1: 
				cout << "insert node" << endl;
				cout << "Enter value of node to insert into the tree: ";
				cin >> val;
				new_node->value = val;
				bs.insertNode(new_node);
				cout << endl;
				break;

			case 2:
				cout << "search node" << endl;
				cout << "Enter a value you want to search for: ";
				cin >> val;
				//new_node = bs.iterativeSearch(val);
				new_node = bs.recursiveSearch(bs.root, val);
				if (new_node != NULL)
				{
					cout << "value " << val << " found" << endl;
				}
				else
				{
					cout << "value " << val << " NOT found" << endl;
				}
				break;

			case 3:
				cout << "delete node" << endl;

				break;

			case 4:
				cout << "print BST values" << endl;
				bs.print2D(bs.root, 5);
				//bs.printPreorder(bs.root);
				//bs.printInorder(bs.root);
				//bs.printPostorder(bs.root);
				bs.printLevelOrder(bs.root);
				break;

			case 5:
				cout << "tree height" << endl;
				cout << "height: " << bs.height(bs.root) << endl;
				break;

			case 6:
				cout << "clear screen" << endl;
				system("cls");
				break;

			default: 
				cout << "Enter a valid operation" << endl;
				break;

		}

	} while (option != 0);

	return 0;
}