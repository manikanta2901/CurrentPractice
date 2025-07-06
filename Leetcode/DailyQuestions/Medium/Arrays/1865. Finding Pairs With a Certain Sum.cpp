#include<bits/stdc++.h>
using namespace std;

class FindSumPairs {
public:
    map<int,int>fre;
    vector<int>nums;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size();
        for(int i = 0; i < size; i++){
            fre[nums1[i]]++;
        }
        nums = nums2;
    }
    
    void add(int index, int val) {
        nums[index] += val;
    }
    
    int count(int tot) {
        int answer = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            int count = fre[tot - nums[i]];
            answer += count;
        }
        return answer;
    }
};

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (std::string::npos == first) {
        return str; // All whitespace or empty
    }
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, (last - first + 1));
}

// Parses a string like "[1,2,3]" into a vector of ints
std::vector<int> parseVectorOfInts(const std::string& s) {
    std::vector<int> result;
    if (s.empty() || s.length() < 2 || s[0] != '[' || s.back() != ']') {
        // std::cerr << "Debug: parseVectorOfInts received invalid format: '" << s << "'\n";
        return result; // Invalid format
    }

    std::string content = s.substr(1, s.length() - 2); // Remove outer brackets
    std::stringstream ss(content);
    std::string segment;

    while (std::getline(ss, segment, ',')) {
        segment = trim(segment); // Trim any spaces around the number
        if (!segment.empty()) {
            try {
                result.push_back(std::stoi(segment));
            } catch (const std::invalid_argument& e) { 
                
            } catch (const std::out_of_range& e) {
            }
        }
    }
    return result;
}

// Parses a string like '["op1", "op2"]' into a vector of strings
std::vector<std::string> parseVectorOfStrings(const std::string& s) {
    std::vector<std::string> result;
    if (s.empty() || s.length() < 2 || s[0] != '[' || s.back() != ']') {
        return result; // Invalid format
    }

    std::string content = s.substr(1, s.length() - 2); // Remove outer brackets
    std::stringstream ss(content);
    std::string segment;

    while (std::getline(ss, segment, ',')) {
        segment = trim(segment); // Trim any spaces
        if (segment.length() >= 2 && segment[0] == '"' && segment.back() == '"') {
            result.push_back(segment.substr(1, segment.length() - 2)); // Remove quotes
        } else {
        }
    }
    return result;
}

int main() {
    FindSumPairs* obj = nullptr; 

    std::string line;

    std::getline(std::cin, line);
    std::vector<std::string> operations = parseVectorOfStrings(line);
    std::getline(std::cin, line);
    std::string full_args_str = line;

    if (full_args_str.length() >= 2 && full_args_str[0] == '[' && full_args_str.back() == ']') {
        full_args_str = full_args_str.substr(1, full_args_str.length() - 2);
    } else {
        return 1;
    }
    std::vector<std::string> arg_tokens;
    int bracket_level = 0;
    std::string current_token;
    for (char c : full_args_str) {
        if (c == '[') {
            bracket_level++;
            current_token += c;
        } else if (c == ']') {
            bracket_level--;
            current_token += c;
        } else if (c == ',' && bracket_level == 0) {
            arg_tokens.push_back(trim(current_token));
            current_token = "";
        } else {
            current_token += c;
        }
    }
    if (!current_token.empty()) { 
        arg_tokens.push_back(trim(current_token));
    }

    if (operations.size() != arg_tokens.size()) {
        return 1;
    }


    for (size_t i = 0; i < operations.size(); ++i) {
        const std::string& op = operations[i];
        const std::string& arg_str_token = arg_tokens[i]; 
        if (op == "FindSumPairs") {
            size_t first_inner_vec_end = std::string::npos;
            int current_bracket_level_for_constructor_arg = 0;
            for (size_t j = 0; j < arg_str_token.length(); ++j) {
                if (arg_str_token[j] == '[') {
                    current_bracket_level_for_constructor_arg++;
                } else if (arg_str_token[j] == ']') {
                    current_bracket_level_for_constructor_arg--;
                    if (current_bracket_level_for_constructor_arg == 1) { 
                        first_inner_vec_end = j;
                        break;
                    }
                }
            }

            if (first_inner_vec_end == std::string::npos ||
                first_inner_vec_end + 2 >= arg_str_token.length() || 
                arg_str_token[first_inner_vec_end + 1] != ',' ||
                arg_str_token[first_inner_vec_end + 2] != '[')
            {
                 return 1;
            }

            std::string nums1_arg_str = arg_str_token.substr(1, first_inner_vec_end);
            std::string nums2_arg_str = arg_str_token.substr(first_inner_vec_end + 2, arg_str_token.length() - (first_inner_vec_end + 2) - 1); // Excludes outer ']'

            std::vector<int> nums1_val = parseVectorOfInts(nums1_arg_str);
            std::vector<int> nums2_val = parseVectorOfInts(nums2_arg_str);

            if (obj) {
                delete obj;
            }
            obj = new FindSumPairs(nums1_val, nums2_val);

        } else if (op == "add") {
            if (!obj) { break; }
            std::vector<int> params = parseVectorOfInts(arg_str_token);
            if (params.size() == 2) {
                obj->add(params[0], params[1]);
            } 
        } else if (op == "count") {
            if (!obj) {break; }
            std::vector<int> params = parseVectorOfInts(arg_str_token);
            if (params.size() == 1) {
                int result = obj->count(params[0]);
            } 
        } else {
        }
    }
    return 0;
}