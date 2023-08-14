#include "commons.h"

// The main function takes the number of input arguments and their values as input
int main(int inputArgCnt, char** inputArgVal) {
    
    if(2 != inputArgCnt) {
        std::cout<<"Invalid number of arguments. Refer to the format below:"<<std::endl;
        std::cout<<"./[PROGRAM NAME] [BOARD POSITIONS]"<<std::endl;
        return RETURN_FAILURE;
    }

    std::string board = inputArgVal[1];

    // Print board
    printBoard(board);
    
    // Return success
    return RETURN_SUCCESS;
}