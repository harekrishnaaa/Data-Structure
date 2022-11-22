#include <iostream>
using namespace std;
struct Queue
{
    int front, rear, capacity;
    int *queue;
    Queue(int c)
    {
        front = rear = 0;
        capacity = c;
        queue = new int;
    }
    ~Queue() { delete[] queue; }
    void Enqueue(int data)
    {
        if (capacity == rear)
        {
            printf("\nQueue is full\n");
            return;
        }
        else
        {
            queue[rear] = data;
            rear++;
        }
        return;
    }
    void Dequeue()
    {
        if (front == rear)
        {
            printf("\nQueue is empty\n");
            return;
        }
        else
        {
            for (int i = 0; i < rear - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            rear--;
        }
        return;
    }
    void Display()
    {
        int i;
        if (front == rear)
        {
            printf("\nQueue is Empty\n");
            return;
        }
        for (i = front; i < rear; i++)
        {
            printf(" %d <-- ", queue[i]);
        }
        return;
    }
    void Front()
    {
        if (front == rear)
        {
            printf("\nQueue is Empty\n");
            return;
        }
        printf("\nFront Element is: %d", queue[front]);
        return;
    }
};
int main(void)
{
    Queue q(4);
    q.Display();
    q.Enqueue(10);
    q.Enqueue(30);
    q.Enqueue(50);
    q.Enqueue(70);
    q.Display();
    q.Enqueue(60);
    q.Display();
    q.Dequeue();
    q.Dequeue();
    printf("\n\nafter two node deletion\n\n");
    q.Display();
    q.Front();
    return 0;
}