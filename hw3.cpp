#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

void user_interface();
void analysis_file(string filename);
void check_long_method();
void check_long_parameter();
void check_duplicate();
vector<string> functions_name;
vector<string> output_long_method;
vector<string> output_long_parameter;
vector<string> output_duplicate;
map<string, string> function_context_map;

int main(int argc, char* argv[]) {
    string filename = argv[1];
    analysis_file(filename);

    cout << "\nWelcome to Code Smell Detection! The file you input contains the following methods/functions:\n"; 
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
                        if(output_long_parameter.size() == 0){
                            cout << "No function has a long parameter list.\n";
                        }else{
                            for(int i = 0; i < output_long_parameter.size(); i+=2){
                                cout << output_long_parameter.at(i) << " has a Long Parameter List. Its parameter list contains " << output_long_parameter.at(i+1) << " parameters.\n";
                            }
                        }
                        break;
                    case 3:
                        bool duplicate_exist;
                        for(int i = 0; i < functions_name.size(); i++){
                            for(int j = i+1; j < functions_name.size(); j++){
                    
                                if(function_context_map[functions_name.at(i)] == function_context_map[functions_name.at(j)]){
                                    cout << functions_name.at(i) << " and " << functions_name.at(j) << " are duplicated.\n";
                                    duplicate_exist = true;
                                }
                            }
                        }
                        if(!duplicate_exist){
                            cout << " No functions are duplicated.\n";
                        }
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
                cout << "4. Quit\n \n";
            } else {
                cout << "Invalid input option selected" << endl;
            }
        }catch(const exception& e){
            cout << "Invalid input option selected" << std::endl;
        }
    }
}

void analysis_file(string filename){
    ifstream input_file(filename);
    int curly_brackets = 0;
    string function_name;
    string current_function;
    string function_context;
    bool function_start = false;

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

                    int count_comma = 0;
                    for(int i = 0; i < line.length(); i++){
                        if(line[i] == ',') count_comma++;
                    }
                    if(count_comma >= 3){
                        output_long_parameter.push_back(function_name);
                        output_long_parameter.push_back(to_string(count_comma + 1));
                    }

                    // Count the lines of the function by looking for opening and closing braces
                    if(first_function){
                        first_function = false;
                    }else{
                        if(line_count >= 16){
                            output_long_method.push_back(functions_name.at(functions_name.size() - 2));
                            output_long_method.push_back(to_string(line_count));
                        }   
                    }
                    brace_count = 0;
                    line_count = 0;
                    function_start = true;
                }

                if(line.find("{") != string::npos) curly_brackets++;
                if(line.find("}") != string::npos) curly_brackets--;

                ++line_count;

                if(function_name.empty() || function_start){
                    function_start = false;
                    if(!function_name.empty()){
                        if(functions_name.size() == 1){
                            function_context_map[functions_name.at(functions_name.size() - 1)] = function_context;
                        }else{
                            function_context_map[functions_name.at(functions_name.size() - 2)] = function_context;
                        }
                    }
                    function_context = "";
                }else{
                    for(int i = 0; i < line.length(); i++){
                        if(line[i] != ' ' && line[i] != '{' && line[i] != '}'){
                            function_context += line[i];
                        }
                    }
                }
                
                brace_count += count(line.begin(), line.end(), '{');
                brace_count -= count(line.begin(), line.end(), '}');
            }

            if(line_count >= 16){
                output_long_method.push_back(functions_name.at(functions_name.size() -1));
                output_long_method.push_back(to_string(line_count));
            }

            function_context_map[functions_name.at(functions_name.size() - 1)] = function_context;
            
            input_file.close();
        }
    }catch(const exception& e){
        cout << "Unable to open file" << endl;
    }
}

