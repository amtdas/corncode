# valgrind-demo
## Valgrind examples to demonstrate basic linux memory debugging.
### Compile .c files
```gcc -g ex-test.c -o ex-test
gcc -g ex1-hello.c -o ex1-hello
gcc -g ex2-hello.c -o ex2-hello
gcc -g freechk.c -o freechk
gcc -g doublefree.c -o doublefree
```
### Run executable via valgrind tool
```valgrind --tool=memcheck --leak-check=yes ./ex-test
valgrind --tool=memcheck --leak-check=yes ./ex1-hello
valgrind --tool=memcheck --leak-check=yes ./ex2-hello
valgrind --tool=memcheck --leak-check=yes ./freechk
valgrind --tool=memcheck --leak-check=yes ./doublefree
```
