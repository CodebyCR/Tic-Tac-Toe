//
//  Statistic.cpp
//  Tic-Tac-Toe
//
//  Created by Christoph Rohde on 13.02.22.
//

#include <stdio.h>
#include <fstream>
#include <filesystem>
#include "Player.cpp"

using std::string;
namespace fs = std::__fs::filesystem;


//TODO: create and modify statistics.

/*
 read the file and return the input of the file.
 */
string getFileText(string path){
    string line;
    string text;
    
    std::ifstream file;
    file.open(path); // Parentpath
    
    if(file.is_open()){
        while(std::getline(file, line))
        {
            text += line + "\n";
        }
    }
    
    file.close();
    
    return text;
}

void updateStatistic(Player one, Player two){
    
    // falls geladene spieler, attribute updaten
    // vector von spielern nach anzahl gewinnen sortiern
    // über eine schleife alle spielerdaten von max-min gewinnen in die statistick schreiben

}

void placeholder(){
    fs::path thisFilePath = fs::current_path();
    
    string str = getFileText(thisFilePath.parent_path());
    
    
}





