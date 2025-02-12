### Probe Hashing

Probe hashing is Closed Hashing method for storing values inside of HashMap.
Map contains an array of keys where the values can be stored. 

Example of a hash function:

```
    f(x) = x % 10
```

Example of linear probing:
```
    f'(x) = [f(x) + f(i)]
    f(i) = i, i = 0, 1, ...
```

Loading factor lambda = n / hashSize, where 'n' is number of values being stored, i.e. the number of 
values that are to be mapped on the hash map keys of size 'hashSize'.
We are assuming that the keys are uniformly distributed with the factor lambda.

Number of elements that can be stored in Probed hash list is hashSize / 2. We need to have 
empty spaces due to the fact that probing stop criteria is empty space in hash map.

Average successful search of linear probing:
```
    o(t), t = (1 / lambda) * ln(1 / (1 - lambda))
```

Average unsuccessful search of linear probing:
```
    o(t), t = 1 / (1 - lambda)
```

Example of quadratic probing:
```
    f'(x) = [f(x) + f(i)] % hashSize
    f(i) = i^2, i = 0, 1, ...
```

Average successful search of quadratic probing:
```
    o(t), t = -log(1 - lambda), log with base 'e'
```

Average unsuccessful search of quadratic probing:
```
    o(t), t = 1 / (1 - lambda)
```
### Double Hashing

There can be a closed double hashing method. The idea is to use the primary hashing function 
and if a collision is detected we use the combination of primary and secondary hashing functions
to get a valid result.

Example of double hashing:
```
    h1(x) = x % 10
    h2(x) = R - (x % R), R is a primary number smaller than size of hash table

    h'(x) = [h1(x) + i * h2(x)] % 10, i = 0, 1, 2, ... -> increments with each collision
```