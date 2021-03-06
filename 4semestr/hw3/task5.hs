data Tree a = Empty
          | Node a (Tree a) (Tree a)
            deriving (Eq, Show)
                     
height Empty = 0
height (Node _ l r) = 1 + (min (height l) (height r))
