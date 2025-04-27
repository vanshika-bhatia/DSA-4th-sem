#include<iostream>
using namespace std;

class CircularLinkedList{
    public:
    int data;
    CircularLinkedList *next;


    CircularLinkedList(int value){
        data = value;
    }
};

CircularLinkedList* InsertAtBegining(CircularLinkedList *head, int data){
    CircularLinkedList *ptr = new CircularLinkedList(data);
    CircularLinkedList *p = head->next;
    while (p->next!= head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
    
}

void Traversal(CircularLinkedList *head){
    CircularLinkedList *ptr = head;
    do{
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }while (ptr!=head);
}


int main(){
    CircularLinkedList *head = new CircularLinkedList(1);
    CircularLinkedList *second = new CircularLinkedList(5);
    CircularLinkedList *third = new CircularLinkedList(10);
    CircularLinkedList *fourth = new CircularLinkedList(15);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    //Linked List before inserting.
    Traversal(head);
    cout<<endl;
    //Linked List after inserting.

    head = InsertAtBegining(head, 20);
    head = InsertAtBegining(head, 25);
    Traversal(head);

    return 0;
}