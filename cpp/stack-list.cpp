#include <iostream>
using namespace std;

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} stack;
stack *top = NULL;
stack *createNode(int data)
{
    stack *curr = (stack *)malloc(sizeof(stack));
    curr->data = data;
    curr->prev = NULL;
    curr->next = NULL;
    return curr;
}
void push(int data)
{
    if (top == NULL)
    {
        top = createNode(data);
        return;
    }
    stack *curr = createNode(data);
    top->next = curr;
    curr->prev = top;
    top = curr;
}
void pop()
{
    if (top == NULL)
    {
        cout << "empty stack";
        return;
    }
    stack *temp = top;
    top = top->prev;
    top->next = NULL;
    free(temp);
    return;
}
int peak()
{
    return top->data;
}
void display()
{
    if (top == NULL)
    {
        cout << "empty stack";
        return;
    }

    stack *temp = top;
    while (temp != NULL)
    {
        printf("%3d", temp->data);
        temp = temp->prev;
    }
}
int main()
{

    while (1)
    {
        cout << "\nwrite that to do...\n1.display\n2.push\n3.pop\n4.peak\n5.exit\n";
        int n;
        cin >> n;
        if (n == 5)
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
            int data;
            cout << "write the data\n";
            cin >> data;
            push(data);
            cout << "data inserted";
            break;
        }

        case 3:
        {
            pop();
            break;
        }
        case 4:
        {
            cout << peak();
            break;
        }

        default:
            cout << "invalid input";
        }
    }

    return 0;
}