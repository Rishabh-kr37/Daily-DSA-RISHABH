#include <iostream>
using namespace std;

class node
{
public:
        int data;
        node *next;

        // constructor
        node(int data)
        {
                this->data = data;
                this->next = NULL;
        }

        // destructor
        ~node()
        {
                int value = this->data;
                // memory free
                if (this->next != NULL)
                {
                        delete next;
                        this->next = NULL;
                }
                cout << "memory is free for node with data " << value << endl;
        }
};

void insertathead(node *&head, int d)
{
        // new node create

        node *temp = new node(d);
        temp->next = head;
        head = temp;
}

void insertattail(node *&tail, int d)
{
        node *temp = new node(d);
        tail->next = temp;
        tail = tail->next;
}

void print(node *&head)
{
        node *temp = head;
        while (temp != NULL)
        {
                cout << temp->data << " ";
                temp = temp->next;
        }
        cout << endl;
}

void insertatanywhere(node *&tail, node *&head, int position, int d)
{
        // insert at start
        if (position == 1)
        {
                insertathead(head, d);
                return;
        }
        node *temp = head;
        int cnt = 1;

        while (cnt < position - 1)
        {
                temp = temp->next;
                cnt++;
        }

        // insert at last end
        if (temp->next == NULL)
        {
                insertattail(tail, d);
                return;
        }

        // creating a node for d
        node *nodetoinsert = new node(d);

        nodetoinsert->next = temp->next;
        temp->next = nodetoinsert;
}

void deleteNode(int position, node *&head)
{

        // deleteing first or start node
        if (position == 1)
        {
                node *temp = head;
                head = head->next;
                // memory free start node
                temp->next = NULL;

                delete temp;
        }
        else
        {
                // deleteing any middle node and last node
                node *curr = head;
                node *prev = NULL;
                int cnt = 1;
                while (cnt < position)
                {
                        prev = curr;
                        curr = curr->next;
                        cnt++;
                }
                prev->next = curr->next;
                curr->next = NULL;

                delete curr;
        }
}

int main()
{
        // create a new node
        node *node1 = new node(10);
        cout << node1->data << endl;
        cout << node1->next << endl;

        // head pointed to node1
        node *head = node1;
        node *tail = node1;
        print(head);

        insertattail(tail, 12);
        print(head);

        insertattail(tail, 15);
        print(head);

        insertatanywhere(tail, head, 4, 55);
        print(head);

        cout << "head " << head->data << endl;
        cout << "tail " << tail->data << endl;

        deleteNode(4, head);
        print(head);

        return 0;
}