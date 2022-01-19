#include<bits/stdc++.h>

using namespace std;

vector<int> arrayUnion(vector<int> v1, vector<int> v2){
   vector<int> a;

   int i = 0, j = 0;

   while(i != v1.size() and j != v2.size()){
       
       if(v1[i] == v2[j]){
           a.push_back(v1[i]);
           i++; j++;
       }
       else if(v1[i] < v2[j]){
           a.push_back(v1[i]);
           i++;
       }
       else if(v2[j] < v1[i]){
           a.push_back(v2[j]);
           j++;
       }
   }

   if(i != v1.size()){
       while(i != v1.size()){
           a.push_back(v1[i]);
           i++;
       }
   }
   else if(j != v2.size()){
       while(j != v2.size()){
           a.push_back(v2[j]);
           j++;
       }
   }

   return a;
}

vector<int> arrayIntersection(vector<int> v1, vector<int> v2){
    vector<int> a;

    int i = 0, j = 0;

    while(i != v1.size() and j != v2.size()){
        if(v1[i] == v2[j]){
            a.push_back(v1[i]);
            i++; j++;
        }
        else if(v1[i] < v2[j]){
            i++;
        }
        else if(v2[j] < v1[i]){
            j++;
        }
    }

    return a;
}

set<int> arrayUnionSet(vector<int> v1, vector<int> v2)
{
    set<int> s;
    for(auto x: v1) s.insert(x);
    for(auto x: v2) s.insert(x);

    return s;
}

int main(void){
    // vector<int> v1 {1, 4, 6, 8, 14, 16, 19, 21};
    // vector<int> v2 {2, 4, 5, 6, 8, 9, 11, 14, 16, 17, 19, 20, 21, 23, 26};

   
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);

    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }

    for(int i = 0; i < m; i++){
        cin >> v2[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> ansU = arrayUnion(v1, v2);
    set<int> ansS = arrayUnionSet(v1, v2);
    vector<int> ansI = arrayIntersection(v1, v2);

    cout << ansS.size() << " " << ansU.size() << endl;

    //for(int x: ansU) cout << x << " ";
    //cout << endl;
    //for(int x: ansI) cout << x << " ";
    //cout << endl;

    return 0;
}
