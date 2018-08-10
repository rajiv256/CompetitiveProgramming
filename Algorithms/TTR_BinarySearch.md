- Always select a predicate that is efficiently evaluated and so that binary seacrch can be applied.

- Find a predicate that gives a series of __yes__ followed by __no__ or viceversa.
- Decide on what you are looking for and make sure that always stays in the search space.


- If the algorithm contains only integers in the search space make sure that the algorithm is tested for a two membered search space where the first element returns __No__ and the second returns __Yes__ to the predicate.

- Veriify that upper and lower bounds are not overly constrained. It is usually better to relax them as long as it doesn't break the authenticity of the predicate.

-------------------------------------------------------------


**Step 1 :**  Set the lower and upper bounds of the search space so that the predicate doesn't break.

**Step 2 :** Calculate the appropriate mid value.

**Step 3 :** Check the truth value of the mid wrt to the predicate. Based on your requirements, change the bounds carefully as long as _low<high_

**Step 4 :** Return low. And check if the value exists.

**Step 5 :** Test the solution for a two element search space where the first element may return _false_ to  the predicate and the second element may return _true_ to the predicate.

**Step 6 :** Check for locking above. If locking indeed exists, change the calculation of `mid = lo+(high-lo+1)/2` 
