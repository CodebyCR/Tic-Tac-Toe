//
//  PLayer.cpp
//  Tic-Tac-Toe
//
//  Created by Christoph Rohde on 28.09.21.
//


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
    
    
    // Constructor for new Player
    Player() {

    }
    
    // Constuktoren for new Player
//    Player(string playerName, char symbol){
//        this->m_playerName = playerName;
//        this->m_symbol = symbol;
//        this->m_winCount = 0;
//    }
    
    //  Destuktor
    ~Player() = default;
    
    //  Klassen funktionen
    auto addWin() -> void {
        m_winCount ++;
        cout << "\nwin counter: " << m_winCount;
    }
    
    auto getWinCount() const -> int {
        return m_winCount;
    }


};



