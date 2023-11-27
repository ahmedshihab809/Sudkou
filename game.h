#ifndef game_h
#define game_h

#include <bits/stdc++.h>

using namespace std;


enum game_types
{
    fps,
    tps,
    moba,
    sandbox,
    action_adventure,
    others,
    null
};
char *type_names[] = {"fps", "tps", "moba", "sandbox", "action-adventure", "others", "null"};
enum Medium
{
    bkash,
    paypal,
    visa,
    mastercard
};
char *Medium_names[] = {"bkash", "paypal", "visa", "mastercard"};


class game
{
private:
    static int cnt;
    int GameID;
    string Name;
    game_types Type;
    double Price;
    int developerID;
    string releaseDate;
    float rating;

public:
    game();
    float get_rating();
    float avg_rating(); // incomplete
    void set_info();
    void get_info();
    double get_price();
    int get_id();
    void disk_out();
    void disk_in(int);
    void set_price(double);
    int get_cnt();
   // void set_devID(Developer*);
};

#endif // game_h
