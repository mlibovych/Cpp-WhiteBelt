#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <stdexcept>
using namespace std;

string AskTimeServer();

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            string new_time = AskTimeServer();
            
            last_fetched_time = new_time;
            return last_fetched_time;
        }
        catch (system_error& er) {
            return last_fetched_time;
        }
    }
private:
    string last_fetched_time = "00:00:00";
};

