#include <stdio.h>

#define ll long long 

ll memory[1000000] = {0} ; 


ll funct(ll n){
	if (n < 12){
		return n ; 
	}
	if (n == 12){
		return 13 ; 
	}
	if (n < 1000000){
		if (memory[n] != 0){
			return memory[n] ; 
		}
	}
	ll two , three, four ; 

	two =  n/2 ; 
	three = n/3 ; 
	four = n/4 ; 

	ll k = funct(two) + funct(three) + funct(four) ; 
	if (n < 1000000){
		memory[n] = k ; 
	}
	return k ; 


}

int main(){
	ll n ; 
	while (scanf("%lld",&n)!= EOF){
		printf("%lld\n",funct(n)) ; 
	}

	return 0 ;

}