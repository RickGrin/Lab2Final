#include <iostream>

#include <vector>

#include <map>

#include <cmath>

#include <queue>

#include <set>

#include <iomanip>

#include <map>

using namespace std;


signed main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);

	int n, m;

	cin >> n >> m;

	int max_val = -1, pointer = -1;

	for (int i = 0; i < n; i++)

	{

		int sum = 0, k;

		for (int j = 0; j < m; j++)

		{

			cin >> k;

			sum += k;

		}

		if (sum > max_val)

		{

			max_val = sum;

			pointer = i;

		}

	}

	cout << max_val << "\n" << pointer;

}

