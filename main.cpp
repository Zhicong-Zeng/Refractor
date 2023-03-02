#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void user_interface();
void all_function_names(string filename);
void check_long_method();
void check_long_parameter();
void check_duplicate();
vector<string> functions_name;
vector<string> output_long_method;
string output2;
string output3;

int main() {
    string filename = "test.cpp";
    all_function_names(filename);

    cout << "Welcome to Code Smell Detection! The file you input contains the following methods/functions:\n"; 
    for(int i = 0; i < functions_name.size(); i++){
        cout << functions_name[i];
        if(i != functions_name.size()-1){
            cout << ", ";
        }
    }
    cout << ".\n";
    cout << "Please choose what you want to do now:\n";
    cout << "1. Long Method/Function Detection\n";
    cout << "2. Long Parameter List Detection\n";
    cout << "3. Duplicated Code Detection\n";
    cout << "4. Quit\n \n";

    user_interface();
}

void user_interface(){
    while(true){  
        string input;  
        getline(cin, input);
        try {
            int input_int = stoi(input);
        
            if (input_int >= 0 && input_int <= 4) { 
                switch (input_int) {
                    case 1:
                        if(output_long_method.size() == 0){
                            cout << "No function is a Long Function.\n";
                        }else{
                            for(int i = 0; i < output_long_method.size(); i+=2){
                                cout << "The " << output_long_method.at(i) << " function is a Long Function. It contains " << output_long_method.at(i+1) << " lines of code.\n";
                            }
                        }
                        break;
                    case 2:
                        cout << ""  << endl;
                        break;
                    case 3:
                        cout << ""  << endl;
                        break;
                    case 4:
                        cout << "Exiting...\n";
                        return;
                }
                cout << "\n";
                cout << "Please choose what you want to do now:\n";
                cout << "1. Long Method/Function Detection\n";
                cout << "2. Long Parameter List Detection\n";
                cout << "3. Duplicated Code Detection\n";
                cout << "4. Quit\n";
            } else {
                cout << "Invalid input option selected" << endl;
            }
        }catch(const exception& e){
            cout << "Invalid input option selected" << std::endl;
        }
    }
}

void all_function_names(string filename){
    ifstream input_file(filename);
    int curly_brackets = 0;
    string function_name;
    string current_function;

    try{
        if (input_file.is_open()) {
            string line;
            int brace_count = 0;
            int line_count = 0;
            bool first_function = true;

            while (getline(input_file, line)) {
                bool whiteSpacesOnly =  line.find_first_not_of (' ') == line.npos;
                if(line.length() == 0 || whiteSpacesOnly) continue;

                if(line.find("(") != string::npos && line.find("(") != string::npos && line.find(";") == string::npos && curly_brackets == 0) {
                    // Extract the function name from the line
                    size_t name_start = line.find(" ") + 1;
                    size_t name_end = line.find("(");
                    function_name = line.substr(name_start, name_end - name_start);
                    functions_name.push_back(function_name);

                    // Count the lines of the function by looking for opening and closing braces
                    if(first_function){
                        first_function = false;
                        //cout << "    Lines: " << line_count << endl;
                    }else{
                        if(line_count >= 16){
                            output_long_method.push_back(functions_name.at(functions_name.size() - 2));
                            output_long_method.push_back(to_string(line_count));
                        }
                        //cout << "    Lines: " << line_count << endl;
                    }
                    brace_count = 0;
                    line_count = 0;
                }

                if(line.find("{") != string::npos) curly_brackets++;
                if(line.find("}") != string::npos) curly_brackets--;

                //cout << "    Lines: " << line.length() << line << endl;
                ++line_count;
                brace_count += count(line.begin(), line.end(), '{');
                brace_count -= count(line.begin(), line.end(), '}');
            }

            if(line_count >= 16){
                output_long_method.push_back(functions_name.at(functions_name.size() -1));
                output_long_method.push_back(to_string(line_count));
                //cout << "    Lines: " << line_count << endl;
            }
            input_file.close();
        }
    }catch(const exception& e){
        cout << "Unable to open file" << endl;
    }
}

