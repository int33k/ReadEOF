#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

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


int main(){
    system("clear");

    fstream logfile("customer_data.txt",ios::in | ios::out | ios::app);
    
    string buffer;
    const int numClient = 150;
    RECORDS *arr[numClient];
  
    for(int i = 0; i < numClient; i++) arr[i] = mallocing();

    for(size_t i = 0; i < numClient ; i++){

      if(i==0){
          
            logfile.seekg(0, ios::end);
            streampos fileSize = logfile.tellg(); 
            logfile.seekg(0, ios::beg);

             if(fileSize == 0){
                logfile << "\t\t\tCLIENTS'S DATA : " << endl;
                logfile << "\t\t\t---------------" << endl;
              } 
            else{   
                    logfile.seekg(static_cast<int>(fileSize) - 3);
                    char character;
                    while (logfile.get(character)) {
                        buffer.push_back(character);
                    }
                    i = stoi(buffer);
                    logfile.seekg(0, ios::end); 
                }

          }

      if(i==20) break; //checking for case one with this line uncommented and later commented to check else part is working or not so that to get file entry from index 21
       
      Credentials_Appending(arr[i],"rajat","kurla",15000+100*i,MEDIUM);
  
      PrintingPress(arr[i],logfile,i);
       
     }

    logfile.close();   
  
    for(size_t i = 0; i < numClient ; i++){
        delete arr[i];
    }

  return 0;
}
