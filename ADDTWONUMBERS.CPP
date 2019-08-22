/* Brute Force solution*/

#include<iostream.h>
#include<conio.h>
#include<math.h>

//Node defination
struct Node{
	int data;
	Node *next;

};

//insert at any point in Linked List as per given by the user
void insertAtAnyPoint(Node **create, int x,int pos){
	//allocation of newnode in heap
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;
	
	// at first position
	if(pos == 1){
		temp->next = *create;
		*create = temp;
		return;
	}
	Node *temp2 = *create;
	
	//loop to reach the node just before the pos given
	for(int i=0;i<pos-2;i++){
		temp2 = temp2->next;
	}
	
	//setting pointer or address
	temp->next=temp2->next;
	temp2->next=temp;
}

//to get final number from the all nodes of linked list
int getData(Node **find){
	Node *temp = *find;
	int n=0, a=0;
	//formation of number
	while(temp != NULL){
		a += (temp->data)*pow(10,n);
		n++;
		temp = temp->next;
	}
	return a;
}

//real function
//here all the numbers from function getData() adds anf then splits and save in new Linkes List (res)
Node* addTwoNumbers(int n1, int n2, Node **res){
	int c=n1+n2, final, n=1;
	while(c > 0){
		final = c%10;
		//inserting at nth position final element
		insertAtAnyPoint(&*res, final, n);
		c = c/10;
		n++;
	}
	return *res;
}

//print the Linked List
void printLL(Node **node){
	Node *temp = *node;
	cout<<"List is ";
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<" \n";
}

//main funciton
int main(){
	clrscr();
	// declaring empty Linkes List
	Node *head1 = NULL, *head2 = NULL, *head3 = NULL;
	//creating Linked List 1
	insertAtAnyPoint(&head1, 2, 1);
	insertAtAnyPoint(&head1, 4, 1);
	insertAtAnyPoint(&head1, 3, 1);
	//Printing....
	printLL(&head1);
	//creating Linked List 2
	insertAtAnyPoint(&head2, 4, 1);
	insertAtAnyPoint(&head2, 6, 1);
	insertAtAnyPoint(&head2, 5, 1);
	//Printing...
	printLL(&head2);
	//calling getData() function in call of addTwoNumbers 
	//saves space complexity
	addTwoNumbers(getData(&head1), getData(&head2), &head3);
	//printing res....
	printLL(&head3);
	getch();
	return 0;
}
