// This line includes the header file "commons.h" which contains the necessary declarations and definitions for the program.
#include "commons.h"

// The main function takes the number of arguments passed and the values of those arguments as input.
int main(int inputArgCnt, char** inputArgVal) {

    // An object of the initializeGame class is created and the arguments are passed to it.
    initializeGame game(inputArgCnt, inputArgVal);

    // The startGame method is called on the game object to initialize the game.
    if(game.startGame() == RETURN_FAILURE) {
        return RETURN_FAILURE;
    }

    // Game related logic starts here
    // The applyMinMaxOpeningAlgorithmImproved function is called with the appropriate arguments.
    // It returns the bestBoardData of type boardData, which is a struct containing information about the best board position,
    // the number of positions evaluated by static estimation and the MINIMAX estimate.
    boardData bestBoardData = applyMinMaxOpeningAlgorithmImproved(game.inputMoves, game.depth, MAXIMIZING);

    // The required data is printed on the console.
    std::cout<<"Board Position: "<<bestBoardData.bestBoard<<std::endl;
    std::cout<<"Positions evaluated by static estimation: "<<bestBoardData.staticEstimation<<"."<<std::endl;
    std::cout<<"MINIMAX estimate: "<<bestBoardData.minMaxEstimation<<"."<<std::endl;

    // The writeMoves function is called to write the best board position to the output file.
    writeMoves(game.outputFileHandler, bestBoardData.bestBoard);

    // The function returns a success code.
    return RETURN_SUCCESS;
}