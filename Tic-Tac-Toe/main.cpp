//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Christoph Rohde on 28.09.21.
//
//  Version 1.0.5


#include <iostream>
#include "Player.cpp"
#include <vector>




using mat3x3 = char[3][3];
std::vector<char> choiceList;


bool win = false;
bool playAgain;

int raw_round = 0;
int &round = raw_round;

Player player1;
Player player2;


/**
 * return the current player.
 **/
static auto getCurrentPlayer(int round) -> Player {

    if (round % 2) {
        return player1;
    }
    return player2;
}


/*
 Print the interim Result.
 */
void interimResult( Player &currentPlayer) {

    std::cout
    << "\n --------------------------------------- \n"
    << "|\t Player 1 (" << player1.m_symbol << ")\t|\t Player 2 (" <<  player2.m_symbol << ")\t|\n"
    << "|\t\t " << player1.m_playerName << "\t\t|\t\t" <<  player2.m_playerName << "\t\t|\n"
    << "|\t\tRound: " << round << "\t|\t" << currentPlayer.m_playerName << "'s turn.\t|\n"
    << " --------------------------------------- \n\n";
}

/**
 * update the Matrix.
 **/
void updateMatrix( char sector, Player &currentPlayer, mat3x3 &matrix) {
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
            std::cout << "Invalid input.\n";
            //            round-1?
            break;
    }
}

/*
 Shows the matrix values for debugging
 */
void showMatrixValues(mat3x3 &matrix) {
    std::cout <<
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
bool contains(std::vector<T> &vectorOfElements, const T &element) {
    auto it = std::find(vectorOfElements.begin(), vectorOfElements.end(), element);
    return it != vectorOfElements.end();
}

/**
 * Print the Tic-Tac-Toe field.
 **/
void printField(mat3x3 &matrix)
{
    for (int i = 0; i < 3; i++) {
        std::cout << "\t";
        for (int j = 0; j < 3; j++) {
            printf(" %c",  matrix[i][j] );
            if (j != 2) {
                std::cout << " |";
            }
        }
        
        if (i != 2) {
            std::cout << "\n\t-----------\n";
        }
    }
    printf("\n\n");
}

/**
 * Checked if someone has won.
 **/
char hasWon(mat3x3 &matrix)
{
    // Horizontal
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
    
    // Vertical
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

int main() {

    /*
     * using main Parameter for load statistic.txt,
     * if it exists.
     */
    
    
    // set Player 1 Attribute
    std::cout << "Player 1, please enter your name.\n";
    std::cin >> player1.m_playerName;

    std::cout << "\n" << player1.m_playerName << " choose your symbol.\n";
    
    while ( !(player1.m_symbol == 'x' || player1.m_symbol == 'o') ) {
        std::cout << "Please choose 'x' or 'o'.\n";
        std::cin >> player1.m_symbol;
    }
    
    
    // set Player 2 Attribute
    std::cout << "Player 2, please enter your name.\n";
    std::cin >> player2.m_playerName;
    
    if(player1.m_symbol == 'x') {
        player2.m_symbol = 'o';

    } else{
        player2.m_symbol = 'x';
    }
    
    
    // Start the game
    do{
        // initialise the Matrix
        mat3x3 tttMatrix = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}};
        
        
        while (round < 9 && !win) {
            ++round;
            
            // TODO: add Clean Console methode
            // cleanScreen();
            // system("clear");

            // system("cls"); for windows
            
            Player currentPlayer = getCurrentPlayer(round);
            
            interimResult(currentPlayer);
            printField(tttMatrix);
            
            char choice;
            std::cout << "Enter the number, where your symbol should be placed.\n";
            std::cin >>choice;
            
            try {
                if( contains(choiceList, choice) ) {
                    std::cout << "\n\tCell occupied.\n";
                    round --;
                } else {
                    choiceList.push_back(choice);
                    updateMatrix( choice, currentPlayer, tttMatrix);
                }
                
                if(round >= 5){
                    if(currentPlayer.m_symbol == hasWon(tttMatrix)){
                        std::cout
                                << "\n\n ----------------------------------- \n"
                                << "|\t\t" <<currentPlayer.m_playerName << " wins!!!\t\t|"
                                << "\n ----------------------------------- \n\n";
                        currentPlayer.addWin();
                        win = true;

                    }else if (round == 9){
                        std::cout
                                << "\n\n ----------------------------------- \n"
                                << "|\t\t\tundecided\t\t\t|"
                                << "\n ----------------------------------- \n\n";
                    }
                }
            } catch (std::exception &exception) {
                std::cout << "error 0.1\t" << exception.what();
            }
            currentPlayer.addWin();
        }


        std::cout << "\nDo you want to play a next round? [ yes | no ]\n";
        string nextRound;
        std::cin >> nextRound;


        std::vector<std::string> yes = {"ja", "j", "y", "yes", "Ja", "JA", "J", "Y", "Yes", "YES"};
        if(contains(yes, nextRound)){
            playAgain = true;
            round = 0;
            win = false;
            choiceList.clear();

        } else{
            playAgain = false;
            //TODO: Methode zur Statistik einsicht
            //TODO: methode zum player wechsel
        }
        
    } while(playAgain);
    
    return 0;
}
