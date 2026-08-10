#include<iostream>
using namespace std;

int main(){
  string s;
  cin>>s;

  int n = s.size();

  for(int i=0;i<n;i++){

    if(i%2==0){

        if(s[i]>='A' && s[i]<='Z'){
          s[i] ='A' + (s[i] - 'A' + 2)%26 ;
        }

        else if(s[i]>='a' && s[i]<='z'){
          s[i] ='a' + (s[i] - 'a' + 2)%26 ;
        }

        else if(s[i]>='0' && s[i]<='9'){
          s[i] = '0' + (s[i] - '0' + 2)%10 ;
        }

        else{
          s[i] = s[i]+2;
        }
    }

    else{

        if(s[i]>='A' && s[i]<='Z'){
          s[i] ='A' + (s[i] - 'A' - 1 + 26)%26 ;
        }

        else if(s[i]>='a' && s[i]<='z'){
          s[i] ='a' + (s[i] - 'a' - 1 + 26)%26 ;
        }

        else if(s[i]>='0' && s[i]<='9'){
          s[i] = '0' + (s[i] - '0' - 1 + 10)%10 ;
        }

        else{
          s[i] = s[i] + 2;
        }
    }
  }

  cout<<endl<<s<<endl;
  return 0;
}