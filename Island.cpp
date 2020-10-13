#include <bits/stdc++.h>
using namespace std;

class DSet{
	vector<int> r, p;
	int n;

	public:
	DSet(int n){
		r.resize(n);
		p.resize(n);
		this->n = n;
		makeSet();
	}

	void makeSet(){
		for (int i=0;i<n;i++){
            p[i] = i;
        }
	}

	int find(int x){
		if (p[x] != x){
			return find(p[x]);
		}
		return x;
	}

	void Union(int x, int y){
        int xR = find(x);
        int yR = find(y);
        if (xR == yR)
            return;
        if (r[xR] < r[yR])
            p[xR] = yR;
        else if(r[yR]<r[xR])
            p[yR] = xR;
        else{
            p[yR] = xR;
            r[xR] = r[xR] + 1;
        }
    }
};


void countNumberOfIslands(vector<vector<int> > &arr){
	int n = arr.size();
	int m = arr[0].size();
	DSet *dset = new DSet(n * m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (arr[i][j] == 0)
				continue;

			if (i+1 < n && arr[i+1][j]==1){
                dset->Union(i*(m)+j, (i+1)*(m)+j);
            }
            if (i-1 >= 0 && arr[i-1][j]==1){
                dset->Union(i*(m)+j, (i-1)*(m)+j);
            }
            if (j+1 < m && arr[i][j+1]==1){
                dset->Union(i*(m)+j, (i)*(m)+j+1);
            }
            if (j-1 >= 0 && arr[i][j-1]==1){
                dset->Union(i*(m)+j, (i)*(m)+j-1);
            }
            if (i+1<n && j+1<m && arr[i+1][j+1]==1){
                dset->Union(i*(m)+j, (i+1)*(m)+j+1);
            }
            if (i+1<n && j-1>=0 && arr[i+1][j-1]==1){
                dset->Union(i*m+j, (i+1)*(m)+j-1);
            }
            if (i-1>=0 && j+1<m && arr[i-1][j+1]==1){
                dset->Union(i*m+j, (i-1)*m+j+1);
            }
            if (i-1>=0 && j-1>=0 && arr[i-1][j-1]==1){
                dset->Union(i*m+j, (i-1)*m+j-1);
            }
		}
	}


	int *c = new int[n * m];
	int numberOfIslands = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (arr[i][j] == 1){
				int x = dset->find(i * m + j);
				if (c[x] == 0){
					numberOfIslands++;
					c[x]++;
				}
				else c[x]++;
			}
		}
	}
    cout << "Number of Islands are : " << numberOfIslands << endl;
}


int main(void)
{
	vector<vector<int> > arr;
    int n = 5;

    cout << "Enter the values in the 2d matrix" << endl;
    for(int i=0;i<n;i++){
        vector<int> a;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        arr.push_back(a);
    }

    countNumberOfIslands(arr);
    return 0;
}
