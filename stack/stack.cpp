#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* head;
void push(int val)
{
    Node* n = new Node();
    n->val = val;
    n->next = nullptr;

    if (head == nullptr) 
    {
        head = n;
    }
    else
    {
        Node* t = head;
        head = n;
        head->next = t;
    }
}

int pop()
{
    if(head == nullptr) return -99999;
    Node* temp = head;
    int val = temp->val;
    head = head->next;
    delete temp;
    return val;
}

Node* q_head = nullptr;
Node* q_tail = nullptr;

void enqueue(int val)
{
    Node* node = new Node();
    node->val = val;
    node->next = nullptr;

    if(q_head == nullptr)
    {
        q_head = node;
        q_tail = q_head;
    }
    else 
    {
        q_tail->next = node;
        q_tail = q_tail->next;
    }
}

int dequeue()
{
    if(q_head == nullptr) return -99999;
    Node* temp = q_head;
    int val = temp->val;
    q_head = q_head->next;
    delete temp;
    return val;
}

int main(void)
{
    stack<int> stack;
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    //cout << stack.top(); stack.pop();
    //cout << stack.top(); stack.pop();
    //cout << stack.top(); stack.pop();
    //cout << stack.top(); stack.pop();
    //cout << stack.top(); stack.pop();
    //cout << stack.top(); stack.pop();
    //cout << stack.top(); stack.pop();

    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    cout << dequeue();
    cout << dequeue();
    cout << dequeue();
    cout << dequeue();
    cout << dequeue();
    cout << dequeue();
    cout << endl;

    queue<int> queue;
    queue.push(0);
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    cout << queue.front() ; queue.pop();
    cout << queue.front() ; queue.pop();
    cout << queue.front() ; queue.pop();
    cout << queue.front() ; queue.pop();
    cout << queue.front() ; queue.pop();
    cout << queue.front() ; queue.pop();
    return 0;
}
