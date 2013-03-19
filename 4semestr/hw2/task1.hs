reverse' :: [Int] -> [Int]
reverse' x = rev x [] where
	rev :: [Int] -> [Int] -> [Int]
	rev [] l = l
        rev (x:xs) l = rev xs (x:l)
