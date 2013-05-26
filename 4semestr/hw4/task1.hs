data Tree a = Empty
          | Node a (Tree a) (Tree a)
          deriving (Eq, Show)

filter' ::  (a -> Bool) -> Tree a -> [a]
filter' f Empty = []
filter' f (Node a l r) = (filter' f l) ++ (if f a then [a] else []) ++ (filter' f r)
