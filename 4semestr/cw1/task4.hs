sum1 :: Floating a => [a] -> a
sum1 (x:xs) = sum' (x:xs) 0 1 where
    sum' [] acc1 acc2 = (acc1 / acc2)
    sum' (x:xs) acc1 acc2 = sum' xs (acc1 + x) (acc2 * cos(x))
