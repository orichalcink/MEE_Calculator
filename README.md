# MEE Calculator
Mathematical expression evaluator by chalcinxx.
This works very similarly to an interpreted programming language, but does not include any statements. I wasn't going for efficiency, as the calculator taking 1 millisecond longer does not change anything for me.

[A great reference for creating an interpreted language in typescript](https://www.youtube.com/playlist?list=PL_2VhOvlMk4UHGqYCLWc6GO8FaPl8fQTh), as I said before, a MEE is very similar to this.

### How it works:

User Input --> Lexer --> Parser --> Evaluator --> Result

1. Retrieve input from the user.
2. Lexer converts the input into tokens and checks for any unknown characters and keywords. In this case, it also handles constants.
3. Parser reads through the tokens, produces the AST tree and checks if the syntax is valid.
4. Evaluator evaluates the AST tree and produces the final result. Any functions found are called in this step.

### Features:

- Constants: pi, e, phi, gamma and tau.
- Functions: sin, cos, tan, sqrt, log, randf, randi and many more.
- Operators: +, -, /, *, ^ (exponentiation), ! (factorial) and % (not modulus, but percent instead).
- Parentheses.
