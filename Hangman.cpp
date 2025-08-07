#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> HANGMANPICS = {
    R"(  
  +---+
  |   |
      |
      |
      |
      |
=========
)",

    R"(  
  +---+
  |   |
  O   |
      |
      |
      |
=========
)",

    R"(  
  +---+
  |   |
  O   |
  |   |
      |
      |
=========
)",

    R"(  
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========
)",

    R"(  
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
)",

    R"(  
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
)",

    R"(  
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
)"
};
void DrawGallow(int Mistakes){
  cout<<HANGMANPICS[Mistakes]<<endl;
}

int main(){
  int Mistakes=0;
  bool isGuessed=false;
  string word;
  cout<<"HANGMAN"<<endl;
  cout<<"Input word: "<<endl;
  cin>>word;
  //guessing
  string hidden = string(word.length(), '_');
  while(!isGuessed && Mistakes<6){
    if(hidden.find('_')==string::npos){
      isGuessed=true;
    }
    cout<<hidden<<endl;
    DrawGallow(Mistakes);
    char letter;
    cout<<"write a letter"<<endl;
    cin>>letter;
    size_t found= word.find(letter);
    if(found!=string::npos) {
      cout<<"nice!"<<endl;
      for(size_t i= 0; i<word.length();++i){
        if(word[i]==letter){
          hidden.replace(i,1,1,letter);
        }
      }
    }
    else{
      Mistakes++;

    }
    

  }
  if (Mistakes>=6)
  {
cout<<"you died... game over!"<<endl;  }
else if(isGuessed){
cout<<"congrats the word is "<<word<<endl;
}
  
  return 0;
}
