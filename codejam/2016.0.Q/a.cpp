#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    ifstream inf("in.txt");
    ofstream otf("ot.txt");
    istream& in = inf;
    ostream& ot = otf;

    typedef __int64_t ll;
    int T;
    ll N;

    in >> T;
    for (int t = 1; t <= T; t++)
    {
        in >> N;
        set<int> s;

        ll Target = 0;
        for (int i = 1; i <= 200; i++)
        {
            Target = N*i;
            ll NN = Target;
            while (NN)
            {
                int r = NN % 10;
                s.insert(r);
                NN /= 10;
            }
            if (s.size() == 10)
                break;
        }
        if (s.size() == 10)
        {
            ot << "Case #" << t << ": " << Target << endl;
        }
        else
        {
            ot << "Case #" << t << ": " << "INSOMNIA" << endl;
        }
    }
    return 0;
}
