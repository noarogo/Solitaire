#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct Card {
  char name[20];
  int val;
  char suit;
  int color;
};

struct Tableau {
  struct Card cards[19];
  int numCards;
  int numInvCards;
};

struct Stock {
  struct Card pile[24];
  struct Card flipped[24];
  int pileCards;
  int flipCards;
};

struct Card deck[52], f[4];
struct Tableau tab1, tab2, tab3, tab4, tab5, tab6, tab7;
struct Stock stock;

void display(){
  printf("D: ");
  if(stock.pileCards > 0){ printf("[  ]"); }
  else { printf("[ empty ]"); }
  if(stock.flipCards > 0){ printf("[ %s ]", stock.flipped[stock.flipCards-1].name); }
  else { printf("\t\t"); }

  printf("\t\tF: [ %s ][ %s ][ %s ][ %s ]", f[0].name, f[1].name, f[2].name, f[3].name);
  printf("\nTableau:");
  printf("\n1: ");
  for(int i=0; i < tab1.numCards; i++){
      printf("[ %s ]", tab1.cards[i].name);
  }

  printf("\n2: ");
  if(tab2.numCards > 0){
    if(tab2.numInvCards > 0){
      for(int i=0; i < tab2.numInvCards; i++){
        printf("[  ]");
      }
    }
    for(int i=tab2.numInvCards; i < tab2.numCards; i++){
      printf("[ %s ]", tab2.cards[i].name);
    }
  }

  printf("\n3: ");
  if(tab3.numCards > 0){
    if(tab3.numInvCards > 0){
      for(int i=0; i < tab3.numInvCards; i++){
        printf("[  ]");
      }
    }
    for(int i=tab3.numInvCards; i < tab3.numCards; i++){
      printf("[ %s ]", tab3.cards[i].name);
    }
  }

  printf("\n4: ");
  if(tab4.numCards > 0){
    if(tab4.numInvCards > 0){
      for(int i=0; i < tab4.numInvCards; i++){
        printf("[  ]");
      }
    }
    for(int i=tab4.numInvCards; i < tab4.numCards; i++){
      printf("[ %s ]", tab4.cards[i].name);
    }
  }

  printf("\n5: ");
  if(tab5.numCards > 0){
    if(tab5.numInvCards > 0){
      for(int i=0; i < tab5.numInvCards; i++){
        printf("[  ]");
      }
    }
    for(int i=tab5.numInvCards; i < tab5.numCards; i++){
      printf("[ %s ]", tab5.cards[i].name);
    }
  }

  printf("\n6: ");
  if(tab6.numCards > 0){
    if(tab6.numInvCards > 0){
      for(int i=0; i < tab6.numInvCards; i++){
        printf("[  ]");
      }
    }
    for(int i=tab6.numInvCards; i < tab6.numCards; i++){
      printf("[ %s ]", tab6.cards[i].name);
    }
  }

  printf("\n7: ");
  if(tab7.numCards > 0){
    if(tab7.numInvCards > 0){
      for(int i=0; i < tab7.numInvCards; i++){
        printf("[  ]");
      }
    }
    for(int i=tab7.numInvCards; i < tab7.numCards; i++){
      printf("[ %s ]", tab7.cards[i].name);
    }
  }
}

void game(){
  bool done = false;
  bool good = true;
  char from, to;
  struct Card hold;
  struct Card temp;

  while(done == false) {
    display();
    printf("\nYour move (from; S = flip stock): ");
    scanf(" %c", &from);
    //

    //test if move is possible
    if(from == 'S' || from == 'D') {
      if(stock.pileCards == 0)
        good = false;
    } else if(from == '1') {
      if(tab1.numCards <= 0)
        good = false;
    } else if(from == '2') {
      if(tab2.numCards <= 0)
        good = false;
    } else if(from == '3') {
      if(tab3.numCards <= 0)
        good = false;
    } else if(from == '4') {
      if(tab4.numCards <= 0)
        good = false;
    } else if(from == '5') {
      if(tab5.numCards <= 0)
        good = false;
    } else if(from == '6') {
      if(tab6.numCards <= 0)
        good = false;
    } else if(from == '7') {
      if(tab7.numCards <= 0)
        good = false;
    }

    if(good == false) {
      printf("This move is not possible. Please try again.\n");
      break;
    }

    //start move
    if(from == 'S'){
      stock.flipped[stock.flipCards] = stock.pile[stock.pileCards-1];
      stock.flipCards++;
      stock.pileCards--;
    } else if(from == 'D'){
      hold = stock.flipped[stock.flipCards-1];
      stock.flipCards--;
    } else if(from == '1'){
      hold = tab1.cards[tab1.numCards-1];
      tab1.numCards--;
      tab1.numInvCards--;
    } else if(from == '2'){
      hold = tab2.cards[tab2.numCards-1];
      tab2.numCards--;
      tab2.numInvCards--;
    } else if(from == '3'){
      hold = tab3.cards[tab3.numCards-1];
      tab3.numCards--;
      tab3.numInvCards--;
    } else if(from == '4'){
      hold = tab4.cards[tab4.numCards-1];
      tab4.numCards--;
      tab4.numInvCards--;
    } else if(from == '5'){
      hold = tab5.cards[tab5.numCards-1];
      tab5.numCards--;
      tab5.numInvCards--;
    } else if(from == '6'){
      hold = tab6.cards[tab6.numCards-1];
      tab6.numCards--;
      tab6.numInvCards--;
    } else if(from == '7'){
      hold = tab7.cards[tab7.numCards-1];
      tab7.numCards--;
      tab7.numInvCards--;
    }

    //flipping Stock doesn't require a "to"
    if(from != 'S'){
      printf("Your move (to): ");
      scanf(" %c", &to);
      //test if move is possible
      if(to == '1'){
        if(tab1.cards[tab1.numCards-1].val < hold.val || tab1.cards[tab1.numCards-1].color == hold.color || (tab1.numCards == 0 && hold.val != 13))
          good = false;
      } else if(to == '2'){
        if(tab2.cards[tab2.numCards-1].val < hold.val || tab2.cards[tab2.numCards-1].color == hold.color || (tab2.numCards == 0 && hold.val != 13))
          good = false;
      } else if(to == '3'){
        if(tab3.cards[tab3.numCards-1].val < hold.val || tab3.cards[tab3.numCards-1].color == hold.color || (tab3.numCards == 0 && hold.val != 13))
          good = false;
      } else if(to == '4'){
        if(tab4.cards[tab4.numCards-1].val < hold.val || tab4.cards[tab4.numCards-1].color == hold.color || (tab4.numCards == 0 && hold.val != 13))
          good = false;
      } else if(to == '5'){
        if(tab5.cards[tab5.numCards-1].val < hold.val || tab5.cards[tab5.numCards-1].color == hold.color || (tab5.numCards == 0 && hold.val != 13))
          good = false;
      } else if(to == '6'){
        if(tab6.cards[tab6.numCards-1].val < hold.val || tab6.cards[tab6.numCards-1].color == hold.color || (tab6.numCards == 0 && hold.val != 13))
          good = false;
      } else if(to == '7'){
        if(tab7.cards[tab7.numCards-1].val < hold.val || tab7.cards[tab7.numCards-1].color == hold.color || (tab7.numCards == 0 && hold.val != 13))
          good = false;
      } else if(to == 'F'){
        if(hold.suit == 'D'){
          if(f[0].suit == 'D'){
            if(hold.val != f[0].val-1)
              good = false;
          } else{
            if(hold.val != 0)
              good = false;
          }
        } else if(hold.suit == 'H'){
          if(f[1].suit == 'H'){
            if(hold.val != f[1].val-1)
              good = false;
          } else{
            if(hold.val != 0)
              good = false;
          }
        } else if(hold.suit == 'C'){
          if(f[2].suit == 'C'){
            if(hold.val != f[2].val-1)
              good = false;
          } else{
            if(hold.val != 0)
              good = false;
          }
        } else if(hold.suit == 'S'){
          if(f[3].suit == 'S'){
            if(hold.val != f[3].val-1)
              good = false;
          } else{
            if(hold.val != 0)
              good = false;
          }
        }
      }
    }
    if(good == false) {
      printf("This move is not possible. Please try again.\n");
      break;
    }

    //make move
    if(to == '1'){
      tab1.cards[tab1.numCards] = hold;
      tab1.numCards++;
    } else if(to == '2'){
      tab2.cards[tab2.numCards] = hold;
      tab2.numCards++;
    } else if(to == '3'){
      tab3.cards[tab3.numCards] = hold;
      tab3.numCards++;
    } else if(to == '4'){
      tab4.cards[tab4.numCards] = hold;
      tab4.numCards++;
    } else if(to == '5'){
      tab5.cards[tab5.numCards] = hold;
      tab5.numCards++;
    } else if(to == '6'){
      tab6.cards[tab6.numCards] = hold;
      tab6.numCards++;
    } else if(to == '7'){
      tab7.cards[tab7.numCards] = hold;
      tab7.numCards++;
    } else if(to == 'F') {
      if(hold.suit == 'D'){
        f[0] = hold;
      } else if(hold.suit == 'H'){
        f[1] = hold;
      } else if(hold.suit == 'C'){
        f[2] = hold;
      }  else if(hold.suit == 'S'){
        f[3] = hold;
      }
    }

    //check if game has been won
    if(f[0].val == 13 && f[1].val == 13 && f[2].val == 13 && f[3].val == 13){
      printf("Congratulations, you won!");
      done = true;
    }
  }
}

int main() {
  srand(time(0));

  stock.pileCards = 24; stock.flipCards = 0;

  tab1.numCards = 1;  tab1.numInvCards = 0;
  tab2.numCards = 2;  tab2.numInvCards = 1;
  tab3.numCards = 3;  tab3.numInvCards = 2;
  tab4.numCards = 4;  tab4.numInvCards = 3;
  tab5.numCards = 5;  tab5.numInvCards = 4;
  tab6.numCards = 6;  tab6.numInvCards = 5;
  tab7.numCards = 7;  tab7.numInvCards = 6;

  struct Card aceD;
  struct Card aceH;
  struct Card aceC;
  struct Card aceS;
  strcpy(aceD.name, "Ace of D");
  strcpy(aceH.name, "Ace of H");
  strcpy(aceC.name, "Ace of C");
  strcpy(aceS.name, "Ace of S");
  aceD.val=0;
  aceH.val=0;
  aceC.val=0;
  aceS.val=0;
  aceD.suit='D';
  aceH.suit='H';
  aceC.suit='C';
  aceS.suit='S';
  aceD.color=0;
  aceH.color=0;
  aceC.color=1;
  aceS.color=1;

  struct Card twoD;
  struct Card twoH;
  struct Card twoC;
  struct Card twoS;
  strcpy(twoD.name, "Two of D");
  strcpy(twoH.name, "Two of H");
  strcpy(twoC.name, "Two of C");
  strcpy(twoS.name, "Two of S");
  twoD.val=2;
  twoH.val=2;
  twoC.val=2;
  twoS.val=2;
  twoD.suit='D';
  twoH.suit='H';
  twoC.suit='C';
  twoS.suit='S';
  twoD.color=0;
  twoH.color=0;
  twoC.color=1;
  twoS.color=1;

  struct Card thrD;
  struct Card thrH;
  struct Card thrC;
  struct Card thrS;
  strcpy(thrD.name, "Three of D");
  strcpy(thrH.name, "Three of H");
  strcpy(thrC.name, "Three of C");
  strcpy(thrS.name, "Three of S");
  thrD.val=3;
  thrH.val=3;
  thrC.val=3;
  thrS.val=3;
  thrD.suit='D';
  thrH.suit='H';
  thrC.suit='C';
  thrS.suit='S';
  thrD.color=0;
  thrH.color=0;
  thrC.color=1;
  thrS.color=1;

  struct Card fouD;
  struct Card fouH;
  struct Card fouC;
  struct Card fouS;
  strcpy(fouD.name, "Four of D");
  strcpy(fouH.name, "Four of H");
  strcpy(fouC.name, "Four of C");
  strcpy(fouS.name, "Four of S");
  fouD.val=4;
  fouH.val=4;
  fouC.val=4;
  fouS.val=4;
  fouD.suit='D';
  fouH.suit='H';
  fouC.suit='C';
  fouS.suit='S';
  fouD.color=0;
  fouH.color=0;
  fouC.color=1;
  fouS.color=1;

  struct Card fivD;
  struct Card fivH;
  struct Card fivC;
  struct Card fivS;
  strcpy(fivD.name, "Five of D");
  strcpy(fivH.name, "Five of H");
  strcpy(fivC.name, "Five of C");
  strcpy(fivS.name, "Five of S");
  fivD.val=5;
  fivH.val=5;
  fivC.val=5;
  fivS.val=5;
  fivD.suit='D';
  fivH.suit='H';
  fivC.suit='C';
  fivS.suit='S';
  fivD.color=0;
  fivH.color=0;
  fivC.color=1;
  fivS.color=1;

  struct Card sixD;
  struct Card sixH;
  struct Card sixC;
  struct Card sixS;
  strcpy(sixD.name, "Six of D");
  strcpy(sixH.name, "Six of H");
  strcpy(sixC.name, "Six of C");
  strcpy(sixS.name, "Six of S");
  sixD.val=6;
  sixH.val=6;
  sixC.val=6;
  sixS.val=6;
  sixD.suit='D';
  sixH.suit='H';
  sixC.suit='C';
  sixS.suit='S';
  sixD.color=0;
  sixH.color=0;
  sixC.color=1;
  sixS.color=1;

  struct Card sevD;
  struct Card sevH;
  struct Card sevC;
  struct Card sevS;
  strcpy(sevD.name, "Seven of D");
  strcpy(sevH.name, "Seven of H");
  strcpy(sevC.name, "Seven of C");
  strcpy(sevS.name, "Seven of S");
  sevD.val=7;
  sevH.val=7;
  sevC.val=7;
  sevS.val=7;
  sevD.suit='D';
  sevH.suit='H';
  sevC.suit='C';
  sevS.suit='S';
  sevD.color=0;
  sevH.color=0;
  sevC.color=1;
  sevS.color=1;

  struct Card eigD;
  struct Card eigH;
  struct Card eigC;
  struct Card eigS;
  strcpy(eigD.name, "Eight of D");
  strcpy(eigH.name, "Eight of H");
  strcpy(eigC.name, "Eight of C");
  strcpy(eigS.name, "Eight of S");
  eigD.val=8;
  eigH.val=8;
  eigC.val=8;
  eigS.val=8;
  eigD.suit='D';
  eigH.suit='H';
  eigC.suit='C';
  eigS.suit='S';
  eigD.color=0;
  eigH.color=0;
  eigC.color=1;
  eigS.color=1;

  struct Card ninD;
  struct Card ninH;
  struct Card ninC;
  struct Card ninS;
  strcpy(ninD.name, "Nine of D");
  strcpy(ninH.name, "Nine of H");
  strcpy(ninC.name, "Nine of C");
  strcpy(ninS.name, "Nine of S");
  ninD.val=9;
  ninH.val=9;
  ninC.val=9;
  ninS.val=9;
  ninD.suit='D';
  ninH.suit='H';
  ninC.suit='C';
  ninS.suit='S';
  ninD.color=0;
  ninH.color=0;
  ninC.color=1;
  ninS.color=1;

  struct Card tenD;
  struct Card tenH;
  struct Card tenC;
  struct Card tenS;
  strcpy(tenD.name, "Ten of D");
  strcpy(tenH.name, "Ten of H");
  strcpy(tenC.name, "Ten of C");
  strcpy(tenS.name, "Ten of S");
  tenD.val=10;
  tenH.val=10;
  tenC.val=10;
  tenS.val=10;
  tenD.suit='D';
  tenH.suit='H';
  tenC.suit='C';
  tenS.suit='S';
  tenD.color=0;
  tenH.color=0;
  tenC.color=1;
  tenS.color=1;

  struct Card jacD;
  struct Card jacH;
  struct Card jacC;
  struct Card jacS;
  strcpy(jacD.name, "Jack of D");
  strcpy(jacH.name, "Jack of H");
  strcpy(jacC.name, "Jack of C");
  strcpy(jacS.name, "Jack of S");
  jacD.val=11;
  jacH.val=11;
  jacC.val=11;
  jacS.val=11;
  jacD.suit='D';
  jacH.suit='H';
  jacC.suit='C';
  jacS.suit='S';
  jacD.color=0;
  jacH.color=0;
  jacC.color=1;
  jacS.color=1;

  struct Card queD;
  struct Card queH;
  struct Card queC;
  struct Card queS;
  strcpy(queD.name, "Queen of D");
  strcpy(queH.name, "Queen of H");
  strcpy(queC.name, "Queen of C");
  strcpy(queS.name, "Queen of S");
  queD.val=12;
  queH.val=12;
  queC.val=12;
  queS.val=12;
  queD.suit='D';
  queH.suit='H';
  queC.suit='C';
  queS.suit='S';
  queD.color=0;
  queH.color=0;
  queC.color=1;
  queS.color=1;

  struct Card kinD;
  struct Card kinH;
  struct Card kinC;
  struct Card kinS;
  strcpy(kinD.name, "King of D");
  strcpy(kinH.name, "King of H");
  strcpy(kinC.name, "King of C");
  strcpy(kinS.name, "King of S");
  kinD.val=13;
  kinH.val=13;
  kinC.val=13;
  kinS.val=13;
  kinD.suit='D';
  kinH.suit='H';
  kinC.suit='C';
  kinS.suit='S';
  kinD.color=0;
  kinH.color=0;
  kinC.color=1;
  kinS.color=1;

  deck[0] = aceD;  deck[1] = aceH;  deck[2] = aceC; deck[3] = aceS;
  deck[4] = twoD;  deck[5] = twoH;  deck[6] = twoC; deck[7] = twoS;
  deck[8] = thrD;  deck[9] = thrH;  deck[10] = thrC; deck[11] = thrS;
  deck[12] = fouD;  deck[13] = fouH;  deck[14] = fouC; deck[15] = fouS;
  deck[16] = fivD;  deck[17] = fivH;  deck[18] = fivC; deck[19] = fivS;
  deck[20] = sixD;  deck[21] = sixH;  deck[22] = sixC; deck[23] = sixS;
  deck[24] = sevD;  deck[25] = sevH;  deck[26] = sevC; deck[27] = sevS;
  deck[28] = eigD;  deck[29] = eigH;  deck[30] = eigC; deck[31] = eigS;
  deck[32] = ninD;  deck[33] = ninH;  deck[34] = ninC; deck[35] = ninS;
  deck[36] = tenD;  deck[37] = tenH;  deck[38] = tenC; deck[39] = tenS;
  deck[40] = jacD;  deck[41] = jacH;  deck[42] = jacC; deck[43] = jacS;
  deck[44] = queD;  deck[45] = queH;  deck[46] = queC; deck[47] = queS;
  deck[48] = kinD;  deck[49] = kinH;  deck[50] = kinC; deck[51] = kinS;

  //shuffle cards
  for(int i = 0; i < 100000; i++){
    int index = rand() % 52;
    int index2 = rand() % 52;
    struct Card temp = deck[index];
    deck[index] = deck[index2];
    deck[index2] = temp;
  }

  int j = 0;
  //queue 24 in Stock
  for(; j < 24; j++){
    stock.pile[j] = deck[j];
  }

  //queue each tableau row
  tab1.cards[0] = deck[24];
  j++;
  for(; j < 27; j++)
  { tab2.cards[j-25] = deck[j]; }
  for(; j < 30; j++)
  { tab3.cards[j-27] = deck[j]; }
  for(; j < 34; j++)
  { tab4.cards[j-30] = deck[j]; }
  for(; j < 39; j++)
  { tab5.cards[j-34] = deck[j]; }
  for(; j < 45; j++)
  { tab6.cards[j-39] = deck[j]; }
  for(; j < 52; j++)
  { tab7.cards[j-45] = deck[j]; }

  game();
}
