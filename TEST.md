# Rod Cutting Test Cases

## Test Case 1: Rod Length 45
**Input:**
- Rod Length: 45
- Available Pieces:
  ```
  10, 5
  15, 7
  20, 10
  ```

**Output:**
```
2 @ 20 = 20
1 @ 10 = 5
Remainder: 5
Value: 25
```

## Test Case 2: Perfect Fit with Smaller Pieces
**Input:**
- Rod Length: 30
- Available Pieces:
  ```
  5, 2
  10, 4
  25, 10
  ```

**Output:**
```
1 @ 25 = 10
1 @ 5 = 2
Remainder: 0
Value: 12
```

## How to Run Tests
1. Compile the program:
   ```bash
   gcc main.c -o main
   ```

2. Run this 
    ```bash
    chomd +x test.sh
    ```
        

