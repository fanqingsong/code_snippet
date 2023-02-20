#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
int dp[16][1006];

int main(){
	int h,w,k;

	cin>>h>>w>>k;

	vector<string> v(h+1);

	for(int i=1;i<=h;i++){
		string s;
		cin>>s;
		v[i]+=' ';
		v[i]+=s;
//		cout<<v[i]<<endl;
	}

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++)
		{
			dp[i][j]=dp[i][j-1]+v[i][j]-'0';
//			cout<<dp[j][i]<<" ";
		}
//		cout<<endl;
	}

	int ans=INT_MAX;
	int n=pow(2,h-1);
	
	for(int i=0;i<n;i++){
//		cout << "---------------------------------------" << endl;
		int cuts_num = 0;

		// horizontal cuts
		bool hcuts[15]={false};
		hcuts[0]=true;
		hcuts[h]=true;
		
		int j=1;
		for(int num=i; num>0; num/=2){
			if(num%2==1){
//				cout << "horizontal cut = " << j << endl;
				cuts_num++;
				hcuts[j] = true;
			}
			
			j++;
		}

//		cout << "hcuts number = " << cuts_num << endl;

		// left bound
		int lbound = 0;
		// cannot cut vertically
		int vcannot_cut = false;

		while(lbound < w){
			int curpos=lbound;
			int presee=1;
			
//			cout << "lbound = " << lbound << endl;
			
			while(presee){
				int white_cnt = 0;
				bool great_k = false;
				
                for(int i=1; i<=h; i++){
                	white_cnt += dp[i][curpos+presee]- dp[i][lbound];
                	
                	if(white_cnt>k)
                    {
                        great_k=true;
                        break;
                    }
                    
                    if(hcuts[i]){
                    	white_cnt=0;
					}
				}
				
				if(great_k){
					presee >>= 1;
				}else{
					curpos += presee;
					presee = min(presee*2, w-curpos);
				}
			}

            if(curpos == lbound){
            	vcannot_cut = true;
				break;
			}
			
			lbound = curpos;
            presee = 1;
            
            /* to right end */
            if (lbound == w){
            	break;
			}
			
            cuts_num++;
		}
		
		if(vcannot_cut){
			continue;
		}
		
//		cout << "cuts_num = " << cuts_num << endl;
		
		ans = min(ans, cuts_num);
	}

	cout<<ans<<endl;
}

