# Solitaire

This game of Solitaire is completely played within the terminal after executing the code. The goal of Solitaire is to separate the four card suits–Spades (S), Clubs (C), Hearts (H), and Diamonds (D), where S and C are black and H and D are red–into increasingly sorted piles. 

Your cards will be originally displayed in 7 Tableaus where Tableau number t (t=1,...,7) contains t-1 "face down" cards followed by one "face up" card. The remaining 28 cards will be held in the entirely "face down" Stock. When a card directly preceded by a "face down" card is moved, the card that is now at the end of this Tableau will be "flipped over" to display its value and suit. However, when a card is taken off the Stock, only this card is displayed "face up" while the rest remain "face down".

You will also see 4 Foundation piles at the top. This is where each suit will be built up from lowest card value to highest card value in the sequence A,2,3,4,5,6,7,8,9,J,Q,K. Before the cards make it to these Foundation piles, cards can only be set atop a card at the end of a Tableau that is of the opposite color and is one number higher in value. Additionally, cards can only be moved if they are currently at the end of a Tableau. For example, if the Spade Foundation pile currently has a [5 of S] as its highest card and I currently have a [7 of S] at the end of a Tableau, until the [6 of S] makes it to the Spade Foundation pile, [7 of S] can only be moved if there is an [8 of H] or [8 of D] at the end of a Tableau.

For more details on the rules of Solitaire, please refer to [this link](https://bicyclecards.com/how-to-play/solitaire).

## How to Run and Play

Compile the code using
```
gcc -g -Wall solitaire.c -o solitaire
```
and run using
```
./solitaire
```
