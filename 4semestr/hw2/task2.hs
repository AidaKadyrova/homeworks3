power2 :: Int -> [Int]
power2 num = reverse(double num)
double 0 = []
double 1 = [1]
double n =  2^(n-1) : double(n-1)

