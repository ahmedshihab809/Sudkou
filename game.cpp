#include "game.h"


int game::cnt = 0;
game::game()
{
    GameID = cnt;
    Name = "x";
    Type = null;
    Price = 0;
    developerID = 0;
    releaseDate = "0";
    rating = 0;
}

/*void game::set_devID(Developer* dev)
{
    developerID = dev->get_devID();
}*/

void game::disk_out()
{
    ofstream out;
    out.open("game.dat", ios::app | ios::binary);
    out.write((char *)this, sizeof(*this));
}
void game::disk_in(int i)
{
    ifstream in;
    in.open("game.dat", ios::app | ios::binary);
    in.seekg(i * sizeof(game));
    in.read((char *)this, sizeof(*this));
}
int game::get_id()
{
    return GameID;
}
void game::set_info()
{
    cout << "Name of the game : ";
    cin >> Name;
    cout << "Type of the game : \n0.fps\n 1.tps \n 2.moba \n 3.sandbox \n 4.action-adventure \n 5.others";
    int temp;
    cin >> temp;
    Type = (game_types)temp;
    cout << "Enter price: ";
    cin >> Price;
   // set_devID(dev);
  // developerID = Developer::get_devID();

  cout<<"Enter Developer ID:";
  cin>>developerID;

    cout << "Enter the release date : " << endl;
    cin >> releaseDate;
}

void game::get_info()
{
    cout << "Name of the game : " << Name;
    cout << "Type of the game : " << type_names[Type];
    cout << "Price of the game : " << Price;
    cout << "Release Date : " << releaseDate;
    cout << "Rating : " << rating;
}
double game::get_price()
{
    return Price;
}

void game::set_price(double a)
{
    Price = a;
}

int game::get_cnt()
{
    return cnt;
}

