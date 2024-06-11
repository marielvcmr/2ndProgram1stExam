/* 1.- Eliminar del archivo todas las palabras que empiezan por un numero
   2.- Separar en dos archivos las palabras que empiezan por una vocal y una consonante*/

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std; 

int main(){

    ifstream inWords;    // open the file to get the input
    inWords.open("dataExamen2.csv", ios::in);

    if(!inWords.is_open()){
        cout<<"The requested file could not be open"<<endl;   // check whether the file is open
        return -1;
    }    

    string dataLine;    // contains a line of the file
    string wordsArray[100];   // saves the words of the file

    for(int i = 0; i <100; i++){              // saving the words in the array
        getline(inWords, dataLine); 
        wordsArray[i] = dataLine;
    }

    ofstream outNumbers;                                   // file with the words that doesn't start with a number
    outNumbers.open("wordsWithoutNumbers.txt", ios::out);

    for(int i = 0; i<100; i++){                   // Evaluates the word to write them on the output file outNumber
        if(!isdigit(wordsArray[i][0])){
            outNumbers<<wordsArray[i]<<endl;
        }
    }

    inWords.close();     // close the files 
    outNumbers.close();
    // END OF 1ST TASK


    ofstream vocalWords;    // creation of files that will contain the words that star by vocals
    ofstream consonantWords;    // and the words that start by consonants respectively 

    vocalWords.open("vocalWords.txt", ios::out);
    consonantWords.open("consonantWords.txt", ios::out);

    for(int i = 0; i<100; i++){       // Evaluates every word in the file to check whether to write it on a file or not 

        if(!isdigit(wordsArray[i][0])){            // Word starts with a letter
            if(tolower(wordsArray[i][0]) == 'a'){     // Evaluates whether word starts with a vocal
                vocalWords<<wordsArray[i]<<endl;
            }else if(tolower(wordsArray[i][0]) == 'e'){
                vocalWords<<wordsArray[i]<<endl;
            }else if(tolower(wordsArray[i][0]) == 'i'){
                vocalWords<<wordsArray[i]<<endl;
            }else if(tolower(wordsArray[i][0]) == 'o'){
                vocalWords<<wordsArray[i]<<endl;
            }else if(tolower(wordsArray[i][0]) == 'u'){
                vocalWords<<wordsArray[i]<<endl;
            }else{                                         //word starts with a consonant
                consonantWords<<wordsArray[i]<<endl;
            }
        }
    }
    vocalWords.close();          //close the output files 
    consonantWords.close();

    //END OF 2ND TASK
}