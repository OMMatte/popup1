#ifndef __popup_v1_piano__Mailbox__
#define __popup_v1_piano__Mailbox__

#include <vector>
#include <map>
#include <set>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>

namespace mailbox {
    
    class Mailbox {
    public:
        unsigned int run(unsigned int mailboxes, unsigned int min, unsigned int max, int kMinMax[11][101][101]) {
            
            if(max == min - 1) {
                //special case, look at hit calculation
                return 0;
            }
            if(min == max) {
                return min;
            }
            
            if(mailboxes == 1) {
                return ((max-min+1)*(max+min))/2;
            }
            if(kMinMax[mailboxes][min][max] != 0) {
                return kMinMax[mailboxes][min][max];
            }
            
            
            unsigned int best = 100000;
            for(unsigned int i = min; i < max; i++) {
                unsigned int worst;
                unsigned int hit = i + run(mailboxes - 1, min, i - 1, kMinMax);
                unsigned int miss = i + run(mailboxes, i + 1, max, kMinMax);
                
                if(hit > miss) {
                    worst = hit;
                } else {
                    worst = miss;
                }
                
                if(worst < best) {
                    best = worst;
                }
            }
            
            kMinMax[mailboxes][min][max] = best;
            return best;
        }
    };
}

#endif
