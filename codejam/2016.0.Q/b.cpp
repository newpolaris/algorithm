#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inf("in.txt");
    ofstream otf("ot.txt");
    istream& in = inf;
    ostream& ot = otf;

    int T;
    in >> T;
    for (int t = 1; t <= T; t++)
    {
        string s;
        in >> s;

        vector<bool> v;
        for(auto a : s)
            v.push_back(a == '+');

        reverse(v.begin(), v.end());

        int c = 0;
        int i = 0;
        bool plus = true;

        while (true)
        {
            while (v[i] == plus && i < v.size())
                i++;
            if (i >= v.size())
                break;
            }
            plus = !plus;
            reverse(v.begin()+i, v.end());
            c++;
        }

        ot << "Case #" << t << ": " << c << endl;
    }
    return 0;
}

