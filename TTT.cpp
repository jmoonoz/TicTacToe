//
//  TTT.cpp
//  practice
//
//  Created by Joel munoz on 2/21/20.
//  Copyright © 2020 Joel Muñoz. All rights reserved.
//

#include "TTT.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(){
    // variables needed for the game
    char boardG[9] ={'0', '1', '2','3','4','5','6','7','8'};
    // names for players and p to hold it when swaping turns
    string player1, player2, p = "";
    // holds answer and turn marks
    char gameRun, m;
    // this will be used in the tenary condition
    int turn = 1;
    
    int win = -1;
    

    cout << "Would you like to play a game of Tic Tac Toe?\n";
    cout << "'Y' for yes, 'N' for no, then press enter. \n";
    cin.get(gameRun);

 
    // this is else loop will run depending on the answer inputed
    if (gameRun == 'Y' || gameRun == 'y') {
        cout << "enter name for player 1 : \n";
        cin >> player1;
        cout<< "enter name for player 2 : \n";
        cin >> player2;
        cout << "\n";
        // this will display players name and their mark
        cout << "Player 1: " << player1 << " is 'X' and player 2: "<< player2 << " is 'O' \n";
        cout << "\n";
        
        // this will go to function showboard, and display the board
        // lines 32 - 39
        showBoard(boardG);

        // this do/while loop will ensure the game runs untill its done
        // depending if win is changed from -1 to another number
        do {
            
            // figures out which players turn it is as well as which letter is theres
            // p holds players name, and m hold their board mark
            // this is call ternary condition
            p = (turn % 2) ? player1 : player2;
            m = (turn % 2) ? 'X' : 'O';
            
            // this is the funtion to go in and ask the player to add to a spot,
            // then try and add it
            // lines 84 - 109 in header page
            validMark(p, m, boardG);
            showBoard(boardG);
            
            
            // will return 0 if theres a winner, 1 if its a tie game
            // or stay at -1 if games not complete
            // lines 49 - 79 in header
            win = checkWin(boardG);
            // increment for next player
            turn++;
    
            
        } while (win == -1); // if -1 isnt return, means the game is done
        
        
        // if win equals 1, then it will display their name and results
        if (win == 1) {
            cout << "\n";
            cout << "Player " << p << " won!\n";
            showBoard(boardG);
            exit(1);
        } else {
            // means win was 0 and it returned
            cout << "Its a tie game\n";
            showBoard(boardG);
            exit(1);
        }
        
        

    } else if (gameRun == 'n' || gameRun =='N'){
        // this will only show if the player decides to not play the game
        cout << "Thanks, hasta Luego!" << endl;
        exit(1);
    }else{
        // if its not a valid input, this message will show
        cout << "Invalid input " << endl;
        cin.ignore();
        cin.get();
    }
    
    return 0;
}
