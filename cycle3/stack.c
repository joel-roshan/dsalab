
#include <stdio.h>
#define MAX 10

int Stack[20];

int top = -1;

int isEmpty()
{
  return top == -1;
}

int pop()
{
  if (isEmpty())
  {
    return -1;
  }
  int item = Stack[top];
  top--;
  return item;
}

int peek()
{
  return Stack[top];
}

void display()
{
  for (int i = top; i >= 0; i--)
  {
    printf("%d  ", Stack[i]);
  }
}

int push(int item)
{
  if (top == MAX - 1)
  {
    return -1;
  }
  top++;
  Stack[top] = item;
  return 1;
}

int main()
{
  int item, res, ch;
  char option;

  do
  {
    printf("\nStack operations:\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("Enter item: ");
      scanf("%d", &item);
      res = push(item);
      if (!res)
      {
        printf("Stack full. Aborting");
        break;
      }
      printf("Item pushed");
      break;

    case 2:
      res = pop();
      if (!res)
      {
        printf("Stack Empty. Aborting");
        break;
      }
      printf("Item popped = %d", res);
      break;

    case 3:
      res = peek();
      if (!res)
      {
        printf("Stack Empty. Aborting");
        break;
      }
      printf("Item = %d", res);
      break;

    case 4:
      if (isEmpty())
      {
        printf("Stack Empty. Aborting");
        break;
      }
      display();
      break;
    default:
      printf("Invalid entry.\n");
      break;
    }
    printf("\nDo you want to continue? (y/n): ");
    scanf(" %c", &option);
  } while (option == 'y');
}