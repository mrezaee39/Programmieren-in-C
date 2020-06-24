## Routing
In this exercise you will implement a basic
IPv4 subnet matching. Your task is to
match a given ip address to the correct
gateway. While you will also have to parse
strings to convert them to numbers, the main
focus of this exercise lies on creating the correct
bit patterns and match them against each other.
The network IDs are given as strings of the format

    a.b.c.d/e

where `a`, `b`, `c`, and `d` are decimal numbers between `0-255`
and `e` denotes the number of continuous most-significant
bits, that make up the network address.
This means that the network ID `192.168.2.0/24` is the
ID that corresponds to all addresses in the range `192.168.2.0`-`192.168.2.255`.
Define fitting data structures to represent the following routing table

| network id      | gateway       |
|-----------------|---------------|
| 243.854.33.0/24 |243.854.33.1   |
| 243.854.0.0/16  |243.854.0.100  |
| 0.0.0.0/0       |192.168.0.100  |
| 192.168.208.0/19|192.168.192.100|

Write a function `resolve` that takes a destination address as a string of format `a.b.c.d`
and returns the address of the most specific gateway. The most specific gateway
is the one with longest matching prefix. That means for the above routing table
the function should return the gateway `243.854.0.100` for the destination
address `243.854.2.5`. But for the destination address `243.854.33.5`
the gateway `243.854.33.1` should be returned.

Use the `routing.{c,h}` files for your implementation and the `main.c` file
to try and test whether your code behaves as you expect.


*Hint: There are different ways to iteratively solve this exercise.
The two main problems to solve here are:*

1. *conversion of strings to numbers and vice versa*
2. *creating and matching the correct bit patterns against each other to resolve to the correct gateway*

*Although the first impulse might be to start with the first point, starting with the second point
might be easier for you.*