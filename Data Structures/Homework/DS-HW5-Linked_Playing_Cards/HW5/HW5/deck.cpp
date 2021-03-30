// ==================================================================================
// Implement all functions that you listed by prototype in deck.h
// You may include additional helper functions as necessary
// All of your code must be in deck.h and deck.cpp
//
// NOTE: These are standalone functions, not part of a class.
// ==================================================================================

#include <iostream>
#include <cassert>
#include "playing_card.h"
#include "node.h"
#include "deck.h"

// ==================================================================================


//MARK: DECK SIZE FUNCTION -----------------------------------------------------
int DeckSize(Node* deck){
    int count = 0;              //Deck size counter
    Node* curr = deck;          //Pointer to start of deck
    while(curr!= NULL){
        count++;                //Adds to counter for every card in deck
        curr = curr -> after;
    }
    return count;               //returns int count value
}


//MARK: COPY DECK FUNCTION -----------------------------------------------------
Node* CopyDeck(Node* &deck){
    Node* current = deck;           //Iterator for original list
    Node* newList = NULL;           //Head of new list
    Node* tail = NULL;              //Last element in new list
    Node* previous = tail;
    
    while(current != NULL){
        //First Node:
        if(newList == NULL){
            newList = new Node(current->getCard());     //error?
            newList ->after = nullptr;
            newList -> before = previous;
            tail = newList;
            previous = tail;
        }
        else{
            previous = tail;
            tail->after = new Node(current->getCard());
            tail = tail->after;
            
            tail->before = previous;
            tail->after = nullptr;
            
        }
        current =current->after;
    }
    return newList;
}


//MARK: CUT DECK FUNCTION ------------------------------------------------------
void CutDeck(Node* &deck, Node* &top, Node* &bottom, string type){
    /*
     I will split the deck in half by moving two pointers, the first one
     (ptr 1) will move by 1 and the second one (ptr 2) will move by 2, this
     way the length from beginning to 1 will be half of beginning to 2 for
     even number deck and for odd number decks the top will have 1 more.
     */
    
    //---------- PERFECT CUT --------------------------------------
    if(type == "perfect"){
        
        if(deck == NULL){               //Special Case: Empty deck
            top = nullptr;
            bottom = nullptr;
            
        }
        else if(deck->after == NULL){    //Case with only one elment
            top = deck;
            bottom = NULL;
        }
        else{
            Node* current = deck;                       //Setting head copy
            
            //List: >0 element:
            Node* long_runner = current->after;         //Initializing far ptr
            Node* short_runner = current;               //Initializing middle ptr
            
            while(long_runner != nullptr){
                long_runner = long_runner->after;       //Moving far by 1
                if(long_runner == nullptr){
                    break;                              //Checking if at end of list
                }
                else{
                    long_runner = long_runner->after;       //Move far ptr again
                    short_runner = short_runner->after;     //Move close ptr 1
                }
            }
            
            Node* second_part = short_runner->after;    //Part to return.
            
            //Seperating lists by removing pointers connecting them
            second_part->before = nullptr;
            short_runner->after = nullptr;
            
            top = deck;                             //Assigning top to first half
            bottom = second_part;                   //Assigning bottom to second half
        }
    }
}


//MARK: PRINT SORTED DECK FUNCTION ---------------------------------------------
void PrintDeckSorted(const std::string &description, Node* sorted_deck){
    cout << description;
    
    Node* temp = sorted_deck;                           //sorted Deck pointer
    while(temp != NULL){
        cout << " " << temp->getCard().getString();     //Print out sorted card
        temp = temp->sorted_next;                       //Move to next sorted card
    }
    cout << endl;
}


//MARK: SHUFFLE FUNCTION -------------------------------------------------------
Node* Shuffle(Node* &top, Node* &bottom, string type){
    /*
     Iterates through both of the lists and inserts the bottom elements into the
     top elements list in the specifies place until it reaches the end of the
     linked list.
     */
    Node* head = top;
    
    Node* top_itr = top;
    Node* bottom_itr = bottom;
    
    // ---------- Out Shuffle ----------------------------------------------
    if(top_itr == NULL){               //Empty Deck case
        return NULL;
    }
    else if(bottom_itr == NULL){          //Case of only one card
        return top_itr;
    }
    Node* prev = top_itr;
    Node* next = top_itr->after;
    
    while(next != NULL){
        top_itr->after = bottom_itr;        //connect bottom card to top
        bottom_itr = bottom_itr->after;     //Increment bottom itr
        
        top_itr = top_itr->after;   //Top iter = bottom card to be inserted
        
        
        top_itr->before = prev;     //Assigning pointers to correct place
        top_itr->after = next;
        next->before = top_itr;
        
        //Incrementing top list pointer to next insert spot
        top_itr = next;
        prev = top_itr;
        next = next->after;
        
        //Checking for end case
        if(next == NULL and bottom_itr != NULL){
            top_itr->after = bottom_itr;
            top_itr->after->before = top_itr;
        }
        
    }
    
    return head;     //return head, which now has bottom elements inserted
}



//MARK: SAME PRIMARY ORDER FUNCTION --------------------------------------------
bool SamePrimaryOrder(Node* &deck1, Node* &deck2){
    /*
     Iterates through all of the elements in the decks and if all elements match,
     returns true, if one element doesn't match, then return false.
     */
    
    Node* deck1_check = deck1;
    Node* deck2_check = deck2;
    
    while(deck1_check!= NULL && deck2_check!= NULL){
        //Check if they don't match
        if(deck1_check->getCard().getString() != deck2_check->getCard().getString()){
            return false;
        }
        
        //Increment the decks
        deck1_check = deck1_check->after;
        deck2_check = deck2_check->after;
    }
    return true;
}


//MARK: REVERSE PRIMARY ORDER FUNCTION -----------------------------------------
bool ReversePrimaryOrder(Node* &deck1, Node* &deck2){
    /*
     Iterates through all the elements in both decks in reverse order, if all
     match then returns true, if one doesn't match then returns false.
     */
    Node* deck1_check = deck1;
    Node* deck2_check = deck2;
    
    //Moving the deck2_check to the end of deck2
    while(deck2_check->after != NULL){
        deck2_check = deck2_check->after;
    }
    
    while(deck1_check != nullptr && deck2_check!= nullptr){
        //Check if the elements don't match
        if(deck1_check->getCard().getString() != deck2_check->getCard().getString()){
            return false;
        }
        
        //Increment the decks
        deck1_check = deck1_check->after;
        deck2_check = deck2_check->before;
    }
    return true;
}


//MARK: DELETE ALL CARDS FUNCTION ----------------------------------------------
void DeleteAllCards(Node* &deck){
    /*
     Recursive function to circle through the cards
     in the deck and delete each one.
     */
    
    if(deck == NULL){
        
    }
    else{
        DeleteAllCards(deck->after);
        delete deck;
        deck = NULL;
    }
}

//MARK: DEAL FUNCTION ----------------------------------------------------------
void Deal(Node* &deck, Node** array, int arr_size, string type, int cards){
    
    int expected_cards = DeckSize(deck)/arr_size;
    if(cards > expected_cards){          //Fixs deal with a wrong "cards" input
        cards = expected_cards;
    }
    
    for(int i = 0; i<cards; i++){
        if (deck) {
            for(int j=0; j<arr_size; j++){
                if(i == 0){                     //Dealing the first Card
                    //Assigning the pointers
                    array[j] = deck;
                    deck = deck->after;
                    deck->before->after = NULL;
                    deck->before = NULL;
                    
                }
                else{                           //Dealing all of the other cards
                    //Assigning the pointers
                    array[j]->after = deck;
                    array[j]->after->before = array[j];
                    array[j] = array[j]->after;
                    
                    deck = deck->after;         //Move to the element in the list
                    array[j]->after = NULL;
                    
                    if (deck) {                 //Only runs if not the last card
                        deck->before = NULL;
                    }
                }
            }
        }
    }
    for(int j=0; j<arr_size; j++){          //Resetting the heads
        while(array[j]->before != NULL){
            array[j] = array[j]->before;
        }
    }
}


//MARK: SORT HAND FUNCTION -----------------------------------------------------
Node* SortHand(Node* deck){
    //Uses Insertion sort method from Wikipedia Link in instructions
    if(deck == NULL || deck->after==NULL){      //Empty Deck Case
        return deck;
    }
    
    Node* head = NULL;
    while(deck!=NULL){
        Node* curr = deck;
        deck = deck->after;
        //Check if sorted is empty, if so curr becomes the first element.
        if(head == NULL){
            curr->sorted_next = head;
            head = curr;
        }
        //Check if the card belongs in the front of sorted deck
        else if(curr->getCard()<head->getCard()){
            
            curr->sorted_next = head;
            head->sorted_prev = curr;
            head = curr;
        }
        else{
            Node* p = head;
            while(p!=NULL){
                //Check if the element needs to be inserted as last element
                if(p->sorted_next==NULL){
                    curr->sorted_next = p->sorted_next;
                    p->sorted_next = curr;
                    curr->sorted_prev = p;
                    break;
                }
                //Finding the middle spot to place the card, if belongs in middle
                else if(curr->getCard()<p->sorted_next->getCard()){
                    curr->sorted_next = p->sorted_next;
                    p->sorted_next->sorted_prev = curr;
                    p->sorted_next = curr;
                    curr->sorted_prev = p;
                    break;
                }
                p=p->sorted_next;
            }
        }
    }
    return head;        //Returns the head of the sorted list.
}
