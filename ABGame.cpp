#include "commons.h"

// Main function that accepts command line arguments and starts the game
int main(int inputArgCnt, char** inputArgVal) {
    
    // Create an object of the initializeGame class and pass the input arguments
    initializeGame game(inputArgCnt, inputArgVal);

    // Call the startGame method to initialize the game with input arguments
    if(game.startGame() == RETURN_FAILURE) {
        return RETURN_FAILURE;
    }

    // Start the game-related logic by initializing alpha and beta values
    int alpha = -2147483648; // the smallest possible integer
    int beta = 2147483647;   // the largest possible integer

    // Call the applyABGameAlgorithm function to apply the alpha-beta pruning algorithm to the game
    // The function returns the best board data after applying the algorithm
    boardData bestBoardData = applyABGameAlgorithm(game.inputMoves, game.depth, alpha, beta, MAXIMIZING);

    // Print the required data obtained from the algorithm
    std::cout << "Board Position: " << bestBoardData.bestBoard << std::endl;
    std::cout << "Positions evaluated by static estimation: " << bestBoardData.staticEstimation << "." << std::endl;
    std::cout << "AB estimate: " << bestBoardData.minMaxEstimation << "." << std::endl;

    // Write the best board data to the output file
    writeMoves(game.outputFileHandler, bestBoardData.bestBoard);

    // Return 0 to indicate successful program execution
    return RETURN_SUCCESS;
}