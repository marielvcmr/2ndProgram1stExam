/*1.- Contar la cantidad de personas por genero y mostrar su proporcion en la poblacion
  2.- Separar en diferentes archivos a las personas por su localidad
  3.- Mostrar cuantas personas hay por localidad que sean hombres y mujeres*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std; 

struct persona{
    string id;
    string firstName;
    string email; 
    string gender; 
    string location; 
    string finalNote; 
};

int main(){

    //open file

    ifstream inPeople; 
    inPeople.open("dataExamen.csv", ios::in);

    if(!inPeople.is_open()){
        cout<<"The requested file could not be open"<<endl;
        return -1;
    }
    
    string id;
    string firstName; 
    string email; 
    string gender; 
    string location; 
    string finalNote; 

    string dataLine; 

    persona perArray[1000]; 

    getline(inPeople, dataLine); 

    for(int i = 0; i <1000; i++){

        getline(inPeople, dataLine); 
        stringstream s(dataLine);

        getline(s, id, ',');
        getline(s, firstName, ',');
        getline(s, email, ',');
        getline(s, gender, ',');
        getline(s, location, ',');
        getline(s, finalNote, ',');

        persona addPersona = {id, firstName, email, gender, location, finalNote};

        perArray[i] = addPersona;
    }

    int nbinary = 0, transgender = 0, female= 0, agender = 0, male = 0;

    for(int i = 0; i<1000; i++){
        if(perArray[i].gender == "non-binary"){
            nbinary += 1; 
        }else if (perArray[i].gender == "transgender"){
            transgender += 1; 
        }else if (perArray[i].gender == "female"){
            female += 1; 
        }else if (perArray[i].gender == "agender"){
            agender += 1; 
        }else if (perArray[i].gender == "male"){
            male += 1; 
        }
    }

    cout <<"Non-binary: "<<nbinary<<", %: "<<nbinary/10.0<<endl;
    cout <<"Transgender: "<<transgender<<", %: "<<transgender/10.0<<endl;
    cout <<"Female: "<<female<<", %: "<<female/10.0<<endl;
    cout <<"Agender: "<<agender<<", %: "<<agender/10.0<<endl;
    cout <<"Male: "<<male<<", %: "<<male/10.0<<endl;

    // end of 1st Task 

    ofstream peopleAfr;
    ofstream peopleEur;
    ofstream peopleAsia;
    ofstream peopleAmer;
    ofstream peopleOcean;

    peopleAfr.open("peopleAfr.csv", ios::out);
    peopleEur.open("peopleEur.csv", ios::out);
    peopleAsia.open("peopleAsia.csv", ios::out);
    peopleAmer.open("peopleAmer.csv", ios::out);
    peopleOcean.open("peopleOcean.csv", ios::out);

    if(!peopleAfr.is_open()){
        cout<<"The requested file could not be created"<<endl;
        return -1;
    }

    if(!peopleEur.is_open()){
        cout<<"The requested file could not be created"<<endl;
        return -1;
    }

    if(!peopleAsia.is_open()){
        cout<<"The requested file could not be created"<<endl;
        return -1;
    }

    if(!peopleAmer.is_open()){
        cout<<"The requested file could not be created"<<endl;
        return -1;
    }

    if(!peopleOcean.is_open()){
        cout<<"The requested file could not be created"<<endl;
        return -1;
    }
    

    for(int i = 0; i<1000; i++){
        if(perArray[i].location == "africa"){
            peopleAfr<<perArray[i].id<<','<<perArray[i].firstName<<','<<perArray[i].email<<','<<perArray[i].gender<<','<<perArray[i].location<<','<<perArray[i].finalNote<<endl;
        }else if(perArray[i].location == "europe"){
            peopleEur<<perArray[i].id<<','<<perArray[i].firstName<<','<<perArray[i].email<<','<<perArray[i].gender<<','<<perArray[i].location<<','<<perArray[i].finalNote<<endl;
        }else if(perArray[i].location == "asia"){
            peopleAsia<<perArray[i].id<<','<<perArray[i].firstName<<','<<perArray[i].email<<','<<perArray[i].gender<<','<<perArray[i].location<<','<<perArray[i].finalNote<<endl;
        }else if(perArray[i].location == "america"){
            peopleAmer<<perArray[i].id<<','<<perArray[i].firstName<<','<<perArray[i].email<<','<<perArray[i].gender<<','<<perArray[i].location<<','<<perArray[i].finalNote<<endl;
        }else if(perArray[i].location == "oceania"){
            peopleOcean<<perArray[i].id<<','<<perArray[i].firstName<<','<<perArray[i].email<<','<<perArray[i].gender<<','<<perArray[i].location<<','<<perArray[i].finalNote<<endl;
        }
    }

    inPeople.close();
    peopleAfr.close();
    peopleEur.close();
    peopleAsia.close();
    peopleAmer.close();
    peopleOcean.close();

    // end of 2nd task

    int fmAfrica = 0, fmEurope = 0, fmAsia = 0, fmAmerica = 0, fmOceania = 0;

    for(int i = 0; i<1000; i++){

        if(perArray[i].location == "africa"){
            if(perArray[i].gender == "female" || perArray[i].gender =="male"){
                fmAfrica += 1;
            }
        }else if(perArray[i].location == "europe"){
            if(perArray[i].gender == "female" || perArray[i].gender =="male"){
                fmEurope += 1;
            }
        }else if(perArray[i].location == "asia"){
            if(perArray[i].gender == "female" || perArray[i].gender =="male"){
                fmAsia += 1;
            }
        }else if(perArray[i].location == "america"){
            if(perArray[i].gender == "female" || perArray[i].gender =="male"){
                fmAmerica += 1;
            }
        }else if(perArray[i].location == "oceania"){
            if(perArray[i].gender == "female" || perArray[i].gender =="male"){
                fmOceania += 1;
            }
        }
    }

    cout<<"Hombres y mujeres por localidad: "<<endl;
    cout<<"Africa: "<<fmAfrica<<endl;
    cout<<"Europe: "<<fmEurope<<endl;
    cout<<"Asia: "<<fmAsia<<endl;
    cout<<"America: "<<fmAmerica<<endl;
    cout<<"Oceania: "<<fmOceania<<endl;
    // end of 3rd Task
}
