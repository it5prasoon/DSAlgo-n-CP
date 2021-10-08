#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void insertNode(Node** head, int x)
{
	Node* ptr = new Node;
	ptr->data = x;
	ptr->next = NULL;
	if (*head == NULL) {
		*head = ptr;
	}
	else {
		Node* temp;
		temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = ptr;
	}
}

void display(Node** head)
{
	Node* temp;
	temp = *head;
	if (temp == NULL) {
		cout << "NULL \n";
	}
	else {
		while (temp != NULL) {
			cout << temp->data;
			if (temp->next != NULL)
				cout << "->";
			temp = temp->next;
		}
	}
}

void MergeLinkedlist(Node** head1, Node** head2)
{
	Node* ptr;
	ptr = *head1;
   
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
    ptr->next = *head2;
}

void segregateEvenOdd(Node **head_ref)
{
	Node *end = *head_ref;
	Node *prev = NULL;
	Node *curr = *head_ref;

	while (end->next != NULL)
		end = end->next;

	Node *new_end = end;

	while (curr->data % 2 != 0 && curr != end)
	{
		new_end->next = curr;
		curr = curr->next;
		new_end->next->next = NULL;
		new_end = new_end->next;
	}

	if (curr->data%2 == 0)
	{

		*head_ref = curr;
		while (curr != end)
		{
			if ( (curr->data) % 2 == 0 )
			{
				prev = curr;
				curr = curr->next;
			}
			else
			{
				prev->next = curr->next;

				curr->next = NULL;
				new_end->next = curr;

				new_end = curr;
				curr = prev->next;
			}
		}
	}

	else prev = curr;

	if (new_end != end && (end->data) % 2 != 0)
	{
		prev->next = end->next;
		end->next = NULL;
		new_end->next = end;
	}
	return;
}




int main()
{
	Node* head1 = NULL;
    insertNode(&head1, 2);
	insertNode(&head1, 3);
	insertNode(&head1, 5);
	insertNode(&head1, 1);

	Node* head2 = NULL;
	insertNode(&head2, 6);
	insertNode(&head2, 2);
	insertNode(&head2, 4);
	insertNode(&head2, 9);

	MergeLinkedlist(&head1, &head2);
    segregateEvenOdd(&head1);
    display(&head1);

	return 0;
}
