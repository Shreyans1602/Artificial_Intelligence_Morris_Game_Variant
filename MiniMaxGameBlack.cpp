#include "commons.h"

int main(int inputArgCnt, char** inputArgVal) { // Main function takes input arguments as parameters
    initializeGame game(inputArgCnt, inputArgVal); // Create an object of the initializeGame class with the input arguments
    // Call the startGame function of the initializeGame class
    if(game.startGame() == RETURN_FAILURE) {
        return RETURN_FAILURE;
    }

    // Game related logic starts here
    boardData bestBoardData = applyMinMaxGameAlgorithm(game.inputMoves, game.depth, MAXIMIZING, BLACK); // Call the applyMinMaxGameAlgorithm function with input moves, depth, maximizing player, and current player to get the best board data

    // Print the required data
    std::cout << "Board Position: " << bestBoardData.bestBoard << std::endl; // Print the best board position
    std::cout << "Positions evaluated by static estimation: " << bestBoardData.staticEstimation << "." << std::endl; // Print the number of positions evaluated by static estimation
    std::cout << "MINIMAX estimate: " << bestBoardData.minMaxEstimation << "." << std::endl; // Print the MINIMAX estimate

    // Write move to the output file
    writeMoves(game.outputFileHandler, bestBoardData.bestBoard); // Call the writeMoves function with output file handler and best board data to write the move to the output file

    return RETURN_SUCCESS; // Return success code
}