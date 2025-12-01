#ifndef LIST_H
#define LIST_H
// Header file
// Class definition, data members, functions prototype

class List
{
    // Data Member
    class node
    {
        public:
            int key;
            char data;
            node *next;
    };

    typedef node * NodePointer;

    node *head, *prev, *cursor;

    public:
        List(); // Constructor
        ~List();
        bool listIsEmpty() const; // return True if list is empty
        bool curIsEmpty() const; // return True if current position is empty
        bool atFirst() const; // to return True if the current node is the first node or if the list and the current position are both empty.
        void toFirst(); // to make the current node the first node; if list is empty, the current position is still empty
        void advance(); // to advance to next node. Assume the current position is nonempty initially.
        void toEnd(); // to make the current node the tail node; if list is empty, the current position is still empty
        bool atEnd(); //to return True if the current node is the tail node or if the list and the current position are both empty.
        int listSize() const; // to return the size of the list
        void updateData(const char &d); // to update the data portion of the current node to contain d; assume the current position is nonempty.
        char retrieveData(); // to return the data in the current node; assume the current position is nonempty.
        void retrieveData(char &, int &) const;

        void retrieveKey(int &k) const;
        void insertFirst(int k, char d); // insert a node with key (k) and data (d) at the head of the list; the new node becomes the current node.
        void insertAfter(int k, char d); // insert a node after the current node without changing the current position; assume the current position is nonempty in a non-empty list.
        void insertBefore(int k, char d); // insert a node before the current node ; current position becomes the new node
        void insertEnd(int k, char d); // insert a node at the end of the list, current position becomes the new node.
        void deleteNode(); // delete the current node and set the current position to the next node; if the current node is the last node initially, the current position becomes empty; assume the current position is nonempty initially.
        void deleteFirst(); // delete the first node and set the current position to the next node; if it was initially the only node, the current position becomes empty;
        void deleteEnd(); // delete the last node and set the current position to empty.
        void makeListEmpty(); // delete whole list
        bool search(const int & ); // search the list for the node with key part that matches (k). If found, set cursor to the node and return True, else return false and the current position becomes empty.
        void orderInsert(const char &, const int & ); // insert a node in a position that maintains an ascending order of the key portion of the nodes.

        void traverse(); // traverse list to print key and info fields.

        //exercises
        int getMiddle();
        void reverse();
        bool Sortedlist();
        void selectionSort();
        void insertionSort();

        //exercises
        int Recursive_List_Size( ) ;
        void DispalyList( ) ;
    private:
        int Recursive_List_Size(NodePointer);
        void DispalyList(NodePointer);



};





#endif // LIST_H
