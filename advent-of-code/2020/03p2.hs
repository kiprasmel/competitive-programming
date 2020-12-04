countTrees :: Int -> Int -> Int -> [[Char]] -> Int
countTrees i right down xs
  | rowIdx >= length xs = 0
  | otherwise           = isTree + (countTrees (i + 1) right down xs)
  where
    isTree    = if currChar == '#' then 1 else 0
    currChar  = (xs !! rowIdx) !! modColIdx
    rowIdx    =  i * down
    modColIdx = (i * right) `mod` (length (xs !! 0))

countAllTrees :: [[Char]] -> Int
countAllTrees xs = product $ map countSlope slopes
  where
    countSlope = \(right:down:_) -> countTrees 1 right down xs
    slopes     = [[1, 1], [3, 1], [5, 1], [7, 1], [1, 2]]

main :: IO ()
main = interact $ show . countAllTrees . lines

