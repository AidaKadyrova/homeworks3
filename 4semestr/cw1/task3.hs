findEl :: Eq el => el -> [el] -> [Int]
findEl x = findPos (x==) where
    findPos :: (a -> Bool) -> [a] -> [Int]
    findPos p xs = [ i | (x,i) <- zip xs [0..], p x]



