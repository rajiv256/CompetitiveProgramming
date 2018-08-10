- Euclid's algorithm takes the highest number of steps if the two numbers are the consecutive elements of a Fibonacci sequence. In case it will take same number of steps as the index of the higher element in the seq 1,2,3,5,8,...
- In the same way to get n-steps in the Euclid's algorithm the polynomials to be chosen are `Pn+1 = x.Pn + Pn-1`. Choosing Pn+1 and Pn takes atleast n+1 steps to stop starting from `P0 = 1` and `P1 = x`. Also it is known that using *MOD* to the coefficients will let the method complete in n+1 steps.

- While doing DP try to do by bottom-up or top-down. Try avoiding memoisation as much as possible. Because most of the cases it gives timeOut.

- The number of sequences that sum up to 't' is `g(t) = 2^(t-1)`
- The number of sequences that sum up to 't' with gcd 1 is
    > f(t) = g(t) - ∑ f(t/ti)  i = 2,3,4,... since t1 = 1
    > Also g(t) = ∑ f(t/ti)  i = 1,2,3,...  

- Stirling numbers of the second kind denoted by S(n,k) is the number of ways a set with n-elements can be partitioned into k non-empty subsets.
Its recurrence relation is given by `S(n,k) = S(n-1,k-1) + k*S(n-1,k)`

- Bell number is the number of ways a set with n-elements can be partitioned into non-empty subsets.

             `Bn = ∑ Bk n-1Ck`
    It can also be seen that `Bn = ∑ S(n,k)` *k = 1, 2, ..., n*
