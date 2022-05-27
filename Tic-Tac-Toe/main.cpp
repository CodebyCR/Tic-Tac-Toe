//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Christoph Rohde on 28.09.21.
//
//  Version 1.0.4

#include <stdio.h>
#include <iostream>
#include "Player.cpp"
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using mat3x3 = char[3][3];
// Create a list Iterator
vector <char> choiceList;
vector<string>::iterator it;

bool win = false;
bool playAgain;

int round = 0;

Player player1;
Player player2;


/*
 gibt den aktuellen Spieler zurück
 */
Player getCurrentPlayer()
{
    if (round % 2) {
        return player1;
    }
    return player2;
}

/*
 Print the interim Result.
 */
void interimResult(Player currentPlayer){
    cout << "\n --------------------------------------- \n";
    cout << "|\t Player 1 (" << player1.m_symbol << ")\t|\t Player 2 (" <<  player2.m_symbol << ")\t|\n";
    cout << "|\t\t " << player1.m_playerName << "\t\t|\t\t" <<  player2.m_playerName << "\t\t|\n";
    cout << "|\t\tRunde: " << round << "\t|\t" << currentPlayer.m_playerName << " ist dran.\t|\n";
    cout << " --------------------------------------- \n\n";
}

/*
 Aktualiesiert die Matrix und gibt sie zurück.
 */
mat3x3& updateMatrix( char sector, Player currentPlayer, mat3x3& matrix)
{
    switch (sector) {
        case '1':
            matrix [0][0] = currentPlayer.m_symbol;
            break;
        case '2':
            matrix [0][1] = currentPlayer.m_symbol;
            break;
        case '3':
            matrix [0][2] = currentPlayer.m_symbol;
            break;
            
        case '4':
            matrix [1][0] = currentPlayer.m_symbol;
            break;
        case '5':
            matrix [1][1] = currentPlayer.m_symbol;
            break;
        case '6':
            matrix [1][2] = currentPlayer.m_symbol;
            break;
            
        case '7':
            matrix [2][0] = currentPlayer.m_symbol;
            break;
        case '8':
            matrix [2][1] = currentPlayer.m_symbol;
            break;
        case '9':
            matrix [2][2] = currentPlayer.m_symbol;
            break;
            
            
        default:
            cout << "Ungültige Eingabe.\n";
            //            round-1?
            break;
            
    }
    return matrix;
}

/*
 Shows the matrix values for debuging
 */
void showMatrixValues(mat3x3& matrix){
    cout <<
    "\nLine 1"<<
    "\nmatrix[0][0]: " << matrix[0][0]<<
    "\nmatrix[0][1]: " << matrix[0][1]<<
    "\nmatrix[0][2]: " << matrix[0][2]<<
    
    "\nLine 2"<<
    "\nmatrix[1][0]: " << matrix[1][0]<<
    "\nmatrix[1][1]: " << matrix[1][1]<<
    "\nmatrix[1][2]: " << matrix[1][2]<<
    
    "\nLine 3"<<
    "\nmatrix[2][0]: " << matrix[2][0]<<
    "\nmatrix[2][1]: " << matrix[2][1]<<
    "\nmatrix[2][2]: " << matrix[2][2];
}

/*
 * Generic function to find if an element of any type exists in list
 */
template <typename T>
bool contains(std::vector<T> & vectorOfElements, const T & element)
{
    //https://thispointer.com/c-list-find-contains-how-to-search-an-element-in-stdlist/
    // Find the iterator if element in list
    auto it = std::find(vectorOfElements.begin(), vectorOfElements.end(), element);
    //return if iterator points to end or not. It points to end then it means element
    // does not exists in list
    return it != vectorOfElements.end();
}

/*
 Zeichnet das tic-tac-toe Feld
 */
void printField(mat3x3 matrix)
{
    for (int i = 0; i < 3; i++) {
        cout << "\t";
        for (int j = 0; j < 3; j++) {
            printf(" %c",  matrix[i][j] );
            if (j != 2) {
                cout << " |";
            }
        }
        if (i != 2) {
            cout << "\n\t-----------\n";
        }
    }
    printf("\n\n");
}

/*
 Prüft ob jemand gewonnen hat.
 */
char hasWon(mat3x3 matrix)
{
    //Hoizontal
    if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2])
    {
        return matrix[0][0];
    }
    if (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2])
    {
        return matrix[1][0];
    }
    if (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2])
    {
        return matrix[2][0];
    }
    
    //Vertikal
    if (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0])
    {
        return matrix[0][0];
    }
    if (matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1])
    {
        return matrix[0][1];
    }
    if (matrix[0][2] == matrix[1][2] && matrix[1][2]== matrix[2][2])
    {
        return matrix[0][2];
    }
    
    // Diagonal
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
    {
        return matrix[0][0];
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
    {
        return matrix[0][2];
    }
    
    //  cout << "Nobody wins.";
    return '0';
}

int main(int argc, char** argv) {
    
    // Player 1 Attribut belegung
    cout << "Player 1 gib deinen Namen ein.\n";
    cin >> player1.m_playerName;
    
    cout << "\n" << player1.m_playerName << " gib dein Symbol ein.\n";
    
    while (player1.m_symbol != 'x' && player1.m_symbol != 'o') {
        cout << "Bitte wähle 'x' oder 'o'.\n";
        cin >> player1.m_symbol;
    }
    
    
    // Player 2 Attribut belegung
    cout << "Player 2 gib deinen Namen ein.\n";
    cin >> player2.m_playerName;
    
    if(player1.m_symbol == 'x'){
        player2.m_symbol = 'o';
    } else{
        player2.m_symbol = 'x';
    }
    
    
    //    Spielbeginn
    do{
        //Initalisiere Matrix
        mat3x3 tttMatrix = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}};
        
        
        while (round < 9 && win == false) {
            ++round;
            
            //TODO: add Clean Consol methode
            //        cleanScreen();
            //        system("clear");
            system("clear");
            //        system("cls"); for windows
            
            Player currentPlayer = getCurrentPlayer();
            
            interimResult(currentPlayer);   // Zwischenstand
            printField(tttMatrix);          // Print matchfield
            
            char choice;
            cout << "Gib die Nummer ein, wo dein Symbol plaziert werden soll.\n";
            cin >>choice;
            
            try {
                if( contains(choiceList, choice) )
                {
                    cout << "\n\tSchon belegt.\n";
                    round --;
                }
                else{
                    choiceList.push_back(choice);
                    updateMatrix( choice, currentPlayer, tttMatrix);
                }
                
                if(round >= 5){
                    if(currentPlayer.m_symbol == hasWon(tttMatrix)){
                        cout <<
                        "\n\n ----------------------------------- \n"<<
                        "|\t\t" <<currentPlayer.m_playerName << " hat Gewonnen!!!\t\t|"<<
                        "\n ----------------------------------- \n\n";
                        currentPlayer.addWin();
                        cout << "win counter_1: " << currentPlayer.getWinCount(); //TODO:FIX
                        win = true;
                    }else if (round == 9){
                        cout <<
                        "\n\n ----------------------------------- \n"<<
                        "|\t\t\tUnendschieden\t\t\t|"<<
                        "\n ----------------------------------- \n\n";
                    }
                }
            } catch (std::exception e) {
                cout <<"error 0.1";
            }
            currentPlayer.addWin();
            cout << "\nwin counter_2: " << currentPlayer.getWinCount(); //TODO:FIX
            cout << "\nwin counter_2.1: " << player1.getWinCount(); //TODO:FIX
            cout << "\nwin counter_2.2: " << player2.getWinCount(); //TODO:FIX
        }
        cout << "\nwin counter_3.1: " << player1.getWinCount(); //TODO:FIX
        cout << "\nwin counter_3.2: " << player2.getWinCount(); //TODO:FIX
        
        cout << "\nMöchtet ihr noch eine Runde spielen? [ ja | nein ]\n";
        string nextRound;
        cin >> nextRound;
        
        if(nextRound == "ja" || nextRound == "Ja" || nextRound == "JA"){
            playAgain = true;
            round = 0;
            win = false;
            choiceList.clear();
        } else{
            playAgain = false;
            //TODO: Methode zur Statistik einsicht
            //TODO: methode zum player wechsel
        }
        
    }while(playAgain);
    
    cout<< player1.m_playerName << " hat " << player1.getWinCount() << " mal Gewonnen.\n";
    cout<< player2.m_playerName << " hat " << player2.getWinCount() << " mal Gewonnen.\n";
    
    return 0;
    
}
