#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int dot_pos(char *in, int len);

int test_data(char *in)//Test the data.
{
  int i, len = strlen(in);

  for (i = 0; i <= len - 1; i++)
    {
      if ( !(0 <= (int)(in[i] - 48) && (int)(in[i] - 48) <= 9 ) && in[i] != '.')
	return 0;
    }

  return 1;
}

int res_dot(char *in1, char *in2, int len1, int len2)
//Decide the position of dot in computing result.
{
  if (dot_pos(in1, len1) >= dot_pos(in2, len2))
    return dot_pos(in1, len1);

  return dot_pos(in2, len2);
}


int res_len(int len1, int len2, int pos1, int pos2)// Return the length of result.
{
  int len;

  if (pos1 >= pos2)
    len = pos1;
  else
    len = pos2;

  if ((len1 - pos1) >= (len2 - pos2))
    len += len1 - pos1;
  else
    len += len2 - pos2;
  
  return len;
}


int store(char *in)// Store input as char string.
{
  scanf("%s", in);

  return 0;
}


int t_store(char *in)// Test for store function.
{
  puts(in);

  return 0;
}


int ctoi(char *in, int len_in, int *ini,  int pos, int res_pos)
// Convert char in string to int, and keep their form is uniform.
{
  int i, k;
  i = pos - 1;
  k = res_pos - 1;
  
  while (i >= 0)
    {
      ini[k] = (int)(in[i] - 48);
      i--;
      k--;
    }

  i = pos + 1;
  k = res_pos;

  while (i <= len_in - 1)
    {
      ini[k] = (int)(in[i]-48);
      i++;
      k++;
    }
  
  return 0;
}


int t_ctoi(int *ini, int max_len)// Test for convert function.

{
  int i;

  for (i = 0; i <= max_len - 1; i++)
    printf("%d", ini[i]);

  printf("\n");
  
  return 0;
}


int add(int *res, int *ini1, int *ini2, int max_len)
// Add two integer, they store in int array.
{
  int i, tmp, jw = 0, k = max_len;
  

  for (i = max_len - 1; i >= 0; i--)
    {
      tmp = ini1[i] + ini2[i];
      res[k] = (jw + tmp) % 10;
      jw = (tmp + jw) / 10;
      k--;
    }

  res[0] = jw;
  
  return 0;
}


int show_add(int *res, int len, int res_pos)// Show the computing result of addition.
{
  int i;

  if (res[0] != 0)
    printf("%d", res[0]);
  
  for (i = 1; i <= len - 1; i++)
    {
      if (i == res_pos + 1)// Because add maybe create carry bit,
	//so dot position different.
	printf(".");

      printf("%d", res[i]);
    }
    
  printf ("\n");

  return 0;
}


int show_sub(int *res, int len, int res_pos, int indi)
{
  int i = 0, start;

  if (indi == 2)
    printf("-");
  
  while (i <= len - 1 && i != res_pos)
    {
      if (res[i] == 0)
	{
	  i++;
	  continue;
	}

      break;
    }

  start = i;

  if (start == res_pos)
    printf("0");
  
  for (; start <= len - 1; start++)
    {
      if (start == res_pos)
	printf(".");

      printf("%d", res[start]);
    }

  printf("\n");
  
  return 0;
}


int judge(int *ini1, int *ini2, int max_len)
{
  int i;

  for (i = 0; i <= max_len - 1; i++)
    {
      if (ini1[i] == ini2[i])
	continue;

      else if (ini1[i] > ini2[i])
	return 1;

      else if (ini2[i] > ini1[i])
	return 2;
    }

  return 0;
}


int sub(int *res, int *ini1, int *ini2, int max_len, int indi)// Subtraction.
{
  int i, tmp, jw = 0;
  
  if (indi == 1)
    {
      for (i = max_len - 1; i >= 0; i--)
	{
	  if ((ini1[i] - jw ) < ini2[i])// First minus borrow bit, then compare.
	    {
	      tmp = ini1[i] - jw + 10;
	      res[i] = tmp - ini2[i];
	      jw = 1;
	    }

	  else
	    {
	      tmp = ini1[i] - jw;
	      res[i] = tmp - ini2[i];
	      jw = 0;
	    }
	}
    }

  if (indi == 2)
    {
      for (i = max_len - 1; i >= 0; i--)
	{
	  if ((ini2[i] - jw ) < ini1[i])// First minus borrow bit, then compare.
	    {
	      tmp = ini2[i] - jw + 10;
	      res[i] = tmp - ini1[i];
	      jw = 1;
	    }

	  else
	    {
	      tmp = ini2[i] - jw;
	      res[i] = tmp - ini1[i];
	      jw = 0;
	    }
	}
    }
  
  return 0;
}





int calc(int *res, int *ini1, int *ini2, char op, int max_len, int res_pos)
// Calculate by operation
{
  if (op == '+')
    {
      add(res, ini1, ini2, max_len);
      show_add(res, max_len + 1, res_pos);
    }

  else if (op == '-')
    {
      int indi = judge(ini1, ini2, max_len);
      if (indi == 0)
	printf("0\n");
      
      else
	{
	  sub(res, ini1, ini2, max_len, indi);
	  show_sub(res, max_len, res_pos, indi);
	}
    }

  else if (op == '*')
    {
      
    }

  else if (op == '/')
    {
      
    }

  else
    printf("Your operation is not permitted.\n");

  return 0;
}


int dot_pos(char *in, int len)// Return the dot position of input string.
{
  int i;

  for (i = 0; i <= len - 1; i++)
    {
      if (in[i] == '.')
	return i;
    }

  return len;
}


int main(int argc, char *argv[])
{
  char in1[999999], in2[999999], op;

  printf("Please input the operation that you want(+, -, * or /): ");
  scanf("%c", &op);

  printf("Please input the two operands, parting them by enter:\n");
  
  store(in1);
  store(in2);

  int len1 = strlen(in1);
  int pos1 = dot_pos(in1, len1);

  int len2 = strlen(in2);
  int pos2 = dot_pos(in2, len2);

  int  max_len = res_len(len1, len2, pos1, pos2);
  int *res = (int*)malloc(max_len * sizeof(int));
  int *ini1 = (int*)malloc(max_len * sizeof(int));
  int *ini2 = (int*)malloc((max_len + 1) * sizeof(int));

  int res_pos = res_dot(in1, in2, len1, len2);

  ctoi(in1, len1, ini1, pos1, res_pos);
  
  ctoi(in2, len2, ini2, pos2, res_pos);

  //  printf("The judge: %d.\n", judge(ini1, ini2, max_len));

  if (test_data(in1) && test_data(in2))
    calc(res, ini1, ini2, op, max_len, res_pos);

  else
    printf("Your data is wrong.\n");
      
  return 0;
}
