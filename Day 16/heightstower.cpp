  int a[170];
              a[0]=1;
              m=1;
              temp = 0;
              for(i=1;i<=n;i++)  // to multiply n number 
              {
                               for(j=0;j<m;j++)
                               {
                                               x = a[j]*i+temp;
                                               a[j]=x%10;
                                               temp = x/10;
                               }
                               while(temp!=0)
                               { 
                                 a[m]=temp%10;
                                 temp = temp/10;
                                 m++;
                               }
              }



  void factorial(int n)
{
    int res[MAX];
 
    // Initialize result
    res[0] = 1;
    int res_size = 1;
 
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);
 
    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}
 
// This function multiplies x with the number represented by res[].
// res_size is size of res[] or number of digits in the number represented
// by res[]. This function uses simple school mathematics for multiplication.
// This function may value of res_size and returns the new value of res_size
int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry
 
    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;  // Store last digit of 'prod' in res[]
        carry  = prod/10;    // Put rest in carry
    }
 
    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}