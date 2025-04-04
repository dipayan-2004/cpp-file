#include <iostream>
using namespace std;

struct Node
{
    int data;
    int priority;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *createNode(int d, int p)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

void enque(int d, int p)
{
    struct Node *curr = createNode(d, p);
    if (head == NULL || head->priority > p)
    {
        curr->next = head;
        head = curr;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL || temp->next->priority <= p)
    {
        temp = temp->next;
        curr->next = temp->next;
        temp->next = curr;
    }
    return;
}
void dequeue()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        cout << "empty queue" << endl;
    }

    head = temp->next;
    free(temp);
    return;
}
void display()
{
    if (head == NULL)
    {
        cout << "empty queue\n";
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%5d - %d", temp->data, temp->priority);
        temp = temp->next;
    }
    return;
}
int main(void)
{

    while (1)
    {
        cout << "\nwrite that to do...\n1.display\n2.enqueue\n3.dequeue\n4.exit\n";
        int n;
        cin >> n;
        if (n == 4)
        {
            break;
        }

        switch (n)
        {
        case 1:
        {
            display();
            break;
        }

        case 2:
        {
            int data, priority;
            cout << "write the data and priority\n";
            cin >> data >> priority;
            enque(data, priority);
            cout << "data inserted";
            break;
        }

        case 3:
        {
            dequeue();
            break;
        }

        default:
            cout << "invalid input";
        }
    }

    return 0;
}