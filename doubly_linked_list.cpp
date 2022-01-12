#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
// location of the head & tail don't change while addinng nodes to the list.
class List
{
public:
    
    struct Node
    {
        Node* next;
        Node* prev;
        int data;
        Node (int d=0, Node* p= nullptr, Node* n= nullptr)
        {
            data= d;
            next= n;
            prev= p;
    
        }
    };
    
    Node* head;
    Node* tail;
    List();
    void createnodes(int dat);
    void print();
    void addnodes(Node* head1, Node* tail1, int dat1);
    void addnodes2(int val);
    void connectnodes(int data, Node* ptr, Node* tail);
    vector<Node*>Heads; // vector contains the heads
    vector<Node*>Tails;  // vector contains the tails.
};

List::List()
{
    cout<< " address of the head after intilzation" << &head;
    head= new Node;
    Heads.push_back(head);
    tail= new Node;
    Tails.push_back(tail);
    head->next= tail;
    tail->prev= head;
}

void List::addnodes(Node *head1, Node *tail1, int dat1)
{
    Node* newnode = new Node (dat1, head1, tail1);
    tail->prev->next= newnode;
    tail->prev= newnode;
}

void List::createnodes(int dat)
{
    addnodes(head, tail, dat);
}

void List::connectnodes(int data, Node *ptr, Node *tail)
{
    Node* newnode = new Node(data, ptr, tail);
    tail->prev->next= newnode;
    tail->prev= newnode;
}

void List::addnodes2(int val)
{
    Node* head_ptr = Heads[0]->next;
    Node* tail_ptr = Tails[0];
    while( head_ptr!=tail_ptr)
    {
        head_ptr= head_ptr->next;
    }
    connectnodes(val, head_ptr, tail_ptr);
}



void List::print()
{
    Node* ptr;
    for (ptr= head; ptr!=tail; ptr= ptr->next)
    {
        cout<< ptr->data ;
        cout<< "->" ;
    }
}

int main()
{
    List lst;
    lst.createnodes(2);
    lst.createnodes(5);
    lst.createnodes(8);
    lst.createnodes(6);
    lst.addnodes2(10);
    lst.print();
}



