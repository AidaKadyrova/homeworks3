pos :: Int -> [Int] -> Int
pos n x = posi n x 0 where
	posi n [] acc = -1
	posi n (x:xs) acc = if n == x
        	then acc
                else posi n xs (acc + )
