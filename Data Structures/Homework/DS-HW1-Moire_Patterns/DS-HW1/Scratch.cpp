void diamond(int height, string characters, string out){
    ofstream out_file(out);
    int char_space = 1;         //Initializing it at one and will incrememnt by 2.
    int total_whitespace = height - char_space;
    int whitespace_before = ((total_whitespace)/2), whitespace_after = (total_whitespace - whitespace_before);
    int char_num = 0;
    int top_height = (height/2), bottom_height = (height-top_height);
    
    //Loop interating for TOP half of diamond
    for(int row=0; row<(top_height); row++){
        
        //Printing whitespace before the first character
        for(int space = 0; space<(whitespace_before); space++){
            out_file<<" ";
        }
        //Printing the characters
        out_file<<"*";
        if (char_space>1){              //If not first row, then print characters.
            for(int column = 0; column<(char_space-2); column++){
                if (char_num == characters.size()){
                    char_num = 0;
                }
                out_file<<characters[char_num];
                char_num++;
            }
            out_file<<"*";
        }
        char_space+=2;
        whitespace_before--;
        whitespace_after--;
        
        //Printing whitespace after the last character
        for(int space = 0; space<(whitespace_after); space++){
            out_file<<" ";
        }
        out_file<<endl;
    }
    
    //Loop interating for BOTTOM half of diamond
    for(int row=0; row<(bottom_height); row++){
        
        //Printing whitespace before the first character
        for(int space = 0; space<(whitespace_before); space++){
            out_file<<" ";
        }
        //Printing the characters
        out_file<<"*";
        if (char_space>1){              //If not first row, then print characters.
            for(int column = 0; column<(char_space-2); column++){
                if (char_num == characters.size()){
                    char_num = 0;
                }
                out_file<<characters[char_num];
                char_num++;
            }
            out_file<<"*";
        }
        char_space-=2;
        whitespace_before++;
        whitespace_after++;
        
        //Printing whitespace after the last character
        for(int space = 0; space<(whitespace_after); space++){
            out_file<<" ";
        }
        out_file<<endl;
    }
}

