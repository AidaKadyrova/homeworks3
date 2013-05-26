data Tree a = Empty
          | Node a (Tree a) (Tree a)
          deriving (Eq, Show)

fold' :: Num a => (a -> a -> a -> a) -> a -> Tree a -> a
fold' _ n Empty = n
fold' f n (Node a l r) = f n (f a (f  (fold' f n l) (fold' f n r)))
