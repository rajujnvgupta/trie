/*  @rajujnvgupta
 * 27/dec/2019
 *	 
 */

//Note : by default NULL is put at end of every chain if linked list
//Leet code needed NULL assignment end of every chain and node
#include<bits/stdc++.h>
using namespace std;

class tries{
	public:
	
	tries *left;
	tries *right;
	tries(){}
};

void insrt(int num, tries *root){
	tries *temp = root;
	//tries *root = new tries(');
	for(int i = 31; i>=0; i--){
		int bit = (num >> i) & 1;
		if(bit == 0){
			if(temp -> left != NULL){
				//tries node = new tries();
				temp = temp->left;
				//temp = node;
			}else{
				tries *node = new tries();
                node->left = NULL;
                node->right = NULL;
				//node->data = 20;
				temp->left = node;
				 temp = node;
			 }
		 }else{
			 if(temp->right != NULL){
				 temp = temp->right;
			 }else{
				 tries *node = new tries();
                 node->left = NULL;
                 node->right = NULL;
				 ///node->data = 30;
				 temp->right = node;
				 temp = node;
			 }
		 }
	 }
}

int find_xor(int num, tries *root){
	tries *temp = root;
	//tries *temp = root;
	//tries *temp = new tries();
	int xor_value = 0;
	for(int i = 31; i >= 0; i--){
		int bit = (num >> i) & 1;
		if(bit == 0){
			if(temp->right != NULL){
				xor_value += (1<<i);
				temp = temp->right;
			}else{
				temp = temp->left;
			}
		}else{
			if(temp->left != NULL){
				xor_value += (1<<i);
				temp = temp->left;
			}else{
				temp = temp->right;
			}
		}
	}
	return xor_value;
}
			
int main(){
	int n;
	tries *root = new tries();
	root->left = NULL;
	root->right = NULL;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		insrt(arr[i], root);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(find_xor(arr[i], root), ans);
	}
	cout<<ans<<'\n';
	return 0;
}
