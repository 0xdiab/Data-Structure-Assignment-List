// Implementation file
// functions implementation code
#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
    head = prev = cursor = NULL;
}

// Class Destructor
// template <class keyType, class dataType>
List::~List()
{
	makeListEmpty();
}

bool List::listIsEmpty() const
{
    return (head == NULL);
}

bool List::curIsEmpty() const
{
    return (cursor == NULL);
}

bool List::atFirst() const
{
    return (cursor == head);
}

void List::toFirst()
{
    cursor = head;
    prev = NULL;
}

void List::advance()
{
    prev = cursor;
	cursor = cursor->next;
}

void List::toEnd()
{
    toFirst();
    if(!listIsEmpty())
    {
        while(cursor->next != NULL)
        {
            advance();
        }
    }

}


bool List::atEnd()
{
    if(!listIsEmpty())
    {
        return true;
    }else if(curIsEmpty())
    {
        return true;
    }else
    {
        return (cursor->next == NULL);
    }

}

int List::listSize() const
{
	NodePointer q; // node * q;
	int count;
	q = head;
	count = 0;
	while (q != NULL)
	{
		count++;
		q = q->next;
	}
	return count;
}

void List::updateData(const char &d)
{
    cursor->data = d;
}

char List::retrieveData()
{
    return cursor->data;
}

// to return the data in the current node;
// assume the current position is nonempty.
// template <class keyType, class dataType>
void List::retrieveData(char &d, int &k) const
{
	d = cursor->data; // return cursor->data
	k = cursor->key;
}


void List::retrieveKey(int &k) const
{
	k = cursor->key; // return cursor->data
}

void List::insertFirst(int k, char d)
{
    node *q = new node;
    q->key = k;
    q->data = d;
    q->next = head;
    head = q;
    cursor = q;
    prev = NULL;
}

void List::insertAfter(int k, char d)
{

    node *q = new node;
    q->key = k;
    q->data = d;
    q->next = cursor->next;
    cursor->next = q;
    prev = cursor;
    cursor = q;
}

void List::insertBefore(int k, char d)
{
    if (prev == NULL) {
        insertFirst(k, d);
    } else {
        node *q = new node;
        q->key = k;
        q->data = d;
        q->next = prev->next;
        prev->next = q;
        cursor = q;
    }
    /*
    node *q = new node;
    q->key = k;
    q->data = d;
    q->next = prev->next;
    prev->next = q;
    cursor = q;*/
}

void List::insertEnd(int k, char d)
{
    if(listIsEmpty())
    {
        insertFirst(k, d);
    }else
    {
        toEnd();
        insertAfter(k, d);
    }
}

void List::deleteNode()
{
    node *q;
    if(!listIsEmpty())
    {
        if(atFirst())
        {
            q = cursor;
            cursor = cursor->next;
            head = cursor;
            delete q;
        }else
        {
            q = cursor;
            cursor = cursor->next;
            prev->next = cursor;
            delete q;
        }
    }
}

void List::deleteFirst()
{
    if(!listIsEmpty())
    {
        toFirst();
        deleteNode();
    }
}

void List::deleteEnd()
{
    if(!listIsEmpty())
    {
        toEnd();
        deleteNode();
    }
}

void List::makeListEmpty()
{
     toFirst();
     while (! listIsEmpty())
        deleteNode();
}

// search the list for the node with key part that matches (k).
// If found, set cursor to the node and return True,
// else return false and the current position becomes empty.
// template <class keyType, class dataType>
bool List::search(const int &k)
{
	bool found = false;
	toFirst();
	while ((!found) && (cursor != NULL))
		if (k == cursor->key)
			found = true;
		else
			advance();
	return found;
}

// insert a node in a position that maintains an ascending
// order of the key portion of the nodes.
// template <class keyType, class dataType>
void List::orderInsert(const char &d, const int &k)
{
	toFirst();
	while ((cursor != NULL) && (k > cursor->key))
		advance();
	if (prev == NULL)
		insertFirst(k, d);
	else
		insertBefore(k, d);
}

// traverse list to print key and data fields
// template <class keyType, class dataType>
void List::traverse()
{

	toFirst();
	while (!curIsEmpty())
	{
		cout << cursor->data << " - " << cursor->key << endl;
		advance();
	}
}

int List::getMiddle()
{
	NodePointer p, q;
	int count = 0;
	p = head;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	q = head;
	for (int i = 0; i < (count / 2); i++)
	{
		q = q->next;
	}

	return q->key;
}

void List::reverse()
{
	NodePointer next;
	toFirst();
	while (!curIsEmpty())
	{
		next = cursor->next;
		cursor->next = prev;
		prev = cursor;
		cursor = next;
	}
	head = prev;
}

bool List::Sortedlist()
{
	int d1, d2;

	if (listIsEmpty())
		cout << "List Is Empty" << endl;
	else
	{
		toFirst();
		while (cursor->next != NULL)
		{
			retrieveKey(d1);
			advance();
			retrieveKey(d2);

			if (d1 > d2)
			{
				return false;
				break;
			}
		}
		return true;
	}
}

void List::selectionSort()
{
	node *p, *smallptr, *q;
	int smallest;
	p = head;

	while (p != NULL)
	{
		smallptr = p;
		smallest = p->key;
		q = p->next;

		while (q != NULL)
		{
			if (q->key < smallest)
			{
				smallptr = q;
				smallest = q->key;
			}
			q = q->next;
		}

		smallptr->key = p->key;
		p->key = smallest;
		p = p->next;
	}
}

void List::insertionSort()
{
	node *current = head;
	node *insertionPointer = head;

	current = current->next;

	while (current != NULL)
	{

		insertionPointer = head;

		while (insertionPointer->next != NULL)
		{

			if (insertionPointer->data > current->data)
			{

				int temp = current->key;
				current->key = insertionPointer->key;
				insertionPointer->key = temp;
			}
			else
			{
				insertionPointer = insertionPointer->next;
			}
		}

		current = current->next;
	}
}

int List::Recursive_List_Size()
{
    return Recursive_List_Size(head);
}

int List::Recursive_List_Size(NodePointer p)
{
    if (p == NULL)
        return 0;

    return 1 + Recursive_List_Size(p->next);
}

void List::DispalyList()
{
    DispalyList(head);
}

void List::DispalyList(NodePointer p)
{
    if (p == NULL)
        return;

    cout << p->key << " " << p->data << endl;
    DispalyList(p->next);
}



/*
void List::DispalyList()
{
	Display(head);
}

void List::Display(NodePointer h)
{
	if (h == NULL)
		return;

	else
		cout << h->key << " " << h->data << endl;
	Display(h->next);
}


int List::List_Size2(NodePointer h)
{
	if (h == NULL)
		return 0;
	else
		return 1 + List_Size2(h->next);
}

// list size recursive
int List ::Recursive_List_Size()

{
	return List_Size2(head);
}
*/
/*
void List::Display(NodePointer h)
{
	if (h == NULL)
		return;

	else
		cout << h->key << " " << h->data << endl;
	Display(h->next);
}

void List::DispalyList()
{
	Display(head);
}


*/

