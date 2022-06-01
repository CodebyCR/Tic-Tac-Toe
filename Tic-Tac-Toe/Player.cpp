//
//  PLayer.cpp
//  Tic-Tac-Toe
//
//  Created by Christoph Rohde on 28.09.21.
//

#include <stdio.h>
#include <iostream>
#include <string>
using std::string;
using std::cout;

class Player {
    
private:
    int m_winCount;
    
public:
    // Member / Attribute
    string m_playerName;
    char m_symbol;
    
    
    // Constuktoren for new Player
    Player(){
    }
    
    // Constuktoren for new Player
    Player(string playerName, char symbol){
        this->m_playerName = playerName;
        this->m_symbol = symbol;
        this->m_winCount = 0;
    }
    
    //  Destuktor
    ~Player(){};
    
    //  Klassen funktionen
    void addWin()
    {
        m_winCount ++;
        cout << "\nwin counter: " << m_winCount;
    }
    
    int getWinCount(){
        return m_winCount;
    }
    
};


