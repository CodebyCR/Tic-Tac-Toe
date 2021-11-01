//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Christoph Rohde on 28.09.21.
//
//  Version 1.0.2

#include <stdio.h>
#include <iostream>
#include "XO.cpp"
using namespace::std;

bool win = false;

int Round = 0;

Player player1;
Player player2;



string getCurrentPlayer()
{
    if (Round % 2) {
        return player1.m_playerName;
    } else{
        return player2.m_playerName;
    }
    return "Nobody";
}

int main() {
    
    // Player 1 Attribut belegung
    cout << "Player 1 gib deinen Namen ein.\n";
    cin >> player1.m_playerName;
    
    cout << player1.m_playerName << " gib dein Symbol ein.( x | o )\n";
    cin >> player1.m_symbol;
    
    
    // Player 2 Attribut belegung
    cout << "Player 2 gib deinen Namen ein.\n";
    cin >> player2.m_playerName;
    
    cout << player2.m_playerName << " gib dein Symbol ein.( x | o )\n";
    cin >> player2.m_symbol;
    
    //  Initalisiere Matrix
    char tttMatrix [3][3] = {   {1,2,3},
                                {4,5,6},
                                {7,8,9} };
    
    while (Round < 9 && win == false) {
        ++Round;
        
        //TODO: add Clean Consol methode
        //cleanScreen();
        
        //  Zwischenstand
        cout << "\n" << player1.m_playerName << " wählte: (" << player1.m_symbol << ") & " << player2.m_playerName << " wählte: (" << player2.m_symbol << ")\n";
        cout << "|\tRunde: " << Round << "\t|\t" << getCurrentPlayer() << " ist dran.\t|\n\n";
        
        //  Print matchfield
        for (int i = 0; i < 3; i++) {
            cout << "\t";
            for (int j = 0; j < 3; j++) {
                printf(" %d", tttMatrix[i][j] );
                if (j != 2) {
                    cout << " |";
                }
            }
            if (i != 2) {
                cout << "\n\t-----------\n";
            }
        }
        
        printf("\n\n");
        
        //TODO: add methode that change matchfield sector to currentPlayer symbole + add methode that check has someone win the game.
        
    }
    return 0;
}


