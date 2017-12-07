//
// Created by Jeffrey  Booher-Kaeding on 12/2/17.
//

#include "tablelookup.h"
#include "itoa.h"

int lookup(int** table, unsigned long vpn){
    //table:
    //[valid][permission][ppn][used]
    //check to make sure its valid
    if(table[vpn][0] != 0) {
        //check to see if we have permission
        if (table[vpn][1] != 0) {
            //check to see if its used
            //grab the ppn
                int ppn = table[vpn][2];

                //create a string buffer for our mem maths.
                char* buffer;

                //our final int to return
                long address;
                address = ppn;
                //return [ppn]
                return address;

            }
        } else//no permission
        {
            printf("Seg Fualt\n");
            exit(1);
        }
    //not valid

    printf("Disk Fualt\n");
    exit(1);
}