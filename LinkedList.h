#ifndef LINKEDLIST_H // if_not_defined
#define LINKEDLIST_H // definition του headerfile

#include<iostream>

using namespace std;

template <class T> // Template του struct ετσι ωστε να μπορουμε να δουλευουμε με καθε τυπο δεδομενων που χρειαζομαστε
struct node //Δημιουργία του κομβου node ο οποιος περιεχει δυο πεδια.
{
	T data; //Πεδιο data που περιχει τα δεδομενα του κομβου
	node<T> *next; //Πεδιο next το οποιο αποτελει δεικτης στην διευθηνση του επομενου κομβου
};

template <class T>
class list // Δηλωση της κλασσης list η οποια θα αποτελεσει την δικη μας εκδοση μιας Singly Linked list
{
		private:
		node<T> *head, *tail; //Δηλωση δυο δεικτων οι οποιοι δειχνουν σε αντικειμενα τυπου node
		public:

		list() // constructor
		{
			head = NULL; // αρχικοποιηση του δεικτη head με NULL ετσι ωστε να αποφυγουμε τιμες "σκουπιδια"
			tail = NULL; // αρχικοποιηση και του δεικτη tail
			cout << "In constructor" << '\n';
		}


		~list()
		{
			node<T>* tempo;
			while(head != NULL)
			{
				tempo = head->next;
				delete head;
				head = tempo;
				cout << "In Destructor" << '\n';
			}
		}
	 														 //Δηλωση μεθοδου createnode η οποια θα δημιουργει εναν καινουργια κομβο της λιστας του
		void createnode(T value)	//οποιου θα δινουμε εμεις την τιμη που θα περιεχει. Και ο καινουργιος κομβος θα προστιθεται
														 //στο τελος της εκαστοτε λιστας
		{
			node<T> *temp = new node<T>;
			temp->data = value; // Δινουμε στο πεδιο data του νεου κομβου την τιμη που εδωσε ο χρηστης ως ορισμα της createnode
			temp->next = NULL;
			if(head == NULL)
			{
				head = temp;
				tail = temp;
				temp = NULL;
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
		}


		void display() //Δηλωση της μεθοδου display η οποια θα εκτυπωνει το πεδιο data όλων των κομβων της λιστας
		{
			node<T> *temp = new node<T>;
			temp = head;
			while(temp != NULL) // Οσο ο δεικτης δεν δειχνει στην γειωση συνεχιζυομε να προσπελαυνουμε κομβους
			{
				cout << temp->data <<" "; // εκτυπωση του πεδιου data των κομβων
				temp = temp->next; // redirecitng τον δεικτη στον επομενο κομβο
			}
			cout << '\n';
		}


		void insert_start(T value) // Δηλωση της συναρτησης insert_start η οποία δημιουργει εναν νεο κομβο
															// στην αρχη της εκαστοτε λιστας
		{
			node<T> *temp = new node<T>;
			temp->data = value;
			temp->next = head;
			head = temp;
		}


	 																					  // Δηλωση της συναρτηση insert_position η οποια δημιουργει
		void insert_position(T pos, int value)	 // εναν νεο κομβο στην εκαστοτε λιστα και τον τοποθετει
																					  //  στην θεση που θα προσδιορισει ο χρηστης
		{
			node<T> *pre = new node<T>;
			node<T> *cur = new node<T>;
			node<T> *temp = new node<T>;
			cur = head;
			for(int i=1; i<pos; i++)
			{
				pre = cur;
				cur = cur->next;
			}
			temp->data = value;
			pre->next = temp;
			temp->next = cur;
		}


		void delete_first() // Δηλωση της συναρτησης delete_first η οποια διαγραφει τον πρωτο κομβο της λιστας
		{
			node<T> *temp = new node<T>;
			temp = head;
			head = head->next;
			delete temp;
		}


		void delete_last() // Δηλωση της συναρτησης delete_last η οποια διαγραφει τον τελευταιο κομβο της λιστας
		{
			node<T> *current = new node<T>;
			node<T> *previous = new node<T>;
			current = head;
			while(current->next != NULL)
			{
				previous = current;
				current = current->next;
			}
			tail = previous;
			previous->next = NULL;
			delete current;
		}


		void delete_position(T pos) // Δηλωση της συναρτησης delete_position η οποια διαγραφει τον κομβο της λιστας
																 // που την θεση του θα δηλωσει ο χρηστης
		{
			node<T> *current = new node<T>;
			node<T> *previous = new node<T>;
			current = head;
			for(int i=1; i<pos; i++)
			{
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
		}
};

#endif // τελος του headerfile
