#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int coinSums();
int pandigitalNumber();
int cancelFractions();
int digitFactorials();
int circularPrimes();
int palindromes();
int truncatables();
int pandigitalMultiples();
int rightTriangle();
int ChampersnowneConst();
int pandigitalPrime();
int triangleWords();
long subStringDiv();

bool isPandigital(string num);
template <typename Value>
bool exists(vector<Value> v, Value x);
bool containsChar(string word, char ch);
int factoriel(int number);
bool isPrime(int number);
int rotateNumber(int number);
string convertToBinary(int number);
bool isPalindromic(string value);
bool isTruncatable(int number);
bool isSequencedFromOne(int number);
long generator(string number);
long counter = 0;

int main()
{
  cout << subStringDiv();
  return 0;
}

// problem 31

int coinSums()
{
  int sum = 1;
  for (int x100 = 0; x100 < 3; x100++)
  {
    for (int x50 = 0; x50 < 5; x50++)
    {
      if (x100 * 100 + x50 * 50 > 200)
      {
        break;
      }
      for (int x20 = 0; x20 < 11; x20++)
      {
        if (x100 * 100 + x50 * 50 + x20 * 20 > 200)
        {
          break;
        }
        for (int x10 = 0; x10 < 21; x10++)
        {
          if (x100 * 100 + x50 * 50 + x20 * 20 + x10 * 10 > 200)
          {
            break;
          }
          for (int x5 = 0; x5 < 41; x5++)
          {
            if (x100 * 100 + x50 * 50 + x20 * 20 + x10 * 10 + x5 * 5 > 200)
            {
              break;
            }
            for (int x2 = 0; x2 < 101; x2++)
            {
              if (x100 * 100 + x50 * 50 + x20 * 20 + x10 * 10 + x5 * 5 + x2 * 2 > 200)
              {
                break;
              }
              for (int x1 = 0; x1 < 201; x1++)
              {
                if (x100 * 100 + x50 * 50 + x20 * 20 + x10 * 10 + x5 * 5 + x2 * 1 + x1 > 200)
                {
                  break;
                }
                else if (x100 * 100 + x50 * 50 + x20 * 20 + x10 * 10 + x5 * 5 + x2 * 1 + x1 == 200)
                {
                  sum++;
                }
              }
            }
          }
        }
      }
    }
  }

  return sum;
}

//Problem 32
int pandigitalNumber()
{
  vector<int> numbers;
  for (int i = 1; i < 10; i++)
  {
    for (int j = 1234; j < 10000; j++)
    {
      if (!containsChar(to_string(j), '0'))
      {
        int result = i * j;
        if (to_string(result).size() > 4)
        {
          break;
        }
        if (!containsChar(to_string(result), '0'))
        {
          if (!exists(numbers, result))
          {
            if (isPandigital(to_string(i) + to_string(j) + to_string(result)))
            {
              cout << to_string(i) + to_string(j) + to_string(result) + "\n";
              numbers.insert(numbers.end(), result);
            }
          }
        }
      }
    }
  }

  for (int i = 12; i < 100; i++)
  {
    if (!containsChar(to_string(i), '0'))
    {
      for (int j = 123; j < 1000; j++)
      {
        if (!containsChar(to_string(j), '0'))
        {
          int result = i * j;
          if (to_string(result).size() > 4)
          {
            break;
          }
          if (!containsChar(to_string(result), '0'))
          {
            if (!exists(numbers, result))
            {
              if (isPandigital(to_string(i) + to_string(j) + to_string(result)))
              {
                cout << to_string(i) + to_string(j) + to_string(result) + "\n";
                numbers.insert(numbers.end(), result);
              }
            }
          }
        }
      }
    }
  }

  int sum = 0;

  for (int i = 0; i < numbers.size(); i++)
  {
    sum = sum + numbers[i];
  }

  return sum;
}
template <typename Value>
bool exists(vector<Value> v, Value x)
{
  if (v.empty())
  {
    return false;
  }
  else
  {

    if (find(v.begin(), v.end(), x) != v.end())
    {
      return true;
    }
    return false;
  }
}

bool isPandigital(string num)
{
  bool zero = false;
  for_each(num.begin(), num.end(), [&zero](char c)
           {
             if (c == '0')
               zero = true;
           });

  if (zero)
  {
    return false;
  }

  vector<char> chars(num.length(), *"0");
  for (int i = 0; i < num.length(); i++)
  {
    if (exists(chars, num[i]))
    {
    zero:;
      return false;
    }
    else
    {
      chars.insert(chars.end(), num[i]);
    }
  }

  return true;
}

bool containsChar(string word, char ch)
{
  return word.find(ch) < word.size();
}

//Problem 33

int cancelFractions()
{
  vector<string> numbers;
  int pos1, pos2, cancelTop, cancelBottom;
  for (int i = 12; i < 100; i++)
  {
    for (int j = 11; j < i; j++)
    {
      if (!containsChar(to_string(i), '0') && !containsChar(to_string(j), '0'))
      {
        pos1 = to_string(j).find(to_string(i)[0]);
        if (pos1 == 0)
        {
          cancelBottom = i % 10;
          cancelTop = j % 10;
          if (((double)j / (double)i) == ((double)cancelTop / (double)cancelBottom))
          {
            numbers.insert(numbers.end(), to_string(j) + to_string(i));
          }
        }
        else if (pos1 == 1)
        {
          cancelBottom = i % 10;
          cancelTop = j / 10;
          if (((double)j / (double)i) == ((double)cancelTop / (double)cancelBottom))
          {
            numbers.insert(numbers.end(), to_string(j) + to_string(i));
          }
        }
        if (to_string(i)[0] != to_string(i)[1])
        {
          pos2 = to_string(j).find(to_string(i)[1]);
          if (pos2 == 0)
          {
            cancelBottom = i / 10;
            cancelTop = j % 10;
            if (((double)j / (double)i) == ((double)cancelTop / (double)cancelBottom))
            {
              numbers.insert(numbers.end(), to_string(j) + to_string(i));
            }
          }
          else if (pos2 == 1)
          {
            cancelBottom = i / 10;
            cancelTop = j / 10;
            if (((double)j / (double)i) == ((double)cancelTop / (double)cancelBottom))
            {
              numbers.insert(numbers.end(), to_string(j) + to_string(i));
            }
          }
        }
      }
    }
  }

  for_each(numbers.begin(), numbers.end(), [](string value)
           { cout << value + "\n"; });

  return 100;
}

// Problem 34

int digitFactorials()
{
  int max = 2;
  int sumNum, totalSum = 0;
  string number;
  while (pow(10, max) < max * 362880)
  {
    max++;
  }

  for (int i = 10; i < pow(10, max); i++)
  {
    number = to_string(i);
    sumNum = 0;
    for_each(number.begin(), number.end(), [&sumNum](char c)
             { sumNum = sumNum + factoriel(c - '0'); });
    if (sumNum == i)
    {
      totalSum = totalSum + sumNum;
    }
  }

  return totalSum;
}

int factoriel(int number)

{
  if (number > 1)
  {
    return factoriel(number - 1) * number;
  }
  else
  {
    return 1;
  }
}

// Problem 35

int circularPrimes()
{
  int numberOfPrimes = 4, rotatedNumber;
  string number;
  for (int i = 11; i < 1000000; i++)
  {
    if (isPrime(i))
    {
      number = to_string(i);
      if (!containsChar(number, '2') && !containsChar(number, '0') && !containsChar(number, '4') && !containsChar(number, '5') && !containsChar(number, '6') && !containsChar(number, '8'))
      {
        rotatedNumber = i;
        for (int j = 1; j <= number.length(); j++)
        {
          rotatedNumber = rotateNumber(rotatedNumber);
          if (!isPrime(rotatedNumber))
          {
            goto exit;
          }
        }
        numberOfPrimes++;
      }
    exit:
    {
    }
    }
  }

  return numberOfPrimes;
}

bool isPrime(int number)
{
  if (number < 6 && number >= 1)
  {
    if (number == 1)
    {
      return false;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
      if (number % i == 0)
      {
        return false;
      }
    }
    return true;
  }

  if (number % 6 == 1 || number % 6 == 5)
  {
    for (int i = 2; i <= sqrt(number); i++)
    {
      if (number % i == 0)
      {
        return false;
      }
    }
    return true;
  }
  else
  {
    return false;
  }
}

int rotateNumber(int number)
{
  string num = to_string(number);
  int lastOne = number % 10;
  number = number / 10;
  number = number + lastOne * pow(10, num.length() - 1);
  return number;
}

// Problem 36

int palindromes()
{
  int sum = 0;
  for (int i = 0; i <= 1000000; i++)
  {
    if (isPalindromic(to_string(i)) && isPalindromic(convertToBinary(i)))
    {
      cout << i << " " << convertToBinary(i) << "\n";
      sum = sum + i;
    }
  }

  return sum;
}

string convertToBinary(int number)
{
  string num;
  while (number != 0)
  {
    num.insert(num.begin(), number % 2 + '0');
    number = number / 2;
  }
  return num;
}

bool isPalindromic(string value)

{

  for (int i = 0; i < (int)value.length() / 2; i++)
  {
    if (value[i] != value[value.length() - 1 - i])
    {
      return false;
    }
  }

  return true;
}

// Problem 37
int truncatables()
{
  vector<string> first = {"2", "3", "5", "7"};
  vector<string> last = {"3", "5", "7"};
  int numberOfPrimes = 0;
  int sum = 0;
  int number = 0;
  int test;
  while (numberOfPrimes < 11)
  {
    if (number == 0)
    {
      for (int i = 0; i < first.size(); i++)
      {
        for (int j = 0; j < last.size(); j++)
        {
          test = stoi(first.at(i) + last[j]);
          if (isTruncatable(test))
          {
            numberOfPrimes++;
            sum = sum + test;
          }
        }
      }
    }
    else
    {
      for (int i = 0; i < first.size(); i++)
      {
        for (int j = 0; j < last.size(); j++)
        {
          test = stoi(first.at(i) + to_string(number) + last[j]);
          if (isTruncatable(test))
          {
            numberOfPrimes++;
            sum = sum + test;
          }
        }
      }
    }

    number++;
  }

  return sum;
}

bool isTruncatable(int number)
{
  int num = number;
  while (num != 0)
  {
    if (!isPrime(num))
    {
      return false;
    }
    num = num / 10;
  }
  int dividor = 10;
  int n = number % dividor;
  while (n != number)
  {
    if (!isPrime(n))
    {
      return false;
    }
    dividor = dividor * 10;
    n = number % dividor;
  }

  return true;
}

// Problem 38
int pandigitalMultiples()
{
  string test;
  int num;
  int result = 0;
  for (int i = 5; i > 1; i--)
  {
    for (int number = pow(10, (int)(9 / i) - 1); number < pow(10, (int)(9 / i)); number++)
    {
      num = stoi(to_string(9) + to_string(number));
      test = to_string(num);
      for (int j = 2; j <= i; j++)
      {
        test = test + to_string(num * j);
        if (!containsChar(test, '0') && isPandigital(test) && test.length() == 9)
        {
          if (stoi(test) > result)
          {
            result = stoi(test);
          }
        }
      }
    }
  }

  return result;
}

// Problem 39

int rightTriangle()
{
  double c;
  vector<int> times(1001, 0);
  for (int p = 12; p <= 1000; p++)
  {
    for (int a = 4; a <= p; a++)
    {
      for (int b = 3; b <= a; b++)
      {
        if (a + b > p)
        {
          goto exit;
        }
        c = sqrt(pow(a, 2.0) + pow(b, 2.0));
        if ((a + b + c) == p)
        {
          times[p]++;
        }
      }
    }
  exit:;
  }
  int max = 0;
  int inc = 0, index;
  for_each(times.begin(), times.end(), [&max, &inc, &index](int value)
           {
             if (max < value)
             {
               index = inc;
               max = value;
             }
             inc++;
           });

  return index;
}

// Problem 40
int ChampersnowneConst()
{
  //soved in a paper
  return 210;
}

bool isSequencedFromOne(int number)
{
  string s = to_string(number);
  sort(s.begin(), s.end());
  if (s[0] != '1')
  {
    return false;
  }

  if (s.length() == s[s.length() - 1] - '0')
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Problem 41
int pandigitalPrime()
{
  int max = 87654321;
  int sixMultiple = max / 6;
  int multipleS = sixMultiple * 6 + 1;
  int multipleP = sixMultiple * 6 - 1;
  vector<char> ending = {'9', '7', '3', '1'};
  while (true)
  {
    if (isSequencedFromOne(multipleS))
    {
      if (exists(ending, to_string(multipleS).at(to_string(multipleS).length() - 1)))
      {
        if (isPandigital(to_string(multipleS)))
        {
          if (isPrime(multipleS))
          {

            return multipleS;
          }
        }
      }
    }
    if (isSequencedFromOne(multipleP))
    {
      if (exists(ending, to_string(multipleP).at(to_string(multipleP).length() - 1)))
      {
        if (isPandigital(to_string(multipleP)))
        {
          if (isPrime(multipleP))
          {

            return multipleP;
          }
        }
      }
    }
    sixMultiple--;
    multipleS = sixMultiple * 6 + 1;
    multipleP = sixMultiple * 6 - 1;
  }
}

//Problem 42
int triangleWords()
{
  string text;
  ifstream file("words.txt");
  vector<string> words;
  vector<int> triangles = {1};
  int number = 0;
  while (getline(file, text, '"'))
  {
    if (text != "," && text != "")
    {
      words.push_back(text);
    }
  }

  for_each(
      words.begin(), words.end(), [&number, &triangles](string word)
      {
        int taille = 0;
        for_each(word.begin(), word.end(), [&taille](char c)
                 { taille += c - 'A' + 1; });
        if (exists(triangles, taille))
        {
          number++;
        }
        else
        {
          int last = triangles.size();
          int triangle = 0;
          while (triangle < taille)
          {
            last++;
            triangle = (last * (last + 1)) / 2;
            triangles.push_back(triangle);
            if (triangle == taille)
            {
              number++;
            }
          }
        }
      });

  return number;
}

//Problem 43
long subStringDiv(){
  return generator("");
}

long generator(string number)
{
  if (number.length() == 10)
  {
    int div24 = stoi(number.substr(1, 3));
    int div35 = stoi(number.substr(2, 3));
    int div46 = stoi(number.substr(3, 3));
    int div57 = stoi(number.substr(4, 3));
    int div68 = stoi(number.substr(5, 3));
    int div79 = stoi(number.substr(6, 3));
    int div810 = stoi(number.substr(7, 3));
    if (div24 % 2 == 0)
    {
      if (div35 % 3 == 0)
      {
        if (div46 % 5 == 0)
        {
          if (div57 % 7 == 0)
          {
            if (div68 % 11 == 0)
            {
              if (div79 % 13 == 0)
              {
                if (div810 % 17 == 0)
                {
                  return stol(number);
                }
              }
            }
          }
        }
      }
    }
    return 0;
  }
  else
  {
    long sum = 0;
    for (int i = 0; i < 10; i++)
    {
      char c = i + '0';
      if (!containsChar(number, c))
      {
        sum += generator(number + to_string(i));
      }
    }
    return sum;
  }
}
