f :: [Int] -> Int
f (x:xs) = f' (zipWith (+) (x:xs) (xs ++ [0])) (maximum (zipWith (+) (x:xs) (xs ++ [0]))) 1 where
	f' :: [Int] -> Int -> Int -> Int
        f' [] max pos = pos
	f' (x:xs) max pos = if x == max
		then pos
        	else f' xs max (pos + 1)
