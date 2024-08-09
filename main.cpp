#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if(digits.empty()) return {};
        std::map<std::string,std::string> dict = {
                                            {"2","a"},
					    {"22","b"},
					    {"222","c"},
					    {"3","d"},
					    {"33","e"},
					    {"333","f"},
					    {"4","g"},
					    {"44","h"},
  				            {"444","i"},
					    {"5","j"},
					    {"55","k"},
					    {"555","l"},
					    {"6","m"},
					    {"66","n"},
					    {"666","o"},
                                            {"7","p"},
                                            {"77","q"},
                                            {"777","r"},
					    {"7777","s"},
                                            {"8","t"},
                                            {"88","u"},
                                            {"888","v"},
					    {"9","w"},
					    {"99","x"},
					    {"999","y"},
                                            {"9999","z"}};
        
        std::map<std::string,std::string> rev_dict = {
                                            {"a","2"},
					    {"b","22"},
					    {"c","222"},
					    {"d","3"},
					    {"e","33"},
					    {"f","333"},
					    {"g","4"},
					    {"h","44"},
  				            {"i","444"},
					    {"j","5"},
					    {"k","55"},
					    {"l","555"},
					    {"m","6"},
					    {"n","66"},
					    {"o","666"},
                                            {"p","7"},
                                            {"q","77"},
                                            {"r","777"},
					    {"s","7777"},
                                            {"t","8"},
                                            {"u","88"},
                                            {"v","888"},
					    {"w","9"},
					    {"x","99"},
					    {"y","999"},
                                            {"z","9999"}};
	
        std::string cur = "";
        std::vector<std::string> result;

        gen_comb(digits, 0, dict, rev_dict, cur, result);
        return result;
    }

private:
    void gen_comb(std::string digits, 
                  size_t inx, 
                  std::map<std::string,std::string>& mp,
		  std::map<std::string,std::string>& rev_mp,
                  std::string& cur, 
                  std::vector<std::string>& result){
    
        if(inx == digits.size()){result.push_back(cur); return;}
	/*
        std::string str = mp[digits[inx]];
        for(size_t i = 0; i < str.size(); i++){
            cur.push_back(str[i]);
            gen_comb(digits, inx + 1, mp, cur, result);
            cur.pop_back();
        }
	*/
	for(auto& i : mp){
		if(i.second.c_str()[0] == digits[inx]){
			for(size_t j = 0; j < i.first.size(); j++){
				cur.push_back(i.first[j]);
			}
			if(/*(i.first.size() > 1) && */(inx < digits.size() - 1) && (rev_mp.at(std::string(1,digits[inx + 1]))[0] == i.first[0]))
				cur.push_back('*');
			gen_comb(digits, inx + 1, mp, rev_mp, cur, result);
		}
	}
    }
};


int main(int argc, char* argv[]){
	for(size_t i = 1; i < argc; i++){
		std::vector<std::string> res = Solution().letterCombinations(std::string(argv[i]));
		for(const auto& j : res){
			std::cout<< j << " ";
		}
	}
	return argc == 1 ? EXIT_SUCCESS : EXIT_FAILURE;
}
