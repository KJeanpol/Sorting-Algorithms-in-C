#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

//////Data Structure//// DOUBLE LINKED LIST
typedef struct node* NODE;

typedef struct node{
    int valor;
    NODE siguiente;
    NODE anterior;
};
///////////////////////////////////////////
////////lista///////////////////////////////////////////
typedef struct
{
    int tamano;
    NODE cabeza;
    NODE cola;
}List;


NODE CreateNode(int val)
{
    NODE n;
    n = (NODE)malloc(sizeof(struct node));
    n->valor=val;
    n->anterior = NULL;
    n->siguiente=NULL;
    return n;
}

List CreateList()
{
    List l;
    l.tamano = 0;
    l.cabeza = NULL;
    l.cola = NULL;
    return l;
}
///////////////////////////////////////////////////////////////////////
List Insertar(List L, int n)  // This functions inserts a node in the DLL at the cabeza
{
    NODE v;
    v = CreateNode(n);
    if(L.cabeza == NULL)
    {
        L.cabeza = v;
        L.cola = v;
    }
    else
    {
        v->siguiente = L.cabeza;
        L.cabeza->anterior = v;
        L.cabeza = v;
    }
    L.tamano++;
    return L;
}

void PrintList(List L)
{
    NODE curr = L.cabeza;
    int i=0;
    while(curr!=NULL)
    {
        printf("%d ",curr->valor);
        curr = curr->siguiente;
    }
    printf("\n");
}

//////////Quick Sort Code////////////

NODE dividirLista(NODE *s, NODE *en)
{
    if(*s==*en) return *s;

    int tempi;
    NODE small = *s ,piv = *en,curr = *s,temp;

    while(curr!=NULL && curr!=*en)
    {
        if(curr->valor < piv->valor)
        {
            tempi = small->valor;
            small->valor = curr->valor;
            curr->valor = tempi;
            small = small->siguiente;
        }
        curr = curr->siguiente;

    }
    tempi = piv->valor;
    piv->valor = small->valor;
    small->valor = tempi;
    return small;
}

void quicksort(List *L, NODE *s, NODE *en)
{
    NODE p;
    p = dividirLista(s, en);
    if(*s!=p)
        quicksort(L,s,&(p->anterior));
    if(p!=*en)
        quicksort(L,&(p->siguiente),en);
}
//////////////QUICK SORT PARA PRUEBAS/////////////////////////////////////////////////////
void QuickSort(int q){
    int i,r,n;
    int aux = q+1;
    FILE *fp;
    List L = CreateList();
    printf("QUICKSORT:\n");
    ///MEJOR DE LOS CASOS///
    for(i=0;i<q;i++)
    {
        L = Insertar(L, i);
    }
    printf("Mejor de los casos para:"); printf("%d\n",q);
    printf("Con lista ordenada\n");

    clock_t inicio2 = clock();
    quicksort(&L,&(L.cabeza),&(L.cola));
    int final2 = (clock()-inicio2)*1000/CLOCKS_PER_SEC;

//    printf("Lista ordenada:\n");
//    PrintList(L);
    printf("Tiempo:"); printf("%d",final2);printf("ms\n");


    ///CASO PROMEDIO///////
    for(i=0;i<q;i++)
    {
        L = Insertar(L, rand() % q);
    }
    printf("Caso promedio para:"); printf("%d\n",q);
    printf("Con lista random()\n");
//    printf("Lista sin ordenar:\n");
//    PrintList(L);

    clock_t inicio = clock();
    quicksort(&L,&(L.cabeza),&(L.cola));
    int final = (clock()-inicio)*1000/CLOCKS_PER_SEC;

//    printf("Lista ordenada:\n");
//    PrintList(L);
    printf("Tiempo:"); printf("%d",final);printf("ms\n");



    ///PEOR DE LOS CASOS///
    for(i=q;i>0;i--)
    {
        L = Insertar(L, i);
    }
    clock_t inicio1 = clock();
    quicksort(&L,&(L.cabeza),&(L.cola));
    int final1= (clock()-inicio)*1000/CLOCKS_PER_SEC;
/*Passing the cabeza and cola pointers of DLL unlike array where we pass starting and end index of the array */
    printf("Peor de los casos para:"); printf("%d\n",q);
    printf("Con lista ordenada al inverso\n");

    printf("Tiempo:"); printf("%d",final1);printf("ms\n");printf("\n");
    //PrintList(L);

}

///////////////////////////////INSERTION//////////////////////////////////////////////////////////////////
// Node of a doubly linked list
struct Node {
    int data;
    struct Node* prev, *next;
};

// function to create and return a new node
// of a doubly linked list
struct node* getNode(int valor)
{
    // allocate node
    struct node* newNode =
            (struct node*)malloc(sizeof(struct node));


    newNode->valor = valor;
    newNode->anterior = newNode->siguiente = NULL;
    return newNode;
}


void sortedInsert(struct node** head_ref, struct node* newNode)
{
    struct node* current;

    if (*head_ref == NULL)
        *head_ref = newNode;

    else if ((*head_ref)->valor >= newNode->valor) {
        newNode->siguiente = *head_ref;
        newNode->siguiente->anterior = newNode;
        *head_ref = newNode;
    }

    else {
        current = *head_ref;

        while (current->siguiente != NULL &&
               current->siguiente->valor < newNode->valor)
            current = current->siguiente;

        newNode->siguiente = current->siguiente;

        if (current->siguiente != NULL)
            newNode->siguiente->anterior = newNode;

        current->siguiente = newNode;
        newNode->anterior = current;
    }
}


void insertionSort(struct node** head_ref)
{
    struct node* sorted = NULL;

    struct node* current = *head_ref;
    while (current != NULL) {

        struct node* next = current->siguiente;

        current->anterior = current->siguiente = NULL;

        sortedInsert(&sorted, current);

        current = next;
    }

    *head_ref = sorted;
}

// function to print the doubly linked list
void printList(struct node* head)
{
    while (head != NULL) {
        printf("%d ",head->valor);
        head = head->siguiente;
    }
}

// function to insert a node at the beginning of
// the doubly linked list
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*)malloc(sizeof(struct node));

    /* put in the valor  */
    new_node->valor = new_data;

    /* Make siguiente of new node as head and previous as NULL */
    new_node->siguiente = (*head_ref);
    new_node->anterior = NULL;

    /* change anterior of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->anterior = new_node;

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
//////FUNCION INSERTION SORT PARA PUREBAS///////////////
void InsertionSort(int q){

    int i,r,n;
    int aux = q+1;
    struct node* head = NULL;
    printf("INSERTION SORT:\n");
    ///MEJOR DE LOS CASOS///
    for(i=0;i<q;i++)
    {
        push(&head, i);
    }
    printf("Mejor de los casos para:"); printf("%d\n",q);

    printf("Con lista ordenada\n");

    clock_t inicio2 = clock();
    insertionSort(&head);
    int final2 = (clock()-inicio2)*1000/CLOCKS_PER_SEC;

//    printf("Lista ordenada:\n");
    //printList(head);
    printf("Tiempo:"); printf("%d",final2);printf("ms\n");


    ///CASO PROMEDIO///////
    for(i=0;i<q;i++)
    {
        push(&head, rand() % q);
    }
    printf("Caso promedio para:"); printf("%d\n",q);

    printf("Con lista random()\n");
//    printf("Lista sin ordenar:\n");
//    PrintList(L);

    clock_t inicio = clock();
    insertionSort(&head);
    int final = (clock()-inicio)*1000/CLOCKS_PER_SEC;

//    printf("Lista ordenada:\n");
//    PrintList(L);
    printf("Tiempo:"); printf("%d",final);printf("ms\n");



    ///PEOR DE LOS CASOS///
    for(i=q;i>0;i--)
    {
        push(&head, i);
    }
    clock_t inicio1 = clock();
    insertionSort(&head);
    int final1= (clock()-inicio)*1000/CLOCKS_PER_SEC;
/*Passing the cabeza and cola pointers of DLL unlike array where we pass starting and end index of the array */
    printf("Peor de los casos para:"); printf("%d\n",q);

    printf("Con lista ordenada al inverso\n");

    printf("Tiempo:"); printf("%d",final1);printf("ms\n");printf("\n");
    //PrintList(L);


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////MERGE SORT///////////////////////////////////////////////////////////////////

struct node *split(struct node *head);

// Function to merge two linked lists
struct node *merge(struct node *first, struct node *second)
{
    // If first linked list is empty
    if (!first)
        return second;

    // If second linked list is empty
    if (!second)
        return first;

    // Pick the smaller value
    if (first->valor < second->valor)
    {
        first->siguiente = merge(first->siguiente,second);
        first->siguiente->anterior = first;
        first->anterior = NULL;
        return first;
    }
    else
    {
        second->siguiente = merge(first,second->siguiente);
        second->siguiente->anterior = second;
        second->anterior = NULL;
        return second;
    }
}

// Function to do merge sort
struct node *mergeSort(struct node *head) {
    if (!head || !head->siguiente)
        return head;
    struct node *second = split(head);

    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);

    // Merge the two sorted halves
    return merge(head, second);
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
struct node *split(struct node *head)
{
    struct node *fast = head,*slow = head;
    while (fast->siguiente && fast->siguiente->siguiente)
    {
        fast = fast->siguiente->siguiente;
        slow = slow->siguiente;
    }
    struct node *temp = slow->siguiente;
    slow->siguiente = NULL;
    return temp;
}
////FUNCION MERGE SORT PARA PRUEBAS//////////////
 void MergeSort(int q){

    int i,r,n;
    int aux = q+1;
    struct node* head = NULL;
    printf("MERGE SORT:\n");
    ///MEJOR DE LOS CASOS///
    for(i=0;i<q;i++)
    {
        push(&head, i);
    }
    printf("Mejor de los casos para:"); printf("%d\n",q);

    printf("Con lista ordenada\n");

    clock_t inicio2 = clock();
    mergeSort(head);
    int final2 = (clock()-inicio2)*1000/CLOCKS_PER_SEC;

//    printf("Lista ordenada:\n");
    //printList(head);
    printf("Tiempo:"); printf("%d",final2);printf("ms\n");


    ///CASO PROMEDIO///////
    for(i=0;i<q;i++)
    {
        push(&head, rand() % q);
    }
    printf("Caso promedio para:"); printf("%d\n",q);

    printf("Con lista random()\n");
//    printf("Lista sin ordenar:\n");
//    PrintList(L);

    clock_t inicio = clock();
    mergeSort(head);
    int final = (clock()-inicio)*1000/CLOCKS_PER_SEC;

    printf("Lista ordenada:\n");
//    PrintList(L);
    printf("Tiempo:"); printf("%d",final);printf("ms\n");



    ///PEOR DE LOS CASOS///
    for(i=q;i>0;i--)
    {
        push(&head, i);
    }
    clock_t inicio1 = clock();
    mergeSort(head);
    int final1= (clock()-inicio)*1000/CLOCKS_PER_SEC;
/*Passing the cabeza and cola pointers of DLL unlike array where we pass starting and end index of the array */
    printf("Peor de los casos para:"); printf("%d\n",q);

    printf("Con lista ordenada al inverso\n");
    printf("Tiempo:"); printf("%d",final1);printf("ms\n");printf("\n");
    //PrintList(L);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////
//////////////////////////////// SELECT SORT/////////////////////////////////////////////////////////////////////////

// function to swap nodes 'currX' and 'currY' in a
// Double linked list without swapping valor
void swapNodes(struct node** head_ref, struct node* currX,
               struct node* currY, struct node* prevY)
{
    // make 'currY' as new head
    *head_ref = currY;

    // adjust links
    prevY->siguiente = currX;

    // Swap siguiente pointers
    struct node* temp = currY->siguiente;
    currY->siguiente = currX->siguiente;
    currX->siguiente = temp;
}

struct node* recurSelectionSort(struct node* head)
{
    // if there is only a single node
    if (head->siguiente == NULL)
        return head;

    // 'min' - pointer to store the node having
    // minimum valor value
    struct node* min = head;

    // 'beforeMin' - pointer to store node previous
    // to 'min' node
    struct node* beforeMin = NULL;
    struct node* ptr;

    // traverse the list till the last node
    for (ptr = head; ptr->siguiente != NULL; ptr = ptr->siguiente) {

        // if true, then update 'min' and 'beforeMin'
        if (ptr->siguiente->valor < min->valor) {
            min = ptr->siguiente;
            beforeMin = ptr;
        }
    }

    // if 'min' and 'head' are not same,
    // swap the head node with the 'min' node
    if (min != head)
        swapNodes(&head, head, min, beforeMin);

    // recursively sort the remaining list
    head->siguiente = recurSelectionSort(head->siguiente);

    return head;
}

void sort(struct node** head_ref)
{
    // if list is empty
    if ((*head_ref) == NULL)
        return;

    // sort the list using recursive selection
    // sort technique
    *head_ref = recurSelectionSort(*head_ref);
}
//////////////////// SELECT SORT PARA PRUEBAS///////////////////////
void SelectSort(int q){

    int i,r,n;
    int aux = q+1;
    struct node* head = NULL;
    printf("SELECT SORT:\n");
    ///MEJOR DE LOS CASOS///
    for(i=0;i<q;i++)
    {
        push(&head, i);
    }
    printf("Mejor de los casos para:"); printf("%d\n",q);

    printf("Con lista ordenada\n");

    clock_t inicio2 = clock();
    sort(&head);
    int final2 = (clock()-inicio2)*1000/CLOCKS_PER_SEC;

//    printf("Lista ordenada:\n");
    //printList(head);
    printf("Tiempo:"); printf("%d",final2);printf("ms\n");


    ///CASO PROMEDIO///////
    for(i=0;i<q;i++)
    {
        push(&head, rand() % q);
    }
    printf("Caso promedio para:"); printf("%d\n",q);

    printf("Con lista random()\n");
//    printf("Lista sin ordenar:\n");
//    PrintList(L);

    clock_t inicio = clock();
    sort(&head);
    int final = (clock()-inicio)*1000/CLOCKS_PER_SEC;

//    printf("Lista ordenada:\n");
//    PrintList(L);
    printf("Tiempo:"); printf("%d",final);printf("ms\n");



    ///PEOR DE LOS CASOS///
    for(i=q;i>0;i--)
    {
        push(&head, i);
    }
    clock_t inicio1 = clock();
    sort(&head);
    int final1= (clock()-inicio)*1000/CLOCKS_PER_SEC;
/*Passing the cabeza and cola pointers of DLL unlike array where we pass starting and end index of the array */
    printf("Peor de los casos para:"); printf("%d\n",q);

    printf("Con lista ordenada al inverso\n");
    printf("Tiempo:"); printf("%d",final1);printf("ms\n");printf("\n");
    //PrintList(L);

}

/////////////////////////////BUBBLE SORT///////////////////////////////////////////
/////////////////////

void bubblesort(struct node *head){
    struct node *i,*j;
    int temp;
    for(i=head;i->siguiente != NULL; i=i->siguiente){
        for(j=i->siguiente;j !=NULL; j=j->siguiente){
            if(i->valor > j->valor){
                temp=i->valor;
                i->valor=j->valor;
                j->valor = temp;
            }
        }
    }

}

//////////////  BUBLE SORT PARA PRUEBAS////////////////////

void BubbleSort(int q){

    int i,r,n;
    int aux = q+1;
    struct node* head = NULL;
    printf("BUBBLE SORT:\n");
    ///MEJOR DE LOS CASOS///
    for(i=0;i<q;i++)
    {
        push(&head, i);
    }
    printf("Mejor de los casos para:"); printf("%d\n",q);

    printf("Con lista ordenada\n");

    clock_t inicio2 = clock();
    bubblesort(head);
    int final2 = (clock()-inicio2)*1000/CLOCKS_PER_SEC;

//    printf("Lista ordenada:\n");
    //printList(head);
    printf("Tiempo:"); printf("%d",final2);printf("ms\n");


    ///CASO PROMEDIO///////
    for(i=0;i<q;i++)
    {
        push(&head, rand() % q);
    }
    printf("Caso promedio para:"); printf("%d\n",q);

    printf("Con lista random()\n");
//    printf("Lista sin ordenar:\n");
//    PrintList(L);

    clock_t inicio = clock();
    bubblesort(head);
    int final = (clock()-inicio)*1000/CLOCKS_PER_SEC;

//    printf("Lista ordenada:\n");
//    PrintList(L);
    printf("Tiempo:"); printf("%d",final);printf("ms\n");



    ///PEOR DE LOS CASOS///
    for(i=q;i>0;i--)
    {
        push(&head, i);
    }
    clock_t inicio1 = clock();
    bubblesort(head);
    int final1= (clock()-inicio)*1000/CLOCKS_PER_SEC;
/*Passing the cabeza and cola pointers of DLL unlike array where we pass starting and end index of the array */
    printf("Peor de los casos para:"); printf("%d\n",q);

    printf("Con lista ordenada al inverso\n");
    printf("Tiempo:"); printf("%d",final1);printf("ms\n");printf("\n");
    //PrintList(L);

}




///////////Main or Driver Function/////////

int main(int argc, char *argv[])
{
    int limit;
    limit=10000;
    while(limit<100000){
        if(limit>=40000){
            QuickSort(limit);
            InsertionSort(limit);
            MergeSort(limit);
            BubbleSort(limit);
            limit = limit+10000;

        }
        else{
            QuickSort(limit);
            InsertionSort(limit);
            MergeSort(limit);
            SelectSort(limit);
            BubbleSort(limit);
            limit = limit+10000;

        }



    }






}