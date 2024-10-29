#include <iostream>
#include <cstdlib>
#include <climits>
#include "number.h"

int main()
{
  // Test constructors
  std::cout << "Testing Constructors:" << std::endl;
  Number num1(12345);
  Number num2(-6789);
  Number num3(0);
  Number num4(num1); // Copy constructor
  Number num5;       // Default constructor
  num5 = num2;       // Assignment operator

  std::cout << "num1: " << num1.toString() << "\n"; // Expected: "12345"
  std::cout << "num2: " << num2.toString() << "\n"; // Expected: "-6789"
  std::cout << "num3: " << num3.toString() << "\n"; // Expected: "0"
  std::cout << "num4 (copy of num1): " << num4.toString() << "\n"; // Expected: "12345"
  std::cout << "num5 (assigned from num2): " << num5.toString() << "\n"; // Expected: "-6789"

  std::cout << "\nTesting Assignment Operator with int:" << "\n";
  Number num6;
  num6 = 9876;
  std::cout << "num6 (assigned from int 9876): " << num6.toString() << "\n"; // Expected: "9876"

  // Test comparison operators
  std::cout << "\nTesting Comparison Operators:" << "\n";
  std::cout << std::boolalpha; // Print bools as true/false

  std::cout << "num1 == num4: " << (num1 == num4) << "\n"; // Expected: true
  std::cout << "num1 != num2: " << (num1 != num2) << "\n"; // Expected: true
  std::cout << "num1 > num2: " << (num1 > num2) << "\n";   // Expected: true
  std::cout << "num2 < num1: " << (num2 < num1) << "\n";   // Expected: true
  std::cout << "num1 >= num4: " << (num1 >= num4) << "\n"; // Expected: true
  std::cout << "num3 <= num2: " << (num3 <= num2) << "\n"; // Expected: false

  // Test operator+
  std::cout << "\nTesting Addition Operator:" << "\n";
  Number sum1 = num1 + num2;
  std::cout << num1.toString() << " + " << num2.toString() << " = " << sum1.toString() << "\n"; // Expected: "5556"

  Number sum2 = num2 + num3;
  std::cout << num2.toString() << " + " << num3.toString() << " = " << sum2.toString() << "\n"; // Expected: "-6789"

  Number sum3 = num1 + num4;
  std::cout << num1.toString() << " + " << num4.toString() << " = " << sum3.toString() << "\n"; // Expected: "24690"

  Number sum4 = num2 + num5;
  std::cout << num2.toString() << " + " << num5.toString() << " = " << sum4.toString() << "\n"; // Expected: "-13578"

  // Test operator-
  std::cout << "\nTesting Subtraction Operator:" << "\n";
  Number diff1 = num1 - num2;
  std::cout << num1.toString() << " - " << num2.toString() << " = " << diff1.toString() << "\n"; // Expected: "19134"

  Number diff2 = num2 - num1;
  std::cout << num2.toString() << " - " << num1.toString() << " = " << diff2.toString() << "\n"; // Expected: "-19134"

  Number diff3 = num1 - num4;
  std::cout << num1.toString() << " - " << num4.toString() << " = " << diff3.toString() << "\n"; // Expected: "0"

  Number diff4 = num2 - num2;
  std::cout << num2.toString() << " - " << num2.toString() << " = " << diff4.toString() << "\n"; // Expected: "0"

  // Edge cases
  std::cout << "\nTesting Edge Cases:" << "\n";
  Number zero(0);
  Number negativeZero(-0); // In practice, -0 should be treated the same as 0

  std::cout << "zero: " << zero.toString() << "\n";                   // Expected: "0"
  std::cout << "negativeZero: " << negativeZero.toString() << "\n";   // Expected: "0"

  std::cout << "zero == negativeZero: " << (zero == negativeZero) << "\n"; // Expected: true

  Number sumZero = zero + negativeZero;
  std::cout << zero.toString() << " + " << negativeZero.toString() << " = " << sumZero.toString() << "\n"; // Expected: "0"

  // Test adding and subtracting zero
  std::cout << "\nTesting Addition and Subtraction with Zero:" << "\n";
  Number sum5 = num1 + zero;
  std::cout << num1.toString() << " + " << zero.toString() << " = " << sum5.toString() << "\n"; // Expected: "12345"

  Number diff5 = num1 - zero;
  std::cout << num1.toString() << " - " << zero.toString() << " = " << diff5.toString() << "\n"; // Expected: "12345"

  Number sum6 = zero + num2;
  std::cout << zero.toString() << " + " << num2.toString() << " = " << sum6.toString() << "\n"; // Expected: "-6789"

  Number diff6 = zero - num2;
  std::cout << zero.toString() << " - " << num2.toString() << " = " << diff6.toString() << "\n"; // Expected: "6789"

  // Test chaining operations
  std::cout << "\nTesting Chaining of Operations:" << "\n";
  Number chainSum = num1 + num2 + num3 + num4 + num5 + num6;
  std::cout << "Chain sum: " << chainSum.toString() << "\n"; // Expected: sum of all nums

  Number chainDiff = num1 - num2 - num3 - num4 - num5 - num6;
  std::cout << "Chain difference: " << chainDiff.toString() << "\n"; // Expected: result of chained subtraction

  // Test large numbers
  std::cout << "\nTesting Large Numbers:" << "\n";
  Number largeNum1(999999999);
  Number largeNum2(888888888);
  Number largeSum = largeNum1 + largeNum2;
  std::cout << largeNum1.toString() << " + " << largeNum2.toString() << " = " << largeSum.toString() << "\n"; // Expected: "1888888887"

  Number largeDiff = largeNum1 - largeNum2;
  std::cout << largeNum1.toString() << " - " << largeNum2.toString() << " = " << largeDiff.toString() << "\n"; // Expected: "111111111"

  // Negative large numbers
  std::cout << "\nTesting Negative Large Numbers:" << "\n";
  Number negLargeNum1(-999999999);
  Number negLargeNum2(-888888888);
  Number negLargeSum = negLargeNum1 + negLargeNum2;
  std::cout << negLargeNum1.toString() << " + " << negLargeNum2.toString() << " = " << negLargeSum.toString() << "\n"; // Expected: "-1888888887"

  Number negLargeDiff = negLargeNum1 - negLargeNum2;
  std::cout << negLargeNum1.toString() << " - " << negLargeNum2.toString() << " = " << negLargeDiff.toString() << "\n"; // Expected: "-111111111"

  // Cross-sign large numbers
  std::cout << "\nTesting Cross-Sign Operations with Large Numbers:" << "\n";
  Number crossLargeSum = largeNum1 + negLargeNum2;
  std::cout << largeNum1.toString() << " + " << negLargeNum2.toString() << " = " << crossLargeSum.toString() << "\n"; // Expected: "111111111"

  Number crossLargeDiff = negLargeNum1 - largeNum2;
  std::cout << negLargeNum1.toString() << " - " << largeNum2.toString() << " = " << crossLargeDiff.toString() << "\n"; // Expected: "-1888888887"

  // Test self-assignment
  std::cout << "\nTesting Self-Assignment:" << "\n";
  num1 = num1;
  std::cout << "After self-assignment, num1: " << num1.toString() << "\n"; // Expected: "12345"

  // Test assignment after operations
  std::cout << "\nTesting Assignment After Operations:" << "\n";
  Number result;
  result = num1 + num2;
  std::cout << num1.toString() << " + " << num2.toString() << " = " << result.toString() << "\n"; // Expected: "5556"

  result = num1 - num2;
  std::cout << num1.toString() << " - " << num2.toString() << " = " << result.toString() << "\n"; // Expected: "19134"

  // Test edge case: subtracting from zero
  std::cout << "\nTesting Subtracting from Zero:" << "\n";
  Number zeroMinusNum1 = zero - num1;
  std::cout << zero.toString() << " - " << num1.toString() << " = " << zeroMinusNum1.toString() << "\n"; // Expected: "-12345"

  // Test edge case: adding zero to zero
  std::cout << "\nTesting Adding Zero to Zero:" << "\n";
  Number zeroPlusZero = zero + zero;
  std::cout << zero.toString() << " + " << zero.toString() << " = " << zeroPlusZero.toString() << "\n"; // Expected: "0"

  // Test large number operations
  std::cout << "\nTesting Operations with Very Large Numbers:" << "\n";
  Number veryLargeNum1(1234567890);
  Number veryLargeNum2(9876543210);
  Number veryLargeSum = veryLargeNum1 + veryLargeNum2;
  std::cout << veryLargeNum1.toString() << " + " << veryLargeNum2.toString() << " = " << veryLargeSum.toString() << "\n"; // Expected: "11111111100"

  Number veryLargeDiff = veryLargeNum2 - veryLargeNum1;
  std::cout << veryLargeNum2.toString() << " - " << veryLargeNum1.toString() << " = " << veryLargeDiff.toString() << "\n"; // Expected: "8641975320"

  // Test negative and positive number addition
  std::cout << "\nTesting Addition of Negative and Positive Numbers:" << "\n";
  Number mixedSum = num1 + negLargeNum1;
  std::cout << num1.toString() << " + " << negLargeNum1.toString() << " = " << mixedSum.toString() << "\n"; // Expected: depends on values

  // Test negative and positive number subtraction
  std::cout << "\nTesting Subtraction of Negative and Positive Numbers:" << "\n";
  Number mixedDiff = num1 - negLargeNum1;
  std::cout << num1.toString() << " - " << negLargeNum1.toString() << " = " << mixedDiff.toString() << "\n"; // Expected: depends on values

  // Test extreme values
  std::cout << "\nTesting Extreme Values:" << "\n";
  Number maxIntNum(INT_MAX);
  Number minIntNum(INT_MIN);
  Number extremeSum = maxIntNum + minIntNum;
  std::cout << maxIntNum.toString() << " + " << minIntNum.toString() << " = " << extremeSum.toString() << "\n"; // Expected: "-1"

  // Test chaining multiple operations
  std::cout << "\nTesting Chaining Multiple Operations:" << "\n";
  Number chainResult = num1 + num2 - num3 + num4 - num5 + num6 - num1;
  std::cout << "Chain result: " << chainResult.toString() << "\n"; // Expected: depends on values

  // Test object destruction and memory leaks
  std::cout << "\nTesting Object Destruction and Memory Management:" << "\n";
  {
    Number tempNum1(123);
    Number tempNum2(456);
    Number tempResult = tempNum1 + tempNum2;
    std::cout << tempNum1.toString() << " + " << tempNum2.toString() << " = " << tempResult.toString() << "\n"; // Expected: "579"
  } // tempNum1, tempNum2, and tempResult go out of scope here

  std::cout << "Temporary objects have been destroyed." << "\n";

  std::cout << "\nTesting Multiplication Operator:" << "\n";

  // Test multiplying positive numbers
  Number mul1 = num1 * num4; // 12345 * 12345
  std::cout << num1.toString() << " * " << num4.toString() << " = " << mul1.toString() << "\n"; // Expected: "152399025"

  // Test multiplying a positive number by a negative number
  Number mul2 = num1 * num2; // 12345 * -6789
  std::cout << num1.toString() << " * " << num2.toString() << " = " << mul2.toString() << "\n"; // Expected: "-83810205"

  // Test multiplying two negative numbers
  Number mul3 = num2 * num5; // -6789 * -6789
  std::cout << num2.toString() << " * " << num5.toString() << " = " << mul3.toString() << "\n"; // Expected: "46153521"

  // Test multiplying by zero
  Number mul4 = num1 * num3; // 12345 * 0
  std::cout << num1.toString() << " * " << num3.toString() << " = " << mul4.toString() << "\n"; // Expected: "0"

  Number mul5 = num3 * num2; // 0 * -6789
  std::cout << num3.toString() << " * " << num2.toString() << " = " << mul5.toString() << "\n"; // Expected: "0"

  // Test multiplying zero by zero
  Number mul6 = num3 * num3; // 0 * 0
  std::cout << num3.toString() << " * " << num3.toString() << " = " << mul6.toString() << "\n"; // Expected: "0"

  // Test multiplying large numbers
  Number mul7 = largeNum1 * largeNum2; // 123456789 * 987654321
  std::cout << largeNum1.toString() << " * " << largeNum2.toString() << " = " << mul7.toString() << "\n"; // Expected: "121932631112635269"

  // Test multiplying negative large numbers
  Number mul8 = negLargeNum1 * negLargeNum2; // -123456789 * -987654321
  std::cout << negLargeNum1.toString() << " * " << negLargeNum2.toString() << " = " << mul8.toString() << "\n"; // Expected: "121932631112635269"

  // Test multiplying a positive large number by a negative large number
  Number mul9 = largeNum1 * negLargeNum2; // 123456789 * -987654321
  std::cout << largeNum1.toString() << " * " << negLargeNum2.toString() << " = " << mul9.toString() << "\n"; // Expected: "-121932631112635269"

  // Test chaining multiplication operations
  Number chainMul = num1 * num2 * num4; // 12345 * -6789 * 12345
  std::cout << num1.toString() << " * " << num2.toString() << " * " << num4.toString() << " = " << chainMul.toString() << "\n"; // Expected: "-18842790455625"

  // Test associativity
  Number assocMul1 = (num1 * num2) * num4;
  Number assocMul2 = num1 * (num2 * num4);
  std::cout << "\nAssociativity Test: " << "\n";
  std::cout << "(" << num1.toString() << " * " << num2.toString() << ") * " << num4.toString() << " = " << assocMul1.toString() << "\n";
  std::cout << num1.toString() << " * (" << num2.toString() << " * " << num4.toString() << ") = " << assocMul2.toString() << "\n";
  std::cout << "\nAssociativity holds: " << (assocMul1 == assocMul2) << "\n"; // Expected: true

  // Test commutativity
  Number commMul1 = num1 * num2;
  Number commMul2 = num2 * num1;
  std::cout << "\nCommutativity Test: " << "\n";
  std::cout << num1.toString() << " * " << num2.toString() << " = " << commMul1.toString() << "\n";
  std::cout << num2.toString() << " * " << num1.toString() << " = " << commMul2.toString() << "\n";
  std::cout << "\nCommutativity holds: " << (commMul1 == commMul2) << "\n"; // Expected: true

  // Test multiplication with INT_MAX and INT_MIN
  Number mul10 = maxIntNum * Number(2);
  Number mul11 = minIntNum * Number(2);
  std::cout << "Multiplying INT_MAX * 2: " << maxIntNum.toString() << " * 2 = " << mul10.toString() << "\n"; // Expected: "4294967294"
  std::cout << "Multiplying INT_MIN * 2: " << minIntNum.toString() << " * 2 = " << mul11.toString() << "\n"; // Expected: "-4294967296"

  // Test multiplication with one
  Number one(1);
  Number mul12 = num1 * one;
  std::cout << num1.toString() << " * 1 = " << mul12.toString() << "\n"; // Expected: "12345"

  Number mul13 = one * num2;
  std::cout << "1 * " << num2.toString() << " = " << mul13.toString() << "\n"; // Expected: "-6789"

  // Test self-assignment with multiplication
  Number numSelfAssign(5);
  numSelfAssign = numSelfAssign * numSelfAssign; // 5 * 5
  std::cout << "After self-assignment multiplication, numSelfAssign: " << numSelfAssign.toString() << "\n"; // Expected: "25"

  // Test multiplication resulting in zero
  Number mulZero = Number(0) * Number(12345);
  std::cout << "0 * 12345 = " << mulZero.toString() << "\n"; // Expected: "0"

  // Test multiplication of very large numbers
  Number mulVeryLarge = veryLargeNum1 * veryLargeNum2;
  std::cout << veryLargeNum1.toString() << " * " << veryLargeNum2.toString() << " = " << mulVeryLarge.toString() << "\n";
  // Expected: "1219326311370217952237463801111263526900"

  // Note: If you don't have a string constructor, you can skip the very large number test or implement the constructor.

  // Test multiplication by -1
  Number minusOne(-1);
  Number mul14 = num1 * minusOne;
  std::cout << num1.toString() << " * -1 = " << mul14.toString() << "\n"; // Expected: "-12345"

  Number mul15 = minusOne * num2;
  std::cout << "-1 * " << num2.toString() << " = " << mul15.toString() << "\n"; // Expected: "6789"

  // Test multiplying numbers resulting in overflow of built-in types
  Number bigNum1(1000000000);
  Number bigNum2(1000000000);
  Number bigMul = bigNum1 * bigNum2;
  std::cout << bigNum1.toString() << " * " << bigNum2.toString() << " = " << bigMul.toString() << "\n"; // Expected: "1000000000000000000"

  // Ensure no overflow occurs and the result is correct.

  // Testing Object Destruction and Memory Management:
  std::cout << "\nTesting Object Destruction and Memory Management after Multiplication:" << "\n";
  {
    Number tempNum1(123);
    Number tempNum2(456);
    Number tempResult = tempNum1 * tempNum2;
    std::cout << tempNum1.toString() << " * " << tempNum2.toString() << " = " << tempResult.toString() << "\n"; // Expected: "56088"
  } // tempNum1, tempNum2, and tempResult go out of scope here

  std::cout << "Temporary objects after multiplication have been destroyed." << "\n";

  std::cout << "\nTesting Division Operator:" << std::endl;

  num1 = (123456);
  num2 = (789);

  // Test dividing positive numbers
  Number div1 = num1 / num2;
  std::cout << num1.toString() << " / " << num2.toString() << " = " << div1.toString() << std::endl; // Expected: "156"

  // Test dividing a positive number by a negative number
  num3 = (-789);
  Number div2 = num1 / num3;
  std::cout << num1.toString() << " / " << num3.toString() << " = " << div2.toString() << std::endl; // Expected: "-156"

  // Test dividing negative numbers
  num4 = (-123456);
  Number div3 = num4 / num3;
  std::cout << num4.toString() << " / " << num3.toString() << " = " << div3.toString() << std::endl; // Expected: "156"

  // Test division by one
  one = (1);
  Number div4 = num1 / one;
  std::cout << num1.toString() << " / 1 = " << div4.toString() << std::endl; // Expected: "123456"

  // Test division of zero
  zero = (0);
  Number div5 = zero / num2;
  std::cout << "0 / " << num2.toString() << " = " << div5.toString() << std::endl; // Expected: "0"

  Number divByZero = num1 / zero;
  std::cout << num1.toString() << " / 0 = " << divByZero.toString() << std::endl;

  // Test division resulting in zero
  Number smallNum(100);
  Number largeNum(1000);
  Number div7 = smallNum / largeNum;
  std::cout << smallNum.toString() << " / " << largeNum.toString() << " = " << div7.toString() << std::endl; // Expected: "0"

  // Test division where numerator and denominator are equal
  Number div8 = num1 / num1;
  std::cout << num1.toString() << " / " << num1.toString() << " = " << div8.toString() << std::endl; // Expected: "1"

  // Test division resulting in a non-integer quotient (integer division)
  num5 = (10);
  num6 = (3);
  Number div9 = num5 / num6;
  std::cout << num5.toString() << " / " << num6.toString() << " = " << div9.toString() << std::endl; // Expected: "3"


  return EXIT_SUCCESS;
}
