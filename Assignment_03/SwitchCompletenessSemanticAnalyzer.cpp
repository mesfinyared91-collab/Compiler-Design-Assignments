#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

/*
  Represents an Enum definition stored in the Symbol Table
*/
struct EnumDefinition {
    string name;
    set<string> values;  // All enum constants
};

/*
  Represents a Switch Statement node in the AST
*/
struct SwitchStatement {
    string enumType;
    vector<string> caseLabels;
    bool hasDefault;
};

/*
  Semantic Analyzer class
*/
class SemanticAnalyzer {
public:
    void checkSwitchCompleteness(
        const EnumDefinition& enumDef,
        const SwitchStatement& sw
    ) {
        cout << "Analyzing switch on Enum '" 
             << enumDef.name << "'..." << endl;

        // Rule 1: Default case exists
        if (sw.hasDefault) {
            cout << "[STATUS]: Valid (default case present)\n";
            cout << "----------------------------------\n";
            return;
        }

        // Rule 2: Check exhaustive coverage
        set<string> coveredCases(
            sw.caseLabels.begin(),
            sw.caseLabels.end()
        );

        bool error = false;

        for (const string& val : enumDef.values) {
            if (coveredCases.find(val) == coveredCases.end()) {
                if (!error) {
                    cout << "[ERROR]: Incomplete switch statement\n";
                    cout << "[DETAILS]: Missing cases: ";
                    error = true;
                }
                cout << val << " ";
            }
        }

        if (!error) {
            cout << "[STATUS]: Valid (all enum values covered)\n";
        }

        cout << "\n----------------------------------\n";
    }
};

/*
  Main function - Test Driver
*/
int main() {
    SemanticAnalyzer analyzer;

    // Define Enum
    EnumDefinition trafficLight;
    trafficLight.name = "TrafficLight";
    trafficLight.values = {"RED", "YELLOW", "GREEN"};

    // Test Case 1: Incomplete switch
    SwitchStatement sw1;
    sw1.enumType = "TrafficLight";
    sw1.caseLabels = {"RED", "YELLOW"};
    sw1.hasDefault = false;
    analyzer.checkSwitchCompleteness(trafficLight, sw1);

    // Test Case 2: Complete switch
    SwitchStatement sw2;
    sw2.enumType = "TrafficLight";
    sw2.caseLabels = {"RED", "YELLOW", "GREEN"};
    sw2.hasDefault = false;
    analyzer.checkSwitchCompleteness(trafficLight, sw2);

    // Test Case 3: Default case present
    SwitchStatement sw3;
    sw3.enumType = "TrafficLight";
    sw3.caseLabels = {"RED"};
    sw3.hasDefault = true;
    analyzer.checkSwitchCompleteness(trafficLight, sw3);

    return 0;
}
