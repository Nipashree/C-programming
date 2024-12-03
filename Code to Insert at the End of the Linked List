void insertatend()
{
 struct node *NewNode,*temp;
 int item;
 NewNode = (struct node*)malloc(sizeof(struct node));
 if(NewNode == NULL)
 {
 printf("\nOVERFLOW");
 }
 else
 {
 printf("\nEnter value?\n");
 scanf("%d",&item);
 NewNode->data = item;
 if(start == NULL)
 {
 NewNode -> next = NULL;
 start = NewNode;
 printf("\nNode inserted");
 }
 else
 {
 temp = start;
 while (temp -> next != NULL)
 {
 temp = temp -> next;
 }
 temp->next = NewNode;
 NewNode->next = NULL;
 printf("\nNode inserted");
 }
 }
}
