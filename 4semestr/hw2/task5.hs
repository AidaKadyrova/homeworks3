pal :: String -> Bool
pal [] = True
pal s = s == (reverse s)
