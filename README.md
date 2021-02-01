# Quick Calc

Quick calculator for performing operations on numbers in multiple bases on the command line.

Supported bases | Example
-|-
Decimal | 1234 |
Hexadecimal | 0x4d2 ("0x" then digits) |
Octal | 02322 ("0" then digits) |
Binary | 0b10011010010 ("0b" then bits) |
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

Negative numbers are supported. Place a negative sign to the left of the number to make it negative. Numbers should not be inputted and will not be outputted with the 2's complement form. Bitwise operations are done with the 2's complement form.

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
Addition | <div align="center"> **+** </div>|
Subtraction | <div align="center"> **-** </div> |
Multiplication | <div align="center"> **.** or **\*** </div> |
Integer Divison | <div align="center"> **/** </div> |
Modulus | <div align="center"> **%** </div> |
Bitwise Addition | <div align="center"> **&** or **a** or **A** </div> |
Bitwise Or | <div align="center"> **\|** or **o** or **O** </div> |
Bitwise Xor | <div align="center"> **^** or **x** or **X** </div> |
Bitshift Left | <div align="center"> **<** or **l** or **L** </div> |
Bitshift Right | <div align="center"> **>** or **r** or **R** </div> |

Any set of characters will work for an operation as long as the first character in the sequence is one of the ones above.

Ex. "+dsa-a.4"  &rarr;  '+'  &rarr; Addition

The following characters on their own won't work as intended on certain operating systems unless the operation is in quotes:

Windows: **& | ^ < \>** (characters **& | < \>** can't be used at all in the operation)
Linux: **\* & | < \>** (characters **& | < \>** can't be used at all in the operation)
