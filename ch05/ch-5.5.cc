// to show the fatal mistake of using goto statement.
// but don't use goto in any program, 
// it makes program hard to understand and hard to modify

int main() {
    int x = 0;
goto label;
    int b = 20; // note:   crosses initialization of 'int b'
label:
    x = 20;
    return 0;
}