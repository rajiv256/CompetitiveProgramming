/* Resilience is the greatest of all virtues */
/* Code written by rajiv. */

// Problem  : http://www.spoj.com/problems/SUBXOR/
// Description : Given an array of N positive integers, find the number of sub-arrays with Xor sum < K
// Tags     : Trie , Sub-array XOR

// Solution :
/*
The approach is simple(well not so much!).

Suppose 0,N-1 are the bounds of the array, Xor of the sub-array i->j i.e., Xor[i,j] = Xor[i,N-1]^Xor[j+1,N-1]

So it is possible to obtain the Xor of any sub-array just using the suffix Xors.

Now we can run a nested loop over i=0->N-1 and j=0->N-1 and calculate the no.of sub-arrays' Xor is < K. This approach takes O(N^2), as we are running two loops. For N=10^5 this will not pass.

If we observe closely, Instead of searching over all the domain space(i.e.., (i,j) pairs), Why not we search over all bit patterns possible which are less than K? Since K is <= 10^6, We just need to search over all 20 bit patterns. This is about 2^20 patterns for each suffixXor . So for each suffix Xor we need to find the 20 bit patterns which on Xor-ed with the suffix Xor will give a value < K. Where do we get these 20-bit patterns from? As we can observe for a suffix-array starting at i-th index, it is enough to check the suffix-array Xors that occured before the current suffix array Xor. That will cover all the required sub-arrays, right? But will this work in a given time? No! Why? For each suffix-array Xor there are O(2^20) ~ O(N) patterns we need to check. The total complexity will now become O(N^2).

Fortunately there is a work around! In the above method, we are enumerating each possible 20 bit pattern of the previous Xors for each Xor. Only after calculating each Xor we are comparing with 'K'. This elevates the complexity to O(N) for each suffix-array.
But suppose if the i-th bit of K is '1' and i-th bit of the suffix added is '0' the entire left child can be abandoned. as for sure all the previous suffix xors that went into that tree will be less than K. In a similar way for each case we can prune the search space to half! Which makes the query O(1). We just need 20 iterations.

Just note that we go the left child when the current trie bit is 0. And right if currbit is 1.
*/


 int bits[22] ;
 int N, K , B = 21 ;

 struct Node{
     ll cnt ;
     struct Node* next[2] ;

     Node(){
         cnt = 0 ;
         next[0] = NULL ; next[1] = NULL;
     }
 };
 deque<int> num2bits(int num){
     int B = 21 ;
     deque<int> dq ;
     while (B>=0){
         dq.push_back(((num&(1<<B))==0)?0:1) ;
         B--  ;
     }
     return dq ;
 }


 void addI(Node* root, int num){

     for(int i = 21 ; i >= 0 ; i--){
         int bit = (num>>i)&1 ;
         if (root->next[bit]==NULL){
             root->next[bit] = new Node() ;
         }
         root = root->next[bit] ;
         ++root->cnt ;
     }
 }

 ll query(Node* root, int num){

     ll ret = 0 ;
     for(int i = 21 ; i >= 0 ; i--){
         if(root==NULL){

            return ret ;
         }
         bool kbit = (K>>i)&1 ;
         bool sbit = (num>>i)&1 ;

         if (kbit){

             if (sbit){
                 ret += (root->next[1]==NULL)?0:root->next[1]->cnt ;
                 root = root->next[0];
             }
             else{

                 ret += (root->next[0]==NULL)?0:root->next[0]->cnt ;
                 root = root->next[1] ;
             }
         }
         else{
             if (sbit){
                 root = root->next[1] ;
             }
             else{
                 root= root->next[0] ;
             }
         }
     }

     return ret ;

 }

 int main(){
 	ios_base::sync_with_stdio(false) ;
 	cin.tie(nullptr) ;

    int  T ; cin >> T ;
    while (T--){
        cin >> N >> K ;
        int A[N] ; ll Xor = 0;
        for(int i = 0 ; i < N ; i++){
            cin >> A[i] ;
            Xor^= A[i] ;
        }
        ll suffxor[N] ; suffxor[0] = Xor ;
        for(int i = 1 ; i < N ; i++){
            suffxor[i] = suffxor[i-1]^A[i-1] ;
        }

        Node* root = new Node() ;
        ll ans = 0 ;
        addI(root,0) ;
        for(int i = 0 ; i < N ; i++){

            ans += query(root,suffxor[i]) ;
            addI(root,suffxor[i]) ;
        }


        cout << ans << el ;
    }

 }
