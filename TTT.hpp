//
//  TTT.hpp
//  practice
//
//  Created by Joel munoz on 2/21/20.
//  Copyright © 2020 Joel Muñoz. All rights reserved.
//

// this is the header page,
// seperate page from the main.
// holds the funcitons for the tic tac toe game

#ifndef TTT_hpp
#define TTT_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

string intro(string, string);
void showBoard(char);
void validMark(string, char, char);
void showBoard(char);
int checkWin(char);
bool startGame(char);




void showBoard(char b[]){
    int sw = 15;
    cout << setw(sw) << b[0] << " | " << b[1] << " | " << b[2] << endl;
  
    cout << setw(sw) << b[3] << " | " << b[4] << " | " << b[5] << endl;
   // cout << "---   ---   ---\n";
    cout << setw(sw) << b[6] << " | " << b[7] << " | " << b[8] << endl;
    cout << "\n";
}

int checkWin(char b[]){
    
    // if winning line is found, it will return 1
    // if no one won, then it will return 0
    // if its not a tie or no one won, it will return -1
    // which will keep the game runing
    
    if (b[0] == b[1] && b[1] == b[2]) {
        return 1;
    }
    else if (b[3] == b[4] && b[4] == b[5]) {
        return 1;
    }
    else if (b[6] == b[7] && b[7] == b[8]) {
        return 1;
    }
    else if (b[0] == b[3] && b[3] == b[6]) {
        return 1;
    }
    else if (b[1] == b[4] && b[4] == b[7]) {
        return 1;
    }
    else if (b[2] == b[5] && b[5] == b[8]) {
        return 1;
    }
    else if (b[0] == b[4] && b[4] == b[8]) {
        return 1;
    }
    else if (b[6] == b[4] && b[4] == b[2]) {
        return 1;
    }
    else if (b[0] != '0' && b[1] != '1' && b[2] != '2' &&
             b[3] != '3' && b[4] != '4' && b[5] != '5' &&
             b[6] != '6' && b[7] != '7' && b[8] != '8'){
        return 0;
    }
    else
        return -1;
}


// p = placement and b[] is the board being passed
void validMark(string player, char mark, char bg[]){
    // hold the integer for board placement
    int p;
    
    // gets placement location from player to add to
    // the board, p will show which players turn it is
    cout << player << " pick a number placement: \n";
    cin >> p;
    
    // this first if loop will check to see if it is within the board
    // if its not, it will recursivly run back
    if (p < 0 || p > 8){
        cout << "\n";
        cout << "This is not on the board \n";
        cout << "\n";
        validMark(player, mark, bg);
        
    }else{
        // this second if else loop will check to see if the location isnt already take
        if(bg[p] == 'X' || bg[p] == 'O'){
            cout << "this spot is already taken, try again \n";
            validMark(player, mark, bg);
        }
        else
            bg[p] = mark;
        // end of if else loop
    }
    
}

#endif /* TTT_hpp */

