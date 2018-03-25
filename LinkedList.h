#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <limits>


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

		list() // Constructor
		{
			head = nullptr; // αρχικοποιηση του δεικτη head με NULL ετσι ωστε να αποφυγουμε τιμες "σκουπιδια"
			tail = nullptr; // αρχικοποιηση και του δεικτη tail
			cout << "Constructor Called" << '\n';
		}


		~list() // Destructor
		{
			int index = 1;
			node<T>* tempo;
			while(head != nullptr)
			{
				tempo = head->next;
				delete head;
				head = tempo;
				cout << "Destructor Called "<< "Destroying node number "<< index << '\n';
				index++;
			}
		}
	 														 //Δηλωση μεθοδου createnode η οποια θα δημιουργει εναν καινουργια κομβο της λιστας του
		void createnode(T value)	//οποιου θα δινουμε εμεις την τιμη που θα περιεχει. Και ο καινουργιος κομβος θα προστιθεται
														 //στο τελος της εκαστοτε λιστας
		{
			node<T> *temp = new node<T>;
			temp->data = value; // Δινουμε στο πεδιο data του νεου κομβου την τιμη που εδωσε ο χρηστης ως ορισμα της createnode
			temp->next = nullptr;
			if(head == nullptr)
			{
				head = temp;
				tail = temp;
				temp = nullptr;
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
			while(temp != nullptr) // Οσο ο δεικτης δεν δειχνει στην γειωση συνεχιζυομε να προσπελαυνουμε κομβους
			{
				cout << temp->data <<" "; // εκτυπωση του πεδιου data των κομβων
				temp = temp->next; // redirecitng του δεικτη στον επομενο κομβο
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
		void insert_position(int pos, T value)	// εναν νεο κομβο στην εκαστοτε λιστα και τον τοποθετει
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
			while(current->next != nullptr)
			{
				previous = current;
				current = current->next;
			}
			tail = previous;
			previous->next = nullptr;
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

		int length() const{

			node<T> *current = head;
			int len = 0;
			while(current){
				len++;
				current = current->next;
			}
			cout << "The lists length is: " << len << '\n';
			return len;
		}



		T find(int k)
		{
			node<T> *current = new node<T>;

			if(k < 1){
				cout << "Invalid Index point" << '\n';
				throw std::out_of_range ("Invalid Index point");
			}
			if(k > length()){
				cout << "Index Out of Bounds" << '\n';
				throw std::out_of_range ("Invalid Index point");
			}
			current = head;
			int index = 1;
			while (index < k && current){
				current = current->next;
				index++;
			}
			if(current){
				cout << "In index point: " << k << " || " << " The value is: "<< current->data << '\n';
				return current->data;
			}
		}

		int search(const T& x) const{

			node<T> *current = new node<T>;
			current = head;
			int index = 1;
			while (current && current->data != x){
				current = current->next;
				index++;
			}
			if(current){
				cout << "The value: " << x << " || " << "Was found in index point: " << index << '\n';
				return index;
			}
			return 0;
		}

		bool isempty(){

			if(head == nullptr){
				cout << "The list is empty" << '\n';
				return true;
			}
			cout << "The list is NOT empty" << '\n';
			return false;
		}

		T const findmax(){
			T max;
			node<T> *current = new node<T>;
			node<T> *nn = new node<T>;
			nn = head->next;
			current = head;
			max = std::numeric_limits<T>::min();
			int index = 1;
			while(current){
				if(current->data > max){
					max = current->data;
				}
				current = current->next;
				index++;
			}
			cout << "The MAXIMUM value found in the list is: " << max << '\n';
			return max;
			}

			T const findmin(){
				T min;
				node<T> *current = new node<T>;
				current = head;
				min = std::numeric_limits<T>::max();
				int index = 1;
				while(current){
					if(current->data < min){
						min = current->data;
					}
					current = current->next;
					index++;
				}
				cout << "The MINIMUM value found in the list is: " << min << '\n';
				return min;
				}

};

#endif
