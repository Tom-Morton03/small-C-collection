# 🧮 CLI Calculator

A simple command-line calculator built in C. Supports basic arithmetic expressions and evaluates them using tokenization and postfix (Reverse Polish Notation) evaluation.

---

## 🚀 How to Use

1. **Build the project** using the makefile:
```bash
$ make
```

2. Run the calculator executable:
```bash
$ ./bin/calculator
```

3. Enter an arithmetic expression when prompted
➤ **Important:** Do **not** include any spaces.

#### ✅ Example:
```bash
$ Enter an expression: 2+3*4
$ Answer: 14.000000
``` 

---

## ✅ Current Features

- Supports basic arithmetic operations:
- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)
- Handles negative numbers.
- Respects **operator precedence**.

---

## 🧪 Example Expressions

| Input        | Output       |
|--------------|--------------|
| `2+3`        | `5.000000`   |
| `10-4/2`     | `8.000000`   |
| `5*-3+6/2`   | `-12.000000` |

---

## 🔮 Planned Features / Future Work

- Accept **whitespace** between tokens (e.g. `2 + 3 * 4`)
- Add support for **brackets** (e.g. `2 * (3 + 4)`)
- Add **exponentiation** (`^`)
- Support **scientific functions** like `sin`, `cos`, `sqrt`, etc.
- Improve **input validation** to catch unexpected or malformed input and display helpful error messages.

---

## ⚠️ Current Limitations

- Input **must not contain spaces**.
- Brackets and advanced functions are **not supported yet**.
- Invalid input may cause incorrect behavior or crashes.


