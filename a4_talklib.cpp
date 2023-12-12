
#include "a4_talklib.hpp"
#include "a4_talkList.hpp"

#define MAX_CHARS 300 // 300 chars at most in each line 

#define MAX_FILE_NAME 50 // file name at most 50 chars

#define SEARCH_CHARS 50 // look up talk at most 50 chars

#include <cstring> // to compare 2 string for sorting


Talk* createTalk(short hours, short minutes, short seconds, const string title, const string overview) {

    Talk* newTalk = new Talk;

    if (newTalk != nullptr) {
        newTalk ->hours = hours;
        newTalk ->minutes = minutes;
        newTalk->seconds  = seconds;

        // Allocate memory for title
        newTalk->title = title;
       
        // Allocate memory for overview
        newTalk->overview = overview;
    }
    return newTalk;
}

void deleteTalk(Talk* talk) {
    delete talk;
}

    
bool compareTalksByDuration(const Talk *p1, const Talk *p2) {
    long int totalsec1 = (p1->hours)*3600 + (p1->minutes)*60 + (p1->seconds);
    long int totalsec2 = (p2->hours)*3600 + (p2->minutes)*60 + (p2->seconds);
    return (totalsec1 < totalsec2);
}


bool compareTalksByTitle(const Talk *p1, const Talk *p2) {
    return strcmp(p1->title.c_str(), p2->title.c_str()) < 0;
}


void printTalk(const Talk* talk) {
        cout << talk->hours << "h" << talk->minutes << "m" << talk->seconds << "s" << endl;
        cout << talk->title << endl;
        cout << talk->overview << endl;
        cout << "---"<< endl;
    }

// Clear old Talk* if user loads different file
void clear(Talk* talk) {
    talk->hours = -1;
    talk->minutes = -1;
    talk->seconds = -1;
    talk->title.clear();
    talk->overview.clear();
}











