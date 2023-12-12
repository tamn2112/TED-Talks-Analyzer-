
// Implement of TalkList class 

#include "a4_talkList.hpp"


TalkList::TalkList(){}

TalkList:: ~TalkList(){
    // going inside the vector
    // loop through vector
    // delete each Talk* inside 
    for (Talk* talk : talkEntries) {
        deleteTalk(talk);
        delete talk;
        talkEntries.clear();
    }
   
}

int TalkList::getSize(){
    return talkEntries.size();
}


void TalkList::listTalksByDuration(){
    sort(talkEntries.begin(), talkEntries.end(), compareTalksByDuration);
    for(int i=0;i<talkEntries.size();i++){
        printTalk(talkEntries[i]);
    }
}

void TalkList::listTalksByTitle(){
    sort(talkEntries.begin(), talkEntries.end(), compareTalksByTitle);
    for(int i=0;i<talkEntries.size();i++){
        printTalk(talkEntries[i]); 
    }
    
}

void TalkList:: insertTalk(short hours, short minutes, short seconds,const string title, const string overview){
    Talk* talk = createTalk(hours, minutes, seconds, title, overview);
    talkEntries.push_back(talk);
}

void TalkList::listTalksContainingTitle(const string keyTitle){
    bool found = false;

    for (Talk* talk: talkEntries){
        size_t position = talk->title.find(keyTitle);
        if (position != string::npos) {
            found = true;
            printTalk(talk);

        } 
    }
    if (!found) cout << "No such talk on record." << endl;
    
}


void TalkList::clearVector() {
    for (Talk* talk: talkEntries){
        clear(talk);
    }
    talkEntries.clear();
    
}

void TalkList:: printLastTalk() {
    cout << "You have entered: " << talkEntries.back()->hours << "h" << talkEntries.back()->minutes
    << "m" << talkEntries.back()->seconds << "s" << endl;
    cout << "Title: " << talkEntries.back()->title << endl;
    cout << "Overview: " << talkEntries.back()->overview << endl;
}


void TalkList::saveTalksToFile(const string& filename){
    ofstream outFile;
    outFile.open(filename);
    if (outFile.is_open()) {
        for(Talk* talk: talkEntries) {
            outFile << "**Duration:** " << talk->hours << " hour," << ' ' << 
            talk->minutes << " minutes," << ' ' << talk->seconds << " seconds" << endl;

            outFile << "**Talk Title:** " << '"' << talk->title << '"' << endl;
            outFile << "**Overview:** " << talk->overview << endl;
            outFile << "---" << endl;
            

            }
    }

    outFile.close();
}











