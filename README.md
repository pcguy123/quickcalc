# Quick Calc

Quick calculator for performing operations on numbers in multiple bases on the command line.

Supported bases | Example
-|-
Decimal | 1234
Hexadecimal | 0x4d2 ("0x" then digits)
Octal | 02322 ("0" then digits)
Binary | 0b10011010010 ("0b" then dits)
&nbsp;

Order of operations is strictly left to right.

Ex.
```
qc.exe 234 + 1 * 2 . 4 - 5 / 25
Dec: 75
Hex: 0x4b
Oct: 0113
Bin: 0b1001011
```
&nbsp;

Negative numbers are supported. Place a negative sign to the left of the number to make it negative (no 2's complement).

Ex.
```
qc.exe 5 + -10
Dec: -5
Hex: -0x5
Oct: -05
Bin: -0b101
```
&nbsp;

Supported operations | Character
-|-
Addition | +
Subtraction | -
Multiplication | . or \* ('\*' does not work on Linux)
Integer Divison | /
