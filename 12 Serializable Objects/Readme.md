# 12 - Serializable Objects
This weeks exercise will combine many of the things you learned so far.
The goal is to write a very basic library that can be used to represent
JSON objects and serialize them.
See https://www.json.org/json-en.html for summary of the JSON
syntax. We will however concentrate on just a subset of JSON.
We will for now arrays and numbers. That means that we assume that
every JSON Object is basically a nested dictionary of strings.
We also assume that all strings are pure ASCII and no unicode is required.

Design and implement an API that can be used to construct
JSON Objects and write them to files using the functions in
the `stdio.h` header. We do not need to read and parse json
files for now.