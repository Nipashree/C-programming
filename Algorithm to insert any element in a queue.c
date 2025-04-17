void insert (int queue[], int max, int front, int rear, int item)
 {
 if (rear + 1 == max)
 {
 printf("overflow");
 }
 else
 {
 if(front == -1 && rear == -1)
 {
 front = 0;
 rear = 0;
 }
 else
 {
 rear = rear + 1;
 }
 queue[rear]=item;
 }
 }
