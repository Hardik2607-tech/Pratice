#include<iostream>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int ans = 0;

    int sunnet[2][2] = {{a,b},{b,a}};
    int slavic[2][2] = {{c,d},{d,c}};

    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
        int win = 0;
        int lose = 0;

        for(int k=0;k<2;k++){
          if(sunnet[i][k]>slavic[j][k]){
            win++;
          }
          else if(sunnet[i][k]<slavic[j][k]){
            lose++;
          }
        }
        if(win>lose) ans++;
      }
    }
    cout<<endl<<ans<<endl;
  }
  return 0;
}