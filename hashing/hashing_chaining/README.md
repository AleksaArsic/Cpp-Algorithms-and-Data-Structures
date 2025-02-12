### Chain Hashing

Chain hashing is Open Hashing method for storing values inside of HashMap.
Map contains pointers to the root nodes of linked lists and from there we can store 
and access multiple values that are mapped to the same key by the hashing function.

Example of a hash function:

```
    f(x) = x % 10
```

Loading factor lambda = n / hashSize, where 'n' is number of values being stored, i.e. the number of 
values that are to be mapped on the hash map keys of size 'hashSize'.
We are assuming that the keys are uniformly distributed with the factor lambda.