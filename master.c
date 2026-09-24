#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* factorial(int n);
void multiply_factorial_str(char* fact_str, int multiplier);
int get_len_of_int(int n);

int main(){
    int fact;
    char* result;
    char user_input;
    bool exit_program = false;

    while (exit_program == false){
        printf("Factorial of: ");
        scanf(" %d", &fact);
        result = factorial(fact);
        printf("Result is %s \n", result);
        free(result);

        printf("Exit? [Y/N]: ");
        scanf(" %c", &user_input);
        if (user_input == 'Y' || user_input == 'y'){
            exit_program = true;
        }
    }
    return 0;
}

char* factorial(int n) {
  if (n < 0){
    char* str = malloc(1);
    str[0] = '\0';
    return str;
  }
  if (n == 0){
    char* str = malloc(2);
    str[0] = '1';
    str[1] = '\0';
    return str;
  }
  
  //Final factorial string
  char* factorial = calloc(10000, sizeof(char));
  
  //Starting with 1 so it can work
  strcpy(factorial, "1");
  
  //Factorial loop for each multiplication
  for (int i = 2; i <= n; i++){
    multiply_factorial_str(factorial, i);
  }
  return factorial;
}

void multiply_factorial_str(char* fact_str, int multiplier){
  int len = strlen(fact_str);
  int carry = 0;
  
  //Multiplication of each digit
  for (int i = len - 1; i >= 0; i--){
    int previous_digit = fact_str[i] - '0';
    int value = previous_digit * multiplier + carry;
    
    //Putting new digit into place of original one
    fact_str[i] = value % 10 + '0';
    carry = value / 10;
  }
  
  int carry_len = get_len_of_int(carry);
  //Adding carry value to the front by shifting the whole string
  if (carry > 0){
    for (int i = strlen(fact_str); i >= 0; i--){
      fact_str[i + carry_len] = fact_str[i];
    }
    while (carry > 0){
      fact_str[carry_len - 1] = carry % 10 + '0';
      carry /= 10;
      carry_len--;
    }
  }
}

int get_len_of_int(int n){
  int len = 0;
  while (n > 0){
    len++;
    n /= 10;
  }
  return len;
}