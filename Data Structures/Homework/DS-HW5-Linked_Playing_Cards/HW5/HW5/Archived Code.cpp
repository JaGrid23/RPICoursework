//
//  Archived Code.cpp
//  HW5
//
//  Created by Jared Gridley on 2/24/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//

#include <stdio.h>

/*
 OUT SHUFFLE:
 

 Node* shuffled = new Node(top_itr->getCard());
 shuffled->after = nullptr;
 shuffled->before = nullptr;
 
 Node* head = shuffled;
 top_itr = top_itr->after;
 
 while(top_itr != nullptr){
     Node* previous = shuffled;
     shuffled = shuffled->after;
     
     shuffled = new Node(bottom_itr->getCard());
     shuffled->before = previous;
     shuffled->after = nullptr;
     
     bottom_itr = bottom_itr->after;
     
     if(top_itr == nullptr){
         break;
     }
     else{
         Node* previous = shuffled;
         shuffled = shuffled->after;
         
         shuffled = new Node(top_itr->getCard());
         
         shuffled->before = previous;
         shuffled->after = nullptr;
         
         top_itr = top_itr->after;
     }
 }
 return head;
 
 
 
 IN SHUFFLE
 
     Node* shuffled = new Node(bottom_itr->getCard());
     shuffled->after = nullptr;
     shuffled->before = nullptr;
     
     Node* const head = shuffled;
     bottom_itr = bottom_itr->after;
     
     while(bottom_itr != nullptr){
         Node* previous = shuffled;
         shuffled = shuffled->after;
         
         shuffled = new Node(top_itr->getCard());
         shuffled->before = previous;
         shuffled->after = nullptr;
         
         top_itr = top_itr->after;
         
         if(bottom_itr == NULL and top_itr == NULL){
             break;
         }
         else if (bottom_itr == NULL and top_itr != NULL){
             Node* previous = shuffled;
             shuffled = shuffled->after;
             
             shuffled = new Node(top_itr->getCard());
             shuffled->before = previous;
             shuffled->after = nullptr;
             
             top_itr = top_itr->after;
         }
         else{
             Node* previous = shuffled;
             shuffled = shuffled->after;
             
             shuffled = new Node(bottom_itr->getCard());
             shuffled->before = previous;
             shuffled->after = nullptr;
             
             bottom_itr = bottom_itr->after;
         }
     }
     return head;
 }

 */




//COPY DECK:
 /*
    Node* curr = deck;
    
    //For 0 cards in the deck
    
    //For 1st card in the deck
    //Creating an iterator through the linked list
    Node* copy = new Node(curr->getCard());
    copy->after = nullptr;
    copy->before = nullptr;
    
    //Creating a new head for the copied deck
    Node (*copy_head) = copy;
    
    curr = curr->after;
    
    //For the rest of the cards in the deck
    while(curr != nullptr){
        Node* previous = copy;              //Assigning previous to node before it moves
        
        //copy = copy->after;                 //Moving to null pointer of current node
        copy->after = new Node(curr->getCard());   //Making a new node to point to
        
        copy->before = previous;            //Assigning back pointer the previous node
        copy->after = nullptr;
        curr = curr->after;                 //Moving current to the next node to be copied
    }

    return copy_head;
}
*/
