#include"commons.h"

// The main function takes the number of input arguments and the values of those arguments
int main(int inputArgCnt, char** inputArgVal) {
    // Initialize the game with the input arguments
    initializeGame game(inputArgCnt, inputArgVal);
    // Start the game
    if(game.startGame() == RETURN_FAILURE) {
        return RETURN_FAILURE;
    }

    // Game related logic starts here
    // Initialize alpha-beta pruning variables
    int alpha = -2147483648; // Set alpha to the minimum possible value of an integer
    int beta = 2147483647; // Set beta to the maximum possible value of an integer
    
    // Apply alpha-beta pruning algorithm to find the best board position
    boardData bestBoardData = applyABOpeningAlgorithm(game.inputMoves, game.depth, alpha, beta, MAXIMIZING);

    // Print the required data
    // Print the best board position found by the algorithm
    std::cout<<"Board Position: "<<bestBoardData.bestBoard<<std::endl;
    // Print the number of positions evaluated by the static estimation function
    std::cout<<"Positions evaluated by static estimation: "<<bestBoardData.staticEstimation<<"."<<std::endl;
    // Print the AB estimate
    std::cout<<"AB estimate: "<<bestBoardData.minMaxEstimation<<"."<<std::endl;

    // Write move to the output file
    // Write the best board position found by the algorithm to the output file
    writeMoves(game.outputFileHandler, bestBoardData.bestBoard);

    // Return success
    return RETURN_SUCCESS;
}