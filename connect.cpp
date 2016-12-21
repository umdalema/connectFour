/*
    Dale Mallette
    December 12th, 2016
    Personal project: just a simple little texted based c++ game.
*/

#include <iostream>
#include <vector>
#include <string> 
#include <getopt.h>
using namespace std;

void printHelpInfo();

int main(int argc, char* argv[]){
    
    static struct option longOpts[] = {
        {"mode", argument_optional, nullptr, 'm'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}
    } // longOpts
    
    int option, index;
    int mode;
    
    while ((option = getopt_long(argc, argv, "m:h", longOpts, &index)) != -1){
        switch (option) {
            case 'm':
                mode = atoi(tolower(optarg));
                break;
            case 'h':
                printHelpInfo();
                exit(0);
            default:
                cerr << "You've provide an un-recognized flag." << endl;
                printHelpInfo();
                exit(1);
        } // switch
    } // while getopt_long
    
    switch (mode) {
        case 's':
            // run simple mode with 2 human players on a 6x7 board.
            break;
            
        default:
            cout << "Invalid mode selected!";
            printHelpInfo(); 
            break;
    }
    
    
    return 0;
} // main()

void printHelpInfo(){
    
    cout << "Text based connect 4 varient:\n";
    cout << "Discalimer: I do not own any rights to this game!!\n";
    cout << "\n";
    cout << "USAGE:\n";
    cout << "-h, --help: get helpful information about the game\n"
    cout << "-m, --mode <MODE>: MODE is optional. If unspecified will default to SIMPLE.\n";
    cout << "MODE option:\n";
    cout << "   S: simple mode. two players will vs eachother on a standard 6x7 board.\n"
    
    return;
}











