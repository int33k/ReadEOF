#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <string>
#include<bits/stdc++.h>

using namespace std;

enum Status{
    HIGH,
    MEDIUM,
    LOW
};

typedef struct Client_Data {
    string name;
    string address;
    long int balance;
    Status clientstatus;
} RECORDS;

RECORDS * mallocing(){ 
    return new RECORDS;     //return(RECORDS *)(malloc(sizeof(RECORDS)));
}

void Credentials_Appending(RECORDS * addr, string name, string address, long int balance, Status clientstatus){
    addr->name = name;
    addr->address = address;
    addr->balance = balance;
    addr->clientstatus = clientstatus;
}

string getstring(RECORDS *addr) {
        switch(addr->clientstatus){
            case HIGH:
                return "High";
                break;
            case MEDIUM:
                return "Medium";
                break;
            case LOW:
                return "Low";
                break;
            default:
                return "Unknown";
        }
}

void PrintingPress(RECORDS *arr,fstream &logfile, int i){

        logfile << endl << endl <<"Name : " << arr->name << endl;
        logfile << "Address : " << arr->address << endl;
        logfile << "Balance : " << arr->balance << endl;
        logfile << "Status : " << getstring(arr) << endl;
        logfile << endl << endl;
        logfile << "-------------------------------";
        logfile << setw(3) << setfill('0') << i+1;
}


// not to be in the class if so

/* int customStringToInt(const string& str) {
    int result = 0;

    for (size_t i = 0; i < str.size(); ++i) {
            result = result * 10 + (str[i] - '0');
        }

    return result;
} */



int main(){
    system("clear");

    fstream logfile("customer_data.txt",ios::in | ios::out | ios::app);
    //FILE *logfile = fopen("customer_data.txt","a+");

    char boool;
    const int numClient = 150;
    RECORDS *arr[numClient];


    for(int i = 0; i < numClient; i++) arr[i] = mallocing();


     for(size_t i = 0; i < numClient ; i++){

        /*if(i==0){

            logfile.seekg(-1, ios_base::end);
            char ch;
            logfile.get(ch);

             if(ch=='\0') 
            {
                logfile << "\t\t\tCLIENTS'S DATA : " << endl;
                logfile << "\t\t\t---------------" << endl;
            } 
            else
            {
                logfile.seekg(-3, ios_base::end);
                char buffer[3];
                logfile.read(buffer,3);
                string str(buffer);
                int num = stoi(str);
                //i = customStringToInt(str); 
                i = num;
            }  
            
        }  */
 
        if(i==20) break;

        Credentials_Appending(arr[i],"rajat","kurla",15000,MEDIUM);

        PrintingPress(arr[i],logfile,i);
    }

    logfile.close();   

    cout << arr[10]->name << endl << arr[10]->clientstatus << endl << endl;
    cout << arr[40]->name << endl << arr[40]->clientstatus << endl << endl;
    
    for(size_t i = 0; i < numClient ; i++){
        delete arr[i];
    }
}



