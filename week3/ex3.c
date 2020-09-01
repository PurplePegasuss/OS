#include <stdio.h>

struct node{
    int data;
    struct node *link ;
};

struct node *curr_node;

struct node *head;

void print_list(){
    struct node *nextToPrint = head; // using this node to cycle through the list
    while (nextToPrint != NULL){
        printf("%d ",nextToPrint->data);
        nextToPrint = nextToPrint->link; //going through all nodes
    }
    printf("\n");
};
void create_head(int value){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = value;
    head = newNode;
};
void insert_node(int findValue,int insertedValue){
    struct node *current = head; // using this node to cycle through the list
    while (current != NULL){
        if (current->data == findValue){
            struct node * newNode = (struct node*) malloc(sizeof(struct node)); //creating new node with inserted value

            //inserting a new node between current and next nodes 
            struct node *temp = current->link; 
            current->link = newNode;
            newNode->link = temp;

            newNode->data = insertedValue; //assigning data
        }
        current = current->link;//going through nodes
    }
}

void delete_node(int deleteValue){
    struct node *current = head; 
    struct node* previous = NULL; // to delete a node we need to connect previous and next node
    while (current != NULL){
        if (current->data == deleteValue){
            if (current == head){ // observing the case then node to be deleted is the head of the list 
                head = head->link;
            }else {
                previous->link = current->link;
            } 
        };
        previous = current;
        current = current->link;
    }
}

int main(){
    create_head(3); // adding node with value 3
    print_list(); // printing results
    insert_node(3,0); // adding node with value 0 after the node with value 3
    print_list();
    insert_node(0,4);
    print_list();
    delete_node(3); // deleting node with value 
    print_list();
    delete_node(4);
    print_list();
}