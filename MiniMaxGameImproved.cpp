#include "commons.h"

int main(int inputArgCnt, char** inputArgVal) { // main function with input arguments count and values
    initializeGame game(inputArgCnt, inputArgVal); // create an instance of the initializeGame class
    // Start the game
    if(game.startGame() == RETURN_FAILURE) {
        return RETURN_FAILURE;
    }

    // Game related logic starts here
    boardData bestBoardData = applyMinMaxGameAlgorithmImproved(game.inputMoves, game.depth, MAXIMIZING); // apply the improved Minimax algorithm to get the best move

    // Print the required data
    std::cout<<"Board Position: "<<bestBoardData.bestBoard<<std::endl; // print the best board position
    std::cout<<"Positions evaluated by static estimation: "<<bestBoardData.staticEstimation<<"."<<std::endl; // print the number of board positions evaluated by the static estimation function
    std::cout<<"MINIMAX estimate: "<<bestBoardData.minMaxEstimation<<"."<<std::endl; // print the Minimax estimate for the best move

    // Write move to the output file
    writeMoves(game.outputFileHandler, bestBoardData.bestBoard); // write the best move to the output file

    return RETURN_SUCCESS; // return success code
}