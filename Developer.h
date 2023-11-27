#ifndef Developer_h
#define Developer_h

#include "game.h"

#include <bits/stdc++.h>

using namespace std;



class Developer
{
private:
    static int cnt;
    int devID;
    string dev_type;
    string dev_name;
    double revenue;

public:
    Developer();
    void setprice(game&);
    void addGameRequest();
    void disk_out();
    void disk_in(int);
    int get_devID();
    int get_count();
    void dec_count();
};

#endif // Developer_h
