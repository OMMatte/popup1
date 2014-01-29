#ifndef __popup_v1_help__Help__
#define __popup_v1_help__Help__

#include <vector>
#include <map>
#include <set>
#include <string>

namespace help {
    class Help {
    public:
        bool run(std::vector<std::string> & first, std::vector<std::string> & second) {
            std::map<std::string, std::string> variableSet;
            std::map<std::string, std::vector<int>> firstCon;
            std::map<std::string, std::vector<int>> secondCon;
            std::vector<int> firstDep;
            std::vector<int> secondDep;
            int solved = 0;
            
            
            
            for(unsigned int i = 0; i < first.size(); i++){
                std::string firstWord = first[i];
                std::string secondWord = second[i];
                if(firstWord[0] == '<') {
                    buildMap(firstCon, firstWord, i);
                } else if(secondWord[0] == '<') {
                    secondDep.push_back(i);
                }
                
                if(secondWord[0] == '<') {
                    buildMap(secondCon, secondWord, i);
                } else if(firstWord[0] == '<') {
                    firstDep.push_back(i);
                }
                
                if(firstWord[0] != '<' && secondWord[0] != '<') {
                    solved++;
                    if(firstWord != secondWord) {
                        return false;
                    }
                }
            }
            
            if(solved == first.size()) {
                return true;
            }
            
            int nextNewSetter = 0;
            while(true){
                if(firstDep.empty() && secondDep.empty()) {
                    for(int i = 0; ;i++) {
                        if(first[i].at(0) == '<') {
                            nextNewSetter = i + 1;
                            std::vector<int> firstPos = firstCon.find(first[i])->second;
                            for(int pos : firstPos) {
                                first[pos] = "a";
                                secondDep.push_back(pos);
                            }
                            break;
                        }
                    }
                }
                
                while(!firstDep.empty()) {
                    int depPos = firstDep.front();
                    firstDep.erase(firstDep.begin());
                    std::string varWord = first[depPos];
                    if(varWord[0] != '<') {
                        continue;
                    }
                    std::string newWord = second[depPos];
                
                    std::vector<int> otherPos = firstCon.find(varWord)->second;
                    for(int pos : otherPos) {
                        first[pos] = newWord;
                        if(second[pos].at(0) == '<') {
                            secondDep.push_back(pos);
                        } else if(newWord == second[pos]){
                            solved++;
                        } else {
                            return false;
                        }
                    }
                }
                
                while(!secondDep.empty()) {
                    int depPos = secondDep.front();
                    secondDep.erase(secondDep.begin());
                    std::string varWord = second[depPos];
                    if(varWord[0] != '<') {
                        continue;
                    }
                    std::string newWord = first[depPos];
                    
                    std::vector<int> otherPos = secondCon.find(varWord)->second;
                    for(int pos : otherPos) {
                        second[pos] = newWord;
                        if(first[pos].at(0) == '<') {
                            firstDep.push_back(pos);
                        } else if(newWord == first[pos]){
                            solved++;
                        } else {
                            return false;
                        }
                    }
                }
                if(solved == first.size()) {
                    return true;
                }
            }
        }
        
        
        void buildMap(std::map<std::string, std::vector<int>> & map, std::string & word, int i) {
            if(map.find(word) == map.end()) {
                map[word] = {i};
            } else {
                map[word].push_back(i);
            }
        }

    };
}

#endif
