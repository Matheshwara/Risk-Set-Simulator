#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a_ctr=0; int b_ctr=0; int c_ctr=0;

char getRandomCard(char arr[], int size) {
    // Generate a random index from 0 to (size - 1)
    int randomIndex = rand() % size;
    return arr[randomIndex];
} 

int reset() {
    a_ctr = 0; b_ctr = 0; c_ctr = 0; //reset counters
    return -1; //reset index counter by returning -1
}
    
int main() {
    char inHandDeck[10];
    
    //Global elements for function to throw randrom card
    srand(time(NULL));
    char basicDeck[3]={'a','b','c'};
    int basicDeckLength = sizeof(basicDeck) / sizeof(basicDeck[0]);
    
    for (int i=0; i<10; i++){
        char randomCard = getRandomCard(basicDeck, basicDeckLength);
        inHandDeck[i] = randomCard;
        
        //incrementing basic card counters
        if (inHandDeck[i] == 'a') a_ctr++;
        else if (inHandDeck[i] == 'b') b_ctr++;
        else if (inHandDeck[i] == 'c') c_ctr++;
        
        //printing cards in hands
        for (int j=0; j<=i; j++){
            printf("%c ", inHandDeck[j]);
        }
        printf("\n");
        
        printf("Drew: %c | Hand: %d/10 | Counts: a:%d b:%d c:%d\n", inHandDeck[i], i + 1, a_ctr, b_ctr, c_ctr);
        
        //Checking for three of a kind combination
        if (a_ctr == 3 || b_ctr == 3 || c_ctr == 3){
            printf("--- Three of a kind! Clearing hand... ---\n\n");
            
            i = reset();
        }
        
        //Checking for combination of each basic cards
        if (a_ctr != 0 && b_ctr != 0 && c_ctr != 0){
            printf("--- Combo of each! Clearing hand... ---\n\n");

            i = reset();
        }
        
    }//end of for loop
    
    
    return 0;
}