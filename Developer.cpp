#include "Developer.h"



int Developer::cnt=0;

Developer ::Developer()
{
    devID = cnt;
    cout << "Enter Developer name:";
    cin >> dev_name;
    cout << "Enter Developer type:";
    cin >> dev_type;
    revenue = 0;

    cnt++;
}

int Developer ::get_devID()
{

    return devID;
}

void Developer::disk_out()
{
    ofstream out;
    out.open("developer.dat", ios::app | ios::binary);
    out.write((char *)this, sizeof(*this));
}
void Developer::disk_in(int i)
{
    ifstream in;
    in.open("developer.dat", ios::app | ios::binary);
    in.seekg(i * sizeof(Developer));
    in.read((char *)this, sizeof(*this));
}

void Developer ::setprice(game &g_name)
{
    vector<game> vec;
    ifstream infile;
    infile.open("game.dat", ios::app | ios::binary);

    int temp = g_name.get_cnt();
    game *ptr = new game;

    for (int i = 0; i < temp; i++)
    {
        infile.seekg(i * sizeof(game));
        infile.read((char *)ptr, sizeof(game));
        if (ptr->get_id() != g_name.get_id())
        {
            vec.push_back(*ptr);
        }
    }
    delete ptr;

    infile.close();

    ofstream outfile;
    outfile.open("game.dat", ios::trunc | ios::binary);

    vector<game>::iterator p;



    for (p = vec.begin(); p < vec.end(); p++)
    {
        game gg = *p ;
        game *pp ;
        pp = &gg;
        outfile.write((char *)pp, sizeof(game));
    }



    double new_price;
    g_name.get_info();
    cout << "What should be the price of the game? Please enter :";
    cin >> new_price;
    g_name.set_price(new_price);
    *ptr = g_name;

    outfile.write((char *)ptr, sizeof(game));
    outfile.close();
    delete ptr;
}


void Developer::addGameRequest()
{
    ofstream game_file;
    game_file.open("pending_games.dat", ios::app | ios::binary);

    game *new_game = new game;

    new_game->set_info();

    game_file.write((char *)new_game, sizeof(new_game));
    game_file.close();
}

int Developer::get_count()
{
    return cnt;
}

void Developer:: dec_count()
{

    cnt--;
}
