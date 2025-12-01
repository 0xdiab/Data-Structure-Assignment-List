// Application File

#include <iostream>
#include "List.h"

using namespace std;

int main()
{

	List l;
	l.insertEnd(10, 'I');
	l.insertEnd(100, 'M');
	l.insertEnd(80, 'S');
	l.insertEnd(35, 'A');
	l.insertEnd(50, 'L');

    cout << "Original List: "<<endl;
    l.traverse();

    // Insert After
    l.toFirst();           // move cursor to first
    l.advance();           // move cursor to second
    if (!l.curIsEmpty()) {
        l.insertAfter(4, 'Z');
    } else {
        cout << "Cursor is empty! Cannot insertAfter.\n";
    }
    cout << "\nAfter insertAfter: "<<endl;
    l.traverse();

    l.selectionSort();
    cout << "\nAfter Selection Sort: "<<endl;
    l.traverse();

    // Insert Before
    l.toFirst();            // move cursor to first
    l.insertBefore(2, 'A'); // insert before cursor
    cout << "\nAfter insertBefore: "<<endl;
    l.traverse();

    // Delete Node
    l.toFirst();
    l.advance();  // move cursor to second
    l.deleteNode();
    cout << "\nAfter deleteNode at second node: "<<endl;
    l.traverse();

    // Delete First
    l.deleteFirst();
    cout << "\nAfter deleteFirst: "<<endl;
    l.traverse();

    // Delete End
    l.deleteEnd();
    cout << "\nAfter deleteEnd: "<<endl;
    l.traverse();


    // Get Middle
    cout << "\nMiddle key = " << l.getMiddle() << endl;

    // Recursive List Size
    cout << "\nRecursive list size = " << l.Recursive_List_Size() << endl;

    // Display List Recursively
    cout << "\nDisplay list recursively: "<<endl;
    l.DispalyList();


    List m;
    m.insertEnd(100, 'D');
    m.insertEnd(200, 'I');
    m.insertEnd(300, 'A');
    m.insertEnd(400, 'B');
    cout << "\nList m Before Reverse: "<<endl;
    m.traverse();
    m.reverse();
    cout << "\nList m After Reverse: "<<endl;
    m.traverse();

    List r;
    r.insertEnd(11, 'k');
    r.insertEnd(22, 'k');
    r.insertEnd(33, 'k');
    cout << "\nRecursive Size: " << r.Recursive_List_Size() << endl;
    cout << "\nDisplay Recursive: "<<endl;
    r.DispalyList();

    List s;
    s.insertEnd(1, 'a');
    s.insertEnd(2, 'a');
    s.insertEnd(3, 'a');
    cout << "Is s sorted? " << (s.Sortedlist() ? "YES" : "NO") << endl;
    s.insertEnd(-5, 'b');
    cout << "Is s sorted after adding -5? " << (s.Sortedlist() ? "YES" : "NO") << endl;


    cout << "\n\nProgram Finished.\n";

	return 0;
}
