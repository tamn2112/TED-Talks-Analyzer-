// User Interface Implement 

#include "a4_talkList.hpp"

#define MAX_FILE_NAME 50 // file name at most 50 chars

using namespace std;

// Load file from user
ifstream loadFile(const string& file_name) {
    ifstream file;
    file.open(file_name, ifstream::in);
    if (!file.is_open()) {
        return ifstream();
    }

    return file;
}

int main() {

    // Display banner
    printf("============================================================\n");
    printf("====================== Welcome! ============================\n");
    printf("=================== CS Talks Lists =========================\n");
    printf("====================== Tam Nguyen ==========================\n");
    printf("====================== ttn47@sfu.ca ========================\n");
    printf("============================================================\n");


    int option;
    
    // Make a pointer to TalkList
    TalkList* talkEntries = new TalkList; 

    // to check if a file is being loaded
    bool file_load = false;

    do {
        cout << "Press number 1-7 for the following option and then enter: \n"
             << "1) to load a talk file.\n"
             << "2) to list talks sorted by duration.\n"
             << "3) to list talks sorted by title.\n"
             << "4) to look up a talk.\n"
             << "5) to add a talk.\n"
             << "6) to save talks to a file.\n"
             << "7) to terminate the program.\n"
             << "Option: ";
        cin >> option;


    switch(option)
    {
        case 1: {

            string filename;
            cout <<"Enter the full name of the talks file(with extension): ";
            cin >> filename;

            if(file_load) {
                talkEntries->clearVector();
            }

            ifstream loadedFile = loadFile(filename); 
            file_load = true;

            string title;
            string overview;
            string buffer;

            string Strhours;
            string Strseconds;
            string Strminutes;
    
            while(!loadedFile.eof()) {
            // Successful
                getline(loadedFile, buffer, ' ');
                if(buffer == ""){
                    break;
                }
                getline(loadedFile, Strhours, ' ');
                //cout << endl;
                //cout << Strhours << endl;

                getline(loadedFile, buffer, ' ');
                getline(loadedFile, Strminutes, ' ');
                //cout << Strminutes << endl;

                getline(loadedFile, buffer, ' ');
                getline(loadedFile, Strseconds, ' ');
                //cout << Strseconds << endl;
                getline(loadedFile, buffer);

                //using stoi to conver hours back to int
                short hours = stoi(Strhours);
                
            
                //using stoi to conver minutes back to int
                short minutes = stoi(Strminutes);
                


                //using stoi to convert seconds back to int
                short seconds = stoi(Strseconds);

                // Extract info for title
                // Successful!
                getline(loadedFile, buffer, '"');
                getline(loadedFile, title, '"');
                //cout << title << endl;
                getline(loadedFile, buffer);
        
        
                // Extract info for overview
                // Successful!
                getline(loadedFile, buffer, ' ');
                getline(loadedFile, overview);
                //cout << overview << endl;
                getline(loadedFile, buffer);

                talkEntries->insertTalk(hours, minutes, seconds, title, overview);
            
            }
            
            int numEntries = talkEntries->getSize();
            cout << numEntries << " entries read." << endl;
            loadedFile.close();
            break;
                
            }

    
        case 2: {
            // Successful
            if (!file_load) {
                cout << "No talks file loaded. Load one first" << endl;
            } else {
                talkEntries->listTalksByDuration();
            }
            break;
        }
        case 3: {
            // Successful
            if(!file_load) {
                cout << "No talks file loaded. Load one first" << endl;

            } else {
                talkEntries->listTalksByTitle();
            }
            break;
        }
        case 4: {
            // Successful
            if(!file_load) {
                cout << "No talks file loaded. Load one first" << endl;

            } else {
                string substring;
                cout << "What is the title of the talk, enter in part or as a whole (50 character max.)? ";
                cin.ignore();
                getline(cin, substring);

                cout << substring << endl;
                talkEntries->listTalksContainingTitle(substring);
                
            }
    
            break;
        }
        case 5: {
            // Successful
            if(!file_load) {
                cout << "No talks file loaded. Load one first" << endl;

            } else {
                short newHours, newMinutes, newSeconds;
                string newTitle, newOverview;
                while(true) {
                cout << "What is the number of hours? (input 0 or more and press enter)? ";
                cin >> newHours;
                if(newHours < 0) {
                    cout << "Invalid input. Please enter a valid one." << endl;
                    cin.clear();
                } else {
                    break;
                }
            }
                while (true) {
                cout << "What is the number of minutes? (input 0-59 and press enter)? ";
                cin >> newMinutes;
                if(newMinutes < 0 || newMinutes > 59) {
                    cout << "Invalid input. Please enter a valid one." << endl;
                    cin.clear();
                } else {
                    break;
                }
            }
                while(true) {
                cout << "What is the number of seconds? (input 0-59 and press enter)? ";
                cin >> newSeconds;
                if(newSeconds < 0 || newSeconds> 59) {
                    cout << "Invalid input. Please enter a valid one." << endl;
                    cin.clear();
                } else {
                    break;
                }
            }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "What is the title of the talk? ";
                getline(cin, newTitle);

                cout << "What is the overview of the talk? ";
                getline(cin, newOverview);

                talkEntries->insertTalk(newHours, newMinutes, newSeconds, newTitle, newOverview);

                talkEntries->printLastTalk();

                cout << "Entry added." << endl;

            }

            
            break;
        }

        case 6: {
            // Successful
            if(!file_load) {
                cout << "No talks file loaded. Load one first" << endl;

            } else { 
                string outFile;
                cout << "Enter the full name of the save file (with extension): ";
                cin >> outFile;
                talkEntries->saveTalksToFile(outFile);
                int numEntries = talkEntries->getSize();
                cout << numEntries << " entries read." << endl;
            }
            
            break;
        }

        case 7: {
            // Successful
            cout << "Thank you for using our program!" << endl;
            talkEntries->clearVector();
            talkEntries->~TalkList();
            break;   
        }
        default:
            cout << "Invalid input. Please choose option from 1 to 7." << endl;
            break;

    }

    } while(option!=7);

    return 0;
}










