#include <stdio.h> 
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}Node;

Node* createNode(int value){
    Node* new_node_pointer = (Node*)malloc(sizeof(Node));
    new_node_pointer->data = value;
    new_node_pointer->link = NULL;
    return new_node_pointer;
}

Node* insertNode(Node* pointer_to_head,int value){
    Node *new_node_pointer = createNode(value);
    Node *pointer_to_current_element = pointer_to_head;
    if(pointer_to_head == NULL || value < pointer_to_head->data){
        new_node_pointer->link = pointer_to_head;
        return new_node_pointer;
    }
    while(1){
        if(value < (pointer_to_current_element->link->data) || (pointer_to_current_element->link) == NULL){
            break;
        }
        pointer_to_current_element = pointer_to_current_element -> link;
    }
    new_node_pointer->link = pointer_to_current_element->link;
    pointer_to_current_element->link = new_node_pointer;
    return pointer_to_head;
}

Node* deleteNode(Node* head_pointer, int key){
    //this function finds the element which has holds the same value as given in the key, and then removes that element fromt the chain.. and returns the head pointer.
    if(head_pointer == NULL){
        printf("Given list is empty, No node deleted\n");
        return head_pointer;
    }
    if(head_pointer->data == key){
        free(head_pointer);
        return NULL;
    }
    Node* current_element_pointer = head_pointer;
    while(1){
        if(key <= (current_element_pointer->link->data) || current_element_pointer->link == NULL){
            break;
        }
        current_element_pointer = current_element_pointer->link;
    }
    if(current_element_pointer->link == NULL){
        printf("No match found\n");
        return head_pointer;
    }
    if(current_element_pointer->link->data == key){
        Node* temp = current_element_pointer->link;
        current_element_pointer->link = current_element_pointer->link->link;
        free(temp);
        return head_pointer;
    }else{
        printf("No match found\n");
        return head_pointer;
    }

}

void display(Node* pointer_to_head){
    while(pointer_to_head != NULL){
        printf("%d->", pointer_to_head->data);
        pointer_to_head = pointer_to_head->link;
    }
    printf("NULL\n");
}

int main(){
    Node* head_pointer = createNode(10);
    
    head_pointer->link = createNode(20);
    head_pointer->link->link = createNode(30);

    head_pointer = insertNode(head_pointer,15);
    head_pointer = insertNode(head_pointer,25);
    head_pointer = insertNode(head_pointer,5);

    display(head_pointer);
    deleteNode(head_pointer, 15);
    display(head_pointer);
    free(head_pointer);

return 0;
}
