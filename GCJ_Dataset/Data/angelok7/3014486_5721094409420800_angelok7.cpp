#include <iostream>
#include <fstream>

using namespace std;

int arr[1010];
int t[1010];
int main()
{
	int n,N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;

	for(n=0;n<N;n++){
		int num,i,j,z,temp;
		fin>>num;
		for(i=0;i<num;i++) fin>>arr[i];
		
		int count;
		int min = 100000000;

		for(i=0;i<num;i++){
			t[0] = arr[0];
			count = 0;
			for(j=1;j<i;j++){
				t[j] = arr[j];
				if(t[j-1] > t[j]){
					for(z=j;z>0;z--){
						if(t[z-1] > t[z]){
							count++;
							temp = t[z];
							t[z] = t[z-1];
							t[z-1] = temp;
						}
						else
							break;
					}
				}
			}
			for(j=i+1;j<num;j++){
				t[j] = arr[j];
				if(t[j-1] < t[j]){
					for(z=j;z>i;z--){
						if(t[z-1] < t[z]){
							count++;
							temp = t[z];
							t[z] = t[z-1];
							t[z-1] = temp;
						}
						else
							break;
					}
				}					
			}
			if(i > 0 && t[i-1] > t[i]){
				for(z=i;z>0;z--){
					if(t[z-1] > t[z]){
						count++;
						temp = t[z];
						t[z] = t[z-1];
						t[z-1] = temp;
					}
					else
						break;
				}
			}
			if(min > count)
				min = count;


			t[0] = arr[0];
			count = 0;
			for(j=1;j<=i;j++){
				t[j] = arr[j];
				if(t[j-1] > t[j]){
					for(z=j;z>0;z--){
						if(t[z-1] > t[z]){
							count++;
							temp = t[z];
							t[z] = t[z-1];
							t[z-1] = temp;
						}
						else
							break;
					}
				}
			}
			for(j=i+1;j<num;j++){
				t[j] = arr[j];
				if(t[j-1] < t[j]){
					for(z=j;z>i;z--){
						if(t[z-1] < t[z]){
							count++;
							temp = t[z];
							t[z] = t[z-1];
							t[z-1] = temp;
						}
						else
							break;
					}
				}					
			}
			if(min > count)
				min = count;

		}		
		
		fout<<"Case #"<<n+1<<": "<<min<<endl;
	}


	return 0;
}


//fout.setf(ios::fixed);
//fout.precision(6);