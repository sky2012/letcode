#include <iostream>
#include <list>

using namespace std;

#define TREE_DEPTH_EQUAL_TO_VALUE MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_ITF, 101)
#define TREE_DEPTH_GREATER_THAN_VALUE MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 102)
#define TREE_DEPTH_LESS_THAN_VALUE MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 103)
#define VALUE_IS_NEGATIVE MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 104)
#define TREE_NODE_IS_NULL MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 105)

struct NODE
{
    NODE* pLeft;
	NODE* pRight;
};

HRESULT TreeHasDepth(NODE* pNode, int depth)
{	
	if (depth < 0)
	{
		return VALUE_IS_NEGATIVE;
	}
	
	if (!pNode)
	{
		return TREE_NODE_IS_NULL;
	}	
	
	int depthTree = TreeDepth(pNode);
	if (depthTree > depth)
	{
		return TREE_DEPTH_GREATER_THAN_VALUE;
	}
	else if (depthTree < depth)
	{
		return TREE_DEPTH_LESS_THAN_VALUE;
	}
	else
	{
		return TREE_DEPTH_EQUAL_TO_VALUE;
	}
}

int TreeDepth(NODE* pNode)
{
	// If the node is NULL, the depth is 0
	// In many textbooks, the height of a tree is the length of the path from 
	// the root to the deepest node in the tree. A (rooted) tree with only one node (the // root) has a height of 0 and a depth of 1.
	// In this code, we assume a (rooted) tree with only one node has a depth of 1.
	if (!pNode) 
	{
		return 0;
	}
	// return 1 + max(TreeDepth(pNode->pLeft), TreeDepth(pNode->pRight));
	
	// get the depth of the left child
	int depthLeft = TreeDepth(pNode->pLeft);
	
	// get the depth of the right child
	int depthRight = TreeDepth(pNode->pRight);
	
	return (depthLeft > depthRight) ? depthLeft + 1 : depthRight + 1;
}



   
struct NODE
{
   int value;
   NODE *pLeft;
   NODE *pRight;
   
   NODE(int val) : value(val), pLeft(NULL), pRight(NULL){}
};

NODE* buildNode(int value)
{
      NODE *T = new NODE(value);
      T->pLeft = NULL;
      T->pRight = NULL;
      return T;
}

// Get the depth of tree using recusive method                          
int TreeDepth(NODE* pNode)
{
	// If the node is NULL, the depth is 0
	// In many textbooks, the height of a tree is the length of the path from 
	// the root to the deepest node in the tree. A (rooted) tree with only one node (the // root) has a height of 0 and a depth of 1.
	// In this code, we assume a (rooted) tree with only one node has a depth of 1.
	if (!pNode) 
	{
		return 0;
	}
	// return 1 + max(TreeDepth(pNode->pLeft), TreeDepth(pNode->pRight));
	
	// get the depth of the pLeft child
	int depthLeft = TreeDepth(pNode->pLeft);
	
	// get the depth of the pRight child
	int depthRight = TreeDepth(pNode->pRight);
	
	return (depthLeft > depthRight) ? depthLeft + 1 : depthRight + 1;
}

// Get the depth of the tree using level-order traversal
int TreeDepthLevelOrder(NODE* pNode)
{
    int depth = 0;
    list<NODE*> current;
    
    // visit the (root) node
    if(pNode != NULL)
    {
          current.push_back(pNode);
    }
    
    while (!current.empty())
    {
          depth++;
          
          // Traverse the next level
          
          // Store the elements in a new list parents
          list<NODE*> parents = current;
          // Clear all the elements in the list current
          current.clear();
          
          list<NODE*>::iterator it;
          
          // Visit the children
          for (it = parents.begin(); it != parents.end(); it++)
          {
              if ((*it)->pLeft != NULL)
              {
                   current.push_back((*it)->pLeft);
              }
              if ((*it)->pRight != NULL)
              {
                   current.push_back((*it)->pRight);
              }
          }
    }
    
    return depth;          
}


int main()
{
    NODE *root = buildNode(30);
    root->pLeft        = buildNode(10);
    root->pRight       = buildNode(20);
    root->pLeft->pLeft  = buildNode(50);
    root->pRight->pLeft  = buildNode(45);
    root->pRight->pRight = buildNode(32);
    root->pRight->pRight->pLeft = buildNode(78);
    
     cout << TreeDepth(root) << endl;
     cout << TreeDepthLevelOrder(root) << endl;
     system("pause");
     return 0;
}    
       
    
   
   
   
              
              
         
