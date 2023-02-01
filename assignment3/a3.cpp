// Rakib Shahid CSCI211 Section 22 
// Assignment 3
#include <iostream>
#include <string>
using namespace std;

// function to score current race
void scoreRace(string input){
    // arrays to score team total finishing positions and number of people on each team
    int score[26] = {};
    int people[26] = {};
    // variables to store number of teams and number of runners
    int teamCount = 0;
    int memberNum = 0;
    // variables to score the winning score and the index of the winning team
    int minScore = 0;
    int minScoreIndex = 0;

    // add all scores to arrays and count how many members in each team
    for (int i = 0; i < input.size(); i++){
        // convert character to ascii code to get array index
        int index = (int)(input[i] - 65);
        score[index] += i+1;
        people[index]++;
    }

    // verify team sizes and find winning team
    bool teamsSame = true;
    for (int i = 0; i < 26; i++){
        if (people[i] != 0){
            // initialize the counter for runner count
            if (memberNum == 0) memberNum = people[i];
            // set boolean to false if teams have different # of runners
            if (memberNum < people[i] || memberNum > people[i]) teamsSame = false;
            teamCount++;
        }
        if (score[i] != 0){
            // update minimum score if it is currently 0 or if a new minimum is found
            if ((minScore != 0 && (score[i] < minScore)) || minScore == 0){
                minScore = score[i];
                minScoreIndex = i;
            }
        }
    }

    // only print results if teams are of the same size
    if (teamsSame){
        cout << "There are " << teamCount << " teams.\n" << endl;
        cout << "Each team has " << memberNum << " runners.\n" << endl;
        cout << "Team\tScore" << endl;
        for (int i = 0; i < 26; i++){
            if (score[i] != 0){
                cout << ((char)(i+65)) << "\t"<<((double)score[i] / people[i]) << endl;
            }
        }
        cout << "\nThe winning team is team " << (char)(minScoreIndex+65) << " with a score of " << minScore/(double)memberNum << "." << endl;
    }
    // alert user of unequal teams
    else {
        cout << "Entered string has different number of runners on each team.\nTry again\n" << endl;
    }

    // input = "";

}

int main(){
    string input = "";

    // loop until user inputs "done"
    while (input != "done"){
        cin >> input;
        if (input != "done"){
            scoreRace(input);
        }
    }

    return 0;
}