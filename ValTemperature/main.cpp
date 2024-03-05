#include <iostream>
#include <map>
#include <thread>
#include <fstream>

using namespace std;
using namespace std::chrono;




void updateTemperature(map<string, int> &meteo) {
    while (1) {
        for (auto &elemento: meteo) {
            elemento.second++;
        }
        this_thread::sleep_for(milliseconds(150));
    }
}

void Scrivi( map<string, int> &meteo){
    ofstream oFile("C:\\Users\\casar\\Desktop\\C++\\ValTemperature\\Valori.txt");
    for(auto elemento : meteo){
        oFile << elemento.second << endl;
    }
    oFile.close();



}
void Leggi(){
    ifstream iFile("C:\\Users\\casar\\Desktop\\C++\\ValTemperature\\Valori.txt");
    string riga = "";
    while(getline(iFile, riga)){
        cout << riga << endl;
    }
    iFile.close();
}


int main() {

//    cout << thread::hardware_concurrency() <<endl;

    map<string, int> meteo;
    meteo["Vicenza"] = 15;

    thread worker(updateTemperature, ref(meteo));


/*
    while (1) {
        for (auto elemento: meteo) {
            cout << "Citta " << elemento.first << " T: " << elemento.second << endl;
        }
        this_thread::sleep_for(seconds(1));
    }
*/


    worker.join();
    thread th1(Scrivi, ref(meteo));
    th1.join();


    Leggi();

    return 0;

}
