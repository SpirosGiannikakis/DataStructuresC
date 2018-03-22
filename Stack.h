#ifndef Stack_
#define Stack_

#include<iostream>
using namespace std;


// Δημιουργια του κομβου nodes ο οποιος εχει δυο πεδια
// Ενα για τα δεδομενα (data)
// Και εναν δεικτη ο οποιος δειχνει σε αντικειμενο τυπου nodes
struct nodes
{
    int data;
    nodes *next;
};

// Δημιουργια της κλασσης stack
class stack
{
    //Δημιουργια του δεικτη top ο οποιος θα δειχνει παντοτε στο πρωτο στοιχειο
    // του stack
    nodes *top;
    public:
    stack() // constructor
    {
        top=NULL; // Αρχικοποιηση του δεικτη top με την γειωση
    }
    void push(int value); // Μεθοδος προσθηκης κομβου στο stack
    void pop();  // Μεθοδος διαγραφης κομβου απο το stack
    void show(); // Εμφανιση του stack στο τερματικο περιβαλλον
};

// Υλοποιηση της μεθοδου push(Τ value)
void stack::push(int value) // Η συναρτηση περνει ως ορισμα την τιμη που θελει ο χρηστης να προσθεσει στο stack
{

    nodes *ptr; //Δημιουργια ενος δεικτη που ονομζεται ptr και δειχνει σε τυπο nodes
    ptr=new nodes; // Δεσμευση μνημης για τον δεικτη ptr
    ptr->data=value; // κανουμε extract το πεδιο data απο τον ptr και του δινουμε την τιμη που περνει ως ορισμα η push
    ptr->next=NULL; //Ο δεικτης next δειχνει στην γειωση
    if(top!=NULL) // Εαν το stack δεν ειναι αδειο
    ptr->next=top; // Κανε τον δεικτη next ισο με την τιμη που βρισκεται "πανω πανω" στο stack
    top=ptr;
    cout<<"\nNew item is inserted to the stack";

}

// Υλοποιηση της μεθοδου pop()
void stack::pop()
{
    nodes *temp; //Δηλωση ενος προσωρινου δεικτη temp
    if(top == NULL) // Εαν το stack ειναι αδειο
    {
        cout<<"\nThe stack is empty";
        return;
    }
    temp = top; //Αποθηκευσε την διευθηνση που δειχνει ο top στον temp ετσι ωστε να μην χαθει η διευθηνση
    top = top->next; //Δινουμε στον δεικτη top την διεθυνση του προηγουμενου στοιχειου
    cout<<"\nPOP Operation........\nPoped value is "<<temp->data;
    delete temp; //Αποδεσμευση του δεικτη temp
}

// Εμφανιση του stack
void stack::show()
{
    nodes *ptr1 = top;
    cout<<"\nThe stack is\n";
    while(ptr1 != NULL)
    {
        cout << ptr1->data<<" ->";
        ptr1 = ptr1->next;
    }
    cout << "NULL\n";
}


#endif
