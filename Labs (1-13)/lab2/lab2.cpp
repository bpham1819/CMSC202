#include <iostream>

using namespace std;

double sumOfDoubles() {
  int num;
  double num2;
  double sum;
  
  cout << "How many doubles would you like to add together? ";
  cin >> num;
  
  for(int i = 0; i < num; i++) {
    cout << "Enter a double: ";
    cin >> num2;
    sum += num2;
  }

  return sum;
  
}

double greaterThanTwenty(double sum) {

  cout << "Sum: " << sum << endl;
  
  if(sum > 20)
    cout << sum << " is greater than 20!" << endl;
  else if(sum > 10)
    cout << sum << " is greater than 10!" << endl;
  else
    cout << sum << endl;

  return 0;
}


int main() {
 
  greaterThanTwenty(sumOfDoubles());
  
  return 0;
}
