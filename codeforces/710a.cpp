#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std; 

int main() {
#ifdef _DEBUG
	freopen("710a.in", "r", stdin);
#endif

	string in;
	cin >> in;
	int x = in[0] - 'a';
	int y = in[1] - '1';

	int pos[3][3];
	memset(pos, -1, sizeof(pos));
	pos[1][1] = 1;
	
	if (x == 0) 
		pos[0][0] = pos[0][1] = pos[0][2] = 1;
	else if (x == 7) 
		pos[2][0] = pos[2][1] = pos[2][2] = 1;

	if (y == 7) 
		pos[0][0] = pos[1][0] = pos[2][0] = 1;
	else if (y == 0) 
		pos[0][2] = pos[1][2] = pos[2][2] = 1;

	int c = 0;
	for (int w = 0; w < 3; w++)
	for (int h = 0; h < 3; h++)
		if ( pos[w][h] == -1 )
			c++;

	cout << c << endl;

	return 0;
}
