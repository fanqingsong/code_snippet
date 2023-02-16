// Code 2
// O(2^H*(log W)*H)
#include<bits/stdc++.h>
using namespace std;
const bool ZJS_AK_IOI=1;//fast read&write or not
int n,m,x;

char c[50][1020];

int s[50][1020];
bool hlines_used[50];

int ans=INT_MAX;

void solve()
{
    cin>>n>>m>>x;
    
    /*
	for every row, calculate prefix sum from left to right
	for example
	1 2 3
	--->
	1 3 6
	*/
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c[i][j];
            s[i][j]=s[i][j-1]+(c[i][j]=='1');
            // cout<<s[i][j]<<" \n"[j==m];
        }
    }
    
    /*
	regarding to every case of row combination,
	look into splitting it vertically
	
	explaination for 1 << n-1
	n-1 : there are n-1 lines for cutting
	for example:
	1 2 3
	-------- line one for cutting
	4 5 6
	-------- line two for cutting
	7 8 9
	
	1<<n-1 : there are 2^(n-1) cases of row combination
	for example:
	4 cases for cutting regarding to 3 rows
	
	list:
	empty
	line one
	line two
	line one & line two
	
	bits presentation:
	1 1 == n-1 == 2
	0 0 --- empty
	0 1 --- line one
	1 0 --- line two
	1 1 --- line one & line two
	
	k is the bits presetation for every case
	*/
    for(int k=0;k<(1<<n-1);k++)
    {
    	/*
		how many lines are selected for cutting
		*/
        int cuts_num=0;
        
        /*
		hlines_used arrary to record which lines are in the this combination case
		h means horizontal
		hlines_used[1] -- line one
		hlines_used[2] -- line two
		.....
		*/
        memset(hlines_used,0,sizeof(hlines_used));
        
        /*
		kk is the power(2^kk) of line in the bits presentation
		such as
		1 1
		line one is corresponding to later one, with the power 0 -- 01 = 0*2^1 + 1*2^0
		line two is corresponding to former one, with the power 1 -- 10 = 1*2^1 + 0*2^0
		*/
        for(int kk=0;kk<n;kk++)
        {
        	/*
			k is the bits presentation of row combination case
			decrease the power of k by kk
			it means making the bit of kk power to rightmost position
			for example:
			1010 >> 1 ==> 101
			then we can use 101&1 == 1 to test if the power kk bit position are occupied
			i.e. line kk+1 is selected for cutting
			so set hlines_used[kk+1] = 1
			*/
            if((k>>kk)&1)
            {
                hlines_used[kk+1]=1;
                cuts_num++;
            }
            // cout<<f[kk+1]<<" \n"[kk==n-1];
        }
        
        /*
		Is there one possible way to cut vertically
		i.e. cn find vertical cuts
		such as
		1 2 | 3
		4 5 | 6
		7 8 | 9
		*/
        bool vcuts_ok=1;
        
        int lst=0;
        int p=1,step=0;
        
        while(step<m)
        {
            while(p)
            {
            	/*
            	white_num:
				how many white blocks are counted in one reactangle
				for example, there are four rectangles by this cuts:
				1 2 | 3
				-------
				4 5 | 6
				7 8 | 9
				*/
            	int white_num=0;
            	
            	/*
				Is the white blocks not great than x
				*/
                bool not_great_x = true;
                
                /*
				for all horizontal cuts sections,
				decide if all sections white blocks number is not great than x
				from 1st postion to step+p
				*/
                for(int i=1;i<=n;i++)
                {
                    white_num += s[i][step+p] - s[i][lst];
                    
                    if(white_num>x)
                    {
                        not_great_x = false;
                        break;
                    }
                    
                    if(hlines_used[i]){
						white_num=0;
					}
                }
                
                // cout<<step+p<<" "<<lst<<" "<<cnt<<endl;
                /*
				not_great_x == true
				means
				for (1st, step+p] interval of width direction
				the white block numbers of all horizontal cuts sections are not great than x
				then we can move step much further
				for example:
				1st = 0
				step = 0
				p = 1

				1 2 3
				-------
				4 5  6
				7 8  9

				there are two horizontal cuts sections
				section one:
				1 2 3
				
				section two:
				4 5  6
				7 8  9

				for section one, it will count one element 1
				|1| 2 3

				for section two, it will count two element 4 7
				|4| 5  6
				|7| 8  9
				*/
                if(not_great_x)
                {
					/*
					change current position to predicted postion
					step -> step + p
					*/
                    step += p;
                    
                    if(step==m){
						break;
					}

                    /*
					beacuse it is ok for (1st, step+p] interval
					we want to enlarge this interval to increase efficiency
					like gredient descent algorithm
					policy is to enlarge by multipling by two
					*/
                    p = min(p<<1, m-step);
                }
                else
                {
                    p>>=1;
                    
                    if(p==0)
                    {
                        if(step==lst){
                        	vcuts_ok=false;
						}

                        break;
                    }
                }
            }
            
            if(!vcuts_ok){
				break;
			}
			
            lst=step;
            p=1;
            
            cuts_num++;
        }
        
        if(vcuts_ok){
        	ans=min(ans,cuts_num);
		}
    }
    
    cout<<ans-1<<endl;
}

int main()
{
    if(ZJS_AK_IOI){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
    // int t;cin>>t;while(t--)
    solve();
    return 0;
}
