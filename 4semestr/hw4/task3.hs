f1 :: [Int] -> Int
f1 x = length (filter even x)

f2 :: [Int] -> Int
f2 x = length x - length (filter odd x)

f3 :: [Int] -> Int
f3 x = foldr (+) 0 (map (\x -> x `mod` 2) x)
