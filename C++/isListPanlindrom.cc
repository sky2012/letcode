#include <iostream>

using namespace std;

struct LinkList
{
    int data;
    LinkList *next;
};

LinkList* createList(int arr[], int length)
{
      LinkList *head;
      LinkList *ptr;
      LinkList *newNode;
            
      head = new LinkList;
      head->data = arr[0];
      head->next = NULL;
      ptr = head;

      for (int i = 1; i < length; i++)
      {
    	  newNode = new LinkList;
    	  newNode->data = arr[i];
    	  newNode->next = NULL;
    
    	  ptr->next = newNode;
          ptr = ptr->next;
      }
      
      return head;
}

void displayList(LinkList *L)
{
     LinkList *ptr = L;
     
     cout << "The content of the linked list is: ";
     while (ptr)
     {
          cout << ptr->data << " ";
    	  ptr = ptr->next;
     }
     cout << endl;
}

LinkedList* reverseList(LinkedList *head)
{
	LinkedList *current = head;
	LinkedList *prev = NULL;
	LinkedLisst *next = NULL;
	
	while (current->next)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	return prev;
}

LinkedList* findListMiddle(LinkedList *head)
{
	LinkedList *fast = head;
	LinkedList *slow = head;
	
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	
	if (fast->next)
	{
		
	
	while (first && second)
	{
		if (first->value != second->value)
		{
			return false;
		}
	}
	
	return false;
}

int main()
{   
      int num = 0;
      int temp = 0;
      int pos = 1;
      LinkList *newArray;
      int *array;
      array = new int[10];
      
      cout << "Please enter the number of nodes in the linked list: ";
      cin >> num;
      
      cout << "Please enter the value: ";      
      for (int i = 0; i < num; i++)
      {
          cin >> array[i];
      }
      
      newArray = createList(array, num);
      displayList(newArray);
	  
	  bool isPanli = isPalindrome(newArray);
	  
	  if (isPanli)
	  {
			cout << "The linked list is palindrom." << endl;
	  }
	  else
	  {
			cout << "The linked list is not palindrom." << endl;
      }
             
      return 0;
}