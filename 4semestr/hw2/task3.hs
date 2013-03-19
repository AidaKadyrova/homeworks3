sum :: Int -> Int
sum 0 = 0
sum n = (mod n 10) + sum(div n 10)
