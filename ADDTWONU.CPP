#include<iostream.h>
#include<conio.h>
#include<math.h>


struct Node{
	int data;
	Node *next;

};

void insertAtAnyPoint(Node **create, int x,int pos){
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if(pos == 1){
		temp->next = *create;
		*create = temp;
		return;
	}
	Node *temp2 = *create;
	for(int i=0;i<pos-2;i++){
		temp2 = temp2->next;
	}
	temp->next=temp2->next;
	temp2->next=temp;
}

int getData(Node **find){
	Node *temp = *find;
	int n=0, a=0;
	while(temp != NULL){
		a += (temp->data)*pow(10,n);
		n++;
		temp = temp->next;
	}
	return a;
}
Node* addTwoNumbers(int n1, int n2, Node **res){
	int c=n1+n2, final, n=1;
	while(c > 0){
		final = c%10;
		insertAtAnyPoint(&*res, final, n);
		c = c/10;
		n++;
	}
	return *res;
}

void printLL(Node **node){
	Node *temp = *node;
	cout<<"List is ";
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<" \n";
}


int main(){
	clrscr();
	Node *head1 = NULL, *head2 = NULL, *head3 = NULL;
	head1 = NULL;
	head2 = NULL;
	head3 = NULL;
	insertAtAnyPoint(&head1, 2, 1);
	insertAtAnyPoint(&head1, 4, 1);
	insertAtAnyPoint(&head1, 3, 1);
	printLL(&head1);
	insertAtAnyPoint(&head2, 4, 1);
	insertAtAnyPoint(&head2, 6, 1);
	insertAtAnyPoint(&head2, 5, 1);
	printLL(&head2);
	addTwoNumbers(getData(&head1), getData(&head2), &head3);
	printLL(&head3);
	getch();
	return 0;
}
