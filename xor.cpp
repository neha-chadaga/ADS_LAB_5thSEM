#include <iostream>
using namespace std;

class Node
{

public :
    int data;
    Node* xnode;

};

// It returns Xored value of the node addresses

Node* Xor(Node* x, Node* y)

{

    return reinterpret_cast<Node*>(

               reinterpret_cast<uintptr_t>(x)

               ^
               reinterpret_cast<uintptr_t>(y));

}

Node* insert(Node* head_ref, int data)

{

// Allocate memory for new node

    Node* new_node = new Node();

    new_node -> data = data;

    new_node -> xnode = head_ref;

    if (head_ref != NULL)
    {

        head_ref -> xnode = Xor(new_node, head_ref -> xnode);

    }

//head_ref = new_node;
    return new_node;

}

void printList(Node* head)

{

    Node* curr = head;

    Node* prev = NULL;

    Node* next;

    cout << "The nodes of Linked List are: \n";

// Till condition holds true

    while (curr != NULL)
    {

// print current node

        cout << curr -> data << " ";

        next = Xor(prev, curr -> xnode);


        prev = curr;

        curr = next;

    }

}

Node* insert_rear(Node* head,int data)

{
    Node* new_node = new Node();

    new_node -> data = data;
    new_node -> xnode = head;
    if (head==NULL)
    {
        return new_node;
    }

    Node* curr = head;

    Node* prev = NULL;

    Node* next;

// Till condition holds true

    while (curr!=NULL)
    {

// print current node


        next = Xor(prev, curr -> xnode);

        if (next==NULL)
        {
            curr->xnode=Xor(curr->xnode,new_node);
            new_node->xnode=Xor(curr,NULL);
            break;
        }

        prev = curr;
        curr = next;

    }
    return head;

}

int main()

{

    Node* head = NULL;

    head=insert_rear(head, 10);

    head=insert_rear(head, 100);

    head=insert_rear(head, 1000);

    head=insert_rear(head, 10000);

// Printing the created list

    printList(head);

    return (0);

}
