# Example 

For example, consider the following list of section assignment pairs:
```
.234.....  2-4
.....678.  6-8

.23......  2-3
...45....  4-5

....567..  5-7
......789  7-9

.2345678.  2-8
..34567..  3-7

.....6...  6-6
...456...  4-6

.23456...  2-6
...45678.  4-8
```

* Within the first pair of Elves, the first Elf was assigned sections 2-4 (sections 2, 3, and 4), while the second Elf
was assigned sections 6-8 (sections 6, 7, 8).
* The Elves in the second pair were each assigned two sections.
* The Elves in the third pair were each assigned three sections: one got sections 5, 6, and 7, while the other also got
7, plus 8 and 9.

Some of the pairs have noticed that one of their assignments fully contains the other. For example, 2-8 fully contains
3-7, and 6-6 is fully contained by 4-6. In pairs where one assignment fully contains the other, one Elf in the pair
would be exclusively cleaning sections their partner will already be cleaning, so these seem like the most in need of
reconsideration. In this example, there are 2 such pairs.