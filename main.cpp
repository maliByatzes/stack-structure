#include <iostream>

class Stack 
{
  private:
    int top;
    int arr[5];
  
  public:
    Stack() 
    {
      top = -1;
      for (int i=0; i<5; i++)
        arr[i] = 0;
    }

    bool isEmpty()
    {
      if(top == -1)
        return true;
      else
        return false;
    }

    bool isFull()
    {
      if(top==4)
        return true;
      else
        return false;
    }

    void push(int value)
    {
      if(isFull())
      {
        std::cout << "Stack Overflow\n";
      }
      else
      {
        top++;
        arr[top] = value;
      }
    }

    int pop() 
    {
      if(isEmpty())
      {
        std::cout << "Stack underflow\n";
        return 0;
      }
      else
      {
        int number = arr[top];
        arr[top] = 0;
        top--;
        return number;
      }
    }

    int count()
    {
      return top + 1; // arraysize + 1
    }

    void change(int index, int value)
    {
      if(isEmpty())
      {
        std::cout << "Stack underflow\n";
      }
      else
      {
        arr[index] = value;
      }
    }

    int peek(int index)
    {
      if(isEmpty())
      {
        std::cout << "Stack underflow\n";
        return 0;
      }
      else 
      {
        return arr[index];
      }
    }

    void fillArr()
    {
      for (int i=0; i<5; i++)
        arr[i] = rand() % 100 + 1;
      top = 4; // arraysize - 1
    }

    void display()
    {
      for (int i=0; i<5; i++)
        std::cout << arr[i] << " ";
      std::cout << "\n"; 
    }
};

int main()
{
  Stack stack1;
  char chInput {'\0'};
  bool blnLoop {true};
  int pushNumber {0};
  int popNumber {0};
  int changeIndex {0};
  int changeValue {0};
  int peekIndex {0};

  do
  {
    std::cout << "\n******************Choose the operations to perform******************\n"
              << "a) push()\n"
              << "b) pop()\n"
              << "c) isEmpty()\n"
              << "d) isFull()\n"
              << "e) count()\n"
              << "f) change()\n"
              << "g) peek()\n"
              << "h) fillArr()\n"
              << "x) quit\n";
    stack1.display();
    std::cout << "Choice: ";
    std::cin >> chInput;

    switch (toupper(chInput))
    {
    case 'A':
      std::cout << "Enter a number to push: ";
      std::cin >> pushNumber;
      stack1.push(pushNumber);
      break;
    case 'B':
      popNumber = stack1.pop();
      if(popNumber!=0)
        std::cout << "Deleted: " << popNumber;
      break;
    case 'C':
      if(stack1.isEmpty())
        std::cout << "The stack is empty\n";
      else
        std::cout << "The stack is NOT empty\n";
      break;
    case 'D':
      if(stack1.isFull())
        std::cout << "The stack is full\n";
      else
        std::cout << "The stack is NOT full\n";
      break;
    case 'E':
      std::cout << "The stack can have " << stack1.count() << " item(s).\n";
      break;
    case 'F':
      std::cout << "Enter the index (0-4): ";
      std::cin >> changeIndex;
      std::cout << "Enter the value: ";
      std::cin >> changeValue;
      stack1.change(changeIndex, changeValue); 
      break;
    case 'G':
      std::cout << "Enter the index (0-4): ";
      std::cin >> peekIndex;
      std::cout << "Value at index " << peekIndex << ": " << stack1.peek(peekIndex) << "\n";
      break;
    case 'H':
      stack1.fillArr();
      break;
    case 'X':
      blnLoop = false;
      break;
    default:
      std::cerr << "Invalid input\n";
      break;
    }
  } while (blnLoop);
  
  return 0;
}
