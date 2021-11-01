//
//  XO.cpp
//  Tic-Tac-Toe
//
//  Created by Christoph Rohde on 28.09.21.
//

#include <stdio.h>
#include <string>
using namespace std;

class Player {
    
public:
//  Member/ Attribute
    string m_playerName;
    char m_symbol;
    
    
//  Konstuktoren
    Player(){
    }
    
    Player(string playerName, char symbol){
        this->m_playerName = playerName;
        this->m_symbol = symbol;
    }
  
//  Destuktor (Nicht zu führ benutzen.)
    //~Player();
    
//  Klassen funktionen
};


