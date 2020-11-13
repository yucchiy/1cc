#!/bin/bash
assert() {
    expected="$1"
    input="$2"

    ./1cc "$input" > tmp.s
    cc -o tmp tmp.s
    ./tmp
    actual="$?"

    if [ "$actual" = "$expected" ]; then
        echo "OK: $input => $actual"
    else
        echo "NG: $input => $expected expected, but got $actual"
        exit 1
    fi
}

assert 0 "0;"
assert 42 "42;"

echo OK