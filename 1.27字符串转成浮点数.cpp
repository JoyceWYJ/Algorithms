#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int compareVersion2(string version1, string version2) {  
        int lev1=0,lev2=0;  
        int id1=0,id2=0;  
        while(id1!=version1.length()||id2!=version2.length()){  
            lev1=0;  
            while(id1<version1.length()){  
                if(version1[id1]=='.'){  
                    ++id1;  
                    break;  
                }  
                lev1=lev1*10+(version1[id1]-'0');  
                ++id1;  
            }  
              
            lev2=0;  
            while(id2<version2.length()){  
                if(version2[id2]=='.'){  
                    ++id2;  
                    break;  
                }  
                lev2=lev2*10+(version2[id2]-'0');  
                ++id2;  
            }  
             cout<<lev1<<"   "<<lev2<<endl; 
            if(lev1>lev2){  
                return 1;  
            }else if(lev1<lev2){  
                return -1;  
            }  
        }  
        return 0;//equal  
    }  
int compareVersion(string version1, string version2) {
        int n1=version1.length();
        int n2=version2.length();
        int point1=0,point2=0;
        float num1=0.0,num2=0.0;
        for(int i=0;i<n1;i++){
            if(version1[i]=='.'){
                point1=i;
                break;
            }
        }
        for(int i=0;i<n2;i++){
            if(version2[i]=='.'){
                point2=i;
                break;
            }
        }
        cout<<"point1:"<<point1<<" point2:"<<point2<<endl;
        if(point1==0){
            for(int i=0;i<n1;i++){
                num1*=10;
                num1+=version1[i]-48;
            }
        }
        else{
            for(int i=0;i<point1;i++){
                num1*=10;
                num1+=version1[i]-48;
            }
            for(int i=point1+1;i<n1;i++){
                num1+=pow(0.1,i-point1)*(version1[i]-48);
            }
        }
        
        if(point2==0){
            for(int i=0;i<n2;i++){
                num2*=10;
                num2+=version2[i]-48;
            }
        }
        else{
            for(int i=0;i<point2;i++){
                num2*=10;
                num2+=version2[i]-48;
            }
            for(int i=point2+1;i<n2;i++){
                num2+=pow(0.1,i-point2)*(version2[i]-48);
            }
        }
        cout<<num1<<"   "<<num2<<endl;
        const float E=0.000001;
        if(num1>num2)
            return 1;
        else if((num1-num2)>=-E && (num1-num2)<=E)
            return 0;
        else
            return -1;
    }
int main(){
	string a="12.1";
	string b="12.10";
	cout<<compareVersion2(a,b);
	return 0;
} 
