#include "playing_card.h"
#include "node.h"
using namespace std;

// ==================================================================================
// prototypes for provided functions (implemented in main.cpp)
// ==================================================================================

bool SanityCheckPrimary(Node* top);
bool SanityCheckSorted(Node* first);
Node* CreateDeck(int numCards);
void DeckPushBackCard(Node* &deck, const std::string& suit, int num);
void PrintDeckPrimary(const std::string &description, Node* deck);


// ==================================================================================
//
// Write all the prototypes for the your functions here
// (they will be implemented in deck.cpp)
//
// NOTE: These are standalone functions, not part of a class.
//
// You may include additional helper functions as necessary
// All of your code must be in deck.h and deck.cpp
//
// ==================================================================================

int DeckSize(Node* deck);
 
Node* CopyDeck(Node* &deck);

void CutDeck(Node* &deck, Node* &top, Node* &bottom, string type);

void PrintDeckSorted(const std::string &description, Node* deck);

Node* Shuffle(Node* &top, Node* &bottom, string type);

bool SamePrimaryOrder(Node* &deck1, Node* &deck2);

bool ReversePrimaryOrder(Node* &deck1, Node* &deck2);

void DeleteAllCards(Node* &deck);

void Deal(Node* &deck, Node* array[], int arr_size, string type, int cards);

Node* SortHand(Node* deck);
