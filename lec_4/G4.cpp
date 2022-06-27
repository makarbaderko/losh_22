#include<vector>
#include<iostream>

using namespace std;

int w, h;
vector < vector<int> > d;


void calc (int x, int, int mask, int nmask)
{
	if (x == w)
		return;
	if (y >= h)
		d[x+1][nmask] += d[x][mask];
	else
	{
		int mask_2 = 1 << y;
		if (mask & mask_2)
			calc (x, y+1, mask, nmask);
		else
		{
			calc (x, y+1, mask, nmask | mask_2);
			if (y+1 < h && ! (mask & mask_2) && ! (mask & (mask_2 << 1)))
				calc (x, y+2, mask, nmask);
		}
	}
}


int main()
{
	cin >> w >> h;
	d.resize (w+1, vector<int> (1<<h));
	d[0][0] = 1;
	for (int i = 0; i < w ; x++)
		for (int mask = 0; mask < (1 << h); mask++)
			calc(i, 0, mask, 0);

	cout << d[w][0];

}
