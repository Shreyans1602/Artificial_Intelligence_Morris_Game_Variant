#include"commons.h"

// The main function of the program
int main(int inputArgCnt, char** inputArgVal) {
    // Create an instance of the initializeGame class and pass in the command line arguments
    initializeGame game(inputArgCnt, inputArgVal);

    // Start the game by initializing the board and players
    if(game.startGame() == RETURN_FAILURE) {
        return RETURN_FAILURE;
    }

    // Apply the Minimax algorithm to determine the best move to make based on the current board state
    boardData bestBoardData = applyMinMaxOpeningAlgorithm(game.inputMoves, game.depth, MAXIMIZING, BLACK);

    // Print the required data to the console
    std::cout<<"Board Position: "<<bestBoardData.bestBoard<<std::endl;
    std::cout<<"Positions evaluated by static estimation: "<<bestBoardData.staticEstimation<<"."<<std::endl;
    std::cout<<"MINIMAX estimate: "<<bestBoardData.minMaxEstimation<<"."<<std::endl;

    // Write the best move to the output file
    writeMoves(game.outputFileHandler, bestBoardData.bestBoard);

    // Return success status to the operating system
    return RETURN_SUCCESS;
}