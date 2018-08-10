#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int de ;
int ins ; 
int rep ; 

int isAnag(char *s1 , char *s2){
	int i ; 
	int count = 0 ; 
	if (strlen(s1)!= strlen(s2))
		return 0 ; 
	for ( i = 0 ; i < strlen(s1) ; i++){
		count += s1[i] - s2[i] ;  
	}
	if (count == 0)
		return 1 ; 
	return 0 ; 
	
}

int min(int a , int b){
	if (a > b){
		return b ; 
	}
	return a ; 
}



int makeAdjustments(int[] arr1 , int[] arr2){
	int v1 = 0 , int v2 = 0 ;
	int i ; 
	for ( i= 0 ; i < 26 ; i++){
		if (arr1[i] < arr2[i]){
			v1 += arr2[i] - arr1[i] ; 
		}
	}
	return v1 ; 
}



int main(){
	int t ; 
	scanf("%d",&t); 
	int i = 0 ;
	char *s1 = (char*)malloc(sizeof(char)) ; 
	char *s2 = (char*)malloc(sizeof(char)) ; 
	
	while ( i < t ){
		scanf("%s%s",s1,s2); 
		
		scanf("%d%d%d",&de,&ins,&rep) ; 
		
		if (isAnag(s1 , s2)){
			printf("0\n"); 
			return 0; 
		}
		
		int cost = 0 ; 
	 
		int arr1[26];
		int arr2[26]; 
		int i ; 
		for (i = 0 ; i < 26 ; i++){
			arr1[i] = 0 ;
			arr2[i] = 0 ; 
		}
		for (i = 0 ; i < 26 ; i++){
			arr1[s1[i]-97] += 1 ;
		}
		for (i = 0 ; i < 26 ; i++){
			arr2[s2[i]-97] += 1 ;
		}
		
		int v1 = 0 , v2 = 0 ;
		int nins = strlen(s2) - strlen(s1) ;
		cost += ins * nins ; 

		for ( i = 0 ; i < 26 ; i++){
			if (nins>= 0){
				if (arr1[i] < arr[2]){
					if (arr2[i] - arr[i] > nins){
						arr1[i] += nins ; 
						nins = 0 ; 
					}
					else {
						arr1[i] = arr2[i] ; 
						nins -= (arr2[i] - arr1[i]) ;
					}
				}
			}
		}
		
		cost += makeAdjustments(arr1 , arr2) * min(rep , (de + ins)) ; 
		
		printf("%d\n",cost) ; 
		
		i++ ; 
	}
	return 0 ;
}
