#include <iostream>
#include <vector>
using namespace std;

vector<string> getMazePathswithjump(int sr, int sc, int dr, int dc)
{
    if (sr > dr || sc > dc)
    {
        vector<string> base;
        return base;
    }

    if (sr == dr && sc == dc)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> paths;
    for (int move = 1; move <= dc - sc; move++)
    {
        vector<string> hpaths = getMazePathswithjump(sr, sc + move, dr, dc);
        for (string hpath : hpaths)
        {
            paths.push_back("h" + move + hpath);
        }
    }

    for (int move = 1; move <= dr - sr; move++)
    {
        vector<string> vpaths = getMazePathswithjump(sr + move, sc, dr, dc);
        for (string vpath : vpaths)
        {
            paths.push_back("v" + move + vpath);
        }
    }

    for (int move = 1; move <= dc - sc && move <= dr - sr; move++)
    {
        vector<string> dpaths = getMazePathswithjump(sr + move, sc + move, dr, dc);
        for (string dpath : dpaths)
        {
            paths.push_back("d" + move + dpath);
        }
    }

    return paths;
}