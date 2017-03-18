#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

#include "mp.h"

machine* createArray(int machineAmount);
void inputArray(int, machine*, ifstream&, int, string);
void sortArray(int, machine*);

int main(){
  ifstream machineFile;
  machine* machineArray;
  int amountOfParts = 21;
  int numWords=1;
  string line;

  machineFile.open("machine_parts.txt");



  machineArray = createArray(amountOfParts);
  inputArray(amountOfParts, machineArray, machineFile, numWords, line);
  sortArray(amountOfParts, machineArray);

}

machine* createArray(int machineAmount){
  machine* machineArray = new machine[machineAmount];
  return machineArray;
}

void inputArray(int amountOfParts, machine* machineArray, ifstream& machineFile, int numWords, string line){

  //Counts the words in a line
  while(getline(machineFile, line)){
    for(int i=0; i<100; i++){
      if(line[i]==' '){
        numWords++;
      }
    }
    if(numWords==2){
      for(int i=0; i<amountOfParts; i++){
        machineFile >> machineArray[i].machineNum >> machineArray[i].partName;
      }
    }
    if(numWords>=3){
      for(int i=0; i<amountOfParts; i++){
        machineFile >> machineArray[i].machineNum >> machineArray[i].partName >> machineArray[i].partDep;
      }
    }
    numWords = 1;
  };
}

void sortArray(int amountOfParts, machine* machineArray){
  cout << "Machine 1..." << endl;
  for(int i=0; i<amountOfParts; i++){
    if(machineArray[i].machineNum==1){
      cout << machineArray[i].partName << ", with a dependency of " << machineArray[i].partDep << endl;
    }
  }

  cout << endl << "Machine 2..." << endl;
  for(int i=0; i<amountOfParts; i++){
    if(machineArray[i].machineNum==2){
      cout << machineArray[i].partName << ", with a dependency of " << machineArray[i].partDep << endl;
    }
  }

  cout << endl << "Machine 3..." << endl;
  for(int i=0; i<amountOfParts; i++){
    if(machineArray[i].machineNum==3){
      cout << machineArray[i].partName << ", with a dependency of " << machineArray[i].partDep << endl;
    }
  }
}
