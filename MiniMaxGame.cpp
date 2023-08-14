#include "commons.h"

// The main function takes the number of input arguments and their values as input
int main(int inputArgCnt, char** inputArgVal) {
    // Create a game object and initialize it using the input arguments
    initializeGame game(inputArgCnt, inputArgVal);
    // Start the game
    if(game.startGame() == RETURN_FAILURE) {
        return RETURN_FAILURE;
    }

    // Apply the Minimax algorithm to find the best board position
    boardData bestBoardData = applyMinMaxGameAlgorithm(game.inputMoves, game.depth, MAXIMIZING, WHITE);

    // Print the required data
    std::cout << "Board Position: " << bestBoardData.bestBoard << std::endl;
    std::cout << "Positions evaluated by static estimation: " << bestBoardData.staticEstimation << "." << std::endl;
    std::cout << "MINIMAX estimate: " << bestBoardData.minMaxEstimation << "." << std::endl;

    // Write the best board position to the output file
    writeMoves(game.outputFileHandler, bestBoardData.bestBoard);

    // Return success
    return RETURN_SUCCESS;
}