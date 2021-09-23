/* design linked list using c
Date : 23-09-2021
Author Udhayamoorthi

typedef struct {
    int length;
    int val;
    struct MyLinkedList* next;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->val=-1;
    obj->next=NULL;
    obj->length=-1;
    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(obj->length<index||index<-1){
        return -1;
    }
    obj=obj->next;
    int i=0;
    while(i!=index){
        obj=obj->next;
        i++;
    }
    return obj->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    obj->length++;
    MyLinkedList* p=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->val=val;
    p->next=obj->next;
    obj->next=p;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    obj->length++;
    MyLinkedList* p=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->val=val;
    p->next=NULL;
    while(obj->next!=NULL){
        obj=obj->next;
    }
    obj->next=p;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(obj->length+1<index||index<-1){
        return;
    }
    obj->length++;
    int i=0;
    while(i!=index){
        obj=obj->next;
        i++;
    }
    MyLinkedList* p=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    p->val=val;
    p->next=obj->next;
    obj->next=p;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(obj->length<index||index<-1){
        return;
    }
    obj->length--;
    int i=0;
    while(i!=index){
        obj=obj->next;
        i++;
    }
    MyLinkedList* p=obj->next;
    obj->next=p->next;
    free(p);
}

void myLinkedListFree(MyLinkedList* obj) {
    while(obj!=NULL){
        MyLinkedList* p=obj;
        obj=obj->next;
        free(p);
    }
}
