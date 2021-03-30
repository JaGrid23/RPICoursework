//
//  Sorting.h
//  HW7
//
//  Created by Jared Gridley on 4/1/20.
//  Copyright © 2020 Jared Gridley. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h


//Struct to custom sort the '-s' command, reverse sorts strings and the ints
struct s_sort{
    bool operator() (const fighter &a, const fighter& b) const{
        if(a.first != b.first){
            return a.first > b.first;
        }
        return b.second > a.second;
    }
};



#endif /* Sorting_h */
