#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();
    int l1,l2,r1,r2,mid1,mid2;
    l1=l2=0;
    r1=w;
    r2=h;
    // game loop     bomb_dir == "U"||bomb_dir == "UR"||bomb_dir == "UL"
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();
        while (1){
            mid1 = l1+ (r2-l1)/2;
            mid2 = l2+ (r1-l2)/2;
            cout<<mid2<<" "<<mid1<<endl;
            cin >> bomb_dir; cin.ignore();
            if(bomb_dir == "U"||bomb_dir == "UR"||bomb_dir == "UL"){
                r2=mid1;
            }else if(bomb_dir == "D"||bomb_dir == "DR"||bomb_dir == "DL"){
                l1 = mid1;
            }
            if(bomb_dir == "L"||bomb_dir == "UL"||bomb_dir == "DL"){
                r1=mid2;
            }else if(bomb_dir == "R"||bomb_dir == "UR"||bomb_dir == "DR"){
                l2 = mid2;
            }
           
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // the location of the next window Batman should jump to.
        
    }
}