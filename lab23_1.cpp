#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}


void importDataFromFile(string filename,vector<string>& names, vector<int> &scores, vector<char> &grade){
    ifstream input(filename);
    string mytext;
    
    int score1,score2,score3;

    char format[] = "%[^:]: %d %d %d";
    while (getline(input, mytext)) {
        char name[100] = {};
        const char *linechar = mytext.c_str();
        sscanf(linechar,format,name,&score1,&score2,&score3);
        names.push_back(name);
        int totalscore = score1+score2+score3;
        scores.push_back(score1 + score2 + score3);
        grade.push_back(score2grade(totalscore));
        
        
      }
    }

void getCommand(string &command, string &key){
        cout << "Please input your command: "<<endl;
         string text;
        char command1[100] = {};
        char key1[100] = {};
        getline(cin , text);
        const char * ctext = text.c_str();
        char format[] = "%s %[^\n]";
        sscanf(ctext,format, command1,key1);
        command = command1;
        key = key1;

    }

    void searchName(vector<string> names,vector<int> scores,vector<char> grades,string name){
        bool found = true;
        cout << "---------------------------------" << endl;
        for(unsigned int i = 0; i < names.size(); i++){
            
            if(toUpperStr(names[i]) ==  name){
                cout << names[i]<< "'s score = " << scores[i]<<endl;
                cout << names[i]<< "'s grade = " << grades[i]<<endl;
                found = false;
            }
        }
        
       
        if(found)cout << "Cannot found."<<endl;
        cout << "---------------------------------"<< endl;
    
    
    
    
    }

    void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string grade){
        char ugrade = grade[0];
        bool found = true;
        cout << "---------------------------------" << endl;
            for(unsigned int i = 0; i < names.size(); i++){
    
                if(grades[i] == ugrade){
                    cout << names[i]<< " (" << scores[i] <<")" <<endl;
                    found = false;
                    
                }
                
            }
            
           if(found)cout << "Cannot found."<<endl;
            
            cout << "---------------------------------"<< endl;
        
        
        
        
        
        }


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
