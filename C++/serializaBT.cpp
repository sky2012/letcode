#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
   
struct biTree
{
   int value;
   biTree *left;
   biTree *right;
   
   biTree(int val) : value(val), left(NULL), right(NULL){}
};

biTree* buildNode(int value)
{
      biTree *T = new biTree(value);
      T->left = NULL;
      T->right = NULL;
      return T;
}

void printPreOrder(biTree *T)
{
    if (T != NULL)
    {
        cout << T->value << endl;
        printPreOrder(T->left);
        printPreOrder(T->right);
    }
}

void printLevel(biTree *T)
{
     vector<biTree*> arr;
     
     int current = 0;
     int last = 0;
     biTree *temp = NULL;
     
     if(T != NULL)
     {
          arr.push_back(T);
          
          while(current < arr.size())
          {
              last = arr.size();
              while(current < last)
              {
                    temp = arr[current]; 
                    cout << temp->value << ' ';
                    if(temp->left != NULL)
                    {
                          arr.push_back(temp->left);
                    }
                    if(temp->right != NULL)
                    {
                          arr.push_back(temp->right);
                    }
                    current++;
              }
              cout << endl;  
          }               
     }
}
   
list<int> encodeTree(biTree *node)
{
   list<int> nodeList;
   queue<biTree*> nodeQueue;
   
   if (node == NULL)
   {
      nodeList.push_back(-1);
	  return nodeList;
   }
   
   nodeQueue.push(node);
        
   while (!nodeQueue.empty())
   {
			if (nodeQueue.front() == NULL)
			{
                nodeList.push_back(-1);
                nodeQueue.pop();
				continue;
			}
			
			nodeList.push_back(nodeQueue.front()->value);

            if (nodeQueue.front()->left == NULL && nodeQueue.front()->right == NULL) 
            {
                  nodeQueue.pop();
                  continue;
		    }
          
            nodeQueue.push(nodeQueue.front()->left == NULL ? NULL : nodeQueue.front()->left);
		    nodeQueue.push(nodeQueue.front()->right == NULL ? NULL : nodeQueue.front()->right);
		    nodeQueue.pop();
   }               
   return nodeList; 
} 

biTree* decodeTree(list<int> nodeList)
{
   if (nodeList.empty() || nodeList.front() == -1)
   {
       return NULL;
   }
   
   queue<biTree *> nodeQueue;
   biTree *root = new biTree(nodeList.front());
   nodeQueue.push(root);
   list<int>::iterator it = nodeList.begin();
   it++;
   while (it != nodeList.end())
   {	
        biTree *currentNode = nodeQueue.front();
		
		if (*it != -1)
		{
			currentNode->left = new biTree(*it);
			nodeQueue.push(currentNode->left);
		}
		it++;
		
		if (*it != -1)
		{
			currentNode->right = new biTree(*it);
			nodeQueue.push(currentNode->right);
		} 
		it++;
		nodeQueue.pop();
	}		
   
   return root; 
} 

void encodeTree2(biTree *node, list<int>& nodeList)
{
   biTree *ptr = node;
       
   if (!ptr) 
   {
      nodeList.push_back(-1);
   }
   else 
   {
       nodeList.push_back(ptr->value);
       encodeTree2(ptr->left, nodeList);
       encodeTree2(ptr->right, nodeList);
   }  
}

biTree *decodeTree2(list<int>& nodeList)
{
	if (nodeList.empty())
	{
        return NULL;
    } 
	
	if (*(nodeList.begin()) == -1)
	{
		nodeList.erase(nodeList.begin());
		return NULL;
	}

	biTree *root = new biTree(*(nodeList.begin()));
	nodeList.erase(nodeList.begin());
	root->left = decodeTree2(nodeList);
	root->right = decodeTree2(nodeList);
	return root;
}			

list<int> encodeTree3(biTree *root)
{
	list<int> result;
	list<biTree *> current;
	
	if (root == NULL)
	{
		result.push_back(-1);
		return result;
	}
	
	if (root->left == NULL && root->right == NULL)
	{
		result.push_back(root->value);
		return result;
	}
	
	biTree *ptr = root;
	current.push_back(ptr);
	
	while (!current.empty())
	{
		list<biTree *> parent = current;
		current.clear();
		
		list<biTree *>::iterator it;
		
		for (it = parent.begin(); it != parent.end(); it++)
		{
			if ((*it)->left == NULL && (*it)->right == NULL)
			{
				result.push_back((*it)->value);
			}
			
			if ((*it)->left != NULL)
			{
				parent.push_back((*it)->left);
			}
			
			if ((*it)->right != NULL)
			{
				parent.push_back((*it)->right);
			}
		}
	}
		
	return result;	
}

void inOrderTraverse(biTree *root)
{
     if (root != NULL)
     {
           inOrderTraverse(root->left);
           cout << root->value << ' ';
           inOrderTraverse(root->right);
     }
}

void inOrderTraverse2(biTree *root)
{
     stack<biTree *> nodeStack;
     biTree *ptr = root;
     
     while (!nodeStack.empty() || ptr != NULL)
     {
           if (ptr != NULL)
           {
                   nodeStack.push(ptr);
                   ptr = ptr->left;                 
           }
           else
           {
                ptr = nodeStack.top();
                nodeStack.pop();
                cout << ptr->value << ' ';
                ptr = ptr->right;
           }
     }
}

vector<int> printLeaves(biTree *root)
{
	vector<int> result;
	queue<biTree *> nodeQueue;
	
	//if (root == NULL)
//	{
//		return result;
//	}
	
	biTree *ptr = root;
	nodeQueue.push(ptr);
	
	while (!nodeQueue.empty())
	{
		biTree *currentNode = nodeQueue.front();
		nodeQueue.pop();
		
		if (currentNode->left == NULL && currentNode->right == NULL)
		{
			result.push_back(currentNode->value);
		}
		
		if (currentNode->left != NULL)
		{
			nodeQueue.push(currentNode->left);
		}
		
		if (currentNode->right != NULL)
		{
			nodeQueue.push(currentNode->right);
		}
	}
	
	return result;
}

vector<int> printLeaves2(biTree *root)
{
	vector<int> result;
	list<biTree *> current;
	
	if (root == NULL)
	{
		return result;
	}
	
	if (root->left == NULL && root->right == NULL)
	{
		result.push_back(root->value);
		return result;
	}
	
	biTree *ptr = root;
	current.push_back(ptr);
	
	while (!current.empty())
	{
		list<biTree *> parent = current;
		current.clear();
		
		list<biTree *>::iterator it;
		
		for (it = parent.begin(); it != parent.end(); it++)
		{
			if ((*it)->left == NULL && (*it)->right == NULL)
			{
				result.push_back((*it)->value);
			}
			
			if ((*it)->left != NULL)
			{
				parent.push_back((*it)->left);
			}
			
			if ((*it)->right != NULL)
			{
				parent.push_back((*it)->right);
			}
		}
	}
		
	return result;	
}


int main()
{
    biTree *root = buildNode(30);
    root->left        = buildNode(10);
    root->right       = buildNode(20);
    root->left->left  = buildNode(50);
    root->left->left->right  = buildNode(70);
    root->right->left  = buildNode(45);
    root->right->right = buildNode(32);
    
     inOrderTraverse(root);
     cout << endl;
     list<int> mylist;
     encodeTree2(root, mylist);
     list<int>::iterator it;
     for (it = mylist.begin(); it != mylist.end(); it++)
     {
         cout << *it << ' ';
     } 
     cout << endl;
     biTree *newTree = decodeTree2(mylist);
     inOrderTraverse(newTree);
	 cout << endl;
	 
//	 vector<int> leaves = printLeaves(root);
//	 vector<int> leaves2 = printLeaves2(root);
//	 vector<int>::iterator itv;
//	 for (itv = leaves.begin(); itv != leaves.end(); itv++)
//     {
//         cout << *itv << ' ';
//     } 
//	 
//     cout << endl;
//	 
//	 for (itv = leaves2.begin(); itv != leaves2.end(); itv++)
//     {
//         cout << *itv << ' ';
//     } 
//	 
	 cout << endl;
     system("pause");
     return 0;
}
           
       
       
       
           
           
   
   
   
              
              
         
