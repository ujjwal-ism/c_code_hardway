// A linked list is a sequence of items arranged one after another 
// Each item in a list is linked to next item via a link
// Each item is placed together with the link to the next item, resulting in a simple component called a node.

// Declaring a Class for Node

struct Node{
	typedef double Item;
	Item data; // Data stored in node
	Node *link; // Pointer to next node
};

Node *head_ptr;
Node *tail_ptr;

// Computing the length of a linked list

size_t list_length(Node *head_ptr){
	Node *cursor;
	int answer=0;

	for(cursor=head_ptr;cursor !=NULL;cursor=cursor->link)
		answer++;

	return answer;
}

// Inserting a Node at List Head

void list_head_insert(Node *head_ptr,const Node::Item& entry){
	//Precondition: head_ptr is a head pointer to a linked list
	//Postcondition: new node is added to front of list containing entry
	//head_ptr is set to point at new node

	Node *insert_ptr;

	insert_ptr=new Node;
	insert_ptr->data=entry;
	insert_ptr->link=head_ptr;
	head_ptr=insert_ptr;
}

// Inserting a Node "not" at List Head

void list_insert(Node *previous_ptr,const Node::Item& entry){
	// Precondition: previous_ptr is a pointer to a node in a valid linked list
    // Postcondition: new node is added after the node pointed to by previous pointer

    Node *insert_ptr;

    insert_ptr=new Node;
    insert_ptr->data=entry;
    insert_ptr->link=previous_ptr->link;
    previous_ptr->link=insert_ptr;
}

// Searching list for Item

Node* list_search(Node *head_ptr,const Node::Item& target){
	// Precondition: head_ptr is a head pointer to a linked list
	// Postcondition: return value is pointer to first node containing specified target.Returns NULL if nomatching node is found

	Node *cursor;

	for(cursor=head_ptr;cursor !=NULL;cursor=cursor->link)
		if(target==cursor->data)
			return cursor;

		return NULL;
}

// Locating n th Node in the List

Node* list_locate(Node* head_ptr,size_t position){
	// Precondition: head_ptr is a head pointer to a linked list
	// Postcondition: return value is pointer to node at specified position
	// first node in list has position=0

	Node *cursor;
	size_t i;

	cursor=head_ptr;
	for(i=0;(i<position)&&(cursor != NULL);++i)
		cursor=cursor->link;

	return cursor;
}

// Removing a Node at List Head

void list_head_remove(Node *head_ptr){
	// Precondition: head_ptr is a head pointer to a linked list
	// Postcondition: first node is removed from front of list, and
	// head_ptr is set to point at head_ptr->link. Removed node is deleted

	Node *remove_ptr;
	if(head_ptr==NULL)
		return;
	remove_ptr=head_ptr;
	head_ptr=head_ptr->link;
	delete remove_ptr;
}

// Removing a Node not at List Head

void list_remove(Node *previous_ptr){
	// Precondition: previous_ptr is a pointer to node in a linked list
	// Postcondition: node is removed from front of list, and
	// removed node is deleted

	Node *remove_ptr;

	remove_ptr=previous_ptr->link;
	previous_ptr->link=remove_ptr->link;
	delete remove_ptr;
}