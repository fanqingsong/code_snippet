#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> >v[2];

void wy(int x,int a){
 for(int i1=1;i1<=x-2;i1++){
  for(int i2=1;i2<=x-i1-1;i2++){
   int i3=x-i1-i2;
   if(i3<=0)continue;
   vector<int>vec;
   vec.push_back(i1);
   vec.push_back(i2);
   vec.push_back(i3);
   v[a].push_back(vec);
  }
 }
}

int main(){
 int h1,h2,h3,w1,w2,w3;
 cin>>h1>>h2>>h3>>w1>>w2>>w3;
 
 wy(h1,0);
 wy(h2,1);
 
 int ans=0;
 for(int i=0;i<v[0].size();i++){
  for(int j=0;j<v[1].size();j++){
   vector<int>v1,v2,v3;
   v1=v[0][i];
   v2=v[1][j];
   v3.push_back(w1-v1[0]-v2[0]);
   v3.push_back(w2-v1[1]-v2[1]);
   v3.push_back(w3-v1[2]-v2[2]);
   if(v3[0]+v3[1]+v3[2]==h3 and v3[0]>0 and v3[1]>0 and v3[2]>0)ans++;
  }
 }

 cout<<ans;
 return 0;
}
