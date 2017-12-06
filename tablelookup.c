//
// Created by Jeffrey  Booher-Kaeding on 12/2/17.
//

#include "tablelookup.h"
#include "itoa.h"

int lookup(int** table, char* offset, int vpn){
    //table:
    //[valid][permission][ppn][used]

    //check to make sure its valid
    if(table[vpn][0] != 0) {
        //check to see if we have permission
        if (table[vpn][1] != 0) {
            //check to see if its used
            if(table[vpn][3] != 0){
                //grab the ppn
                int ppn = table[vpn][3];

                //create a string buffer for our mem maths.
                char* buffer;

                //add out ppn
                buffer = itoa(ppn,2);
                //add our offset
                strcat(buffer,offset);

                //our final int to return
                long address;
                address = strtol ( buffer,NULL,2);
                //return [ppn][offset]
                return address;
            } else
                //not used
                return -1;
        } else
            //no permission
            return -2;
    }
    //not valid
    return -3;
}