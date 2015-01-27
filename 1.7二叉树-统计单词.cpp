#include<iostream>
#include<string.h> 
#include<stdlib.h>
using namespace std;

typedef struct node{
	char str[50];
	struct node *lchild,*rchild;
	int count;
}TreeNode;

TreeNode *root=NULL;
int n=0;

void mid_cal(TreeNode *root){
	if(root!=NULL){
		mid_cal(root->lchild);
		cout<<root->str<<":"<<((double)(root->count)/(double)n)*100<<endl;
		mid_cal(root->rchild);
	}
}

void insertBST(TreeNode *&root,char s[]){
	if(root==NULL){
	//	TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
		TreeNode *p = new TreeNode;
		strcpy(p->str,s);
		p->lchild=NULL;
		p->rchild=NULL;
		p->count=1;
		root=p; 
	}
	else{
		if(strcmp(s,(root->str))==0){
			(root->count)++;
			return;
		}
		else if(strcmp(s,(root->str))<0){
			insertBST(root->lchild,s);
		}
		else{
			insertBST(root->rchild,s);
		}
	}
}

int main(){
	char s[50];
	while(gets(s)){//½áÊøctrl+z 
		insertBST(root,s);
		n++;
	}
	mid_cal(root);
	return 0;
} 
