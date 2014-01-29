#ifndef __popup_v1_piano__Piano__
#define __popup_v1_piano__Piano__

#include <vector>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>

namespace piano {
    
    class Piano {
    public:
        bool isFine(const std::vector<int> pianoDates[], unsigned int moveTeams, unsigned int totalPianos) {
            return isWorking(pianoDates, moveTeams, totalPianos, [](unsigned int day){
                if(((day+2)/7)*7-2 == day) {
                    return false;
                }
                if(((day+1)/7)*7-1 == day) {
                    return false;
                }
                return true;
            });
        }
        
        bool isWeekend(const std::vector<int> pianoDates[], unsigned int moveTeams, unsigned int totalPianos) {
            return isWorking(pianoDates, moveTeams, totalPianos, [](unsigned int day){ return true;});
        }
        
        bool isWorking(const std::vector<int> pianoDates[], unsigned int moveTeams, unsigned int totalPianos, std::function<bool (unsigned int day)> operation) {
            std::vector<int> currentPianos;
            int availableMoveTeams;
            for(int i = 0; i < 100 && totalPianos > 0; i++) {
                //first insert all new end dates
                for(int endDate: pianoDates[i]) {
                    insertSorted(currentPianos, endDate);
                }
                
                //We got all the moveTeams again
                availableMoveTeams = moveTeams;
                if(operation(i)) {
                    while(currentPianos.size() > 0 && availableMoveTeams > 0) {
                        
                        if(currentPianos[0] < i) {
                            return false; // we failed, the last day has past
                        } else {
                            //make the move
                            availableMoveTeams--;
                            totalPianos--;
                            currentPianos.erase(currentPianos.begin());
                        }
                    }
                }
            }
            
            if(totalPianos > 0) {
                return false;
            }
            return true;
        }
        
        void insertSorted(std::vector<int> & vec, int value) {
            std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), value, std::less<int>() );
            vec.insert( it, value );
        }
    };
}

#endif
