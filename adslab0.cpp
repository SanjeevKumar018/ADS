#include<iostream>
using namespace std;

typedef struct node{
	int data;
    struct node *next;
}*Node;

Node create_node(){
	Node temp;
	temp=(Node)malloc(sizeof(Node));
	return temp;
}

Node insert_rear(Node head,int ele){
	Node p,q;
	p=create_node();
	p->data=ele;
	p->next=NULL;
	if(head==NULL)
		return p;
	else{
		q=head;
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
		return head;
	}
}

Node reverse(Node head,int k){
    Node current = head;  
    Node next = NULL;  
    Node prev = NULL;  
    int count = 0;  

    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }

    if (next != NULL)  
        head->next = reverse(next, k);  

    return prev;  
}

void display(Node head){
	Node p;
	p=head;
	if(head==NULL)
		printf("List is empty\n");
	else{
		printf("Elements: ");
		while(p!=NULL){
			printf("%d ",p->data);
			p=p->next;
		}
	}
	printf("\n");
}

int main(){
    Node head = NULL;
    int n,temp;
    cout<<"Enter no of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>temp;
        head = insert_rear(head,temp);
    }
    int k;
    cout<<"Enter k: ";
    cin>>k;
    cout<<"Before Reversing: ";
    display(head);
    head = reverse(head,k); 
    cout<<"After Reversing: "
    display(head);
    return 0;
}