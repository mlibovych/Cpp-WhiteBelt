#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int Q;
    string command;
    map<string,string>  countries;

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> command;
        if (command == "DUMP") {
            if (!countries.size()) {
                cout << "There are no countries in the world" << endl;
            }
            else {
                for (const auto& [key, value] : countries) {
                    cout << key << "/" << value << " ";
                }
                cout << endl;
            }
        }
        else if (command == "ABOUT") {
            string country;
            
            cin >> country;
            if (!countries.count(country)) {
                cout << "Country " <<  country << " doesn't exist" << endl;
            }
            else {
                cout << "Country " <<  country << " has capital " << countries[country] << endl;
            }
        }
        else if (command == "RENAME") {
            string old_country_name, new_country_name;
            
            cin >> old_country_name >> new_country_name;
            if (!countries.count(old_country_name) || countries.count(new_country_name)) {
                cout << "Incorrect rename, skip" << endl;
            }
            else {
                countries[new_country_name] = countries[old_country_name];
                countries.erase(old_country_name);
                cout << "Country " <<  old_country_name << " with capital " << countries[new_country_name] 
                << " has been renamed to " << new_country_name<< endl;
            }

        }
        else if (command == "CHANGE_CAPITAL") {
            string country, new_capital;
            
            cin >> country >> new_capital;
            if (!countries.count(country)) {
                countries[country] = new_capital;
                cout << "Introduce new country " <<  country << " with capital " << new_capital << endl;
            }
            else {
                if (countries[country] == new_capital) {
                    cout << "Country "<< country <<" hasn't changed its capital" << endl;
                }
                else {
                    cout << "Country " << country << " has changed its capital from " 
                    << countries[country] << " to " << new_capital << endl;
                    countries[country] = new_capital;
                }
            }
        }     
    }
    return 0;
}
