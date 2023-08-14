#include "commons.h"

int main(int inputArgCnt, char** inputArgVal) {
    // Initialize the game with the command-line arguments
    initializeGame game(inputArgCnt, inputArgVal);

    // Start the game
    if(game.startGame() == RETURN_FAILURE) {
        return RETURN_FAILURE;
    }

    // Run the Minimax algorithm with opening moves and get the best board position
    boardData bestBoardData = applyMinMaxOpeningAlgorithm(game.inputMoves, game.depth, MAXIMIZING, WHITE);

    // Print the required data
    std::cout << "Board Position: " << bestBoardData.bestBoard << std::endl;
    std::cout << "Positions evaluated by static estimation: " << bestBoardData.staticEstimation << "." << std::endl;
    std::cout << "MINIMAX estimate: " << bestBoardData.minMaxEstimation << "." << std::endl;

    // Write the best move to the output file
    writeMoves(game.outputFileHandler, bestBoardData.bestBoard);

    // Return success status
    return RETURN_SUCCESS;
}