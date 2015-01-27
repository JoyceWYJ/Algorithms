//2015-1-22
//从一长串中找到最长的连续英文字符 
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

bool isLegal(char a){
	if((a>='a' && a<='z')||a==' '){
		return true;
	}
	return false;
}

char* GetLongestStr(char* str){
	assert(str!=NULL);
	
	int strn = strlen(str);
	assert(str>0);
	
	char* longestStr;
	char* currentStr;
	int longestLen=0,currentLen=0;
	
	int i=0;
	while(i<strn){
		
		while(!isLegal(str[i]))
			++i;
			
		currentStr=&str[i++];
		currentLen++;
		while(isLegal(str[i])){
			currentLen++;
			i++;
		}
		if(currentLen >longestLen){
			longestStr = currentStr;
			longestLen = currentLen;
			currentStr = NULL;
			currentLen = 0;	
		}
		else{
			currentStr = NULL;
			currentLen = 0;	
		}
	}
	
	char* result = new char[longestLen+1];
//	memcpy(result,longestStr,longestLen);
	for(int i=0;i<longestLen;i++)
		result[i]=longestStr[i];
	result[longestLen]='\0';
	
	return result;
} 

int main(){
	char* a="2hi4hello world464";
	cout<<GetLongestStr(a);
}
